#include<windows.h>


LRESULT CALLBACK WindowProc(
	HWND   hwnd,//��Ϣ�������ھ��
	UINT   uMsg,//�������Ϣ���� WM_XXXX
	WPARAM wParam,//���̸�����Ϣ
	LPARAM lParam //��긽����Ϣ
) {

	switch (uMsg)
	{
	case WM_CLOSE:

		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN://����������
	{
		int xPost = LOWORD(lParam);

		int yPost = HIWORD(lParam);

		char buf[1024];

		wsprintf(buf,TEXT("x= %d,y= %d"), xPost, yPost);

		MessageBox(hwnd, buf, TEXT("����������"), MB_OK);

		break;
	}

	case WM_KEYDOWN://����
	{
		MessageBox(hwnd, TEXT("���̰���"), TEXT("���̰���"), MB_OK);
		break;
	}

	case WM_PAINT://��ͼ�¼�
	{
		PAINTSTRUCT	ps;

		HDC hdc= BeginPaint(hwnd,&ps);

		TextOut(hdc, 100, 100, TEXT("Hello"),strlen("Hello"));


		EndPaint(hwnd, &ps);

		break;
	}
	default:
		break;
	}
	return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance
	,LPSTR lpCmdLine,
	int nSHowCmd
) {
	//���ô���
	//ע�ᴰ��
	//��������
	//��ʾ�͸���
	//ѭ��ȡ��Ϣ
	//������Ϣ

	WNDCLASS wc;
	wc.cbClsExtra = 0;//class�����ڴ�

	wc.cbWndExtra = 0;//���ڶ����ڴ�

	wc.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);//���ñ���

	wc.hCursor = LoadCursor(NULL, IDC_HAND);//���ù��

	wc.hIcon = LoadIcon(NULL, IDI_ERROR);

	wc.hInstance = hInstance;//Ӧ�ó���ʵ�ʾ��

	wc.lpfnWndProc = WindowProc;//���ڹ��̻ص����� 

	wc.lpszClassName = TEXT("WIN");//����������

	wc.lpszMenuName = NULL;

	wc.style = 0;


	//ע��
	RegisterClass(&wc);

	//����

	/**
	lpClassName
	lpWindowName
	dwStyle WS_OVERLAPPEDWINDOW
	x CW_USEDEFAULT
	y CW_USEDEFAULT
	nWidth
	nHeight
	 hWndParent   
	hMenu,
	hInstance,
	lpParam
	**/
	HWND hwnd = CreateWindow(wc.lpszClassName,TEXT("Windows"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL, hInstance,NULL);


	//��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);

	UpdateWindow(hwnd);

	//ѭ��ȡ��Ϣ

	/*
	HWND        hwnd; �����ھ��
    UINT        message; ������Ϣ����
    WPARAM      wParam; ������Ϣ
    LPARAM      lParam; �����Ϣ
    DWORD       time; ��Ϣ����ʱ��
    POINT       pt; �����Ϣ
	*/
	MSG msg;
	
	while (1) {
		if (GetMessage(&msg,NULL,0,0)==FALSE) {

			break;
		}

		TranslateMessage(&msg);

		DispatchMessage(&msg);
	}

	return 0;

}
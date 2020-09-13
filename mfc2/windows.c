#include<windows.h>


LRESULT CALLBACK WindowProc(
	HWND   hwnd,//消息所处窗口句柄
	UINT   uMsg,//具体的消息名称 WM_XXXX
	WPARAM wParam,//键盘附加消息
	LPARAM lParam //鼠标附加消息
) {

	switch (uMsg)
	{
	case WM_CLOSE:

		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN://鼠标左键按下
	{
		int xPost = LOWORD(lParam);

		int yPost = HIWORD(lParam);

		char buf[1024];

		wsprintf(buf,TEXT("x= %d,y= %d"), xPost, yPost);

		MessageBox(hwnd, buf, TEXT("鼠标左键按下"), MB_OK);

		break;
	}

	case WM_KEYDOWN://键盘
	{
		MessageBox(hwnd, TEXT("键盘按下"), TEXT("键盘按下"), MB_OK);
		break;
	}

	case WM_PAINT://绘图事件
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
	//设置窗口
	//注册窗口
	//创建窗口
	//显示和更新
	//循环取消息
	//处理消息

	WNDCLASS wc;
	wc.cbClsExtra = 0;//class额外内存

	wc.cbWndExtra = 0;//窗口额外内存

	wc.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);//设置背景

	wc.hCursor = LoadCursor(NULL, IDC_HAND);//设置光标

	wc.hIcon = LoadIcon(NULL, IDI_ERROR);

	wc.hInstance = hInstance;//应用程序实际句柄

	wc.lpfnWndProc = WindowProc;//窗口过程回调函数 

	wc.lpszClassName = TEXT("WIN");//窗口类名称

	wc.lpszMenuName = NULL;

	wc.style = 0;


	//注册
	RegisterClass(&wc);

	//创建

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


	//显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL);

	UpdateWindow(hwnd);

	//循环取消息

	/*
	HWND        hwnd; 主窗口句柄
    UINT        message; 具体消息名称
    WPARAM      wParam; 键盘消息
    LPARAM      lParam; 鼠标消息
    DWORD       time; 消息产生时间
    POINT       pt; 鼠标消息
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
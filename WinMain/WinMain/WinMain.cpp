#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WinChenProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
);

int WINAPI WinMain(
				   HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow
				   )
{
	//设计一个窗口类
	WNDCLASS wndcls ;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinChenProc;
	wndcls.lpszClassName = "DersonChen";
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	wndcls.lpszMenuName = NULL;

	//注册窗口类

	if (!RegisterClass(&wndcls))
	{
		return 0;
	}

	//创建窗口，定义一个变量用来保存成功创建窗口后返回的句柄
	HWND hwnd;
	hwnd = CreateWindow("DersonChen", "www.baidu.com", 
			WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);

	//显示及刷新窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	//定义消息结构体，开始消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;

}

LRESULT CALLBACK WinChenProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CHAR:
		char szChar[20];
		sprintf(szChar, "char code is %d", wParam);
		MessageBox(hwnd, szChar, "char", 0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "mouse clicked", "message", 0);
		HDC hdc;
		TextOut(hdc,0,50,"DersonChen",strlen("DersonChen"));
		break;
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd,&ps);
		TextOut(hDC,0,0,"DersonChen",strlen("DersonChen"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd,"是否真的结束？","message",MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}



}
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
	//���һ��������
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

	//ע�ᴰ����

	if (!RegisterClass(&wndcls))
	{
		return 0;
	}

	//�������ڣ�����һ��������������ɹ��������ں󷵻صľ��
	HWND hwnd;
	hwnd = CreateWindow("DersonChen", "www.baidu.com", 
			WS_OVERLAPPEDWINDOW, 0, 0, 600, 400, NULL, NULL, hInstance, NULL);

	//��ʾ��ˢ�´���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	//������Ϣ�ṹ�壬��ʼ��Ϣѭ��
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
		if (IDYES == MessageBox(hwnd,"�Ƿ���Ľ�����","message",MB_YESNO))
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
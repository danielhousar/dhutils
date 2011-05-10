/***************************************************************
 * file:	win32-window/main.c
 ***************************************************************/

#include <windows.h>
#include "resource.h"

#define _AppName TEXT("Hello World window")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("Hello World window");
	HWND hWnd;
	MSG msg;
	WNDCLASSEX wc;


	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = NULL;
	wc.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName = "MAINMENU";
	wc.lpszClassName = szAppName;

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(0,szAppName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance,NULL);
	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while(GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	static int cxClient, cyClient;
	HMENU hMenu;
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rect;

	switch(message) {
		case WM_COMMAND:
			hMenu=GetMenu(hWnd);
			switch(LOWORD(wParam)) {
				case IDM_ABOUT:
					MessageBox(hWnd,TEXT("win32-window 0.1"),TEXT("About"), MB_OK | MB_ICONINFORMATION);
					return 0;
				case IDM_CLOSE:
					DestroyWindow(hWnd);
					return 0;
			}
			return 0;

		case WM_SIZE:
			cxClient = LOWORD(lParam);
			cyClient = HIWORD(lParam);
			return 0;

		case WM_PAINT:
			GetClientRect(hWnd, &rect);
			hDC=BeginPaint(hWnd, &ps);
			DrawText(hDC, TEXT("Message in Window."), -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			EndPaint(hWnd, &ps);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


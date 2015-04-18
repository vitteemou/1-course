#undef UNICODE

#include <windows.h>
#include <vector>
#include <algorithm>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "ClassName";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS wcApp;

	// Заполняем структуру класса окна 
	wcApp.lpszClassName = szClassName;
	wcApp.hInstance = hInstance;
	wcApp.lpfnWndProc = WndProc;
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcApp.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcApp.lpszMenuName = 0;
	wcApp.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcApp.style = CS_HREDRAW | CS_VREDRAW;
	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;

	// Регистрируем класс окна
	if (!RegisterClass(&wcApp)){
		MessageBox(NULL, "Class hasn't been registered", "RegisterClass", MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szClassName, "Simple Windows Program", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, hInstance, 0);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	PAINTSTRUCT ps;

	switch (uMsg) {
	case WM_PAINT:
	{
		RECT r;

		GetClientRect(hWnd, &r);

		int logX = r.right / 4;
		int logY = r.bottom;

		hdc = BeginPaint(hWnd, &ps); 

		for (int i = 0; i < 4; i++)
			Rectangle(hdc, logX*i, 0, logX*(i + 1), logY);

		Rectangle(hdc, logX/4, logY/4, 3*logX/4, logY/2);
		TextOut(hdc, logX / 4, 5*logY / 8, "Прямоугольник", 13);

		Ellipse(hdc, 5*logX/4, logY / 4, 7*logX/4, logY / 2);
		TextOut(hdc, 11*logX / 8, 5*logY / 8, "Эллипс", 6);

		Pie(hdc, 9*logX/4, logY / 4, 11*logX / 4, 3*logY /4, 550, 100, 100, 200);
		TextOut(hdc, 38*logX / 16, 5*logY / 8, "Сектор", 6);

		

		POINT arr[5] = { 
				         { 13 * logX / 4, 3 * logY / 8 },
						 { 14 * logX / 4, logY / 4 },
						 { 15 * logX / 4, 3 * logY / 8 },
						 { 14 * logX / 4, logY / 2 },
						 { 13 * logX / 4, 3 * logY / 8 } 
		               };
		Polyline(hdc, arr, 5);
		TextOut(hdc, 55*logX / 16, 5*logY / 8, "Ромб", 4);

		EndPaint(hWnd, &ps);
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0);
}

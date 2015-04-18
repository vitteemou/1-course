#undef UNICODE
#include <windows.h>
#include <cmath>
#include <math.h>
#define FIRST_TIMER 1
int nTimerID;
const double cosinus = cos(3.14 / 4);
const double sinus = sin(3.14 / 4);

INT x = 800, y = 600;
RECT rect;
PAINTSTRUCT ps;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Project";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*хотя параметр hPrevInstance в Win32 всегда равно NULLпродолжаем проверять его значение */
	if (!hPrevInstance)
	{  /* инициализируем приложение -  подготавливаем данные класса окна и регистрируем его */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* завершаем создание копии приложения -     создаем главное окно приложения */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* Цикл обработки сообщений */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}

BOOL InitApplication(HINSTANCE hInstance)
{
	WNDCLASS  wc;
	// Заполняем структуру класса окна WNDCLASS
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	// Регистрируем класс окна
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // указатель на строку зарегистрированного имени класса
		szTitle,			 // указатель на строку заголовка окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		300,       // горизонтальная координата окна
		100,       // вертикальная координата окна
		x,       // ширина окна
		y,       // высота окна
		NULL,                // дескриптор родительского окна
		NULL,                // дескриптор меню окна
		hInstance,           // дескриптор экземпляра приложения
		NULL);               // указатель на дополнительные данные окна

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}



LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	HPEN hPen;
	static int x1, y1;
	static int x2, y2;
	static int k;
	static int x, y;

	switch (message)
	{

	case WM_CREATE:

		nTimerID = SetTimer(hwnd, FIRST_TIMER, 10, NULL);
		x1 = rect.left - 300;
		y1 = rect.bottom - 100;
		k = 0;
		break;


	case WM_PAINT:

		GetClientRect(hwnd, &rect);
		hDC = BeginPaint(hwnd, &ps);

		if (k == 1)
		{
			hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			SelectObject(hDC, hPen);
			Rectangle(hDC, (x1 - 10), (y1 - 10), (x1 + 310), (y1 + 310));
			k = 0;
			DeleteObject(hPen);
		}

		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		SelectObject(hDC, hPen)

		Ellipse(hDC, (x1 + 50), (y1 + 150), (x1 + 150), (y1 + 250));
		Ellipse(hDC, (x1 + 175), (y1 + 150), (x1 + 275), (y1 + 250));
		Rectangle(hDC, (x1), (y1 + 100), (x1 + 201), (y1 + 200));
		Rectangle(hDC, (x1 + 200), (y1), (x1 + 300), (y1 + 200));

		if (x1 == rect.right)
			x1 = rect.left - 300;
		DeleteObject(hPen);
		EndPaint(hwnd, &ps);
		break;


	case WM_TIMER:

		x1 += 1;
		y1 = (rect.bottom - 300);
		k = 1;

		InvalidateRect(hwnd, &rect, NULL);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
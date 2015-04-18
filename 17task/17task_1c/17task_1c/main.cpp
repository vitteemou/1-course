#undef UNICODE
#include <windows.h>
#include <string.h>
#include <cstring>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

LPCSTR szClassName = "WinAPI";
LPCSTR szTitle = "Project";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	/*���� �������� hPrevInstance � Win32 ������ ����� NULL���������� ��������� ��� �������� */
	if (!hPrevInstance)
	{  /* �������������� ���������� -  �������������� ������ ������ ���� � ������������ ��� */
		if (!InitApplication(hInstance))
			return (FALSE);
	}
	/* ��������� �������� ����� ���������� -     ������� ������� ���� ���������� */
	if (!InitInstance(hInstance, nCmdShow))
		return (FALSE);

	/* ���� ��������� ��������� */
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
	// ��������� ��������� ������ ���� WNDCLASS
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_ASTERISK);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	// ������������ ����� ����
	return RegisterClass(&wc);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(
		szClassName,         // ��������� �� ������ ������������������� ����� ������
		szTitle,			 // ��������� �� ������ ��������� ����
		WS_OVERLAPPEDWINDOW && WS_THICKFRAME, // ����� ����
		300,       // �������������� ���������� ����
		100,       // ������������ ���������� ����
		800,       // ������ ����
		600,       // ������ ����
		NULL,                // ���������� ������������� ����
		NULL,                // ���������� ���� ����
		hInstance,           // ���������� ���������� ����������
		NULL);               // ��������� �� �������������� ������ ����

	if (!hWnd)    return (FALSE);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);
	return (TRUE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int x1 = 0, y1 = 0;
	int x2 = 150, y2 = 100;
	int r = 60, g = 0, b = 80;
	char s1[7] = "������", s2[9] = "��������";

	
	HDC hDC;
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);

		HGDIOBJ hpenOld, hbrushOld;
		HBRUSH hbrush;

		SetTextColor(hDC, RGB(255, 255, 255));

		hbrush = CreateSolidBrush(RGB(r, g, b));
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

		Rectangle(hDC, x1, y1, x2, y2);
		SetBkColor(hDC, RGB(r, g, b));

		TextOut(hDC, x1 + 10, y1 + 10, s2, 9);
		TextOut(hDC, x1 + 10, y1 + 40, "���. 150", 9);

		for (int i = 0; i < 4; i++)
		{
			hbrush = CreateSolidBrush(RGB(r += 5, g += 13, b += 10));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

			Rectangle(hDC, x1 += 150, y1, x2 += 150, y2);
			SetBkColor(hDC, RGB(r, g, b));

			TextOut(hDC, x1 + 10, y1 + 10, s2, 9);
			TextOut(hDC, x1 + 10, y1 + 40, "���. 263", 9);

			Sleep(50);

		}

		x1 = 0, y1 = 100;
		x2 = 150, y2 = 200;

		hbrush = CreateSolidBrush(RGB(r += 5, g += 13, b += 10));
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

		Rectangle(hDC, x1, y1, x2, y2);
		SetBkColor(hDC, RGB(r, g, b));

		TextOut(hDC, x1 + 10, y1 + 10, s1, 7);
		TextOut(hDC, x1 + 10, y1 + 40, "���. 328", 9);

		Sleep(20);

		for (int i = 0; i < 4; i++)
		{
			hbrush = CreateSolidBrush(RGB(r += 5, g += 13, b += 10));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

			Rectangle(hDC, x1 += 150, y1, x2 += 150, y2);
			SetBkColor(hDC, RGB(r, g, b));

			TextOut(hDC, x1 + 10, y1 + 10, s1, 7);
			TextOut(hDC, x1 + 10, y1 + 40, "���. 457", 9);

			Sleep(50);

		}

		x1 = 0, y1 = 200;
		x2 = 150, y2 = 300;

		hbrush = CreateSolidBrush(RGB(r += 10, g += 25, b += 10));
		hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

		Rectangle(hDC, x1, y1, x2, y2);
		SetBkColor(hDC, RGB(r, g, b));

		TextOut(hDC, x1 + 10, y1 + 10, s1, 7);
		TextOut(hDC, x1 + 10, y1 + 40, "���. 239", 9);

		Sleep(20);


		for (int i = 0; i < 4; i++)
		{
			hbrush = CreateSolidBrush(RGB(r += 10, g += 25, b += 10));
			hbrushOld = (HBRUSH)SelectObject(hDC, hbrush);

			Rectangle(hDC, x1 += 150, y1, x2 += 150, y2);
			SetBkColor(hDC, RGB(r, g, b));

			TextOut(hDC, x1 + 10, y1 + 10, s2, 9);
			TextOut(hDC, x1 + 10, y1 + 40, "���. 346", 9);

			Sleep(50);

		}

		DeleteObject(SelectObject(hDC, hbrush));
		DeleteObject(SelectObject(hDC, hbrushOld));

		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
#include <Windows.h>
#include <stdio.h>
#if _DEBUG
#include <crtdbg.h>
#endif
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void
F(void)
{
	UINT16 a0 = 9;
	a0 |= 1;
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), L"The answer is always %d\n", a0);
	OutputDebugString(TextBuffer);

	char str[128] = "";
	sprintf(str, "%s %s", str, "FUNC");
	sprintf(str, "%s %s", str, "0");
	OutputDebugStringA(str);
}

int CALLBACK
WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow)
{
	F();
	MessageBox(0, L"Press OK.", L"The New App", 
		MB_OKCANCEL | MB_ICONINFORMATION);
	return(0);
}
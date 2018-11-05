#include <Windows.h>
#include <stdio.h>
#if _DEBUG
#include <crtdbg.h>
#endif

void
F(void)
{
	UINT16 a0 = 9;
	a0 |= 1;
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), L"The answer is always %d\n", a0);
	OutputDebugString(TextBuffer);

	char str[128] = "START";
	sprintf_s(str, 128, "%s %s", str, "FUNC");
	sprintf_s(str, 128, "%s %s", str, "0");
	OutputDebugStringA(str);
}

void
F2(void)
{
	UINT8 a0 = 2;
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), L"\nThe answer is now %d\n", a0 & 2);
	OutputDebugString(TextBuffer);
}

int CALLBACK
WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow)
{
	void * a = ((void *)0);
	void * b = &a + 1;
	b = (void *)1;
	F();
	F2();
	MessageBox(0, L"Press OK.", L"The New App", 
		MB_OKCANCEL | MB_ICONINFORMATION);
	return(0);
}

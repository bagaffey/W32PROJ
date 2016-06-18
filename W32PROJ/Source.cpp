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
#include <Windows.h>
#include <stdio.h>
#if _DEBUG
#include <crtdbg.h>
#endif

void
G(void)
{
	UINT16 a0 = 9;
	a0 |= 1;
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), L"%d\n", a0);
	OutputDebugString(TextBuffer);
}

int 
F(void)
{
#if _DEBUG
	void* x = malloc(512);
	return (_CrtDumpMemoryLeaks());
#endif
}

int CALLBACK
WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow)
{
	F();
	G();
	MessageBox(0, L"Press OK.", L"The New App", 
		MB_OKCANCEL | MB_ICONINFORMATION);
	return(0);
}
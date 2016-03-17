#include <Windows.h>
#include <crtdbg.h>

int 
F(void)
{
	void* x = malloc(512);
#if _DEBUG
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
	MessageBox(0, L"Press OK.", L"The New App", 
		MB_OKCANCEL | MB_ICONINFORMATION);
	return(0);
}
#include <Windows.h>

int CALLBACK
WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow)
{
#if _DEBUG
	OutputDebugString(L"Running in debug mode.\n");
#endif
	MessageBox(0, L"Press OK.", L"The New App", 
		MB_OKCANCEL | MB_ICONINFORMATION);
	return(0);
}
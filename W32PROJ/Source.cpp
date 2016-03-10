#include <Windows.h>

int CALLBACK
WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR lpCmdLine,
		int nCmdShow)
{
	MessageBox(0, L"Press OK.", L"The New App",
			   MB_OK | MB_ICONINFORMATION);
	return(0);
}
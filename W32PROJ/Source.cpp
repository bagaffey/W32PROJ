#include <Windows.h>
#include <stdio.h>

#if _DEBUG
#include <crtdbg.h>
#endif

void
F(void)
{
	UINT16 a0 = 9;
	a0 |= 4;
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), 
		     L"The answer is always %d\n", 
		     a0);
	OutputDebugString(TextBuffer);

	char str[128] = "START";
	sprintf_s(str, 128, "%s %s", str, "FUNC");
	sprintf_s(str, 128, "%s %s", str, "0");
	OutputDebugStringA(str);
}


void
F2(void)
{
	UINT8 a0 = 15;
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), L"\nThe answer is now %d\n", a0 & 2);
	OutputDebugString(TextBuffer);
}

inline UINT32
GetHex(char Char)
{
	UINT32 Result = 0;

	if ((Char >= '0') && (Char <= '9'))
	{
		Result = Char - '0';
	}
	else if ((Char >= 'A') && (Char <= 'F'))
	{
		Result = 0xA + (Char - 'A');

	}
	return(Result);
}

void
F4(void)
{
	INT32 A0 = GetHex('F');
	WCHAR TextBuffer[512];
	_snwprintf_s(TextBuffer, sizeof(TextBuffer), L"\nResult from GetHex is %d\n", A0);
	OutputDebugString(TextBuffer);
}

UINT32
F5(void)
{
	UINT32 Result = 9;
	return (Result);
}

void Concat1(char s[256], char t[256])
{
	int i = 0, j = 0;

	while (s[i] != '\0') {
		++i;
	}

	while (t[j] != '\0') {
		s[i] = t[j];
		++i;
		++j;
	}

	s[i] = '\0';

	char output[512] = "";
	sprintf_s(output, sizeof(output), "Result of Concat1 is %s\n", s);
	OutputDebugStringA(output);
}

void Concat2(char s[256], char t[256])
{
	int i = 0, j = 0;
	
	while (s[i] != '\0') { ++i; };

	while ((s[i++] = t[j++]) != '\0');

	char output[512] = "";
	sprintf_s(output, sizeof(output), "result of Concat2 is %s\n", s);
	OutputDebugStringA(output);
}

int CALLBACK
WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	F();
	F2();
	F4();
	// Too cold
	
	MessageBox(0, L"Battlecruiser operational.", L"Battlecruiser Application",
		MB_ABORTRETRYIGNORE | MB_ICONINFORMATION);
	return(0);
}

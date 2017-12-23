//#include<stdbool.h>

#include <stdio.h>
#include <wchar.h>

/*
#include <io.h>
#include <fcntl.h>
#ifndef _O_U16TEXT
  #define _O_U16TEXT 0x20000
#endif
*/

int main() {

/*

https://stackoverflow.com/questions/15528359/printing-utf-8-strings-with-printf-wide-vs-multibyte-string-literals

Once you decide to work with wide strings, wprintf can be used to print wide characters directly. It's also worth to note here that in case of Windows console, the translation mode of the stdout should be explicitly set to one of the Unicode modes by calling _setmode:

*/
	//TCHAR s[10] = L"George";
	//WCHAR Windows only
	//WCHAR *str2 = L"Asshat";

	//_setmode(_fileno(stdout), _O_U16TEXT);

	wchar_t *sp = L"Asshat";
	wprintf(L"A %s\n", sp);
	wprintf(L"C %ls\n", sp);
	wprintf(L"%s\n", L"ο Δικαιοπολις εν αγρω εστιν");

/*
	WCHAR t[10] = L"Asshat2";
	WCHAR *str2 = &t[0];
	wprintf("%S\n", str2);

	//WCHAR *str = L"Geo ";
	//wchar_t *str = L"Geo ";
	//wprintf("%s\n", str);


	BOOL res =
		CopyFile(L"d:\\tmp\\existing", "d:\\tmp\\new", TRUE);
	printf("%i\n", res);
*/

}

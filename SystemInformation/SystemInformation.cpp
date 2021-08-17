// SystemInformation.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <windows.h>
#include<sysinfoapi.h>
#include <stdexcept>
using namespace std;
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS


wstring getComputerName() {
	wchar_t buffer[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };
	DWORD cchBufferSize = sizeof(buffer) / sizeof(buffer[0]);
	if (!GetComputerNameW(buffer, &cchBufferSize))
		throw std::runtime_error("GetComputerName() failed.");
	return std::wstring(&buffer[0]);
}


BOOL Is64BitWindows()
{
	#if defined(_WIN64)
	return TRUE;  // 64-bit programs run only on Win64
	#elif defined(_WIN32)
	// 32-bit programs run on both 32-bit and 64-bit Windows
	// so must sniff
	BOOL f64 = FALSE;
	return IsWow64Process(GetCurrentProcess(), &f64) && f64;
	#else
	return FALSE; // Win64 does not support Win16
	#endif
}


int main()
{
	
	// Get user name
	wcout << getComputerName()<< endl;
	// get Sysem architecture. 
	if (Is64BitWindows()) cout <<"Windows 64 BIt"<< endl;
	else cout << "Windows is 32 BIt" << endl;
	system("pause");

	return 0;
}
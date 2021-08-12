// Program to retrieve file path, size, modification time

#include "stdafx.h"
#include <windows.h>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <strsafe.h>

using namespace std;
ofstream fout;



BOOL GetLastWriteTime(HANDLE hFile, LPTSTR lpszString, DWORD dwSize)
{
        FILETIME ftCreate, ftAccess, ftWrite;
        SYSTEMTIME stUTC, stLocal;
        DWORD dwRet;

        // Retrieve the file times for the file.
        if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
                return FALSE;

        // Convert the last-write time to local time.
        FileTimeToSystemTime(&ftWrite, &stUTC);
        SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

        // Build a string showing the date and time.
        dwRet = StringCchPrintf(lpszString, dwSize,
                TEXT("%02d/%02d/%d  %02d:%02d"),
                stLocal.wMonth, stLocal.wDay, stLocal.wYear,
                stLocal.wHour, stLocal.wMinute);

        /*char timeModified[50];
        DWORD dg = dwRet;
        sprintf_s(timeModified, "%d", dg);
        string ak = timeModified;
        wstring abc(ak.begin(), ak.end());*/


        if (S_OK == dwRet)
                return TRUE;
        else return FALSE;
}


bool ListFiles(wstring path, wstring mask, vector<wstring>& files) {
        HANDLE hFind = INVALID_HANDLE_VALUE;
        WIN32_FIND_DATA ffd;
        wstring spec;
        stack<wstring> directories;
        HANDLE hFile;
        TCHAR szBuf[MAX_PATH];

        directories.push(path);
        files.clear();

        while (!directories.empty())
        {
                path = directories.top();
                spec = path + L"\\" + mask;
                directories.pop();

                hFind = FindFirstFile(spec.c_str(), &ffd);
                if (hFind == INVALID_HANDLE_VALUE) {
                        return false;
                }

                do {
                        if (wcscmp(ffd.cFileName, L".") != 0 &&
                                wcscmp(ffd.cFileName, L"..") != 0) {
                                if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                                        directories.push(path + L"\\" + ffd.cFileName);

                                }
                                else {


                                        char test[10];
                                        DWORD dg = ffd.nFileSizeLow;
                                        sprintf_s(test, "%d", dg);
                                        string ak = test;
                                        wstring abc(ak.begin(), ak.end());
                                        //Getting Modified Time of files.
                                        hFile = CreateFile((path + L"\\" + ffd.cFileName).c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
                                        if (GetLastWriteTime(hFile, szBuf, MAX_PATH))
                                                //_tprintf(TEXT("Last write time is: %s\n"), szBuf);

                                        files.push_back(path + L"\\" + ffd.cFileName + L",    "  + ffd.cFileName + L" ,     "+ abc+ L" ,     "+ L"Last write time is: "+ szBuf);
                                        
                                        CloseHandle(hFile);

                                        

                                }
                        }
                } while (FindNextFile(hFind, &ffd) != 0);

                if (GetLastError() != ERROR_NO_MORE_FILES) {
                        FindClose(hFind);
                        return false;

                }

                FindClose(hFind);
                hFind = INVALID_HANDLE_VALUE;
        }
        return true;
}


int main(int argc, char* argv[])
{
        fout.open("FileDetails.txt", ios::app);
        vector<wstring> files;
        vector<wstring>::iterator ptr;



        if (ListFiles(L"C:\\Users\\Saurav\\Documents\\Visual Studio 2015\\Projects", L"*", files) == true) {

                for (vector<wstring>::iterator it = files.begin();
                it != files.end();
                        ++it) {
                        wcout << it->c_str() << endl;
                }
        }

        for (ptr = files.begin(); ptr < files.end();ptr++)
        {
                wstring wstr = *ptr;
                string str(wstr.begin(), wstr.end());
                fout << str << endl;
                wcout << *ptr << endl;
        }

        fout.close();
        system("pause");
        return 0;
}

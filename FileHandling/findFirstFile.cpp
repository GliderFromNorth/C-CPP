// findFirstFile.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <direct.h>
#include <vector>

using namespace std;
ofstream fout; // for creating file which would include names of the files in a directory. 
int fileCount = 0; // for conting ntotal numbers of files.


void get_file_list(string fileDir)
{
	fout.open("filenames.txt", ios::app);
	HANDLE hFind;
	WIN32_FIND_DATAA data;
	hFind = FindFirstFileA(fileDir.c_str(), &data);

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			fout << data.cFileName << endl; // Adding FileNames into "filesnames.txt" 
			
			
		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
		fout.close();
	}
}

 int main(int argc, char** argv)
{
	string DATA_DIR = "C:\\Windows\\*.*";  // file path
	get_file_list(DATA_DIR); //passing to the function 
	system("pause");

}
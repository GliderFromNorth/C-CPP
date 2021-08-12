// CopyFile_std.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>



using namespace std;





int main()
{
	string str;
	ofstream fout;
	fout.open("code.txt");
	fout << "Creating a program to copy file. We are doing this for the first time.";
	fout.close();
	

	ifstream fin;
	fin.open("code.txt");
	while (getline(fin, str))
	{
		cout << str;
		fin >> str;
	}
	system("pause");
	fin.close();
	BOOL cp = CopyFile(L"C:\\Users\\Saurav\\Documents\\Visual Studio 2015\\Projects\\FileHandling\\CopyFile_std\\code.txt", L"C:\\Users\\Saurav\\Documents\\Visual Studio 2015\\Projects\\FileHandling\\CopyFile_std\\copiedFile\\task1.txt",true);


    return 0;
}


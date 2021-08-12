// RenameAndDelete.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cstdio>
#include <stdio.h> 

using namespace std;

void Func_remove(string filename) 
{
	remove(filename.c_str());

}

void Func_rename(string fileName, string newFileName)
{
	rename(fileName.c_str(), newFileName.c_str());

}

int main()
{

	Func_remove("code.txt");
	Func_rename("jaldi.txt", "slow.txt");


    return 0;
}


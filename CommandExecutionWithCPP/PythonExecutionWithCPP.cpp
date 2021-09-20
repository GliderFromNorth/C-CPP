// PythonExecutionWithCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include <processthreadsapi.h>
#include <iostream>
#include <string>
#include<shellapi.h>

using namespace std;



int main()
{
	string Application = "\"python.exe\"";
	//string Application = "\"C:\\Program Files\\Python\\python.exe\"";
	string Function = "\"C:\\\\Users\\Saurav\\AppData\\Local\\Microsoft\\WindowsApps\\Encrypt and Decrypt\\Encrypt.py\"";
	string key = "\"qwsecretpassword\"";
	string Path= "\"C:\\\\Users\\Saurav\\Downloads\\python-3.9.7-amd64.exe\"";
	string command = ("\""+Application + " " + Function + " " + key + " " + Path+"\"");
	cout<< command<<endl;
	system(command.c_str());
	cout << endl;
	system("pause");
} 
/*
	 UpdateConfigFile.cpp : Defines the entry point for the console application.
     For the Multiple Arguement Input.
     Command to Run for Test -->  .\UpdateConfigFile.exe "C:\Program Files\Sequretek\Kawach\endpoint\settings\debugControl.json" "{\""sandbox\"":false,\""Raid\"":false,\""encryptSandboxFile\"":false,\""GoodDbScan\"":false}"
	 C:\Program Files\Sequretek\Kawach\endpoint\settings\debugControl.json
*/


#include "stdafx.h"
#pragma warning(disable : 26812)
#pragma warning(disable : 4996
#include <iostream>
#include <stdio.h>
#include <json\json.h>
#include <json\value.h>
#include <fstream>
#include <sstream>
#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")

using namespace std;

int main(int argc, char* argv[])
{
	ofstream fout;
	Json::Reader reader;
	Json::Value rootOfOriginal;
	Json::Value rootOfJsonString;
	Json::StyledWriter  writer;
	if (argc != 3)
	{
		cout << "Error: Invalid arguments \nUsage: ReadLastIndex.exe \"Complete\\File\\Path\"\n";
		return 0;
	}
	string fileName = argv[1];
	string jsonString = argv[2];
	if (PathFileExistsA(fileName.c_str()) != TRUE)
	{
		cout << "Error: File does not exist\n";
		return 0;
	}
	else
	{
		ifstream debug_file(fileName, ifstream::binary);
		if (!debug_file.is_open())
		{
			printf("Failed to open file\n");
			return false;
		}
		bool parsingOriginal = reader.parse(debug_file, rootOfOriginal);
		bool JsonString = reader.parse(jsonString, rootOfJsonString);
		if (!parsingOriginal && !JsonString)
		{
			cout << "Error: Parsing Failed\n";
			return 0;
		}
		cout << "********************************Original Json************************************" << endl;
		cout << rootOfOriginal << endl;
		cout << endl;
		cout << "********************************JsonString Json************************************" << endl;
		cout << rootOfJsonString << endl;
		cout << endl;
		Json::Value::Members keys = rootOfJsonString.getMemberNames();
		for (int i = 0; i < keys.size(); i++)
		{
			string key = keys[i];
			rootOfOriginal[key] = rootOfJsonString[key].asBool();
		}
		debug_file.close();
		string outputConfig = writer.write(rootOfOriginal);
		cout << "********************************Updated Json************************************" << endl;
		cout << outputConfig << endl;
		fout.open(fileName, ios::out);
		fout << outputConfig;
		fout.close();
	}
	return 0;
}




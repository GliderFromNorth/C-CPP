// UpdateConfigFile.cpp : Defines the entry point for the console application.
// C:\Program Files\Sequretek\Kawach\endpoint\settings\debugControl.json
// Command to Run for Test -->  .\UpdateConfigFile.exe "C:\Program Files\Sequretek\Kawach\endpoint\settings\debugControl.json" "{\""sandbox\"":false,\""Raid\"":false,\""encryptSandboxFile\"":false,\""GoodDbScan\"":false}"

#include "stdafx.h"
#pragma warning(disable : 26812)
#pragma warning(disable : 4996
#include <iostream>
#include <stdio.h>
#include "json/json.h"
#include <string>
#include <fstream>
#include <Wbemidl.h>
#include <sstream>
#include <wuapi.h>
#include <comdef.h>
#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib")
using namespace std;
int main(int argc, char* argv[])
{
	if (argc !=3)
	{
		cout << "Error: Invalid arguments \nUsage: ReadLastIndex.exe \"Complete\\File\\Path\"\n";
		return 0;
	}
	string fileName = argv[1];
	string newJson = argv[2];
	ifstream ifile(fileName, ifstream::binary);
	if (PathFileExistsA(fileName.c_str()) != TRUE)
	{
		cout << "Error: File does not exist\n";
		return 0;
	}

	if (!ifile.is_open())
	{
		printf("Failed to open file\n");
		return false;
	}
	Json::Reader reader;
	Json::Value rootSettings;
	bool ret = reader.parse(ifile, rootSettings);
	if (ret != true)
	{
		printf("Invalid json in the config file\n");
	}
	cout << "********************************Original Json************************************" << endl;
	cout << rootSettings << endl;
	Json::Value root;
	ret = reader.parse(newJson, root);
	if (ret != true)
	{
		printf("Invalid json provided\n");
		cout << newJson << endl;
	}
	cout <<"**********************************New Confog for updation**********************************"<< endl;
	cout << root << endl;
	Json::Value::Members keys = root.getMemberNames();
	for (int i = 0; i < keys.size(); i++) {
		string key = keys[i];
			rootSettings[key] = root[key].asBool();
	}
	ifile.close();
	Json::FastWriter writer;
	std::string newConfig = rootSettings.toStyledString();
	cout << "************************************Updated Json*****************************" << endl;
	cout << newConfig << endl;
	ofstream fout(fileName);
	if (fout.is_open())
	{
		fout << newConfig.c_str();
		fout.close();
	}
	return 0;
}


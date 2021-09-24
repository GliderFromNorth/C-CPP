// UpdateConfigFile.cpp : Defines the entry point for the console application.
// C:\Program Files\Sequretek\Kawach\endpoint\settings\debugControl.json

#pragma warning(disable : 26812)
#pragma warning(disable : 4996)
#include <iostream>
#include <json\json.h>
#include <json\value.h>
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
	Json::Reader reader;
	Json::Value root;
	if (argc != 4)
	{
		cout << "Error: Invalid arguments \nUsage: ReadLastIndex.exe \"Complete\\File\\Path\"\n";
		return 0;
	}
	string fileName = argv[1];
	string Key = argv[2];
	string Value = argv[3];
	if (PathFileExistsA(fileName.c_str()) != TRUE)
	{
		cout << "Error: File does not exist\n";
		return 0;
	}
	else
	{

		std::cout << "Index file: " << fileName << endl;
		cout << endl;
		cout << endl;
		std::ifstream debug_file(fileName);
		bool parsingsuccessful = reader.parse(debug_file, root); //or : debug_file >> root;
		if (!parsingsuccessful) cout << "Error: Parsing Failed\n";
		cout << root << endl;  //printing whole object
		cout << endl;
		cout << "Sandbox : " << root[Key] << endl;   //printig default key value
		cout << endl;
		root[Key] = Value;  //making changes to given key value
		cout << endl;

		Json::StyledWriter writer;
		std::string outputConfig = writer.write(root);
		/*cout << "ransomware : " << root["ransomware"] << endl;
		cout << "registryScan : " << root["registryScan"] << endl;
		cout << endl;*/
		/*std::string encoding = root["fileReputation"].get("fileReputation", "Not found").asString();
		cout << encoding << endl;*/
		cout << Key + " : " << root[Key] << endl;
		cout << endl;
		cout << outputConfig << endl;
		cout << endl;
		ofstream fout;
		fout.open(fileName, ios::out);
		fout << outputConfig;
		fout.close();

	}

	return 0;
}
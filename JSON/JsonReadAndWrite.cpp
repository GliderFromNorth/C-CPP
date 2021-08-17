// JsonReadAndWrite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <json\json.h>
#include <json\value.h>

using namespace std;



int main()
{
	ofstream fout;
	fout.open("sample.json", ios::app);

	std::ifstream people_file("alice.json");
	Json::Value people;
	people_file >> people;
	
	cout << people<<endl; //This will print the entire json object.

	// Printing Content to sample.json file.
	
	fout << people;
	fout.close();
	system("pause");
}
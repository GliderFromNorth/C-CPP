// recursiveFilesListingUsingFilesystem.cpp : Defines the entry point for the console application.
//Version Task completed.
#include "stdafx.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <time.h>
namespace fs = std::experimental::filesystem;
using namespace std;
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

string SplitFilename(const std::string& str) {
	//std::cout << "Splitting: " << str << '\n';
	unsigned found = str.find_last_of("/\\");
	//std::cout << " path: " << str.substr(0, found) << '\n';
	//std::cout << " file: " << str.substr(found + 1) << '\n';
	return str.substr(found + 1);
}


int main() {
	
	int count = 0;
	std::ofstream fout;
	fout.open("filenames.txt", std::ios::app);
	std::string path = "C:\\Windows\\";
	for (auto& p : fs::recursive_directory_iterator(path))
	{
		
		
		if (!fs::is_directory(p.path()))
		{
			// File Size Calculation
			std::uintmax_t size = file_size(p.path());
			// Last tiem modifed time 
			auto modifiedTime = fs::last_write_time(p.path());
			time_t cftime = chrono::system_clock::to_time_t(modifiedTime);
			//Prnting and writing the details to file.
			std::cout << p.path()<< "    ||     "<< SplitFilename(p.path().string().c_str())<< "    ||     " <<size << "    ||     " << std::asctime(std::localtime(&cftime)) <<endl;     // Prints output to console
			fout<< p.path() << "    ||     " << SplitFilename(p.path().string().c_str()) << "    ||     " <<size << "    ||     " << std::asctime(std::localtime(&cftime)) << endl; // Prints output to file "fileDetails.txt".
			count += 1;
		
		}
	
	}
	fout.close();	
	std::cout << count <<std::endl;
	system("pause");
}
// SystemDateAndTime.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

int main()
{
	time_t my_time = time(0);
	string time = ctime(&my_time);

	cout << "The system day and time are : " << time;
	system("pause");
	return 0;
}


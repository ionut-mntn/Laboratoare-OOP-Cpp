// lab4oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <windows.h>
//#include <exception>

#include "UserInterface.h"
#include"Tests.h"

using std::cout;

int main()
{
	/*
	float a = 58.6;
	float b = 58.6;
	assert(a == b);
	*/

	testAll();

	UserInterface ui;
	ui.start();
	
	
	/*
	vector<int> temp;
	int index = 0;
	
	cout << "trece";
	temp[index] = 2;
	cout << "trece";
	/*
	temp.push_back(2);
	//temp.insert(5,1);
	
	for (int i = 0; i < temp.size(); i++)
		cout << temp.at(i) << '\n';
	*/

	/*
	system("Color 1A");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color 2B");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color 3C");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color 4D");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color 5E");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color 6F");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color A1");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color B2");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color C3");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color D4");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color E5");
	std::cout << "\t\t\t    Hello World" << std::endl;
	cin.get();
	system("Color F6");
	std::cout << "\t\t\t    Hello World" << std::endl;
	*/

	/*
	const WORD colors[] =
	{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	// Tell the user how to stop
	SetConsoleTextAttribute(hstdout, 0xEC);
	std::cout << "Press any key to quit.\n";

	// Draw pretty colors until the user presses any key
	while (WaitForSingleObject(hstdin, 100) == WAIT_TIMEOUT)
	{
		SetConsoleTextAttribute(hstdout, colors[index]);
		std::cout << "\t\t\t\t Hello World \t\t\t\t" << std::endl;
		if (++index > sizeof(colors) / sizeof(colors[0]))
			index = 0;
	}
	FlushConsoleInputBuffer(hstdin);

	// Keep users happy
	SetConsoleTextAttribute(hstdout, csbi.wAttributes)
	*/
}



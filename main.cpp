#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"
/*
*	Instructions:
* Complete the following program accordingly as explained in the stream. If you can't do it contact me
*/

// Helper functions
void INCREAS_SIZE(Cafe*& _PTR, size_t& _SIZE)
{

}
void CLEAR_FLAG(std::string& _STRING, char _flag = '\n', int _pos = 0)
{
	if (_STRING[_pos] == _flag)
	{
		_STRING = std::string(_STRING.begin() + 1, _STRING.end());
	}
}

int INITIALIZE(Cafe*& ENTRY)
{
	//	Read the file
	std::ifstream handle("input.txt");
	std::string** content = nullptr;
	std::string _BUFF;
	size_t _line_count = 0;
	if (handle.is_open())
	{
		while (std::getline(handle, _BUFF, '\n'))
		{
			_line_count++;
		}
		handle.clear();
		handle.seekg(0, std::fstream::beg);
		ENTRY = new Cafe[_line_count];
		content = new std::string * [_line_count];
		for (size_t i = 0; i < _line_count; i++)
		{
			content[i] = new std::string[4];
		}
		for (size_t i = 0; i < _line_count; i++)
		{
			std::getline(handle, content[i][0], ';');
			CLEAR_FLAG(content[i][0]);
			std::getline(handle, content[i][1], ';');
			std::getline(handle, content[i][2], ';');
			std::getline(handle, content[i][3], ';');
			ENTRY[i].setDrink(std::stoi(content[i][0]),
				content[i][1],
				std::stod(content[i][2]),
				std::stoi(content[i][3]));
		}
		for (size_t i = 0; i < _line_count; i++)
		{
			delete[]content[i];
		}
		delete content;
	}
	else
	{
		std::cout << "File error";
		return 1;
	}
	return 0;
}
int main()
{
	Cafe* ENTRY = nullptr;
	int _Error = INITIALIZE(ENTRY);
	if (_Error != 0)
	{
		// Process the errors
		exit(0);
	}
	// USER SPACE STARTS HERE
	bool bExit = false;
	while (!bExit)
	{
		bool bValid = false;
		int input;
		// Display the menu
		std::cout << "Welcome to He&She Coffee" << std::endl;
		std::cout << "What do you want to do?" << std::endl;
		std::cout << "1- Enter the selling interface" << std::endl
			<< "2- Get report" << std::endl;
		while (!(std::cin >> input) || !bValid)
		{
			if (input != 1 && input != 2)
			{
				bValid = false;
			}
			else
			{
				break;
			}
			std::cout << "There's been an error, please try again" << std::endl;
		}
		switch (input)
		{
		case 1:
		{
			// SHOW THE INTERFACE
		}
			break;
		case 2:
		{
			// Display everything meaning every sale
		}
			break;
		default:
			break;
		}
	}
}

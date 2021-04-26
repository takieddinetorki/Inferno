#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"
// Helper functions
void INCREAS_SIZE(Cafe*& _PTR, size_t& _SIZE)
{
	// This function will increase the size of the given array of objects
}
void CLEAR_FLAG(std::string& _STRING, char _flag = '\n', int _pos = 0)
{
	if (_STRING[_pos] == _flag)
	{
		_STRING = std::string(_STRING.begin() + 1, _STRING.end());
	}
}
int main()
{
	//	Read the file
	std::ifstream handle("input.txt");
	std::string** content = nullptr;
	std::string _BUFF;
	size_t _line_count = 0;
	Cafe* ENTRY = nullptr;
	if (handle.is_open())
	{
		while (std::getline(handle, _BUFF, '\n'))
		{
			_line_count++;
		}
		handle.clear();
		handle.seekg(0, std::fstream::beg);
		ENTRY = new Cafe[_line_count];
		content = new std::string*[_line_count];
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
		}
		ENTRY->setMenu(content, _line_count);
		for (size_t i = 0; i < _line_count; i++)
		{
			delete[]content[i];
		}
		delete content;
	}
	else
	{
		std::cout << "File error";
		exit(1);
	}
}

#include "logic.h"
/*
* -----------------------------------------------------------------------
*	Class Sales implementation
* -----------------------------------------------------------------------
*/




/*
* -----------------------------------------------------------------------
*	Class Cafe implementation
* -----------------------------------------------------------------------
*/

void Cafe::setMenu(std::string* menu)
{
}

Cafe::Cafe() {}
Cafe::~Cafe() {}

void Menu::setMenu(std::string**& menu, size_t SIZE)
{
	MENU = new std::string * [SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		MENU[i] = new std::string[4];
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			MENU[i][j] = menu[i][j];
		}
	}
}

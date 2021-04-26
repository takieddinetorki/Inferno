#pragma once
#include <string>
class Sales;
class Menu;
class Cafe;
/// <summary>
/// Sales Class
///		Handles all of the calculations and the storage unit for the sales
/// </summary>
class Sales
{
public:
	Sales() {}
	~Sales() {}

private:

};
/// <summary>
/// Menu Class
///		This class handles everythign regarding the menu which we read from the main funciton
/// The menu is set via the setMenu() method which COPIES the content. IT DOES NOT SIMPLY POINT
/// IT COPIES THE WHOLE DATA. Thus, deleteing content** in main is safe.
/// 
/// </summary>
class Menu
{
public:
	friend Cafe; 
	Menu() {}
	~Menu() {}
	void setMenu(std::string**& menu, size_t SIZE);
private:
	std::string** MENU = nullptr;
};
/// <summary>
/// Class CAFE.
///		The "entry" point for our program. It is the middle class between SALES and MENU.
/// Handles everything from the main function.
/// </summary>
class Cafe : public Sales
{
public:
	std::string** getMenu()
	{
		return MENU.MENU;
	}
	void setMenu(std::string**& menu, size_t SIZE)
	{
		MENU.setMenu(menu, SIZE);
	}
	Cafe();
	~Cafe();

private:
	Menu MENU;
};


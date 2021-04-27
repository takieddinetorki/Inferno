#pragma once
#include <string>
#include <tuple>
class Sales;
class Drink;
class Cafe;
class Sales
{
public:
	void calculateSales(int QUANTITY, int PRICE)
	{
		TOTAL_QUANTITY += QUANTITY;
		TOTAL_SALES = TOTAL_SALES + (QUANTITY * PRICE);
	}
	Sales() { TOTAL_QUANTITY = 0; TOTAL_SALES = 0; }
	~Sales() {}

protected:
	unsigned int TOTAL_SALES;
	unsigned int TOTAL_QUANTITY;
};

class Drink
{
public:
	friend Cafe; 
	Drink() { DRINK_PRICE = 0; QUANTITY = 0; ID = 0; }
	void setDrink(int ID, std::string NAME, double price, int quantity)
	{
		DRINK_PRICE = price;
		QUANTITY = quantity;
		this->NAME = NAME;
		this->ID = ID;
	}
	~Drink() {}
private:
	double DRINK_PRICE; int QUANTITY, ID;
	std::string NAME;
};
class Cafe : public Sales
{
public:
	Drink getDrinkInfo()
	{
		return DRINK;
	}
	std::tuple<int, std::string, double, int> getDrink()
	{
		return std::make_tuple(DRINK.ID, DRINK.NAME, DRINK.DRINK_PRICE, DRINK.QUANTITY);
	}
	void getDrink(std::string*& DRINK_IFNO)
	{
		if (DRINK_IFNO == nullptr)
		{
			DRINK_IFNO = new std::string[4];
		}
		DRINK_IFNO[0] = std::to_string(DRINK.ID);
		DRINK_IFNO[1] = DRINK.NAME;
		DRINK_IFNO[2] = std::to_string(DRINK.DRINK_PRICE);
		DRINK_IFNO[3] = std::to_string(DRINK.QUANTITY);
	}
	void setDrink(int ID, std::string NAME, double price, int quantity)
	{
		DRINK.setDrink(ID, NAME, price, quantity);
	}
	Cafe() : DRINK() {}
	~Cafe() {}
private:
	Drink DRINK;
};


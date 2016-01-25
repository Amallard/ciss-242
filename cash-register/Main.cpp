// Adam Allard
// Week 7 Assignment 2
// This program displays a list of items to buy with quantities of how many of each are available. it prompts the 
// user which item to buy, then quantity. it will then display the total price after adding 30% profit and 6% sales tax.
// the program will subtract the amount just sold from the available menu

#include <iostream>
#include <iomanip>
#include "CashRegister.h"
#include "InventoryItem.h"
using namespace std;

void displayMenu(InventoryItem[], int, int&, int&);
void getOrder(int&, int&, InventoryItem[], int size);
void displayTotal(CashRegister);
bool buyAgain();

int main()
{
	const int SIZE = 5;
	int menuNumber, numUnits;

	InventoryItem tools[SIZE] = {
		InventoryItem("Adjustable Wrench", 15.00, 10),
		InventoryItem("Screwdriver",	   5.00,  20),
		InventoryItem("Pliers",			   7.00,  35),
		InventoryItem("Ratchet",		   10.00, 10),
		InventoryItem("Socket Wrench",	   12.00, 7 )};

	displayMenu(tools, SIZE, menuNumber, numUnits);

	cout << endl;
	system("pause");
	return 0;
}

// this function displays the menu with quanities of items and then calls the getOrder function
void displayMenu(InventoryItem array[], int size, int &menuNumber, int &numUnits)
{
	for (int i = 0; i < 80; i++)
		cout << char(196);
	cout << left << setw(5) << "#" << setw(20) << "Item" << setw(10) << "qty on Hand" << endl;
	for (int i = 0; i < 80; i++)
		cout << char(196);
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << (i + 1) << setw(20) << array[i].getDescription() << setw(10) << array[i].getUnits() << endl;
	}
	getOrder(menuNumber, numUnits, array, size);
}

// this function prompts the user which item they would like to buy and how many. it will validate the 
// item and quantity for proper entries
void getOrder(int &menu, int &units, InventoryItem array[], int size)
{
	bool checksGood = false,  // over all test
		testOne = false,      // test if units is above 0
		testTwo = false;      // test if units is less than or equal to the quantity left in stock

	cout << "Which item above is being purchased? ";
	cin >> menu;
	while (menu < 1 || menu > 5)
	{
		cout << "Invalid item selection." << endl;
		cout << "Which item above is being purchased? ";
		cin >> menu;
	}
	cout << "How many units? ";
	cin >> units;
	while (!checksGood)
	{
		while (units < 0)
		{
			cout << "Units cannot be less than 0." << endl;
			cout << "How many units would you like to buy? ";
			cin >> units;
			if (units > array[(menu - 1)].getUnits())
				testTwo = false;
		}
		testOne = true;

		// if units is greater than how many are left in stock
		while (units > array[(menu - 1)].getUnits())
		{
			cout << "ERROR: We only have " << array[(menu - 1)].getUnits() << " in stock." << endl;
			cout << "How many units would you like to buy? ";
			cin >> units;
			if (units < 0)
				testOne = false;
		}
		testTwo = true;

		// if both tests come back true, pass the function
		if (testOne == true && testTwo == true)
			checksGood = true;
	}

	CashRegister price(array[(menu-1)].getCost(), units);
	displayTotal(price);
	array[(menu - 1)].setUnitsSold(units);
	if (buyAgain())
		displayMenu(array, size, menu, units);
}

// this function displays the subtotal tax and total
void displayTotal(CashRegister totals)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "Subtotal:\t$" << totals.getSubtotal() << endl
		<< "Sales Tax:\t$" << totals.getSalesTax() << endl
		<< "Total:\t\t$" << totals.getPurchaseTotal() << endl;
}
 // this function prompts the user if they would like to make another purchase 
bool buyAgain()
{
	bool again = false;
	char let = '0';
	if (!again)
	{
		cout << "Do you want to purchase another item (Y or N)? ";
		cin >> let;
	}
	if (toupper(let) == 'Y')
		again = true;

	cout << endl;
	return again;
}
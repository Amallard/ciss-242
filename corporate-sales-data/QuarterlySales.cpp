// Adam Allard
// Week 4 Assignment 1
// This program has a structure that holds and displays data about each division within a corporation. 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Division
{
	string name;
	double qtr1Sales,
		   qtr2Sales,
		   qtr3Sales,
		   qtr4Sales,
		   annualSales,
		   avgSales;
};

void DisplayCorpInformation(const Division& east, 
							const Division& west,
							const Division& north, 
							const Division& south);
void FindTotalAndAverage(Division& div);
void GetDivisionSales(Division& div);

int main()
{
	Division east = { "East" },
			 west = { "West" },
			 north = { "North" },
			 south = { "South" };

	GetDivisionSales(east);
	GetDivisionSales(west);
	GetDivisionSales(north);
	GetDivisionSales(south);

	FindTotalAndAverage(east);
	FindTotalAndAverage(west);
	FindTotalAndAverage(north);
	FindTotalAndAverage(south);

	DisplayCorpInformation(east, west, north, south);

	cout << endl << endl;

	system("pause");
	return 0;
}

// this function displays each division's total and average sales
void DisplayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south)
{
	cout << setprecision(2) << fixed;
	cout << endl << "Total Annual Sales:";
	cout << endl << "\tEast Division:  $" << east.annualSales;
	cout << endl << "\tWest Division:  $" << west.annualSales;
	cout << endl << "\tNorth Division: $" << north.annualSales;
	cout << endl << "\tSouth Division: $" << south.annualSales;

	cout << endl << "Average Quarterly Sales:";
	cout << endl << "\tEast Division:  $" << east.avgSales;
	cout << endl << "\tWest Division:  $" << west.avgSales;
	cout << endl << "\tNorth Division: $" << north.avgSales;
	cout << endl << "\tSouth Division: $" << south.avgSales;
}

// this function accepts a division and finds the average and total sales
void FindTotalAndAverage(Division& div)
{
	div.annualSales = (div.qtr1Sales + div.qtr2Sales + div.qtr3Sales + div.qtr4Sales);
	div.avgSales = div.annualSales / 4;
}

// this function prompts the user to enter in the sales info for a division 
// and tests the input for a positive entry
void GetDivisionSales(Division& div)
{
	cout << "Enter the quarterly sales for the " << div.name << " Division:" << endl;

	cout << "\tFirst quarter:   ";
	cin >> div.qtr1Sales;
	while (div.qtr1Sales < 0)
	{
		cout << "\tERROR: Sales cannot be negative." << endl;
		cout << "\tFirst quarter:   ";
		cin >> div.qtr1Sales;
	}

	cout << "\tSecond quarter:  ";
	cin >> div.qtr2Sales;
	while (div.qtr1Sales < 0)
	{
		cout << "\tERROR: Sales cannot be negative." << endl;
		cout << "\tFirst quarter:   ";
		cin >> div.qtr1Sales;
	}

	cout << "\tThird quarter:   ";
	cin >> div.qtr3Sales;
	while (div.qtr1Sales < 0)
	{
		cout << "\tERROR: Sales cannot be negative." << endl;
		cout << "\tFirst quarter:   ";
		cin >> div.qtr1Sales;
	}

	cout << "\tFourth quarter:  ";
	cin >> div.qtr4Sales;
	while (div.qtr1Sales < 0)
	{
		cout << "\tERROR: Sales cannot be negative." << endl;
		cout << "\tFirst quarter:   ";
		cin >> div.qtr1Sales;
	}
}

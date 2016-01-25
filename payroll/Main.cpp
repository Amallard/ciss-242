// Adam Allard
// Week 7 Assignment 1
// this program calculates 7 employees weekly pay. it creates an array of 7 Payroll objects and assigns
// a pay rate for each employee. 

#include <iostream>
#include <iomanip>
#include "Payroll.h"
using namespace std;

int main()
{
	double hours;

	Payroll employeesPay[7];

	employeesPay[0].setPayRate(10.00);
	employeesPay[1].setPayRate(11.00);
	employeesPay[2].setPayRate(12.00);
	employeesPay[3].setPayRate(13.00);
	employeesPay[4].setPayRate(14.00);
	employeesPay[5].setPayRate(15.00);
	employeesPay[6].setPayRate(16.00);

	// prompt user for how many hours each employee worked 
	for (int i = 0; i < 7; i++)
	{
		cout << "Enter the hours worked by Employee " << (i + 1) << " : ";
		cin >> hours;
		// validate a user "cant" work over 60 hours a week
		while (hours > 60)
		{
			cout << "Hours cannot be above 60 (unless you're in the military...)" << endl
				<< "Enter the hours worked by Employee " << (i + 1) << " : ";
			cin >> hours;
		}
		employeesPay[i].setHoursWorked(hours);
	}

	// display the employees' week pay
	for (int i = 0; i < 7; i++)
	{
		cout << "Employee " << (i + 1) << " pay: $" << employeesPay[i].getWeeksPay() << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}
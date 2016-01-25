// Adam Allard
// Week 7 Assignment 1
// this Payroll implementation has a default constructor that sets the object attributes to 0, 2 setter functions that 
// assign their arguemtn to its respective attribute, and 3 getter functions that return their attribute and the weekspay

#include "Payroll.h"
using namespace std;

// default constructor
Payroll::Payroll()
{
	payRate = 0.0;
	hoursWorked = 0.0;
}

// setters
void Payroll::setPayRate(double pay)
	{ payRate = pay; }

void Payroll::setHoursWorked(double hours)
	{ hoursWorked = hours;}

// getters
double Payroll::getPayRate() const
	{ return payRate;}

double Payroll::getHoursWorked() const
	{ return hoursWorked;}

double Payroll::getWeeksPay() const
{ 
	// regular pay
	if (hoursWorked <= 40)
	{
		return (payRate * hoursWorked);
	}
	// overtime pay, if only, i'd be a millionaire.. well close, maybe
	else
	{
		return ((payRate*40) + (payRate*1.5*(hoursWorked-40)));
	}
}




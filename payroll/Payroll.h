// Adam Allard
// Week 7 Assignment 1
// this payroll header declares 2 member variables, one default constructor, 2 setters, and 3 getters 

#ifndef PAYROLL_H
#define PAYROLL_H

class Payroll
{
private:
	// member variables
	double payRate;
	double hoursWorked;
public:
	// default construstor
	Payroll();

	// setters
	void setPayRate(double);
	void setHoursWorked(double);

	// getters
	double getPayRate() const;
	double getHoursWorked() const;
	double getWeeksPay() const;
};
#endif
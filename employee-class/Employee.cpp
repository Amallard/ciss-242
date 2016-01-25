// Adam Allard
// Week 6 Assignment 1 *** Employee.cpp ***
// This implementation file has 3 constructors and assigns the attributes to the passed arguements and sets 
// default data for the others. the class has 4 setters to set each attribute of the Employee class, and 4 getters
// to return the attributes about the class. NOTE* with the simplicity of this class, everything could've been inlined 
// in the header file for a cleaner look, but for the scope of learning I understand why we needed to create the .cpp 

#include "Employee.h"
#include <string>
using namespace std;

// 4 arg constructor
Employee::Employee(string n, int i, string d, string p)
{
	name = n;
	idNum = i;
	dept = d;
	position = p;
}

// 2 arg constructor - sets default data to dept and position
Employee::Employee(string n, int i)
{
	name = n;
	idNum = i;
	dept = " ";
	position = " ";
}

// no arg constructor - sets detault data for all attributes
Employee::Employee()
{
	name = " ";
	idNum = 0;
	dept = " ";
	position = " ";
}



// setters - set the corresponding member variable to the passed arguement
void Employee::setName(string n)
	{ name = n; }

void Employee::setIdNum(int i)
	{ idNum = i; }

void Employee::setDept(string d)
	{ dept = d; }

void Employee::setPosition(string p)
	{ position = p; }



// getters - return the member variable 
string Employee::getName() const
	{ return name; }

int Employee::getIdNum() const
	{ return idNum; }

string Employee::getDept() const
	{ return dept; }

string Employee::getPosition() const
	{ return position; }


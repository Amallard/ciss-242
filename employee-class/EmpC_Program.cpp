// Adam Allard
// Week 6 Assignment 1 *** Program ***
// This program creates 3 instances of the Employee class with 3 different constructors. 
// the program creates 3 object pointers to the 3 Employee objects and passes the pointers to
// the displayEmployee function which calls the Employee class's getter functions to display 
// the objects data 

#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"
using namespace std;


void displayEmployee(Employee*);


int main() {
	// create an first instance of Employee using 4 arg constructor
	Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
	// create pointer to first object
	Employee *emp1Ptr = nullptr;
	emp1Ptr = &emp1;

	// create a second instance of Employee using 2 arg constructor
	Employee emp2("Mark Jones", 39119);
	// set remaining 2 attributes of object
	emp2.setDept("IT");
	emp2.setPosition("Programmer");
	// create pointer to second object
	Employee *emp2Ptr = nullptr;
	emp2Ptr = &emp2;

	// create a third instance of Employee using no arg constructor
	Employee emp3;
	// set all 4 attributes of object
	emp3.setName("Joy Rogers");
	emp3.setIdNum(81774);
	emp3.setDept("Manufacturing");
	emp3.setPosition("Engineer");
	// create pointer to third object
	Employee *emp3Ptr = nullptr;
	emp3Ptr = &emp3;

	// format and display data
	cout << left;
	cout << setw(15) << "Name" 
		 << setw(13) << "ID Number" 
		 << setw(20) << "Department" 
		 << setw(25) << "Position" << endl;
	// this for loop simply displays a line across the terminal 
	for (int i = 0; i < 80; i++)
		cout << char(196);

	// calling displayEmployee function with pointers to Employee objects to display data
	displayEmployee(emp1Ptr);
	displayEmployee(emp2Ptr);
	displayEmployee(emp3Ptr);

	cout << endl;
	system("pause");
	return 0;
}


// this function accepts a pointer to an Employee object and calls the classes member functions to display its data
void displayEmployee(Employee* e) {
	cout << setw(15) << e->getName() 
		 << setw(13) << e->getIdNum() 
		 << setw(20) << e->getDept() 
		 << setw(25) << e->getPosition() << endl;
}
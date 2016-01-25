// Adam Allard
// Week 6 Assignment 2
// this program creates 2 Circle objects using 2 different constructors. The program then passes an object pointer to 
// the displayCircle function which uses to classes getters to display the information about the circle

#include <iostream>
#include <iomanip>
#include "Circle.h"
using namespace std;


void displayCircle(Circle*);


int main()
{
	double radius;

	// get radius from the user for one Circle object
	cout << "Let's create a Circle object with a 1 arg constructor" << endl << endl;
	cout << "What is the circle's radius: ";
	cin >> radius;
	cout << endl;

	// now creating a Circle object with a 1 arg constructor
	Circle cir1(radius);
	Circle *cir1Ptr = nullptr;
	cir1Ptr = &cir1;
	// pass the object pointer to the displayCircle function to get and display its data 
	displayCircle(cir1Ptr);
	cout << endl << endl;

	// now getting info about another Circle object
	cout << "Now we will create an object with a no arg constructor." << endl << endl;
	cout << "What is the circle's radius: ";
	cin >> radius;
	cout << endl;

	// creating a Circle object with a no arg constructor
	Circle cir2;
	cir2.setRadius(radius);
	Circle *cir2Ptr = nullptr;
	cir2Ptr = &cir2;
	// pass the object pointer to the displayCircle function to get and display its data 
	displayCircle(cir2Ptr);

	cout << endl;
	system("pause");
	return 0;
}

// this function accepts a Circle object pointer and gets its member functions to display its data 
void displayCircle(Circle* c)
{
	cout << left;
	cout << setw(16) << "Area:"				<< c->getArea()				<< endl
		 << setw(16) << "Diameter:"			<< c->getDiameter()			<< endl 
		 << setw(16) << "Circumference:"	<< c->getCircumference()	<< endl;
}
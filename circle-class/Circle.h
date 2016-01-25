// Adam Allard
// Week 6 Assignment 2
// this Circle class header file declares 2 member variables, 2 constructors (a no arg and a 1 arg), 
// a mutator function, and 4 accessor functions 

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	// member variables 
	double radius;
	double pi;
public:
	// constructors 
	Circle();
	Circle(double);

	// setters
	void setRadius(double);

	// getters 
	double getRadius() const;
	double getArea() const;
	double getDiameter() const;
	double getCircumference() const;
};
#endif
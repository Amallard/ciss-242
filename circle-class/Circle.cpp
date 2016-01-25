// Adam Allard
// Week 6 Assignment 2
// this Circle class implementation file has 2 constructors that both set pi to 3.14159, one of them accepts a radius argument
// and the other sets radius to 0. this class has 4 getter methods that can return a circle's radius, area, diameter, and circumference

#include "Circle.h"
using namespace std;

// no arg constructor
Circle::Circle()
{
	radius = 0.0;
	pi = 3.14159;
}

// 1 arg constructor
Circle::Circle(double rad)
{
	radius = rad;
	pi = 3.14159;
}

// setters
void Circle::setRadius(double rad)
	{ radius = rad; }

// getters 
double Circle::getRadius() const
	{ return radius; }

double Circle::getArea() const
{
	double area = pi * radius * radius;
	return area;
}

double Circle::getDiameter() const
{
	double diameter = radius * 2;
	return diameter;
}

double Circle::getCircumference() const
{
	double circumference = 2 * pi * radius;
	return circumference;
}
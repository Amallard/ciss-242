// Adam Allard
// Course Project
// This DVD implementation file makes use of 2 constructors, 5 setters, and 5 getter methods
// all of which are used to create DVD objects.

#include "DVD.h"

// constructors
DVD::DVD()
{
	// no arg constructor assigns the title as (empty) and everything else zero.
	title = "(empty)";
	movieLength = 0;
	year = 0;
	actor1 = "0";
	actor2 = "0";
}

DVD::DVD(string t)
{
	// this constructor accepts a string as its title and assigns everything else zero
	title = t;
	movieLength = 0;
	year = 0000;
	actor1 = "";
	actor2 = "";
}

// setters 
void DVD::setTitle(string t)
{
	title = t;
}
void DVD::setMovieLength(int m)
{
	movieLength = m;
}
void DVD::setYear(int y)
{
	year = y;
}
void DVD::setActor1(string a)
{
	actor1 = a;
}
void DVD::setActor2(string a)
{
	actor2 = a;
}

// getters
string DVD::getTitle() const
{
	return title;
}
int DVD::getMovieLength() const
{
	return movieLength;
}
int DVD::getYear() const
{
	return year;
}
string DVD::getActor1() const
{
	return actor1;
}
string DVD::getActor2() const
{
	return actor2;
}
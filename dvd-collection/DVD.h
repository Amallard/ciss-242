// Adam Allard
// Course Project
// This header file defines the DVD class with a default constructor, a 1 arg constructor, 5 setters methods and 5 getter methods 

#ifndef DVD_H
#define DVD_H
#include <string>
using namespace std;

class DVD
{
private:
	string title;
	int movieLength;
	int year;
	string actor1;
	string actor2;

public:
	// constructors
	DVD();
	DVD(string t);

	// setters 
	void setTitle(string t);
	void setMovieLength(int m);
	void setYear(int y);
	void setActor1(string a);
	void setActor2(string a);

	// getters
	string getTitle() const;
	int getMovieLength() const;
	int getYear() const;
	string getActor1() const;
	string getActor2() const;
};
#endif // !DVD.H

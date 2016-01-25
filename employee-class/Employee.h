// Adam Allard
// Week 6 Assignment 1 *** Employee.h ***
// This Employee class header file declares the 4 member variables, 3 constructors (a no arg, a 2 arg, and a 4 arg)
// 4 setter functions, and 4 getter functions 

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
	// member variables 
	private:
		string name;
		int idNum;
		string dept;
		string position;

	// member functions 
	public:
		// constructors 
		Employee(string n, int i, string d, string p);
		Employee(string n, int i);
		Employee();

		// setters 
		void setName(string n);
		void setIdNum(int i);
		void setDept(string d);
		void setPosition(string p);

		// getters 
		string getName() const;
		int getIdNum() const;
		string getDept() const;
		string getPosition() const;
};
#endif
// Adam Allard
// Course Project
// This header file defines the DVD_Manager class with 3 mutator methods that
// are used to manage the DVD class objects 

#ifndef DVD_MANAGER_H
#define DVD_MANAGER_H
#include <iostream>
#include "DVD.h"

class DVD_Manager
{
private:
	
public:
	void addDVD(DVD&);
	void deleteDVD(DVD&);
	void updateDVD(DVD&);
};

#endif // !DVD_MANAGER.H

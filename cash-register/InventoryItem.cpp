#include "InventoryItem.h"

// Private member function.
void InventoryItem::createDescription(int size, char *value)
{ 
    // Allocate the default amount of memory for description.
    description = new char [size+1];

    // Store a value in the memory.
    strcpy_s(description, size+1, value); 
}

// Constructor #1
InventoryItem::InventoryItem()
{ 
    // Store an empty string in the description
    // attribute.
    createDescription(DEFAULT_SIZE, "");

    // Initialize cost and units.
    cost = 0.0;
    units = 0; 
	unitsSold = 0;
}

// Constructor #2
InventoryItem::InventoryItem(char *desc)
{ 
    // Allocate memory and store the description.
    createDescription(strlen(desc), desc); 

    // Initialize cost and units.
    cost = 0.0;
    units = 0;
	unitsSold = 0;
}

// Constructor #3
InventoryItem::InventoryItem(char *desc, double c, int u)
{ 
    // Allocate memory and store the description.
    createDescription(strlen(desc), desc); 

    // Assign values to cost and units.
    cost = c;
    units = u; 
	unitsSold = 0;
}      

// Destructor
InventoryItem::~InventoryItem()
{
    delete [] description; 
}

// Mutator functions
void InventoryItem::setDescription(char *d) 
{
    //strcpy(description, d); 
	if (strlen(description) != strlen(d))
		delete [] description;

	createDescription(strlen(d), d);

}

void InventoryItem::setCost(double c)
{
    cost = c; 
}

void InventoryItem::setUnits(int u)
{
    units = u; 
	units -= unitsSold;
}

void InventoryItem::setUnitsSold(int d)
{
	unitsSold = d;
	setUnits(units);
}

// Accessor functions
const char *InventoryItem::getDescription() const
{
    return description; 
}

double InventoryItem::getCost() const
{
    return cost; 
}

int InventoryItem::getUnits() const
{
    return units; 
}

int InventoryItem::getUnitsSold() const
{
	return unitsSold;
}
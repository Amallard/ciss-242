// Adam Allard
// Week 7 Assignment 2
// this CashRegister header file declares 6 member variables, one constructor, 4 setters, and 4 getters 

#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "InventoryItem.h"

class CashRegister
{
private:
	double cost;
	int units;
	double unitPrice;
	double subtotal;
	double salesTax;
	double purchaseTotal;
public:
	// constructor 
	CashRegister(double, int);

	// setters 
	void setUnitPrice();
	void setSubtotal();
	void setSalesTax();
	void setPurchaseTotal();

	// getters
	double getUnitPrice() const;
	double getSubtotal() const;
	double getSalesTax() const;
	double getPurchaseTotal() const;
};

#endif
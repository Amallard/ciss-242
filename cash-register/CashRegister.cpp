// Adam Allard
// Week 7 Assignment 2
// this CashRegister implementation file one constructor and assigns the arguements to the cost and units. 
// the constructor then sets all the setter functions. 

#include "CashRegister.h"
#include "InventoryItem.h"

// constructor
CashRegister::CashRegister(double c, int u)
{
	cost = c;
	units = u;
	setUnitPrice();
	setSubtotal();
	setSalesTax();
	setPurchaseTotal();
}

// this setter function assigns the unit price to the cost with 30% profit
void CashRegister::setUnitPrice()
	{ unitPrice = (cost * 0.30) + cost;}

// this setter function assigns the subtotal to the unit price times the quantity
void CashRegister::setSubtotal()
	{ subtotal = unitPrice * units;}

// this setter function sets the sales tax to the subtotal times 6%
void CashRegister::setSalesTax()
	{ salesTax = subtotal * .06;}

// this setter function sets the purchase total to the subtotal plus the sales tax 
void CashRegister::setPurchaseTotal()
	{ purchaseTotal = subtotal + salesTax;}


// getter functions return their respective attributes 
double CashRegister::getUnitPrice() const
	{ return unitPrice;}

double CashRegister::getSubtotal() const
	{ return subtotal;}

double CashRegister::getSalesTax() const
	{ return salesTax;}

double CashRegister::getPurchaseTotal() const
	{ return purchaseTotal;}
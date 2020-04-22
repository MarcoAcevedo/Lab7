#pragma once
#include <string>
#include <iostream>
#include "Item.h"
#include "Date.h"

using namespace std;

class Receipt{

private:
	string customer_name;
	Item* items;
	int numItems;
	Date date;
	double TotalQuantity;

public:
	Receipt();
	Receipt(string, Item*, int, Date);
	~Receipt();

	void setCustomerName(string);
	string	getCustomerName();

	void setDate(Date);
	Date getDate();

	void setTotalQuantity(double);
	double getTotalQuantity();

	void setItems(Item[],int);
	Item * getItems();

	void setNumItems(int);
	int getNumItems();

	string toString();
};


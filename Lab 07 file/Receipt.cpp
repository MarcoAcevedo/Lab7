#include "Receipt.h"

Receipt::Receipt() {
	this->customer_name = "Empty Name";
	this->items = new Item[1024];
	this->numItems = 0;
	this->date = Date();
	this->TotalQuantity = 0;
}
Receipt::Receipt(string name, Item itemArr[], int numberOfItems, Date date) {
	this->customer_name = name;
	this->items = itemArr;
	this->numItems = numberOfItems;
	this->date = date;
	this->TotalQuantity = this->getTotalQuantity();
}
Receipt::~Receipt() {
	this->customer_name = "";
	this->items = NULL;
	this->numItems = NULL;
	this->TotalQuantity = NULL;
}

void Receipt::setCustomerName(string name) {
	this->customer_name = name;
}
string Receipt::getCustomerName() {
	return this->customer_name;
}

void Receipt::setDate(Date date) {
	this->date = date;
}
Date Receipt::getDate() {
	return this->date;
}

void Receipt::setTotalQuantity(double tq) {
	this->TotalQuantity = tq;
}
double Receipt::getTotalQuantity() {
	double total=0;

	for (int i = 0; i < this->numItems; i++) {
		total += this->items[i].getPrice();
	}
	this->TotalQuantity = total;
	return this->TotalQuantity;
}

void Receipt::setItems(Item itemArr[], int size) {
	delete this->items;
	this->items = new Item[size];
	this->items = itemArr;
	this->setTotalQuantity(this->getTotalQuantity());
}
Item * Receipt::getItems() {
	return this->items;
}

void Receipt::setNumItems(int i) {
	this->numItems = i;
}
int Receipt::getNumItems() {
	return this->numItems;
}

string Receipt::toString() {
	string rtn = "";
	rtn += "Customer: "+this->customer_name + "\t" +"Date: "+ this->date.toString()+"\n";

	for (int i = 0; i < this->numItems;i++) {
		rtn += items[i].getName();
		rtn += "\t\t";
		rtn += to_string(items[i].getPrice());
		rtn += "\n";
	}

	rtn += "Total num items = " + to_string(this->numItems);
	rtn += "\n";
	rtn += "Subtotal: \t\t" + to_string(getTotalQuantity());

	return rtn;
}
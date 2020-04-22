#include "Item.h"

Item::Item() {
	this->name = "";
	this->price = 0;
}
Item::Item(string n, double p) {
	this->name = n;
	this->price = p;
}
Item::~Item() {
	this->name = "";
	this->price = NULL;
}

string Item::getName() {
	return this->name;
}
void Item::setName(string n) {
	this->name = n;
}

double Item::getPrice() {
	return this->price;
}
void Item::setPrice(double p) {
	this->price = p;
}

string Item::toString() {
	string rtn = "";
	rtn += this->getName();
	rtn += "\t";
	rtn += to_string(this->getPrice());
	return rtn;
}
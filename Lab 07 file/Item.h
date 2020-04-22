#pragma once 
#include <string>
#include <iostream>
using namespace std;

class Item{
private: 
	string name;
	double price;

public:
	Item();
	Item(string, double);
	~Item();

	string getName();
	void setName(string);

	double getPrice();
	void setPrice(double);

	string toString();
};


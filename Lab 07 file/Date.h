#pragma once
#include <string>
#include<iostream>
using namespace std;

class Date{
public:
	Date();
	Date(int, int, int);
	~Date();

private:
	int day, month, year;

public:
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	bool isLeapYear();
	bool isValidDate();
	void print();
	string toString();
};
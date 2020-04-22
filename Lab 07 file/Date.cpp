#include "Date.h"


Date::Date() {
	this->day = 1;
	this->month = 1;
	this->year = 1;
}

Date::Date(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
}

Date::~Date() {
	this->day = NULL;
	this->month = NULL;
	this->year = NULL;
}

int Date::getDay() {
	return 	this->day;
}

int Date::getMonth() {
	return 	this->month;
}

int Date::getYear() {
	return 	this->year;
}

void Date::setDay(int d) {
	this->day = d;
}

void Date::setMonth(int m) {
	this->month = m;
}

void Date::setYear(int y) {
	this->year = y;
}

bool Date::isLeapYear() {
	if (this->year % 400 == 0) {
		return true;
	}
	if (this->year % 100 == 0) {
		return false;
	}
	if (this->year % 4 == 0) {
		return true;
	}

	return false;
}

bool Date::isValidDate() {
	if (this->year < 1) {
		return false;
	}
	if (this->month < 1 || this->month >12) {
		return false;
	}
	if ((this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) && (this->day > 0 && this->day < 32)) {
		return true;
	}
	if (this->month == 2) {
		if (this->isLeapYear() && (this->day > 0 && this->day < 30)) {
			return true;
		}
		else {
			return (this->day > 0 && this->day < 29);
		}
	}
	return (this->day > 0 && this->day < 31);

}

void Date::print() {
	cout << this->day;
	cout << "\\";
	cout << this->month;
	cout << "\\";
	cout << this->year;
	cout << "\n";
}

string Date::toString() {
	string rtn = "";
	rtn += to_string(this->month);
	rtn += "/";
	rtn += to_string(this->day);
	rtn += "/";
	rtn += to_string(this->year);
	return rtn;
}
#include "Receipt.h"
#include "Date.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <ctime> 
#include <algorithm>
#include<fstream>

using namespace std;

void menu();
bool selectOption();
void newOrder();
void printReceit();
void delay(int);
bool inputYesorNo(string);
Date addDate();

int printQueue = 0;
bool exitVar = false;
char inputChar;
Receipt receipts[1024];
int receipt_array_size = 0;

int main() {
	while (!exitVar) {
		menu();
		exitVar = selectOption();
	}
}

void menu() {
	system("CLS");
	cout << "Receipt System: Type option, then press Enter\n\n";
	cout << "1. Enter a new order\n";
	cout << "2. Print reciept. Saves last receipt to the system drive. (Creates file)\n";
	cout << "3. Exit\n\n";
}

bool selectOption() {

	cin >> inputChar;

	switch (inputChar) {
	case '1'://Enter a new order
		newOrder();
		return false;
		break;

	case '2'://Print reciept
		printReceit();
		return false;
		break;

	case '3'://Exit
		cout << "Shutting Down.";
		delay(1);
		return true;
		break;

	default:
		system("CLS");
		cout << "\nInvalid menu selection. Type option number only then press 'Enter'\n";
		cin.clear();
		cin.ignore(10000, '\n');
		delay(1);
		return false;
		break;
	}

	return false;
}

void newOrder() {
	string item_name;
	double item_price;
	int purchased_items_counter = 0;
	Item* purchased_items =new Item[1024];
	string customer_name;
	Date purchase_date;
	double subtotal = 0;

	system("CLS");

	cout << "Enter Customer's Name; then press 'Enter'\n";
	cin >> customer_name;
	cout << "\n";

	cout << "Enter Today's Date. Keep in mind the following format: Month/day/Year\n";
	purchase_date = addDate();
	cout << "\n";

	cout << "Enter Item Name\n";
	cin >> item_name;

	cout << "Enter " + item_name + "'s price\n";
	cin >> item_price;

	//Create Objet of type Item with user given inputs
	Item new_item = Item(item_name, item_price);

	//Save Object of type Item to an array
	purchased_items[purchased_items_counter++] = new_item;

	//Ask the user if need to enter more items
	while (inputYesorNo("\nStill need to enter item's?\n 'y' for yes; 'n' for no.\n")) {
		cout << "Enter Item Name\n";
		cin >> item_name;

		cout << "Enter " + item_name + "'s price\n";
		cin >> item_price;

		//Create Objet of type Item with user given inputs
		Item new_item = Item(item_name, item_price);

		//Save Object of type Item to an array
		purchased_items[purchased_items_counter++] = new_item;
	}

	//Create a receipt with all of the items purchased
	Receipt new_receipt = Receipt(customer_name, purchased_items, purchased_items_counter, purchase_date);

	receipts[receipt_array_size++] = new_receipt;

	cout << "\nReceipt succesfully created. Enter menu option 2 to print the receipt\n";
	delay(1);
}

void printReceit() {
	int temp = printQueue;
	string fileName = "receipt-"+to_string(temp)+".txt";
	string filePath="";
	//filePath = "C:\\Users\\marco\\Desktop//"; //Uncomment for Entering a Specific FilePath
	if (printQueue < receipt_array_size) {

	ofstream output_receipt;
	output_receipt.open((filePath+fileName),ios::app);
	output_receipt << receipts[temp].toString();
	output_receipt.close();

	cout << receipts[printQueue++].toString();
	cout << "\n";
	
	if (filePath=="") {
		cout << "\nFile created in the default directory.\n";
	}
	else {
		cout << "\nFile created at: "+filePath;
	}

	delay(3);
	
	}
	else {
		cout << "Must enter an order before printing a receipt.\n";
		delay(2);
	}
}

void delay(int i) {
	chrono::seconds dura(i);
	this_thread::sleep_for(dura);
}

bool inputYesorNo(string messege) {
	system("CLS");
	cout << messege;
	cin >> inputChar;
	while (!cin || (inputChar != 'y' && inputChar != 'n')) {
		cin.clear();
		cin.ignore(10000, '\n');
		system("CLS");
		cout << "\nError. Type either the letter 'y' or 'n'. Nothing else typed is valid \n";
		cout << messege;
		cin >> inputChar;
	}
	if (inputChar == 'y') {
		return true;
	}
	return false;
}

Date addDate() {
	int d, m, y;

	cout << "Date Format: (Month,day,Year)\n";

	cout << "Type Date MONTH, then press Enter\n";
	cin >> m;
	while (!cin) {
		cout << "Error, input MONTH is not valid\n";
		cout << "Type Date MONTH again, then press Enter\n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> m;
	}

	cout << "Type Date DAY, then press Enter\n";
	cin >> d;
	while (!cin) {
		cout << "Error, input DAY is not valid. Numbers Only\n";
		cout << "Type Date DAY again, then press Enter. (1-31)\n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> d;
	}

	cout << "Type Date YEAR, then press Enter\n";
	cin >> y;
	while (!cin) {
		cout << "Error, input YEAR is not valid. Numbers only! (0-999999)\n";
		cout << "Type Date YEAR again, then press Enter\n";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> y;
	}

	Date obj = Date::Date(d, m, y);

	if (obj.isValidDate()) {
		return obj;
		delay(1);
	}
	else {
		system("CLS");
		cout << "Input date is not a real date. Try again!\n";
		obj = addDate();
		delay(1);
	}

	return obj;
}
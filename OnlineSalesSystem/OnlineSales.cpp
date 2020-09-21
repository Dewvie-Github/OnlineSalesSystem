#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// Data Storage
string name[99];
string surname[99];
bool exitProgram = false;
char menu;

//function declare


int main() {
	cout << " >> Welcome to Online Warehouse Management <<" << endl << endl;
	do {
		cout << "Please selected menu" << endl;
		cout << "1. Manage Customer Data." << endl;
		cout << "2. Manage Stockpile." << endl;
		cout << "3. Sell Product." << endl;
		cout << "4. Exit." << endl;
		cout << "Input menu : " << endl;
		cin >> menu;
	} while (exitProgram != true);

	
	
	system("pause");
	return 0;
}
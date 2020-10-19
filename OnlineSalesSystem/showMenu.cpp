#include <iostream>
using namespace std;
char showMainMenu(char &menu){
	cout << "=======================================" << endl;
	cout << "Please selected menu" << endl;
	cout << "1) Manage Customer Data." << endl;
	cout << "2) Manage Stockpile." << endl;
	cout << "3) Sell Product." << endl;
	cout << "4) Exit." << endl;
	cout << "---------------------------------------" << endl;
	cout << ">> Enter menu : ";
	cin >> menu;
	cout << endl;
	return 0;
}

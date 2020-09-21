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
		cout << "=======================================" << endl;
		cout << "Please selected menu" << endl;
		cout << "1. Manage Customer Data." << endl;
		cout << "2. Manage Stockpile." << endl;
		cout << "3. Sell Product." << endl;
		cout << "4. Exit." << endl;
		cout << "=======================================" << endl;
		cout << ">> Enter menu : ";
		cin >> menu;

		if (menu == '1') {

		}
		else if (menu == '2') {

		}
		else if (menu == '3') {

		}
		else if (menu == '4') {
			char check;
			do {
				cout << "Please confirm you exit status(y/n)";
				cin >> check ;
				if (check == 'y' || check == 'Y') {
					cout << "Exit Program..." << endl;
					exitProgram = true;
				}
				else if (check == 'n' || check == 'N') {
					cout << ">> Back to menu..." << endl;
				}
				else {
					cout << ">> Invalid input! Try again." << endl << endl;
				}
			} while (check != 'y' && check != 'Y' && check != 'n' && check != 'N');
			
			

		}
		else {
			cout << ">> Invalid input! Please enter again." << endl;
		}
	} while (exitProgram != true);

	
	
	system("pause");
	return 0;
}
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// admin user and password
string adminUsername = "admin",adminPassword = "1234";


// Customer datas
int customerID[99];
string customerName[99];
string customerTel[99];
string customerEmail[99];

// Warehouse datas
string productName[99], productClass[99];
int productType[99], productPrice[99], productQuantity[99];

// Selling system datas
string checkID;



bool exitProgram = false;
char menu;


//function declare
char showMenu(char &menu);

int main() {
	cout << " >> Welcome to Online Warehouse Management <<" << endl << endl;
	do {
		showMenu(menu);
		
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

	//exit program
	system("pause");
	return 0;
}
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

// admin username and password
string adminUsername = "admin", adminPassword = "1234";


// Customer Datas
int customerCount = 0; //This is for count data(data).
int customerID[99];
int idGenerate = 630000;

string customerName[99][2];
string customerTel[99];
string customerEmail[99];

// Warehouse Datas
string productName[99], productClass[99], productType[99];
int idCount = 0;
int productPrice[99], productQuantity[99];

// Selling System Datas
string checkID;

bool exitProgram = false;
char mainMenu, menu;

//function declare
char showMainMenu(char& mainMenu);



int main() {

	cout << " >> Welcome to Online Warehouse Management <<" << endl << endl;
	do {
		showMainMenu(mainMenu);
		if (mainMenu == '1') {
			do {
				cout << "=======================================" << endl;
				cout << "[ Manage Customer Data ]" << endl;
				cout << "(1) Register" << endl;
				cout << "(2) Manage ID" << endl;
				cout << "(3) Show you ID" << endl;
				cout << "(4) Show all ID. [admin only]" << endl;
				cout << "(5) Exit to main menu." << endl;
				cout << "---------------------------------------" << endl;
				cout << " >> Enter menu : ";
				cin >> menu;

				if (menu == '1') {
					cout << endl << "Register..." << endl;

					int i = customerCount;
					cout << "Enter name surname (Example : Farsang Jangsai) : " << endl;
					cout << " >> ";
					cin >> customerName[i][0] >> customerName[i][1];

					cout << "Enter your telephone" << endl;
					cout << " >> ";
					cin >> customerTel[i];

					cout << "Enter your email " << endl;;
					cout << " >> ";
					cin >> customerEmail[i];

					customerID[i] = ++idGenerate;

					customerCount++;

					cout << "-----------------------------------------------------------------" << endl;;
					cout << "	ID : " << customerID[i] << endl;
					cout << "	Name : " << customerName[i][0] << " " << customerName[i][1] << endl;
					cout << "	Tel. " << customerTel[i] << " " << "Email : " << customerEmail[i] << endl;
					cout << "-----------------------------------------------------------------" << endl << endl;
				}
				else if (menu == '2') {
					int inputID = 0;
					cout << "Enter you ID : ";
					cin >> inputID;

					//Check is ID in data
					for (int i = 0; i <= idCount; i++) {
						char manageCustomerMenu = '0';
						if (inputID == customerID[i]) {
							;
							do{
								
							} while (manageCustomerMenu != '4');
						}
					}
				}
				else if (menu == '3') {
					
				}
				else if (menu == '4') {

				}
				else if (menu == '5') {
					cout << "Exit to main menu." << endl;
					cout << "=======================================" << endl;
				}
				else {
					cout << endl << ">> invalid input! Please enter again <<" << endl;
				}

			} while (menu != '5');


		}
		else if (mainMenu == '2') {

		}
		else if (mainMenu == '3') {

		}
		else if (mainMenu == '4') {
			char check;
			do {
				cout << "Please confirm you exit status(y/n)";
				cin >> check;
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
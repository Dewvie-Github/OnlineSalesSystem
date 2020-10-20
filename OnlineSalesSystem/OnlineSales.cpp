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
int idCount = 0;

string customerName[99][2];
string customerTel[99];
string customerEmail[99];

// Warehouse Datas
string productName[99], productClass[99], productType[99];
int productPrice[99], productQuantity[99];
int productOwner[99];

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
				// menu
				cout << "=======================================" << endl;
				cout << "[ Manage Customer Data ]" << endl;
				cout << "(1) Register" << endl;
				cout << "(2) Edited ID" << endl;
				cout << "(3) Show you ID" << endl;
				cout << "(4) Show all ID. [admin only]" << endl;
				cout << "(5) Exit to main menu." << endl;
				cout << "---------------------------------------" << endl;
				cout << " >> Enter menu : ";
				cin >> menu;

				if (menu == '1') {
					cout << endl << "Register..." << endl;

					int i = customerCount;
					cout << "Enter name surname (Example : Farsang Jangsai)" << endl;
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

					// Check is ID in Data
					int inputID = 0;
					int pointer;
					bool checkIDstatus = false;
					do {
						cout << "Enter your ID you want to edit : ";
						cin >> inputID;
						for (int i = 0; i <= customerCount; i++) {
							if (inputID == customerID[i]) {
								checkIDstatus = true;
								pointer = i;
							}
						}
						if (checkIDstatus != true) cout << "ID not found in data(s). Please enter again." << endl;

					} while (checkIDstatus == false);

					// manage data
					char manageCustomerdata = '0';
					do {
						cout << "-----------------------------------------------------------------" << endl;;
						cout << "	ID : " << customerID[pointer] << endl;
						cout << "	Name : " << customerName[pointer][0] << " " << customerName[pointer][1] << endl;
						cout << "	Tel. " << customerTel[pointer] << " " << "Email : " << customerEmail[pointer] << endl;
						cout << "-----------------------------------------------------------------" << endl;
						cout << "Selected what you want to change." << endl
							<< "(1) Change name and surname." << endl
							<< "(2) Change Tel." << endl
							<< "(3) Change Email." << endl
							<< "(4) Back to Manage Customer Data Menu" << endl;
						cout << "Select menu : ";
						cin >> manageCustomerdata;
						if (manageCustomerdata == '1') {
							cout << "Enter name surname (Example : Farsang Jangsai)" << endl
								<< " >> ";
							cin >> customerName[pointer][0] >> customerName[pointer][1];
						}
						else if (manageCustomerdata == '2') {
							cout << "Enter email your Tel." << endl
								<< " >> ";
							cin >> customerTel[pointer];
						}
						else if (manageCustomerdata == '3') {
							cout << "Enter email your email." << endl
								<< " >> ";
							cin >> customerEmail[pointer];
						}
						cout << "=================================================================" << endl;
					} while (manageCustomerdata != '4');
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
			bool Idstatus = false;
			int Inputid = 0;
			do {

				cout << "Login id" << endl;
				cout << " >> ";
				cin >> Inputid;
				for (int i = 0; i <= customerCount; i++) {
					if (Inputid == customerID[i]) {
						Idstatus = true;
						cout << "Product Type" << endl;
						cout << " >> ";
						cin >> productType[i];
						cout << "Product Name" << endl;
						cout << " >> ";
						cin >> productName[i];
						cout << "Product Price" << endl;
						cout << " >> ";
						cin >> productPrice[i];
						cout << "Product Classifier" << endl;
						cout << " >> ";
						cin >> productClass[i];
						cout << "Product Quantity" << endl;
						cout << " >> ";
						cin >> productQuantity[i];

					}
					if (Idstatus != true) {
						cout << "Enter not found in data(s).Please enter again" << endl;
					}
				}
			} while (Idstatus == false);
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
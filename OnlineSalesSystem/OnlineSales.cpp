#include<iostream>
#include<string>
using namespace std;

// Data Storage
string name[99];
string surname[99];
string productName[99];


bool exitProgram = false;
char menu;

//function declare
char selectMenu(char &menu);
string collab();

int main() {
	cout << " >> Welcome to Online Warehouse Management <<" << endl << endl;
	do {
		selectMenu(menu);
		
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
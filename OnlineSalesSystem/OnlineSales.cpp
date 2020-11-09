#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<iomanip>
#include<ctime>
using namespace std;

//write file.
fstream file("Logs.txt", ios::in | ios::out | ios::app);

//time
string monthString[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
string dayString[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


int year, month, day, hour, mins, secs, weekDay;

void getTm(int& year, int& month, int& day, int& hour, int& mins, int& secs, int& weekDay)
{
	time_t tt;
	time(&tt);
	tm TM = *localtime(&tt);

	year = TM.tm_year + 2443;
	month = TM.tm_mon;
	day = TM.tm_mday;
	hour = TM.tm_hour;
	mins = TM.tm_min;
	secs = TM.tm_sec;
	weekDay = TM.tm_wday;
}


// Login Online Status
int loginID;
bool adminOnline = false;
string loginName[2];



//user ID


// Customer Datas
int customerCount = 1; //This is for count data(data).
int customerID[99];
int idGenerate = 630000;
string customerPassword[99];



string customerName[99][2];
string customerTel[99];
string customerEmail[99];

// Warehouse Datas
string productName[99], productClass[99], productType[99];
double productPrice[99];
int productQuantity[99];
int productOwner[99];
int productCount = 0; //This is for count data(data).

//This is bill
int billCount;
string billBuyerName[2];
string billProductName[99], billProductClass[99], billProductType[99];

// 0 = productPrice, 1 = price*quantity, 2 = sum of price
double billProductPrice[99][3];
int billProductQuantity[99];
int billProductID[99];
int billProductOwner[99];


// Selling System Datas
string checkID;

bool exitProgram = false;
char mainMenu, menu = '0';

//function declare

// format text seperate
void fmLeftText(string text, int num) {
	cout << left << setw(num) << setfill(' ') << text;
}
void fmLeftText(float text, int num) {
	cout << left << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}
void fmLeftText(int text, int num) {
	cout << left << setw(num) << setfill(' ') << text;
}
void fmLeftText(double text, int num) {
	cout << left << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}

void fmRightText(string text, int num) {
	cout << right << setw(num) << setfill(' ') << text;
}
void fmRightText(float text, int num) {
	cout << right << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}
void fmRightText(int text, int num) {
	cout << right << setw(num) << setfill(' ') << text;
}
void fmRightText(double text, int num) {
	cout << right << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}

// write file with fomat
void fileLeftText(string text, int num) {
	file << left << setw(num) << setfill(' ') << text;
}
void fileLeftText(float text, int num) {
	file << left << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}
void fileLeftText(int text, int num) {
	file << left << setw(num) << setfill(' ') << text;
}
void fileLeftText(double text, int num) {
	file << left << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}

void fileRightText(string text, int num) {
	file << right << setw(num) << setfill(' ') << text;
}
void fileRightText(float text, int num) {
	file << right << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}
void fileRightText(int text, int num) {
	file << right << setw(num) << setfill(' ') << text;
}
void fileRightText(double text, int num) {
	file << right << setw(num) << setfill(' ') << setprecision(2) << fixed << text;
}

//This is function to make first charactor upper!
string firstToUpper(string& text) {
	char first = text.at(0);

	//change char to string
	string firstbutstring(1, toupper(first));

	//replace string to text
	text.replace(0, 1, firstbutstring);
	return text;
}

void showDate(int y = year, int m = month, int d = day, int h = hour, int mn = mins, int sec = secs, int weekday = weekDay) {
	cout << "Date: " << dayString[weekday] << ", " << d << " " << monthString[m] << " " << y << '\n';
}

void showtime(int y = year, int m = month, int d = day, int h = hour, int mn = mins, int sec = secs, int weekday = weekDay) {
	cout << "Time: " << h << ":" << mn << ":" << sec << '\n';
}

int main() {
	// admin username and password
	customerID[0] = 630000;
	customerPassword[0] = "1234";
	customerEmail[0] = "was.dew4546@gmail.com";
	customerTel[0] = "0654796545";
	customerName[0][0] = "Saharat";
	customerName[0][1] = "Thongin";

	// get time

	getTm(year, month, day, hour, mins, secs, weekDay);
	

	// This is our shop product (10 product)
	{
	productType[productCount] = "Furniture";
	productName[productCount] = "Table";
	productPrice[productCount] = 1000;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 10;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Furniture";
	productName[productCount] = "Chair";
	productPrice[productCount] = 450;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 20;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Drink";
	productName[productCount] = "Water Drink";
	productPrice[productCount] = 7;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 100;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Drink";
	productName[productCount] = "Cola";
	productPrice[productCount] = 20;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 200;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Phone";
	productName[productCount] = "Samsung";
	productPrice[productCount] = 10000;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 25;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Phone";
	productName[productCount] = "Iphone";
	productPrice[productCount] = 25000;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 18;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Cloth";
	productName[productCount] = "Shirt";
	productPrice[productCount] = 150;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 30;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Cloth";
	productName[productCount] = "Shoes";
	productPrice[productCount] = 450;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 25;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Toy";
	productName[productCount] = "Robot ";
	productPrice[productCount] = 450;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 15;
	productOwner[productCount++] = 630000;

	productType[productCount] = "Toy";
	productName[productCount] = "Toy Cars";
	productPrice[productCount] = 300;
	productClass[productCount] = "Piece";
	productQuantity[productCount] = 22;
	productOwner[productCount++] = 630000;

	}
	cout << " >> Welcome to Online Warehouse Management <<" << endl << endl;

	//LOGIN REGISTER
	char homeMenu;
	   
	do {
		int pointer;
		bool adminOnline = false;
		cout << "---------------------------------------------" << endl;
		cout << "Select MENU" << endl
			<< "1. Register" << endl
			<< "2. Login" << endl
			<< "3. Forget Username & Password" << endl
			<< "4. Exit Program" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Enter menu : ";
		cin >> homeMenu;

		// Register menu
		if (homeMenu == '1') {
			cout << endl << "Register..." << endl;

			int i = customerCount;
			cout << "Enter name surname (Example : Farsang Jangsai)" << endl;
			cout << " >> ";
			cin >> customerName[i][0] >> customerName[i][1];

			cout << "Enter your telephone." << endl;
			cout << " >> ";
			cin >> customerTel[i];

			cout << "Enter your email. " << endl;
			cout << " >> ";
			cin >> customerEmail[i];

			string confirmPassword = "";
			bool userPassed = false;
			do{
				cout << "Enter your password : ";
				cin >> customerPassword[i];
				cout << "Confirm your password :";
				cin >> confirmPassword;
				if (confirmPassword != customerPassword[i]) {
					cout << "Your password is not match!. Please enter again." << endl;
				}
			} while (confirmPassword != customerPassword[i]);
			customerID[i] = ++idGenerate;
			customerCount++;

			cout << "-----------------------------------------------------------------" << endl;;
			cout << "	ID : " << customerID[i] << endl;
			cout << "	Name : " << customerName[i][0] << " " << customerName[i][1] << endl;
			cout << "	Tel. " << customerTel[i] << " " << "Email : " << customerEmail[i] << endl;
			cout << "-----------------------------------------------------------------" << endl << endl;
		}

		// Login menu
		else if (homeMenu == '2') {
			int loginUserID = 0;
			bool loginPass = false;
			string loginUserPassword = "";
			do {
				bool userIDFound = false;
				cout << "Enter User ID (-1 to back to Register & Login menu): ";
				cin >> loginUserID;
				if (loginUserID == -1) {
					break;
				}
				cout << "Enter User Password :";
				cin >> loginUserPassword;

				//check ID and password
				for (int i = 0; i < customerCount; i++) {
					if ((loginUserID == customerID[i]) && (loginUserPassword == customerPassword[i])) {
						loginPass = true;
						
						if (loginUserID == customerID[0]) {
							cout << "---------------------------------------------" << endl;
							cout << endl;
							cout << "Login success! Welcome Administrator." << endl;
							loginID = loginUserID;
							loginName[0] = "Administrator";
							loginName[1] = " ";
							pointer = 0;
							break;
						}
						else {
							cout << "---------------------------------------------" << endl;
							cout << "Login success! Welcome " << customerName[i][0] << ' ' << customerName[i][1] << endl;
							loginID = loginUserID;
							loginName[0] = customerName[i][0];
							loginName[1] = customerName[i][1];
							pointer = i;
							break;
						}
					}
					else if (loginUserID == customerID[i]) {
						userIDFound = true;
					}
				}

				if (userIDFound == true && loginPass == false){
					cout << "Password don't match with User ID! Please enter again." << endl << endl;
				}
				else if (userIDFound == false && loginPass == false) {
					cout << "Don't found user ID in data! Please enter again." << endl << endl;
				}
				
			} while (loginPass == false);
			if (loginPass == true) {
				do {
					cout << "============================================" << endl;
					cout << "User ID : " << loginID << "\tName : " << loginName[0] << ' ' << loginName[1] << endl << endl;

					cout << "Please selected menu" << endl;
					cout << "1) Manage Customer Data." << endl;
					cout << "2) Manage Stockpile." << endl;
					cout << "3) Sell Product." << endl;
					cout << "4) Exit to Home Menu & Log out." << endl;
					cout << "--------------------------------------------" << endl;
					cout << ">> Enter menu : ";
					cin >> mainMenu;
					cout << endl;

					if (mainMenu == '1') {
						{
							do {
								// menu
								cout << "============================================" << endl;
								cout << "[ Manage Customer Data ]" << endl;
								cout << "(1) Edited Account" << endl;
								cout << "(2) Show you ID" << endl;
								cout << "(3) Show all ID[Admin ONLY]" << endl;
								cout << "(4) Exit to main menu." << endl;
								cout << "--------------------------------------------" << endl;
								cout << " >> Enter menu : ";
								cin >> menu;

								// Edited ID MENU
								if (menu == '1') {

									// Edit Data
									char manageCustomerdata = '0';
									do {
										cout << "-----------------------------------------------------------------" << endl;;
										cout << "	ID : " << customerID[pointer] << endl;
										cout << "	Name : " << customerName[pointer][0] << " " << customerName[pointer][1] << endl;
										cout << "	Tel. " << customerTel[pointer] << " " << "Email : " << customerEmail[pointer] << endl;
										cout << "-----------------------------------------------------------------" << endl;
										cout << "Selected what you want to change." << endl
											<< " (1) Change Name and Surname." << endl
											<< " (2) Change Tel." << endl
											<< " (3) Change Email." << endl
											<< " (4) Change Password." << endl
											<< " (5) Back to Manage Customer Data Menu" << endl;
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
										else if (manageCustomerdata == '4') {
											string oldPassword;
											string newPassword;
											string confirmPassword;
											cout << "Enter old password";
											cin >> oldPassword;
											if (oldPassword == customerPassword[pointer]) {
												do {
													cout << "Enter new password : ";
													cin >> newPassword;
													cout << "Enter your new password again : ";
													cin >> confirmPassword;
													if (newPassword != confirmPassword) {
														cout << "New password not match! Please enter new password again." << endl;
													}
													else if(newPassword == confirmPassword){
														cout << "[!]Password has been change to new password[!]" << endl;
														customerPassword[pointer] = confirmPassword;
													}
												} while (newPassword != confirmPassword);
											}
										}
										
									} while (manageCustomerdata != '5');
								}
								else if (menu == '2') {

									cout << "-----------------------------------------------------------------" << endl;;
									cout << "	ID : " << customerID[pointer] << endl;
									cout << "	Name : " << customerName[pointer][0] << " " << customerName[pointer][1] << endl;
									cout << "	Tel. " << customerTel[pointer] << " " << "Email : " << customerEmail[pointer] << endl;
									cout << "-----------------------------------------------------------------" << endl << endl << endl;

								}

								else if (menu == '3') {
									if (loginID == customerID[0]) {
									// cout all ID datas
									cout << "----------------------------------------------------------------------" << endl;;
									for (int i = 0; i < customerCount; i++) {
										cout << "	ID : " << customerID[i] << endl;
										cout << "	Name : " << customerName[i][0] << " " << customerName[i][1] << endl;
										cout << "	Tel. " << customerTel[i] << " " << "Email : " << customerEmail[i] << endl << endl;
									}
									cout << "----------------------------------------------------------------------" << endl;
								}
									else {
										cout << "Access Denied! This is for ADMIN ONLY!" << endl;
									}
								}
								
								else if (menu == '4') {
									cout << "Exit to main menu." << endl;
									cout << "=======================================" << endl;
								}
								else {
									cout << endl << ">> invalid input! Please enter again <<" << endl;
								}

							} while (menu != '4');



						}
					}

					
					else if (mainMenu == '2') {
					do {
						menu = '0';
						cout << "--------------------------------------------" << endl;
						cout << "Select menu" << endl
							<< "(1) Add Product." << endl
							<< "(2) Edit Product." << endl
							<< "(3) Show all product[admin]." << endl
							<< "(4) back to Main Menu." << endl;
							cout << "--------------------------------------------" << endl;
							cout << " >> Enter menu : ";
							cin >> menu;

						if (menu == '1') {
							char enterAgain = ' ';
							do {
								cout << "------------------------------" << endl << endl;
								cout << "Product Type" << endl;
								cout << " >> ";
								cin >> productType[productCount];
								cout << "Product Name" << endl;
								cout << " >> ";
								cin >> productName[productCount];
								cout << "Product Price" << endl;
								cout << " >> ";
								cin >> productPrice[productCount];
								cout << "Product Classifier" << endl;
								cout << " >> ";
								cin >> productClass[productCount];
								cout << "Product Quantity" << endl;
								cout << " >> ";
								cin >> productQuantity[productCount];

								do {
									cout << "Do you want to enter more product? (y/n) : ";
									cin >> enterAgain;
								} while ((enterAgain != 'y') && (enterAgain != 'Y') && (enterAgain != 'n') && (enterAgain != 'N'));

								productOwner[productCount] = loginID;
								productCount++;
							} while ((enterAgain != 'n') && (enterAgain != 'N'));


						}
						else if (menu == '2') {
							int inputProductID = 0;

							do {
								cout << "----------------------------------------------------------------------------------------" << endl;
								cout << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
									<< "price" << "     " << "classifier" << "  " << "quantity" << endl;
								cout << "----------------------------------------------------------------------------------------" << endl;
								for (int i = 0; i < productCount; i++) {
									if (productOwner[i] == loginID) {
										fmLeftText(i, 11);
										fmLeftText(productType[i], 15);
										fmLeftText(productName[i], 28);
										fmRightText(productPrice[i], 10);
										cout << "      ";
										fmLeftText(productClass[i], 15);
										fmLeftText(productQuantity[i], 8);
										cout << endl;
									}
								
								}
								cout << "----------------------------------------------------------------------------------------" << endl;
								
								cout << "Enter product ID you want to change(-1 to Back to Stockpile Menu)" << endl;
								cout << " >> ";
								cin >> inputProductID;
								char changeProductMenu = ' ';
								if (loginID == productOwner[inputProductID]) {
									do {
										cout << "Select menu you want to change." << endl
											<< "(1) Change Product Type." << endl
											<< "(2) Change Product Name." << endl
											<< "(3) Change Product Price." << endl
											<< "(4) Change Product Classifier." << endl
											<< "(5) Change Product Quantity." << endl
											<< "(6) Back to edit product." << endl;
										
										cout << " Menu : ";
										cin >> changeProductMenu;
									
										if (changeProductMenu == '1') {
											cout << "Enter Product Type : ";
											cin >> productType[inputProductID];
										}
										else if (changeProductMenu == '2') {
											cout << "Enter Product Name : ";
											cin >> productName[inputProductID];
										}
										else if (changeProductMenu == '3') {
											cout << "Enter Price : ";
											cin >> productPrice[inputProductID];
										}
										else if (changeProductMenu == '4') {
											cout << "Enter Classifier : ";
											cin >> productClass[inputProductID];
										}
										else if (changeProductMenu == '5') {
											cout << "Enter Quantity : ";
											cin >> productQuantity[inputProductID];
										}
										cout << endl << endl;
									} while (changeProductMenu != '6');
								}
								else if (inputProductID == -1) {
									cout << "Back to Manage Stockpile Menu." <<endl;
								}
								else {
									cout << "ID not match with Product Owner. Please enter again!!";
								}
							} while (inputProductID != -1);

							cout << "----------------------------------------------------------------------------------------" << endl << endl;

						}
						else if (menu == '3') {
							if (loginID == 630000) {
								cout << "----------------------------------------------------------------------------------------" << endl;
								cout << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
									<< "price" << "     " << "classifier" << "  " << "quantity" << endl;
								cout << "----------------------------------------------------------------------------------------" << endl;
								for (int i = 0; i < productCount; i++) {
									fmLeftText(i, 11);
									fmLeftText(productType[i], 15);
									fmLeftText(productName[i], 28);
									fmRightText(productPrice[i], 10);
									cout << "      ";
									fmLeftText(productClass[i], 15);
									fmLeftText(productQuantity[i], 8);
									cout << endl;
								}

								cout << "----------------------------------------------------------------------------------------" << endl << endl;

							}
							else {
								cout << "Acess Denied. This menu for \"ADMIN\" only." << endl;
							}
						}
					} while (menu != '4');
					}

					else if (mainMenu == '3') {
					do {
						menu = '0';
						cout << "[Select Sale Product Menu]" << endl
							<< "(1) Show all Product." << endl
							<< "(2) Buy product and Make Bill." << endl
							<< "(3) Back to Main Menu." << endl;
						cout << "--------------------------------------------" << endl;
						cout << " >> Enter menu : ";
						cin >> menu;
						if (menu == '1') {
							cout << "----------------------------------------------------------------------------------------" << endl;
							cout << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
								<< "price" << "     " << "classifier" << "  " << "quantity" << endl;
							cout << "----------------------------------------------------------------------------------------" << endl;
							for (int i = 0; i < productCount; i++) {
								fmLeftText(i, 11);
								fmLeftText(productType[i], 15);
								fmLeftText(productName[i], 28);
								fmRightText(productPrice[i], 10);
								cout << "      ";
								fmLeftText(productClass[i], 15);
								fmLeftText(productQuantity[i], 8);
								cout << endl;
							}

							cout << "----------------------------------------------------------------------------------------" << endl << endl;
						}

						// make bill and buy product
						else if (menu == '2') {
							// Find ID pointer
							int idPointer = pointer;

								char billMenu;
								int inputProductID = 0;
								
								do {
									cout << endl;
									cout << "[Select bill menu]" << endl
										<< "(1) Add or edit buyer Name-Surname." << endl
										<< "(2) Add product that buyer want to buy." << endl
										<< "(3) Show Bill." << endl
										<< "(4) Print Bill(show total price)." << endl
										<< "(5) Reset Bill." << endl
										<< "(6) Exit to Sale Product Menu." << endl;
									cout << "--------------------------------------------" << endl;
									cout << " >> Enter menu : ";
									cin >> billMenu;
									cout << endl;
									if (billMenu == '1') {
										cout << "Enter buyer name surname : ";
										cin >> billBuyerName[0] >> billBuyerName[1];
									}
									else if (billMenu == '2') {
										cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
											<< "price" << "     " << "classifier" << "  " << "quantity" << "   " << "OwnerID" << endl;
										cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
										for (int i = 0; i < productCount; i++) {
											fmLeftText(i, 11);
											fmLeftText(productType[i], 15);
											fmLeftText(productName[i], 28);
											fmRightText(productPrice[i], 10);
											cout << "      ";
											fmLeftText(productClass[i], 15);
											fmLeftText(productQuantity[i], 8);
											fmLeftText(productOwner[i], 9);
											cout << endl;
										}

										cout << "---------------------------------------------------------------------------------------------------------------------" << endl << endl;

										//Store product to bill
										do {
											cout << " Enter product ID(-1 to Exit) : ";
											cin >> inputProductID;

											if (inputProductID != -1) {
												for (int i = 0; i < productCount; i++) {
													if (productName[inputProductID] == productName[i]) {
														cout << " You selected " << productName[i];
														do {
															cout << " Enter quantity : ";
															cin >> billProductQuantity[billCount];
															//remove quantity from warehouse
															if (billProductQuantity[billCount] < 0) {
																cout << "Quantity less than in stock! Please enter again." << endl;
															}
															else if (billProductQuantity[billCount] > productQuantity[i]) {
																cout << "Quantity more than in stock! Please enter again." << endl;
															}
														} while ((billProductQuantity[billCount] < 0) || (billProductQuantity[billCount] > productQuantity[i]));
														productQuantity[i] -= billProductQuantity[billCount];

														billProductName[billCount] = productName[i];
														billProductClass[billCount] = productClass[i];
														billProductType[billCount] = productType[i];

														// 0 = productPrice, 1 = price*quantity, 2 = sum of price
														billProductPrice[billCount][0] = productPrice[i];
														billProductPrice[billCount][1] = productPrice[i] * billProductQuantity[billCount];
														billProductPrice[0][2] += billProductPrice[billCount][1];
														billProductID[billCount] = i;
														billProductOwner[billCount] = productOwner[i];
														billCount++;
													}
												}
											}
										} while (inputProductID != -1);

									}
									else if (billMenu == '3') {


										cout << "=====================================================================================================================";
										cout << "                                                                                        ";
										cout << "Date: " << dayString[weekDay] << ", " << day << " " << monthString[month] << " " << year << '\n';
										cout << endl;
										fmRightText((customerName[idPointer][0] + ' ' + customerName[idPointer][1]), 106);
										cout << endl;
										fmRightText(loginID, 106);
										cout << endl << endl;
										cout << billBuyerName[0] << ' ' << billBuyerName[1] << endl;
										cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
											<< "price" << "     " << "classifier" << "  " << "quantity" << "     Total Price" << "     " << "OwnerID" << endl;
										cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
										for (int i = 0; i < billCount; i++) {
											fmLeftText(i, 11);
											fmLeftText(billProductType[i], 15);
											fmLeftText(billProductName[i], 28);
											fmRightText(billProductPrice[i][0], 10);
											cout << "      ";
											fmLeftText(billProductClass[i], 15);
											fmLeftText(billProductQuantity[i], 8);
											fmRightText(billProductPrice[i][1], 13);
											cout << "    ";
											fmLeftText(billProductOwner[i], 9);
											cout << endl;
										}


										cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
										
									}
									else if (billMenu == '4') {
										bool isPrint = false;
										char isPrintYN = ' ';
										do {
											cout << "Do you want to print bill?(y/n) : ";
											cin >> isPrintYN;
											if (isPrintYN == 'y' || isPrintYN == 'Y') {
												cout << "=====================================================================================================================";
												cout << "                                                                                        ";
												cout << "Date: " << dayString[weekDay] << ", " << day << " " << monthString[month] << " " << year << '\n';
												cout << endl;
												fmRightText((customerName[idPointer][0] + ' ' + customerName[idPointer][1]), 106);
												cout << endl;
												fmRightText(loginID, 106);
												cout << endl << endl;
												cout << billBuyerName[0] << ' ' << billBuyerName[1] << endl;
												cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
												cout << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
													<< "price" << "     " << "classifier" << "  " << "quantity" << "     Total Price" << "     " << "OwnerID" << endl;
												cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
												for (int i = 0; i < billCount; i++) {
													fmLeftText(i, 11);
													fmLeftText(billProductType[i], 15);
													fmLeftText(billProductName[i], 28);
													fmRightText(billProductPrice[i][0], 10);
													cout << "      ";
													fmLeftText(billProductClass[i], 15);
													fmLeftText(billProductQuantity[i], 8);
													fmRightText(billProductPrice[i][1], 13);
													cout << "    ";
													fmLeftText(billProductOwner[i], 9);
													cout << endl;
												}


												cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
												fmRightText(billProductPrice[0][2], 106);
												cout << endl;
												cout << "=====================================================================================================================";
												cout << endl;


												file << "=====================================================================================================================";
												file << "                                                                                        ";
												file << "Date: " << dayString[weekDay] << ", " << day << " " << monthString[month] << " " << year << '\n';
												file << endl;
												fileRightText((customerName[idPointer][0] + ' ' + customerName[idPointer][1]), 106);
												file << endl;
												fileRightText(loginID, 106);
												file << endl << endl;
												file << billBuyerName[0] << ' ' << billBuyerName[1] << endl;
												file << "---------------------------------------------------------------------------------------------------------------------" << endl;
												file << "ProductID" << "     " << "Type" << "        " << "Product Name" << "                    "
													<< "price" << "     " << "classifier" << "  " << "quantity" << "     Total Price" << "     " << "OwnerID" << endl;
												file << "---------------------------------------------------------------------------------------------------------------------" << endl;
												for (int i = 0; i < billCount; i++) {
													fileLeftText(i, 11);
													fileLeftText(billProductType[i], 15);
													fileLeftText(billProductName[i], 28);
													fileRightText(billProductPrice[i][0], 10);
													file << "      ";
													fileLeftText(billProductClass[i], 15);
													fileLeftText(billProductQuantity[i], 8);
													fileRightText(billProductPrice[i][1], 13);
													cout << "    ";
													fileLeftText(billProductOwner[i], 9);
													file << endl;
												}


												file << "---------------------------------------------------------------------------------------------------------------------" << endl;
												fileRightText(billProductPrice[0][2], 106);
												file << "=====================================================================================================================";
												file << endl << endl << endl;
												break;
											}
											else if (isPrintYN == 'n' || isPrintYN == 'N') {

												break;
											}
											else {
												cout << " Invalid input! Please enter again." << endl;
											}
										} while (isPrint == false);
									}
									else if (billMenu == '5') {
										char resetBill = ' ';
										bool reset = false;
										cout << "Are you sure you wanto reset bill (y/n) : ";
										cin >> resetBill;
										if (resetBill == 'y')reset = true;

										if (reset == true) {
											billCount = 0;
											billBuyerName[0] = billBuyerName[1] = " ";
											for (int i = 0; i < 99; i++) {
												billProductName[i] = " ";
											}
											for (int i = 0; i < 99; i++) {
												billProductClass[i] = " ";
											}
											for (int i = 0; i < 99; i++) {
												billProductType[i] = " ";
											}
											for (int i = 0; i < 3; i++) {
												for (int j = 0; j < 99; j++) {
													billProductPrice[j][i] = 0;
												}
											}
											for (int i = 0; i < 99; i++) {
												billProductQuantity[i] = 0;
											}
											for (int i = 0; i < 99; i++) {
												billProductID[i] = 0;
											}
											for (int i = 0; i < 99; i++) {
												billProductOwner[i] = 0;
											}

										}

									}

								} while (billMenu != '6');
						}
					} while (menu != '3');
					}
					else if (mainMenu == '4') {
						loginID = 0;
						cout << "You has been Log out." << endl;
					}
				} while (mainMenu != '4');
			}

		}
		else if (homeMenu == '3') {
		string inputEmail;
		bool found = false;
		do {
			cout << "Enter your email : " << endl;
			cin >> inputEmail;
			for (int i = 0; i < customerCount; i++) {
				if (inputEmail == customerEmail[i]) {
					cout << " You ID is : " << customerID[i] << endl;
					cout << " You passsword is : " << customerPassword[i] << endl;
					found = true;
				}
			}
			if (found == false) {
				cout << "Email not found in data." << endl;
			}
		} while (found == false);
		}
		else if (homeMenu == '4'){
		char exitStatus;
		do {
			cout << "Are you sure you want to Exit Program(y/n) : ";
			cin >> exitStatus;
			if (exitStatus == 'y' || exitStatus == 'Y') {
				exitProgram = true;
			}
			else if (exitStatus == 'n' || exitStatus == 'N') {
				exitProgram = false;
			}
			else {
				cout << "Invalid input!(y/n)" << endl;
			}
		} while (exitStatus != 'y' && exitStatus != 'Y' && exitStatus != 'n' && exitStatus != 'N');
		}

		else {
			cout << "Invalid input! Please enter again." << endl;
		}
	} while (exitProgram == false);
	

	return 0;
}

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// Data Storage
string name[99];
string surname[99];
int name_length = 0;
int surname_length = 0;

//function declare



int main() {
	cout << " >> Welcome to www.onlinemarketing.co.th <<" << endl;
	ofstream nameFile("name.txt");
	name[0] = "Saharat";
	name[1] = "John";
	name[2] = "Jack";
	surname[0] = "Thongin";
	surname[1] = "Son";
	surname[2] = "San";
	nameFile << "{";
	for (int i = 0; i <= 2; i++) {
	nameFile << name[i] << " : " << surname[i];
	}
	nameFile << "}";
	
	return 0;
	system("pause");
}
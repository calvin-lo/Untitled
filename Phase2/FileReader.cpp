// Phase2.cpp : main project file.

//Imports
#include "FileReader.h"
#include <iostream> 
#include <string>
#include <fstream>


using namespace std;


//ReadFile function
void FileReader::ReadFile() { 
	string line; //stores line of currently read string
	ifstream file(file_path); //open ifstream
	if (file.is_open()) {  //if file opened successfully
		while (getline(file,line)) { //while there are lines
			cout << line << '\n'; //output to the screen for now
		}
		file.close(); //close file
	} else { //if the file is not found
		cout << "Unable to open" << '\n';
	}
}

int main() {
	//new bank_accounts object
	FileReader bank_accounts;
	//referring to the filepath of created object
	bank_accounts.file_path = "BankAccounts.txt";
	//call the readfile function on filepath given above
	bank_accounts.ReadFile();
	return 0;
}

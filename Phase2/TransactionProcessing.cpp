/*
	CSCI 3060/ SOFE 3980 Course Project Front End
	Group: Untitled
	Member: Calvin Lo, Albert Fung, Karan Chandwaney
*/
#include "TransactionProcessing.h"
#include "FileReader.cpp"
#include "FileWriter.cpp"
#include <vector>
#include <algorithm>

TransactionProcessing::TransactionProcessing() {
	status = false;
}

TransactionProcessing::~TransactionProcessing() {

}

bool TransactionProcessing::login(string line) {

	do { 
		cout << "Do you wish to login as a standard user or admin?" << '\n';
		getline(cin, line);
		
	} while (line.compare("standard session") != 0 && line.compare("admin session") != 0);

	cout << "Logged in" << endl;

	return status;
}

bool TransactionProcessing::withdrawal(string line) {
	return status;
}

bool TransactionProcessing::transfer(string line) {
	return status;
}

bool TransactionProcessing::paybill(string line) {
	return status;
}

bool TransactionProcessing::deposit(string line) {
	return status;
}

bool TransactionProcessing::create(string line) {
	return status;
}

bool TransactionProcessing::delete1(string line) {
	return status;
}

bool TransactionProcessing::enable(string line) { 
	return status;
}

bool TransactionProcessing::disable(string line) {
	return status;
}

bool TransactionProcessing::changeplan(string line) {
	return status;
}

bool TransactionProcessing::logout(string line) { 
	return status;
}

bool TransactionProcessing::in_array(string value, vector<string> array) {
    //cout << "value: " << value << endl;
    //cout << array.begin() << endl;
    //cout << array.end() << endl;
   
    //return find(array.begin(), array.end(), value) != array.end();
    return true;
}

int main () {
	//new bank_accounts object
	FileReader bank_accounts;
	//referring to the filepath of created object
	bank_accounts.file_path = "BankAccounts.txt";
	//call the readfile function on filepath given above
	bank_accounts.ReadFile();
	bank_accounts.commands = buffer;

	TransactionProcessing trans;

	
	vector<string> transactions = {"Login", "login", "Withdrawal", "withdrawal", "Transfer", "transfer", "Paybill", "paybill", "Deposit", "deposit", "Create", "create", "Delete", "delete", "Enable", "enable", "Disable", "disable", "Changeplan", "changeplan", "Logout", "logout"};

	string temp;
	
	/*
	do { 

		cout << "Please enter a valid transaction code" << endl;
		getline(cin, temp);
		trans.login(temp);
		trans.input = temp;	
		temp = "login";
	} while (trans.in_array(temp, transactions) == false);
	*/
	
	cout << find(transactions.begin(), transactions.end(), "login");

	//cout << trans.in_array("login", transactions);
	
	//cout << "valid" << endl;

	/*
	//print out the vector of strings
	for (int i = 0; i < bank_accounts.commands.size(); i++) { 
		cout << bank_accounts.commands.at(i) << '\n';
	}
	*/
	//new transaction file object
	FileWriter transaction_file;
	//referring to the filepath of created object
	transaction_file.file_path = "Transaction.txt";
	//call the WriteFile function on filepath given above
	transaction_file.WriteFile("HELLOasdasdsadas");
	return 0;

}
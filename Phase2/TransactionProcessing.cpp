/*
	CSCI 3060/ SOFE 3980 Course Project Front End
	Group: Untitled
	Member: Calvin Lo, Albert Fung, Karan Chandwaney
*/
#include "TransactionProcessing.h"
#include "FileReader.cpp"
#include "FileWriter.cpp"

TransactionProcessing::TransactionProcessing() {
	status = false;
}

TransactionProcessing::~TransactionProcessing() {

}

bool TransactionProcessing::login(string line) {
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

int main () {
	//new bank_accounts object
	FileReader bank_accounts;
	//referring to the filepath of created object
	bank_accounts.file_path = "BankAccounts.txt";
	//call the readfile function on filepath given above
	bank_accounts.ReadFile();
	bank_accounts.commands = buffer;
	
	for (int i = 0; i < bank_accounts.commands.size(); i++) { 
		cout << bank_accounts.commands.at(i) << '\n';
	}

	//new bank_accounts object
	FileWriter transaction_file;
	//referring to the filepath of created object
	transaction_file.file_path = "Transaction.txt";
	//call the WriteFile function on filepath given above
	transaction_file.WriteFile("HELLOasdasdsadas");
	return 0;

}
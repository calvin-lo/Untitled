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

bool TransactionProcessing::login() {
	string line;

	do { 
		cout << "Do you wish to login as a standard user or admin?" << '\n';
		getline(cin, line);
		
	} while (line.compare("standard session") != 0 && line.compare("admin session") != 0);

	do { 
		
		cout << "What is the account holder's name?" << endl;

	} while (line.compare("standard session") != 0 && line.compare("admin session") != 0);
		


	return status;
}

bool TransactionProcessing::withdrawal() {
	return status;
}

bool TransactionProcessing::transfer() {
	return status;
}

bool TransactionProcessing::paybill() {
	return status;
}

bool TransactionProcessing::deposit() {
	return status;
}

bool TransactionProcessing::create() {
	return status;
}

bool TransactionProcessing::delete1() {
	return status;
}

bool TransactionProcessing::enable() { 
	return status;
}

bool TransactionProcessing::disable() {
	return status;
}

bool TransactionProcessing::changeplan() {
	return status;
}

bool TransactionProcessing::logout() { 
	return status;
}

bool TransactionProcessing::in_array(string value, vector<string> array) {
    return find(array.begin(), array.end(), value) != array.end();
}

string TransactionProcessing::promptTransaction() { 
	// checks if the transaction they want to use is valid 
	vector<string> transactions = {"Login", "login", "Withdrawal", "withdrawal", "Transfer", "transfer", "Paybill", "paybill", "Deposit", "deposit", "Create", "create", "Delete", "delete", "Enable", "enable", "Disable", "disable", "Changeplan", "changeplan", "Logout", "logout"};
	string temp;
	do { 
		cout << "Please enter a valid transaction code" << endl;
		getline(cin, temp);
	} while (in_array(temp, transactions) != 1);
	
	return temp;
}

string TransactionProcessing::parse(string to_parse, int field) { 

	// field 0 = account number
	// field 1 = name
	// field 2 = active/disabled
	// field 3 = balance
	// field 4 = student/non student

	if (field == 0) { 
		return to_parse.substr(0, 4);
	
	} else if (field == 1) { 
		return to_parse.substr(6, 26);
	
	} else if (field == 2) { 
		return to_parse.substr(27, 28);
	
	} else if (field == 3) { 
		return to_parse.substr(30, 37);
	
	} else if (field == 4) { 
		return to_parse.substr(38, 39);
	} 
	return "";
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

	//string cmd = trans.promptTransaction();


	for (int i = 0; i < bank_accounts.commands.size(); i++) { 
		
		//string name = trans.parse(bank_accounts.commands.at(i), 1);
		int lol = bank_accounts.commands.at(i).find("Chris Doe");
		int lol2 = bank_accounts.commands.at(i).find("00001");

		if (lol2 != -1) { 
			cout << bank_accounts.commands.at(i).substr(lol2, 5) << endl;
		}
		/*

		if (lol != -1) { 
			string name = bank_accounts.commands.at(i).substr(lol, 20);
			cout << name << endl;
		}

		*/
		//cout << bank_accounts.commands.at(i) << '\n';
	}
	
	/*

	if (cmd.compare("Login") == 0 || cmd.compare("login") == 0) { 
		trans.login();
	
	} else if (cmd.compare("Withdrawal") == 0 || cmd.compare("withdrawal") == 0) { 
		trans.withdrawal();
	
	} else if (cmd.compare("Transfer") == 0 || cmd.compare("transfer") == 0) { 
		trans.transfer();
	}
	*/

	
	//print out the vector of strings
	
	
	//new transaction file object
	FileWriter transaction_file;
	//referring to the filepath of created object
	transaction_file.file_path = "Transaction.txt";
	//call the WriteFile function on filepath given above
	transaction_file.WriteFile("HELLOasdasdsadas");
	return 0;

}
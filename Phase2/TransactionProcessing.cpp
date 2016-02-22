//	CSCI 3060/ SOFE 3980 Course Project Front End
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#include "TransactionProcessing.h"
#include "FileReader.h"
#include "FileWriter.h"

TransactionProcessing::TransactionProcessing() {
	status = false;
	login_mode = 'N';
}

TransactionProcessing::~TransactionProcessing() {

}

bool TransactionProcessing::login(string line) {

	// Keep track of valid account holder's name
	bool valid_name;


	msg = "Do you wish to login as a standard user or admin?";
	cout << msg << endl;
	getline(cin, input);
	if (input == "standard") {
		msg = "Logged in as a standard user.";
		login_mode = 'S';
	} else if (input == "admin") {
		msg = "Logged in as an admin user.";
		login_mode = 'A';
	}
	cout << msg << endl;
	msg = "What is the account holder's name?";
	cout << msg << endl;
  	getline(cin, input);
	account_holder_name = input;

	//cout << parse("John Doe", 1) << endl;	
	cout << "account holder name is " << account_holder_name << "." << endl;
	string parsed = parse(account_holder_name, 1);
	
	cout << "looking for: " << parsed << "." << endl;

	if (parsed.compare(account_holder_name) == 0) { 
		valid_name = true;
	}
	
	// if account holder name is valid
	if (valid_name == true) {
		msg = "logged in as " + account_holder_name + ".";
		cout << msg << endl;
	}
	// if account hodler name is NOT valid
	else {
		msg = "Invalid account holder name";
		cout << msg << endl;
		return status;
	}
	
	status = true;
	return status;
}

bool TransactionProcessing::withdrawal(string line) {
	// Keep track of the account holder name for withdrawal
	string withdrawal_acc_name;
	// Keep track of the account holder name for withdrawal
	string withdrawal_acc_num;
	// Keep track of the amount for withdrawal;
	string amount;
	// True if the amount to withdraw is valid, False if not
	bool valid_amount;
	// True if the account holder name to withdraw is valid, False if not
	bool valid_name;
	// True if the account number to withdraw is valid, False if not
	bool valid_num;
	
	// Check whether the user logged in.  If logged in, check if they have the privilege to withdrawal money
	// Return false if the user is not logged in
	if (login_mode == 'N') {
		msg = "withdrawal: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "withdrawal: Valid command.";
		cout << msg << endl;
		msg = "What is the account holder's name for withdrawal?";
		cout << msg << endl;
		getline(cin, input);
		withdrawal_acc_name = input;
		// if the account holder name is valid.
		if (valid_name == true) {
			msg =  withdrawal_acc_name+ "set as withdrawal account holder.";
			cout << msg << endl;
			msg = "What is the account number you wish to withdrawal from?";
			cout << msg << endl;
			getline(cin, input);
			withdrawal_acc_num = input;
			// if the account number is valid.			
			if (valid_num == true) {
				msg = "Valid account number" + withdrawal_acc_num + ".";
				cout << msg << endl;
				msg = "What is the amount to withdrawal?";
				cout << msg << endl;
				getline(cin, input);
				amount = input;
				// if the amount is valid.	
				if (valid_amount == true) {
					msg = "$" + amount + " withdrawn from account" + withdrawal_acc_num + ".";
					cout << msg << endl;
				} 
				// if the amount is NOT valid
				else {
					msg = "Invalid account holder name";
					cout << msg << endl;
					return status;
				}
			}
			// if the account number is NOT valid
			else {
					msg = "Invalid account number";
					cout << msg << endl;
					return status;
			}
		}
		// if the acount holder name is NOT valid
		else {
			msg = "Invalid Amount";
			cout << msg << endl;
			return status;
		}
		status = true;

	}
	
	return status;
}

bool TransactionProcessing::transfer(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to transfer money
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "trasfer: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "transfer: Valid command.";
		cout << msg << endl;
	}

	return status;
}

bool TransactionProcessing::paybill(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to pay bill
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "paybill: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "paybill: Valid command.";
		cout << msg << endl;
	}

	return status;
}

bool TransactionProcessing::deposit(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to deposit money
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "deposit: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "deposit: Valid command.";
		cout << msg << endl;
	}

	return status;
}

bool TransactionProcessing::create(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to create account
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "create: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S') {
		msg = "create: Invalid command. Admin access required.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'A') {
		msg = "create: Valid command. Admin access granted.";
		cout << msg << endl;
	}

	return status;
}

bool TransactionProcessing::delete1(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to delete account
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "delete: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S') {
		msg = "delete: Invalid command. Admin access required.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'A') {
		msg = "delete: Valid command. Admin access granted.";
		cout << msg << endl;
	}	

	return status;
}

bool TransactionProcessing::enable(string line) { 
	// Check whether the user logged in.  If logged in, check if they have the privilege to enable account
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "enable: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S') {
		msg = "enable: Invalid command. Admin access required.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'A') {
		msg = "enable: Valid command. Admin access granted.";
		cout << msg << endl;
	}	

	return status;
}

bool TransactionProcessing::disable(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to disable account
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "disable: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S') {
		msg = "disable: Invalid command. Admin access required.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'A') {
		msg = "disable: Valid command. Admin access granted.";
		cout << msg << endl;
	}	

	return status;
}

bool TransactionProcessing::changeplan(string line) {
	// Check whether the user logged in.  If logged in, check if they have the privilege to change plan
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "changeplan: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S') {
		msg = "changeplan: Invalid command. Admin access required.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'A') {
		msg = "changeplan: Valid command. Admin access granted.";
		cout << msg << endl;
	}	

	return status;
}

bool TransactionProcessing::logout(string line) { 
	// Check whether the user logged in.  If logged in, check if they have the privilege to logout
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "logout: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "logout: Valid command.";
		cout << msg << endl;
		login_mode = 'N';
		account_holder_name = "";
	}

	status = false;
	return status;
}

string TransactionProcessing::erase(string str) { 

	int count = 0;
	for (int i = 1; i < str.length(); i++) { 
		if (str.at(i).compare(" ") == 0) { 
			count++;
		}
		if (count > 1) { 
			return str.substr(0, i);
		}
	}
}

string TransactionProcessing::parse(string check, int field) { 
	// field 0 = account number
	// field 1 = name
	// field 2 = active/disabled
	// field 3 = balance
	// field 4 = student/non student
/*
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
	*/
	FileReader bank_accounts;
	//referring to the filepath of created object
	bank_accounts.file_path = "BankAccounts.txt";
	//call the readfile function on filepath given above
	bank_accounts.commands = bank_accounts.ReadFile();
	
	TransactionProcessing trans;

	//string cmd = trans.promptTransaction();

	for (int i = 0; i < bank_accounts.commands.size(); i++) { 
		
		//string name = trans.parse(bank_accounts.commands.at(i), 1);
		int accnum_loc = bank_accounts.commands.at(i).find(check);
		int name_loc = bank_accounts.commands.at(i).find(check);
		
		if (accnum_loc != -1 && field == 0) { 
			return bank_accounts.commands.at(i).substr(accnum_loc, 5);

		} else if (name_loc != -1 && field == 1) { 
			return erase(bank_accounts.commands.at(i).substr(name_loc, 20));
		}	
		//cout << bank_accounts.commands.at(i) << '\n';
	}
	return "";
}

/*int main () {
	//new bank_accounts object
	FileReader bank_accounts;
	//referring to the filepath of created object
	bank_accounts.file_path = "BankAccounts.txt";
	//call the readfile function on filepath given above
	bank_accounts.ReadFile();

	bank_accounts.commands = bank_accounts.buffer;
	
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

}*/
//	CSCI 3060/ SOFE 3980 Course Project Front End
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#include "TransactionProcessing.h"

TransactionProcessing::TransactionProcessing() {
	// set the default login mode to 'N' (Not logged in)
	login_mode = 'N';
	// set the default input type to 'T' (Termainal input)
	input_type = 'T';
	//referring to the filepath of created object
	transaction_writer.file_path = "Transaction.txt";
	// Set account holder's name, bank account number, amount, miscellaneous to default
	account_holder_name = "";
	account_number = "";
	amount = "";
	miscellaneous = "";
	trans_code = "";

	while (true) {
		getline(cin, input);
		startTransaction(input);
	}
}

TransactionProcessing::TransactionProcessing(string input_file) {
	// set the default login mode to 'N' (Not logged in)
	login_mode = 'N';
	// set the default input type to 'F' (File input)
	input_type = 'F';
	// Set the command index for the input file to 0
	command_index = 0;
	//referring to the filepath of created object
	transaction_writer.file_path = "Transaction.txt";

	//referring to the filepath of created object
	input_reader.file_path = input_file;
	//call the readfile function on filepath given above
	input_reader.ReadFile();
	input_reader.commands = input_reader.buffer;
	// Read int the commands from the file
	while (command_index < input_reader.commands.size()) { 
		input = input_reader.commands.at(command_index);
		// increase the command index
		command_index++;
		startTransaction(input);
	}
	// Start command line input when all the transaction in the input file is done
	while (true) {
		getline(cin, input);
		startTransaction(input);
	}
}

TransactionProcessing::~TransactionProcessing() {

}

void TransactionProcessing::startTransaction(string input) {

	// set the default transaction status to false;
	status = false;
	// Set the miscellaneous information to empty;
	miscellaneous = "";

	if (input == "login") {
		trans_code = "10";
		login();
	} else if (input == "withdrawal") {
		trans_code = "01";
		withdrawal();
	} else if (input == "transfer") {
		trans_code = "02";
		transfer();
	} else if (input == "paybill") {
		trans_code = "03";
		paybill();
	} else if (input == "deposit") {
		trans_code = "04";
		deposit();
	} else if (input == "create") {
		trans_code = "05";
		create();
	} else if (input == "delete") {
		trans_code = "06";
		delete1();
	} else if (input == "enable") {
		trans_code = "09";
		enable();
	} else if (input == "disable") {
		trans_code = "07";
		disable();
	} else if (input == "changeplan") {
		trans_code = "08";
		changeplan();
	} else if (input == "logout") {
		trans_code = "00";
		logout();
	} else {
		cout << "Invalid command." << endl;
	} 

}

string TransactionProcessing::readCommand() {
	string command;
	// if the input type is terminal input
	if (input_type == 'T') {
		getline(cin, command);
	}
	// if the input type is file input 
	else if (input_type == 'F') {
		command = input_reader.commands.at(command_index);
		cout << command << endl;
		// increase the command index
		command_index++;
	}
	return command;
}

bool TransactionProcessing::login() {

	// Keep track of valid account holder's name
	bool valid_name = true;

	// if there are no one logged in.
	if (login_mode == 'N') {
		msg = "Do you wish to login as a standard user or admin?";
		cout << msg << endl;
		input = readCommand();
		// logged in as standard mode
		if (input == "standard session") {
			msg = "Logged in as a standard user.";
			login_mode = 'S';
		} 
		// logged in as admin mode
		else if (input == "admin") {
			msg = "Logged in as an admin user.";
			login_mode = 'A';
		} 
		// Not valid mode
		else {
			msg = "Invalid Mode";
			cout << msg << endl;
			return status;
		}

		// set the miscel information
		miscellaneous =+ login_mode;
		cout << msg << endl;
		msg = "What is the account holder's name?";
		cout << msg << endl;
	  	input = readCommand();
		account_holder_name = input;
		
		// if account holder name is valid
		if (valid_name == true) {
			// Sucessfully log in
			status = true;
			msg = "logged in as " + account_holder_name + ".";
			cout << msg << endl;
			// write the transation file
			transaction_writer.WriteTransation(trans_code, account_holder_name, account_number, amount, miscellaneous);
			return status;
		}
		// if account hodler name is NOT valid
		else {
			msg = "Invalid account holder name";
			cout << msg << endl;
			return status;
		}
	} 
	// if there are already someone logged in
	else {
		msg = "login: Invalid command. User " + account_holder_name + " must be logged out before attempting to login again.";
		cout << msg << endl;
		return status;
	}

	return status;
}

bool TransactionProcessing::withdrawal() {
	// Keep track of the account holder name for withdrawal
	string withdrawal_acc_name;
	// Keep track of the account holder name for withdrawal
	string withdrawal_acc_num;
	// Keep track of the amount for withdrawal;
	string withdrawal_amount;
	// True if the amount to withdraw is valid, False if not
	bool valid_amount = true;
	// True if the account holder name to withdraw is valid, False if not
	bool valid_name = true;
	// True if the account number to withdraw is valid, False if not
	bool valid_num = true;
	
	// Check whether the user logged in.  If logged in, check if they have the privilege to withdrawal money
	// Return false if the user is not logged in
	if (login_mode == 'N') {
		msg = "withdrawal: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "withdrawal: Valid command.";
		cout << msg << endl;
		// Ask for the account holder's name if logged in as admin
		if (login_mode == 'A') {
			msg = "What is the account holder's name for withdrawal?";
			cout << msg << endl;
			input = readCommand();
			withdrawal_acc_name = input; 
		}
		// Set the account holder's name to the current user if logged in as standard 
		else {
			withdrawal_acc_name = account_holder_name;
		}

		// if the account holder name is valid.
		if (valid_name == true) {
			msg =  withdrawal_acc_name+ "set as withdrawal account holder.";
			cout << msg << endl;
			msg = "What is the account number you wish to withdrawal from?";
			cout << msg << endl;
			input = readCommand();
			withdrawal_acc_num = input;
			// if the account number is valid.			
			if (valid_num == true) {
				msg = "Valid account number " + withdrawal_acc_num + ".";
				cout << msg << endl;
				msg = "What is the amount to withdrawal?";
				cout << msg << endl;
				input = readCommand();
				withdrawal_amount = input;
				// if the amount is valid.	
				if (valid_amount == true) {
					// Successfully withdrawa money
					status = true;
					msg = "$" + withdrawal_amount + " withdrawn from account " + withdrawal_acc_num + ".";
					cout << msg << endl;
					// write the transaction file
					transaction_writer.WriteTransation(trans_code, withdrawal_acc_name, withdrawal_acc_num, withdrawal_amount, miscellaneous);
					return status;
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

	}
	return status;
}

bool TransactionProcessing::transfer() {
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

bool TransactionProcessing::paybill() {
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

bool TransactionProcessing::deposit() {
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

bool TransactionProcessing::create() {
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

bool TransactionProcessing::delete1() {
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

bool TransactionProcessing::enable() { 
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

bool TransactionProcessing::disable() {
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

bool TransactionProcessing::changeplan() {
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

bool TransactionProcessing::logout() { 
	// Check whether the user logged in.  If logged in, check if they have the privilege to logout
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "logout: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "logout: Valid command.";
		cout << msg << endl;
		msg = "Logout Sucessfully.";
		cout << msg << endl;
		transaction_writer.WriteTransation(trans_code, account_holder_name, account_number, amount, miscellaneous);
		login_mode = 'N';
		account_holder_name = "";
	}

	status = true;
	return status;
}
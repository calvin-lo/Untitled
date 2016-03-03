//	CSCI 3060/ SOFE 3980 Course Project Front endl
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#include "TransactionProcessing.h"

TransactionProcessing::TransactionProcessing(string trans_file) {
	// set the default login mode to 'N' (Not logged in)
	login_mode = 'N';
	// set the default input type to 'T' (Termainal input)
	input_type = 'T';

	//referring to the filepath of created object
	transaction_writer.file_path =  trans_file;
	// Set account holder's name, bank account number, amount, account type, miscellaneous to default
	account_holder_name = "";
	account_number = "";
	amount = "";
	miscellaneous = "";
	trans_code = "";
	acc_status = 'E';
	account_type = 'N';

	// parse the current bank account file
	parse();

	while (true) {
		getline(cin, input);
		startTransaction(input);
	}
}

TransactionProcessing::TransactionProcessing(string input_file, string trans_file) {
	// set the default login mode to 'N' (Not logged in)
	login_mode = 'N';
	// set the default input type to 'F' (File input)
	input_type = 'F';
	// Set the command index for the input file to 0
	command_index = 0;
	//referring to the filepath of created object
	transaction_writer.file_path = trans_file;


	// parse the current bank account file
	parse();

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
		// start transactions with given input
		startTransaction(input); 
	}
	// Start command line input when all the transaction in the input file is done
	TransactionProcessing("trans_file");
}

TransactionProcessing::TransactionProcessing() {
 	// set the default login mode to 'N' (Not logged in)
 	login_mode = 'N';
 	// set the default input type to 'T' (Termainal input)
 	input_type = 'T';
 	//referring to the filepath of created object
 	transaction_writer.file_path = "transactions.trans";
 	// Set account holder's name, bank account number, amount, account type, miscellaneous to default
 	account_holder_name = "";
 	account_number = "";
 	amount = "";
 	miscellaneous = "";
 	trans_code = "";
 	acc_status = 'E';
	account_type = 'N';
 
 	// parse the current bank account file
 	parse();
 
 	while (true) {
 		getline(cin, input);
 		startTransaction(input);
 	}
 }

TransactionProcessing::~TransactionProcessing() {

}

bool TransactionProcessing::startTransaction(string input) {

	// set the default transaction status to false;
	status = false;
	// Set the miscellaneous information to empty;
	miscellaneous = "";
	
	if (input == "login") {
		trans_code = "10";
		return login();
	} else if (input == "withdrawal") {
		trans_code = "01";
		return withdrawal();
	} else if (input == "transfer") {
		trans_code = "02";
		return transfer();
	} else if (input == "paybill") {
		trans_code = "03";
		return paybill();
	} else if (input == "deposit") {
		trans_code = "04";
		return deposit();
	} else if (input == "create") {
		trans_code = "05";
		return create();
	} else if (input == "delete") {
		trans_code = "06";
		return delete1();
	} else if (input == "enable") {
		trans_code = "09";
		return enable();
	} else if (input == "disable") {
		trans_code = "07";
		return disable();
	} else if (input == "changeplan") {
		trans_code = "08";
		return changeplan();
	} else if (input == "logout") {
		trans_code = "00";
		return logout();
	} else {
		cout << "Invalid command." << endl;
		return false;
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

	//startTransaction(in)

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
			account_type = 'S';
		}
		// logged in as admin mode
		else if (input == "admin session") {
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
		miscellaneous = + login_mode;
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
	// true if the transfer amount is under the limit, false if not
	bool valid_under_limit = true;

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
			msg =  withdrawal_acc_name + "set as withdrawal account holder.";
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
					msg = "Invalid amount";
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
			msg = "Invalid account holder name";
			cout << msg << endl;
			return status;
		}

	}
	return status;
}

bool TransactionProcessing::transfer() {
	// Keep track of the account holder name for transfer from
	string transfer_acc_name_from;

	// Keep track of the account holder name for transfer to
	string transfer_acc_name_to;

	// Keep track of the account holder name for transfer from
	string transfer_acc_num_from;

	// Keep track of the account holder name for transfer to
	string transfer_acc_num_to;

	// Keep track of the amount for transfer
	string transfer_amount;

	// True if the amount to transfer is valid, False if not
	bool valid_amount = true;

	// True if the account holder names to transfer is valid, False if not
	bool valid_name_from = true;
	bool valid_name_to = true;

	// True if the account numbers to transfer is valid, False if not
	bool valid_num_from = true;
	bool valid_num_to = true;

	// true if the transfer amount is under the limit, false if not
	bool valid_under_limit = true;

	// true if the account to transfer to is not disabled, false if not
	bool valid_not_disabled = true;

	// true if the account has enough money to cover the transaction fee, false if not
	bool valid_non_student_fee = true;

	// true if the account has enough money to cover the student transaction fee, false if not
	bool valid_student_fee = true;

	// true if the account has sufficient funds to cover transfer, false if not

	bool sufficient_funds = true;

	// Check whether the user logged in.  If logged in, check if they have the privilege to transfer money
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "trasfer: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "transfer: Valid command.";
		cout << msg << endl;

		// Admin mode transfer request
		if (login_mode == 'A') {
			msg = "What is the account holder's name for origin transfer?";
			cout << msg << endl;
			input = readCommand();
			transfer_acc_name_from = input;

			// standard mode transfer, from is the account currently logged in
		} else {
			transfer_acc_name_from = account_holder_name;
		}

		// if name given for origin transfer is valid
		if (valid_name_from == true) {
			msg =  transfer_acc_name_from + " selected as account holder name for origin transfer.";
			cout << msg << endl;
			msg = "What is the account number for origin transfer?";
			cout << msg << endl;
			input = readCommand();
			transfer_acc_num_from = input;

			// if the origin account number is valid.
			if (valid_num_from == true) {
				msg = "Account number " + transfer_acc_num_from + " selected for origin transfer.";
				cout << msg << endl;
				msg = "What is the destination account number";
				cout << msg << endl;
				input = readCommand();
				transfer_acc_num_to = input;

				// if destination account number is valid
				if (valid_num_to == true) {
					msg = "Account number " + transfer_acc_num_to + " set as destination account number.";
					cout << msg << endl;
					msg = "What is the amount to transfer from accounts " + transfer_acc_num_from + " to " + transfer_acc_num_to + "?";
					cout << msg << endl;
					input = readCommand();
					transfer_amount = input;

					//sufficient funds
					if (sufficient_funds == true) {
						// destination account number not disabled
						if (valid_not_disabled == true) {

							// if valid amount to transfer
							if (valid_amount == true) {

								// if account type is student, check if bal is enough to cover fee
								if (account_type == 'S') {
									if (valid_student_fee == true) {
										// if amount to transfer is below limit
										if (valid_under_limit == true) {
											// success

											status = true;
											msg = "$" + transfer_amount + " transferred from accounts " + transfer_acc_num_from + " to " + transfer_acc_num_to + ".";
											cout << msg << endl;
											transaction_writer.WriteTransation(trans_code, transfer_acc_name_from, transfer_acc_num_from, transfer_amount, miscellaneous);
											transaction_writer.WriteTransation(trans_code, transfer_acc_name_to, transfer_acc_num_to, transfer_amount, miscellaneous);
											return status;
											// amount to transfer above limit
										} else {
											msg = "Transfer limit exceeded. You must transfer less than $" + transfer_amount + ".";
											cout << msg << endl;
											return status;
										}
										// student not enough to cover fee
									} else {
										msg = "Insufficient funds of 5 cents to transfer $" + transfer_amount + " due to transaction fee.";
										cout << msg << endl;
										return status;
									}
								}
								// if account type is non-student, check if bal is enough to cover fee
								if (account_type == 'N') {
									if (valid_non_student_fee == true) {
										// if amount to transfer is below limit
										if (valid_under_limit == true) {
											// success

											status = true;
											msg = "$" + transfer_amount + " transferred from accounts " + transfer_acc_num_from + " to " + transfer_acc_num_to + ".";
											cout << msg << endl;
											transaction_writer.WriteTransation(trans_code, transfer_acc_name_from, transfer_acc_num_from, transfer_amount, miscellaneous);
											transaction_writer.WriteTransation(trans_code, transfer_acc_name_to, transfer_acc_num_to, transfer_amount, miscellaneous);
											return status;
											// amount to transfer above limit
										} else {
											msg = "Transfer limit exceeded. You must transfer less than $" + transfer_amount + ".";
											cout << msg << endl;
											return status;
										}
										// non - student not enough to cover fee
									} else {
										msg = "Insufficient funds of 10 cents to transfer $" + transfer_amount + " due to transaction fee.";
										cout << msg << endl;
										return status;
									}
								}
								// amount to transfer not valid
							} else {
								msg = "Invalid format. Must be ####.## where # is a digit 0 - 9.";
								cout << msg << endl;
								return status;
							}
							// destination account number disabled
						} else {
							msg = "Invalid destination account number, the account has been disabled.";
							cout << msg << endl;
							return status;
						}
						// insufficient funds
					} else {
						msg = "Insufficient funds to transfer $" + transfer_amount + ".";
						cout << msg << endl;
						return status;
					}
					// if destination account number is invalid
				} else {
					msg = "Invalid account number for destination of transfer.";
					cout << msg << endl;
					return status;
				}
				// origin account number is not valid
			} else {
				msg = "Invalid account number for origin of transfer.";
				cout << msg << endl;
				return status;
			}
			// origin account name is not valid
		} else {
			msg = "Invalid account name";
			cout << msg << endl;
			return status;
		}
	}
	return status;
}

bool TransactionProcessing::paybill() {
	// Keep track of the account holder name for withdrawal
	string paybill_acc_name;
	// Keep track of the account holder number for withdrawal
	string paybill_acc_num;
	// Keep track of the amount to be paid
	string paybill_amount;
	// Keep track of the company to whom the bill is being paid
	string paybill_company_name;
	// True if the amount to pay is valid, False if not
	bool valid_amount = true;
	// True if the account holder name to pay bill is valid, False if not
	bool valid_name = true;
	// True if the account holder number to pay bill is valid, False if not
	bool valid_num = true;
	// True if the company name to whom bill is being paid is valid, False if not
	bool valid_company_name = true;

	// Check whether the user logged in.  If logged in, check if they have the privilege to pay bill
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "paybill: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "paybill: Valid command.";
		cout << msg << endl;
		// Ask for the account holder's name if logged in as admin
		if (login_mode == 'A') {
			msg = "What is the account holder's name for bill payment?";
			cout << msg << endl;
			input = readCommand();
			paybill_acc_name = input;
		}
		// Set the account holder's name to the curretn user if logged in as standard
		else {
			paybill_acc_name = account_holder_name;
		}

		// if the account holder name is valid
		if (valid_name == true) {
			msg = paybill_acc_name + " set as the account holder of the bill payment.";
			cout << msg << endl;
			msg = "What is the account number from which you wish to pay a bill from?";
			cout << msg << endl;
			input = readCommand();
			paybill_acc_num = input;
			// if the account number is valid
			if (valid_num == true) {
				msg = "Valid account number " + paybill_acc_num + ".";
				cout << msg << endl;
				msg = "What is the amount to pay?";
				cout << msg << endl;
				input = readCommand();
				paybill_amount = input;
				// if the amout is valid (<2000)
				if (valid_amount == true) {
					msg = "Valid amount " + paybill_amount + ".";
					cout << msg << endl;
					msg = "What company would you like to pay the bill to?";
					cout << msg << endl;
					input = readCommand();
					paybill_company_name = input;
					// if the company name is valid
					if (valid_company_name == true) {
						// Successfully paid bill
						status = true;
						msg = "$" + paybill_amount + " Successfully paid to " + paybill_company_name + " from account number " + paybill_acc_num + ".";
						cout << msg << endl;
						// Write the transaction file
						transaction_writer.WriteTransation(trans_code, paybill_acc_name, paybill_acc_num, paybill_amount, paybill_company_name);
						return status;
					}
					// if the company name is NOT valid
					else {
						msg = "Invalid company name";
						cout << msg << endl;
						return status;
					}
				}
				// if the amount is NOT valid
				else {
					msg = "Invalid amount";
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
		// if the account name is NOT valid
		else {
			msg = "Invalid account holder name";
			cout << msg << endl;
			return status;
		}
	}
	return status;
}

bool TransactionProcessing::deposit() {
	// stores the name of the account holder
	string deposit_account_holder;

	// stores the account number of the account holder
	string deposit_account_num;

	// stores the amount to be deposited
	string amount_deposit;

	// true if the account holder is valid, otherwise false
	bool valid_account_holder = true;

	// true if the account number is valid, otherwise false
	bool valid_account_num = true;

	// true if the deposit is valid, otherwise false
	bool valid_deposit = true;

	// true if the deposit is a multiple of 5, otherwise false
	bool multiple_of_five = true;


	// Check whether the user logged in.  If logged in, check if they have the privilege to deposit money
	// Return false if the user is not logged
	if (login_mode == 'N') {
		msg = "deposit: Invalid command. You are required to be logged into the system.";
		cout << msg << endl;
		return status;
	} else if (login_mode == 'S' || login_mode == 'A') {
		msg = "deposit: Valid command.";
		cout << msg << endl;
		msg = "What is the account number?";
		cout << msg << endl;
		input = readCommand();
		deposit_account_num = input;
		deposit_account_holder = account_holder_name;
		// if account number is valid
		if (valid_account_num == true) {
			// if account name is valid
			if (valid_account_holder == true) {
				msg = "Login successful. What is the amount to be deposited?";
				cout << msg << endl;
				input = readCommand();
				amount_deposit = input;

				// if valid deposit
				if (valid_deposit == true) {
					msg = "Deposit completed";
					cout << msg << endl;

					// if it is a multiple of five and student account
					if (multiple_of_five == true && account_type == 'S') {
						// success
						status = true;
						msg = "$" + amount_deposit + " successfully deposited ($00.10 deducted for Non - Student Account transaction fees).";
						cout << msg << endl;
						msg = "Deposited amount usable next day only.";
						cout << msg << endl;
						transaction_writer.WriteTransation(trans_code, deposit_account_holder, deposit_account_num, amount, miscellaneous);
						return status;
						// if it is a multiple of five and a non student account
					} else if (multiple_of_five == true && account_type == 'N') {
						// success
						status = true;
						msg = "$" + amount_deposit + " successfully deposited ($00.05 deducted for Non - Student Account transaction fees).";
						cout << msg << endl;
						msg = "Deposited amount usable next day only.";
						cout << msg << endl;
						transaction_writer.WriteTransation(trans_code, deposit_account_holder, deposit_account_num, amount, miscellaneous);
						return status;
						//not a multiple of five
					} else {
						msg = "Unable to complete deposit. Amount must be a multiple of 5.";
						cout << msg << endl;
						return status;
					}
					// not a valid deposit
				} else {
					msg = "Amount format incorrect. Deposit failed.";
					cout << msg << endl;
					return status;
				}
				// account holder is not valid
			} else {
				msg = "Name and account number do not match. Deposit rejected.";
				cout << msg << endl;
				return status;
			}
			// account number is not valid
		} else {
			msg = "Name and account number do not match. Deposit rejected.";
			cout << msg << endl;
			return status;
		}
	}
	return status;
}

bool TransactionProcessing::create() {
	// Stores the name of the account holder you want to create
	string create_account_name;
	// Stores the account number that you want to create
	string create_account_num;
	// True if the account name is valid, otherwise false
	bool valid_account_name = true;
	// True if the account number is valid, otherwise false
	bool valid_account_num = true;

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
		msg = "Enter the new bank account holder's name to be created.";
		cout << msg << endl;
		input = readCommand();
		create_account_name = input;
		// If the account holder's name is valid
		if (valid_account_name == true) {
			msg = "Accepted new bank account name: " + create_account_name + ".";
			cout << msg << endl;
			msg = "Enter the bank account number to be created.";
			cout << msg << endl;
			input = readCommand();
			create_account_num = input;
			// If account number is valid
			if (valid_account_num == true) {
				// Successfully created account
				status = true;
				msg = "Accepted bank account number to be created: " + create_account_num + " for " + create_account_name + ". Information saved to bank account transaction file.";
				cout << msg << endl;
				transaction_writer.WriteTransation(trans_code, create_account_name, create_account_num, amount, miscellaneous);
				return status;
				// If the account number is not valid
			} else {
				msg = "Rejected bank account number to be created: " + create_account_num + ". (Entered an invalid bank account number)";
				cout << msg << endl;
				return status;
			}
			// If the account holder's name is not valid
		} else {
			msg = "Rejected bank account holder's name. (Entered an invalid account holder name).";
			cout << msg << endl;
			return status;
		}
	}
	msg = "Account creation unsuccessful.";
	cout << msg << endl;
	return status;
}

bool TransactionProcessing::delete1() {
	// stores the name of the account holder that you want to delete
	string delete_account_holder;

	// stores the account number that you want to delete
	string delete_account_num;
	// true if the account holder is valid, otherwise false
	bool valid_account_holder = true;

	// true if the bank acconut number is valid, otherwise false
	bool valid_account_num = true;

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
		msg = "Enter the bank account holder's name to be deleted.";
		cout << msg << endl;
		input = readCommand();
		delete_account_holder = input;
		// if the account holder's name is valid
		if (valid_account_holder == true) {
			msg = "Accepted bank account holder's name: " + delete_account_holder + ".";
			cout << msg << endl;
			msg = "Enter bank account number to be deleted.";
			cout << msg << endl;
			input = readCommand();
			delete_account_num = input;
			// if account number is valid
			if (valid_account_num == true) {
				// success
				status = true;
				msg = "Accepted bank account number to be deleted: " + delete_account_num + ".";
				cout << msg << endl;
				msg = "Account " + delete_account_num + "from " + delete_account_holder + " has been deleted. Information saved to bank account transaction file.";
				cout << msg << endl;
				transaction_writer.WriteTransation(trans_code, delete_account_holder, delete_account_num, amount, miscellaneous);
				return status;
				// if the account number is not valid
			} else {
				msg = "Rejected bank account number to be deleted: " + delete_account_num + ". (Entered an invalid bank account number)";
				cout << msg << endl;
				return status;
			}
			// if the account holder's name is not valid
		} else {
			msg = "Rejected bank account holder's name: Invalid name. (Entered an invalid account holder's name)";
			cout << msg << endl;
			return status;
		}
	}
	msg = "Delete Unsucessfully.";
	cout << msg << endl;
	return status;
}

bool TransactionProcessing::enable() {
	// stores the name of the account holder that you want to enable
	string enable_account_holder;

	// stores the account number that you want to enable
	string enable_account_num;
	// true if the account holder is valid, otherwise false
	bool valid_account_holder = true;

	// true if the bank acconut number is valid, otherwise false
	bool valid_bank_acc_num = true;

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
		msg = "Enter the bank account holder's name to be enabled.";
		cout << msg << endl;
		input = readCommand();
		enable_account_holder = input;
		// valid account holder
		if (valid_account_holder == true) {
			msg = "Accepted bank account holder's name : " + enable_account_num + ".";
			cout << msg << endl;
			msg = "Enter bank account number to be enabled.";
			cout << msg << endl;
			input = readCommand();
			enable_account_num = input;
			// valid bank account number, enabled account
			if (valid_bank_acc_num == true && acc_status == 'E') {
				//success
				status = true;
				msg = "Accepted bank account number :" + enable_account_num + ".";
				cout << msg << endl;
				msg = "Account" + enable_account_num + "from" + enable_account_holder + "had been enabled. Information saved to bank account transaction file.";
				cout << msg << endl;
				transaction_writer.WriteTransation(trans_code, enable_account_holder, enable_account_num, amount, miscellaneous);
				return status;
				// valid bank account number, disabled account
			} else if (valid_bank_acc_num && acc_status == 'D') {
				msg = "Rejected bank account number to be enabled :" + enable_account_holder + "(Account " + enable_account_num + " is a enabled account.)";
				cout << msg << endl;
				return status;
			} else { // not valid bank account number
				msg = "Rejected bank account number to be enabled :" + enable_account_holder + "(Account " + enable_account_num + ". (Entered an invalid bank account number)";
				cout << msg << endl;
				return status;
			}
			// not valid account holder
		} else {
			msg = "Rejected the bank account holder's name : Invalid name.  (Entered an invalid account holder's name)";
			cout << msg << endl;
			return status;
		}
	}
	msg = "enable Unsucessfully.";
	cout << msg << endl;
	return status;
}

bool TransactionProcessing::disable() {

	// Keep track of the account holder name to disable
	string disable_account_name;
	// Keep track of the account number to disable
	string disable_account_num;
	// True if the account holder name is valid, False if not
	bool valid_account_name = true;
	// True if the account holder number is valid, False if not
	bool valid_account_number = true;

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
		msg = "Enter the bank account holder's name to be disabled.";
		cout << msg << endl;
		input = readCommand();
		disable_account_name = input;
		// if valid account holder name
		if (valid_account_name == true) {
			msg = "Accepted bank account holder's name: " + disable_account_num + ".";
			cout << msg << endl;
			msg = "Enter bank account number to be disabled.";
			cout << msg << endl;
			input = readCommand();
			disable_account_num = input;
			// Valid bank account number, account disabled
			if (valid_account_number == true && acc_status == 'D') {
				// Successfully disabled
				status = true;
				msg = "Accepted bank account number: " + disable_account_num + ".";
				cout << msg << endl;
				msg = "Account" + disable_account_num + " from " + disable_account_name + " has been disabled. Information saved to bank account transaction file.";
				cout << msg << endl;
				transaction_writer.WriteTransation(trans_code, disable_account_name, disable_account_num, amount, miscellaneous);
				return status;
				// Valid bank account number, enabled account
			} else if (valid_account_number && acc_status == 'E') {
				msg = "Rejected bank account number to be disabled: " + disable_account_name + " (Account " + disable_account_num + " is an enabled account).";
				cout << msg << endl;
				return status;
			} else { // Not valid bank account number
				msg = "Rejected bank account number to be disabled: " + disable_account_name + ", Account number: " + disable_account_num + ". (entered an invalid bank account number).";
				cout << msg << endl;
				return status;
			}
			// Invalid account holder
		} else {
			msg = "Rejected bank account holder's name (Invalid name)";
			cout << msg << endl;
			return status;
		}
	}
	msg = "Account disable unsuccessful.";
	cout << msg << endl;
	return status;
}

bool TransactionProcessing::changeplan() {

	// stores the name of the account holder that you want to change the plan for
	string changeplan_account_holder;

	// stores the account number that you want to change the plan for
	string changeplan_account_num;
	// true if the account holder is valid, otherwise false
	bool valid_account_holder = true;

	// true if the bank acconut number is valid, otherwise false
	bool valid_bank_acc_num = true;

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
		msg = "Enter the bank account holder's name to change the transaction payment plan.";
		cout << msg << endl;
		input = readCommand();
		changeplan_account_holder = input;
		// if valid bank account holder name student to non student
		if (valid_account_holder == true) {
			msg = "Accepted bank account holder's name: " + changeplan_account_holder + ".";
			cout << msg << endl;
			msg = "Enter bank account number to change the transaction payment plan.";
			cout << msg << endl;
			input = readCommand();
			changeplan_account_num = input;
			// valid bank account number
			if (valid_bank_acc_num == true && account_type == 'S') {
				//success

				status = true;
				msg = "Accepted bank account number: " + changeplan_account_num + ".";
				cout << msg << endl;
				msg = "Account " + changeplan_account_num + "from " + changeplan_account_holder + "has changed from student (SP) to non - student (NP). Information saved to bank account transaction file.";
				cout << msg << endl;
				transaction_writer.WriteTransation(trans_code, changeplan_account_holder, changeplan_account_num, amount, miscellaneous);
				return status;
				// valid bank account number non student to student
			} else if (valid_bank_acc_num == true && account_type == 'N') {
				// success

				status = true;
				msg = "Account " + changeplan_account_num + "from " + changeplan_account_holder + "has changed from non - student (NP) to student (SP). Information saved to bank account transaction file.";
				cout << msg << endl;
				transaction_writer.WriteTransation(trans_code, changeplan_account_holder, changeplan_account_num, amount, miscellaneous);
				return status;
				// not valid bank account number
			} else {
				msg = "Rejected bank account number to change the transaction payment plan : " + changeplan_account_num + " (Entered an invalid bank account number)";
				cout << msg << endl;
				return status;
			}
			// not valid bank account holder name
		} else {
			msg = "Rejected Bank account holder's name: Invalid name.  (Entered an invalid account holder's name)";
			cout << msg << endl;
			return status;
		}
	}
	//fail
	msg = "changeplan Unsucessfully.";
	cout << msg << endl;
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

void TransactionProcessing::parse() {

	FileReader bank_account_reader;
	//referring to the filepath of created object
	bank_account_reader.file_path = "BankAccounts.txt";
	//call the readfile function on filepath given above
	bank_account_reader.ReadFile();
	bank_account_reader.commands = bank_account_reader.buffer;

	for (int i = 0; i < bank_account_reader.commands.size(); i++) {

		bank_account temp_account;
		// Bank account number start at 0 and have a length of 5
		temp_account.acc_number = bank_account_reader.buffer.at(i).substr(0, 5);
		// Bank account holder name start at 6 and have a length of 20
		temp_account.acc_holder_name = bank_account_reader.buffer.at(i).substr(6, 20);
		// Account status (Active or Disabled) at 27
		temp_account.acc_status = bank_account_reader.buffer.at(i).at(27);
		// Account balance start at 29 and have a length of 8
		temp_account.acc_balance = bank_account_reader.buffer.at(i).substr(29, 8);
		// Account type (Student or Non Student) at 38
		temp_account.acc_type = bank_account_reader.buffer.at(i).at(38);

		// Remove all the white space after the last character
		temp_account.acc_holder_name = trim(temp_account.acc_holder_name);

		//cout << temp_account.acc_holder_name.length() << endl;

		// push back the temp account to the all account vector
		all_accounts.push_back(temp_account);

	}

}

string TransactionProcessing::trim(string s)
{
	// substing from 0 to the first not white space char from the end
	return s.substr(0, (s.find_last_not_of(' ') + 1));
}
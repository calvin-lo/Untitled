//	CSCI 3060/ SOFE 3980 Course Project Front End
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#ifndef TransactionProcessing_h_
#define TransactionProcessing_h_

#include <string>

using namespace std;

class TransactionProcessing {

private:

	// Keep track of the user input
	string input;	
	// Keep track of the transaction status
	bool status;
	// The output msg to terminal or file
	string msg;
	// Keep track of the current session mode (A for admin; S for standard; N for not logged in)
	char login_mode;
	// Keep track of the current account holder name
	string account_holder_name;

protected:

public:

	// Constructor
	// Set the login_mode to N
	// Set the status to false
	TransactionProcessing();
	// Deconstructor
	~TransactionProcessing();
	// Start a Front End session
	// Set the login_mode to S if logged in standard mode
	// Set the login_mode to A if logged in admin mode
	// Set the account_holder_name based on user input
	// Returns true if the transaction success
	bool login(string line);
	// Withdraw money from a bank account
	// Returns true if the transaction success
	bool withdrawal(string line);
	// Transfer money from one bank account to another
	// Returns true if the transaction success
	bool transfer(string line);
	// Pay a bill from a bank account
	// Returns true if the transaction success
	bool paybill(string line);
	// Deposit money into a bank account
	// Returns true if the transaction success
	bool deposit(string line);
	// Create a new bank account (privileged transaction) 
	// Returns true if the transaction success
	bool create(string line);
	// Delete a bank account (privileged transaction)
	// Returns true if the transaction success
	bool delete1(string line);
	// Enable all transactions in a bank account (privileged transaction)
	// Returns true if the transaction success
	bool enable(string line);
	// Disable all transactions in a bank account (privileged transaction)
	// Returns true if the transaction success	
	bool disable(string line);
	// Change the transaction plan of a bank account (privileged transaction)
	// Returns true if the transaction su	
	bool changeplan(string line);
	// End a Front End session
	// Returns true if the transaction su	
	bool logout(string line);
	// Parse BankAccounts.txt file for accounts
	string parse(string check, int field);


};

#endif // TransactionProcessing_h_
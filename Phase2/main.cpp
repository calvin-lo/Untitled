//	CSCI 3060/ SOFE 3980 Course Project Front End
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#include "TransactionProcessing.h"
#include "FileReader.h"
#include "FileWriter.h"

// main function
int main() {
	TransactionProcessing T;
	string input;
	while (true) {
		getline(cin, input);
		if (input == "login") {
			T.login(input);
		} else if (input == "withdrawal") {
			T.withdrawal(input);
		} else if (input == "transfer") {
			T.transfer(input);
		} else if (input == "paybill") {
			T.paybill(input);
		} else if (input == "deposit") {
			T.deposit(input);
		} else if (input == "create") {
			T.create(input);
		} else if (input == "delete") {
			T.delete1(input);
		} else if (input == "enable") {
			T.enable(input);
		} else if (input == "disable") {
			T.disable(input);
		} else if (input == "changeplan") {
			T.changeplan(input);
		} else if (input == "logout") {
			T.logout(input);
		} else {
			cout << "Invalid command." << endl;
		} 

	}
	return 0;
}
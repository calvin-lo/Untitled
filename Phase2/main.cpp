//	CSCI 3060/ SOFE 3980 Course Project Front End
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#include "TransactionProcessing.h"

// main function
int main(int argc, char*argv[]) {

	// if no file specified, start terminal input
	if (argc == 1) {
		TransactionProcessing T;
	} 
	// if there are file specified, start file input
	else {
		TransactionProcessing T(argv[1]);
	}
	return 0;
}
/*
	CSCI 3060/ SOFE 3980 Course Project Front End
	Group: Untitled
	Member: Calvin Lo, Albert Fung, Karan Chandwaney
*/
#ifndef __TransactionProcessing_h__ 
#define __TransactionProcessing_h__

#include <string>

using namespace std;

/*

*/
class TransactionProcessing {

private:

	string input;	
	bool status;

protected:

public:

	TransactionProcessing();
	~TransactionProcessing();
	bool login(string line);
	bool withdrawal(string line);
	bool transfer(string line);
	bool paybill(string line);
	bool deposit(string line);
	bool create(string line);
	bool delete1(string line);
	bool enable(string line);
	bool disable(string line);
	bool changeplan(string line);
	bool logout(string line);



};

#endif

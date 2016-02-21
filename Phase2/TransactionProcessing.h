/*
	CSCI 3060/ SOFE 3980 Course Project Front End
	Group: Untitled
	Member: Calvin Lo, Albert Fung, Karan Chandwaney
*/
#ifndef __TransactionProcessing_h__ 
#define __TransactionProcessing_h__

#include <string>
#include <vector>

using namespace std;

/*

*/
class TransactionProcessing {

private:
	
	bool status;

protected:

public:
	string input;
	TransactionProcessing();
	~TransactionProcessing();
	bool login();
	bool withdrawal();
	bool transfer();
	bool paybill();
	bool deposit();
	bool create();
	bool delete1();
	bool enable();
	bool disable();
	bool changeplan();
	bool logout();
	bool in_array(string value, vector<string> array);
	string promptTransaction();
	string parse(string to_parse, int field);
};

#endif

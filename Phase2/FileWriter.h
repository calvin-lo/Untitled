/*
	CSCI 3060/ SOFE 3980 Course Project Front End
	Group: Untitled
	Member: Calvin Lo, Albert Fung, Karan Chandwaney
*/
#ifndef __FileWriter_h__ 
#define __FileWriter_h__

#include <string>

using namespace std;

class FileWriter { 
 public:
	string file_path; //stores file path
	void WriteFile(string); //WriteFile function
};

#endif

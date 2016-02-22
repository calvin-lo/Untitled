//	CSCI 3060/ SOFE 3980 Course Project Front End
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
#ifndef __FileReader_h__ 
#define __FileReader_h__

#include <string>
#include <vector> 
#include <iostream> 
#include <fstream>

using namespace std;


class FileReader { 
 public:
	string file_path; //stores file path
	vector<string> commands;
	vector<string> ReadFile(); //ReadFile function
};


#endif // FileReader_h_

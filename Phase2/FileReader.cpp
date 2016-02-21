// Phase2.cpp : main project file.

//Imports
#include "FileReader.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <vector> 

using namespace std;

vector<string> buffer;
//ReadFile function
void FileReader::ReadFile() { 
	string line; //stores line of currently read string
	
	ifstream file(file_path); //open ifstream
	if (file.is_open()) {  //if file opened successfully
		while (getline(file,line)) { //while there are lines
			buffer.push_back(line); //intpush into the list
		}
		file.close(); //close file
	} else { //if the file is not found
		cout << "Unable to open" << '\n';
	}
}
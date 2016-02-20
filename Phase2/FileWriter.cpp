// Phase2.cpp : main project file.

//Imports
#include "FileWriter.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

//WriteFile function
void FileWriter::WriteFile(string line) { 
	ofstream file(file_path); //open ifstream
	if (file.is_open()) {  //if file opened successfully
		file << line << '\n';
		file.close(); //close file
	} else { //if the file is not found
		cout << "Unable to open" << '\n';
	}
}

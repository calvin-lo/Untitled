//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: writes out files for the back end

import java.util.*;
import java.io.*;

public class FileWriter { 
        java.io.FileWriter FW;
	public FileWriter(String filename) { 
            try {
                FW = new java.io.FileWriter(new File(filename));
            } catch (IOException e) {
                System.out.println("ERROR: Cannot open File Writer.");
            }
	}
	
	// produces a new Current Bank File
	public void writeCBAF(List<account> updated_accounts) {
            // loop all the updated accounts and write the information to the new file
            int length = 39;
            for (int i = 0; i < updated_accounts.size(); i++) {
                    // init variables
                    int index = 0;
                    String line = "";
                    // fill in the account number
                    line += updated_accounts.get(i).acc_num + " ";
                    // fill in the account holder
                    // if the account holder name is less than 20 characters
                    if (updated_accounts.get(i).acc_holder.length() < 20) {
                        // fill out the name first and space separator
                        line += updated_accounts.get(i).acc_holder + " ";
                        // fill out the remaining spaces
                        for (int j = 0; j < 20 - updated_accounts.get(i).acc_holder.length(); j++) {
                            line += " ";
                        }
                    } 
                    // if the account holder name had exactly 20 characters
                    else if (updated_accounts.get(i).acc_holder.length() == 20) {
                        line += updated_accounts.get(i).acc_holder + " ";
                    }
                    // fill in the account status
                    line += updated_accounts.get(i).acc_status + " ";
                    // fill in the account balance
                    // make sure the account balance have a length of 8
                    if ( updated_accounts.get(i).acc_balance.length() < 8) {
                        // fill out the 0 first
                        for (int j = 0; j < 8 - updated_accounts.get(i).acc_balance.length(); j++) {
                            line += "0";
                        }
                        // fill out the actual balance
                        line += updated_accounts.get(i).acc_balance + " ";
                    }
                    else if ( updated_accounts.get(i).acc_balance.length() == 8) {
                        line += updated_accounts.get(i).acc_balance + " ";
                    }
                    // fill in teh account type
                    line += updated_accounts.get(i).acc_type;
                    
                    // Write the information
                    try {
                        FW.write(line + '\n');
                    } catch (IOException e) {
                        System.out.println("ERROR: Cannot write file");
                    }
            }
        }
	
	// close the FileWriter
	public void close() {
            try {
                FW.close();
            } catch (IOException e) {
                System.out.println("ERROR: Cannot close File Writer");
            }
	}
}
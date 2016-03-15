//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: processes and applies all transactions from merged Bank Account Transaction files

import java.util.*;

class account {
    public String acc_holder;
    public String acc_num;
    public char acc_status;
    public String acc_balance;
    public char acc_type;
}

public class Transactions { 

        List<account> all_accounts;
        FileReader FR;

	public Transactions() { 
            all_accounts = new ArrayList<account>();
            FR = new FileReader("f.trans", "merged.trans");
            parse();
	}
	
	// read current bank account file
	public void parse() {
	
            List<String> currAccFile = new ArrayList<String>();
            currAccFile = FR.readFile("BankAccounts.txt");
            for (int i = 0; i < currAccFile.size(); i++) {
                account temp_account = new account();
                // Bank account number start at pos 0 and end at 5.
                temp_account.acc_num = currAccFile.get(i).substring(0,5);
                // Bank account holder name start at 6 and end at 26;
                temp_account.acc_holder = currAccFile.get(i).substring(6,26);
                // Account status (Active or Disabled) at 27
                temp_account.acc_status = currAccFile.get(i).charAt(27);
                // Accpunt balance start at 29 and end at 37
                temp_account.acc_balance = currAccFile.get(i).substring(29,37); 
                // Account type (Student or Non Student) at 38 
                temp_account.acc_type = currAccFile.get(i).charAt(38);
                
                // Remove all the white space after the last character
                temp_account.acc_holder = temp_account.acc_holder.trim();
                
                // put the temp account to the list
                all_accounts.add(temp_account);
                
            }
	}
	
	
}
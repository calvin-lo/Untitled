//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: processes and applies all transactions from merged Bank Account Transaction files

import java.util.*;


// Store the account information
class account {
    public String acc_holder;
    public String acc_num;
    public char acc_status;
    public String acc_balance;
    public char acc_type;
}

// Store the transaction information
class trans {
    public String code;
    public String acc_holder;
    public String acc_num;
    public String amount;
    public String mis_info;
}

public class Transactions { 

        List<account> all_accounts;
        List<trans> all_trans;
        FileReader FR;
        // store the current index of the transactions list
        int trans_index;

	public Transactions(String transDir, String mergedPath) { 
            all_accounts = new ArrayList<account>();
            all_trans = new ArrayList<trans>();
            FR = new FileReader(transDir, mergedPath);
            parseCurrent();
            parseMerged();
            
            // init trans_index to zero;
            trans_index = 0;
            
            // loop all transaction and execute corresponding commands
            while (trans_index < all_trans.size()) {
                execute(all_trans.get(trans_index).code);
               
                // add 1 to trans_index;
                trans_index++;
            }
            
            // create new current bank account file
            createNewCurrent(all_accounts);
	}
	
	// Write Current Bank Account File
	public void createNewCurrent(List<account> updated_accounts) {
            FileWriter FW = new FileWriter("new_BankAccounts.txt");
            FW.writeCBAF(updated_accounts);
            FW.close();
	}
	
	// execute the commands based on the code
	public void execute(String code) {
            if (code.equals("10")) {
                login();
            } else if (code.equals("01")) {
                withdrawal();
            } else if (code.equals("02")) {
                transfer();
            } else if (code.equals("03")) {
                paybill();
            } else if (code.equals("04")) {
                deposit();
            } else if (code.equals("05")) {
                create();
            } else if (code.equals("06")) {
                delete();
            } else if (code.equals("07")) {
                disable();
            } else if (code.equals("08")) {
                changeplan();
            } else if (code.equals("09")) {
                enable();
            } else if (code.equals("00")) {
                logout();
            } else {
                System.out.println("ERROR: Invalid transaction code!");
            }
	}
	
        // read current bank account file
	public void parseCurrent() {
	
            // get the file from the file reader
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
	
        // read the merged Transaction file
        public void parseMerged() {
        
            // get the file from the file reader
            List<String> transFile = new ArrayList<String>();
            transFile = FR.readFile("merged.trans");
            // loop all the transaction
            for (int i = 0; i < transFile.size(); i++)  {
                trans temp_trans = new trans();
                // code start at pos 0 to 2;
                temp_trans.code = transFile.get(i).substring(0,2);
                // account holder name start at pos 3 and end at 22
                temp_trans.acc_holder = transFile.get(i).substring(3,22);
                // account number start at pos 23 and end at 28
                temp_trans.acc_num = transFile.get(i).substring(23,28);
                // amount start at pos 29 and end at 37
                temp_trans.amount = transFile.get(i).substring(29,37);
                // mis info start at pos 38 and end at 40
                temp_trans.mis_info = transFile.get(i).substring(38,40);
                
                // Remove all the white space after the last character
                temp_trans.acc_holder = temp_trans.acc_holder.trim();
                
                // put the temp account to the list
                all_trans.add(temp_trans);
                
            }
            
        }
        
        // login
        public void login() {

        }
        
        // withdrawal
        public void withdrawal() {
            
        }
        
        // transfer
        public void transfer() {
            
        }
        
        // paybill
        public void paybill() {
            
        }
        
        // deposit
        public void deposit() {
            
        }
        
        // create
        public void create() {
            
        }
        
        // delete
        public void delete() {
            
        }
        
        // enable
        public void enable() {
        
        }
        
        // Disable
        public void disable() {
        
        }
        
        // changeplan
        public void changeplan() {
        
        }
        
        //logout 
        public void logout() {
        
        }
        
        // search the target account by name
        // return the position of the account
        // return -1 if not found
        int searchName(String name) {
            for (int i = 0; i < all_accounts.size(); i++) {
                if (all_accounts.get(i).acc_holder.equals(name)) {
                    return i;
                }
            }
            return -1;
        }
        
        // search the target account by account number
        // return the position of the account
        // return -1 if not found
        int searchAcc(String acc_num) {
            for (int i = 0; i < all_accounts.size(); i++) {
                if (all_accounts.get(i).acc_num.equals(acc_num)) {
                    return i;
                }
            }
            return -1;
        }
        
        // search the target account by name AND account number
                // return the position of the account
        // return -1 if not found
        int searchNameAcc(String name, String acc_num) {
            for (int i = 0; i < all_accounts.size(); i++) {
                if (all_accounts.get(i).acc_holder.equals(name) && all_accounts.get(i).acc_num.equals(acc_num)) {
                    return i;
                }
            }
            return -1;
        }
               
        
	
}
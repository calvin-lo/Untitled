
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
	public int num_trans;
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
	// store the current login mode
	int curr_login_mode;
	
	
	// empty constructor for testing
	public Transactions() {
            curr_login_mode = 'S';
            all_accounts = new ArrayList<account>();
            all_trans = new ArrayList<trans>();
            FR = new FileReader();
	}
	
	public Transactions(String mergedPath) {
		// set the default login mode as standard
		curr_login_mode = 'S';
		all_accounts = new ArrayList<account>();
		all_trans = new ArrayList<trans>();
		FR = new FileReader();
		all_accounts = parseMaster("MasterAccounts.txt");
		all_trans = parseMerged(mergedPath);

		// init trans_index to zero;
		trans_index = 0;

		// loop all transaction and execute corresponding commands
		while (trans_index < all_trans.size()) {
                        trans current_trans = all_trans.get(trans_index);
			execute(current_trans.code, current_trans);

			// add 1 to trans_index;
			trans_index++;
		}

		// calculate the trans fee
		for (int i = 0; i < all_accounts.size(); i++) {
			float trans_fee = all_accounts.get(i).num_trans * getTransactionFee(i);
			String trans_fee_S = Float.toString(trans_fee);
			minus(i, trans_fee_S);
		}

		// create new current bank account file
		createNewCurrent(all_accounts);
		// create new master bank account file
		createNewMaster(all_accounts);
	}

	// execute the commands based on the code
	public void execute(String code, trans current_trans) {
		if (code.equals("10")) {
			login(current_trans);
		} else if (code.equals("01")) {
			withdrawal(current_trans);
		} else if (code.equals("02")) {
			transfer(current_trans);
		} else if (code.equals("03")) {
			paybill(current_trans);
		} else if (code.equals("04")) {
			deposit(current_trans);
		} else if (code.equals("05")) {
			create(current_trans);
		} else if (code.equals("06")) {
			delete(current_trans);
		} else if (code.equals("07")) {
			disable(current_trans);
		} else if (code.equals("08")) {
			changeplan(current_trans);
		} else if (code.equals("09")) {
			enable(current_trans);
		} else if (code.equals("00")) {
			logout(current_trans);
		} else {
			System.out.println("ERROR: Invalid transaction code!");
		}
	}

	// read Master bank account file
	public List<account> parseMaster(String path) {
                List<account> result = new ArrayList<account>();
		// get the file from the file reader
		List<String> masterFile = new ArrayList<String>();
		masterFile = FR.readFile(path);
		for (int i = 0; i < masterFile.size(); i++) {
			account temp_account = new account();
			// Bank account number start at pos 0 and end at 5.
			temp_account.acc_num = masterFile.get(i).substring(0, 5);
			// Bank account holder name start at 6 and end at 26;
			temp_account.acc_holder = masterFile.get(i).substring(6, 26);
			// Account status (Active or Disabled) at 27
			temp_account.acc_status = masterFile.get(i).charAt(27);
			// Accpunt balance start at 29 and end at 37
			temp_account.acc_balance = masterFile.get(i).substring(29, 37);
			// Account type (Student or Non Student) at 38
			temp_account.acc_type = masterFile.get(i).charAt(38);
			// number of transaction start at 40 to 43
			//temp_account.num_trans = Integer.parseInt(masterFile.get(i).substring(40, 44));
			temp_account.num_trans = 0;
			// Remove all the white space after the last character
			temp_account.acc_holder = temp_account.acc_holder.trim();

			// put the temp account to the list
			result.add(temp_account);
		}
		
		return result;
	}

	// read the merged Transaction file
	public List<trans> parseMerged(String path) {
                List<trans> result = new ArrayList<trans>();
		// get the file from the file reader
		List<String> transFile = new ArrayList<String>();
		transFile = FR.readFile(path);
		//transFile = FR.readFile("merged.trans");
		//transFile = FR.readFile("MergedBankAccountTrans.trans");
		// loop all the transaction
		for (int i = 0; i < transFile.size(); i++) {
			trans temp_trans = new trans();
			// code start at pos 0 to 2;
			temp_trans.code = transFile.get(i).substring(0, 2);
			// account holder name start at pos 3 and end at 22
			temp_trans.acc_holder = transFile.get(i).substring(3, 22);
			// account number start at pos 23 and end at 28
			temp_trans.acc_num = transFile.get(i).substring(23, 28);
			// amount start at pos 29 and end at 37
			temp_trans.amount = transFile.get(i).substring(29, 37);
			// mis info start at pos 38 and end at 40
			temp_trans.mis_info = transFile.get(i).substring(38, 40);

			// Remove all the white space after the last character
			temp_trans.acc_holder = temp_trans.acc_holder.trim();

			// put the temp account to the list
			result.add(temp_trans);
		}
		
                return result;

	}

        // Write Current Bank Account File
	public void createNewCurrent(List<account> updated_accounts) {
		FileWriter FW = new FileWriter("new_BankAccounts.txt");
		FW.writeCurrent(updated_accounts);
		FW.close();
	}

	// Write Master Bank Account File
	public void createNewMaster(List<account> updated_accounts) {
		FileWriter FW = new FileWriter("new_MasterAccounts.txt");
		FW.writeMaster(updated_accounts);
		FW.close();
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
		// if the account doesn't exist
		System.out.println("ERROR: Account doesn't exist.");
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
                // if the account doesn't exist
		System.out.println("ERROR: Account doesn't exist.");
		return -1;
	}

	// minus the amount from a specfic account position
	// return true if succesfully minus, else return false
	boolean minus(int pos, String value) {
	
                // check if the pos is valid
                if (pos < 0 || pos > all_accounts.size()) {
                    // if the account doesn't exist
                    System.out.println("ERROR: Account doesn't exist.");
                    return false;
                }
                
                
                float amount = 0;
                float balance = 0;
		// convert value to float
		try {
                    amount = Float.parseFloat(value);
                    balance = Float.parseFloat(all_accounts.get(pos).acc_balance);
		} catch (Exception e) {
                    System.out.println("ERROR: Invalid amount format");
                    return false;
		}
		
		// minus the amount and transaction fee
		float new_balance = balance - amount;
		
		// if the new balance is less than 0
		if (new_balance < 0) {
			System.out.println("ERROR: Below 0.");
			return false;
		} else {
			// convert back the new balance to string and save it the account
			all_accounts.get(pos).acc_balance = String.format("%.2f", new_balance);
		}

		return true;
	}

	// add the amount from a specfic account position
	// return true if succesfully add, else return false
	boolean add(int pos, String value) {
		
		// check if the pos is valid
                if (pos < 0 || pos > all_accounts.size()) {
                    // if the account doesn't exist
                    System.out.println("ERROR: Account doesn't exist.");
                    return false;
                }
		
                float amount = 0;
                float balance = 0;
		// convert value to float
		try {
                    amount = Float.parseFloat(value);
                    balance = Float.parseFloat(all_accounts.get(pos).acc_balance);
		} catch (Exception e) {
                    System.out.println("ERROR: Invalid amount format");
                    return false;
		}
		
		// add the amount and minus the transaction fee
		float new_balance = balance + amount;
		// if the new balance is greater than 99999
		if (new_balance > 99999) {
			System.out.println("ERROR: Over 99999.");
			return false;
		}
		// if the new balance is less than 0
		else if (new_balance < 0) {
			System.out.println("ERROR: Below 0.");
			return false;
		} else {
			// convert back the new balance to string and save it the account
			all_accounts.get(pos).acc_balance = String.format("%.2f", new_balance);
		}
		return true;
	}

	
	// login
	public void login(trans current_trans) {
		// search the position that matches the account name and number
		int pos = searchName(current_trans.acc_holder);

		// set the login mode
		if (pos != -1) {
			// set the login mode to A if log in as admin. (default as standard)
			if (current_trans.mis_info.charAt(0) == 'A') {
				curr_login_mode = 'A';
			} 
		}

	}

	// withdrawal
 	public void withdrawal(trans current_trans) {
		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);

		// reduce the amount from that account
		if (pos != -1) {
			minus(pos, current_trans.amount);
			// increase the number of transaction if in standard mode
			if (curr_login_mode == 'S') {
				all_accounts.get(pos).num_trans++;
			}

		}

	}

	// transfer
	public void transfer(trans current_trans) {
		// withdrawal money from the current index account
		withdrawal(current_trans);
		// increase the trans_index by 1
		trans_index++;
		// depost money to the current index account
		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);

		// reduce the amount from that account
		if (pos != -1) {
			add(pos, current_trans.amount);
		}
		// if the account doesn't exist
		// deposit the amount back
		else {
			int pos2 = searchNameAcc(all_trans.get(trans_index - 1).acc_holder, all_trans.get(trans_index - 1).acc_num);
			// used - the transaction fee to add back the transaction fee
			add(pos2, current_trans.amount);
		}
	}

	// paybill
	public void paybill(trans current_trans) {
		// withdraw money from the current index account
		withdrawal(current_trans);
	}

	// deposit
	public void deposit(trans current_trans) {
		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);

		// reduce the amount from that account
		if (pos != -1) {
			add(pos, current_trans.amount);
			// increase the number of transaction if in standard mode
			if (curr_login_mode == 'S') {
				all_accounts.get(pos).num_trans++;
			}

		}
	}

	// create
	public void create(trans current_trans) {

		account acc = new account();
		acc.acc_holder = current_trans.acc_holder;
		acc.acc_num = current_trans.acc_num;
		acc.acc_balance = current_trans.amount;
		acc.acc_type = current_trans.mis_info.charAt(0);
		acc.acc_status = 'A';
		acc.num_trans = 0;

		all_accounts.add(acc);

	}

	// delete
	public void delete(trans current_trans) {

		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);
		
		// remove the account from the all accounts
		if (pos != -1) {
			all_accounts.remove(pos);
		}
	}

	// enable
	public void enable(trans current_trans) {
		
		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);
		
		// change the account status to active
		if (pos != -1) {
			all_accounts.get(pos).acc_status = 'A';
		}
		
	}

	// Disable
	public void disable(trans current_trans) {
		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);
		
		// change the account status to disable
		if (pos != -1) {
			all_accounts.get(pos).acc_status = 'D';
		}
	}

	// changeplan
	public void changeplan(trans current_trans) {
		// search the position that match the account name and account number
		int pos = searchNameAcc(current_trans.acc_holder, current_trans.acc_num);

		// change the plan
		if (pos != -1) {
			if (all_accounts.get(pos).acc_type == 'N') {
				all_accounts.get(pos).acc_type = 'S';
			}
			else if (all_accounts.get(pos).acc_type == 'S') {
				all_accounts.get(pos).acc_type = 'N';
			}
		}
		
	}

	// logout
	public void logout(trans current_trans) {
		// set the current login mode to standard as default
		curr_login_mode = 'S';
	}
	
	// minus the transaction fee
	float getTransactionFee(int pos) {
	
            // check if the pos is valid
            if (pos < 0 || pos > all_accounts.size()) {
                // if the account doesn't exist
                System.out.println("ERROR: Account doesn't exist.");
                return 0.0f;
            }
            
            if (all_accounts.get(pos).acc_type == 'S') {
                    return 0.05f;
            } else if (all_accounts.get(pos).acc_type == 'N') {
                    return 0.10f;
            }
            return 0.0f;
    }

}
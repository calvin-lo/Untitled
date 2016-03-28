
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
	// store the merged transaction file
	String merged_path;

	public Transactions(String transDir, String mergedPath) {
		// set the default login mode as standard
		curr_login_mode = 'S';
		all_accounts = new ArrayList<account>();
		all_trans = new ArrayList<trans>();
		FR = new FileReader(transDir, mergedPath);
		merged_path = mergedPath;
		parseMaster();
		parseMerged();

		// init trans_index to zero;
		trans_index = 0;

		// loop all transaction and execute corresponding commands
		while (trans_index < all_trans.size()) {
			execute(all_trans.get(trans_index).code);

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

	// read Master bank account file
	public void parseMaster() {
		// get the file from the file reader
		List<String> masterFile = new ArrayList<String>();
		masterFile = FR.readFile("MasterAccounts.txt");
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
			all_accounts.add(temp_account);
		}
	}

	// read the merged Transaction file
	public void parseMerged() {

		// get the file from the file reader
		List<String> transFile = new ArrayList<String>();
		transFile = FR.readFile(merged_path);
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
			all_trans.add(temp_trans);

		}

	}

	// login
	public void login() {
		// search the position that matches the account name and number
		int pos = searchName(all_trans.get(trans_index).acc_holder);

		// set the login mode
		if (pos != -1) {
			// set the login mode to A if log in as admin. (default as standard)
			if (all_trans.get(trans_index).mis_info.charAt(0) == 'A') {
				curr_login_mode = 'A';
			} 
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}
	

	}

	// withdrawal
 	public void withdrawal() {
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);

		// reduce the amount from that account
		if (pos != -1) {
			minus(pos, all_trans.get(trans_index).amount);
			// increase the number of transaction if in standard mode
			if (curr_login_mode == 'S') {
				all_accounts.get(pos).num_trans++;
			}

		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}

	}

	// transfer
	public void transfer() {
		// withdrawal money from the current index account
		withdrawal();
		// increase the trans_index by 1
		trans_index++;
		// depost money to the current index account
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);

		// reduce the amount from that account
		if (pos != -1) {
			add(pos, all_trans.get(trans_index).amount);
		}
		// if the account doesn't exist
		// deposit the amount back
		else {
			System.out.println("ERROR: Account doesn't exist.");
			int pos2 = searchNameAcc(all_trans.get(trans_index - 1).acc_holder, all_trans.get(trans_index - 1).acc_num);

			// used - the transaction fee to add back the transaction fee
			add(pos2, all_trans.get(trans_index).amount);

		}
	}

	// paybill
	public void paybill() {
		// withdraw money from the current index account
		withdrawal();
		
		// increase the trans_index by 1
		/*trans_index++;
		// deposit money to the current index account
		// search position that matches account name and number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);

		// reduce amount from account
		if (pos != -1) {
			add(pos, all_trans.get(trans_index).amount, 0);
		}
		// if the account doesn't exist, despoit amount back
		else {
			System.out.println("ERROR: Account doesn't exist.");
			int pos2 = searchNameAcc(all_trans.get(trans_index - 1).acc_holder, all_trans.get(trans_index - 1).acc_num);

			// used - the transaction fee to add back the transaction fee
			add(pos2, all_trans.get(trans_index).amount, -all_accounts.get(pos2).acc_type);

		}*/

	}

	// deposit
	public void deposit() {
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);

		// reduce the amount from that account
		if (pos != -1) {
			add(pos, all_trans.get(trans_index).amount);
			// increase the number of transaction if in standard mode
			if (curr_login_mode == 'S') {
				all_accounts.get(pos).num_trans++;
			}

		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}

	}

	// create
	public void create() {

		account acc = new account();
		acc.acc_holder = all_trans.get(trans_index).acc_holder;
		acc.acc_num = all_trans.get(trans_index).acc_num;
		acc.acc_balance = all_trans.get(trans_index).amount;
		acc.acc_type = all_trans.get(trans_index).mis_info.charAt(0);
		acc.acc_status = 'A';
		acc.num_trans = 0;

		all_accounts.add(acc);
		/*
		// increase trans_index by 1
		trans_index++;
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_accounts.get(trans_index).acc_holder, all_accounts.get(trans_index).acc_num);

		if (pos != -1) {
			add(pos, all_trans.get(trans_index).amount, getTransactionFee(pos));
			all_accounts.get(pos).num_trans++;
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}*/


	}

	// delete
	public void delete() {

		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);
		
		// remove the account from the all accounts
		if (pos != -1) {
			all_accounts.remove(pos);
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}

		/*
		// withdraw to close account with $0 remaining funds
		withdrawal();
		// increase trans_index by 1
		trans_index++;
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);

		if (pos != -1) {
			add(pos, all_trans.get(trans_index).amount, getTransactionFee(pos));
			all_accounts.get(pos).num_trans--;
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}*/
	}

	// enable
	public void enable() {
		
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);
		
		// change the account status to active
		if (pos != -1) {
			all_accounts.get(pos).acc_status = 'A';
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}
		
	}

	// Disable
	public void disable() {
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);
		
		// change the account status to disable
		if (pos != -1) {
			all_accounts.get(pos).acc_status = 'D';
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}
	}

	// changeplan
	public void changeplan() {
		// search the position that match the account name and account number
		int pos = searchNameAcc(all_trans.get(trans_index).acc_holder, all_trans.get(trans_index).acc_num);

		// change the plan
		if (pos != -1) {
			if (all_accounts.get(pos).acc_type == 'N') {
				all_accounts.get(pos).acc_type = 'S';
			}
			else if (all_accounts.get(pos).acc_type == 'S') {
				all_accounts.get(pos).acc_type = 'N';
			}
		}
		// if the account doesn't exist
		else {
			System.out.println("ERROR: Account doesn't exist.");
		}
		
	}

	// logout
	public void logout() {
		// set the current login mode to standard as default
		curr_login_mode = 'S';
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

	// minus the amount from a specfic account position
	// return true if succesfully minus, else return false
	boolean minus(int pos, String value) {
		// convert value to float
		float amount = Float.parseFloat(value);
		float balance = Float.parseFloat(all_accounts.get(pos).acc_balance);
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
		// convert value to float
		float amount = Float.parseFloat(value);
		float balance = Float.parseFloat(all_accounts.get(pos).acc_balance);
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

	// minus the transaction fee
	float getTransactionFee(int pos) {
		if (all_accounts.get(pos).acc_type == 'S') {
			return 0.05f;
		} else if (all_accounts.get(pos).acc_type == 'N') {
			return 0.10f;
		}
		return 0.0f;
	}

}
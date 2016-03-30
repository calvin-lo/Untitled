//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: Test the back end with Junit

import static org.junit.Assert.*;
import junit.framework.JUnit4TestAdapter;
import org.junit.Test;
import java.util.*;

public class TransactionTest {

    // Test Transaction class: create a new Transactions class
    @Test
    public void testCreateTransaction() {
        Transactions T = new Transactions();
    }
    
    // Test account class: create a new account class
    @Test
    public void testCreateAccountCreate() {
        account acc = new account();
    }

    // Test trans: create a new trans class
    @Test
    public void testCreateTransCreate() {
        trans t = new trans();
    }
    
    // Test Transaction class with merged path
    @Test
    public void testCreateTransaction2() {
        Transactions T = new Transactions("merged.trans");
    }
    // Test execute login
    @Test 
    public void testExecuteLogin() {
        Transactions T = new Transactions();
        
        // set up test data
        trans t = new trans();
        t.code = "10";
        t.mis_info = "A";
        
        assertEquals(true, T.execute(t.code, t));
    }
    
    // Test execute login
    @Test 
    public void testExecuteWithdrawal() {
        Transactions T = new Transactions();
    
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
    
        // set up test data
        trans t = new trans();
        t.code = "01";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "100.00";
        
        assertEquals(true, T.execute(t.code, t));
    }
    
    // Test execute transfer
    @Test 
    public void testExecuteTransfer() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t1 = new trans();
        t1.code = "02";
        t1.acc_holder = "John Doe";
        t1.acc_num = "00001";
        t1.amount = "100.00";
        
        trans t2 = new trans();
        t2.code = "02";
        t2.acc_holder = "Tom Doe";
        t2.acc_num = "44444";
        t2.amount = "100.00";
        
        T.all_trans.add(t1);
        T.all_trans.add(t2);
        
        assertEquals(true, T.execute(t1.code, t1));
    }
    
    // Test execute paybill
    @Test 
    public void testExecutePaybill() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "03";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "100.00";
        t.mis_info = "EC";
        
        assertEquals(true, T.execute(t.code, t));
        
    }
    
    // Test execute deposit
    @Test 
    public void testExecuteDeosit() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "04";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "100.00";
        
        assertEquals(true, T.execute(t.code, t));
        
        
    }
    
    // Test execute create
    @Test 
    public void testExecuteCreate() {
        Transactions T = new Transactions();
        
        // set up test data
        trans t = new trans();

        t.code = "05";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "0";
        t.mis_info = "N";
        
        assertEquals(true, T.execute(t.code, t));
        
        
    }
    
    // Test execute delete
    @Test 
    public void testExecuteDelete() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        
        // set up test data
        trans t = new trans();

        t.code = "06";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        
        assertEquals(true, T.execute(t.code, t));
    }
    
    // Test execute disable
    @Test
    public void testExecuteDisable() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "07";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        
        assertEquals(true, T.execute(t.code, t));
        
    }
    
    // Test execute changeplan
    @Test 
    public void testExecuteChangeplan() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "08";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        
        assertEquals(true, T.execute(t.code, t));
    }
    
    // Test execute enable
    @Test 
    public void testExecuteEnable() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "09";
        t.acc_holder = "John Doe";
        t.acc_num = "88888";
        
        assertEquals(true, T.execute(t.code, t));
    }

    // Test execute logout
    @Test 
    public void testExecuteLogout() {
        Transactions T = new Transactions();
        
        // set up test data
        trans t = new trans();
        t.code = "00";
        
        assertEquals(true, T.execute(t.code, t));
    }
    // Test execute invalid transaction() 
    @Test
    public void testExecuteInvalid() {
        Transactions T = new Transactions();
        
        // set up test data
        trans t = new trans();
        t.code = "99";
        
        assertEquals(false, T.execute(t.code,t));
    }
    
    // Test parseMaster: with existing file
    @Test
    public void testParseMaster1() {
        Transactions T = new Transactions();


        assertEquals(true, T.parseMaster("MasterAccounts.txt"));
    }
    
    // Test parseMerged: with existing file
    @Test
    public void testParseMerged1() {
        Transactions T = new Transactions();
        
        assertEquals(true, T.parseMaster("merged.trans"));
    }
    
    // Test createNewCurrent: with a testing accounts list
    @Test
    public void testCreateNewCurrent() {
        Transactions T = new Transactions();
        
        // set test data
        List<account> testAccounts = new ArrayList<account>();
        
        T.createNewCurrent(testAccounts);
    }
    
    // Test createNewMaster: with a testing accounts list
    @Test
    public void testCreateNewMaster() {
        Transactions T = new Transactions();
        
        // set test data
        List<account> testAccounts = new ArrayList<account>();
        
        T.createNewMaster(testAccounts);
    }
    
    // loop coverage
    // Test searchName: when account list have many accounts (
    @Test
    public void testSearchName1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        String name = "John Doe";
        assertEquals(0, T.searchName(name));
    }
    
    // loop coverage
    // Test searchName: when account list is empty (condition 0)
    @Test
    public void testSearchName2() {
        Transactions T = new Transactions();
        
        // set up the test data
        String name = "John Doe";
        assertEquals(-1, T.searchName(name));
    }
    
    // loop coverage
    // Test searchName: when account list have only one accounts (condition 1)
    @Test
    public void testSearchName3() {
        Transactions T = new Transactions();
        
        // set up the test data
        account acc = new account();
        acc.acc_holder = "TEST1";
        T.all_accounts.add(acc);
        String name = "TEST1";
        assertEquals(0, T.searchName(name));
    }
    
    // loop coverage
    // Test searchName: when account list have only two accounts (condition 2)
    @Test
    public void testSearchName4() {
        Transactions T = new Transactions();
        
        // set up the test data
        account acc1 = new account();
        acc1.acc_holder = "TEST1";
        account acc2 = new account();
        acc2.acc_holder = "TEST2";
        T.all_accounts.add(acc1);
        T.all_accounts.add(acc2);
        String name = "TEST1";
        
        assertEquals(0, T.searchName(name));
    }
    
    // Test searchNameAcc: Search both name and account number that exist in the test data
    @Test
    public void testSearchNameAcc1() {
        Transactions T = new Transactions(); 
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        String name = "John Doe";
        String number = "00001";

        assertEquals(0, T.searchNameAcc(name, number));
        
    }
    
    // Test searchNameAcc: Search a both name and account number that doesn’t exist in the test data
    @Test
    public void testSearchNameAcc2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        String name = "NOT EXIST";
        String number = "NOT EXIST";

        assertEquals(-1, T.searchNameAcc(name, number));
    }
    
    
    // Test minus: when input a correct position and an amount greater the the relative account’s balance
    @Test
    public void testMinus1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        int pos = 4;
        String value = "100.00";
        
        assertEquals(true, T.minus(pos, value));
        
    }
    
    // Test minus: when input value is greater than the account balance
    @Test
    public void testMinus2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        int pos = 4;
        String value = "500.00";
        
        assertEquals(false, T.minus(pos, value));
        
    }
    
    // Test add: when input a correct position and an amount greater the the relative account’s balance
    @Test
    public void testAdd1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        int pos = 4;
        String value = "100.00";
        
        assertEquals(true, T.add(pos, value));
    }
    
    // Test add: when input value is greater than 99999
    @Test
    public void testAdd2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        int pos = 1;
        String value = "100000";
        
        assertEquals(false, T.add(pos, value));
        
    }
     
    // Test login: when input a admin login transaction 
    @Test
    public void testLogin1() {
        Transactions T = new Transactions();
        
        // set up test data
        trans t = new trans();
        t.code = "10";
        t.mis_info = "A";
        
        assertEquals(true, T.login(t));
    }
    
    // Test withdrawal: input a valid account (decision coverage)
    @Test
    public void testWithdrawal1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "01";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "100.00";
        
        assertEquals(true, T.withdrawal(t));

    }
    
    // Test withdrawal: input a invalid account
    @Test
    public void testWithdrawal2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "01";
        t.acc_holder = "INVALID";
        t.acc_num = "INVALID";
        t.amount = "100.00";
        
        assertEquals(false, T.withdrawal(t));

    }
    
    // Decision coverage: TRUE
    // Test transfer: input a valid account name 
    @Test
    public void testTransfer1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t1 = new trans();
        t1.code = "02";
        t1.acc_holder = "John Doe";
        t1.acc_num = "00001";
        t1.amount = "100.00";
        
        trans t2 = new trans();
        t2.code = "02";
        t2.acc_holder = "Tom Doe";
        t2.acc_num = "44444";
        t2.amount = "100.00";
        
        assertEquals(true, T.transfer(t1, t2));
        
    }
    
    // Decision coverage: TRUE
    // Test transfer: input an invalid account name for destination
    @Test
    public void testTransfer2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t1 = new trans();
        t1.code = "02";
        t1.acc_holder = "John Doe";
        t1.acc_num = "00001";
        t1.amount = "100.00";
        
        trans t2 = new trans();
        t2.code = "02";
        t2.acc_holder = "INVALID";
        t2.acc_num = "INVALID";
        t2.amount = "100.00";
        
        assertEquals(false, T.transfer(t1, t2));
        
    }
    
    
    // Test paybill: call the withdrawal method
    @Test
    public void testPaybill1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "03";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "100.00";
        t.mis_info = "EC";
        
        assertEquals(true, T.paybill(t));
    }
    
    
    // Test deposit: Input a valid account
    @Test 
    public void testDeposit1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "04";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "100.00";
        
        assertEquals(true, T.deposit(t));
    }
    
    // Test create

    @Test
    public void testCreate1() {

        Transactions T = new Transactions();

        // set up test data
        trans t = new trans();

        t.code = "05";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        t.amount = "0";
        t.mis_info = "N";


        assertEquals(true, T.create(t));

    }

    // Test delete
    @Test
    public void testDelete1() {

        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "06";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";

        assertEquals(true, T.delete(t));

    }
    
    // Test enable
    @Test
    public void testEnable1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "09";
        t.acc_holder = "John Doe";
        t.acc_num = "88888";
        
        assertEquals(true, T.enable(t));
        
        
    }
    
    // Test disable
    @Test
    public void testDisable1() {
        Transactions T = new Transactions();

        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up test data
        trans t = new trans();
        t.code = "07";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";

        assertEquals(true, T.disable(t));

    }
    
    // Test changeplan: from a non student plan
    @Test
    public void testChangeplan1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        // set up test data
        trans t = new trans();
        t.code = "08";
        t.acc_holder = "Chris Doe";
        t.acc_num = "00002";
        
        assertEquals(true, T.changeplan(t));
        
    }
    
    // Test changeplan: from a student plan
    @Test
    public void testChangeplan2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        // set up test data
        trans t = new trans();
        t.code = "08";
        t.acc_holder = "John Doe";
        t.acc_num = "00001";
        
        assertEquals(true, T.changeplan(t));
        
    }
    
    // Test logout
    @Test
    public void testLogout1() {
        Transactions T = new Transactions();
        
        // set up test data
        trans t = new trans();
        t.code = "00";
        
        assertEquals(true, T.logout(t));
    }
    
    
    // Test getTransactionFee: when input a valid position with Student type
    @Test
    public void testGetTransactionFee1() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        int pos = 0;
        
        assertEquals(0.05, T.getTransactionFee(pos), 0.01);
        
    }
    
    // Test getTransactionFee: when input a valid position with Non student type
    @Test
    public void testGetTransactionFee2() {
        Transactions T = new Transactions();
        
        // parse the master bank accounts file and set the all_accounts variable
        T.parseMaster("MasterAccounts.txt");
        
        // set up the test data
        int pos = 2;
        
        assertEquals(0.10, T.getTransactionFee(pos), 0.01);
        
    }
    
    // Test getTransactionFee: when input an invalid type
    @Test
    public void testGetTransactionFee3() {
        Transactions T = new Transactions();
        
        
        // set up the test data
        account acc = new account();
        acc.acc_type = 'X';
        T.all_accounts.add(acc);
        int pos = 0;
        
        assertEquals(0.0, T.getTransactionFee(pos), 0.01);
        
    }
    
    
    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(TransactionTest.class);
    }
}
//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: Test the back end with Junit

import static org.junit.Assert.*;
import junit.framework.JUnit4TestAdapter;
import org.junit.Test;
import java.util.*;

public class TransactionTest {
    
    // Test create a new Transactions class
    @Test
    public void testEmptyConstructor() {
        Transactions T = new Transactions();
    }
    
    // create a account class
    @Test
    public void testAccountCreate() {
        account acc = new account();
    }

    // create a Transactions class
    @Test
    public void testTransCreate() {
        trans t = new trans();
    }
    
    // Test createNewCurrent with a testing accounts list
    @Test
    public void testCreateNewCurrent() {
        Transactions T = new Transactions();
        List<account> accounts = new ArrayList<account>();
        
        // create test accounts
        account acc = new account();
        acc.acc_holder = "Test";
        acc.acc_num = "00001";
        acc.acc_status = 'A';
        acc.acc_balance = "100.00";
        acc.acc_type = 'N';
        
        accounts.add(acc);
        
        T.createNewCurrent(accounts);
    }
    // Test createNewMaster with a testing accounts list
    @Test
    public void testCreateNewMaster() {
        Transactions T = new Transactions();
        List<account> accounts = new ArrayList<account>();
        
        // create test accounts
        account acc = new account();
        acc.acc_holder = "Test";
        acc.acc_num = "00001";
        acc.acc_status = 'A';
        acc.acc_balance = "100.00";
        acc.acc_type = 'N';
        acc.num_trans = 1;
        
        accounts.add(acc);
        
        T.createNewMaster(accounts);
        
        
    }
    
    // Test execute
    
    // Test parseMaster with existing file
    @Test
    public void testParseMaster1() {
        Transactions T = new Transactions();
        T.parseMaster("MasterAccounts.txt");
    }
    
    // Test parseMaster with not existing file
    @Test
    public void testParseMaster2() {
        Transactions T = new Transactions();
        T.parseMaster("NOT_EXIST_FILE");
    }
    
    // Test parseMerged with existing file
    @Test
    public void testParseMerged1() {
        Transactions T = new Transactions();
        T.parseMaster("merged.trans");
    }
    
    // Test parseMerged with not existing file
    @Test
    public void testParseMerged2() {
    
    // Test login 
    
    // Test withdrawal
    
    // Test transfer
    
    // Test paybill 
    
    // Test deposit
    
    // Test create
    
    // Test delete
    
    // Test enable
    
    // Test disable
    
    // Test changeplan
    
    // Test logout
    
    // Test searchName
    
    // Test searchNameAcc
    
    // Test minus
        Transactions T = new Transactions();
        T.parseMaster("NOT_EXIST_FILE");
    }
    
    // Test add
    
    // Test getTransactionFee
    
    
    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(TransactionTest.class);
    }
}
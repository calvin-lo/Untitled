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
        Transactions T = new Transactions();
        T.parseMerged("NOT_EXIST_FILE");
    }
    
    // create a testing account database and trans database
    List<account> testAccounts;
    List<trans> testTrans;
    
    public void createTestingData() {
        Transactions test = new Transactions();
        testAccounts = test.parseMaster("MasterAccounts.txt");
        testTrans = test.parseMerged("merged.trans");
    }
    
    // Test createNewCurrent with a testing accounts list
    @Test
    public void testCreateNewCurrent() {
        Transactions T = new Transactions();
        createTestingData();
        T.createNewCurrent(testAccounts);
    }
    
    // Test createNewMaster with a testing accounts list
    @Test
    public void testCreateNewMaster() {
        Transactions T = new Transactions();
        createTestingData();
        T.createNewMaster(testAccounts);
        
        
    }
    
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
    
    // Test add
    
    // Test getTransactionFee
    
    
    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(TransactionTest.class);
    }
}
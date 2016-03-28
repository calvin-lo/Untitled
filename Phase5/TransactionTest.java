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
    
    // Test execute
    
    // Test parseMaster: with existing file
    @Test
    public void testParseMaster1() {
        Transactions T = new Transactions();
        T.parseMaster("MasterAccounts.txt");
    }
    
    // Test parseMaster: with a not existing file
    @Test
    public void testParseMaster2() {
        Transactions T = new Transactions();
        T.parseMaster("NOT_EXIST_FILE");
    }
    
    // Test parseMerged: with existing file
    @Test
    public void testParseMerged1() {
        Transactions T = new Transactions();
        T.parseMaster("merged.trans");
    }
    
    // Test parseMerged: with a not existing file
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
    
    // Test createNewCurrent: with a testing accounts list
    @Test
    public void testCreateNewCurrent() {
        Transactions T = new Transactions();
        createTestingData();
        T.createNewCurrent(testAccounts);
    }
    
    // Test createNewMaster: with a testing accounts list
    @Test
    public void testCreateNewMaster() {
        Transactions T = new Transactions();
        createTestingData();
        T.createNewMaster(testAccounts);
    }
    
    // Test searchName: Search a name that exist in the test data
    @Test
    public void testSearchName1() {
        Transactions T = new Transactions();
        String name = "John Doe";
        T.searchName(name);
    }
    
    // Test searchName: Search a name that does not exist in the test data
    @Test
    public void testSearchName2() {
        Transactions T = new Transactions();
        String name = "NOT EXIST";
        T.searchName(name);
    }
    
    // Test searchNameAcc:
    @Test
    public void testSearchNameAcc1() {
        Transactions T = new Transactions(); 
        String name = "John Doe";
        String number = "00001";
        T.searchNameAcc(name, number);
        
    }
    
    // Test searchNameAcc:
    @Test
    public void testSearchNameAcc2() {
        Transactions T = new Transactions();  
        String name = "NOT EXIST";
        String number = "NOT EXIST";
        T.searchNameAcc(name, number);
    }
    
    // Test searchNameAcc:
    @Test
    public void testSearchNameAcc3() {
        Transactions T = new Transactions();    
        String name = "NOT EXIST";
        String number = "00001";
        T.searchNameAcc(name, number);
    }
    
    // Test searchNameAcc:
    @Test
    public void testSearchNameAcc4() {
        Transactions T = new Transactions();    
        String name = "John Doe";
        String number = "NOT EXIST";
        T.searchNameAcc(name, number);
    }
    
    // Test minus
    
    // Test add
    
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
    
    
    // Test getTransactionFee
    
    
    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(TransactionTest.class);
    }
}
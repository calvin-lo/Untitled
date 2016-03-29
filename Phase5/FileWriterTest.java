//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: Test the FileWriter class with JUNIT

import static org.junit.Assert.*;
import junit.framework.JUnit4TestAdapter;
import org.junit.Test;
import java.util.*;

public class FileWriterTest {
    
    // Test FileWriter class: create a new FileWriter class
    @Test
    public void testFileWriter() {
    	FileWriter FW = new FileWriter("Test");
        FW.close();
    }

    // Test writeTransaction method: with string "moo"
    @Test
    public void testWriteTransaction() {
    	FileWriter FW = new FileWriter("TestWriteTransaction");
    	
    	// set up the test data
    	List<String> test = new ArrayList<String>();
    	test.add("moo");
    	FW.writeTransaction(test);
        FW.close();
    }

    // Test writeCurrent method: with account class and List of account type
    @Test
    public void testWriteCurrent() {
    	FileWriter FW = new FileWriter("TestWriteCurrent");
    	account temp = new account();
    	// set up the test data
    	List<account> test = new ArrayList<account>();
        temp.acc_holder = "Jerry Doe Current";
        temp.acc_num = "12345";
        temp.acc_status = 'A';
        temp.acc_balance = "123.33";
        temp.acc_type = 'S';
        temp.num_trans = 1;

        test.add(temp);
        FW.writeCurrent(test);
        FW.close();
    }

    // Test writeMaster method: with account class and List of account type
    @Test
    public void testWriteMaster() {
   		FileWriter FW = new FileWriter("TestWriteMaster");
        
        // set up the test data
    	account temp = new account();
        List<account> test = new ArrayList<account>();
        temp.acc_holder = "Jerry Doe Master";
        temp.acc_num = "12346";
        temp.acc_status = 'A';
        temp.acc_balance = "1123.33";
        temp.acc_type = 'N';
        temp.num_trans = 1;

        test.add(temp);
        FW.writeMaster(test);
        FW.close();
        FW.close();
    }


    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(FileWriterTest.class);
    }
}
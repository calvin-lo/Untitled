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
    }

    // Test writeTransaction method: 
    @Test
    public void testWriteTransaction() {
    	FileWriter FW = new FileWriter("Test");
    	
    	// set up the test data
    	List<String> transactions = new ArrayList<String>();
    	transactions.add("moo");
    	FW.writeTransaction(transactions);
    }

    // Test writeCurrent method: 
    @Test
    public void testWriteCurrent() {
    	FileWriter FW = new FileWriter("Test");
    	
    	// set up the test data
    	//FW.writeCurrent();
    }

    // Test writeMaster method: 
    @Test
    public void testWriteMaster() {
   		FileWriter FW = new FileWriter("Test");

    	// set up the test data
    	//FW.writeMaster();
    }

     // Test close method: 
    @Test
    public void testClose() {
    	FileWriter FW = new FileWriter("Test");

    	// set up the test data
    	FW.close();
    }

    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(TransactionTest.class);
    }
}
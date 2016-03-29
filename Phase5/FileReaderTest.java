//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: Test the FileReader class with JUNIT

import static org.junit.Assert.*;
import junit.framework.JUnit4TestAdapter;
import org.junit.Test;
import java.util.*;
import java.io.*;

public class FileReaderTest {
    // Test FileReader class: create a new FileReader class
    @Test
    public void testFileReader() {
    	FileReader FR = new FileReader();
    }

    // Test readFile method: with file name BankAccounts.txt
    @Test
    public void testReadFile() {
    	FileReader FR = new FileReader();
    	FR.readFile("BankAccounts.txt");
    }

    // Test match method: 
    @Test
    public void testMatch() {
    	FileReader FR = new FileReader();
    	File[] idk = FR.match("Login", "Login");
    }

    // Test mergeTrans method: 
    @Test
    public void testMergeTrans() {
    	FileReader FR = new FileReader();
    	FR.filePath = "hi";
    	FR.mergeTrans();
    }

    // Test get method:
    @Test
    public void testGet() {
    	FileReader FR = new FileReader();
    	List<String> test = FR.get();
    }

     // Test readTransactions method: 
    @Test
    public void testReadTransactions() {
    	FileReader FR = new FileReader();
    	List<String> test = new ArrayList<String>();
    	test.add("randomrandomradnom");
    	FR.readTransactions(test);
    }

    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(FileReaderTest.class);
    }
}
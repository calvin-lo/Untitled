//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: Test the back end with Junit
//	Input files: Transaction files, old master bank accounts file
//	Output files: Merged transaction files, new current bank accounts file, new master bank accounts file

import static org.junit.Assert.*;
import junit.framework.JUnit4TestAdapter;
import org.junit.Test;
public class TransactionTest {
    
    @Test
    public void mytest() {
        Transactions T = new Transactions(".", "merged.trans");
    }
    
    // Test parseMaster
    @Test
    public void testParseMaster() {
        Transactions T = new Transactions(".", "merged.trans");
        T.parseMaster();
    }

    public static junit.framework.Test suite() {
        return new JUnit4TestAdapter(TransactionTest.class);
    }
}
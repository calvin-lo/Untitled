//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: reads in files for the back end and merges the Bank Account Transaction Files
import java.util.*;
import java.io.*;

public class FileReader { 
	List<String> transFiles = new ArrayList<String>();
	String filePath, mergedPath;

	public FileReader(String path, String merge) { 
		filePath = path;
		mergedPath = merge;
	}
}
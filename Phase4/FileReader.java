
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

	// read file
	public List<String> readFile(String filename) {
		List<String> results = new ArrayList<String>();
		try {
			BufferedReader br = new BufferedReader(new java.io.FileReader(filename));
			String s;
			while ((s = br.readLine()) != null) {
				results.add(s);
			}
		} catch (IOException e) {
			System.out.println("ERROR: Input/Output error");
		}

		return results;
	}

	public File[] match(String filePath, String toFind) {
		FilenameFilter textFilter = new FilenameFilter() {
			public boolean accept(File dir, String name) {
				String lowercaseName = name.toLowerCase();

				if (lowercaseName.contains(toFind)) {
					return true;
				} else {
					return false;
				}

			}
		};

		File f = new File(filePath);
		File[] files = f.listFiles(textFilter);
		return files;
	}

	public void mergeTrans() {

		String search[] = { "login", "withdrawal", "transfer", "paybill", "deposit", "create", "delete", "disable",
				"enable", "changeplan" };

		for (int i = 0; i < search.length; i++) {

			File[] files = match(filePath, search[i]);

			String path = files[0].toString();
			File[] transFiles = match(path, ".trans");
			// Arrays.sort(transFiles);

			for (int j = 0; j < transFiles.length; j++) {
				// System.out.println(transFiles[j]);
				this.transFiles.add(transFiles[j].toString());

			}

		}
		display(this.transFiles);
		// for each pathname in pathname array

	}

	public void display(List<String> idk) {
		for (int i = 0; i < idk.size(); i++) {
			System.out.println(idk.get(i));
		}
	}

}
//	CSCI 3060/ SOFE 3980 Course Project back end
//	Group: Untitled
//	Member: Calvin Lo, Albert Fung, Karan Chandwaney
//	Purpose: 
//	Input files: 
//	Output files: 
// 	How this is intended to run: 

public class Main { 

	public static void main (String args[]) { 
		String mergedPath = "";
		String transDir = "";
		
		mergedPath = "/home/admin/Code/Untitled/Phase4/";
		transDir = "/home/admin/Code/Untitled/Phase3/";

		FileReader fr = new FileReader(transDir, mergedPath);
		fr.mergeTrans();
		/*
		try { 
		
			//mergedPath = args[0];
			//transDir = args[1];
			
		} catch (Exception e) { 
			System.out.println("No arguments specified!");
		}

		*/
				
		Transactions T = new Transactions(transDir, mergedPath);
	
	}
}

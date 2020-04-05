import java.util.Scanner;

public class Sol {

    public static void main(String args[]){
	   
	   Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		
		// number of test cases loop
		
		for(int x = 0; x<t ; x++){
			int n = scan.nextInt(); // input for the number of princesses
			int unmarriedPs = 0; //only need the first unmarried princess.
			
			int[] princes = new int[n]; //creates an array of length equal to the number of princes.
			for(int c = 0; c<0; c++){ // each prince is represented by the index in the array+1. 0 means he is unmarried. 1 means he is married.
				princes[c] = 0;
			}
			
			for(int y = 0; y<n; y++){//loops over each princess 
			
				int k = scan.nextInt();// each princess has k princes she wants to marry.
				int targets[] = new int[k];
				boolean married = false;
				
				for(int z = 0; z<k; z++){ // loop that builds an array of all the princes a princess likes.
				
					targets[z]= scan.nextInt() - 1;
				}
				for(int i = 0; i<k;i++){
					if(princes[targets[i]] == 0){
						princes[targets[i]] = 1;
						married = true;
						break;
					}
				}
				if(!married){
					unmarriedPs = y+1;
				}
			}
			boolean allMarried = true;
			for(int y = 0; y<n; y++){
				if(princes[y] == 0){
					allMarried = false;
					System.out.println("IMPROVE" + "\n" + unmarriedPs +" "+ (y+1));
					break;
				}
			}
			if(allMarried){
				System.out.println("OPTIMAL");
			}
		}
	}
}

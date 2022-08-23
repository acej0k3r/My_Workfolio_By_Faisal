import java.io.File;
import java.util.Scanner;

public class Scheduling {
node start = new node();

	Scheduling(){
		node x = new node();
		start = x;
		}
	
	int numNodes(String x) {
		int num = 0;
		try {
		Scanner inFile = new Scanner(new File(x));
		
		num = inFile.nextInt();
		
		inFile.close();
		
		}catch(Exception e){
			System.out.println(e);
		}
		
		return num;
	}
	
	int totalJobTimes(String x) {
		int num = 0;
		int count = 0;
		int total = 0;
		try {
		Scanner inFile = new Scanner(new File(x));
		
		num = inFile.nextInt();
		while(inFile.next() != null) {
			if(count % 2 == 0) {
				num = inFile.nextInt();
				
			}else {
				total += inFile.nextInt();
			}
			count++;
		}
		
		inFile.close();
		
		}catch(Exception e){
			System.out.println(e);
		}
	
		return total;
	}
	
	
	
}

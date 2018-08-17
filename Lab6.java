import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Lab6 implements lolli{
	
	
	public static void printd(double x){
		 System.out.println(x);
		
		
	}

	
	
	public static void main(String[] args) {
		String yo,kai,lol; 
		
		yo = "hola";
		kai = "sinarita";
		lol = "FK ME SILLLY AYYEE";
		yo = yo.replace('h','p');
		yo = yo.concat(" " + kai);
		System.out.println(yo);
		/*
		
		int holder = lol.compareTo(yo); 
		if(holder == 0){
			System.out.println("hi");
			
		}else if(holder == 1){
			System.out.println("SIKE");
			
		}else{
			System.out.println("-1");
			
		}
		
		JOptionPane hi = new JOptionPane();
		String lol2 = hi.showInputDialog("Hey whats up dog ");
		hi.showMessageDialog(null, lol2,"the name  is goofy",JOptionPane.YES_NO_CANCEL_OPTION);
		
		roll a = new roll();
		
					
		int [][] grades = new int [7][2];
		int l = grades.length;
		for( int i = 0; i < grades.length; i++ ){
			
			for(int nex = 0; nex < 2; nex++){
			grades[i][nex] = l; 
			printIn(l);
			prints(" "); 
			l--;
				}
			prints("\n");
		}
		
		
		
		*/
		
		Scanner sc = new Scanner(System.in);
		assFK("OOOOHH DADDYYY HARDER PLZ");
		try{
			int sc2 = sc.nextInt();
			System.out.println(4/sc2);
		}catch(Exception e){
			System.out.println("ERRROR CANNTO DEVIDE 0");
		}
		
		
		////////////////////////////////////////////////
		PrintWriter out = null;
		try{
			out = new PrintWriter("out.txt");
		}catch(FileNotFoundException e){
			System.out.println("ERROR WITH OPENNIG FIEL");
		}
		
		System.out.println("enter theree lines of textt: ");
		Scanner key = new Scanner(System.in);
		for (int c = 1; c <=3 ; c++){
			String r = key.nextLine();	
			out.write(r);
		}
			
			
			
		out.close();
		
		
		Scanner  in = null;
		try{
			in = new Scanner(new File ("out.txt"));
		}
		catch(FileNotFoundException e){
			System.out.println("ERROR CANNOT OPEN");
		}
		
		while(in.hasNextLine()){
			String leo = in.nextLine();
			System.out.println(leo);
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	public static class roll{
		private int num = 3, hei = 90; private double  k = 4.3;
		
		public roll(){
				int	numk = (int) Math.random(); 
				System.out.println(numk);
				
				
				printd(Math.ceil((double)k));
				
				
		}
	}
	
	public static void printIn(int x){
		System.out.print(x);
	}
	public static void prints(String x){
		System.out.print(x);
	}



	public static void assFK(String x) {
		// TODO Auto-generated method stub
		System.out.println(x);
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}


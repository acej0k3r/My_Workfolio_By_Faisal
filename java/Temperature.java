import java.util.Scanner;

public class Temperature {

	
	
	public static void main(String[] args) {
	Scanner key = new Scanner(System.in);
	prints("Please enter a temperature in fahrenheit");
	int temp = key.nextInt();
	printd(convertToCel(temp));
	
	
	
	
}

public static void prints(String x){
	System.out.println(x);
	
}
public static void printi(int x){
	System.out.println(x);
	
}

public static void printd(double x){
	System.out.println(x);
	
}
public static double convertToCel(int x){
	
	double p = ((x - 32) / 1.8);
	p = p*10;
	p = (int)p;
	p = p/10;
	
	return p;
}



}

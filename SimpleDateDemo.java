// MD A FAISAL
// mac 190.5431
// 5/27/17
public class SimpleDateDemo {
	
			
	public static void main(String[] args) {
		
		SimpleDate dat = new SimpleDate(); 
		printDate(dat);
		SimpleDate dat2 = new SimpleDate(5,11,2017); // uses second constructor with arguments 
		printDate(dat2);
		
		
		SimpleDate dat3  = new SimpleDate();
		dat3.setDate(1, 17, 1999);
		printDate(dat3);
		
		dat3.setMonth(4);	//individually sets each member variable
		dat3.setDay(11);
		dat3.setYear(2005);
		printDate(dat3);
		
		
		
		dat3.nextDay();	// calls the next day function from simpledate class
		printDate(dat3);
		
		String l = dat3.toString();
		System.out.println(l);
		
		boolean check = dat3.equals(dat2);
		System.out.println(check);
		
		
		
		//END MAIN
	}
	
	
	public static void printDate(SimpleDate x){
		
		System.out.println(x.getMonth() + "/ " + x.getDay() + "/ " + x.getYear());
		
	//END PRINTDATE
	}
	
	
	
	//END SIMPLEDATEDEMO
}

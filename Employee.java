//MD A FAISAL
//MAC 190 5431
//5/27/17
public class Employee extends Person{
	String emplName = getName();
	private double EmplSal;
	private int HireDate;
	private int ID;
	public Employee(){
		super();
		EmplSal = 0.0;
		HireDate = 0;
		ID = 0;
		
	}
	public Employee(String init, double x, int y, int p){
		super(init);
		EmplSal = x;
		HireDate = y;
		ID = p;
		
	}
	
	
	public void setID(int num){
		ID = num;
		
	}
	
	public void setEmplSal(double val){
		EmplSal = val;
	}
	
	public void setHireDate(int yr){
		HireDate = yr;
	}
	
	public double getEmplSal(){
		return EmplSal;
	}
	public int getHireDate(){
		return HireDate;
		
	}
	public int getID(){
		return ID;
	}
	public boolean isEqual(Employee r){
		return this.hasSameName(r) && (this.ID == r.ID);
		
		
	}
	
	public static void main(String[] args) {
		Employee num1 = new Employee();
		printDetails(num1);
		
		Employee sam = new Employee("sam", 30000.69, 2005, 000000001);
		printDetails (sam);
		
		boolean l = sam.isEqual(sam);
		System.out.println(l);
	
		Employee rem = new Employee();
		rem.emplName = "rem";
		rem.setEmplSal(2300.02);
		rem.setHireDate(2017);
		rem.setID(192342543);
		
		printDetails(rem);
		
	}
	
	
	
	public static void printDetails(Employee obj){
		System.out.println("name is " + obj.emplName + ", the id is " + obj.ID + "\nthe Employee salaray is "
	+ obj.EmplSal + "The employees hire date is " + obj.HireDate);
	}
	
	
	
}

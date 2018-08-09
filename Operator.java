
public class Operator {

	public static void main(String[] args) {
		
		Scheduling sc = new Scheduling();
		int num = sc.numNodes("DependencySchedule_Time_Data1.txt");
		int total = sc.totalJobTimes("DependencySchedule_Time_Data1.txt");
		System.out.println(num);
		System.out.println(total);
		
		
	}
	
}

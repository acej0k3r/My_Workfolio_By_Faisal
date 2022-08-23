import javax.swing.JOptionPane;
public class LAB4 {
public static void main(String[] args) {
	int i;
	String x[] = {"First Toss", "Second Toss", "Third Toss", "Forth Toss", "Fifth Toss", "Sixth Toss", "Seventh Toss", "Eighth Toss"};
	int head = 0, tail = 0;
	double percentH = 0 , percentL = 0;
	
	for (i = 0; i < 8 ; i++){
	String input = JOptionPane.showInputDialog(x[i] + ": "); 
		while(!input.contains("h") && !input.contains("H") && !input.contains("t") && !input.contains("T") || input.length() > 1){
			input = JOptionPane.showInputDialog("NOTE: ONLY ONE VALUE OF LETTER IS EXCEPTED WHICH IS H OR T, and they can be"
					+ " lower case or upper case \n" + x[i] + ": "); 
		}
		if(input.contains("h") || input.contains("H")){
			head++; 
		}
		else{
			tail++;
		}
		
	}
	percentH = ((double)head / 8) * 100; 
	percentL = ((double)tail / 8)* 100; 

	JOptionPane.showMessageDialog(null, "The number of head " + head+ "\n"
			+ "the number of tails " + tail + "\n"
			+ "the percent of heads " + percentH + "\n"
			+ "the percent of tails " + percentL + "\n"
			, "Result", JOptionPane.PLAIN_MESSAGE);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
}

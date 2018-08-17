
public class Assignment2 {
	
	public static void main(String[] args) {
		String line = new String();
		String por1 = new String();
		String por2 = new String();
		String por3 = new String();
		String por4 = new String();
		String por5 = new String();
		String temp = new String();
		
		DequeUsingStacks<String> deq = new DequeUsingStacks<>();
		deq.addFirst("New York City");
		deq.addLast("California");
		deq.addLast("Salt Lake City");
		
		NoteCode nc = new NoteCode();
		nc.openReadF("assignment2.txt");
		
		while((line = nc.readfile())!= null){
			String [] arr = line.split(" ");
			//stores all words up to 5 words into portion variables
			for(int i =0; i < arr.length; i++){
				switch(i){
				case 0:
					por1 = arr[i];
				break;
				case 1:
					por2 = arr[i];
				break;
				case 2: 
				    por3 = arr[i];
				case 3: 
				    por4 = arr[i];    
				 break;
				case 4:
					 por5 = arr[i];
				break;
				
				}
			}
			
			
			switch(por1){
			
			case "size":
				int size = deq.size();
				System.out.println("The Deque contains " + size + " strings");
			
				break;
			
			case "is_empty":
				if(deq.isEmpty()){
					System.out.println("The deque is empty");
				}else{
					System.out.println("The deque is not empty");
				}
				break;
				
		
			
			case "first":
				if(deq.first() == null){
					System.out.println("The deque was empty.");

				}else{
					temp = deq.first();
					System.out.println("The string at the front of the deque is \"" + temp + "\".");
				}
					
				break;
				
			case "last":
				if(deq.last() == null){
					System.out.println("The deque was empty.");
				}else{
					temp = deq.last();
					System.out.println("The string at the back of the deque is \"" + temp + "\".");
				}
				break;
			
			case "add_first":
				temp = por2 + " " + por3;
				deq.addFirst(temp);
				System.out.println("Added the string \"" + temp + "\"to the front of the deque.");
				
				break;
			
			case "add_last":
				temp = por2 + " " + por3;
				deq.addLast(temp);
				System.out.println("Added the string \"" + temp + "\"to the back of the deque.");

				break;
			case "remove_first":
				if(deq.removeFirst() == null){
					System.out.println("The deque was empty");
				}else{
					temp = deq.removeFirst();
					System.out.println("Removed the string \"" + temp + "\" from the front of the deque");

				}				
			    break;
			case "remove_last":
				if(deq.removeLast() == null){
					System.out.println("The deque was empty");

				}else{
					temp = deq.removeLast();
					System.out.println("Removed the string \"" + temp + "\" from the back of the deque");
				}
				
				break;
			default:
			    System.out.println("Nothing in file");
				break;
								
				
			}
			
			
		}
		
			
			

		
			
			
			
		}
		
		
		
		
	}


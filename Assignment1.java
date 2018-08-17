
public class Assignment1 {
	
	public static void main(String[] args) {
		String line = new String();
		String por1 = new String();
		String por2 = new String();
		String por3 = new String();
		String por4 = new String();
		String por5 = new String();
		String temp = new String();
		int number;
		
		CircularLinkedList<String> list = new CircularLinkedList<String>();
		list.add("1");
		list.add("California");
		list.add("Silicon Valley");
		list.add("Paris");
		list.add("New York City");
		list.add("Life on Mars");
		list.add("Zombo");
		
		
		Notecode nc = new Notecode();
		nc.openReadF("assignment1.txt");
		
		while((line = nc.readfile())!= null){
			String [] arr= line.split(" ");
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
			por3 += " " + por4 + " " + por5;
			
			switch(por1){
			case "clear":
				list.clear();
				System.out.println("The circular linked list is now empty.");
				break;
			
			case "size":
				int size = list.size();
				System.out.println("The circular linked list contains " + size + " strings");
			
				break;
			
			case "is_empty":
				if(list.isEmpty()){
					System.out.println("The circular linked list is empty");
				}else{
					System.out.println("The circular linked list is not empty");
				}
				break;
				
			case "get":
				if(list.isEmpty()){
				System.out.println("THE LIST IS EMPTY YOU CANT GET NOTHING CHANGE ORDER");	
				}else{
				number = Integer.parseInt(por2); //converts the second word into number
				 temp = list.get(number);//uses number as index to access value 
				System.out.println("The String at position " + number + " in "
						+ "the circular linked list is " + temp);
				}
				break;
			
			case "set":
				if(list.isEmpty()){
					System.out.println("THE LIST IS EMPTY YOU CANT SET NOTHING CHANGE ORDER");
				}else{	
				number = Integer.parseInt(por2);
				String removed = list.set(number, por3);
				System.out.println("The string" + por3 + " replaces the string "
						+ removed + " at position " + number);			
				}
				break;
			
			case "add":
				number = Integer.parseInt(por2);
				list.add(number,por3 + " " + por4);
				System.out.println("Added the string " + por3  + " at position "
						+ number + " in the circular linked list.");
				
				break;
			case "add_last":
				list.add(por3);
				System.out.println("Added the string " + por3 + " at the end in the circular linked list.");				
				break;
			
			case "remove":
				if(list.isEmpty()){
					System.out.println("THE LIST IS EMPTY YOU CANT REMOVE NOTHING CHANGE ORDER");
				}else{	
				number = Integer.parseInt(por2);
				String val = list.remove(number);
				System.out.println("Removed the string " + val + " at position "
						+ number + " from the circular linked list");
				}
				break;
			
			case "rotate":
				list.rotate();
				System.out.println("The value at the head of the circular linked list"
						+ " was rotated to the tail of the circular linked list.");
				break;
			case "print_list":
				if(list.isEmpty()){
					System.out.println("THE LIST IS EMPTY YOU CANT SET NOTHING CHANGE ORDER");
				}else{	
					System.out.print("The circular linked list contains: ");
				   for(int i = 0; i < list.size(); i++){
					   
					   System.out.println(list.get(i));
				   }
				   
				}
			    break;
			default:
			    System.out.println("Nothing in file");
				break;
								
				
			}
			
			
		}
		
			
			

		
			
			
			
		}
		
		
		
		
	}


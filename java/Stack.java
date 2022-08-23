

public class Stack {
public int top;
public int[] arr;
public int stackSize;

public Stack(int max){
	stackSize = max;
  arr = new int[max];
  top = -1;
  
}

public void push(int x){
	if(top + 1 < stackSize){
		top++;
		arr[top] = x;
		prints(x + " was pushed into the stack ");
	}else{
		prints("Sorry but the stack is full");
		
	}
	
	
	
}
public void pop(){
	if(!empty()){
   prints(arr[top] + " was popped ");
   top--;
	}
	else{
		prints(" Nothing in stack ");
	}
	
	
	
}

public void popAll(){
	if(!empty()){
		int r = top;
	
	 for(int i = r; i >= 0; i--){
		prints(arr[top] + " was popped ");
	
	 top--;
	 }
	 }
	
	
}

public boolean empty(){
	
	return (top == -1);
}



public void prints(String x){
	System.out.println(x);
}
public void prints(int x){
	System.out.println(x);
}
public void prints(double x){
	System.out.println(x);
}



//display stack
public void displayTheStack(){
      prints("the stack is as follows");
      if(!empty()){
    	  
      
      for(int i = top;i >= 0;i--){
    	  prints(arr[i]);
      }
      }else{
    	  prints("STaCk EmpTy " );
      }

}
public static void main(String[] args) {
	Stack pplAge = new Stack(10);
	pplAge.push(8);
	pplAge.push(10);
	pplAge.push(99);
	pplAge.push(93);
	pplAge.push(14);
	pplAge.push(26);
	pplAge.pop();
	pplAge.displayTheStack();
	
	pplAge.popAll();
	pplAge.displayTheStack();
	
	
	
	
}










}

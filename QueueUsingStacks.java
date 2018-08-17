
import java.util.Stack;

public class QueueUsingStacks<AnyType> implements Queue<AnyType>
{
  Stack<AnyType> back;
  Stack<AnyType> front;

  public QueueUsingStacks()
  {
    back = new Stack<>();
    front = new Stack<>();
  }

  public int size()
  {
	  	return back.size();
  }

  public boolean isEmpty()
  {
	  if (size() == 0){
		  return true;
	  }else{
		  return false;
	  }
  }

  public AnyType first()
  {	 
	  
	  if(isEmpty()){
	  return null;
  }else{
	  
	  popBackInStack2();
	  AnyType x = front.peek();
	  popFrontInStack1();  
	
	  return x;
	  
   }  
  }

  public void enqueue(AnyType newValue)
  {
	  if(isEmpty()){
		  back.push(newValue);
		  
	  }else if(back.size() != back.capacity()){
		  back.push(newValue);
		  
	  }else if(back.size() == back.capacity()){
		  System.out.println("cannot Enter a new Value the stack for queue is full");
	  }
  }

  public AnyType dequeue()
  {
	  popBackInStack2();
	  AnyType x = front.pop();
	  popFrontInStack1();
	 
	  
	  return x;
  }
  
  private void popBackInStack2(){
	  while(back.isEmpty() == false){
		  front.push(back.pop());
	  }
  }
  private void popFrontInStack1(){
	  while(front.isEmpty() == false){
		  back.push(front.pop());
	  }
  }
}
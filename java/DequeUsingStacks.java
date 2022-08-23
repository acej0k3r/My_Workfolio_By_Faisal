
import java.util.Stack;

import org.omg.CORBA.Any;

public class DequeUsingStacks<AnyType> implements Deque<AnyType>
{
  Stack<AnyType> back;
  Stack<AnyType> front;

  public DequeUsingStacks()
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
	  if(size() == 0){
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

  public AnyType last()
  {
	  if(size() == 0){
		  return null;
	  }else{
	  return back.peek();
	  }
  }

  public void addFirst(AnyType newValue)
  {
	  if(size() == 0){
		  back.push(newValue);
	  }else if(back.size() != back.capacity()){
		  popBackInStack2();
		  front.push(newValue);
		  popFrontInStack1();
		  	  
	  }else if(back.size() == back.capacity()){
		  System.out.println("Cannot add at the end of queue because stack is full");

	  }
  }

  public void addLast(AnyType newValue)
  {
	  if(size() == 0){
		  back.push(newValue);
	  }else if(back.size() != back.capacity()){
		  back.push(newValue);
	  }else if(back.size() == back.capacity()){
		  System.out.println("Cannot add at the end of queue because stack is full");
	  }
	  
  }

  public AnyType removeFirst()
  {	  if(isEmpty()){
	  System.out.println("Cannot remove anything due to stack being empty");
	  return null;
  }else{
	  popBackInStack2();
	  AnyType x = front.pop();
	  popFrontInStack1(); 
	  return x;
  }  
  }

  public AnyType removeLast()
  {   if(isEmpty()){
	 System.out.println("Cannot remove anything due to stack being empty"); 
	 return null;
  	}else{
	  
	 return back.pop();
  }
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
import java.util.Iterator;


public class CircularLinkedList<AnyType> implements List<AnyType>
{
  private static class Node<AnyType>
  {
    private AnyType data;
    private Node<AnyType> next;

    public Node(AnyType d, Node<AnyType> n)
    {
      setData(d);
      setNext(n);
      
    }

    public AnyType getData() { return data; }

    public void setData(AnyType d) { data = d; }

    public Node<AnyType> getNext() { return next; }

    public void setNext(Node<AnyType> n) { next = n; }
  }

  private int theSize;
  private int modCount;
  private Node<AnyType> tail;
  
  public CircularLinkedList()
  {   
	this.tail = null;
	this.theSize = 0; 
	this.modCount = 0; 
	
	  
	
   }
//////////////////////////////////////PRIVATE FUNCTIONS///////////////////////  
  ////////////////////////////////////////////////////////////////////PRIVATE FUNCTIONS//////////////
  private void addFirstWhenEmpty( AnyType t) {
	  tail = new Node<AnyType>(t, null);
	  tail.setNext(tail);
  }
  
  private void addfirst(AnyType t) {
	  if(size() == 1){
		addLast(t);
		  
	  }else{
	  Node<AnyType> head = tail.next;
	  Node<AnyType> temp =  new Node<AnyType>(t,null);
      tail.setNext(temp);
      temp.setNext(head);   
	  }
  
  }
  
  private void addAnyWhere(int index,AnyType t){
	  Node <AnyType> current = tail; 
	  for(int i = 0; i < index; i++){
		  current = current.getNext();
	  }
	  Node <AnyType> temp = current.next;
	  Node <AnyType> newAddedNode = new Node <AnyType> (t,temp);
	  current.setNext(newAddedNode);
	  
	  
  }
  
  
  
  private void addLast(AnyType t) {
	  if(size() == 1) {
		  Node<AnyType> temp = new Node<AnyType>(tail.getData(),null);	  
		  tail.setData(t);
		  temp.setNext(tail);
		  tail.setNext(temp);  
	  }else {
		 
		  Node<AnyType> temp = new Node<AnyType>(tail.getData(),null);
		  tail.setData(t);
		  temp.setNext(tail.next);
		  tail.setNext(temp);
		  
	  }
  }
  
  public void prints(String x){
	  System.out.println(x);
  }
  
  ///****////*****/////REMOVE METHODS/////*****///////*******//////REMOVE METHODS/////////////////////////////////////
  private void removeFirstWhenEmpty(){
	  prints("YOU CANNOT REMOVE FROM THE LIST BECAUSE THERE IS NOTHING TO REMOVE");
  }
  
  private Node <AnyType> removeFirst(){
	     Node <AnyType> temp = tail.next;
	     tail.setNext(temp.next);
		 theSize--;
		 modCount++;
		 return temp;
  }
  
  private Node <AnyType> removeAnywhere(int index){
	  Node <AnyType> previous = tail; 
	  Node <AnyType> current = tail.next;
	  for(int i = 0; i < index; i++){
		  previous = previous.getNext();
		  current = current.getNext();
	 }
	 
	   Node <AnyType>temp = current; 
	   previous.setNext(temp.next);  
	   theSize--;
	   modCount++;
	   return temp;
  }
  


  
 /*******************************************************************************/ 
 /*******************************************************************************/ 
  
////////////////////////////////////////////////////////////
  public void clear()
  {	  
	
	  tail = null; 
	  theSize = 0; 
      modCount = 0; 
  }
////////////////////////////////////////////////////////////
  public int size()
  {
	  return this.theSize; 
  }
////////////////////////////////////////////////////////////
  public boolean isEmpty()
  {
   return size() == 0; 
  }
///////////////////////////////////////////////////////////
  public AnyType get(int index)
  {	  
	  Node <AnyType> current = tail; 
	  for(int i = 0; i <= index; i++){
		  current = current.getNext();
	  }
	  return  current.getData();
	  
  }
  
  
  //////////////////////////////////////////////////////////
  public AnyType set(int index, AnyType newValue)
  {   if(index > size()-1){
	throw new IndexOutOfBoundsException();  
  
  }else{
	  
	  Node <AnyType> current = tail.next; 
	  for(int i = 0; i < index; i++){
		  current = current.getNext();
	  }
	  
	  Node <AnyType> temp = new Node<AnyType>(current.getData(),null); 
	  current.setData(newValue);
	  
	  return temp.getData();
  }  
	  
  }

////////////////////////////////////////////////////////////
  public boolean add(AnyType newValue) // add_last
  {
    add(size(), newValue);
    return true;
  }

////////////////////////////////////////////////////////////
  public void add(int index, AnyType newValue) // add_based_on_position
  {
	  if(index < 0 || index  > size()){
		  throw new IndexOutOfBoundsException();
	  }
	  else if(isEmpty()){
		  addFirstWhenEmpty(newValue);
		  
	  }
	  else if(index == size() && !isEmpty()){
		 
		  addLast(newValue);
		  
	  }
	  else if(index == 0 && !isEmpty()){
		 addfirst(newValue);
		 		  
	  }
	  else if (index > 0 || index < size()){
		 
		  		addAnyWhere(index,newValue);
		  
	  }
	  
	  this.modCount++; 
	  this.theSize++;
  }

////////////////////////////////////////////////////
  public AnyType remove(int index)
  {   Node <AnyType> temp = null;
	  
	  if(index < 0 || index > size()){ 
	 throw new IndexOutOfBoundsException();
	 
  }   else if(isEmpty()){
	  removeFirstWhenEmpty();
  } 
	  else if(index == 0){
	  temp = removeFirst();
	  return temp.getData();
  }
	  else if(index > 0 || index <= size()){
	 temp = removeAnywhere(index);
     }
	  
	  return temp.getData();
	  
  }
////////////////////////////////////////////////////
  public void rotate()
  {
   Node <AnyType> head = tail.next;
   Node <AnyType> temp = new Node <AnyType>(tail.getData(),null); 
   tail.setData(head.getData());  //CHANGE TAIL TO THE VALUE OF HEAD
   head.setData(temp.getData()); // CHANGE THE VALUE OF HEAD TO TEMP TAIL
   
   
   
  }

  public Iterator<AnyType> iterator()
  {
    return new LinkedListIterator();    
  }

  private Node<AnyType> getNode(int index)
  {
    return (getNode(index, 0, size()-1));
  }

  private Node<AnyType> getNode(int index, int lower, int upper)
  {    Node <AnyType> current = tail; 
	  
	  if(lower != 0 && upper != size()-1) {
		System.out.println("The range of the array is out of bounds");  
	  }else {
	  
	  for(int i = 0; i <= index; i++){
		  current = current.getNext();
		  
	  }
	  }
	  return current; 
	  	
  }

  private class LinkedListIterator implements Iterator<AnyType>
  {
    private Node<AnyType> previous;
    private Node<AnyType> current;
    private int expectedModCount;
    private boolean okToRemove;

    LinkedListIterator()
    {
    	current = tail.next; 
    	previous = null;
    	expectedModCount = modCount; 
    	okToRemove = false;
    }

    public boolean hasNext()
    {
       return current.getNext() != null;
    }

    public AnyType next()
    {
    	if( modCount != expectedModCount ){
            throw new java.util.ConcurrentModificationException( );
    	}
        if( !hasNext( ) ){
            throw new java.util.NoSuchElementException( );
        }
        Node <AnyType> temp = current;
        Node <AnyType> prev2 = null;
        previous = prev2;
        prev2 = current;
        okToRemove = true;
    	current = current.getNext(); 
        return  temp.getData();
    }

    public void remove()
    {
    	if( modCount != expectedModCount ){
            throw new java.util.ConcurrentModificationException( );
    	}
        if( !okToRemove ){
            throw new IllegalStateException( );
        }//NEXT HASNT BEEN cALLED
        
        if(previous == null){
        	tail.next = current;
        }else if(previous != null){
        	
        	previous.setNext(current);
        	
        }
        okToRemove = false;
        expectedModCount++;
        theSize--;
    	   
       }
    }
  }

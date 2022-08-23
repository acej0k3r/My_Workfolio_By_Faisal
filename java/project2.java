import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


class project2 {

	public static void main(String[] args) {
		String r [] = new String[100];
		int e [] = new int[100];
		int counter = 0;
		
		Scanner inFile = null;
		
		try{
			inFile = new Scanner(new File("HuffmanCoding_Data1.txt"));
			
			
			while(inFile.hasNext()){
				r[counter] = inFile.next();
				e[counter] = inFile.nextInt();
				counter++;
				
			}
					
		}catch(Exception err){
			System.out.println("Could not find file");
		}
		
		String[] chrHolder = new String[counter];
		int[] probHolder = new int[counter];
		
		//new arrays with the appropriate size required to hold data
		for(int i = 0; i < counter; i++){
			chrHolder[i] = r[i];
			probHolder[i] = e[i];
		}
		//old arrays made null to regain memory
		r = null;
		e = null;
		
		inFile.close();
		
		
		
		//constructs huffmanlisttree		
		HuffmanListTree ll = new HuffmanListTree();
		ll.ConstructLinkedList(chrHolder, probHolder);
		//stores the linnked list data as a string into output
		String output = ll.printList();
		
		System.out.println(output);
		//writes the string output to outfile1
		
		
		File outFile1 = new File("outFile1.txt");
		try {
		if(!outFile1.exists()){
			
				outFile1.createNewFile();
		}		
				PrintWriter pw = new PrintWriter(outFile1);
				pw.println(output);
				pw.close(); 

			
		} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();			
	}
		
		ll.ConstructBinTree(ll.listHead);
		ll.constructCode(ll.Root, "");
		ll.preOrderTravTreee(ll.Root);
		
		
		
	}
}

class listBinTreeNode {

	private int prob;
	private String chStr;
	private String code;
	private listBinTreeNode next = null;
	private listBinTreeNode leftChild = null;
	private listBinTreeNode rightChild = null;

	
	//SETTER AND GETTER
	public void setProb(int x){
		this.prob = x;
	}
	public int getProb(){
		return this.prob;
		
	}
	
	public void setchStr(String x){
		this.chStr = x;
	}
	
	public String getchStr(){
		return this.chStr;
	}
	
	public void setCode(String x){
		this.code = x;
	}
	public String getCode(){
		return this.code;
	}
	
	
	
	public void setNext(listBinTreeNode T){
		this.next = T;
	}
	public listBinTreeNode getNext(){
		
		
		return this.next;
	}
	
	public void setLeftChild(listBinTreeNode T){
		this.leftChild = T;
	}
	
	public listBinTreeNode getLeftChild(){
	
		return this.leftChild;
	}
	
	public void setRightChild(listBinTreeNode T){
		this.rightChild = T;

		
	}
	
	public listBinTreeNode getRightChild(){
		
		return this.rightChild;
	}
	
	
	
	//CONSTRUCTOR
	listBinTreeNode(String word,int key){
			
			this.prob = key;
			this.chStr = word;
		}

	public String toString() {
		return chStr + " has a key " + prob;

	}
	
	public void printNode(listBinTreeNode T){
		System.out.println("T's chrStr is: " + T.chStr + "T's prob is: " + T.prob +
				"T's code is:" + T.code + "T's next chStr is \n: " + T.next.chStr + 
				"T's left's chStr is: " + T.leftChild.chStr + "T's right's chStr is: "+ T.rightChild.chStr);
	}

}





 class HuffmanListTree {
	listBinTreeNode listHead;
	listBinTreeNode Root;
	
	HuffmanListTree(){
		listHead = new listBinTreeNode("Dummy", 0);
		
	}
	
	public listBinTreeNode ConstructLinkedList(String[] chArr, int[] prob){
		listBinTreeNode spot;
		for(int i =0; (i < chArr.length || i < prob.length);i++ ){
			listBinTreeNode newNode = new listBinTreeNode(chArr[i],prob[i]);
			
			spot = findSpot(listHead, newNode);
			insertNewNode(spot, newNode);
		    		
		}
		return listHead;		
	}
	
	public void ConstructBinTree(listBinTreeNode listHead){
		
		
		
		while(listHead.getNext().getNext() != null){
		listBinTreeNode newNode = new listBinTreeNode("empty",0);
		listBinTreeNode firstNode = listHead.getNext();
		listBinTreeNode secondNode = firstNode.getNext();
		
		String concat = firstNode.getchStr() + secondNode.getchStr();
		int totalProb = firstNode.getProb() + secondNode.getProb();
		newNode.setchStr(concat);
		newNode.setProb(totalProb);
	    newNode.setLeftChild(firstNode);
	    newNode.setRightChild(secondNode);
	    
	    printNode(newNode);
	    listBinTreeNode spot = findSpot(listHead, newNode);
	    insertNewNode(spot, newNode);   
	    printList(listHead);
	    listHead = secondNode;
	    
		}
		Root = listHead.getNext();
	   
	}
	
	public void constructCode(listBinTreeNode Root, String bitstr){
		if(Root == null){
			System.out.println("This is an empty tree");
			System.exit(0);
		}else if (isLeaf(Root)){
			Root.setCode(bitstr);
			printLeaf(Root);
		}else{
			constructCode(Root.getLeftChild(), bitstr + "0");
			constructCode(Root.getRightChild(), bitstr + "1");
		}
	}
	
	


	
	
	
	 private boolean isLeaf(listBinTreeNode t) {
         assert ((t.getLeftChild() == null) && (t.getRightChild() == null)) || ((t.getLeftChild() != null) && (t.getRightChild() != null));
         return (t.getLeftChild() == null) && (t.getRightChild() == null);
     }
	
	
	
	
public void inOrderTravTreee(listBinTreeNode focusNode){
		
		if(focusNode != null){
			inOrderTravTreee(focusNode.getLeftChild());
			printNode(focusNode,0);
			inOrderTravTreee(focusNode.getRightChild());
		}
	}
	

	public void preOrderTravTreee(listBinTreeNode focusNode){
		
		if(focusNode != null){
			
			
			printNode(focusNode,0);
			preOrderTravTreee(focusNode.getLeftChild());
			preOrderTravTreee(focusNode.getRightChild());
		}
	}
		public void postOrderTravTreee(listBinTreeNode focusNode){
			
			if(focusNode != null){
				
				
			
				postOrderTravTreee(focusNode.getLeftChild());
				postOrderTravTreee(focusNode.getRightChild());
				printNode(focusNode,0);
			}
	
	
		
	}
	
	
	public listBinTreeNode findSpot(listBinTreeNode listHead,listBinTreeNode T){
		listBinTreeNode spot = listHead;
		
		if(isEmpty()){
			spot = listHead;
		}else if(T.getProb() == listHead.getNext().getProb() || T.getProb() < listHead.getNext().getProb()){
			
			// REPLACE SECONDNODE WITH NEWNODE AND LINK SECONDNODE TO NEWNODE
			spot = listHead;
			
		}else if(T.getProb() > listHead.getNext().getProb()){
			//making local reference
			
					
			while((spot.getNext() != null) && (T.getProb() > spot.getNext().getProb()) && (T.getProb() != spot.getNext().getProb())){
				spot = spot.getNext();
		
			}
					
		}
		
		return spot;
		
	}
	
	
	public void insertNewNode(listBinTreeNode spot, listBinTreeNode newNode){
		newNode.setNext(spot.getNext());
		spot.setNext(newNode);
		
		
	}
	
	
	
	public boolean isEmpty(){
		if(listHead.getNext() == null){
			return true;
		}else{
			return false;
		}
		
	}
	
	String n = "";
	public void printList(listBinTreeNode listHead){
		listBinTreeNode spot = listHead;
		String x = "";
		while(spot.getNext()!= null){
			x +="(" + " \"" + spot.getchStr() +"\"" + "," +
		spot.getProb() + "," + "\"" + spot.getNext().getchStr() + "\"" + ")";
		spot = spot.getNext();
		}
		//we know there is still one next because it stops after .getnext
		x += "(" + " \"" + spot.getchStr() +"\"" + "," +
				spot.getProb() + ","  + "NULL" + ")" + "(" + "NULL" +")" ;
		
		n += x;
		//puts it in file 2
		File outFile2 = new File("outFile.txt");
		try {
		if(!outFile2.exists()){
			
				outFile2.createNewFile();
		}		
				PrintWriter pw = new PrintWriter(outFile2);
				pw.println(n += "                     \n");
				pw.close(); 
				
			
		} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();			
	}
		
		
		
		
	}
	
	public String printList(){
		listBinTreeNode spot = listHead;
		String x = "";
		while(spot.getNext()!= null){
			x +="(" + " \"" + spot.getchStr() +"\"" + "," +
		spot.getProb() + "," + "\"" + spot.getNext().getchStr() + "\"" + ")";
		spot = spot.getNext();
		}
		//we know there is still one next because it stops after .getnext
		x += "(" + " \"" + spot.getchStr() +"\"" + "," +
				spot.getProb() + ","  + "NULL" + ")" + "(" + "NULL" +")";
		
		return x;
	}
	
    String r = "";
	public void printNode(listBinTreeNode t){
		String x = "";
	
		File outFile2_0 = new File("outFile2.txt");
		if(t.getNext() != null){
		x += "("  + t.getchStr() + "," + t.getProb()  + ", " + t.getCode() + ", " + t.getNext().getchStr() + ", " + t.getLeftChild().getchStr() + ", " + t.getRightChild().getchStr() + ")"         ;
		}else{
		x +=	"("  + t.getchStr() + "," + t.getProb() + ", " + t.getCode() + ", " + "NULL" + ", " +t.getLeftChild().getchStr() + ", " + t.getRightChild().getchStr() + ")";
		}
		
		r += x;
		try {
		if(!outFile2_0.exists()){
			
				outFile2_0.createNewFile();
		}		
				PrintWriter pw = new PrintWriter(outFile2_0);
				pw.println(r);
				pw.close();
			
		} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();			
	}
		
	}
	
	String rp = "";
	public void printNode(listBinTreeNode t,int lol){
		String x = "";
			x += "("  + t.getchStr() + "," + t.getProb()  + ", " + t.getCode() +")";
			
		rp += x;
		File outFile2_0 = new File("outFile4.txt");
		
		try {
		if(!outFile2_0.exists()){
			
				outFile2_0.createNewFile();
		}		
				PrintWriter pw = new PrintWriter(outFile2_0);
				pw.println(rp);
				pw.close();
			
		} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();			
	}
		
	}
	
	
	String rpr = "";
	public void printLeaf(listBinTreeNode Root){
		String x = "(" + Root.getchStr() + "," + Root.getCode() + ")";
		File outFile2_0 = new File("outFile3.txt");
		rpr += x;
		try {
			if(!outFile2_0.exists()){
				
					outFile2_0.createNewFile();
			}		
					PrintWriter pw = new PrintWriter(outFile2_0);
					pw.println(rpr);
					pw.close();
				
			} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
}


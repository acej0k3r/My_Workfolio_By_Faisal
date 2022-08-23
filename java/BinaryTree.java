
public class BinaryTree {

	class Node{
		
		int k;
		String name;
		private Node leftChild;
		private Node rightChild;
		
		Node(int key, String word){
			
			this.k = key;
			this.name = word;
		}
		
	public String toString(){
		return name + " has a key " + k;
		
	}
	}
	
	Node root;
	public void addNode(int key,String name){
		
		Node newNode = new Node(key,name);
		
		
		if(root == null){
			root = newNode;
		}
		else{
		  Node focusNode = root;
		  Node parent;
		  
		  while(true){
			 parent = focusNode;
			 if(key < focusNode.k) {
				 focusNode = focusNode.leftChild;
				 if(focusNode == null){
					 parent.leftChild = newNode;
					 return;
				 }
			 }else{
				 focusNode = focusNode.rightChild;
				 if(focusNode == null){
					 parent.rightChild = newNode;
					 return;
					
				 }
			 }
			  
		  }
			
		}
		
		
	}//END ADDNOTE
	
	
	
	
		
		public Node findNode(int key){
			
			Node focusNode = root;
			while(focusNode.k != key){
				 if(key < focusNode.k){
					 focusNode = focusNode.leftChild;
				 }
				 else{
					 focusNode = focusNode .rightChild;
				 }
				 if(focusNode == null){
					 return null;
				 }
	
			}
			return focusNode;
		}
	
	public boolean remove(int key){
		Node focusNode = root;
		Node parent  = root;
		
		boolean isItALeft = true;
		
		while(focusNode.k != key){
			parent = focusNode;
			if(key < focusNode.k){
				isItALeft = true;
				
				focusNode = focusNode.leftChild;
			}else{
				isItALeft = false;
				focusNode = focusNode.rightChild;
				
			}
			if(focusNode == null){
				return false;
			}
			
				
			}
			
		if(focusNode.leftChild == null && focusNode.rightChild == null){
			if(focusNode == root){
				root = null;
			}
			else if(isItALeft){
				parent.leftChild = null;
			}	
			else{
				parent.rightChild = null;
			}
			
		}
		else if(focusNode.rightChild == null){
			if(focusNode  == root){
				root = focusNode.leftChild;
			}
			else if(isItALeft){
				parent.leftChild = focusNode.leftChild;
			}else{
				parent.rightChild = focusNode.leftChild;
			}
			
		}
		else if(focusNode.leftChild == null){
			if(root == null){
			root = focusNode.rightChild;
			}else if(isItALeft){
				parent.leftChild = focusNode.rightChild;
			}else{
				parent.rightChild = focusNode.leftChild;
			}
		}
		
		
		
		
		
		return true;
	}
	
	
	
	
	
	
	

	

}



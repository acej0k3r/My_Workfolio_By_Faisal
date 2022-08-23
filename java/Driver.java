
public class Driver {
	public static void main(String[] args) {
		BinaryTree theTree = new BinaryTree();
		theTree.addNode(30, "king");
		theTree.addNode(34, "queen");
		theTree.addNode(36, "prince");
		theTree.addNode(37, "princess");
		theTree.addNode(21, "knights");
		theTree.addNode(24, "Bishop");
		theTree.addNode(28, "castle");
		theTree.addNode(19, "teacher");
		theTree.addNode(20, "student");
		theTree.addNode(18, "deciple");
		
		theTree.inOrderTravTreee(theTree.root);
		System.out.println("\n \n \n");
		
		theTree.preOrderTravTreee(theTree.root);
		
		System.out.println("\n \n \n");

		theTree.postOrderTravTreee(theTree.root);
	}
	
}

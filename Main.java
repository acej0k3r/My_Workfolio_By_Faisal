
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
class Main {
	public static void main(String[] args) {
		/* OPENING A FILE IS NOT NEEDED AS IT IS INCORPORATED 
		 * WITH THE CONSTRUCTOR AND HEAP_ARY IS GIVEN A
			SIZE AS WELL AS NUMITEMS GIVEN A VALUE */
		HeapSort hs = new HeapSort();
		  //SINCE OUTFILE1 WILL ALWAYS APPEND WE MUST START PROGRAM WITH CLEARING A FILE AND OPENING AN EMPTY FILE
		  hs.clearFile("outFile1.txt");
		  hs.clearFile("outFile2.txt");
		  hs.buildHeap();
		  hs.deleteHeap();
		  System.out.println("done");
		  
}

}	
	

		 


class HeapSort {
	int rootIndex;
	int fatherIndex;
	int leftKidIndex;
	int rightKidIndex;
	int kidIndex;
	int minKidIndex;
	int numItems;
	
	
	int[] heapAry;
	
	HeapSort(){
		rootIndex = 0;
		numItems = countData();
		heapAry = new int[numItems + 1];
		heapAry[0] = 0;
	}
	
	public int countData(){
		int i = 0;
		@SuppressWarnings("unused")
		int p = 0;
		try{
		Scanner in = new Scanner(new File("Heap_Sort_Data.txt"));
		
		
			while(in.hasNext()){
				p = in.nextInt();
				i++;
			}
			
			in.close();
			
		}catch(Exception e){
			System.out.println(e);
		}
		
		return  i;	
		
	}
	
	public void buildHeap(){
		try{
			Scanner in = new Scanner(new File("Heap_Sort_Data.txt"));
			rootIndex = 1;
			int data;
				while(in.hasNext()){
					data = in.nextInt();
					insertOneDataItem(data);
				}
				
				printHeap("outFile1.txt");
			

				
				
				
				
				
				
				in.close();
				
			}catch(Exception e){
				System.out.println(e);
			}
		
		
		
		
	}
	
	public void insertOneDataItem(int x){
		heapAry[0] += 1;
		kidIndex = heapAry[0];
		heapAry[kidIndex] = x;
		bubbleUp(kidIndex);
	}
	
	
	
	
	
	
	
	public void bubbleUp(int index){
		if(isRoot(index)){
			return;
		}else{
			fatherIndex = kidIndex / 2;
				if(heapAry[kidIndex] >= heapAry[fatherIndex])
					return;
				else{
					int holder;
					holder = heapAry[fatherIndex];
					heapAry[fatherIndex] = heapAry[kidIndex];
					heapAry[kidIndex] = holder;
					kidIndex = fatherIndex;
					bubbleUp(fatherIndex);
				}
		}
	}
	
	
	public boolean isRoot(int x){
		if( x == 1){
			return true;
		}else{
			return false;
		}
	}
	
	
	public void deleteHeap(){
		while(!isHeapEmpty()){
			replaceRoot();
		}
		printHeap("outFile1.txt");
	}
	
	public boolean isHeapEmpty(){
		if(heapAry[0] == 0){
			return true;
		}else{
			return false;
		}
	}
	
	public void replaceRoot(){
		int data = heapAry[rootIndex];
		printToFile("outFile2.txt", data);
		heapAry[rootIndex] = heapAry[0];
		heapAry[heapAry[0]] = 0;
		heapAry[0] -= 1;
		fatherIndex = rootIndex;
		bubbleDown(fatherIndex);
		
		printHeap("outFile1.txt");
		
		
	} 
	
	public void bubbleDown(int index){
		if(isLeaf(index)){
			return;
		}else{
			leftKidIndex = fatherIndex * 2;
			rightKidIndex = fatherIndex * 2 + 1;
			minKidIndex = findMinKidIndex(leftKidIndex, rightKidIndex);
			
			if(heapAry[minKidIndex] >= heapAry[fatherIndex])
				return;
			else{
				int holder = 0;
				holder = heapAry[fatherIndex];
				heapAry[fatherIndex] = heapAry[minKidIndex];
				heapAry[minKidIndex] = holder;
				
				bubbleDown(minKidIndex);
				
			}
						
			
		}
	}
		
	
	public boolean isLeaf(int x){
		if(heapAry[x * 2 + 1] > 0  || heapAry[x*2 + 2] > 0){
			return false;
		}else{
			return true;
		}
		
		
		
	}
	
	public int findMinKidIndex(int l, int r){
		int box = 0;
		if(heapAry[r] <= 0 && heapAry[l] > 0){
			return box += l;
		}
		else if(heapAry[l] <= 0 && heapAry[r] > 0){
			return box += r;
		}
		else if(heapAry[l] < heapAry[r]){
			return box += l;
		}else if(heapAry[r] < heapAry[l]){
			return box += r;
		}
		return box;
	}
	
	
	String rp = "";
	int track = 0;
	public void printHeap(String x){
		File outFile2_0 = new File(x);
	
		
		
		try {
		if(!outFile2_0.exists()){
			
				outFile2_0.createNewFile();
		}		
				FileWriter fw = new FileWriter(outFile2_0,true);
				BufferedWriter buffer = new BufferedWriter(fw);
				PrintWriter pw = new PrintWriter(buffer);
				
				rp += "[" + heapAry[0];
				for(int i = 1; i < heapAry[0] + 1; i++){
					rp += ", " + heapAry[i]; 
				}
				rp += "]\n";
				
				
				
				pw.println(rp);
				if(track == 0){
					
					pw.println("__________________________________________________________________\n");
					pw.println("__________________________________________________________________\n");
					pw.println("__________________________________________________________________\n");
					pw.println("DELETIION OF HEAP RESULTS:::::::::::::::::::::::::::::::::::::::::\n");
				track++;
				}
				
				
				
				

				pw.close();
			    rp = "";
		} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();			
	}
	}
	
	public void printToFile(String x, int num){
		File outFile2_0 = new File(x);
		
		
		
		try {
		if(!outFile2_0.exists()){
			
				outFile2_0.createNewFile();
		}		
		
				FileWriter fw = new FileWriter(outFile2_0, true);
				BufferedWriter bw = new BufferedWriter(fw);
				PrintWriter pw = new PrintWriter(bw);
				
				
				
				
				
				pw.println(num);
				pw.close();
		} catch (IOException e1) {
		// TODO Auto-generated catch block
		e1.printStackTrace();			
	}
	}
	
	
	 public void clearFile(String x){
		  File clearTxtFile = new File(x);
			 try{
			  PrintWriter pw = new PrintWriter(clearTxtFile);
			 if(!clearTxtFile.exists()){
				 clearTxtFile.createNewFile();
			 }
			 	pw.write("");
			 	pw.close();
			 //this writes to the file which cancels out the appending done due to previous runs
			 }catch(Exception e){
				 System.out.println(e);
			 }
	 }
}


	
	
	

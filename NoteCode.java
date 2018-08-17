import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class NoteCode {
	/////////////MEMBER VAR//////////////MEMBER VAR////////////MEMBER VAR
    private String fileName = null;
	private FileInputStream r;
	private BufferedReader br;

///////////PRIVATE FUNCTION//////////////PRIVATE FUNCTION/////////////PRIVATE FUNCTION	
private void prints(String x){
	System.out.println(x);
}
	
//////////////////////////////////////////////////////////////
	
	public void openReadF(String x){
		fileName = x;
		try{
			r = new FileInputStream(x);
			br = new BufferedReader(new InputStreamReader(r));
			
			
		}catch(Exception e){
			System.out.println("Error found named " + e);
		}
		
	}
	//////////////////////////////////////////////////////////
	public String readfile(){
	String x = null;
	  if(fileName != null){
			
		try{
			x = br.readLine();
			
			
		}catch(IOException e){
			prints("There was an error " + e);
			
		}
	  }else{
		 prints("DID NOT OPEN THE FILE TO READ IT"); 		  
	  }
	  return x;
	}
	///////////////////////////////////////////////////////////
	
	
	
	
	//////////////////////////////////////////////////////////
	 public void closeReadF(){
		 try {
			fileName = null; 
			r.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	 }
	 
	 //////////////////////////////////////////////////////////
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
}






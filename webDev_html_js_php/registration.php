<?php
   





 $user = $_POST['email'];
 $pass = $_POST['password'];
	

   $host = "mars.cs.qc.cuny.edu";
   $username = "kcbh8602";
   $password = "23148602";
   $dbname = "kcbh8602";
   // connection
   $conn = mysqli_connect($host,$username,$password,$dbname);
   $db = $conn;
   //check




//functions
function goToUrl($url) {
             ob_start(); // ensures anything dumped out will be caught

            // do stuff here
            
            // clear out the output buffer
            while (ob_get_status())  
            {
                ob_end_clean();
            }

            // no redirect
            header( "Location: $url" );
       }







   if($conn->connection_error){
       
        die("Connection Failed :". mysqli_connect_error());
       

       
   }else{
   
   		ini_set('display_errors', 1);
		ini_set('display_startup_errors', 1);
		error_reporting(E_ALL);
       
       echo "connection success <br>";
       
       
       //check if username for student
       $query = 'select studentUsername, studentPassword from `Students` where studentUsername = "'.$user.'"';
       $result = mysqli_query($conn, $query);
       
       
       //check if username for admin
        $query2 = 'select adminUsername, adminPassword from `Administrator` where adminUsername = "'.$user.'"';
        $result2 = mysqli_query($conn, $query2);
       
      //check if username for staff
        $query3 = 'select staffUsername, staffPassword from `Staffs` where staffUsername = "'.$user.'"';
        $result3 = mysqli_query($conn, $query3);
       
       
       if($row = mysqli_fetch_array($result)){
      
       
       		echo "".$row["studentUsername"]." ".$row["studentPassword"]." <br>";
           
           
           if($pass != $row["studentPassword"]){ //theres a student that exists with this name but password doesnt match
            
               goToUrl('https://venus.cs.qc.cuny.edu/~famd7995/final/login.html');
 
           }else{
               //SUCCESS STUDENT AND PASSWORD MATCH
               goToUrl('https://venus.cs.qc.cuny.edu/~famd7995/final/StudentsPage/StudentsPage.html');
  
           }
           
       
       }elseif($row2 = mysqli_fetch_array($result2)){
           
        /////////////////////////////////  
       

                   
                   if($pass != $row2["adminPassword"]){ //theres a admin that exists with this name but password doesnt match
            
               goToUrl('https://venus.cs.qc.cuny.edu/~famd7995/final/login.html');
 
                    }else{
               //SUCCESS admin AND PASSWORD MATCH
                goToUrl('https://venus.cs.qc.cuny.edu/~famd7995/final/admin_page/admin.html');
  
                }
                   
                   
                   
       }elseif($row3 = mysqli_fetch_array($result3)){
                   

                   if($pass != $row3["staffPassword"]){ //theres a admin that exists with this name but password doesnt match
            
                    goToUrl('https://venus.cs.qc.cuny.edu/~famd7995/final/login.html');
 
                    }else{
               //SUCCESS admin AND PASSWORD MATCH
                goToUrl('https://venus.cs.qc.cuny.edu/~famd7995/final/staffs_page.html');
  
                  } 
                   
                   
                   
                   
               
           
       }//end of username check studennt
       
      
       
       
       
       
      
   
}// end of alive check

?>




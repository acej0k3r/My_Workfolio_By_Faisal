<?php
   

 $date = $_POST['date'];
 $id = $_POST['id'];
 $lastName = $_POST['lName'];
 $firstName = $_POST['fName'];
 $midName = $_POST['mName'];
 $address = $_POST['address'];
 $email = $_POST['email'];
 $homePhone = $_POST['homePhoneNum'];
 $cellPhone = $_POST['cellPhoneNum'];

$withdrawlArr = array(
array($_POST['course0'],$_POST['code0'],$_POST['year0'],$_POST['instructor0'],$_POST['grade0']),
array($_POST['course1'],$_POST['code1'],$_POST['year1'],$_POST['instructor1'],$_POST['grade1']),
array($_POST['course2'],$_POST['code2'],$_POST['year2'],$_POST['instructor2'],$_POST['grade2']),
array($_POST['course3'],$_POST['code3'],$_POST['year3'],$_POST['instructor3'],$_POST['grade3']),
array($_POST['course4'],$_POST['code4'],$_POST['year4'],$_POST['instructor4'],$_POST['grade4'])
    
);
	

   $host = "mars.cs.qc.cuny.edu";
   $username = "kcbh8602";
   $password = "23148602";
   $dbname = "kcbh8602";
   // connection
   $conn = mysqli_connect($host,$username,$password,$dbname);
   $db = $conn;
   //check
   if($conn->connection_error){
       
        die("Connection Failed :". mysqli_connect_error());
       

       
   }else{
   
   		ini_set('display_errors', 1);
		ini_set('display_startup_errors', 1);
		error_reporting(E_ALL);
       
       echo "connection success";
       
       
       
       $query = "SELECT * FROM `Students`";
       $result = mysqli_query($conn, $query);
       
       while($row = mysqli_fetch_array($result)){
       echo "".$row["studentName"]." ".$row["studentUsername"]."<br>";
       
       }
       
       
      
   }


?>




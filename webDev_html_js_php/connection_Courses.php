<?php
   $host = "venus.cs.qc.cuny.edu";
   $username = "KCBH8602";
   $password = "23148602";
   $dbname = "KCBH8602";
   // connection
   $conn = mysqli_connect($host,$username,$password,$dbname);
   //check
   if($conn){
       echo "";
   }else{
       die("Connection Failed :". mysqli_connect_error());
   }

    $date = $POST['date'];


?>




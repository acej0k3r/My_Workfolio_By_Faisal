<?php
$host = "mars.cs.qc.cuny.edu";

$user ="KCBH8602";   
$password= "23148602"; 
$db = "KCBH8602";   


$mysqli = new mysqli($host, $user, $password, $db);


if( $mysqli->connect_errno) {
	
	echo $mysqli->connect_error;
	
	exit();
}




if( isset($_POST["delete"])){
	if(isset($_POST["checkbox"])){
	foreach($_POST["checkbox"] as $studentID){
	$query= "DELETE StaffReview, AdminSubmits, Forms, StudentCourseHistory, Courses, Students
	FROM StaffReview
	JOIN AdminSubmits
	ON StaffReview.submitID= AdminSubmits.submitID
	JOIN StudentRequest
	ON AdminSubmits.requestID = StudentRequest.requestID
	JOIN Students
	ON  StudentRequest.studentID=Students.studentID
	JOIN Forms
	ON StudentRequest.FormID= Form.FormID
	JOIN StudentCourseHistory
	ON Forms.SCH_ID= StudentCourseHistory.SCH_ID";
	JOIN Courses
	ON StudentCourseHistory.SCH_ID= Courses.SCH_ID";
	WHERE studentID='$studentID';";
	
	
	$mysqli->query($query);
	}
	
    }
}


if( isset($_POST["student_name"]) && !empty($_POST["student_name"])) {
	$sql= "SELECT  Students.studentID, Students.studentName, StudentRequest.dateRequested, StaffReview.reviewStatus
	FROM StaffReview
	JOIN AdminSubmits
	ON StaffReview.submitID= AdminSubmits.submitID
	JOIN StudentRequest
	ON StudentRequest.requestID= AdminSubmits.requestID
	JOIN Students
	ON StudentRequest.studentID= Students.studentID
	WHERE studentName LIKE %$_POST["student_name"]%;";
	ORDER BY dateRequested;";
}
else{

	$sql = "SELECT Students.studentID, Students.studentName, StudentRequest.dateRequested, StaffReview.reviewStatus
	FROM StaffReview
	JOIN AdminSubmits
	ON StaffReview.submitID= AdminSubmits.submitID
	JOIN StudentRequest
	ON AdminSubmits.requestID = StudentRequest.requestID
	JOIN Students
	ON StudentRequest.studentID=Students.studentID
	ORDER BY dateRequested;";
}


$results = $mysqli->query($sql);

if (!$results) {
	echo $mysqli->error;
	exit();
}


?>



<!doctype html>
<html lang="en">
	<head>
	    <title>Admin Panel</title>
	   <meta name="viewport" content="width=device-width, initial-scale=1">
	  
	   <link rel="stylesheet" type="text/css" href="css.css">	
	</head>

<body>
	<form action="admin.php" method="POST">
	
	<header>
	<img src="QClogo.png" alt="qc"/>
	<button type ="submit" name= "logoutbtn" id= "logout">Logout</button>
	</header>
	

	
	<h2>Welcome to Admin Panel</h2>

	<div id="searchbar">
	<input id= "search" name="student_name" type="text" placeholder="Search Name">
	<button type= "submit" name="search" id="searchname">Search</button>
	</div>

<div id="requests">
	

	<div id="head">
		<h3>Student Requests</h3>
		<button type= "submit" name="delete" id="deleterow">Delete</button>
	</div>




<table> 
   <thead>
 	 <tr>
	    <th><input type="checkbox" id="checkAll"></th>
	    <th>CUNYFirst ID</th>
	    <th>Name</th> 
    	    <th>Date Submitted</th>
    	    <th>Status</th> 
  	</tr>
   </thead>
 <tbody>
<?php while($row = $results->fetch_assoc()) :?>
   <tr>
	<td><input type="checkbox" value="<?php echo ($row['studentID']); ?>" name="checkbox[]"</td>
	<td> <?php echo ($row['studentID']); ?></td>
	<td> <?php echo strtoupper($row['studentName']); ?></td>
	<td> <?php echo strtoupper($row['dateRequested']); ?></td>
	<td> <?php echo "$". $row['reviewStatus']; ?></td>
	
   </tr>
<?php endwhile;?>
  </tbody>
</table>



</div>


<script
  src="http://code.jquery.com/jquery-3.5.1.min.js"
  integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0="
  crossorigin="anonymous"></script>
<script src="script.js"></script>
</form>

</body>
</html>
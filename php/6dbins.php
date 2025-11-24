<?php

$rollno=$_GET["rollno"];
$name=$_GET["name"];
$gender=$_GET["gender"];
$mark1=$_GET["mark1"];
$mark2=$_GET["mark2"];
$total=$mark1+$mark2;

$dbcon=mysqli_connect('localhost','root','','student');

if(!$dbcon){
    die("connection failed:".mysqli_connect_error()); 
}
else{
    echo "connected successfully<br>";
}


$check_sql = "SELECT rollno FROM stud1 WHERE rollno = '$rollno'";
$check_result = mysqli_query($dbcon, $check_sql);

if(mysqli_num_rows($check_result) > 0) {
    echo "<script>alert('Error: Roll number $rollno already exists!');</script>";
    exit();
}

echo "hello  ".$name." your roll no is ".$rollno . "<br>";
$sql="INSERT INTO stud1 VALUES ('$rollno ','$name','$gender','$mark1','$mark2','$total')";
$display="SELECT * FROM stud1";



if(mysqli_query($dbcon,$sql)){
    echo "New record created successfully";
}
else{
    echo "Error: ".$sql."<br>".mysqli_error($dbcon);
}

echo "<br><br> <b> Displaying all records from the table </b> <br><br>";
$result=mysqli_query($dbcon,$display);
while($row=mysqli_fetch_assoc($result)){
    echo "Roll No: ".$row['rollno']." Name: ".$row['name']." Gender: ".$row['gender']." Mark1: ".$row['mark1']." Mark2: ".$row['mark2']." Total: ".$row['total']."<br>";       
}

?>   
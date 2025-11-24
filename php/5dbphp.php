<?php

$rollno=$_GET["rollno"];
$name=$_GET["name"];

$dbcon=mysqli_connect('localhost','root','','student');

if(!$dbcon){
    die("connection failed:".mysqli_connect_error()); 
}
else{
    echo "connected successfully<br>";
}

echo "hello  ".$name." your roll no is ".$rollno;
$sql="INSERT INTO stud VALUES ('$rollno','$name')";
if(mysqli_query($dbcon,$sql)){
    echo "New record created successfully";
}
else{
    echo "Error: ".$sql."<br>".mysqli_error($dbcon);
}
?>   
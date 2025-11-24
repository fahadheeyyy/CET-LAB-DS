<?php

$rollno=$_POST["rollno"];
$name=$_POST["name"];   
$username=$_POST["username"];
$password=$_POST["password"];
$address=$_POST["address"];

$dbcon=mysqli_connect("localhost","root","","student");
if(!$dbcon){
    die("connection failed:".mysqli_connect_error()); 
}

$sql="INSERT INTO stud_login VALUES ('$rollno','$name','$username','$password','$address')";

$check="SELECT * FROM stud_login WHERE username='$username' OR  rollno='$rollno'";
$result=mysqli_query($dbcon,$check);

if(mysqli_num_rows($result)>0){
    die("Username or Roll no already exists");
}



if(mysqli_query($dbcon,$sql)){
    echo "New record created successfully";
}
else{
    echo "Roll no already exists";
}



?>
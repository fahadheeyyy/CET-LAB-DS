<?php

if(isset($_POST['username']) && isset($_POST['password'])){
    $username=$_POST['username'];
    $password=$_POST['password'];

    $dbcon=mysqli_connect("localhost","root","","student");
    if(!$dbcon){
        die("connection failed:".mysqli_connect_error()); 
    }
    else{
        echo "connected successfully<br>";
    }

    $sql="SELECT * FROM admin WHERE username='$username' AND password='$password'";
    $result=mysqli_query($dbcon,$sql);

    // $checkRoll="SELECT rollno FROM stud_login WHERE username='$username' AND password='$password'";
    // $roll=mysqli_query($dbcon,$checkRoll);

    if(mysqli_num_rows($result)>0){
        while($row=mysqli_fetch_assoc($result)){
            echo "welcome , admin";
        }
    }
    else{
        die("invalid credentials");
    }

    // $rollno=mysqli_fetch_assoc($roll)['rollno'];

    // echo "<h3>You selected Roll Number: $rollno</h3>";


}

?>

    <iframe src="8.3.php" name="frame1">
<?php

if(isset($_POST['update'])){
    $name = $_POST['name'];
    $rollno = $_POST['rollno'];
    $address = $_POST['address'];
    $phone = $_POST['phone'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $cpassword = $_POST['cpassword'];

    if($password !== $cpassword){
        echo "<p style='color:red'>❌ Passwords do not match!</p>";
    } 
    else{
        $con = mysqli_connect("localhost", "root", "", "student");

        if ($con){
            $sql ="INSERT INTO students (rollno, name , address, phone, username, password) VALUES ('$rollno', '$name', '$address', '$phone', '$username', '$password')";
            if(mysqli_query($con,$sql)){
                echo"succesfully registered";

            }
            else{
                echo "Error: " . mysqli_error($con);
            }

        }
        else{
            die("Connection failed: " . mysqli_connect_error());
        }
    }
}



?>

<h2>Student Registration</h2>
<form method="POST" >
    Enter Name:
    <input type="text" name="name" required>
    <br><br>
    Enter Roll No:
    <input type="number" name="rollno" required>
    <br><br>
    Enter Address:
    <input type="text" name="address" required>
    <br><br>
    Enter Phone No:
    <input type="number" name="phone" required>
    <br><br>
    Enter Username:
    <input type="text" name="username" required>
    <br><br>
    Enter Password:
    <input type="password" name="password" required>
    <br><br>
    Re-enter Password:
    <input type="password" name="cpassword" required>
    <br><br>
    <input type="submit" name="update" value="Register">
</form>
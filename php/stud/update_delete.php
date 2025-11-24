<?php
$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}
$sql="SELECT * FROM students";
$result=mysqli_query($con,$sql);
while($row=mysqli_fetch_assoc($result)){
    echo "Roll No: ".$row['rollno']." | Name: ".$row['name']." | Address: ".$row['address'];
    echo " <a href='delete_student.php?rollno=".$row['rollno']."'>Delete</a> ";
    echo " <a href='update_student.php?rollno=".$row['rollno']."'>Update</a> ";
    echo "<br>";
}

?>
<form method="post" >
    Select Roll Number:
    <select name="rollno">
        <?php
        $con = mysqli_connect("localhost", "root", "", "student");
        $sql="SELECT rollno FROM students";
        $result=mysqli_query($con,$sql);
        while($row=mysqli_fetch_assoc($result)){
            echo "<option value=".$row['rollno'].">".$row['rollno']."</option>";
        }
        
        ?>
    </select>
    <input type="submit" name="submit" value="Submit">
</form>

<?php

if(isset($_POST["submit"])){
$rollno=$_POST["rollno"];

$con=mysqli_connect("localhost","root","","student");
$sql="SELECT * FROM students WHERE rollno='$rollno'";
$result=mysqli_query($con,$sql);
$mark="SELECT * FROM marks WHERE rollno='$rollno'";
$resultMark=mysqli_query($con,$mark);


if($row=mysqli_fetch_assoc($result)){

    // echo $row;
    echo "name : ".$row["name"]."<br>";
    echo "rollno : ".$row["rollno"]."<br>";
    echo "address : ".$row["address"]."<br>";
    echo "phone : ".$row["phone"]."<br>";
    // echo "marks:";
    // echo "English :".$marks["english"];
    // echo "Maths :".$marks["maths"];
    // echo "Science :".$marks["science"];
}
if($marks=mysqli_fetch_assoc($resultMark)){

    echo "marks:"."<br>";
    echo "English :".$marks["english"]."<br>";
    echo "Maths :".$marks["maths"]."<br>";
    echo "Science :".$marks["science"]."<br>";
}
}
?>

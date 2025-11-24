<?php
$rollno=$_GET["rollno"];
$con=mysqli_connect("localhost","root","","student");
if(!$con){
    die("not connected");
}
$sql="SELECT * FROM students WHERE rollno=$rollno";
$result=mysqli_query($con,$sql);
if($row=mysqli_fetch_assoc($result)){
    $rollno=$row["rollno"];
    $name=$row["name"];
    $address=$row["address"];
    $phone=$row["phone"];
}

if(isset($_POST["submit"])){

    $newName=$_POST["name"];
    $newrollno=$_POST["rollno"];
    $newaddress=$_POST["address"];
    $newphone=$_POST["phone"];

    
    $upd="UPDATE students SET name='$newName' , rollno='$newrollno' , address='$newaddress' , phone='$newphone' WHERE rollno='$rollno'";

    if(mysqli_query($con,$upd)){
        echo "updated data successfully";
    }
}

?>

<h3>Update Data</h3>
<form method="post">
    Name:
    <input type="text" name="name" value="<?php echo $name; ?>" required>

    <br><br>
    Roll No:
    <input type="number" name="rollno" value="<?php echo $rollno; ?>" required>
    <br><br>
    Address:
    <input type="textarea" name="address" value="<?php echo $address; ?>" required>
    <br><br>
    Phone No:
    <input type="number" name="phone" value="<?php echo $phone; ?>" required>
    <br><br>
    <input type="submit" name="submit" value="submit">

    

</form>
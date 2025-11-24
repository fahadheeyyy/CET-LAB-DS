<?php
if(isset($_POST['username']) && isset($_POST['password']) && !isset($_POST['update'])){
    $username=$_POST['username'];
    $password=$_POST['password'];

    $dbcon=mysqli_connect("localhost","root","","student");
    if(!$dbcon){
        die("connection failed:".mysqli_connect_error()); 
    }
    else{
        echo "connected successfully<br>";
    }

    $sql="SELECT * FROM stud_login WHERE username='$username' AND password='$password'";
    $result=mysqli_query($dbcon,$sql);

    $checkRoll="SELECT rollno FROM stud_login WHERE username='$username' AND password='$password'";
    $roll=mysqli_query($dbcon,$checkRoll);

    if(mysqli_num_rows($result)>0){
        while($row=mysqli_fetch_assoc($result)){
            echo "<br>"."Roll No: ".$row['rollno']."<br>"." Name: ".$row['name']."<br>";
        }
    }
    else{
        die("invalid credentials");
    }

    $rollno=mysqli_fetch_assoc($roll)['rollno'];

    echo "<h3>You selected Roll Number: $rollno</h3>";
}
    ?>
    <form method="post" action="">
            <input type="hidden" name="rollno" value="<?php echo $rollno; ?>">
            mark1:
            <input type="number" name="mark1" ><br><br>
            mark2:
            <input type="number" name="mark2"><br><br>
            <input type="submit" name="update" value="Update Data">
    </form>
<?php
if (isset($_POST['update'])) {
    // Get data from form
    $rollno = $_POST['rollno'];  // <-- Make sure your form has an input named 'rollno'
    $mark1 = $_POST['mark1'];
    $mark2 = $_POST['mark2'];
    $total = $mark1 + $mark2;

    // Database connection
    include 'dbconnect.php'; // make sure $dbcon is defined here

    // If your table has 4 columns (rollno, mark1, mark2, total)
    $insertQuery = "INSERT INTO mark (rollno, mark1, mark2, total) VALUES ('$rollno', '$mark1', '$mark2', '$total')";

    // Execute query once
    if (mysqli_query($dbcon, $insertQuery)) {
        echo "Marks inserted successfully<br>";
    } else {
        echo "Error: " . mysqli_error($dbcon);
    }

    // Example of update query (if you want to update instead of insert)
    // $updateQuery = "UPDATE mark SET mark1='$mark1', mark2='$mark2', total='$total' WHERE rollno='$rollno'";

    // if (mysqli_query($dbcon, $updateQuery)) {
    //     echo "Record updated successfully";
    // } else {
    //     echo "Error updating record: " . mysqli_error($dbcon);
    // }
}
?>

   
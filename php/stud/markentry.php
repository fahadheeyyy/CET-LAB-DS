<?php
$showForm = false;

if(isset($_POST['show'])){
    $rollno = $_POST['rollno'];

    $con = mysqli_connect("localhost", "root", "", "student");
    $query = "SELECT * FROM students WHERE rollno = '$rollno'";
    $res=mysqli_query($con, $query);
    $check="SELECT * FROM marks WHERE rollno=$rollno";
    $result=mysqli_query($con,$check);
    if(mysqli_num_rows($result)>0){
        die("Mark already inserted!");
    }
    else{
    if ($row = mysqli_fetch_assoc($res) ) {
        $showForm = true;
        echo "<h3>Entering marks for Roll Number: $rollno</h3>";
    }
    else {
        echo "No student found with Roll Number: $rollno";
    }
    }
    
}

?>

<?php if (!$showForm) { ?>
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
    <input type="submit" name="show" value="Submit">
</form>
<?php } ?>

<?php if ($showForm) { ?>
    <form method="post" action="">
        <input type="hidden" name="rollno" value="<?php echo $rollno; ?>">
        Science:
        <input type="number" name="Science" required><br><br>
        English:
        <input type="number" name="English" required><br><br>
        Math:
        <input type="number" name="Math" required><br><br>
        <input type="submit" name="submit" value="Update Data">
    </form>
<?php } ?>

<?php
if (isset($_POST['submit'])) {
    $rollno = $_POST['rollno'];  
    $Science = $_POST['Science'];
    $English = $_POST['English'];
    $Math = $_POST['Math'];

    echo $Science;
    echo $Math;
    echo $English;



    $dbcon = mysqli_connect("localhost", "root", "", "student");
    if (!$dbcon) {
        die("Connection failed: " . mysqli_connect_error());
    }


    $insertQuery = "INSERT INTO marks (rollno, science, maths ,english) VALUES ('$rollno', '$Science', '$English', '$Math')";

    if (mysqli_query($dbcon, $insertQuery)) {
        echo "Marks inserted successfully<br>";
    } else {
        echo "Error: " . mysqli_error($dbcon);
    }
}
?>



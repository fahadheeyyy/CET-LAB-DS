<?php

$rollno = $_GET['rollno'];
$showForm = true;

$con = mysqli_connect("localhost", "root", "", "student");
if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}

if(isset($_POST['submit'])) {

$showForm = false;

$sql = "DELETE FROM students WHERE rollno = '$rollno'";
if (mysqli_query($con, $sql)) {
    echo "Record deleted successfully.";
} else {
    echo "Error deleting record: " . mysqli_error($con);
}
}
?>

<?php 
if ($showForm) {
?>
<h3>Do you want to delete the record of Roll Number: <?php echo $rollno; ?>?</h3>
<form method="post" action="">
        <input type="hidden" name="rollno" value="<?php echo $rollno ?>">
        <button type="submit" name="submit">Yes, delete</button>
        <a href="update_delete.php">Cancel</a>
</form>
<?php
}
?>
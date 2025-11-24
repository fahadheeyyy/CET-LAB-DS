<?php
$con = mysqli_connect("localhost", "root", "", "student");

if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}
echo "Connected successfully<br>";

$sq = "SELECT rollno FROM stud1";
$result = mysqli_query($con, $sq);
?>

<form method="post" action="">
    <label>Select Roll Number:</label>
    <select name="rollno">
        <?php
        while ($rows = mysqli_fetch_assoc($result)) {
            echo "<option value='".$rows['rollno']."'>".$rows['rollno']."</option>";
        }
        ?>
    </select>

    <input type="submit" name="show" value="Submit">
</form>

<?php



if (isset($_POST['rollno'])) {
    $selected_rollno = $_POST['rollno'];  

    echo "<h3>You selected Roll Number: $selected_rollno</h3>";

    $query = "SELECT * FROM stud1 WHERE rollno = '$selected_rollno'";
    $data = mysqli_query($con, $query);

    if ($row = mysqli_fetch_assoc($data)) {
        echo "Name: " . $row['name'] . "<br>";
        echo "gender: " . $row['gender'] . "<br>";
    }
}

if (isset($_POST['show']) && !empty($_POST['rollno'])) {
    $rollno = $_POST['rollno'];

    $query = "SELECT * FROM stud1 WHERE rollno = '$rollno'";
    $data = mysqli_query($con, $query);

    if ($row = mysqli_fetch_assoc($data)) {
        ?>
        <form method="post" action="">
            <input type="hidden" name="rollno" value="<?php echo $row['rollno']; ?>">
            mark1:
            <input type="number" name="mark1" value="<?php echo $row['mark1']; ?>"><br><br>
            mark2:
            <input type="number" name="mark2" value="<?php echo $row['mark2']; ?>"><br><br>

            <input type="submit" name="update" value="Update Data">
        </form>
        <?php
    } else {
        echo "<p>No record found for roll number $rollno.</p>";
    }
}

if (isset($_POST['update'])) {
    $rollno = $_POST['rollno'];
    $mark1 = $_POST['mark1'];
    $mark2 = $_POST['mark2'];
    $total = $mark1 + $mark2;

    $update_query = "UPDATE stud1 SET mark1='$mark1', mark2='$mark2', total='$total' WHERE rollno='$rollno'";

    if (mysqli_query($con, $update_query)) {
        echo "update aayi";
    } else {
        echo "update aavnilla: " . mysqli_error($con);
    }
}

mysqli_close($con);
?>

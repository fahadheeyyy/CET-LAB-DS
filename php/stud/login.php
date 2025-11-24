

<h2>Login</h2>
<form  method="post">
    Enter Username:
    <input type="text" name="username" required>
    <br><br>
    Enter Password:
    <input type="password" name="password" required>
    <br><br>
    <input type="submit" name="login" value="Submit">
</form>

<?php

if(isset($_POST['login'])){
$username = $_POST['username'] ;
$password = $_POST['password'] ;

$con = mysqli_connect("localhost", "root", "", "student");

if (!$con) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "SELECT * FROM login WHERE username='$username' AND password='$password'";

if (mysqli_query($con, $sql)) {
    $result = mysqli_query($con, $sql);
    if (mysqli_num_rows($result) > 0) {
       header("Location: admin_home.php");
    } else {
        echo "Invalid username or password.";
    }
}
else {
    echo "Error: " . mysqli_error($con);
}
}
?>
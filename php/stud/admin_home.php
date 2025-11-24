<?php session_start(); ?>
<!DOCTYPE html>
<html>
<head>
    <style>
        .sidebar{
            height: 100vh;
            width: 200px;
            position: fixed;
            top: 0;
            left: 0;
            background-color: #ccc;
            padding-top: 20px;
            display: flex;
            flex-direction: column;
            align-items: flex-start;
            gap: 10px;

            a{
                padding: 10px;
                text-decoration: none;
                color: black;
                width: 100%;
            }
        }
        .content{
            margin-left: 250px;
            padding: 20px;
            height: 90vh;
        }
            iframe{
                border: none;
                scrollbar-width: none;
                width: 100%;
                height: 100%;
            }
        
    </style>
</head>
<body>

<div class="container">

    <div class="sidebar">
        <h2 style="text-align:center;">Admin Menu</h2>

        <a href="student_register.php" target="rightFrame">Student Registration</a>
        <a href="markentry.php" target="rightFrame">Make Entry</a>
        <a href="markupdate.php" target="rightFrame">Mark Update</a>
        <a href="update_delete.php" target="rightFrame">Delete / Update Student</a>
        <a href="progress_card.php" target="rightFrame">View Progress Card</a>
    </div>

    <div class="content">
        <iframe name="rightFrame" src="student_register.php"></iframe>
    </div>

</div>

</body>
</html>

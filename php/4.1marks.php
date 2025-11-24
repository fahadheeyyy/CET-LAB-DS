<?php
if (isset($_GET['submit'])) {
    $name = $_GET['name'];
    $age = $_GET['age'];
    $eng = $_GET['eng-mark'];
    $maths = $_GET['maths-mark'];
    $cs = $_GET['cs-mark'];
    $total = $_GET['total'];
    $percentage = $_GET['percentage'];
    $grade = $_GET['grade'];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo htmlspecialchars($name); ?>'s Progress Card</title>
    <style>
        body {
            font-family: "Poppins", sans-serif;
            /* background: linear-gradient(120deg, #89f7fe, #66a6ff); */
            min-height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .card {
            background: white;
            padding: 30px 50px;
            border-radius: 12px;
            /* box-shadow: 0 4px 10px rgba(0,0,0,0.2); */
            width: 420px;
        }
        h1 {
            text-align: center;
            margin-bottom: 10px;
            color: #333;
        }
        h3 {
            text-align: center;
            margin-top: 0;
            color: #666;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 25px;
        }
        th, td {
            border: 1px solid #ddd;
            text-align: center;
            padding: 10px;
        }
        th {
            background-color: #0078d4;
            color: white;
        }
        .summary {
            text-align: center;
            margin-top: 20px;
            font-size: 1.1em;
        }
        .grade {
            font-weight: bold;
            color: <?php
                if ($grade == "Fail") echo "red";
                else if ($grade == "A+" || $grade == "A") echo "green";
                else echo "#0078d4";
            ?>;
        }
    </style>
</head>
<body>

<div class="card">
    <h1>Progress Card</h1>
    <h3><?php echo htmlspecialchars($name); ?> (Roll No: <?php echo htmlspecialchars($age); ?>)</h3>

    <table>
        <tr>
            <th>Subject</th>
            <th>Mark</th>
        </tr>
        <tr><td>English</td><td><?php echo htmlspecialchars($eng); ?></td></tr>
        <tr><td>Maths</td><td><?php echo htmlspecialchars($maths); ?></td></tr>
        <tr><td>Computer Science</td><td><?php echo htmlspecialchars($cs); ?></td></tr>
        <tr><th>Total</th><th><?php echo htmlspecialchars($total); ?></th></tr>
    </table>

    <div class="summary">
        <p>Percentage: <b><?php echo htmlspecialchars($percentage); ?>%</b></p>
        <p class="grade">Grade: <?php echo htmlspecialchars($grade); ?></p>
    </div>
</div>

</body>
</html>
<?php
} else {
    echo "No data submitted!";
}
?>

<?php
$str= "            `hello Fahad`     ";

$len = strlen($str);
$rep = str_replace("hello","hi",$str);
$low = strtolower($str);
$rev = strrev($str);
$tr=trim($str);

echo "string is :".$str."<br>" .$len . "<br>" . $rep . "<br>" . $low . "<br>" . $rev . "<br>"  . $tr . "<br>" ;
?>
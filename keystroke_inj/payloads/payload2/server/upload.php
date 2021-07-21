<?php
$file = date("H-i-s-m") . ".txt";
file_put_contents($file, file_get_contents("php://input"));
?>

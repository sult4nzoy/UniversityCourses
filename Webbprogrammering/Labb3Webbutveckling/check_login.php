<?php
session_start();

$user = $_POST['username'];
$pass = $_POST['password'];

if ($user == "omar" && $pass == "hemligt") {
    $_SESSION['username'] = $user;
    header("Location: index.php");
    exit;
} 
else {
    echo "Fel användarnamn eller lösenord!";
}
?>
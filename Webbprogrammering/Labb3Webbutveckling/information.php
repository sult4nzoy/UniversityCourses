<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: loginPage.php");
    exit;
}

include("header.html");
include("displayInfoAboutUser.php");
?>

<h2>Din information:</h2>
<?php
display_visitor_info();
?>

<?php
include("footer.html");
?>
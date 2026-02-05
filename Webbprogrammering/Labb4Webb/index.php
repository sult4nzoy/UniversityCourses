<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit;
}

require_once "guestBookDel1.php";

include("header.html");
?>

<main>
    <h2>Besökarnas Gästbok</h2>
    
    <form action="index.php" method="post">
        <p>
            Namn:<br>
            <input type="text" name="alias" required>
        </p>
        <p>
            Inlägg:<br>
            <textarea name="entry" required></textarea>
        </p>
        <p>
            <input type="submit" name="publicera" value="Publicera inlägg">
        </p>
    </form>

    <hr>

<?php
include("footer.html");
?>
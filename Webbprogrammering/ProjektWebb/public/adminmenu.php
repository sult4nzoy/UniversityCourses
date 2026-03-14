<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida är adminpanelen där administratörer kan välja att lägga till produkter, 
hantera produkter, visa ordrar eller hantera användare. Den är endast tillgänglig för administratörer.
*/

session_start();

if (!isset($_SESSION['user_rights']) || $_SESSION['user_rights'] != 'admin') {
    header("Location: index.php");
    exit;
}

include '../includes/adminheader.html';
?>

<div class="container">
    <h1>Adminpanel</h1>
    <hr>
    <a href="addproduct.php" class="btn">Lägg till produkt</a>
    <a href="manageproducts.php" class="btn">Hantera produkter</a>
    <a href="manageorders.php" class="btn">Hantera ordrar</a>
    <a href="manageusers.php" class="btn">Hantera användare</a>
</div>

<?php include '../includes/footer.html'; ?>
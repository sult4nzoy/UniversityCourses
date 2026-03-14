<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar registrering av nya användare. Den är tillgänglig för alla användare.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/users.php';

if (isset($_POST['register_btn'])) {
    $dbObj = new Database();
    $db = $dbObj->getConnection();
    $userHandler = new User($db);

    $fn = $_POST['username'];
    $ln = $_POST['last_name'];
    $em = $_POST['email'];
    $pw = $_POST['password'];

    $userHandler->register($fn, $ln, $em, $pw);

    $_SESSION['user_id'] = $db->lastInsertId(); 
    $_SESSION['username'] = $fn;
    $_SESSION['user_rights'] = 'regular';

    header("Location: index.php");
    exit;
}
include '../includes/loginheader.html';
?>

<div class="container">
    <form method="post">
        <h2>Skapa konto</h2>
        <input type="text" name="username" placeholder="Förnamn" required>
        <input type="text" name="last_name" placeholder="Efternamn" required>
        <input type="email" name="email" placeholder="E-post" required>
        <input type="password" name="password" placeholder="Lösenord" required>
        <button type="submit" name="register_btn">Registrera mig</button>
    </form>
</div>
<?php include '../includes/footer.html'; ?>
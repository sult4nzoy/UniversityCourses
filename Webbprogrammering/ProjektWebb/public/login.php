<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar inloggning av användare. Den är tillgänglig för alla användare.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/users.php';

include '../includes/loginheader.html';
$db = (new Database())->getConnection();
$userHandler = new User($db);

if (isset($_SESSION['username'])) {
    header("Location: index.php");
    exit;
}

if (isset($_POST['login_btn'])) {

    $user = $userHandler->login($_POST['username'], $_POST['password']);

    if ($user) {

        $_SESSION['user_id'] = $user['user_id'];
        $_SESSION['username'] = $user['user_first_name']; 
        $_SESSION['user_rights'] = $user['user_rights'];
        $_SESSION['email'] = $user['user_email'];

        header("Location: index.php");
        exit;
    } else {
        echo "<p style='color:red;'>Fel e-post eller lösenord!</p>";
    }
}
?>

<div class="container">
    <form method="post">
        <h2>Logga in</h2>
        <label>E-postadress</label>
        <input type="email" name="username" placeholder="din@mail.se" required>
        
        <label>Lösenord</label>
        <input type="password" name="password" placeholder="Lösenord" required>
        
        <button type="submit" name="login_btn">Logga in</button>
    </form>
    <p>Inget konto? <a href="register.php">Registrera dig här</a></p>
</div>

<?php include '../includes/footer.html'; ?>
<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: En enkel informationssida om skaparen av webbplatsen.
*/
session_start();

if (isset($_SESSION['user_id'])) {
    if (isset($_SESSION['user_rights']) && $_SESSION['user_rights'] == 'admin') {
        include '../includes/adminheader.html';
    } else {
        include '../includes/header.html';
    }
} else {
    include '../includes/loginheader.html';
}
?>

<div class="container">
    <h2>Om utvecklaren</h2>
    <hr>

    <div style="line-height: 1.6; padding: 20px 0;">
        <p><strong>Namn:</strong> Omar Sultanzoy</p>
        <p><strong>E-post:</strong> <a href="mailto:omsu2400@student.miun.se">omsu2400@student.miun.se</a></p>
        <p><strong>Kurs:</strong> Webbutveckling - Projektarbete</p>
        <p><strong>Universitet:</strong> Mittuniversitetet (MIUN)</p>
        <p><strong>Kursansvariga:</strong> Mikael Hasselmalm & Jan-Erik Jonsson</p>
    </div>

    <div style="margin-top: 20px;">
        <a href="login.php" class="btn" style="width:auto;">Tillbaka till login</a>
    </div>
</div>

<?php include '../includes/footer.html'; ?>
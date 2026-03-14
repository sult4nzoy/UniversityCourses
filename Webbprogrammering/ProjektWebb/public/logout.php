<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar utloggning av användare. Den är tillgänglig för alla användare.
*/
session_start();
session_destroy();
header("Location: login.php");
exit;
?>
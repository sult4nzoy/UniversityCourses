<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: loginPage.php");
    exit;
}

include("header.html");
?>

<h1>Välkommen, <?php echo $_SESSION['username']; ?>!</h1>

<h2>Detta är startsidan</h2>

<h3>1. Har du tidigare erfarenhet av utveckling med PHP?</h3>
<p>Svar: Nej</p>

<h3>2. Hur har du valt att strukturera upp dina filer och kataloger?</h3>
<p>Svar: Jag har valt att skapa en mapp som heter Labb3Webbutveckling i denna path: C:\xampp\htdocs\Labb3Webbutveckling. Jag har valt att dela upp min kod till en god grad för att förenkla laborationen då det blir enklare att följa koden när man har det strukturerat.</p>

<h3>3. Har du följt guiden, eller skapat på egen hand?</h3>
<p>Svar: Jag har inte följt guiden. De enda verktygen jag använt är Google (W3Schools) och YouTube.</p>

<h3>4. Har du gjort några förbättringar eller vidareutvecklingar av guiden?</h3>
<p>Svar: Eftersom jag inte följt guiden har jag inte gjort några direkta förbättringar på just den, men jag har skapat en egen struktur.</p>

<h3>5. Vilken utvecklingsmiljö har du använt för uppgiften (Editor, webbserver etcetera)?</h3>
<p>Svar: Visual Studio Code och XAMPP (Apache).</p>

<h3>6. Har något varit svårt med denna uppgift?</h3>
<p>Svar: Nej.</p>

<?php
include("footer.html");
?>
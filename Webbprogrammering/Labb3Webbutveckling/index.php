
<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: loginPage.php");
    exit;
}
include("header.html");
?>

<main>
    <h1>Välkommen! Du är nu inloggad, <?php echo $_SESSION['username']; ?></h1>
    <h1>Detta är startsidan!</h1>
    
    <h3>1. Har du tidigare erfarenhet av utveckling med PHP?</h3>
    <h4>Svar: Nej</h4>

    <h3>2. Hur har du valt att strukturera upp dina filer och kataloger?</h3>
    <h4>Svar: Jag har valt att skapa en mapp som heter Labb3Webbutveckling i denna path: C:\xampp\htdocs\Labb3Webbutveckling. Jag har valt att dela upp min kod till en god grad för att förenkla laborationen då det blir enklare att följa koden när man har det strukturerat.</h4>

    <h3>3. Har du följt guiden, eller skapat på egen hand?</h3>
    <h4>Svar: Jag har inte följt guiden. Dom ända verktygen jag använt är Google (W3Schools) och YouTube.</h4>

    <h3>4. Har du gjort några förbättringar eller vidareutvecklingar av guiden (om du följt denna)?</h3>
    <h4>Svar: Eftersom jag inte följt guiden har jag inte gjort några direkta förbättringar på just den, men jag har skapat en egen struktur.</h4>

    <h3>5. Vilken utvecklingsmiljö har du använt för uppgiften (Editor, webbserver etcetera)?</h3>
    <h4>Svar: Visual Studio Code.</h4>

    <h3>6. Har något varit svårt med denna uppgift?</h3>
    <h4>Svar: Nej.</h4>
</main>

<?php
include("footer.html");
?>
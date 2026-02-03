<?php
include("header.html");
?>

<main>
    <h2>Logga in</h2>
    <form action="check_login.php" method="post">
        <p>
            Användarnamn:<br>
            <input type="text" name="username" required>
        </p>
        <p>
            Lösenord:<br>
            <input type="text" name="password" required>
        </p>
        <p>
            <input type="submit" value="Logga in">
        </p>
    </form>
</main>

<?php
include("footer.html");
?>
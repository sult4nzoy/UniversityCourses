<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar hantering av användare i databasen. Den är endast tillgänglig för administratörer.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/users.php';

$db = (new Database())->getConnection();
$userHandler = new User($db);

if (!isset($_SESSION['user_rights']) || $_SESSION['user_rights'] != 'admin') {
    header("Location: index.php");
    exit;
}

if (isset($_POST['save_user'])) {
    $userHandler->updateUser($_POST['user_id'], $_POST['user_first_name'], $_POST['user_last_name'], $_POST['user_email'], $_POST['user_password'], $_POST['user_rights']);
    header("Location: manageusers.php");
    exit;
}

if (isset($_POST['delete_user'])) {
    $userHandler->deleteUser($_POST['delete_user']);
    header("Location: manageusers.php");
    exit;
}

$users = $userHandler->getAllUsers();
include '../includes/adminheader.html';
?>

<div class="container">
    <h2>Hantera användare</h2>
    <hr>
    <table class="admin-table">
        <thead>
            <tr>
                <th>Förnamn</th>
                <th>Efternamn</th>
                <th>E-post</th>
                <th>Lösenord</th>
                <th>Behörighet</th>
                <th>Spara</th>
                <th>Ta bort</th>
            </tr>
        </thead>
        <?php foreach ($users as $u): ?>
        <tr>
            <form method="post">
                <input type="hidden" name="user_id" value="<?php echo $u['user_id']; ?>">
                <td><input type="text" name="user_first_name" value="<?php echo $u['user_first_name']; ?>"></td>
                <td><input type="text" name="user_last_name" value="<?php echo $u['user_last_name']; ?>"></td>
                <td><input type="email" name="user_email" value="<?php echo $u['user_email']; ?>"></td>
                <td><input type="text" name="user_password" value="<?php echo $u['user_password']; ?>"></td>
                <td>
                    <select name="user_rights">
                        <option value="regular" <?php if($u['user_rights'] == 'regular') echo 'selected'; ?>>Kund</option>
                        <option value="admin" <?php if($u['user_rights'] == 'admin') echo 'selected'; ?>>Admin</option>
                    </select>
                </td>
                <td><button type="submit" name="save_user" class="btn" style="width:auto; margin:0;">OK</button></td>
                <td>
                    <button type="submit" name="delete_user" value="<?php echo $u['user_id']; ?>" style="color:red; background:none; border:none;">Ta bort</button>
                </td>
            </form>
        </tr>
        <?php endforeach; ?>
    </table>
</div>

<?php include '../includes/footer.html'; ?>
<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida visar en användares tidigare beställningar. Den är endast tillgänglig för registrerade användare.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/order.php';

$db = (new Database())->getConnection();
$orderHandler = new Order($db);

if (!isset($_SESSION['user_rights'])) {
    header("Location: index.php");
    exit;
}

$orders = $orderHandler->getOrdersByUserId($_SESSION['user_id']);

if(isset($_SESSION['user_rights']) && $_SESSION['user_rights'] == 'admin') {
    include '../includes/adminheader.html';
} else {
    include '../includes/header.html';
}
?>

<div class="container">
    <h2>Mina Beställningar</h2>
    <hr>

    <table class="admin-table">
        <thead>
            <tr>
                <th>Order ID</th>
                <th>Totalpris (kr)</th>
                <th>Status</th>
            </tr>
        </thead>
        <tbody>
            <?php if (!empty($orders)): ?>
                <?php foreach ($orders as $o): ?>
                    <tr>
                        <td><?php echo $o['order_id']; ?></td>
                        <td><?php echo $o['order_total']; ?> kr</td>
                        <td><?php echo $o['order_status']; ?></td>
                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="3" style="text-align:center; padding:20px;">Du har inga tidigare beställningar.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div>

<?php include '../includes/footer.html'; ?>
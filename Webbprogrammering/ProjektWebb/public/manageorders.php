<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar hantering av ordrar i databasen. Den är endast tillgänglig för administratörer.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/order.php';
require_once '../src/classes/product.php';

$db = (new Database())->getConnection();
$orderHandler = new Order($db);
$productHandler = new Product($db);

if (!isset($_SESSION['user_rights']) || $_SESSION['user_rights'] != 'admin') {
    header("Location: index.php");
    exit;
}

if (isset($_POST['update_status'])) {
    $orderHandler->updateOrderStatus($_POST['order_id'], $_POST['status']); 
    header("Location: manageorders.php");
    exit;
}

if (isset($_POST['delete_order'])) {
    $orderHandler->deleteOrder($_POST['order_id']);
    header("Location: manageorders.php");
    exit;
}

$orders = $orderHandler->getAllOrders();
include '../includes/adminheader.html';
?>

<div class="container">
    <h2>Hantera ordrar</h2>
    <hr>
    <table class="admin-table">
        <thead>
            <tr>
                <th>Order ID</th>
                <th>Kund ID</th>
                <th>Totalpris</th>
                <th>Betalstatus</th>
                <th>Innehåll</th>
                <th>Åtgärd</th>
            </tr>
        </thead>
        <tbody>
            <?php if (!empty($orders)): ?>
                <?php foreach ($orders as $o): ?>
                    <tr>
                        <td>#<?php echo $o['order_id']; ?></td>
                        <td><?php echo $o['user_id']; ?></td>
                        <td><strong><?php echo $o['order_total']; ?> kr</strong></td>
                        <td>
                            <form method="post" style="display:inline;">
                                <input type="hidden" name="order_id" value="<?php echo $o['order_id']; ?>">
                                <select name="status">
                                    <option value="Betald" <?php if($o['order_status'] == 'Betald') echo 'selected'; ?>>Betald</option>
                                    <option value="Obetald" <?php if($o['order_status'] == 'Obetald') echo 'selected'; ?>>Ej betald</option>
                                </select>
                                <button type="submit" name="update_status" class="btn" style="width:auto; margin:0; padding: 2px 10px;">OK</button>
                            </form>
                        </td>
                        <td>
                            <?php 
                            $items = $orderHandler->getItemsByOrderId($o['order_id']);
                            foreach ($items as $item) {
                                $p = $productHandler->getProductById($item['product_id']);
                                echo $item['quantity'] . "x " . ($p['product_name'] ?? 'Borttagen produkt') . "<br>";
                            }
                            ?>
                        </td>
                        <td>
                            <form method="post" style="display:inline;">
                                <input type="hidden" name="order_id" value="<?php echo $o['order_id']; ?>">
                                <button type="submit" name="delete_order" style="color:red; background:none; border:none; cursor:pointer;">Ta bort</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="6" style="text-align:center;">Inga ordrar hittades.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div>

<?php include '../includes/footer.html'; ?>
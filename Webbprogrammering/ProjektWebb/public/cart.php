<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida visar produkterna i kundvagnen och hanterar borttagning av produkter från kundvagnen.
Den är tillgänglig för alla användare.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/product.php';

$db = (new Database())->getConnection();
$productHandler = new Product($db);

if (isset($_POST['product_id'])) {
    $id = $_POST['product_id'];
    $_SESSION['cart'][$id] = ($_SESSION['cart'][$id] ?? 0) + 1;
    header("Location: cart.php");
    exit;
}

if (isset($_GET['remove'])) {
    unset($_SESSION['cart'][$_GET['remove']]);
    header("Location: cart.php");
    exit;
}

if (isset($_SESSION['user_rights']) && $_SESSION['user_rights'] == 'admin') {
    include '../includes/adminheader.html';
} else {
    include '../includes/header.html';
}
?>

<div class="container">
    <h2>Kundvagn</h2>
    <hr>
    <?php if (!empty($_SESSION['cart'])): ?>
        <table class="admin-table">
            <thead>
                <tr>
                    <th>Bild</th>
                    <th>Produkt</th>
                    <th>Antal</th>
                    <th>Summa</th>
                    <th>Hantera</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $total = 0;
                foreach ($_SESSION['cart'] as $id => $qty):
                    $p = $productHandler->getProductById($id);
                    $sum = $p['product_price'] * $qty;
                    $total += $sum;
                ?>
                    <tr>
                        <td><img src="../../writeable/images/<?php echo $p['product_image']; ?>" width="50" style="border-radius:4px;"></td>
                        <td><?php echo $p['product_name']; ?></td>
                        <td><?php echo $qty; ?> st</td>
                        <td><?php echo $sum; ?> kr</td>
                        <td><a href="cart.php?remove=<?php echo $id; ?>" style="color:red; text-decoration:none;">Ta bort</a></td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>

        <p style="font-size: 1.2em; margin-top: 20px;"><strong>Totalt att betala: <?php echo $total; ?> kr</strong></p>

        <form method="post" action="stripe_pay.php">
            <button type="submit" class="btn" style="width:auto;">Gå till kassan</button>
        </form>

    <?php else: ?>
        <div style="text-align:center; padding: 40px 0;">
            <h3>Din kundvagn är tom</h3>
            <br>
            <a href="index.php" class="btn" style="width:auto;">Tillbaka till butiken</a>
        </div>
    <?php endif; ?>
</div>

<?php include '../includes/footer.html'; ?>
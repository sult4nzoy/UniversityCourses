<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar hantering av produkter i databasen. Den är endast tillgänglig för administratörer.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/product.php';

$db = (new Database())->getConnection();
$productHandler = new Product($db);

if (!isset($_SESSION['user_rights']) || $_SESSION['user_rights'] != 'admin') {
    header("Location: index.php");
    exit;
}

if (isset($_POST['save_changes'])) {
    $productHandler->updateProduct($_POST['product_id'], $_POST['product_name'], $_POST['product_price'], $_POST['product_stock']);
    header("Location: manageproducts.php");
    exit;
}

if (isset($_POST['delete'])) {
    $productHandler->deleteProduct($_POST['delete']);
    header("Location: manageproducts.php");
    exit;
}

$products = $productHandler->getAllProducts();
include '../includes/adminheader.html';
?>

<div class="container">
    <h2>Hantera produkter</h2>
    <a href="addproduct.php" class="btn" style="width:auto;">+ Lägg till produkt</a>
    <hr>

    <table class="admin-table">
        <thead>
            <tr>
                <th>Bild</th>
                <th>Produktnamn</th>
                <th>Pris (kr)</th>
                <th>Lagersaldo</th>
                <th>Spara</th>
                <th>Radera</th>
            </tr>
        </thead>
        <tbody>
            <?php if (!empty($products)): ?>
                <?php foreach ($products as $p): ?>
                    <tr>
                        <form method="post">
                            <input type="hidden" name="product_id" value="<?php echo $p['product_id']; ?>">

                            <td><img src="../../writeable/images/<?php echo $p['product_image']; ?>" width="50" style="border-radius:4px;"></td>

                            <td><input type="text" name="product_name" value="<?php echo $p['product_name']; ?>"></td>

                            <td><input type="number" name="product_price" value="<?php echo $p['product_price']; ?>"></td>

                            <td><input type="number" name="product_stock" value="<?php echo $p['product_stock']; ?>"></td>

                            <td><button type="submit" name="save_changes" class="btn" style="width:auto; margin:0; padding:5px 10px;">OK</button></td>

                            <td>
                                <button type="submit" name="delete" value="<?php echo $p['product_id']; ?>"
                                    style="color:red; background:none; border:none; cursor:pointer;">Ta bort</button>
                            </td>
                        </form>
                    </tr>
                <?php endforeach; ?>
            <?php else: ?>
                <tr>
                    <td colspan="6" style="text-align:center; padding:20px;">Inga produkter hittades i databasen.</td>
                </tr>
            <?php endif; ?>
        </tbody>
    </table>
</div>
<?php include '../includes/footer.html'; ?>
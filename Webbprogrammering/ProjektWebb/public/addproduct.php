<?php
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/product.php';

$db = (new Database())->getConnection();
$productHandler = new Product($db);

if (!isset($_SESSION['user_rights']) || $_SESSION['user_rights'] != 'admin') {
    header("Location: index.php");
    exit;
}

if (isset($_POST['add_product'])) {
    $n = $_POST['p_name'];
    $d = $_POST['p_desc'];
    $p = $_POST['p_price'];
    $s = $_POST['p_stock'];
    $img = $_FILES['p_image']['name'];

    $targetPath = "../../writeable/images/" . $img;

    if (move_uploaded_file($_FILES['p_image']['tmp_name'], $targetPath)) {
        $productHandler->addProduct($n, $d, $p, $s, $img);
        header("Location: manageproducts.php");
        exit;
    } else {
        echo "Uppladdning misslyckades.";
    }
}

include '../includes/adminheader.html';
?>

<div class="container">
    <form method="post" enctype="multipart/form-data">
        <h2>Lägg till produkt</h2>
        <input type="text" name="p_name" placeholder="Produktnamn" required>
        <textarea name="p_desc" placeholder="Beskrivning"></textarea>
        <input type="number" name="p_price" placeholder="Pris" required>
        <input type="number" name="p_stock" placeholder="Lagersaldo" required>
        <input type="file" name="p_image" required>
        <button type="submit" name="add_product">Spara produkt</button>
    </form>
</div>

<?php include '../includes/footer.html'; ?>
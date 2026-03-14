<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med filen: Denna sida hanterar betalning via Stripe. Den är endast tillgänglig för registrerade användare.
*/
session_start();
require_once '../src/classes/database.php';
require_once '../src/classes/product.php';

$secret_key = 'sk_test_51Syf5KBQXZgMGaGH3YU5KDjAsuHtKmY9a1VY40k4WRaiiMfBE40haAonBUp5FGdBzLCuqEdw9dlRiHUGHnFyWQ0900MO1Hos1q';

$db = (new Database())->getConnection();
$productHandler = new Product($db);

$line_items = [];


foreach ($_SESSION['cart'] as $id => $qty) {
    $p = $productHandler->getProductById($id);

    $line_items[] = [
        'price_data' => [
            'currency' => 'sek',
            'unit_amount' => $p['product_price'] * 100, // Stripe vill ha ören (100kr = 10000)
            'product_data' => [
                'name' => $p['product_name'],
            ],
        ],
        'quantity' => $qty,
    ];
}

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, 'https://api.stripe.com/v1/checkout/sessions');
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, http_build_query([
    'payment_method_types[]' => 'card',
    'line_items' => $line_items,
    'mode' => 'payment',
    'success_url' => 'https://studenter.miun.se/~omsu2400/ProjektWebb/public/checkout.php?success=true',
    'cancel_url' => 'https://studenter.miun.se/~omsu2400/ProjektWebb/public/cart.php',
]));
curl_setopt($ch, CURLOPT_USERPWD, $secret_key . ':');

$result = curl_exec($ch);
$session = json_decode($result, true);
curl_close($ch);

if (isset($session['url'])) {
    header("Location: " . $session['url']);
    exit;
} else {
    echo "Stripe Error: " . $result;
}

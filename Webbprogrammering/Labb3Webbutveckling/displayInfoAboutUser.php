<?php
function display_visitor_info() {
    echo "Datum/klockslag: " . date("Y-m-d H:i:s");

    if (date("l") == "Friday") {
        echo "Äntligen fredag!";
    }
    echo "<br>";
    echo "Din IP-adress: " . $_SERVER['REMOTE_ADDR'] . "<br>";
    echo "Sökväg/filnamn: " . $_SERVER['PHP_SELF'] . "<br>";
    echo "OS info: " . $_SERVER['HTTP_USER_AGENT'] . "<br>";
}
?>
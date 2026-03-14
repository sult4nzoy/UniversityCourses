<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Projektarbete
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Syfte med klassen: Denna klass hanterar användarhantering i databasen. 
Den har funktioner för att registrera en ny användare, logga in en användare, 
hämta användarrättigheter, hämta alla användare, uppdatera en användare och ta 
bort en användare.
*/
class User
{
    private $dbConnection;

    function __construct($dbConnection)
    {
        $this->dbConnection = $dbConnection;
    }

    function register($fname, $lname, $email, $password)
    {
        $createdAt = date('Y-m-d H:i:s');

        $sql = "INSERT INTO users (user_first_name, user_last_name, user_email, user_password, user_account_created_at, user_rights) 
            VALUES ('$fname', '$lname', '$email', '$password', '$createdAt', 'regular')";

        $this->dbConnection->query($sql);
    }

    function login($email, $password)
    {
        return $this->dbConnection->query("SELECT * FROM users WHERE user_email = '$email' AND user_password = '$password'")->fetch(PDO::FETCH_ASSOC);
    }

    function getRights($userId)
    {
        return $this->dbConnection->query("SELECT user_rights FROM users WHERE user_id = $userId")->fetchColumn();
    }

    function getAllUsers()
    {
        return $this->dbConnection->query("SELECT * FROM users")->fetchAll();
    }

    function updateUser($id, $fname, $lname, $email, $password, $rights)
    {
        $sql = "UPDATE users 
            SET user_first_name = '$fname', 
                user_last_name = '$lname', 
                user_email = '$email', 
                user_password = '$password', 
                user_rights = '$rights' 
            WHERE user_id = $id";

        $this->dbConnection->query($sql);
    }
    
    function deleteUser($id)
    {
        $this->dbConnection->query("DELETE FROM users WHERE user_id = $id");
    }

    function getOrdersByUserId($userId)
    {
        return $this->dbConnection->query("SELECT * FROM orders WHERE user_id = $userId")->fetchAll();
    }
}

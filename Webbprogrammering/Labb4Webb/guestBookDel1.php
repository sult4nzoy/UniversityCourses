<?php
/*
Författare: Omar Sultanzoy
Kurs: Webbprogrammering - Laboration 4p
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Senast ändrad: 2026-02-03
*/
class GuestBook
{

    private string $name;
    private string $text;
    private string $date;
    private string $file = "file.txt";
/*
    Konstruktor som kollar på filen för att se om den finns, om inte skapas en ny fil.
    Tar emot namn och text som argument och sätter datumet till nuvarande tid.
*/
    function __construct(string $name, string $text)
    {
        if (!file_exists($this->file)) {
            fopen($this->file, "w");
        }
        $this->name = $name;
        $this->text = $text;
        $this->date = date('Y-m-d H:i:s');
    }

    function __destruct() {}

/*
    Hämtar alla inlägg från filen och returnerar dem som en array.
*/
    function getPosts()
    {
        if (file_exists($this->file)) {
            $posts = file_get_contents($this->file);
            return unserialize($posts);
        }
        return "File doesnt exist";
    }

/*
    Lägger till ett inlägg i filen med namn, text och datum.
*/
    function addPost(string $name, string $text)
    {
        if (file_exists($this->file)) {
            $posts = file_get_contents($this->file);
            $unserielized = unserialize($posts);
            $date = date('Y-m-d H:i:s');
            $newPost = "Name: " . $name . "Text: " . $text . "Date: " . $date;
            $newPostsList = [$unserielized, $newPost];
            $serialized = serialize($newPostsList);
            file_put_contents($this->file, $serialized);
            return "Post added successfully";
        }
        return "File doesnt exist";
    }

/*
    Tar bort ett inlägg baserat på index från filen.
*/
    function deletePost(int $index)
    {
        if (file_exists($this->file)) {
            $posts = file_get_contents($this->file);
            $postsArray = unserialize($posts);
            if (isset($postsArray[$index])) {

                unset($postsArray[$index]);
                $postsArray = array_values($postsArray); // indexera om arrayen till faktiska storleken
                $serializedPosts = serialize($postsArray);
                file_put_contents($this->file, $serializedPosts);
                return "Post deleted successfully";
            } 
            else {
                return "Post not found";
            }
        }
    }
}
<?php
    class GuestBook{
        private int $postId;
        private string $name;
        private string $text;
        private string $date;

        function __construct($id, $name, $text)
        {
            $this->postId = $id;
            $this->name = $name;
            $this->text = $text;
            $this->date = date('Y-m-d H:i:s');
        }

        function __destruct() {}

        function getPost(int $id){


        }

        function addPost(){


        }
        
        function deletePost(int $index){


        }
    }




?>
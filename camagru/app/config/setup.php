<?php

class setup extends Database {
    private $db;

public function __construct()
    {
       try{
            $this->db= new PDO('mysql:host=' . DB_HOST, 'root', 'test');
            }catch(PDOException $e){
                $this->error = $e->getMessage();
                echo $this->error;
            }
        $this->db->exec("CREATE DATABASE IF NOT EXISTS camagru;
                use camagru;
                CREATE table users(
                id int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
                name VARCHAR(255) NOT NULL,
                password VARCHAR(255) NOT NULL,
                email VARCHAR(255) NOT NULL,
                created_at datetime DEFAULT CURRENT_TIMESTAMP,
                token VARCHAR(255) NOT NULL,
                is_validated int(11) NOT NULL DEFAULT '0',
                notifyme int(11) NOT NULL DEFAULT '1');
                CREATE table galleries(
                id int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
                user_id int(11) NOT NULL,
                url VARCHAR(255) NOT NULL,
                created_at datetime DEFAULT CURRENT_TIMESTAMP);
                CREATE table likes(
                id int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
                user_id int(11) NOT NULL,
                img_id int(11) NOT NULL);
                CREATE table comments(
                id int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
                user_id int(11) NOT NULL,
                img_id int(11) NOT NULL,
                comment text NOT NULL,
                created_at datetime DEFAULT CURRENT_TIMESTAMP);
                CREATE table stickers(
                id int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
                url VARCHAR(255) NOT NULL,
                name VARCHAR(255) NOT NULL);
                INSERT INTO `stickers` (id, url, name) VALUES
                (1, '/public/stickers/1337.png', 1337),
                (2, '/public/stickers/42.png', 42),
                (3, '/public/stickers/19.png', 19),
                (4, '/public/stickers/21.png', 21),
                (5, '/public/stickers/101.png', 101),
                (6, '/public/stickers/alem.png', 'alem'),
                (7, '/public/stickers/hive.png', 'hive'),
                (8, '/public/stickers/codam.png', 'codam')
                ");
        
    }
 }
$install = new setup;
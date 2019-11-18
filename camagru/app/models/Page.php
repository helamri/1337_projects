<?php
class Page {
    private $db;

    public function __construct(){
        $this->db = new Database;
    }

    public function getNumber(){
        $this->db->query('SELECT * FROM galleries');
        $row = $this->db->single();
        $count = $this->db->rowCount();
        return $count;
    }
    public function showall($page){
        $this->db->query('SELECT *, galleries.id as galleryId, users.id as userId, galleries.created_at as galleryCreated, users.created_at as userCreated FROM galleries INNER JOIN users ON galleries.user_id = users.id ORDER BY galleries.created_at DESC limit :page,5');
        $this->db->bind(':page', $page);
        $results = $this->db->resultSet();
        return $results;
    }
    public function numberoflikes($img_id){
        $this->db->query("SELECT * from likes where img_id = :img_id");
        $this->db->bind(':img_id', $img_id);
        $row = $this->db->single();
        $count = $this->db->rowCount();
        return $count;
}
public function getcomments($img_id)
{
    $this->db->query("SELECT comment, name FROM comments left join users on users.id = comments.user_id WHERE img_id = :img_id order by comments.created_at desc");
    $this->db->bind(':img_id', $img_id);
    $res = $this->db->resultSet();
    return $res;
}
}
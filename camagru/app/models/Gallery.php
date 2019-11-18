<?php
class Gallery {
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
    public function hiFive(){
        $this->db->query('SELECT *, galleries.id as galleryId, users.id as userId, galleries.created_at as galleryCreated, users.created_at as userCreated FROM galleries INNER JOIN users ON galleries.user_id = users.id WHERE users.id = :user_id ORDER BY galleries.created_at DESC');
        $this->db->bind(':user_id', $_SESSION['user_id']);
        $results = $this->db->resultSet();
        return $results;
    }
    public function insertPhoto($datas){
        if(!empty($_SESSION['user_id'])){
            $this->db->query('INSERT INTO galleries (user_id, url) VALUES(:uid, :url)');
            $this->db->bind(':uid', $_SESSION['user_id']);
            $this->db->bind(':url', $datas);
            if($this->db->execute()){
                return true;
            } else {
                return false;
            }
        }
    }
    public function showall($page){
        $this->db->query('SELECT *, galleries.id as galleryId, users.id as userId, galleries.created_at as galleryCreated, users.created_at as userCreated FROM galleries INNER JOIN users ON galleries.user_id = users.id ORDER BY galleries.created_at DESC limit :page,5');
        $this->db->bind(':page', $page);
        $results = $this->db->resultSet();
        return $results;
    }
    public function get_stickers(){
        $this->db->query('SELECT * from stickers');
        $results = $this->db->resultSet();
        return $results;
    }

    public function getUserIdFromImageId($imageId){
        $this->db->query("SELECT user_id FROM galleries WHERE id = :imageId");
        $this->db->bind(':imageId', $imageId);
        $res = $this->db->single();
        return $res;
    }

    public function deleteimg($id){
        $this->db->query("DELETE FROM galleries WHERE id = :id");
        $this->db->bind(':id', $id);
        if($this->db->execute()){
        return true;
    } else {
        return false;
    }
    }
    public function likes($img_id){
        $this->db->query('INSERT INTO likes (img_id, user_id) VALUES(:img_id, :session)');
        $this->db->bind(':img_id', $img_id);
        $this->db->bind(':session', $_SESSION['user_id']);
        if($this->db->execute()){
          return true;
        }else{
          return false;
        }
      }
      public function isliked($img_id){
        $this->db->query("SELECT * FROM likes WHERE user_id = :session AND img_id = :img_id");
        $this->db->bind(':img_id', $img_id);
        $this->db->bind(':session', $_SESSION['user_id']);
        $res = $this->db->single();
        if($this->db->rowCount() > 0){
            return true;
        } else {
        return false;
        }
      }
      public function unliked($img_id){
        $this->db->query("DELETE FROM likes WHERE user_id = :session AND img_id = :img_id");
        $this->db->bind(':img_id', $img_id);
        $this->db->bind(':session', $_SESSION['user_id']);
        if($this->db->execute()){
            return true;
        } else {
        return false;
        }
        }
    public function numberoflikes($img_id){
        $this->db->query("SELECT * from likes where img_id = :img_id");
        $this->db->bind(':img_id', $img_id);
        $row = $this->db->single();
        $count = $this->db->rowCount();
        return $count;

}
public function checknotify($img_id)
{

    $this->db->query('SELECT notifyme FROM users left join galleries on users.id = galleries.user_id where users.id = galleries.user_id  and galleries.id = :img_id');
    $this->db->bind(':img_id', $img_id);
    if($row = $this->db->single()){
            return $row;

        } else {
            return false;
        }
}
public function getemail($img_id)
{

    $this->db->query('SELECT email from users left join galleries on users.id = galleries.user_id where users.id = galleries.user_id and galleries.id = :img_id limit 1');
    $this->db->bind(':img_id', $img_id);
    if($row = $this->db->single()){
            return $row;
        } else {
            return false;
        }
}
public function comments($img_id, $comment)
{
    $this->db->query('INSERT INTO comments (user_id, img_id, comment) VALUES(:session, :img_id, :comment)');
        $this->db->bind(':img_id', $img_id);
        $this->db->bind(':session', $_SESSION['user_id']);
        $this->db->bind(':comment', $comment);
        if($this->db->execute()){
          return true;
        }else{
          return false;
        }
}
public function getcomments($img_id)
{
    $this->db->query("SELECT comment, name FROM comments left join users on users.id = comments.user_id WHERE img_id = :img_id order by comments.created_at desc");
    $this->db->bind(':img_id', $img_id);
    $res = $this->db->resultSet();
    return $res;
}
}
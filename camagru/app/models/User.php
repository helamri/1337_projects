<?php
class User {
    private $db;

    public function __construct(){
        $this->db = new Database;
    }
    public function register($data){
        if (!(filter_var($data['email'], FILTER_VALIDATE_EMAIL))) {
            redirect('users/register');
        }else{
            $token = "poklhmcnvberstwzsfd";
            $token = str_shuffle($token);
            $token = substr($token, 0, 10);
            $this->db->query('INSERT INTO users (name, email, password, token) VALUES(:name, :email, :password, :token)');
            $this->db->bind(':name', $data['name']);
            $this->db->bind(':email', $data['email']);
            $this->db->bind(':password', $data['password']);
            $this->db->bind(':token', $token);
            $message = "Please click on this link to confirm your email:
            http://localhost:8001/camagru/users/confirm?&token=$token";
            mail($data['email'], "Confirm email", $message, "From: CAMAGRU");
            if($this->db->execute()){
                return true;
            } else {
                return false;
            }
        }
    }
    public function is_verified($name)
    {
        $this->db->query('SELECT is_validated FROM users WHERE name = :name');
        $this->db->bind(':name', $name);
        $res = $this->db->single();
        return $res;
    }
    public function login($name, $password){
        $this->db->query('SELECT * FROM users WHERE name = :name');
        $this->db->bind(':name', $name);
        $row = $this->db->single();
        $hashed_password = $row->password;
        if((password_verify($password, $hashed_password))){
            return $row;
        } else {
            return false;
        }
    }
    public function forget($email){
       $this->db->query('SELECT token FROM users WHERE email = :email');
       $this->db->bind(':email', $email);
       $res = $this->db->single();
       $message = "Please click on this link to change your password:
       http://localhost:8001/camagru/users/changepassviaemail?&token=$res->token";
       mail($email, "Forget password", $message, "From: CAMAGRU");
       if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function findUserByEmail($email){
    $this->db->query('SELECT * FROM users WHERE email = :email');
    $this->db->bind(':email', $email);

    $row = $this->db->single();

    if($this->db->rowCount() > 0){
        return true;
    } else {
        return false;
    }
}
public function findUserByName($name){
    $this->db->query('SELECT * FROM users WHERE name = :name');
    $this->db->bind(':name', $name);

    $row = $this->db->single();

    if($this->db->rowCount() > 0){
        return true;
    } else {
        return false;
    }
}
public function confirm($token){
    $this->db->query("UPDATE users SET is_validated = '1' WHERE token = :token");
    $this->db->bind(':token', $token);
    $this->db->execute();
    if ($this->db->rowCount() > 0)
    {
        return true;
    }else {
        return false;
    }
}
public function changepassviaemail($data){
    $this->db->query("UPDATE users SET password = :password WHERE token = :token");
    $this->db->bind(':password', $data['password']);
    $this->db->bind(':token', $data['token']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function changepassviaprofile($data){
    $this->db->query("UPDATE users SET password = :password WHERE email = :email");
    $this->db->bind(':password', $data['password']);
    $this->db->bind(':email', $_SESSION['user_email']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function changeuser($data){
    $this->db->query("UPDATE users SET name = :name WHERE email = :email");
    $this->db->bind(':name', $data['name']);
    $this->db->bind(':email', $_SESSION['user_email']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function changemail($data){
    if (!(filter_var($data['email'], FILTER_VALIDATE_EMAIL))) {
        return false;
    }else{
        $this->db->query("UPDATE users SET email = :email WHERE name = :name");
        $this->db->bind(':email', $data['email']);
        $this->db->bind(':name', $_SESSION['user_name']);
        if($this->db->execute()){
            return true;
        } else {
            return false;
        }
    }
}
public function deleteaccount(){
    $this->db->query("DELETE FROM users WHERE email = :email");
    $this->db->bind(':email', $_SESSION['user_email']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function deleteallimages(){
    $this->db->query("DELETE FROM galleries WHERE user_id = :id");
    $this->db->bind(':id', $_SESSION['user_id']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function deletealllikes(){
    $this->db->query("DELETE FROM likes WHERE user_id = :id");
    $this->db->bind(':id', $_SESSION['user_id']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function deleteallcomments(){
    $this->db->query("DELETE FROM comments WHERE user_id = :id");
    $this->db->bind(':id', $_SESSION['user_id']);
    if($this->db->execute()){
        return true;
    } else {
        return false;
    }
}
public function no()
{
        $this->db->query("UPDATE users SET notifyme = 0 WHERE id = :id");
        $this->db->bind(':id', $_SESSION['user_id']);
        if($this->db->execute()){
            return true;
        } else {
            return false;
        }
}
public function yes()
{
        $this->db->query("UPDATE users SET notifyme = 1 WHERE id = :id");
        $this->db->bind(':id', $_SESSION['user_id']);
        if($this->db->execute()){
            return true;
        } else {
            return false;
        }
}
public function checknotify()
{

    $this->db->query('SELECT notifyme FROM users WHERE id = :id');
    $this->db->bind(':id', $_SESSION['user_id']);
    if($row = $this->db->single()){
            return $row;
        } else {
            return false;
        }
}
}
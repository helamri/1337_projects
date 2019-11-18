<?php
class Users extends Controller{
    public function __construct(){
        $this->userModel = $this->model('user');
    }
    public function index(){
        $data = [
            'title' => 'Error'
        ];
        $this->view('users/index', $data);
    }
    public function register(){
        if(isset($_SESSION['user_id']))
            redirect('galleries/gallery');
        if($_SERVER['REQUEST_METHOD'] == 'POST'){
            $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
            $data = [
                'name' => trim($_POST['name']),
                'email' => trim($_POST['email']),
                'password' => trim($_POST['password']),
                'confirm_password' => trim($_POST['confirm_password']),
                'name_err' => '',
                'email_err' => '',
                'password_err' => '',
                'confirm_password_err' => ''
            ];
            if(empty($data['email'])){
                $data['email_err'] = 'Please enter email';
            } else {
                if($this->userModel->findUserByEmail($data['email'])){
                    $data['email_err'] = 'Email is already taken';
                }
            }
            if(empty($data['name'])){
                $data['name_err'] = 'Please enter a username';
            } else {
                if($this->userModel->findUserByName($data['name'])){
                    $data['name_err'] = 'Username is already taken';
                }elseif(!preg_match( "/^(?=.{5,20}$)(?![.])(?!.*[.]{2})[a-zA-Z0-9.]+(?<![.])$/", $data['name'])){
                   $data['name_err'] = 'Please enter a valid Username';
               }
           }
           $uppercase = preg_match('@[A-Z]@', $data['password']);
           $lowercase = preg_match('@[a-z]@', $data['password']);
           $onenumber = preg_match('@[\d]@', $data['password']);
           $special = preg_match('/[#$%^&*()+_!@=\-\[\]\';,.\/{}|":<>?~\\\\]/', $data['password']);
           if(empty($data['password'])){
            $data['password_err'] = 'Please enter password';
        } elseif(!$uppercase || !$lowercase || !$onenumber || !$special || strlen($data['password']) < 8){
            $data['password_err'] = "Your password must be have at least 8 characters long, 1 number, 1 special character, 1 uppercase and 1 lowercase character";
        }
        if(empty($data['confirm_password'])){
            $data['confirm_password_err'] = 'Please confirm password';
        } else{
            if($data['password'] != $data['confirm_password']){
                $data['confirm_password_err'] = 'Passwords do not match';
            }
        }
        if(empty($data['email_err']) && empty($data['name_err']) && empty($data['password_err']) && empty($data['confirm_password_err'])){
            $data['password'] = password_hash($data['password'], PASSWORD_DEFAULT);
            if($this->userModel->register($data)){
                flash('register_success', 'Please confirm your email');
                redirect('users/login');
            } 
        } else {
            $this->view('users/register', $data);
        }
    } else {
        $data = [
            'name' => '',
            'email' => '',
            'password' => '',
            'confirm_password' => '',
            'name_err' => '',
            'email_err' => '',
            'password_err' => '',
            'confirm_password_err' => ''
        ];
        $this->view('users/register', $data);
    }
}

public function login(){
    if(isset($_SESSION['user_id']))
        redirect('galleries/gallery');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $data = [
            'name' => trim($_POST['name']),
            'password' => trim($_POST['password']),
            'name_err' => '',
            'password_err' => '',
        ];
        if(empty($data['name'])){
            $data['name_err'] = 'Please enter username';
        }
        if(empty($data['password'])){
            $data['password_err'] = 'Please enter password';
        }
        else if($this->userModel->findUserByName($data['name'])){

        } else {
            $data['name_err'] = 'No user found';
        }
        if(empty($data['name_err']) && empty($data['password_err'])){
            $loggedInUser = $this->userModel->login($data['name'], $data['password']);
            $id = $this->userModel->is_verified($data['name']);
            if(($loggedInUser)&&($id->is_validated == '1')){
                $this->createUserSession($loggedInUser);
            } else if($id->is_validated == '0'){
             $data['password_err'] = 'Please confirm your email';
             $this->view('users/login', $data); 
         }
         else {
            $data['password_err'] = 'Password incorrect';
            $this->view('users/login', $data); 
        }
    } else {
        $this->view('users/login', $data);
    }
} else {
    $data = [
        'name' => '',
        'password' => '',
        'name_err' => '',
        'password_err' => ''
    ];
    $this->view('users/login', $data);
}

}

public function createUserSession($user){
    $_SESSION['user_id'] = $user->id;
    $_SESSION['user_email'] = $user->email;
    $_SESSION['user_name'] = $user->name;
    redirect('galleries/gallery');
}
public function logout(){
    unset($_SESSION['user_id']);
    unset($_SESSION['user_email']);
    unset($_SESSION['user_name']);
    session_destroy();
    redirect('users/login');
}
public function confirm(){

    if(isset($_GET['token'])){
        $data = $_GET['token'];
    }else{
        redirect('galleries/gallery');
    }
    if (!$this->userModel->confirm($data))
    {
       flash('register_success', 'Your token is  false');
       $this->view('users/confirm');

   }else {
    $_SESSION['confirm'] = "OK";
    flash('register_success', 'Your email has been confirmed');
    $this->view('users/confirm');
}
}
public function forget(){
    if(isset($_SESSION['user_id']))
        redirect('galleries/gallery');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $data = [
            'foremail' => trim($_POST['foremail']),
            'foremail_err' => ''
        ];
        if(empty($data['foremail'])){
            $data['foremail_err'] = 'Please enter email';
        }
        else if($this->userModel->findUserByEmail($data['foremail'])){

        } 
        else {
            $data['foremail_err'] = 'No user found';
        }
        if(empty($data['foremail_err'])){
            $this->userModel->forget($data['foremail']);
            flash('register_success', 'Please go to your mail box and click on the link to change your password');
            redirect('users/forget');
        } else {
            $this->view('users/forget', $data);
        }
    } else {
        $data = [
            'foremail' => '',
            'foremail_err' => '',
        ];
        $this->view('users/forget', $data);
    }
}
public function changepassviaemail(){
   if($_SERVER['REQUEST_METHOD'] == 'POST'){
    $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
    if(isset($_SESSION['token'])){
        $token = $_SESSION['token'];
        unset($_SESSION['token']);
    }

    $data = [
        'password' => trim($_POST['password']),
        'password_err' => '',
        'token' => $token
    ];
    $uppercase = preg_match('@[A-Z]@', $data['password']);
    $lowercase = preg_match('@[a-z]@', $data['password']);
    $onenumber = preg_match('@[\d]@', $data['password']);
    $special = preg_match('/[#$%^&*()+=\-\[\]\';,.\/{}|":<>?~\\\\]/', $data['password']);
    if(empty($data['password'])){
        $data['password_err'] = 'Please enter password';
    } elseif(!$uppercase || !$lowercase || !$onenumber || !$special || strlen($data['password']) < 8){
        $data['password_err'] = "Your password must be have at least 8 characters long, 1 number, 1 special character, 1 uppercase and 1 lowercase character";
    }
    if(empty($data['password_err'])){
        $data['password'] = password_hash($data['password'], PASSWORD_DEFAULT);
        if($this->userModel->changepassviaemail($data)){
            flash('register_success', 'Your password has been changed');
            redirect('users/login');
        } 
    } else {
        $this->view('users/changepassviaemail', $data);
    }
} else {
    $data = [
        'password' => '',
        'password_err' => ''
    ];
    $this->view('users/changepassviaemail', $data);
}
}
public function changepassviaprofile(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
     $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
     $data = [
         'password' => trim($_POST['password']),
         'password_err' => ''
     ];
     $uppercase = preg_match('@[A-Z]@', $data['password']);
     $lowercase = preg_match('@[a-z]@', $data['password']);
     $onenumber = preg_match('@[\d]@', $data['password']);
     $special = preg_match('/[#$%^&*()+=\-\[\]\';,.\/{}|":<>?~\\\\]/', $data['password']);
     if(empty($data['password'])){
         $data['password_err'] = 'Please enter password';
     } elseif(!$uppercase || !$lowercase || !$onenumber || !$special || strlen($data['password']) < 8){
         $data['password_err'] = "Your password must be have at least 8 characters long, 1 number, 1 special character, 1 uppercase and 1 lowercase character";
     }
     if(empty($data['password_err'])){
         $data['password'] = password_hash($data['password'], PASSWORD_DEFAULT);
         if($this->userModel->changepassviaprofile($data)){
             flash('register_success', 'Your password has been changed');
             redirect('users/changepassviaprofile');
         } 
     } else {
         $this->view('users/changepassviaprofile', $data);
     }
 } else {
     $data = [
         'password' => '',
         'password_err' => ''
     ];
     $this->view('users/changepassviaprofile', $data);
 }
}
public function profile(){
    if(isset($_GET['subcheck']) && !empty($_GET['subcheck']) && $_GET['subcheck'] == 0)
        $this->userModel->notifyme();
    if(!isset($_SESSION['user_id']))
       redirect("pages/index");
   else
    $this->view('users/profile');
}
public function changeuser(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $data = [
            'name' => trim($_POST['name']),
            'name_err' => ''
        ];
        if(empty($data['name'])){
            $data['name_err'] = 'Please enter a username';
        }
        if($this->userModel->findUserByName($_POST['name'])){
            $data['name_err'] = 'Username is already taken';
        }
        if(empty($data['name_err'])){
            if($this->userModel->changeuser($data)){
                flash('register_success', 'Your username has been changed');
                $_SESSION['user_name'] = $data['name'];
                $this->view('users/changeuser', $data);
            } 
        }
        else {
            $this->view('users/changeuser', $data);
        }
    } else {
        $data = [
            'name' => '',
            'name_err' => ''
        ];
        $this->view('users/changeuser', $data);
    }
}

public function changemail(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $data = [
            'email' => trim($_POST['email']),
            'email_err' => ''
        ];
        if(empty($data['email'])){
            $data['email_err'] = 'Please enter email';
        } else {
            if($this->userModel->findUserByEmail($data['email'])){
                $data['email_err'] = 'Email is already taken';
            }
        }
        if(empty($data['email_err'])){
            if($this->userModel->changemail($data)){
                flash('register_success', 'Your email has been changed');
                $_SESSION['user_email'] = $data['email'];
                redirect('users/changemail');
            } 
        } else {
            $this->view('users/changemail', $data);
        }
    } else {
        $data = [
            'email' => '',
            'email_err' => '',
        ];
        $this->view('users/changemail', $data);
    }

}
public function deleteaccount(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    $this->view('users/deleteaccount');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        if($this->userModel->deleteaccount()){
            $this->userModel->deleteallimages();
            $this->userModel->deletealllikes();
            $this->userModel->deleteallcomments();
            $this->logout();
        } 

    }

}

public function deletecomments(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    $this->view('users/deletecomments');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $this->userModel->deleteallcomments();
    } 
}

public function deleteimages(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    $this->view('users/deleteimages');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $this->userModel->deleteallimages();
    } 
}

public function deletelikes(){
    if(!isset($_SESSION['user_id']))
        redirect('pages/index');
    $this->view('users/deletelikes');
    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        $_POST = filter_input_array(INPUT_POST, FILTER_SANITIZE_STRING);
        $this->userModel->deletealllikes();
    } 
}

}
<?php
class Galleries extends Controller {
    public function __construct(){
        if(!isLoggedIn()){
            redirect('users/login');
        }
        $this->galleryModel = $this->model('Gallery');
    }
    public function index(){
       $img_id = 0;
       $notify = 0;
       if(isset($_POST["ok"]) && !empty($_POST['ok']))
       {
        $comment = htmlspecialchars($_POST["comment"]);
        if ($comment == null){
            redirect('galleries/gallery');
            exit;
        }
        $img_id = $_POST["img_id"];
        $name = $_SESSION['user_name'];
        $notify = $this->galleryModel->checknotify($img_id);
        $email = $this->galleryModel->getemail($img_id);
        $this->galleryModel->comments($img_id, $comment);
        $messagecomment = "$name comments on one of your images";
        if ($notify->notifyme == 1)
        {
            mail($email->email, "$name comments on your image!", $messagecomment, "From: CAMAGRU");
            redirect('galleries/gallery');
        }
    }
    $page = 0;
    if(isset($_POST["page"]))
    {
        $page= $_POST["page"];

        $page= ($page*5)-5;
    }
    $galleries = $this->galleryModel->showall($page);
    $datashow = [
        'galleries' => $galleries
    ];
    $this->view('galleries/index', $datashow);
}


public function camera(){
    if(!isset($_SESSION['user_id']))
        redirect('');
    $galleries = $this->galleryModel->hiFive();
    $stickers = $this->galleryModel->get_stickers();
    $datashow = [
        'galleries' => $galleries,
        'stickers' => $stickers
    ];
    if (isset($_POST["img"]) && !empty($_POST["img"])) {
        $img = $_POST['img'];
        $img = str_replace('data:image/png;base64,', '', $img);
        $data = base64_decode($img);
        $file = APPROOT2.'/public/img/'.date("YmdHis"). $_SESSION['user_id'] .'.png';
        file_put_contents($file, $data);
        $file = str_replace(APPROOT2, "", $file);
        $this->galleryModel->insertPhoto($file);
        redirect('galleries/camera');
    }
    if (isset($_GET['delete']) && !empty($_GET["delete"])){
        $imgid = $_GET["delete"];
        $userId = $this->galleryModel->getUserIdFromImageId($imgid);
            // Prevent image deletion by chrome inspect
        if ($userId->user_id == $_SESSION['user_id'])
        {
            $this->galleryModel->deleteimg($imgid);
            flash('register_success', 'The image is deleted');
            redirect('galleries/camera');
        }
        else
            redirect('galleries/camera');
        exit;
    }
    else
        $this->view('/galleries/camera', $datashow);
}

public function likeAjax() {
   if(isset($_GET["id"]))
   {
    $img_id = $_GET["id"];
    $name = $_SESSION['user_name'];
    $messagelike = "$name likes one of your images";
    $notify = $this->galleryModel->checknotify($img_id);
    $email = $this->galleryModel->getemail($img_id);
    if (!($this->galleryModel->isliked($img_id)))
    {
        $this->galleryModel->likes($img_id);
        if ($notify->notifyme == 1)
            mail($email->email, "$name likes your image!", $messagelike, "From: CAMAGRU");
        echo 'like.png,'.$this->galleryModel->numberoflikes($img_id);
    }
    else
    {
        $this->galleryModel->unliked($img_id);
        echo 'unlike.png,'.$this->galleryModel->numberoflikes($img_id);
    }
}
}

public function gallery(){
    if(!isset($_SESSION['user_id']))
        redirect('');
    $img_id = 0;
    $notify = 0;
    if(isset($_POST["ok"]) && !empty($_POST['ok']))
    {
        $comment = htmlspecialchars($_POST["comment"]);
        if ($comment == null){
            redirect('galleries/gallery');
            exit;
        }
        $img_id = $_POST["img_id"];
        $name = $_SESSION['user_name'];
        $notify = $this->galleryModel->checknotify($img_id);
        $email = $this->galleryModel->getemail($img_id);
        $this->galleryModel->comments($img_id, $comment);
        $messagecomment = "$name comments on one of your images";
        if ($notify->notifyme == 1)
        {
            mail($email->email, "$name comments on your image!", $messagecomment, "From: CAMAGRU");
            redirect('galleries/gallery');
        }
    }
    $page = 0;
    if(isset($_POST["page"]))
    {
        $page= $_POST["page"];

        $page= ($page*5)-5;
    }
    $galleries = $this->galleryModel->showall($page);
    $datashow = [
        'galleries' => $galleries
    ];
    $this->view('/galleries/gallery', $datashow);
    
}
}

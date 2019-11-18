<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<h1 align="center">Profile</h1> 
<hr>
<div class="container signin">
    <p>Change your username: <a href="<?php echo URLROOT; ?>/users/changeuser">Click here</a>.</p>
    <p>Change your email: <a href="<?php echo URLROOT; ?>/users/changemail">Click here</a>.</p>
    <p>Change your password: <a href="<?php echo URLROOT; ?>/users/changepassviaprofile">Click here</a>.</p>
    <p>Delete your account: <a href="<?php echo URLROOT; ?>/users/deleteaccount">Click here</a>.</p>
    <p>Delete your images: <a href="<?php echo URLROOT; ?>/users/deleteimages">Click here</a>.</p>
    <p>Delete your likes: <a href="<?php echo URLROOT; ?>/users/deletelikes">Click here</a>.</p>
    <p>Delete your comments: <a href="<?php echo URLROOT; ?>/users/deletecomments">Click here</a>.</p>
    <form method="POST" action="<?php echo URLROOT; ?>/users/profile">
    <?php
$cmt = $this->userModel->checknotify();
if (isset($_POST['d']))
	$this->userModel->no();
else if (isset($_POST['a']))
	$this->userModel->yes();
?>
	<p>Get notified by email about other members reactions on your images:</p>
    <centr><button type="submit" name="d">Desactiver</button></centr><center><button type="submit" name="a">Activer</button></centr>
    </form>
</div>
<?php require APPROOT . '/views/inc/footer.php';?>

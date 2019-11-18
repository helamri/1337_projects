<!DOCTYPE html>
<html>
<head>

</head>

<link type="text/css" href="public/css/navbar.css">

<body>

<ul class="nav">
<?php if(!isset($_SESSION['user_id'])){?>
  <li><a class="active" href="<?php echo URLROOT; ?>"><?php SITENAME; ?>Gallery</a></li>
<?php } else {?>
    <li><a class="active"><?php SITENAME; ?>Welcome</a></li>
<?php
  }?>
  <?php if(isset($_SESSION['user_id'])) : ?>
  <li><a href="<?php echo URLROOT; ?>/users/logout">Logout</a></li>
  <li><a href="<?php echo URLROOT; ?>/users/profile">Profile</a></li>
  <li><a href="<?php echo URLROOT; ?>/galleries/camera">Camera</a></li>
  <li><a href="<?php echo URLROOT; ?>/galleries/gallery">Gallery</a></li>
  <?php else : ?>
  <li><a href="<?php echo URLROOT; ?>/users/register">Register</a></li>
  <li><a href="<?php echo URLROOT; ?>/users/login">Login</a></li>
<?php endif; ?>
  <li style="float:right"><a  href="<?php echo URLROOT; ?>/pages/about">About</a></li>
</ul>

</body>
</html>

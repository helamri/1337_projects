<html>
<head>
</head>
<style>
.logo {
  position:absolute;
  top:18%;
  bottom:10%
  left:30%;
  right:30%
}
#myImg {
  border-radius: 5px;
  cursor: pointer;
  transition: 0.3s;
}

#myImg:hover {opacity: 0.7;}

.bord {
  
  max-width: 100%;
  padding: 1rem;
  color: blue;
  border-width: 3px;
  border-style: solid;
  border-image: 
    linear-gradient(
      to bottom, 
      red, 
      rgba(0, 0, 0, 0)
    ) 1 100%;
}
</style>
<body>
<?php require APPROOT . '/views/inc/header.php';?>
<div class="logo" align="center" style="width: 40%; height: 80%; border: 2px solid black; border-radius: 10px; overflow: auto;">
  <?php 
  foreach($data['pages'] as $page) : 
    ?>
    <div class="bord" align="center">
      <a href="<?php echo URLROOT; ?>/users/login"><img src="<?php echo URLROOT."/public/stickers/unlike.png";?>"" height="5%" width="5%"></a> <?php echo $this->pageModel->numberoflikes($page->galleryId);?> Likes
      <p><?php echo "<img id='myImg' style='width:100%;max-width:700px;' src='". URLROOT. $page->url ."'"; ?></p><br>
      <?php foreach($this->pageModel->getcomments($page->galleryId) as $comments) : 
        echo '<p><b>'.$comments->name.'</b> : '.$comments->comment.'</p>';?>
        <?php endforeach; ?>
        <hr>
    </div>
  <?php endforeach; ?>
  <div align="center">
  <?php
  $count = $this->pageModel->getNumber();
  $a= $count/5;
  $a= ceil($a);
  ?> 
  <form method="post">
    <?php 
    for($b=1;$b<=$a;$b++)
    {
      ?>
      <input type="submit" value="<?php echo $b;?>" name="page">
      <?php
    }
    ?>
  </form>
</div>
</div>
<?php require APPROOT . '/views/inc/footer.php';?>
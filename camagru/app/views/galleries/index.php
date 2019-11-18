<?php require APPROOT . '/views/inc/header.php';?>
<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
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

.button {
  background-color: green;
  background-repeat:no-repeat;
  border: none;
  cursor:pointer;
  overflow: hidden;
  outline:none;
}
</style>
<div class="logo" style="width: 40%; height: 80%; border: 2px solid black; border-radius: 10px; overflow: auto;">
  <?php foreach($data['galleries'] as $gallery) : ?>
    <div class="bord" align="center">
        <img id="<?php echo $gallery->galleryId ;?>" onclick="like_ajax(<?php echo $gallery->galleryId ;?>)" 
        src="<?php if (!($this->galleryModel->isliked($gallery->galleryId))) echo URLROOT."/public/stickers/unlike.png"; else echo URLROOT."/public/stickers/like.png";?>" height="5%" width="5%">
        <span id="likesNbr<?php echo $gallery->galleryId ;?>"> <?php echo  $this->galleryModel->numberoflikes($gallery->galleryId); ?></span> Likes
      <form method="post" action="<?php URLROOT ;?>/camagru/galleries/gallery">
        <input style="text-align: center;" type="text" placeholder="Write a comment" name="comment"/>
        <input type="hidden" name="img_id" value="<?php echo $gallery->galleryId;?>"/>
        <input type="submit" name="ok" class="button" value="send"/>
      </form>
      <p><?php echo "<img id='myImg' style='width:100%;height:80%' src='". URLROOT. $gallery->url ."'"; ?></p><br>
      <?php foreach($this->galleryModel->getcomments($gallery->galleryId) as $comments) : 
        echo '<p><b>'.$comments->name.'</b> : '.$comments->comment.'</p>';?>
      <?php endforeach; ?>
      <hr>
    </div>
  <?php endforeach; ?>

  <div align="center">
    <?php
    $count = $this->galleryModel->getNumber();
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
<script type="text/javascript">
function like_ajax(imgId) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var arr = this.responseText.trim().split(',');
      document.getElementById(imgId).src = "http://localhost:8001/camagru/public/stickers/" + arr[0];
      document.getElementById('likesNbr' + imgId).innerHTML = arr[1];
    }
  };
  xhttp.open("GET", "http://localhost:8001/camagru/galleries/likeAjax?id=" + imgId, true);
  xhttp.send(); 
}
</script>
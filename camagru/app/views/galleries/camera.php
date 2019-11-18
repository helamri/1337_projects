<style>
  .registerbtn {
    background-color: #4CAF50;
    color: white;
    width:5%;
    padding: 12% 15%;
    border-radius: 25px 50px;
    font-size:1vw;  
  }
  .button{
    cursor:pointer;
    border: none;
    width: 10%;
    height: 5%;
    align: center;
    display: block;
  }
  .alert{
  color: #468847; 
  background-color: #dff0d8; 
  border-color: #d6e9c6;
  animation: divisibility 10s forwards;
  text-align: center;
  }
</style>
<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<?php flash('register_success');?>
<div style="float:right;width:50%;">
  <div align="center" style="width: 100%; height: 90%; border: 2px solid black; border-radius: 10px; overflow: auto;">
    <?php
    foreach($data['galleries'] as $gallery) :
      ?>
      <div align=center>
        <a class="button" onclick="Deleteimage()" href="<?php echo URLROOT; ?>/galleries/camera?delete=<?php echo $gallery->galleryId;?>"><img src="<?php echo URLROOT."/public/stickers/delete.png";?>"/></a>
        <p><?php echo "<img style='width:70%;height:40%;align:center' src='" .URLROOT. $gallery->url ."'/>"; ?></p>
        <hr>
      </div>
    <?php endforeach; ?>
  </div>
  <div style="height:5%;width:100%;font-size:1vw;" align="center">
    <form method="post" enctype="multipart/form-data">
      <input type="file" id="uploader" name="file">
    </form>
  </div>
</div>
<div style="padding:2%;float:left;width:50%;">
  <div>
    <div align="center">
      <video id="video" playsinline autoplay height="40%" width="80%"></video>
    </div>
  </form>
</div>
<div>
  <button type="submit" id="snapcap" name="snapcap" class="registerbtn" value="Save">Capture</button>
  <div align="center">
    <canvas style="max-width: 100%;"id="canvas" height="480" width="640"></canvas>
  </div>
  <form method="post">
    <input id="inp_img" name="img" value="" type="hidden">
    <div>
      <button  type="submit" id="snapsav" name="snapsav" class="registerbtn" value="Save" disabled>Save</button>
      <div style="width:100%;font-size:1vw;" align="center">
        <select align="center" id="stickers" onchange="choosestickers()" disabled>
          <option value="def">Choose a sticker</option>
          <?php
          foreach($data['stickers'] as $stickers) :
            echo "<option value='".URLROOT.$stickers->url."'>$stickers->name</option>"; ?>
          <?php endforeach; ?>
        </select>
        <select id="coor" onchange="choosestickers()" disabled>
          <option value="def">Choose a position</option>
          <option value="tlc">top left corner</option>
          <option value="trc">top right corner</option>
          <option value="blc">bottom left corner</option>
          <option value="brc">bottom right corner</option>
          <option value="mid">in the middle</option>
        </select>
        <a style="color:red; background-color:yellow;" onclick="clearCanvas()">Clear</a>
      </div>
    </div>
  </form>
</div>
</div>
<?php require APPROOT . '/views/inc/footer.php';?>
<script>

  const video = document.getElementById('video');
  var canvas = document.getElementById('canvas');
  var snapsav = document.getElementById("snapsav");
  var snapcap = document.getElementById("snapcap");
  const errorMsgElement = document.querySelector('span#errorMsg');
  const emptyImage = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAoAAAAHgCAYAAAA10dzkAAAYlklEQVR4Xu3WQQEAAAgCMelf2iA3GzB8sHMECBAgQIAAAQIpgaXSCkuAAAECBAgQIHAGoCcgQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgAABA9APECBAgAABAgRiAgZgrHBxCRAgQIAAAQIGoB8gQIAAAQIECMQEDMBY4eISIECAAAECBAxAP0CAAAECBAgQiAkYgLHCxSVAgAABAgQIGIB+gAABAgQIECAQEzAAY4WLS4AAAQIECBAwAP0AAQIECBAgQCAmYADGCheXAAECBAgQIGAA+gECBAgQIECAQEzAAIwVLi4BAgQIECBAwAD0AwQIECBAgACBmIABGCtcXAIECBAgQICAAegHCBAgQIAAAQIxAQMwVri4BAgQIECAAAED0A8QIECAAAECBGICBmCscHEJECBAgAABAgagHyBAgAABAgQIxAQMwFjh4hIgQIAAAQIEDEA/QIAAAQIECBCICRiAscLFJUCAAAECBAgYgH6AAAECBAgQIBATMABjhYtLgAABAgQIEDAA/QABAgQIECBAICZgAMYKF5cAAQIECBAgYAD6AQIECBAgQIBATMAAjBUuLgECBAgQIEDAAPQDBAgQIECAAIGYgAEYK1xcAgQIECBAgIAB6AcIECBAgAABAjEBAzBWuLgECBAgQIAAAQPQDxAgQIAAAQIEYgIGYKxwcQkQIECAAAECBqAfIECAAAECBAjEBAzAWOHiEiBAgAABAgQMQD9AgAABAgQIEIgJGICxwsUlQIAAAQIECBiAfoAAAQIECBAgEBMwAGOFi0uAAAECBAgQMAD9AAECBAgQIEAgJmAAxgoXlwABAgQIECBgAPoBAgQIECBAgEBMwACMFS4uAQIECBAgQMAA9AMECBAgQIAAgZiAARgrXFwCBAgQIECAgAHoBwgQIECAAAECMQEDMFa4uAQIECBAgACBB+4+AeEFWYvzAAAAAElFTkSuQmCC";
  var dropstick = document.getElementById("stickers");
  var dropcoor = document.getElementById("coor");
  var imageload = document.getElementById("uploader");
  imageload.addEventListener('change', uploadtocanvas, false);
  var constraints = {
    audio: false,
    video: {
      width: 640, height: 480
    }
  };
// Access webcam
async function init() {
  try {
    var stream = await navigator.mediaDevices.getUserMedia(constraints);
    handleSuccess(stream);
  } catch (e) {
    errorMsgElement.innerHTML = `navigator.getUserMedia error:${e.toString()}`;
  }
}
// Success
function handleSuccess(stream) {
  window.stream = stream;
  video.srcObject = stream;
}
// Load init
init();
var context = canvas.getContext('2d');
snapcap.addEventListener("click", function() {
  imageload.value = '';
  context.drawImage(video, 0, 0, 640, 480);
  if (canvas.toDataURL() != emptyImage)
  {
    dropstick.removeAttribute("disabled");
    dropcoor.removeAttribute("disabled");
    snapsav.removeAttribute("disabled");
  }
});
function uploadtocanvas(e){
  var reader = new FileReader();
  reader.onload = function(event){
    var img = new Image();
    img.src = event.target.result;
    img.onload = function(){
      context.drawImage(img,0,0, 640, 480);
    }
  }
  reader.readAsDataURL(e.target.files[0]);
  dropstick.removeAttribute("disabled");
  dropcoor.removeAttribute("disabled");
  snapsav.removeAttribute("disabled");
}
function choosestickers(){

  var sticker = dropstick.options[dropstick.selectedIndex].value;
  var coor = dropcoor.options[dropcoor.selectedIndex].value;
  var img = new Image;
  img.src = sticker;
  if (canvas.toDataURL() != emptyImage){
  img.onload = function()
  {
    switch(coor) {
      case "tlc":
      context.drawImage(img, 0, 0, 160, 120);
      break;
      case "trc":
      context.drawImage(img, 480, 0, 160, 120);
      break;
      case "blc":
      context.drawImage(img, 0, 350, 160, 120);
      break;
      case "brc":
      context.drawImage(img, 480, 350, 160, 120);
      break;
      case "mid":
      context.drawImage(img, 250, 175, 160, 120);
      break;
      default :
      context.drawImage(img, 0, 0, 160, 120);
      break;
    }
  }
}
}

function clearCanvas(){
  context.clearRect(0, 0, 640, 480);
}
snapsav.addEventListener("click", function() {
  prepareImg();
});
function prepareImg() {
  if (canvas.toDataURL() != emptyImage)
    document.getElementById('inp_img').value = canvas.toDataURL();
}
function Deleteimage()
{ 
  if(confirm("Are you sure you want to delete this image?")==true)
    return true;
}
</script>
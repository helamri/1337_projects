<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<form action="<?php echo URLROOT; ?>/users/deletelikes" method="post">
<br><br><label><b>To delete your likes</b></label>
    <button onclick="Deletelikes()" type="submit" class="registerbtn">click here</button>
   </form>
<?php require APPROOT . '/views/inc/footer.php';?>
<script>
  function Deletelikes()
{ 
  if(confirm("Are you sure you want to delete your likes?")==true)
    return true;
}
  </script>
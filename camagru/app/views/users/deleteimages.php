<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<form action="<?php echo URLROOT; ?>/users/deleteimages" method="post">
<br><br><label><b>To delete your images</b></label>
    <button onclick="Deleteimages()" type="submit" class="registerbtn">click here</button>
   </form>
<?php require APPROOT . '/views/inc/footer.php';?>
<script>
  function Deleteimages()
{ 
  if(confirm("Are you sure you want to delete your images?")==true)
    return true;
}
  </script>
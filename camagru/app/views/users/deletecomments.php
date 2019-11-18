<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<form action="<?php echo URLROOT; ?>/users/deletecomments" method="post">
<br><br><label><b>To delete your comments</b></label>
    <button onclick="Deletecomments()" type="submit" class="registerbtn">click here</button>
   </form>
<?php require APPROOT . '/views/inc/footer.php';?>
<script>
  function Deletecomments()
{ 
  if(confirm("Are you sure you want to delete your comments?")==true)
    return true;
}
  </script>
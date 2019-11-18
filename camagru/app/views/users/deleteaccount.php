<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<form action="<?php echo URLROOT; ?>/users/deleteaccount" method="post">
<br><br><label><b>To delete your account</b></label>
    <button onclick="Deleteaccount()" type="submit" class="registerbtn">click here</button>
   </form>
<?php require APPROOT . '/views/inc/footer.php';?>
<script>
  function Deleteaccount()
{ 
  if(confirm("Are you sure you want to delete your account?")==true)
    return true;
}
  </script>
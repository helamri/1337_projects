<style>

@keyframes divisibility {
  0% { opacity: 1.0; }
  25% { opacity: 0.75; }
  50% { opacity: 0.50; }
  75% { opacity: 0.25; }
  100% { opacity: 0.0; }
}
.alert{
  color: #468847; 
  background-color: #dff0d8; 
  border-color: #d6e9c6;
  animation: divisibility 10s forwards;
  text-align: center;
  }
  </style><link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<form action="<?php echo URLROOT; ?>/users/changeuser" method="post">
<?php flash('register_success');?>
<br><br><label for="name"><b>Username</b></label>
    <input type="text" placeholder="Enter New Username" name="name" <?php echo (!empty($data['name_err'])) ? 'is invalid' : ''; ?>>
    <span style="color:red"><?php echo $data['name_err']; ?></span>
    <button type="submit" class="registerbtn">Ok</button>
   </form>
<?php require APPROOT . '/views/inc/footer.php';?>
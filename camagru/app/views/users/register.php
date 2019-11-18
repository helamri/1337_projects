<link rel="stylesheet" href="<?php echo URLROOT; ?>/css/regform.css">
<?php require APPROOT . '/views/inc/header.php';?>
<br>
<h1>Register</h1>
<form action="<?php echo URLROOT; ?>/users/register" method="post">
<hr>

    <label for="name"><b>Username</b></label>
    <input type="text" placeholder="Enter Your Name" name="name" <?php echo ((!empty($data['name_err']))) ? 'is invalid' : ''; ?>>
    <span style="color:red; font-size:12px"><?php echo $data['name_err']; ?></span>

    <br><br><label for="email"><b>Email</b></label>
    <input type="email" placeholder="Enter Your Email" name="email" <?php echo (!empty($data['email_err'])) ? 'is invalid' : ''; ?>>
    <span style="color:red; font-size:12px"><?php echo $data['email_err']; ?></span>

    <br><br><label for="password"><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="password" <?php echo (!empty($data['password_err'])) ? 'is invalid' : ''; ?>>
    <span style="color:red; font-size:12px"><?php echo $data['password_err']; ?></span>

    <br><br><label for="confirm_password"><b>Confirm Password</b></label>
    <input type="password" placeholder="Confirm Password" name="confirm_password" <?php echo (!empty($data['confirm_password_err'])) ? 'is invalid' : ''; ?>>
    <span style="color:red; font-size:12px" class="spo"><?php echo $data['confirm_password_err']; ?></span>
<hr>
<button type="submit" class="registerbtn">Register</button>
  </div>
  
  <div class="container signin">
    <p>Already have an account? <a href="<?php echo URLROOT; ?>/users/login">Login</a>.</p>
  </div>
</form>
<?php require APPROOT . '/views/inc/footer.php';?>
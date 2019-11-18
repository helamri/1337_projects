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
<?php flash('register_success');?>
<h1>Login</h1> 
<form action="<?php echo URLROOT; ?>/users/login" method="post">
<hr>

    <br><br><label for="name"><b>Username</b></label>
    <input type="text" placeholder="Enter Username" name="name" <?php echo (!empty($data['name_err'])) ? 'is invalid' : ''; ?>>
    <span style="color:red"><?php echo $data['name_err']; ?></span>

    <br><br><label for="password"><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="password" <?php echo (!empty($data['password_err'])) ? 'is invalid' : ''; ?>>
    <span style="color:red"><?php echo $data['password_err']; ?></span>

<hr>
<button type="submit" class="registerbtn">Login</button>
  </div>
  
  <div class="container signin">
    <p>Forgot your password? <a href="<?php echo URLROOT; ?>/users/forget">click here</a>.</p>
    <p>No account? <a href="<?php echo URLROOT; ?>/users/register">Register</a>.</p>
  </div>
</form>
<?php require APPROOT . '/views/inc/footer.php';?>
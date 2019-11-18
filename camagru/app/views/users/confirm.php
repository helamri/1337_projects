<?php require APPROOT . '/views/inc/header.php';?>
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
</style>
<?php if (!empty($_SESSION['confirm'])) :
{flash('register_success');
 unset($_SESSION['confirm']);}
 else: 
 	flash('register_success');
 endif;
 require APPROOT . '/views/inc/footer.php';?>
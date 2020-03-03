<template>
  <div class="container">
    <div class="row">
      <div class="col-md-6 mt-5 mx-auto">
        <form v-on:submit.prevent="register">
          <h1 class="h3 mb-3 font-weight-normal">Register</h1>
          <div class="form-group">
            <div v-if="!image">
              <input style="display: none" ref="fileInput" type="file" @change="onFileChange" name="file" id="input-files"/>
              <button type='button' @click="$refs.fileInput.click()"><font-awesome-icon icon="camera"/></button>
              <img style="width:7em; height:7em; border-radius: 50%" :src="img" />
            </div>
            <div v-else>
              <img style="width:7em; height:7em; border-radius: 50%" :src="image" />
              <button type='button' @click="removeImage"><font-awesome-icon icon="trash-alt"/></button>
            </div>
          </div>
          <div class="form-group">
            <label for="username">Username</label>
            <input type="text" v-model="username" class="form-control" name="username" placeholder="Enter a username">
          </div>
          <div class="form-group">
            <label for="fname">First Name</label>
            <input type="text" v-model="fname" class="form-control" name="fname" placeholder="Enter Fist Name">
          </div>
          <div class="form-group">
            <label for="lname">Last Name</label>
            <input type="text" v-model="lname" class="form-control" name="lname" placeholder="Enter Last Name">
          </div>
          <div class="['form-group', isEmailValid()]">
            <label for="email">Email Address</label>
            <input type="email" v-model="email" class="form-control" name="email" placeholder="Enter Email">
          </div>
          <div class="form-group">
            <label for="password">Password</label>
            <input type="password" v-model="password" class="form-control" name="password" placeholder="Enter Password">
          </div>
          <div class="form-group">
            <label for="password">Default Language</label>
            <select name="lang" v-model="language">
              <option value="" selected>Select One</option>
              <option value="en">English</option>
              <option value="fr">Français</option>
            </select>
          </div>
          <input type="hidden" v-model="picdata" name='picdata'/>
          <span style='color: red;'>{{ error }}</span>
          <button class="btn btn-lg btn-primary btn-block" type="submit">Register</button>
        </form>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios'
export default {
  data () {
    return {
      file: '',
      username: '',
      fname: '',
      lname: '',
      email: '',
      password: '',
      language: '',
      error: '',
      image: '',
      img: 'static/img/anony.png'
    }
  },
computed: {
    picdata: {
        get(){
            return this.image;
        }
    }
  },
  methods: {
    onFileChange(e) {
   
      var files = e.target.files || e.dataTransfer.files;
      if (!files.length)
        return;
      this.createImage(files[0]);
    },
    createImage(file) {
      var image = new Image();
      var reader = new FileReader();

      reader.onload = (e) => {
        this.image = e.target.result;
      };
      reader.readAsDataURL(file);
    },
    removeImage: function (e) {
      this.image = '';
    },
    getvalue() {
      return this.image
    },
   
    async register () {
    try{
        await axios.post('users/register', {
        username: this.username,
        fname: this.fname,
        lname: this.lname,
        email: this.email,
        password: this.password,
        lang: this.language,
        picdata: this.picdata
      }).then(res => {
        if (this.username === '' || this.fname === '' || this.lname === '' || this.email === '' || this.password === '' || this.picdata == '') {
          this.error = 'Please fill all the fields'
        } else if (res.data === 'User already exists') {
          this.error = 'User already exists'
        } else if(res.data === 'Please type a valid email') {
          this.error = 'Please type a valid email'
        } else if(res.data === 'Please type a valid username') {
          this.error = 'Please type a valid username'
        } else if(res.data === 'Please type a valid first name') {
          this.error = 'Please type a valid first name'
        } else if(res.data === 'Please type a valid last name') {
          this.error = 'Please type a valid last name'
        } else if(res.data === 'Please type a valid password') {
          this.error = 'Please type a valid password'
        } else if (res.data === 'Email already exists'){
          this.error = 'Email already exists'
        } else if (res.data === 'Invalid image'){
          this.error = 'Invalid image'
        } else {
          this.error = 'Please check your email'
        }
      }).catch(err => {
        console.log(err)
      })
    }
    catch(err) {
      console.log(err)
      
    }
    }
  }
}
</script>

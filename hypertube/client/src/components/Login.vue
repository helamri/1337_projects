<template>
  <div class="container">
    <div class="row">
      <div class="col-md-6 mt-5 mx-auto">
        <form v-on:submit.prevent="login">
          <h1 class="h3 mb-3 font-weight-normal text-center">Sign in directly</h1>
         <div class="container">
  <div class="row justify-content-center">
    <div class="col-3 text-center">
      <a href="http://localhost:5000/auth/42"><img style="width:3em; height:3em;" :src="fortytwo" /></a>
    </div>
    <div class="col-3 border-left text-center">
      <a href="http://localhost:5000/auth/twitter"><img style="width:3em; height:3em;" :src="twitter" /></a>
    </div>
     <div class="col-3 border-left text-center">
      <a href="http://localhost:5000/auth/github"><img style="width:3em; height:3em;" :src="github" /></a>
    </div>
  </div>
</div>
          <h1 class="h3 mb-3 font-weight-normal text-center">Or sign in using your account</h1>
          <div class="form-group text-center">
            <label for="username">Username</label>
            <input type="text" v-model="username" class="form-control text-center" name="username" placeholder="Enter Your Username">
          </div>
          <div class="form-group text-center">
            <label for="password">Password</label>
            <input type="password" v-model="password" class="form-control text-center" name="password" placeholder="Enter Password">
          </div>
          <div class="row justify-content-center">
            <div v-if="error == ''" class="col-6 text-center">
              <router-link to='/forget'><img style="width:2em; height:2em;" :src="forget" /></router-link>
            </div>
              <div v-else="error != ''" class="col-4 text-center">
              <router-link to='/forget'><img style="width:2em; height:2em;" :src="forget" /></router-link>
            </div>
            <div v-if="error == ''" class="col-6 border-left text-center">
              <router-link to='/register'><img style="width:2em; height:2em;" :src="register" /></router-link>
        </div>
              <div v-else="error != ''" class="col-4 border-left text-center">
          <router-link to='/register'><img style="width:2em; height:2em;" :src="register" /></router-link>
        </div>
        <div v-if="error != ''">
          <div class="col-4 border-left text-center">
          <span style='color: red; text-align: center'>{{ error }}</span>
        </div>
      </div>
      </div>
          <button class="btn btn-lg btn-primary btn-block" type="submit">Sign in</button>
        </form>
      </div>
    </div>
  </div>
</template>

<script>
  import axios from 'axios'
  import router from '../router'
  import EventBus from './EventBus'
  export default {
    data () {
      return {
        username: '',
        password: '',
        error: '',
        auth: '',
        fortytwo: 'static/img/42.png',
        twitter: 'static/img/twitter.png',
        github: 'static/img/github.png',
        facebook: 'static/img/facebook.png',
        forget: 'static/img/forget.png',
        register: 'static/img/register.png'
      }
    },
    methods: {
      login () {
        axios.post('users/login', {
          username: this.username,
          password: this.password
        }).then(res => {
          if (res.data === 'User does not exist' || res.data === 'Password wrong' || res.data === 'Please go to your email to confirm it') {
            this.error = res.data
            this.username = ''
            this.password = ''
          } else {
            this.emitMethod()
            localStorage.setItem('usertoken', res.data)
            router.push({ name: 'Profile' })
            window.location.reload()
          }
        }).catch(err => {
          console.log(err)
        })
      },
    emitMethod () {
      EventBus.$emit('logged-in', 'loggedin');
    }
  },
   mounted () {
        EventBus.$on('logged-in', status => {
          this.auth = status
    });
      }
}
</script>

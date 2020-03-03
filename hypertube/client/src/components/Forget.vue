<template>
    <div class="container">
        <div class="row">
            <div class="col-md-6 mt-5 mx-auto">
                <form v-on:submit.prevent="forget">
                    <h1 class="h3 mb-3 font-weight-normal">Please type your email</h1>
                    <div class="form-group">
                        <label for="username">Email</label>
                        <input type="email" v-model="email" class="form-control" name="email" placeholder="Type your email">
                    </div>
                    <span style='color: red; text-align: center'>{{ error }}</span>
                    <button class="btn btn-lg btn-primary btn-block" type="submit">Reset Password</button>
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
      email: '',
      error: ''
    }
  },
  methods: {
    forget () {
      axios.post('users/forget', {
        email: this.email
      }).then(res => {
          this.error = res.data
          this.email = ''
      }).catch(err => {
        console.log(err)
      })
    }
  }
}
</script>

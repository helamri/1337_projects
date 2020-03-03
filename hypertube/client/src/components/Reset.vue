<template>
    <div class="container">
        <div class="row">
            <div class="col-md-6 mt-5 mx-auto">
                <form v-on:submit.prevent="reset">
                    <h1 class="h3 mb-3 font-weight-normal">Please type your new password</h1>
                    <div class="form-group">
                        <label for="npassword"></label>
                        <input type="password" v-model="npassword" class="form-control" name="npassword" placeholder="Type the new password">
                    </div>
                    <div class="form-group">
                        <label for="renpassword"></label>
                        <input type="password" v-model="renpassword" class="form-control" name="renpassword" placeholder="Confirm the new password">
                    </div>
                    <span style='color: red; text-align: center'>{{ error }}</span>
                    <button class="btn btn-lg btn-primary btn-block" type="submit">Submit</button>
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
      npassword: '',
      renpassword: '',
      error: ''
    }
  },
  methods: {
    reset () {
      axios.post('users/reset', {
        fortoken: this.$route.query.token,
        npassword: this.npassword,
        renpassword: this.renpassword
      }).then(res => {
        if (res.data === 'The password and confirmation password do not match' || res.data === 'Please fill all the fields' || res.data === 'Invalid token') {
          this.error = res.data
          this.npassword = ''
          this.renpassword = ''
        } else {
          router.push({ name: 'Login' })
        }
      }).catch(err => {
        console.log(err)
      })
    }
  }
}
</script>

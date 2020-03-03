<template>
    <div class="container">
        <div class="row">
            <div class="col-md-6 mt-5 mx-auto">
              <form v-on:submit.prevent="verified">
                    <div class="form-group">
                        <img style="border-radius: 50%" src="https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/6a8dc32c-ce1d-4dd6-b830-96abd2b70091/dcm66nu-913e5d7d-7438-4456-8bca-c09ce86ae6ac.jpg/v1/fill/w_1024,h_370,q_75,strp/hypertube_acceleration_station_by_haltenny_dcm66nu-fullview.jpg?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOjdlMGQxODg5ODIyNjQzNzNhNWYwZDQxNWVhMGQyNmUwIiwiaXNzIjoidXJuOmFwcDo3ZTBkMTg4OTgyMjY0MzczYTVmMGQ0MTVlYTBkMjZlMCIsIm9iaiI6W1t7ImhlaWdodCI6Ijw9MzcwIiwicGF0aCI6IlwvZlwvNmE4ZGMzMmMtY2UxZC00ZGQ2LWI4MzAtOTZhYmQyYjcwMDkxXC9kY202Nm51LTkxM2U1ZDdkLTc0MzgtNDQ1Ni04YmNhLWMwOWNlODZhZTZhYy5qcGciLCJ3aWR0aCI6Ijw9MTAyNCJ9XV0sImF1ZCI6WyJ1cm46c2VydmljZTppbWFnZS5vcGVyYXRpb25zIl19.m-QJuAo8J1RkAgoTUPD4xWUTh-DstIsEloHyldkWXkg">
                    </div>
                    <span style='color: red; text-align: center'>{{ error }}</span>
                    <button class="btn btn-lg btn-primary btn-block" type="submit">Click here to verify</button>
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
      error: ''
    }
  },
  methods: {
    verified () {
      axios.post('users/verified', {
        fortoken: this.$route.query.token,
      }).then(res => {
        if (res.data === 'Invalid token') {
          this.error = res.data
        } else if (res.data === 'Your account has been verified!') {
          this.error = res.data
        }
      }).catch(err => {
        console.log(err)
      })
    }
  }
}
</script>

<template>
</template>

<script>
  import router from '../router'
  import axios from 'axios'
  import EventBus from './EventBus'
  import jwtDecode from 'jwt-decode'
  export default {
    data () {
      return {
          token: this.$route.query.token
      }
    },
    methods: {
      async auth () {
          await localStorage.setItem('usertoken', this.token)
          const tokenn = localStorage.getItem('usertoken');
        const decoded = jwtDecode(tokenn)
        var atoken = decoded
          axios.get('users/profile/'+atoken)
          .then(response => {
          })
    
            this.emitMethod()
            router.push({ name: 'Profile' })
          },
    emitMethod () {
      EventBus.$emit('logged-in', 'loggedin');
    }
  },
   mounted () {
        EventBus.$on('logged-in', status => {
          this.auth = status
    });
      },
  async beforeMount(){
    await this.auth();
  }
}
</script>

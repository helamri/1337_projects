<template>
  <nav class="navbar navbar-expand-lg navbar-dark bg-dark rounded">
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar1" aria-controls="navbar1" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <img src="/static/img/devil.png" style="height: 3em:">
    <div class="collapse navbar-collapse justify-content-md-center" id="navbar1">
      <ul class="navbar-nav">
        <li class="nav-item"><router-link class="nav-link" to="/">Home</router-link></li>
        <li v-if="auth==''" class="nav-item"><router-link class="nav-link" to="/login">Login</router-link></li>
        <li v-if="auth==''" class="nav-item"><router-link class="nav-link" to="/register">Register</router-link></li>
        <li v-if="auth=='loggedin' && lang == 'en'" class="nav-item"><router-link class="nav-link" to="/list">List</router-link></li>
        <li v-else-if="auth=='loggedin' && lang == 'fr'" class="nav-item"><router-link class="nav-link" to="/list">Liste</router-link></li>
        <li v-else-if="auth=='loggedin'" class="nav-item"><router-link class="nav-link" to="/list">List</router-link></li>
        <li v-if="auth=='loggedin' && lang == 'en'" class="nav-item"><router-link class="nav-link" to="/profile">Profile</router-link></li>
        <li v-else-if="auth=='loggedin' && lang == 'fr'" class="nav-item"><router-link class="nav-link" to="/profile">Profil</router-link></li>
        <li v-else-if="auth=='loggedin'" class="nav-item"><router-link class="nav-link" to="/profile">Profile</router-link></li>
        <li v-if="auth=='loggedin' && lang == 'en'" class="nav-item"><router-link class="nav-link" to="/watch">Favorite list</router-link></li>
        <li v-else-if="auth=='loggedin' && lang == 'fr'" class="nav-item"><router-link class="nav-link" to="/watch">Liste des favoris</router-link></li>
        <li v-else-if="auth=='loggedin'" class="nav-item"><router-link class="nav-link" to="/watch">Favorite list</router-link></li>
        <li v-if="auth=='loggedin' && lang == 'en'" class="nav-item"><a class="nav-link" href="" v-on:click="logout">Logout</a></li>
        <li v-else-if="auth=='loggedin' && lang == 'fr'" class="nav-item"><a class="nav-link" href="" v-on:click="logout">Se déconnecter</a></li>
        <li v-else-if="auth=='loggedin'" class="nav-item"><a class="nav-link" href="" v-on:click="logout">Logout</a></li>
      </ul>
    </div>
  </nav>
</template>

<script>
import EventBus from './EventBus'
import jwtDecode from 'jwt-decode'
import axios from 'axios'

EventBus.$on('logged-in', test => {
})

export default {
  data () {
    return {
      auth: '',
      lang: ''
    }
  },
  methods: {
  getlang () {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem('usertoken');
        const decoded = jwtDecode(token)
        var username = decoded.username
        axios.post('users/getlanguage', {
        username: username
        }).then(response => {
        this.lang = response.data.lang
          })
      }
  },
    logout () {
      localStorage.removeItem('usertoken')
      router.push({ name: 'Login' })
    }
  },
  mounted () {
    EventBus.$on('logged-in', status => {
      this.auth = status
    });
    const isLogged = localStorage.getItem('usertoken');
    if (isLogged)
      EventBus.$emit('logged-in', 'loggedin');
  },
  async beforeMount() {
    await this.getlang();
  }
}
</script>

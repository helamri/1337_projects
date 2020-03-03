<template>
	<div class="container">
		<div class="jambotron mt-5">
			<h1 v-if="lang == 'en'" class="text-center" style="color: #FFFFFF">Are you ready?!</h1>
			<h1 v-else-if="lang == 'fr'" class="text-center" style="color: #FFFFFF">Es-tu prêt?!</h1>
			<h1 v-else class="text-center" style="color: #FFFFFF">WELCOME</h1>
			<div align="center"><img style="width:47em; height:47em; border-radius: 50%" :src="cinema" /></div>
		</div>
	</div>
</template>

<script>
import axios from "axios";
import router from "../router";
import jwtDecode from "jwt-decode";
export default {
  data() {
    return {
    	lang: '',
      cinema: 'static/img/cinema.gif',
      title: '',
      imdb: ''
    };
  },
  methods: {
  pic () {
  if (!localStorage.getItem("usertoken")) 
  	router.push({ name: "Login" });
  else if(this.title != '' && this.imdb != '')
  	router.push({ path: `/movie?title=${this.title}&imdb=${this.imdb}` })
  else if(this.title != '' || this.imdb != '')
    router.push({ name: "List" });
    },
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
  async getrandmov () {
    var page = Math.floor(Math.random() * 301);
    var film = Math.floor(Math.random() * 50);
    var url = 'https://tv-v2.api-fetch.website/movies/'+page+'?sort=year&order=1'
      await fetch(url)
        .then(response=>response.json())
        .then(data=>{
          this.title = data[film].title
          this. imdb = data[film].imdb_id
        })
  }
  },
  created () {
    this.$options.interval = setInterval(this.pic, 5000) 
  },
  beforeDestroy () {
    clearInterval(this.$options.interval)
  },
  async beforeMount() {
    await this.getlang();
    await this.getrandmov();
  }
};
</script>
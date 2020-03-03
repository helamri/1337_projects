<template>
    <div class="container" style="margin-left: auto;margin-right: auto;display: block;">
  <div v-if="film !== undefined">
    <div v-for="item in film">
      <div v-if="item.title !== undefined && item.imdb !== undefined">
      <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title.replace('#','')+'&imdb='+item.imdb"><h2 style="color:black;text-shadow: 0 0 2px #000">{{item.title}}</h2></a>
      <button @click="deleteit(item.title)"><font-awesome-icon icon="trash-alt"/></button>
    </div>
    <div v-if="item.poster !== undefined">
         <img v-if="item.poster" style="width:25%;height:25%;" :src="item.poster"/>
        <img v-else-if="item.poster" style="width:25%;height:25%;" :src="noposter">
    </div>
    <div id="MyLines">
  <svg class="MyLineLeft" height="10" width="150">
    <line x1="150" y1="5" x2="10" y2="5" style="stroke:rgb(255,0,0);stroke-width:8" />
  </svg>
  <svg class="MyLineRight" height="10" width="150">
    <line x1="0" y1="5" x2="140" y2="5" style="stroke:rgb(255,0,0);stroke-width:8" />
  </svg>
  </div>
    </div>
  </div>
  <div>
    <img style="width:25%;height:25%;" :src="nothing"/>
  </div>
</div>
</template>

<script>
import jwtDecode from 'jwt-decode'
import axios from 'axios'

export default {
  data () {

    return {
      film: [],
      noposter: 'static/img/noposter.png',
      nothing: 'static/img/nothing.gif'
    }
  },
  methods: {
    getsaved () {
    if (localStorage.getItem("usertoken"))
    {
        const token = localStorage.getItem('usertoken');
        const decoded = jwtDecode(token)
        var username = decoded.username
        axios.get('users/getmovs/'+username)
          .then(response => {
            this.film = response.data
      })
    }
  },
  deleteit (title) {
  if (localStorage.getItem("usertoken"))
    {
    const token = localStorage.getItem('usertoken');
        const decoded = jwtDecode(token)
        var username = decoded.username
        try { axios.post('users/deletewatch', {
          title: title,
          username: username
          }).then(response => {
            window.location.reload()
          })
        }
        catch(err){
          console.log("error")
        }
      }
  }
  },
  async beforeMount(){
    await this.getsaved();
  }
}
</script>
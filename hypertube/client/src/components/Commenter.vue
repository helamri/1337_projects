<template>
    <div class="container">
        <div v-if="data != ''" class="jumbotron mt-5">
            <div class="col-sm-8 mx-auto">

                <h1 v-if="lang == 'en'" class="text-center">{{username}} PROFILE</h1>
                <h1 v-else-if="lang == 'fr'" class="text-center">{{username}} PROFIL</h1>

            </div>

            <table class="table col-md-6 mx-auto">
                <tbody>
                    <tr>
                      <td align="center"><img style="width:7em; height:7em; border-radius: 50%" :src="image" /></td>
                    </tr>
                    <tr>
                        
                        <td v-if="lang == 'en'">First Name:</td>
                        <td v-else-if="lang == 'fr'">Prénom:</td>
                        <td><h1>{{fname}}</h1></td>
                    </tr>
                    <tr>
                       
                        <td v-if="lang == 'en'">Last Name:</td>
                        <td v-else-if="lang == 'fr'">Nom de famille:</td>
                        <td><h1>{{lname}}</h1></td>
                    </tr>
                </tbody>
            </table>
        </div>
        <div v-else-if="data == ''" class="jumbotron mt-5">
          <h1 class="text-center" style="margin-left: auto;margin-right: auto;display: block;color: #343a40">The user was removed</h1>
          <img style="width:25%;height:25%;margin-left: auto;margin-right: auto;display: block;" :src="nothing"/>
        </div>
    </div>
</template>

<script>
import jwtDecode from 'jwt-decode'
import router from "../router";
import axios from 'axios'

export default {
  data () {

    return {
      username: this.username,
      fname: this.fname,
      lname: this.lname,
      lang: this.lang,
      image: this.image,
      data: '',
      nothing: 'static/img/nothing.gif'

    }
  },
    beforeCreate () {
      if(!localStorage.getItem('usertoken'))
        router.push({ name: 'Login' })
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
    getInfo () {
        var username = this.$route.query.username
            axios.get('users/getcommenter/'+username)
            .then(response => {
            if(response.data)
              this.data = response.data
            if(this.data[0] != '')
            {
              this.username = this.data[0].username
              this.fname = this.data[0].fname
              this.lname = this.data[0].lname
              this.lang = this.data[0].lang
              this.image = this.data[0].image
            }
            })
            .catch(e => {
                console.log('')
            })
        }
  },
  async beforeMount() {
    await this.getInfo();
    await this.getlang();
  }
}
</script>
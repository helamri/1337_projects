<template>
    <form @submit.prevent="profile">
    <div class="container">
        <div class="jumbotron mt-5">
            <div class="col-sm-8 mx-auto">

                <h1 v-if="lang == 'en'" class="text-center">{{username}} PROFILE</h1>
                <h1 v-else-if="lang == 'fr'" class="text-center">{{username}} PROFIL</h1>

            </div>

            <table class="table col-md-6 mx-auto">
                <tbody>
                    <tr>
                      <td align="center"><input style="display: none" ref="fileInput" type="file" @change="onFileChange" name="file" id="input-files"/>
                          <button @click="$refs.fileInput.click()"><font-awesome-icon icon="camera"/></button></td>
                      <td align="center"><img style="width:7em; height:7em; border-radius: 50%" :src="image" /></td>
                      <td align="center"><button @click="reloadPage()"><font-awesome-icon icon="upload"/></button></td>
                    </tr>
                    <tr>
                        <td v-if="lang == 'en'">Username:</td>
                        <td v-else-if="lang == 'fr'">Nom d'utilisateur:</td>
                        <td><input class="text-center" style="width: 15em;" v-model="username" type="text" :disabled="disabledun == 1"></td>
                        <td><button @click="disabledun = (disabledun + 1) % 2"><font-awesome-icon v-if="disabledun == 1" icon="pencil-alt"/><font-awesome-icon v-else="disabledun == 0" icon="save"/></button></td>
                    </tr>
                    <tr>
                        
                        <td v-if="lang == 'en'">First Name:</td>
                        <td v-else-if="lang == 'fr'">Prénom:</td>
                        <td><input class="text-center" style="width: 15em;" v-model="fname" type="text" :disabled="disabledfn == 1"></td>
                        <td><button @click="disabledfn = (disabledfn + 1) % 2"><font-awesome-icon v-if="disabledfn == 1" icon="pencil-alt" /><font-awesome-icon v-else="disabledun == 0" icon="save"/></button></td>
                    </tr>
                    <tr>
                       
                        <td v-if="lang == 'en'">Last Name:</td>
                        <td v-else-if="lang == 'fr'">Nom de famille:</td>
                        <td><input class="text-center" style="width: 15em;" v-model="lname" type="text" :disabled="disabledln == 1"></td>
                        <td><button @click="disabledln = (disabledln + 1) % 2"><font-awesome-icon v-if="disabledln == 1" icon="pencil-alt" /><font-awesome-icon v-else="disabledun == 0" icon="save"/></button></td>
                    </tr>
                    <tr>
                      
                        <td v-if="lang == 'en'">Password:</td>
                        <td v-else-if="lang == 'fr'">Mot de passe:</td>
                        <td v-if="lang == 'en'"><input class="text-center" placeHolder="Change Password" style="width: 15em;" v-model="password" type="password" :disabled="disabledps == 1"></td>
                        <td v-else-if="lang == 'fr'"><input class="text-center" placeHolder="Changer le mot de passe" style="width: 15em;" v-model="password" type="password" :disabled="disabledps == 1"></td>
                        <td><button @click="disabledps = (disabledps + 1) % 2"><font-awesome-icon v-if="disabledps == 1" icon="pencil-alt" /><font-awesome-icon v-else="disabledun == 0" icon="save"/></button></td>
                    </tr>
                    <tr>
                        <td v-if="lang == 'en'">Email:</td>
                        <td v-else-if="lang == 'fr'">Email:</td>
                        <td><input class="text-center" style="width: 15em;" v-model="email" type="text" :disabled="disabledem == 1"></td>
                        <td><button style='width:80%;' @click="disabledem = (disabledem + 1) % 2"><font-awesome-icon v-if="disabledem == 1" icon="pencil-alt" /><font-awesome-icon v-else="disabledun == 0" icon="save"/></button></td>
                    </tr>
                    <tr>
                   
                    <td v-if="lang == 'en'">Default Language:</td>
                    <td v-else-if="lang == 'fr'">Langage par défaut:</td>
            <td><select style="width:90%" name="lang" v-model="lang" :disabled="disableddl == 1">
           
              <option v-model="lang">en</option>
              <option v-model="lang">fr</option>
            </select></td>
            <td><button style='width:80%;' @click="disableddl = (disableddl + 1) % 2"><font-awesome-icon v-if="disableddl == 1" icon="pencil-alt" /><font-awesome-icon v-else="disabledun == 0" icon="save"/></button></td>
  
          </tr>
                    <tr>
                      <td></td>
                      <td v-if="lang == 'en'"><button class="btn-danger" style="width: 15em;" @click="deleteAccount()">Remove your account</button></td>
                      <td v-else-if="lang == 'fr'"><button class="btn-danger" style="width: 15em;" @click="deleteAccount()">Supprimer votre compte</button></td>
                      <td></td>
                    </tr>
                    <input v-model="picdata" type="hidden" name='picdata'/>
                </tbody>
            </table>
        </div>
    </div>
     </form>
</template>

<script>
import jwtDecode from 'jwt-decode'
import router from '../router'
import axios from 'axios'

export default {
  data () {

    return {
      username: this.username,
      fname: this.fname,
      lname: this.lname,
      email: this.email,
      lang: this.lang,
      password: '',
      image: this.image,
      disabledun: 1,
      disabledfn: 1,
      disabledln: 1,
      disabledps: 1,
      disabledem: 1,
      disableddl: 1,
      user: []

    }
  },
  created: function(){
        this.getInfo();

    },
    computed: {
    picdata: {
        get(){
            return this.image;
        }
    }
  },
  methods: {
    async deleteAccount(){
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem('usertoken');
        const decoded = jwtDecode(token)

        axios.post('users/deleteAccount', {atoken: decoded.atoken, username: decoded.username})
    localStorage.removeItem('usertoken')
      router.push({ name: 'Login' })
      window.location.reload()
      }
    },
    reloadPage(){
    window.location.reload()
  },
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
    getInfo: function(){
    if (localStorage.getItem("usertoken"))
    {
        const token = localStorage.getItem('usertoken');
        const decoded = jwtDecode(token)
        var id = decoded.atoken
            axios.get('users/profile/'+id)
            .then(response => {
              this.user = response.data
              this.username = this.user.username
              this.fname = this.user.fname
              this.lname = this.user.lname
              this.email = this.user.email
              this.lang = this.user.lang
              this.image = this.user.image

            })
            .catch(e => {
                console.log(e)
            })
            }
        },
    profile () {
    if (localStorage.getItem("usertoken"))
    {
        const token = localStorage.getItem('usertoken');
        const decoded = jwtDecode(token)
      axios.post('users/profile', {
        username: this.username,
        fname: this.fname,
        lname: this.lname,
        email: this.email,
        lang: this.lang,
        password: this.password,
        picdata: this.picdata,
        id: decoded.atoken
      }).then(res => {
      }).catch(err => {
        console.log(err)
      })
      }
  }
  }
}
</script>

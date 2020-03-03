<template>
        <video :poster="movie" id="videoPlayer" controls autoplay crossorigin="anonymous" controlsList="nodownload" width="93%"> 
      <source :src="'http://localhost:5000/users/streami/'+hash+'/'+imdb+'/'+language" type="video/mp4">
                <source v-if="sub[0]" type="video/mp4">
                <track v-if="sub[0]" kind="subtitles" :src="'static/subs/'+hash+'/'+sub[0]" :srclang="language" :label="label" type="TextTrack" default/>
                <source v-if="sub[1]" type="video/mp4">
                <track v-if="sub[1]" kind="subtitles" :src="'static/subs/'+hash+'/'+sub[1]" :srclang="langarab" :label="labelarab" type="TextTrack"/>
                <source v-if="sub[2]" type="video/mp4">
                <track v-if="sub[2]" kind="subtitles" :src="'static/subs/'+hash+'/'+sub[2]" :srclang="langother" :label="labelother" type="TextTrack"/>
      </video>
</template>

<script>
import axios from 'axios'
import router from '../router'
import jwtDecode from 'jwt-decode'
export default {
	 data () {
        return {
            hash:this.$route.query.mov,
            imdb:this.$route.query.imdb,
            sub: [],
            language: '',
            label: '',
            langarab: '',
            langother: '',
            labelarab: '',
            labelother: '',
            movie: 'static/img/movie.jpg'
        }
    },
    beforeCreate () {
    	if(!localStorage.getItem('usertoken'))
    		router.push({ name: 'Login' })
    },
  created: function(){
        this.watch();
        this.getvtt();

    },
    methods: {
    	getvtt: function() {
    		if(localStorage.getItem('usertoken'))
    		{
    			const token = localStorage.getItem('usertoken');
        		const decoded = jwtDecode(token)
       		 	this.language = decoded.language
       		 	if(decoded.language == 'en')
       		 		this.label = 'English'
       		 	else if(decoded.language == 'fr')
       		 		this.label = 'French'
    			axios.get('users/getvtt/'+this.hash+'/'+this.language)
            	.then(response => {
              if(response.data.length > 0 && response.data != 'no data')
              {
              	this.sub = response.data
                if(this.sub[1])
                {
                if(this.sub[1].endsWith("_arabic_.vtt")){
                  this.langarab = 'ar'
                  this.labelarab = 'Arabic'
                }else if(this.sub[1].endsWith("_french_.vtt")){
                  this.langarab = 'fr'
                  this.labelarab = 'Frensh'
                }else if(this.sub[1].endsWith("_english_.vtt")){
                  this.langarab = 'en'
                  this.labelarab = 'English'
                }}
                if(this.sub[1])
                {
                if(this.sub[2].endsWith("_arabic_.vtt")){
                  this.langother = 'ar'
                  this.labelother = 'Arabic'
                }else if(this.sub[2].endsWith("_french_.vtt")){
                  this.langother = 'fr'
                  this.labelother = 'Frensh'
                }else if(this.sub[2].endsWith("_english_.vtt")){
                  this.langother = 'en'
                  this.labelother = 'English'
                }}
              }
    			})
    		}
    		else
    		{
    			this.sub = 'nothing'
    			this.language = 'en'
    			this.imdb = 'tt1179933'
    			this.hash = '5B02013B7DC5EDF4277CF83C63ECA643A2F2D3DC'
    		}
    	},

      watch () {
      if(localStorage.getItem('usertoken'))
        {
        var imdb = this.$route.query.imdb
        const token = localStorage.getItem('usertoken');
            const decoded = jwtDecode(token)
            var username = decoded.username
        axios.post('users/postwatch', {
          imdb: imdb,
        username: username,
        }).then(response => {
          })
          }
      }
	}
}
</script>

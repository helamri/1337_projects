<template>
    <div class="container-movies">
        <div class="row" v-if="!apimadomainList.MovieList || !moviesList">
        <div class="main">
            <input v-if="lang == 'en'" type="text" v-model="search" placeholder="Name of the movie" class="form-control text-center">
            <input v-else-if="lang == 'fr'" type="text" v-model="search" placeholder="Nom du film" class="form-control text-center">
    </div>
            <div style="width:100%; margin:auto;" class="row text-center">
                <div class="col-4 dropdown">
                  <button v-if="lang == 'en'" class="btn btn-lg btn-success btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Sort</button>
                  <button v-else-if="lang == 'fr'" class="btn btn-lg btn-success btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Trier</button>
                  <div class="dropdown-menu" aria-labelledby="dropdownMenuButton">
                    <a v-if="lang == 'en'" v-on:click="sorttitlist" class="dropdown-item" href="#">Title</a>
                    <a v-else-if="lang == 'fr'" v-on:click="sorttitlist" class="dropdown-item" href="#">Titre</a>
                    <a v-if="lang == 'en'" v-on:click="firstList" class="dropdown-item" href="#">Rating</a>
                    <a v-else-if="lang == 'fr'" v-on:click="firstList" class="dropdown-item" href="#">Classement</a>
                    <a v-if="lang == 'en'" v-on:click="soryealist" class="dropdown-item" href="#">Year</a>
                    <a v-else-if="lang == 'fr'" v-on:click="soryealist" class="dropdown-item" href="#">Année</a>
                </div>
            </div>
            <div class="col-4">
              <button v-if="lang == 'en'" v-on:click="searchMovie" class="btn btn-lg btn-primary btn-block">Search</button>
              <button v-else-if="lang == 'fr'" v-on:click="searchMovie" class="btn btn-lg btn-primary btn-block">Recherche</button>
          </div>
          <div class="col-4 dropdown">
              <button v-if="lang == 'en'" class="btn btn-lg btn-danger btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Filter</button>
              <button v-else-if="lang == 'fr'" class="btn btn-lg btn-danger btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Filtre</button>
              <div class="dropdown-menu" style="height:200px;overflow-y:auto;" aria-labelledby="dropdownMenuButton">
                <a v-on:click="filteringlist('Action')" class="dropdown-item" href="#">Action</a>
                <a v-on:click="filteringlist('Adventure')" class="dropdown-item" href="#">Adventure</a>
                <a v-on:click="filteringlist('Animation')" class="dropdown-item" href="#">Animation</a>
                <a v-on:click="filteringlist('Comedy')" class="dropdown-item" href="#">Comedy</a>
                <a v-on:click="filteringlist('Crime')" class="dropdown-item" href="#">Crime</a>
                <a v-on:click="filteringlist('Documentary')" class="dropdown-item" href="#">Documentary</a>
                <a v-on:click="filteringlist('Drama')" class="dropdown-item" href="#">Drama</a>
                <a v-on:click="filteringlist('Family')" class="dropdown-item" href="#">Family</a>
                <a v-on:click="filteringlist('Fantasy')" class="dropdown-item" href="#">Fantasy</a>
                <a v-on:click="filteringlist('History')" class="dropdown-item" href="#">History</a>
                <a v-on:click="filteringlist('Horror')" class="dropdown-item" href="#">Horror</a>
                <a v-on:click="filteringlist('Music')" class="dropdown-item" href="#">Music</a>
                <a v-on:click="filteringlist('Mystery')" class="dropdown-item" href="#">Mystery</a>
                <a v-on:click="filteringlist('Romance')" class="dropdown-item" href="#">Romance</a>
                <a v-on:click="filteringlist('science-fiction')" class="dropdown-item" href="#">Science Fiction</a>
                <a v-on:click="filteringlist('tv-movie')" class="dropdown-item" href="#">TV Movie</a>
                <a v-on:click="filteringlist('Thriller')" class="dropdown-item" href="#">Thriller</a>
                <a v-on:click="filteringlist('War')" class="dropdown-item" href="#">War</a>
                <a v-on:click="filteringlist('Western')" class="dropdown-item" href="#">Western</a>
            </div>
        </div>
    </div>
    <div v-for="item in beginList">
            <div class="container-movie">
                <div class="movie">
                    <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title.replace('#','')+'&imdb='+item.imdb_id"><div class="movie-inside front">
                        <img v-if="item.images.poster || item.images.poster != null" style="width:100%;height:100%;" v-bind:src="item.images.poster">
                        <img v-else="!item.images.poster || item.images.poster == null" style="width:100%;height:100%;" :src="noposter">
                    </div></a>
                    <div class="movie-inside back">
                        <div class="movie-details">
                            <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title.replace('#','')+'&imdb='+item.imdb_id"><h1>{{item.title}}<br><span v-if="item.year != null">{{item.year}}</span></h1></a>
                            <ul style="display: inline-block;" v-for="item in item.genres" class="movie-tags"><li><a>{{item}}</a></li></ul>
                            <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title.replace('#','')+'&imdb='+item.imdb_id"><p v-if="item.synopsis !== undefined && item.synopsis.length > 500" class="movie-synopsis">{{item.synopsis.substr(1, 500)}}...</p>
                            <p v-else="item.synopsis !== undefined && item.synopsis.length < 500" class="movie-synopsis">{{item.synopsis}}</p></a>
                        </div>
                    </div>
                </div>
            </div>
    </div>
</div>
<div class="row" v-else-if="apimadomainList.MovieList || moviesList">
    <div class="main">
            <input type="text" v-model="search" placeholder="Name of the movie" class="write form-control text-center">
    </div>
    <div style="width:100%; margin:auto;" class="row text-center">
                <div class="col-4 dropdown">
                  <button v-if="lang == 'en'" class="btn btn-lg btn-success btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Sort</button>
                  <button v-else-if="lang == 'fr'" class="btn btn-lg btn-success btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Trier</button>
                  <div class="dropdown-menu" aria-labelledby="dropdownMenuButton">
                    <a v-if="lang == 'en'" v-on:click="searchMovie" class="dropdown-item" href="#">Title</a>
                    <a v-else-if="lang == 'fr'" v-on:click="searchMovie" class="dropdown-item" href="#">Titre</a>
                    <a v-if="lang == 'en'" v-on:click="sortratSearch" class="dropdown-item" href="#">Rating</a>
                    <a v-if="lang == 'fr'" v-on:click="sortratSearch" class="dropdown-item" href="#">Classement</a>
                    <a v-if="lang == 'en'" v-on:click="soryeaSearch" class="dropdown-item" href="#">Year</a>
                    <a v-if="lang == 'fr'" v-on:click="soryeaSearch" class="dropdown-item" href="#">Année</a>
                </div>
            </div>
            <div class="col-4">
              <button v-if="lang == 'en'" v-on:click="searchMovie" class="btn btn-lg btn-primary btn-block">Search</button>
              <button v-else-if="lang == 'fr'" v-on:click="searchMovie" class="btn btn-lg btn-primary btn-block">Recherche</button>
          </div>
          <div class="col-4 dropdown">
              <button v-if="lang == 'en'" class="btn btn-lg btn-danger btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Filter</button>
              <button v-if="lang == 'fr'" class="btn btn-lg btn-danger btn-block" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Filtre</button>
              <div class="dropdown-menu" style="height:200px;overflow-y:auto;" aria-labelledby="dropdownMenuButton">
                <a v-on:click="filteringsearch('Action')" class="dropdown-item" href="#">Action</a>
                <a v-on:click="filteringsearch('Adventure')" class="dropdown-item" href="#">Adventure</a>
                <a v-on:click="filteringsearch('Animation')" class="dropdown-item" href="#">Animation</a>
                <a v-on:click="filteringsearch('Comedy')" class="dropdown-item" href="#">Comedy</a>
                <a v-on:click="filteringsearch('Crime')" class="dropdown-item" href="#">Crime</a>
                <a v-on:click="filteringsearch('Documentary')" class="dropdown-item" href="#">Documentary</a>
                <a v-on:click="filteringsearch('Drama')" class="dropdown-item" href="#">Drama</a>
                <a v-on:click="filteringsearch('Family')" class="dropdown-item" href="#">Family</a>
                <a v-on:click="filteringsearch('Fantasy')" class="dropdown-item" href="#">Fantasy</a>
                <a v-on:click="filteringsearch('History')" class="dropdown-item" href="#">History</a>
                <a v-on:click="filteringsearch('Horror')" class="dropdown-item" href="#">Horror</a>
                <a v-on:click="filteringsearch('Music')" class="dropdown-item" href="#">Music</a>
                <a v-on:click="filteringsearch('Mystery')" class="dropdown-item" href="#">Mystery</a>
                <a v-on:click="filteringsearch('Romance')" class="dropdown-item" href="#">Romance</a>
                <a v-on:click="filteringsearch('science-fiction')" class="dropdown-item" href="#">Science Fiction</a>
                <a v-on:click="filteringsearch('tv-movie')" class="dropdown-item" href="#">TV Movie</a>
                <a v-on:click="filteringsearch('Thriller')" class="dropdown-item" href="#">Thriller</a>
                <a v-on:click="filteringsearch('War')" class="dropdown-item" href="#">War</a>
                <a v-on:click="filteringsearch('Western')" class="dropdown-item" href="#">Western</a>
            </div>
        </div>
    </div>
    <div v-for="item in apimadomainList.MovieList">
            <div class="container-movie">
                <div class="movie">
                     <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title+'&imdb='+item.imdb"><div class="movie-inside front">
                        <img v-if="item.poster_big || item.poster_big != null" style="width:100%;height:100%;" v-bind:src="item.poster_big">
                        <img v-else="!item.poster_big || item.poster_big == null" style="width:100%;height:100%;" :src="noposter">
                    </div></a>
                    <div class="movie-inside back">
                        <div class="movie-details">
                             <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title+'&imdb='+item.imdb"><h1>{{item.title}}<br><span>{{item.year}}</span></h1></a>
                            <ul style="display: inline-block;" v-for="item in item.genres" class="movie-tags"><li><a>{{item}}</a></li></ul>
                             <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title+'&imdb='+item.imdb"><p v-if="item.description !== undefined && item.description.length > 500" class="movie-synopsis">{{item.description.substr(1, 500)}}...</p>
                             <p v-else="item.description !== undefined && item.description.length < 500" class="movie-synopsis">{{item.description}}</p></a>
                        </div>
                    </div>
                </div>
            </div>
    </div>
    <div v-for="item in moviesList">
            <div class="container-movie">
                <div class="movie">
                    <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title+'&imdb='+item.imdb_id"><div class="movie-inside front">
                        <img v-if="item.images.poster != 'N/A'" style="width:100%;height:100%;" v-bind:src="item.images.poster">
                        <img v-else="!item.images.poster || item.images.poster == 'N/A'" style="width:100%;height:100%;" :src="noposter">
                    </div></a>
                    <div class="movie-inside back">
                        <div class="movie-details">
                             <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title+'&imdb='+item.imdb_id"><h1>{{item.title}}<br><span>{{item.year}}</span></h1></a>
                            <ul style="display: inline-block;" v-for="item in item.genres" class="movie-tags"><li><a>{{item}}</a></li></ul>
                             <a style="text-decoration:none;" v-bind:href="'/movie?title='+ item.title+'&imdb='+item.imdb_id"><p v-if="item.synopsis !== undefined && item.synopsis.length > 500" class="movie-synopsis">{{item.synopsis.substr(1, 500)}}...</p>
                             <p v-else="item.synopsis !== undefined && item.synopsis.length < 500" class="movie-synopsis">{{item.synopsis}}</p></a>
                        </div>
                    </div>
                </div>
            </div>
    </div>
</div>
<div>
    <table class="table col-md-6 mx-auto">
        <tr>
            <td v-if="apimadomainList.MovieList" align="center"><button v-on:click="prePage"><font-awesome-icon icon="backward"/></button><button v-on:click="nextPage"><font-awesome-icon icon="forward"/></button></td>
            <td v-else-if="beginList" align="center"><button v-on:click="prePage2"><font-awesome-icon icon="backward"/></button><button  v-on:click="nextPage2"><font-awesome-icon icon="forward"/></button></td>
        </tr>
    </table>
</div>
</div>
</template>

<script>
import jwtDecode from 'jwt-decode'
import axios from 'axios'
    export default {
      data () {
        return {
            search:'',
            moviesList: [],
            themoviedbList : [],
            ytsList: [],
            apimadomainList: [],
            beginList: [],
            pagelist: 1,
            pagesearch: 1,
            url: '',
            url2: '',
            url3: '',
            filter: '',
            sort: '',
            lang: '',
            noposter: 'static/img/noposter.png'
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
      prePage () {
        if(this.pagesearch === 1)
            this.pagesearch = 1
        else
            this.pagesearch -= 1
        if (this.url2.indexOf('?sort=title') > -1 && this.url3.indexOf('?sort=title') > -1)
            this.searchMovie();
        else if (this.url2.indexOf('?sort=rating') > -1 && this.url3.indexOf('?sort=rating') > -1)
            this.sortratSearch()
        else if (this.url2.indexOf('?sort=year') > -1 && this.url3.indexOf('?sort=year') > -1)
            this.soryeaSearch()
        else
            this.filteringsearch(this.filter)

    },
    nextPage () {
        this.pagesearch += 1
        if (this.url2.indexOf('?sort=title') > -1 && this.url3.indexOf('?sort=title') > -1)
            this.searchMovie();
        else if (this.url2.indexOf('?sort=rating') > -1 && this.url3.indexOf('?sort=rating') > -1)
            this.sortratSearch()
        else if (this.url2.indexOf('?sort=year') > -1 && this.url3.indexOf('?sort=year') > -1)
            this.soryeaSearch()
        else
            this.filteringsearch(this.filter)

    },
    prePage2 () {
        if(this.pagelist === 1)
            this.pagelist = 1
        else
        {
            this.pagelist -= 1
        
        if (this.url.endsWith('?sort=title&order=1'))
            this.sorttitlist()
        else if (this.url.endsWith('?sort=rating&order=-1'))
            this.firstList();
        else if (this.url.endsWith('?sort=year&order=-1'))
            this.soryealist()
        else
            this.filteringlist(this.filter)
        }
    },
    nextPage2 () {
        this.pagelist += 1
        if (this.url.endsWith('?sort=title&order=1'))
            this.sorttitlist()
        else if (this.url.endsWith('?sort=rating&order=-1'))
            this.firstList();
        else if (this.url.endsWith('?sort=year&order=-1'))
            this.soryealist()
        else
            this.filteringlist(this.filter)
    },
    async sorttitlist () {
        this.sort = 'title'
        this.url = 'https://tv-v2.api-fetch.website/movies/'+this.pagelist+'?sort=title&order=1&genre='+this.filter
        await fetch(this.url)
        .then(response=>response.json())
        .then(data=>{
            this.beginList=data
        })
    },
    async soryealist () {
        this.sort = 'year'
        this.url = 'https://tv-v2.api-fetch.website/movies/'+this.pagelist+'?sort='+this.sort+'&order=-1&genre='+this.filter
        await fetch(this.url)
        .then(response=>response.json())
        .then(data=>{
            this.beginList=data
        })
    },
    async firstList () {
        this.sort = 'rating'
        this.url = 'https://tv-v2.api-fetch.website/movies/'+this.pagelist+'?sort='+this.sort+'&order=-1&genre='+this.filter
        await fetch(this.url)
        .then(response=>response.json())
        .then(data=>{
            this.beginList=data
        })
    },
    async sortratSearch () {
        if(this.search != '')
        {
            this.sort = 'rating'
          this.url2 = 'https://tv-v2.api-fetch.website/movies/'+this.pagesearch+'?sort='+this.sort+'&order=1&keywords='+this.search+'&genre='+this.filter+''
          await fetch(this.url2)
          .then(response=>response.json())
          .then(data=>{
            this.moviesList=data
        })
            this.url3 = 'https://api.apiumadomain.com/list?sort='+this.sort+'&page='+this.pagesearch+'&keywords='+this.search+'&genre='+this.filter+'';
          await fetch(this.url3)
          .then(response=>response.json())
          .then(data=>{
            this.apimadomainList=data

        })
      }
    },
    async soryeaSearch () {
        if(this.search != '')
        {
            this.sort = 'year'
          this.url2 = 'https://tv-v2.api-fetch.website/movies/'+this.pagesearch+'?sort='+this.sort+'&order=1&keywords='+this.search+'&genre='+this.filter+''
          await fetch(this.url2)
          .then(response=>response.json())
          .then(data=>{
            this.moviesList=data
        })
            this.url3 = 'https://api.apiumadomain.com/list?sort='+this.sort+'&page='+this.pagesearch+'&keywords='+this.search+'&genre='+this.filter+'';
          await fetch(this.url3)
          .then(response=>response.json())
          .then(data=>{
            this.apimadomainList=data

        })
      }
    },
    async searchMovie () {
        if(this.search != '')
        {
            this.sort = 'title'
          this.url2 = 'https://tv-v2.api-fetch.website/movies/'+this.pagesearch+'?sort='+this.sort+'&order=1&keywords='+this.search+'&genre='+this.filter+''
          await fetch(this.url2)
          .then(response=>response.json())
          .then(data=>{
            this.moviesList=data
        })
            this.url3= 'https://api.apiumadomain.com/list?sort='+this.sort+'&page='+this.pagesearch+'&keywords='+this.search+'&genre='+this.filter+'';
          await fetch(this.url3)
          .then(response=>response.json())
          .then(data=>{
            this.apimadomainList=data

        })
      }
  },
  async filteringlist (string) {
    this.filter = string
    this.url = 'https://tv-v2.api-fetch.website/movies/'+this.pagelist+'?sort='+this.sort+'&order=1&genre='+string
    await fetch(this.url)
    .then(response=>response.json())
    .then(data=>{
        this.beginList=data

    })
    this.url = ''
},
async filteringsearch (string) {
    this.filter = string
    if(this.search != '')
        {
          this.url2 = 'https://tv-v2.api-fetch.website/movies/'+this.pagesearch+'?sort='+this.sort+'&order=1&keywords='+this.search+'&genre='+this.filter+''
          await fetch(this.url2)
          .then(response=>response.json())
          .then(data=>{
            this.moviesList=data
        })
            this.url3 = 'https://api.apiumadomain.com/list?sort='+this.sort+'&page='+this.pagesearch+'&keywords='+this.search+'&genre='+this.filter+'';
          await fetch(this.url3)
          .then(response=>response.json())
          .then(data=>{
            this.apimadomainList=data

        })
        }
        this.url = ''

}
},
async beforeMount(){
    await this.firstList()
    await this.getlang();
},
}
</script>
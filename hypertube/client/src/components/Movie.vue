<template>
  <div v-if="themoviedbList.poster_big" class="movie-card bg-no-repeat bg-cover bg-white hero relative" :style="{ backgroundImage: `url(${themoviedbList.poster_big})` }">
    <div class="container">
      <div v-if="themoviedbList">
        <div class="row">
          <div class="col-md-9">
            <br />
            <a href="http://localhost:8080/list">
              <p v-if="lang == 'en'" style="color:blue;text-shadow: 0 0 3px #000">< Back</p>
              <p v-else-if="lang == 'fr'" style="color:blue;text-shadow: 0 0 3px #000">< Retour</p>
            </a>
            <br />
          </div>
          <div class="col-md-2">
            <br />
            <div v-if="watched == 'yes'">
              <a href="http://localhost:8080/watch">
                <p v-if="lang == 'en'" style="color:white;text-shadow: 0 0 3px #000">Your favorite list ></p>
                <p v-else-if="lang == 'fr'" style="color:white;text-shadow: 0 0 3px #000">Votre liste préférée ></p>
              </a>
            </div>
            <div v-else-if="watched == 'no'">
              <a v-on:click="savefilm">
                <p v-if="lang == 'en'" style="color:blue;text-shadow: 0 0 3px #000">Add to favorite list ></p>
                <p v-else-if="lang == 'fr'" style="color:blue;text-shadow: 0 0 3px #000">Ajouter à la liste des favoris ></p>
              </a>
            </div>
            <br />
          </div>
        </div>
        <div v-if="themoviedbList.trailer && themoviedbList.trailer != 'N/A'">
          <iframe
            width="93%"
            height="576"
            v-bind:src="'http://youtube.com/embed/'+themoviedbList.trailer"
          ></iframe>
        </div>
        <div v-else-if="movieData.trailer && movieData.trailer != 'N/A'">
          <iframe width="93%" height="576" :src="trailer"></iframe>
        </div>
        <div class="row">
          <div class="col-md-4" style="background-color: white;">
            <div v-if="themoviedbList.poster_big">
              <img style="width:100%;height:50%;" v-bind:src="themoviedbList.poster_big" />
            </div>
            <div v-else-if="movieData.images">
              <img
                v-if="movieData.images.poster || movieData.images.poster != null"
                style="width:100%;height:50%;"
                v-bind:src="movieData.images.poster"
              />
            </div>
            <img
              v-else
              style="width:100%;height:50%;"
              :src="noposter"
            />
            <div class="row">
              <div class="col-md-6">
                <div v-if="hash1080">
                  <a v-bind:href="'/streami?mov='+hash1080+'&imdb='+imdb">
                    <button v-if="lang == 'en'" type="button" class="btn btn-success">Watch 1080p</button>
                    <button v-else-if="lang == 'fr'" type="button" class="btn btn-success">Regarder 1080p</button>
                  </a>
                </div>
              </div>
              <div class="col-md-6">
                <div v-if="hash720">
                  <a v-bind:href="'/streami?mov='+hash720+'&imdb='+imdb">
                    <button v-if="lang == 'en'" type="button" class="btn btn-info">Watch 720p</button>
                    <button v-else-if="lang == 'fr'" type="button" class="btn btn-info">Regarder 720p</button>
                  </a>
                </div>
              </div>
            </div>
          </div>
          <div class="col-md-2" style="background-color: white;"></div>
          <div class="col-md-5" style="background-color: white;">
            <div class="row">
              <div class="col-md-6">
                <div v-if="themoviedbList.title && themoviedbList.title != 'N/A'">
                  <h2 style="color:red;text-shadow: 0 0 2px #000">{{themoviedbList.title}}</h2>
                </div>
                <div v-else-if="movieData.title && movieData.title != 'N/A'">
                  <h2 style="color:red;text-shadow: 0 0 2px #000">{{movieData.title}}</h2>
                </div>
              </div>
              <div class="col-md-6">
                <div v-if="vu == 'yes'">
                  <img style="width:42px;height:42px" :src="yes" />
                </div>
                <div v-else-if="vu == 'no'">
                  <img style="width:42px;height:42px" :src="no" />
                </div>
              </div>
            </div>
            <div v-if="themoviedbList.year && themoviedbList.year != 'N/A'">Year: {{themoviedbList.year}}</div>
            <div v-else-if="movieData.year && movieData.year != 'N/A'">Year: {{movieData.year}}</div>
            <div
              v-if="themoviedbList.runtime && themoviedbList.runtime != 'N/A'"
            >Runtime: {{themoviedbList.runtime}}</div>
            <div
              v-else-if="movieData.runtime && movieData.runtime != 'N/A'"
            >Runtime: {{movieData.runtime}}</div>
            <div v-if="themoviedbList.genres">
              Genres:
              <ul
                style="display: inline-block;"
                v-for="item in themoviedbList.genres"
                class="movie-tags"
              >
                
                <li>
                  <a>{{item}}</a>
                </li>
              </ul>
            </div>
            <div v-else-if="movieData.genres">
              Genres:
              <ul
                style="display: inline-block;"
                v-for="item in movieData.genres"
                class="movie-tags"
                >
                <li>
                  <a>{{item}}</a>
                </li>
              </ul>
            </div>
            <div
              v-if="themoviedbList.description && themoviedbList.description != 'N/A'"
            >Description: {{themoviedbList.description}}</div>
            <div
              v-else-if="movieData.synopsis && movieData.synopsis != 'N/A'"
            >Description: {{movieData.synopsis}}</div>
            <div
              v-if="themoviedbList.rating && themoviedbList.rating != 'N/A'"
            >Ratings: {{themoviedbList.rating}}</div>
            <div v-else-if="movieData.rating">
              Ratings:
              <ul>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.percentage && movieData.rating.percentage != 'N/A'"
                >Percentage: {{movieData.rating.percentage}}%</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.loved && movieData.rating.loved != 'N/A'"
                >Loves: {{movieData.rating.loved}}</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.hated && movieData.rating.hated != 'N/A'"
                >Hates: {{movieData.rating.hated}}</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.votes && movieData.rating.votes != 'N/A'"
                >Votes: {{movieData.rating.votes}}</li>
              </ul>
            </div>
            <div>
              <a v-on:click="likemov">
                <img style="width:52px;height:32px" :src="unlike" />
                {{likes}}
              </a>
            </div>
          </div>
        </div>
           <div class="col-md-11" style="background-color: white;">
          <div class="form__group field">
            <div v-if="lang == 'en'" class="form__field" style="text-align: center;color: #11998e;">Comments</div>
            <div v-else-if="lang == 'fr'" class="form__field" style="text-align: center;color: #11998e;">Commentaires</div>
            <div class="form__field" v-for="item in commentss">
              <a v-bind:href="'/commenter?username='+ item.commenter" style="text-decoration:none;"><b style="color: #11998e;">{{item.commenter}} :</b></a>
              {{item.comment}}
            </div>
          <form @submit.prevent="comment">
            <input
            placeholder="Type your comment"
              type="text"
              class="form__field"
              name="name"
              id="name"
              v-model="commentaire"
            />
            <button class="button button3" @click="reloadPage()"> </button>
          </form>
        </div>
        </div>
      </div>
      <div v-else>
        <h3>sorry there is no data</h3>
      </div>
    </div>
  </div>
  <div v-else-if="movieData.images" class="movie-card bg-no-repeat bg-cover bg-white hero relative" :style="{ backgroundImage: `url(${movieData.images.poster})` }">
    <div class="container">
      <div v-if="themoviedbList">
        <div class="row">
          <div class="col-md-9">
            <br />
            <a href="http://localhost:8080/list">
              <p v-if="lang == 'en'" style="color:blue;text-shadow: 0 0 3px #000">< Back</p>
              <p v-else-if="lang == 'fr'" style="color:blue;text-shadow: 0 0 3px #000">< Retour</p>
            </a>
            <br />
          </div>
          <div class="col-md-2">
            <br />
            <div v-if="watched == 'yes'">
              <a href="http://localhost:8080/watch">
                <p v-if="lang == 'en'" style="color:white;text-shadow: 0 0 3px #000">Your favorite list ></p>
                <p v-else-if="lang == 'fr'" style="color:white;text-shadow: 0 0 3px #000">Votre liste préférée ></p>
              </a>
            </div>
            <div v-else-if="watched == 'no'">
              <a v-on:click="savefilm">
                <p v-if="lang == 'en'" style="color:blue;text-shadow: 0 0 3px #000">Add to favorite list ></p>
                <p v-else-if="lang == 'fr'" style="color:blue;text-shadow: 0 0 3px #000">Ajouter à la liste des favoris ></p>
              </a>
            </div>
            <br />
          </div>
        </div>
        <div v-if="themoviedbList.trailer && themoviedbList.trailer != 'N/A'">
          <iframe
            width="93%"
            height="576"
            v-bind:src="'http://youtube.com/embed/'+themoviedbList.trailer"
          ></iframe>
        </div>
        <div v-else-if="movieData.trailer && movieData.trailer != 'N/A'">
          <iframe width="93%" height="576" :src="trailer"></iframe>
        </div>
        <div class="row">
          <div class="col-md-4" style="background-color: white;">
            <div v-if="themoviedbList.poster_big">
              <img style="width:100%;height:50%;" v-bind:src="themoviedbList.poster_big" />
            </div>
            <div v-else-if="movieData.images">
              <img
                v-if="movieData.images.poster || movieData.images.poster != null"
                style="width:100%;height:50%;"
                v-bind:src="movieData.images.poster"
              />
            </div>
            <img
              v-else
              style="width:100%;height:50%;"
              :src="noposter"
            />
            <div class="row">
              <div class="col-md-6">
                <div v-if="hash1080">
                  <a v-bind:href="'/streami?mov='+hash1080+'&imdb='+imdb">
                    <button v-if="lang == 'en'" type="button" class="btn btn-success">Watch 1080p</button>
                    <button v-else-if="lang == 'fr'" type="button" class="btn btn-success">Regarder 1080p</button>
                  </a>
                </div>
              </div>
              <div class="col-md-6">
                <div v-if="hash720">
                  <a v-bind:href="'/streami?mov='+hash720+'&imdb='+imdb">
                    <button v-if="lang == 'en'" type="button" class="btn btn-info">Watch 720p</button>
                    <button v-else-if="lang == 'fr'" type="button" class="btn btn-info">Regarder 720p</button>
                  </a>
                </div>
              </div>
            </div>
          </div>
          <div class="col-md-2" style="background-color: white;"></div>
          <div class="col-md-5" style="background-color: white;">
            <div class="row">
              <div class="col-md-6">
                <div v-if="themoviedbList.title && themoviedbList.title != 'N/A'">
                  <h2 style="color:red;text-shadow: 0 0 2px #000">{{themoviedbList.title}}</h2>
                </div>
                <div v-else-if="movieData.title && movieData.title != 'N/A'">
                  <h2 style="color:red;text-shadow: 0 0 2px #000">{{movieData.title}}</h2>
                </div>
              </div>
              <div class="col-md-6">
                <div v-if="vu == 'yes'">
                  <img style="width:42px;height:42px" :src="yes" />
                </div>
                <div v-else-if="vu == 'no'">
                  <img style="width:42px;height:42px" :src="no" />
                </div>
              </div>
            </div>
            <div
              v-if="themoviedbList.year && themoviedbList.year != 'N/A'"
            >Year: {{themoviedbList.year}}</div>
            <div v-else-if="movieData.year && movieData.year != 'N/A'">Year: {{movieData.year}}</div>
            <div
              v-if="themoviedbList.runtime && themoviedbList.runtime != 'N/A'"
            >Runtime: {{themoviedbList.runtime}}</div>
            <div
              v-else-if="movieData.runtime && movieData.runtime != 'N/A'"
            >Runtime: {{movieData.runtime}}</div>
            <div v-if="themoviedbList.genres">
              Genres:
              <ul
                style="display: inline-block;"
                v-for="item in themoviedbList.genres"
                class="movie-tags"
              >
                
                <li>
                  <a>{{item}}</a>
                </li>
              </ul>
            </div>
            <div v-else-if="movieData.genres">
              Genres:
              <ul
                style="display: inline-block;"
                v-for="item in movieData.genres"
                class="movie-tags"
                >
                <li>
                  <a>{{item}}</a>
                </li>
              </ul>
            </div>
            <div
              v-if="themoviedbList.description && themoviedbList.description != 'N/A'"
            >Description: {{themoviedbList.description}}</div>
            <div
              v-else-if="movieData.synopsis && movieData.synopsis != 'N/A'"
            >Description: {{movieData.synopsis}}</div>
            <div
              v-if="themoviedbList.rating && themoviedbList.rating != 'N/A'"
            >Ratings: {{themoviedbList.rating}}</div>
            <div v-else-if="movieData.rating">
              Ratings:
              <ul>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.percentage && movieData.rating.percentage != 'N/A'"
                >Percentage: {{movieData.rating.percentage}}%</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.loved && movieData.rating.loved != 'N/A'"
                >Loves: {{movieData.rating.loved}}</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.hated && movieData.rating.hated != 'N/A'"
                >Hates: {{movieData.rating.hated}}</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.votes && movieData.rating.votes != 'N/A'"
                >Votes: {{movieData.rating.votes}}</li>
              </ul>
            </div>
            <div>
              <a v-on:click="likemov">
                <img style="width:52px;height:32px" :src="unlike" />
                {{likes}}
              </a>
            </div>
          </div>
        </div>
           <div class="col-md-11" style="background-color: white;">
          <div class="form__group field">
            <div v-if="lang == 'en'" class="form__field" style="text-align: center;color: #11998e;">Comments</div>
            <div v-else-if="lang == 'fr'" class="form__field" style="text-align: center;color: #11998e;">Commentaires</div>
            <div class="form__field" v-for="item in commentss">
              <a v-bind:href="'/commenter?username='+ item.commenter" style="text-decoration:none;"><b style="color: #11998e;">{{item.commenter}} :</b></a>
              {{item.comment}}
            </div>
          <form @submit.prevent="comment">
            <input
            placeholder="Type your comment"
              type="text"
              class="form__field"
              name="name"
              id="name"
              v-model="commentaire"
            />
            <button class="button button3" @click="reloadPage()"> </button>
          </form>
        </div>
        </div>
      </div>
      <div v-else>
        <h3>sorry there is no data</h3>
      </div>
    </div>
  </div>
  <div v-else class="movie-card bg-no-repeat bg-cover bg-white hero relative" :style="{ backgroundImage: `url(${noposter})` }">
    <div class="container">
      <div v-if="themoviedbList">
        <div class="row">
          <div class="col-md-9">
            <br />
            <a href="http://localhost:8080/list">
              <p v-if="lang == 'en'" style="color:blue;text-shadow: 0 0 3px #000">< Back</p>
              <p v-else-if="lang == 'fr'" style="color:blue;text-shadow: 0 0 3px #000">< Retour</p>
            </a>
            <br />
          </div>
          <div class="col-md-2">
            <br />
            <div v-if="watched == 'yes'">
              <a href="http://localhost:8080/watch">
                <p v-if="lang == 'en'" style="color:white;text-shadow: 0 0 3px #000">Your favorite list ></p>
                <p v-else-if="lang == 'fr'" style="color:white;text-shadow: 0 0 3px #000">Votre liste préférée ></p>
              </a>
            </div>
            <div v-else-if="watched == 'no'">
              <a v-on:click="savefilm">
                <p v-if="lang == 'en'" style="color:blue;text-shadow: 0 0 3px #000">Add to favorite list ></p>
                <p v-else-if="lang == 'fr'" style="color:blue;text-shadow: 0 0 3px #000">Ajouter à la liste des favoris ></p>
              </a>
            </div>
            <br />
          </div>
        </div>
        <div v-if="themoviedbList.trailer && themoviedbList.trailer != 'N/A'">
          <iframe
            width="93%"
            height="576"
            v-bind:src="'http://youtube.com/embed/'+themoviedbList.trailer"
          ></iframe>
        </div>
        <div v-else-if="movieData.trailer && movieData.trailer != 'N/A'">
          <iframe width="93%" height="576" :src="trailer"></iframe>
        </div>
        <div class="row">
          <div class="col-md-4" style="background-color: white;">
            <div v-if="themoviedbList.poster_big">
              <img style="width:100%;height:50%;" v-bind:src="themoviedbList.poster_big" />
            </div>
            <div v-else-if="movieData.images">
              <img
                v-if="movieData.images.poster || movieData.images.poster != null"
                style="width:100%;height:50%;"
                v-bind:src="movieData.images.poster"
              />
            </div>
            <img
              v-else
              style="width:100%;height:50%;"
              :src="noposter"
            />
            <div class="row">
              <div class="col-md-6">
                <div v-if="hash1080">
                  <a v-bind:href="'/streami?mov='+hash1080+'&imdb='+imdb">
                    <button v-if="lang == 'en'" type="button" class="btn btn-success">Watch 1080p</button>
                    <button v-else-if="lang == 'fr'" type="button" class="btn btn-success">Regarder 1080p</button>
                  </a>
                </div>
              </div>
              <div class="col-md-6">
                <div v-if="hash720">
                  <a v-bind:href="'/streami?mov='+hash720+'&imdb='+imdb">
                    <button v-if="lang == 'en'" type="button" class="btn btn-info">Watch 720p</button>
                    <button v-else-if="lang == 'fr'" type="button" class="btn btn-info">Regarder 720p</button>
                  </a>
                </div>
              </div>
            </div>
          </div>
          <div class="col-md-2" style="background-color: white;"></div>
          <div class="col-md-5" style="background-color: white;">
            <div class="row">
              <div class="col-md-6">
                <div v-if="themoviedbList.title && themoviedbList.title != 'N/A'">
                  <h2 style="color:red;text-shadow: 0 0 2px #000">{{themoviedbList.title}}</h2>
                </div>
                <div v-else-if="movieData.title && movieData.title != 'N/A'">
                  <h2 style="color:red;text-shadow: 0 0 2px #000">{{movieData.title}}</h2>
                </div>
              </div>
              <div class="col-md-6">
                <div v-if="vu == 'yes'">
                  <img style="width:42px;height:42px" :src="yes" />
                </div>
                <div v-else-if="vu == 'no'">
                  <img style="width:42px;height:42px" :src="no" />
                </div>
              </div>
            </div>
            <div
              v-if="themoviedbList.year && themoviedbList.year != 'N/A'"
            >Year: {{themoviedbList.year}}</div>
            <div v-else-if="movieData.year && movieData.year != 'N/A'">Year: {{movieData.year}}</div>
            <div
              v-if="themoviedbList.runtime && themoviedbList.runtime != 'N/A'"
            >Runtime: {{themoviedbList.runtime}}</div>
            <div
              v-else-if="movieData.runtime && movieData.runtime != 'N/A'"
            >Runtime: {{movieData.runtime}}</div>
            <div v-if="themoviedbList.genres">
              Genres:
              <ul
                style="display: inline-block;"
                v-for="item in themoviedbList.genres"
                class="movie-tags"
              >
                
                <li>
                  <a>{{item}}</a>
                </li>
              </ul>
            </div>
            <div v-else-if="movieData.genres">
              Genres:
              <ul
                style="display: inline-block;"
                v-for="item in movieData.genres"
                class="movie-tags"
                >
                <li>
                  <a>{{item}}</a>
                </li>
              </ul>
            </div>
            <div
              v-if="themoviedbList.description && themoviedbList.description != 'N/A'"
            >Description: {{themoviedbList.description}}</div>
            <div
              v-else-if="movieData.synopsis && movieData.synopsis != 'N/A'"
            >Description: {{movieData.synopsis}}</div>
            <div
              v-if="themoviedbList.rating && themoviedbList.rating != 'N/A'"
            >Ratings: {{themoviedbList.rating}}</div>
            <div v-else-if="movieData.rating">
              Ratings:
              <ul>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.percentage && movieData.rating.percentage != 'N/A'"
                >Percentage: {{movieData.rating.percentage}}%</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.loved && movieData.rating.loved != 'N/A'"
                >Loves: {{movieData.rating.loved}}</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.hated && movieData.rating.hated != 'N/A'"
                >Hates: {{movieData.rating.hated}}</li>
                <li
                  style="display: inline-block;"
                  v-if="movieData.rating.votes && movieData.rating.votes != 'N/A'"
                >Votes: {{movieData.rating.votes}}</li>
              </ul>
            </div>
            <div>
              <a v-on:click="likemov">
                <img style="width:52px;height:32px" :src="unlike" />
                {{likes}}
              </a>
            </div>
          </div>
        </div>
           <div class="col-md-11" style="background-color: white;">
          <div class="form__group field">
            <div v-if="lang == 'en'" class="form__field" style="text-align: center;color: #11998e;">Comments</div>
            <div v-else-if="lang == 'fr'" class="form__field" style="text-align: center;color: #11998e;">Commentaires</div>
            <div class="form__field" v-for="item in commentss">
              <a v-bind:href="'/commenter?username='+ item.commenter" style="text-decoration:none;"><b style="color: #11998e;">{{item.commenter}} :</b></a>
              {{item.comment}}
            </div>
        
          <form @submit.prevent="comment">
            <input
              type="text"
              placeholder="Type your comment"
              class="form__field"
              name="name"
              id="name"
              v-model="commentaire"
            />
            <button class="button button3" @click="reloadPage()"> </button>
          </form>
        </div>
        </div>
      </div>
      <div v-else>
        <h3>sorry there is no data</h3>
      </div>
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
      title: "",
      imdb: "",
      movieData: [],
      themoviedbList: [],
      trailer: "",
      hash1080: "",
      hash720: "",
      commentaire: "",
      commentss: "",
      vu: "",
      likes: "",
      watched: "",
      lang: '',
      noposter: "static/img/noposter.png",
      no: "static/img/no.png",
      yes: "static/img/yes.png",
      unlike: "static/img/unlike.png"
    };
  },
  beforeCreate() {
    if (!localStorage.getItem("usertoken")) router.push({ name: "Login" });
  },
  created: function() {
    this.seen();
    this.getcomments();
  },
  mounted: function() {
    this.title = decodeURIComponent(this.$route.query.title);
    this.imdb = this.$route.query.imdb;
    this.apione();
    this.apitwo();
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
    likemov() {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var username = decoded.username;
      var imdb = this.$route.query.imdb;
      try {
        axios
          .post("users/likemov", {
            username: username,
            imdb: this.imdb
          })
          .then(response => {
            window.location.reload();
          });
      } catch (err) {
        console.log("");
      }
      }
    },
    reloadPage() {
      window.location.reload();
    },
    getlikes() {
      var imdb = this.$route.query.imdb;
      try {
        axios.get("users/getlikes/" + imdb).then(response => {
          this.likes = response.data.length;
        });
      } catch (err) {
        console.log("");
      }
    },
    isliked() {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var username = decoded.username;
      var imdb = this.$route.query.imdb;
      try {
        axios.get("users/isliked/" + imdb + "/" + username).then(response => {
          if (response.data == "ohyeah") this.unlike = "static/img/like.jpeg";
          else if (response.data == "ohno")
            this.unlike = "static/img/unlike.png";
        });
      } catch (err) {
        console.log("");
      }
      }
    },
    seen() {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var username = decoded.username;
      var imdb = this.$route.query.imdb;
      try {
        axios.get("users/getseen/" + imdb + "/" + username).then(response => {
          this.vu = response.data;
        });
      } catch (err) {
        console.log("");
      }
      }
    },
    comment() {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var username = decoded.username;
      try {
        axios
          .post("users/postcomment", {
            imdb: this.imdb,
            username: username,
            commentaire: this.commentaire
          })
          .then(response => {});
      } catch (err) {
        console.log("");
      }
      }
    },
    getcomments() {
      try {
        axios
          .get("users/getcomment/" + this.$route.query.imdb)
          .then(response => {
            this.commentss = response.data;
          });
      } catch (err) {
        console.log("");
      }
    },
    savefilm() {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var username = decoded.username;
      try {
        axios
          .post("users/savemovie", {
            username: username,
            imdb: this.imdb,
            title: this.title,
            poster: this.movieData.images.poster
          })
          .then(response => {
            window.location.reload();
          });
      } catch (err) {
        console.log("");
      }
      }
    },
    downloadvtt(hasho) {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var language = decoded.language;
      try {
        axios
          .post("users/movie", {
            hash: hasho,
            lang: language,
            imdb: this.imdb
          })
          .then(response => {});
      } catch (err) {
        console.log("");
      }
      }
    },
    async apione() {
      if (localStorage.getItem("usertoken") && this.title != '' && this.imdb !== undefined) {
        var url = "https://tv-v2.api-fetch.website/movie/" + this.imdb + "";
        fetch(url)
          .then(response => response.json())
          .then(async data => {
            if (data) {
              var tra = data.trailer;
              if (tra != null)
                this.trailer = tra.replace(
                  "http://youtube.com/watch?v=",
                  "http://youtube.com/embed/"
                );
              if (data.torrents.en["1080p"])
                var magnet1080 = data.torrents.en["1080p"].url;
              if (magnet1080 != null) this.hash1080 = magnet1080.substr(20, 40);
              this.downloadvtt(this.hash1080);
              if (data.torrents.en["720p"].url)
                var magnet720 = data.torrents.en["720p"].url;
              if (magnet720 != null) this.hash720 = magnet720.substr(20, 40);
              this.downloadvtt(this.hash720);
            }
            this.movieData = data;
          });
      } else {
        this.title = "nothing";
        this.imdb = "tt1179933";
      }
    },
    async apitwo() {
      if (localStorage.getItem("usertoken") && this.title != '' && this.imdb !== undefined) {
        var url2 =
          "https://api.apiumadomain.xyz/list?sort=seeds&short=1&cb=&quality=720p,1080p,3d&page=1&keywords=" +
          this.title +
          "";
        await fetch(url2)
          .then(response => response.json())
          .then(data => {
            var i = 0;
            while (i < data.MovieList.length) {
              if (data.MovieList[i] != undefined) {
                if (data.MovieList[i].title == this.title) {
                  this.themoviedbList = data.MovieList[i];
                  break;
                } else i++;
              }
            }
            i = 0;
          });
      } else {
        this.title = "nothing";
        this.imdb = "tt1179933";
      }
    },
    async watchlate() {
    if (localStorage.getItem("usertoken"))
    {
      const token = localStorage.getItem("usertoken");
      const decoded = jwtDecode(token);
      var username = decoded.username;
      var imdb = this.$route.query.imdb;
      try {
        axios
          .post("users/getwatch", {
            username: username,
            imdb: imdb
          })
          .then(response => {
            if (response.data == "yes") this.watched = "yes";
            else if (response.data == "no") this.watched = "no";
          });
      } catch (err) {
        console.log("");
      }
    }
    }
  },
  async beforeMount() {
    await this.getlikes();
    await this.isliked();
    await this.watchlate();
    await this.getlang();
  }
};
</script>
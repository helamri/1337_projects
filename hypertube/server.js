var express = require("express")
var path = require('path')
const jwt = require("jsonwebtoken")
var logger = require('morgan')
var session = require('express-session')
var cors = require("cors")
const passport = require("passport")
var bodyParser = require("body-parser")
var cookieParser = require('cookie-parser')
var TwitterStrategy = require('passport-twitter').Strategy
var FortyTwoStrategy = require('passport-42').Strategy
var GitHubStrategy = require('passport-github2').Strategy
var FacebookStrategy = require('passport-facebook').Strategy
var mongoose = require("mongoose")
var randToken = require("rand-token")

process.env.SECRET_KEY = '1337secret'
var port = process.env.PORT || 5000

var app = express()

var usr;

app.use(logger('dev'));
app.use(bodyParser.json({ limit: '50mb' }));
app.use(cors())
app.use(bodyParser.urlencoded({ limit: '50mb', extended: true }));
app.use(cookieParser())
app.use(session({ secret: 'whatever', resave: true, saveUninitialized: true }))

app.use(passport.initialize())
app.use(passport.session())

const mongoURI = 'mongodb://localhost:27017/hyper'
const User = require("./models/User")

mongoose.connect(mongoURI, { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => console.log("MongoDB Connected"))
    .catch(err => console.log(err))

passport.serializeUser(function(user, callback) {
    callback(null, user);
})

passport.deserializeUser(function(obj, callback) {
    callback(null, obj);
})

passport.use(new GitHubStrategy({
        clientID: '8602b376429cae2bbe7a',
        clientSecret: 'd302b2c83307368ea21d537405d2ad23f78c09d7',
        callbackURL: "http://localhost:5000/auth/github/callback"
    },
    async function(accessToken, refreshToken, profile, cb) {
        var user = new User({
            atoken: randToken.generate(64),
            username: profile.username,
            fname: profile.displayName,
            lname: profile.displayName ? profile.displayName : "none",
            email: profile.profileUrl,
            password: randToken.generate(64),
            lang: "en",
            image: profile.photos[0].value,
            verified: 1,
            omn: 1
        });
        usr = await user.findOrCreate();
        return cb(null, profile);
    }
));

passport.use(new TwitterStrategy({
        consumerKey: 'YXDPAH8dBMD9N5p6G8GQvRwse',
        consumerSecret: 'pRcUgpbv7bP7oQHTAtgIIm9D9m55z6Fb53NrLC5fBkJtTg6oU9',
        callbackURL: "http://localhost:5000/auth/twitter/callback"
    },
    async function(accessToken, refreshToken, profile, cb) {
        var user = new User({
            atoken: randToken.generate(64),
            username: profile.username,
            fname: profile.displayName,
            lname: profile.displayName,
            email: "none",
            password: randToken.generate(64),
            lang: "en",
            image: profile.photos[0].value,
            verified: 1,
            omn: 1
        });
        usr = await user.findOrCreate();
        return cb(null, profile);
    }
));

passport.use(new FortyTwoStrategy({
        clientID: '19fdccb52cbb7c85b8b7cb6f72e57eb9e0c573e38927cdd8a0f2f6020622bf0a',
        clientSecret: '8f3e2e0ccf02034e8054d2e081754529b8d4d5118467dabe4740f947cdceb216',
        callbackURL: "/auth/42/callback"
    },
    async function(accessToken, refreshToken, profile, cb) {
        var user = new User({
            atoken: randToken.generate(64),
            username: profile.name.givenName[0] + profile.name.familyName,
            fname: profile.name.givenName,
            lname: profile.name.familyName ? profile.name.familyName : "none",
            email: profile.emails[0].value,
            password: randToken.generate(64),
            lang: "en",
            image: profile.photos[0].value,
            verified: 1,
            omn: 1
        });
        usr = await user.findOrCreate();
        return cb(null, profile);
    }
));
// Auth Req

async function isAuth(req, res, next) {
    const { token } = req.body;
    try {
        const payload = jwt.verify(token, process.env.JWT_SECRET);

        req.userData = await User.findOne({ _id: payload._id });
        next();
    } catch (err) {
        next(err);
    }
}

app.get('/auth/42',
    passport.authenticate('42'));

app.get('/auth/42/callback',
    passport.authenticate('42', { failureRedirect: '/login' }),
    function(req, res) {
        const payload = {
            atoken: usr.atoken,
            language: 'en',
            username: usr.username
        }
        var token = jwt.sign(payload, process.env.SECRET_KEY, {
            expiresIn: 1000
        });
        res.redirect('http://localhost:8080/wahmiya?token=' + token);
    });

app.get('/auth/twitter',
    passport.authenticate('twitter'));

app.get('/auth/twitter/callback',
    passport.authenticate('twitter', { failureRedirect: '/login' }),
    function(req, res) {
        //res.redirect('/');
        const payload = {
            atoken: usr.atoken,
            language: 'en',
            username: usr.username
        }
        var token = jwt.sign(payload, process.env.SECRET_KEY, {
            expiresIn: 1000
        });
        res.redirect('http://localhost:8080/wahmiya?token=' + token);
    });

app.get('/auth/github',
    passport.authenticate('github', { scope: ['user:email'] }));

app.get('/auth/github/callback',
    passport.authenticate('github', { failureRedirect: '/login' }),
    function(req, res) {
        //res.redirect('/');
        const payload = {
            atoken: usr.atoken,
            language: 'en',
            username: usr.username
        }
        var token = jwt.sign(payload, process.env.SECRET_KEY, {
            expiresIn: 1000
        });
        res.redirect('http://localhost:8080/wahmiya?token=' + token);
    });

var Users = require("./routes/Users")

app.use("/users", Users)

app.listen(port, function() {
    console.log("Server is running on port: " + port)
})
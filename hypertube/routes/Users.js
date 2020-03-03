const express = require("express")
const users = express.Router()
var path = require('path')
const cors = require("cors")
const jwt = require("jsonwebtoken")
const bcrypt = require("bcrypt")
const nodemailer = require('nodemailer')
var torrentStream = require('torrent-stream');
const parseRange = require('range-parser');
var randToken = require ("rand-token")
const yifysubtitles = require('yifysubtitles');
var sizeOf = require('image-size');
var base64 = require('file-base64');
var timeago = require('epoch-timeago')
const rmv = require('fs-extra')
var url = require('url');
const fs = require("fs")
var randToken = require ("rand-token")
var FFmpeg = require('fluent-ffmpeg');
const ffmpegInstdataer = require("@ffmpeg-installer/ffmpeg");
FFmpeg.setFfmpegPath(ffmpegInstdataer.path);

let transporter = nodemailer.createTransport({
	service: 'gmail',
	auth: {
		user: '1337hypertube@gmail.com',
		pass: 'Hypertube00-'
	}
});

let tr = [
'http://104.28.1.30:8080/announce',
'http://104.28.16.69/announce',
'http://107.150.14.110:6969/announce',
'http://109.121.134.121:1337/announce',
'http://114.55.113.60:6969/announce',
'http://125.227.35.196:6969/announce',
'http://128.199.70.66:5944/announce',
'http://157.7.202.64:8080/announce',
'http://158.69.146.212:7777/announce',
'http://173.254.204.71:1096/announce',
'http://178.175.143.27/announce',
'http://178.33.73.26:2710/announce',
'http://182.176.139.129:6969/announce',
'http://185.5.97.139:8089/announce',
'http://188.165.253.109:1337/announce',
'http://194.106.216.222/announce',
'http://195.123.209.37:1337/announce',
'http://210.244.71.25:6969/announce',
'http://210.244.71.26:6969/announce',
'http://213.159.215.198:6970/announce',
'http://213.163.67.56:1337/announce',
'http://37.19.5.139:6969/announce',
'http://37.19.5.155:6881/announce',
'http://46.4.109.148:6969/announce',
'http://5.79.249.77:6969/announce',
'http://5.79.83.193:2710/announce',
'http://51.254.244.161:6969/announce',
'http://59.36.96.77:6969/announce',
'http://74.82.52.209:6969/announce',
'http://80.246.243.18:6969/announce',
'http://81.200.2.231/announce',
'http://85.17.19.180/announce',
'http://87.248.186.252:8080/announce',
'http://87.253.152.137/announce',
'http://91.216.110.47/announce',
'http://91.217.91.21:3218/announce',
'http://91.218.230.81:6969/announce',
'http://93.92.64.5/announce',
'http://atrack.pow7.com/announce',
'http://bt.henbt.com:2710/announce',
'http://bt.pusacg.org:8080/announce',
'http://bt2.careland.com.cn:6969/announce',
'http://explodie.org:6969/announce',
'http://mgtracker.org:2710/announce',
'http://mgtracker.org:6969/announce',
'http://open.acgtracker.com:1096/announce',
'http://open.lolicon.eu:7777/announce',
'http://open.touki.ru/announce.php',
'http://p4p.arenabg.ch:1337/announce',
'http://p4p.arenabg.com:1337/announce',
'http://pow7.com:80/announce',
'http://retracker.gorcomnet.ru/announce',
'http://retracker.krs-ix.ru/announce',
'http://retracker.krs-ix.ru:80/announce',
'http://secure.pow7.com/announce',
'http://t1.pow7.com/announce',
'http://t2.pow7.com/announce',
'http://thetracker.org:80/announce',
'http://torrent.gresille.org/announce',
'http://torrentsmd.com:8080/announce',
'http://tracker.aletorrenty.pl:2710/announce',
'http://tracker.baravik.org:6970/announce',
'http://tracker.bittor.pw:1337/announce',
'http://tracker.bittorrent.am/announce',
'http://tracker.calculate.ru:6969/announce',
'http://tracker.dler.org:6969/announce',
'http://tracker.dutchtracking.com/announce',
'http://tracker.dutchtracking.com:80/announce',
'http://tracker.dutchtracking.nl/announce',
'http://tracker.dutchtracking.nl:80/announce',
'http://tracker.edoardocolombo.eu:6969/announce',
'http://tracker.ex.ua/announce',
'http://tracker.ex.ua:80/announce',
'http://tracker.filetracker.pl:8089/announce',
'http://tracker.flashtorrents.org:6969/announce',
'http://tracker.grepler.com:6969/announce',
'http://tracker.internetwarriors.net:1337/announce',
'http://tracker.kicks-ass.net/announce',
'http://tracker.kicks-ass.net:80/announce',
'http://tracker.kuroy.me:5944/announce',
'http://tracker.mg64.net:6881/announce',
'http://tracker.opentrackr.org:1337/announce',
'http://tracker.skyts.net:6969/announce',
'http://tracker.tfile.me/announce',
'http://tracker.tiny-vps.com:6969/announce',
'http://tracker.tvunderground.org.ru:3218/announce',
'http://tracker.yoshi210.com:6969/announce',
'http://tracker1.wasabii.com.tw:6969/announce',
'http://tracker2.itzmx.com:6961/announce',
'http://tracker2.wasabii.com.tw:6969/announce',
'http://www.wareztorrent.com/announce',
'http://www.wareztorrent.com:80/announce',
'https://104.28.17.69/announce',
'https://www.wareztorrent.com/announce',
'udp://107.150.14.110:6969/announce',
'udp://109.121.134.121:1337/announce',
'udp://114.55.113.60:6969/announce',
'udp://128.199.70.66:5944/announce',
'udp://151.80.120.114:2710/announce',
'udp://168.235.67.63:6969/announce',
'udp://178.33.73.26:2710/announce',
'udp://182.176.139.129:6969/announce',
'udp://185.5.97.139:8089/announce',
'udp://185.86.149.205:1337/announce',
'udp://188.165.253.109:1337/announce',
'udp://191.101.229.236:1337/announce',
'udp://194.106.216.222:80/announce',
'udp://195.123.209.37:1337/announce',
'udp://195.123.209.40:80/announce',
'udp://208.67.16.113:8000/announce',
'udp://213.163.67.56:1337/announce',
'udp://37.19.5.155:2710/announce',
'udp://46.4.109.148:6969/announce',
'udp://5.79.249.77:6969/announce',
'udp://5.79.83.193:6969/announce',
'udp://51.254.244.161:6969/announce',
'udp://62.138.0.158:6969/announce',
'udp://62.212.85.66:2710/announce',
'udp://74.82.52.209:6969/announce',
'udp://85.17.19.180:80/announce',
'udp://89.234.156.205:80/announce',
'udp://9.rarbg.com:2710/announce',
'udp://9.rarbg.me:2780/announce',
'udp://9.rarbg.to:2730/announce',
'udp://91.218.230.81:6969/announce',
'udp://94.23.183.33:6969/announce',
'udp://bt.xxx-tracker.com:2710/announce',
'udp://eddie4.nl:6969/announce',
'udp://explodie.org:6969/announce',
'udp://mgtracker.org:2710/announce',
'udp://open.stealth.si:80/announce',
'udp://p4p.arenabg.com:1337/announce',
'udp://shadowshq.eddie4.nl:6969/announce',
'udp://shadowshq.yi.org:6969/announce',
'udp://torrent.gresille.org:80/announce',
'udp://tracker.aletorrenty.pl:2710/announce',
'udp://tracker.bittor.pw:1337/announce',
'udp://tracker.coppersurfer.tk:6969/announce',
'udp://tracker.eddie4.nl:6969/announce',
'udp://tracker.ex.ua:80/announce',
'udp://tracker.filetracker.pl:8089/announce',
'udp://tracker.flashtorrents.org:6969/announce',
'udp://tracker.grepler.com:6969/announce',
'udp://tracker.ilibr.org:80/announce',
'udp://tracker.internetwarriors.net:1337/announce',
'udp://tracker.kicks-ass.net:80/announce',
'udp://tracker.kuroy.me:5944/announce',
'udp://tracker.leechers-paradise.org:6969/announce',
'udp://tracker.mg64.net:2710/announce',
'udp://tracker.mg64.net:6969/announce',
'udp://tracker.opentrackr.org:1337/announce',
'udp://tracker.piratepublic.com:1337/announce',
'udp://tracker.sktorrent.net:6969/announce',
'udp://tracker.skyts.net:6969/announce',
'udp://tracker.tiny-vps.com:6969/announce',
'udp://tracker.yoshi210.com:6969/announce',
'udp://tracker2.indowebster.com:6969/announce',
'udp://tracker4.piratux.com:6969/announce',
'udp://zer0day.ch:1337/announce',
'udp://zer0day.to:1337/announce',
];

const User = require("../models/User")
const Movie = require("../models/Movie")
const Comment = require("../models/Comment")
const Watched = require("../models/Watched")
const Watchlater = require("../models/Watchlater")
const Like = require("../models/Like")

users.use(cors())

process.env.SECRET_KEY = 'secret'

users.post("/register", async (req, res) => {
	if(typeof req.body.username !== "undefined" && typeof req.body.fname !== "undefined" && typeof req.body.lname !== "undefined" && typeof req.body.email !== "undefined" && typeof req.body.password !== "undefined" && typeof req.body.picdata !== "undefined"
		&& typeof req.body.username === "string" && typeof req.body.fname === "string" && typeof req.body.lname === "string" && typeof req.body.email === "string" && typeof req.body.password === "string" && typeof req.body.picdata === "string")
	{
	try{

	if(req.body.lang == '')
		req.body.lang = 'en'
	function isString(str) {
		var regstring = /^[a-z0-9_-]{3,15}$/
		return (regstring.test(str))
	}
	function isEmailValid() {
		var regemail = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,24}))$/
		return (regemail.test(req.body.email))
	}
	function isPassword() {
		var regpass = /^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$ %^&*-]).{8,}$/
		return (regpass.test(req.body.password))
	}
	if(!isEmailValid()) {
		return res.send('Please type a valid email')
	} else if(!isString(req.body.username)) {
		return res.send('Please type a valid username')
	} else if(!isString(req.body.fname)) {
		return res.send('Please type a valid first name')
	} else if(!isString(req.body.lname)) {
		return res.send('Please type a valid last name')
	} else if(!isPassword()) {
		return res.send('Please type a valid password')
	}
	const today = new Date()
	var picture = await req.body.picdata
	if(picture.startsWith('data:image/'))
	{
	let base64Image = picture.split(';base64,').pop()
	var path = './client/static/images/image'+req.body.username+'.png'
	fs.writeFile(path, base64Image, {encoding: 'base64'}, function(err) {
	});
	path = path.split('./client/').pop()
	const userData = {
		atoken: randToken.generate(64),
		username: req.body.username,
		fname: req.body.fname,
		lname: req.body.lname,
		email: req.body.email,
		password: req.body.password,
		lang: req.body.lang,
		image: path,
		created: today
	}
	

	User.findOne({
		username: req.body.username
	})
	.then(user => {
		if(!user) {
			User.findOne({
				email: req.body.email
			})
			.then(user => {
				if(!user) {
					bcrypt.hash(req.body.password, 10, async (err, hash) => {
						userData.password = hash
						await User.create(userData)
						.then(user => {
							var mailOptions = 
							{
								from: '1337hypertube@gmail.com',
								to: req.body.email,
								subject: 'Confirm account',
								html: "<table><tr><td align='center'><img src='https://i1.wp.com/metro.co.uk/wp-content/uploads/2017/08/warrhyperloop.gif?quality=90&strip=all&zoom=1&resize=440%2C248&ssl=1'/><br><a href='http://localhost:8080/verified?token="+user.atoken+"'>Click to confirm your account</a></td></tr>"
							};
							transporter.sendMail(mailOptions, function(err, data)
							{
								if (err) throw err;
							})
							res.json({status: user.username + ' registered'})
						})
						.catch(err => {
							res.send('error: ' + err)
						})
					})
				}else{
					res.send('Email already exists')
				}})
		}else{
			res.send('User already exists')
		}
	})
	.catch(err => {
		res.send('error: ' + err)
	})
}
else
	res.send('Invalid image')
}catch(err){
		
	console.log("")
}
}
else
	res.send("")
		
});



users.post('/login', (req, res) => {
	if(typeof req.body.username !== "undefined" && typeof req.body.password !== "undefined" && typeof req.body.username === "string" && typeof req.body.password === "string")
	{
	try{
	User.findOne({
		username: req.body.username
	})
	.then(user => {
		if(user) {
			if (user.verified == 0)
				res.send('Please go to your email to confirm it')
			else if(bcrypt.compareSync(req.body.password, user.password)) {
				const payload = {
					atoken: user.atoken,
					language: user.lang,
					username: user.username
				}
				let token = jwt.sign(payload, process.env.SECRET_KEY, {
					expiresIn: 1000
				})
				res.send(token)
			}else{
				res.send('Password wrong')
			}
		}else{
			res.send('User does not exist')
		}
	})
	.catch(err => {
		res.send('error: ' + err)
	})}catch(err){
		
	console.log("")
}
}else
	res.send("")
})

users.get('/getcommenter/:username', (req, res) => {
	try{
	var username = req.params.username
	User.find({
		username: username
	}).then(results => {
	res.send(results)
})}catch(err){
		console.log("")
	}
})

users.post('/getwatch', async (req, res) => {
	try{
	var imdb = req.body.imdb
	var username = req.body.username
	Watchlater.findOne({ username: username, imdb: imdb})
	.then(async data => {
        if (data)
            res.send('yes')
        else
        	res.send('no')
    });}catch(err){
		console.log("")
    }
})

users.post('/getlanguage', async (req, res) => {
	try{
	var username = req.body.username
	User.findOne({
		username: username
	}).then(async data => {
		if (data){
			res.send(data)
		}
		else
			res.send("")
})}catch(err){
		console.log("")
	}
})

users.post('/deletewatch', async (req, res) => {
	try{
	var title = req.body.title
	var username = req.body.username
	Watchlater.deleteOne({ username: username, title: title}, (err) => {
        if (err)
            throw err;
        else
        	res.send('deleted')
    })}catch(err){
		console.log("")
    }
})

users.post('/likemov', async (req, res) => {
	try{
	var username = req.body.username
	var imdb = req.body.imdb
	const likeData = {
		imdb: imdb,
		liker: username
	}
	Like.findOne({
		imdb: imdb,
		liker: username
	}).then(async data => {
		if (!data){
			await Like.create(likeData)
			res.send("film liked")
		}
})}catch(err){
		console.log("")
	}
})

users.get('/getlikes/:imdb', (req, res) => {
	try{
	var imdb = req.params.imdb
	Like.find({
		imdb: imdb
	}).then(results => {
	res.send(results)
})}catch(err){
		console.log("")
	}
})

users.get('/isliked/:imdb/:username', async (req, res) => {
	try{
	var imdb = req.params.imdb
	var username = req.params.username
	await Like.find({
		imdb: imdb,
		liker: username
	}).then( results => {
	if(results.length == 0){
		res.send('ohno')
	}else{
		res.send('ohyeah')
	}
})}catch(err){
		
	console.log("")
}
})

users.post('/savemovie', async (req, res) => {
	try{
	var imdb = req.body.imdb
	var title = req.body.title
	var username = req.body.username
	var poster = req.body.poster
	const filmData = {
		username: username,
		title: title,
		imdb: imdb,
		poster: poster
	}
	Watchlater.findOne({
		username: username,
		imdb: imdb
	}).then(async data => {
		if (!data){
	await Watchlater.create(filmData)
	res.send("film saved")
}
})}catch(err){
		
	console.log("")
}
})

users.get('/getmovs/:username', (req, res) => {
	try{
	var username = req.params.username
	Watchlater.find({
		username: username
	}).then(results => {
	res.send(results)
})}catch(err){
		
	console.log("")
}
})

users.post('/postcomment', async (req, res) => {
	try{
	var imdb = req.body.imdb
	var username = req.body.username
	var comment = req.body.commentaire
	const commentData = {
		imdb: imdb,
		commenter: username,
		comment: comment
	}
	await Comment.create(commentData)
	res.send("comment success")}catch(err){
		
	console.log("")
}
})

users.get('/getcomment/:imdb', (req, res) => {
	try{
	var imdb = req.params.imdb
	Comment.find({
		imdb: imdb
	}).then(comments => {
	res.send(comments)
})}catch(err){
		
	console.log("")
}
})


users.post('/postwatch', async (req, res) => {
	try{
	var imdb = req.body.imdb
	var username = req.body.username
	const watchedData = {
		imdb: imdb,
		username: username

	}
	try {
	Watched.findOne({
		username: username,
		imdb: imdb
	}).then(async data => {
		if (!data){
			await Watched.create(watchedData)
		}
	})
	}catch(err){
	}
	
	res.send("Watched list set")}catch(err){
		
	console.log("")
}
})

users.get('/getseen/:imdb/:username', (req, res) => {
	try{
	var imdb = req.params.imdb
	var username = req.params.username

	Watched.findOne({
			username: username,
			imdb: imdb
		}).then(async data => {
			if (data){
				res.send("yes")
			}else{
				res.send("no")
			}
		})}catch(err){
		
	console.log("")
}
})

function delfilm(hash){
	try{
	const filmData = {
		hash: hash,
		time: Date.now()
	}
	Movie.findOne({
		hash: hash
	}).then(async film => {
		if(!film) {
			await Movie.create(filmData)
		} else {
			Movie.find({}).then(all => {
			currentime = Date.now()
			var i = 0
			while(i < all.length)
			{
				rest = currentime - all[i].time
				rest = rest/(1000*60*60*24)
				if (rest >= 30)
				{	try {
					rmv.remove(`./movies/torrent-stream/${all[i].hash}`)
					}catch(err){
						console.log(err)
					}
				}
				i++
			}
		})
	}
})}catch(err){
		
	console.log("")
}
}

users.post('/movie', async (req, res) => {
	try{
	hash = req.body.hash
	lang = req.body.lang
	imdbbo = req.body.imdb
	
	var subsFolder = `./client/static/subs/${hash}`;
	
	if (fs.existsSync(subsFolder)) {
		try {
	const results = await yifysubtitles(imdbbo, {
		path: subsFolder,
		langs: ['en', 'fr', 'ar']
		});
	res.send("substitle downloaded!")
} catch(err){
	res.send("no substitle found")
}
	}
	else
	{
		await fs.mkdirSync(subsFolder)
		try{
		const results = await yifysubtitles(imdbbo, {
		path: subsFolder,
		langs: ['en', 'fr', 'ar']
		});
			res.send("substitle downloaded!")
	}catch(err){
		res.send("no substitle found")
	}
	}}catch(err){
		
	console.log("")
}
})

const engines = {};
const needToConvert = ext => {
  if (ext === ".mp4" || ext === ".webm") return false;
  else return true;
};

const convertFile = file => {
  try {
    const convertedFile = new FFmpeg(file.createReadStream())
      .videoCodec("libvpx")
      .audioCodec("libvorbis")
      .format("webm")
      .audioBitrate(128)
      .videoBitrate(8000)
      .outputOptions([`-threads 5`, "-deadline realtime", "-error-resilient 1"])
      .on("error", err => {});
    return convertedFile;
  } catch (err) {
    return file.createReadStream();
  }
  
};
const initIngine = (hash) => {
  return new Promise(function (resolve, reject) {
    let engine = engines[hash];
    const supportedFormat = ['.mp4', '.webm', '.ogg', '.wav', '.mkv', '.avi', '.wmv', '.3gp', '.hdv', '.lxf']

    if (engine) {
      return resolve(engine.selectedFile);
    }
try{
    engine = torrentStream(`magnet:?xt=urn:btih:${hash}`, {
      tmp: './movies',
      trackers: tr
    });
}catch(err){
	console.log("")
}
if(engine){
    engine.on('ready', function () {
      const file = engine.files.find(item => supportedFormat.includes(path.extname(item.name)));

      if (!file)
        return reject(new Error('Unsupported file format'));

      file.ext = path.extname(file.name);
      engines[hash] = {
        engine: engine,
        selectedFile: file
      };
      return resolve(file);
    });
}
  });
};

users.get('/streami/:mov/:imdb/:language', async (req, res) => {
try{
	idurl = req.params.mov
	imdb = req.params.imdb
	lang = req.params.language
	delfilm(idurl)
	var timer = Date.now()
	Movie.findOne({
		hash: idurl
	}).then(async film => {
		if(film) {
			await Movie.updateOne({"hash": film.hash}, {$set: {time: timer}})
		}
	})
	try{
	 res.setHeader('Accept-Ranges', 'bytes');

  initIngine(idurl)
    .then(function (file) {
     const converte = needToConvert(file.ext);
      
      if (converte === false) {
	      res.setHeader('Content-Length', file.length);
	      res.setHeader('Content-Type', `video/${file.ext}`);
	      const ranges = parseRange(file.length, req.headers.range, { combine: true });
	      if (ranges === -1) {
	        res.statusCode = 416;
	        return res.end();
	      } else if (ranges === -2 || ranges.type !== 'bytes' || ranges.length > 1) {
	        if (req.method !== 'GET') return res.end();
	        return file.createReadStream().pipe(res);
	      } else {
	        const range = ranges[0];
	        res.statusCode = 206;
	        res.setHeader('Content-Length', 1 + range.end - range.start);
	        res.setHeader('Content-Range', `bytes ${range.start}-${range.end}/${file.length}`);
	        if (req.method !== 'GET') return res.end();
	        return file.createReadStream(range).pipe(res);
      		}
      	}else{
      
          convertFile(file).pipe(res);
       }
    }).catch(function (e) {
      console.error(e);
      res.end(e);
    });
}
catch(err){
	console.log("")
}
}catch(err){
	console.log("")
}
})

users.post('/deleteAccount', (req, res) => {
	try{
	User.deleteOne({ atoken: req.body.atoken}, (err) => {
        if (err)
            throw err;
    });
    Comment.deleteMany({ commenter: req.body.username}, (err) => {
        if (err)
            throw err;
    });
    Like.deleteMany({ liker: req.body.username}, (err) => {
        if (err)
            throw err;
    });
    Watchlater.deleteMany({ username: req.body.username}, (err) => {
        if (err)
            throw err;
    });
    Watched.deleteMany({ username: req.body.username}, (err) => {
        if (err)
            throw err;
    });}catch(err){
		
	console.log("")
}
})
users.post('/forget', (req, res) => {
	if(typeof req.body.email !== "undefined" && typeof req.body.email === "string")
	{
	try{
	User.findOne({
		email: req.body.email
	})
	.then(user => {
		if(user) {
			var mailOptions = 
			{
				from: '1337hypertube@gmail.com',
				to: user.email,
				subject: 'Reset password',
				html: "<table><tr><td align='center'><img src='https://i1.wp.com/metro.co.uk/wp-content/uploads/2017/08/warrhyperloop.gif?quality=90&strip=all&zoom=1&resize=440%2C248&ssl=1'/><br><a href='http://localhost:8080/reset?token="+user.atoken+"'>Click to reset your password</a></td></tr>"
			};
			transporter.sendMail(mailOptions, function(err, data)
			{
				if (err) throw err;
			});
			res.send('Please check your email')
		}else{
			res.send('Email not found')
		}
	})
	.catch(err => {
		res.send('error: ' + err)
	})}catch(err){
		
	console.log("")
}
}
else
	res.send("")
})

users.post('/reset', (req, res) => {
	if(typeof req.body.npassword !== "undefined" && typeof req.body.renpassword !== "undefined" && typeof req.body.npassword === "string" && typeof req.body.renpassword === "string")
	{
	try{
	User.findOne({
		atoken: req.body.fortoken
	})
	.then(user => {
		if(user) {
			if (req.body.npassword == '' || req.body.renpassword == '') {
				res.send('Please fill all the fields')
			} else if (req.body.npassword != req.body.renpassword) {
				res.send('The password and confirmation password do not match')
			} else {
				bcrypt.hash(req.body.npassword, 10, (err, hash) => {
					User.updateOne({"_id": user._id}, {$set: {password: hash}}, (err, result) =>{
						res.send('Password updated!')
					})
					User.updateOne({"_id": user._id}, {$set: {atoken: randToken.generate(64)}}, (err, result) =>{
					})
				})
			}
		} else {
			res.send('Invalid token')
		}
	})}catch(err){
		
	console.log("")
}
}
else
	res.send("")
})

users.post('/verified', (req, res) => {
	try{
	User.findOne({
		atoken: req.body.fortoken
	})
	.then(user => {
		if(user) {
			User.updateOne({"_id": user._id}, {$set: {verified: '1'}}, (err, result) =>{
				res.send('Your account has been verified!')
			})
		} else {
			res.send('Invalid token')
		}
	})}catch(err){
		
	console.log("")
}
})

users.get('/profile/:id', async (req, res) => {
	try{
	var id = req.params.id

	const result = await User.findOne({
		atoken: id
	})
	.then(result => {
		if(result) {
			res.send(result)

		} else {
			res.send('User does not exist');
		}
	})
	.catch(err => {
		res.send('error: ' + err);
	})
}catch(err){
	console.log("")
}
})

users.get('/getvtt/:hash/:language', async (req, res) => {
	try{
	var hash = req.params.hash
	var lang = req.params.language
	var testFolder = `./client/static/subs/${hash}`;
	var filename = []
	if (fs.existsSync(testFolder)) {
		await fs.readdirSync(testFolder).forEach(file => {
    			if (lang == 'en' && file.endsWith('_english_.vtt')){
    				filename.push(file)
    			}
    			else if (lang == 'fr' && file.endsWith('_french_.vtt')){
    				filename.push(file)
    			}
		});

    	await fs.readdirSync(testFolder).forEach(file => {
    			if (!(lang == 'en' && file.endsWith('_english_.vtt')) && !(lang == 'fr' && file.endsWith('_french_.vtt'))){
    				filename.push(file)
    			}
		});
		res.send(filename)
	}
	else{
		res.send('no data')
	}}
	catch(err){
		res.send("")
	}
})

users.post("/profile", async (req, res) => {
	if(typeof req.body.username !== "undefined" && typeof req.body.fname !== "undefined" && typeof req.body.lname !== "undefined" && typeof req.body.email !== "undefined" && typeof req.body.password !== "undefined" && typeof req.body.picdata !== "undefined"
		&& typeof req.body.username === "string" && typeof req.body.fname === "string" && typeof req.body.lname === "string" && typeof req.body.email === "string" && typeof req.body.password === "string" && typeof req.body.picdata === "string")
	{
	try{
	User.findOne({
				atoken: req.body.id
			})
	.then(async user => {
		if(!user.omn)
		{
	if(req.body.password == '')
	{
		var picture = req.body.picdata
		if(picture.startsWith('data:image/'))
		{
			let base64Image = picture.split(';base64,').pop()
			var path1 = './client/static/images/image'+req.body.username+'.png'

			var path = path1.split('./client/').pop()
			try {
				await fs.unlinkSync(path1)
			} catch (e) {
				if (e.code !== 'ENOENT')
					throw err; 
			}
			await fs.writeFile(path1, base64Image, {encoding: 'base64'}, function(err) {
			});
			User.findOne({
				atoken: req.body.id
			})
			.then(async user => {
				User.findOne({
					username: req.body.username
				})
				.then(async res2 => {
					if (!res2){
						const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"username": req.body.username
						}
					}
					);
				res.status(200).send({ result });
					}
					else if (res2){
						const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"fname": req.body.fname,
							"lname": req.body.lname,
							"email": req.body.email,
							"lang": req.body.lang,
							"image": path
						}
					}
					);
				res.status(200).send({ result });
					}
				})
			})
			.catch(err => {
				res.send('error: ' + err)
			})
		}
		else
		{
			User.findOne({
			atoken: req.body.id
			})
			.then(async user => {
				User.findOne({
					username: req.body.username
				})
				.then(async res2 => {
					if (!res2){
					const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"username": req.body.username
						}
					}
					);
				res.status(200).send({ result });
			}
			else if (res2){
					const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"fname": req.body.fname,
							"lname": req.body.lname,
							"email": req.body.email,
							"lang": req.body.lang
						}
					}
					);
				res.status(200).send({ result });
			}
				})
				
			})
			.catch(err => {
				console.log(err)
				res.send('error: ' + err)
			})
		}
	} else if (req.body.password != '')
	{
		var password = req.body.password
		bcrypt.hash(req.body.password, 10, async (err, hash) => {
		password = hash
		var picture = req.body.picdata
		if(picture.startsWith('data:image/'))
		{
			let base64Image = picture.split(';base64,').pop()
			var path1 = './client/static/images/image'+req.body.username+'.png'

			var path = path1.split('./client/').pop()
			try {
				await fs.unlinkSync(path1)
			} catch (e) {
				if (e.code !== 'ENOENT')
					throw err; 
			}
			await fs.writeFile(path1, base64Image, {encoding: 'base64'}, function(err) {
			});
			User.findOne({
				atoken: req.body.id
			})

			.then(async user => {
				User.findOne({
					username: req.body.username
				})
				.then(async res2 => {
					if (!res2){
						const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"username": req.body.username
						}
					}
					);
				res.status(200).send({ result });
					}
					else if (res2){
						const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"fname": req.body.fname,
							"lname": req.body.lname,
							"email": req.body.email,
							"lang": req.body.lang,
							"password": password,
							"image": path
						}
					}
					);
				res.status(200).send({ result });
					}
				})
				
			})
			.catch(err => {
				res.send('error: ' + err)
			})
		}
		else
		{
			User.findOne({
			atoken: req.body.id
			})
			.then(async user => {
				User.findOne({
					username: req.body.username
				})
				.then(async res2 => {
					if (!res2){
						const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"username": req.body.username
						}
					}
					);
				res.status(200).send({ result });
					}
					else if (res2){
						const result = await User.updateOne(
					{"_id": user._id},
					{
						$set: {
							"fname": req.body.fname,
							"lname": req.body.lname,
							"email": req.body.email,
							"lang": req.body.lang,
							"password": password
						}
					}
					);
				res.status(200).send({ result });
					}
				})
				
			})
			.catch(err => {
				console.log(err)
				res.send('error: ' + err)
			})
		}
	})
}
}
})}catch(err){
		
	console.log("")
}
}
else
	res.send("")
})


module.exports = users
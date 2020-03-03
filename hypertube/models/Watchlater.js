const mongoose = require("mongoose")
const Schema = mongoose.Schema


const WatchlaterSchema = new Schema({
	username: {
		type: String,
		required: true
	},
	title: {
        type: String,
		required: true
    },
	imdb: {
		type: String,
		required: true
	},
	poster: {
		type: String,
		required: true
	}
})

Watchlater = mongoose.model('watchedlaters', WatchlaterSchema)
module.exports = Watchlater
const mongoose = require("mongoose")
const Schema = mongoose.Schema


const WatchedSchema = new Schema({
	imdb: {
        type: String,
		required: true
    },
	username: {
		type: String,
		required: true
	}
})

Watched = mongoose.model('watcheds', WatchedSchema)
module.exports = Watched
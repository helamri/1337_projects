const mongoose = require("mongoose")
const Schema = mongoose.Schema

const FilmSchema = new Schema({
	hash: {
        type: String,
		required: true
    },
	time: {
		type: String,
		required: true
	}
})
Film = mongoose.model('films', FilmSchema)
module.exports = Film
const mongoose = require("mongoose")
const Schema = mongoose.Schema

const LikeSchema = new Schema({
	imdb: {
        type: String,
		required: true
    },
	liker: {
		type: String,
		required: true
	}
})
Like = mongoose.model('likes', LikeSchema)
module.exports = Like
const mongoose = require("mongoose")
const Schema = mongoose.Schema

const CommentSchema = new Schema({
	imdb: {
        type: String,
		required: true
    },
	commenter: {
		type: String,
		required: true
	},
	comment: {
		type: String,
		required: true
	}
})
Comment = mongoose.model('comments', CommentSchema)
module.exports = Comment
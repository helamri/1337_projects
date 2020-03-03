const mongoose = require("mongoose")
const Schema = mongoose.Schema

const UserSchema = new Schema({
	atoken: {
        type: String,
        required: true
    },
	username: {
		type: String,
		required: true
	},
	fname: {
		type: String,
		required: true
	},
	lname: {
		type: String,
		required: true
	},
	email: {
		type: String,
		required: true
	},
	password: {
		type: String,
		required: true
	},
	lang: {
		type: String,
		required: true,
	},
	image: {
		type: String,
		required: true
	},
	verified: {
		type: String,
		default: '0'
	},
	date: {
		type: String,
		default: Date.now
	},
	omn: {
		type: String
	}
})

UserSchema.methods.findOrCreate = async function() {
    const User = mongoose.model('users')

    const user = await User.findOne({ username: this.username })

    if (!user) {
        return await this.save()

    }
    return user
}

User = mongoose.model('users', UserSchema)
module.exports = User
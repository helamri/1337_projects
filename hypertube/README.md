![1](pics/hypertube.gif)

**STEPS**:
- install npm
- install mongo from here https://www.mongodb.com/download-center/community
- create an empty folder for your database and make it's name **hyper**
- unzip mongo folder and open your terminal to /mongodb-macos-x86_64-4.2.3**/**bin
- type ./mongod --dbpath [the_path_of_your_hyper_folder]
- open hypertube project folder on other terminal window, then type **npm i** to install the packages of the server side
- open another terminal window and go to client folder insider hypertube project folder, then type **npm i** to install the packages of the client side
- when the installation done in the both sides, type on the two terminal window (server side window and client side window) **npm run dev**
- that's it! you can now open your browser to **localhost:8080** .. enjoy!

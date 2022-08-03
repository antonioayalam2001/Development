const express = require('express');
const cors = require('cors');
const cookieparser = require('cookie-parser');
const session = require('express-session')
const bodyparser = require('body-parser')
const {dbConnection} = require("../database/config");

class Server {
      constructor() {
            this.app = express();
            this.PORT = process.env.PORT;
            this.paths = {
                  authPath: '/api/auth',
                  categoriesPath: '/api/categories',
                  userPath: '/api/users',
            }
            //DB connection
            this.dbConnection()
            //Middlewares
            //    Aquellos que se eejcutan siempre que se levanta el servidor
            this.middlewares()
            //Rutas de la aplicacion
            this.routes();
      }

      async dbConnection() {
            await dbConnection();
      }

      middlewares() {
            const sessionConfig = {
                  name: "session",
                  secret: process.env.SECRETORPUBLICKEY,
                  cookie: {
                        maxAge: 1000 * 60 * 60,
                        secure: false,
                        httpOnly: true
                  },
                  resave: false,
                  saveUninitialized: true
            }
            //CORS
            this.app.use(cors());
            //Lecture and parsing from the body
            this.app.use(express.json())
            //Nos permite recibir los URL search params por medio de una petición fetch
            this.app.use(bodyparser.urlencoded({extended: true}))
            //Configurando sesiones
            this.app.use(session(sessionConfig))
            //Permite realizar la lecutra de las cookies
            this.app.use(cookieparser())
            //PUBLIC DIRECTORY
            this.app.use(express.static('public'));
      }

      routes() {
            this.app.use(this.paths.authPath, require('../routes/auth'))
            this.app.use(this.paths.categoriesPath, require('../routes/categories'))
            this.app.use(this.paths.userPath, require('../routes/user'))
      };

      start() {
            this.app.listen(this.PORT, () => {
                  console.log('Listening from port number : ', this.PORT);
            })
      }
}

module.exports = Server;
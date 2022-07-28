const express = require('express');
const cors = require('cors');
const {dbConnection} = require("../database/config");

class Server {
      constructor() {
            this.app = express();
            this.PORT = process.env.PORT;
            this.usuariosRoutePath = '/api/users'
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
            //CORS
            this.app.use(cors());
            //Lecture and parsing from the body
            this.app.use(express.json())
            //PUBLIC DIRECTORY
            this.app.use(express.static('public'));
      }

      routes() {
            this.app.use(this.usuariosRoutePath, require('../routes/user'))
      };

      start() {
            this.app.listen(this.PORT, () => {
                  console.log('Listening from port number : ', this.PORT);
            })
      }

};

module.exports = Server;
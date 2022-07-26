const express = require('express');
class Server {
      constructor(){
            this.app = express();
            this.PORT = process.env.PORT;

            //Middlewares
            //    Aquellos que se eejcutan siempre que se levanta el servidor
            this.middlewares()
            //Rutas de la aplicacion
            this.routes();
      }

      middlewares(){
            this.app.use(express.static('public'))
      }

      routes(){
            //ENDPOINT mas comunes: PUT REST POST DELETE
            this.app.get('/api',(req,res)=>{
                  res.status(403).json({
                        ok : true,
                        msg : "get API"
                  });
            });
      };

      start(){
            this.app.listen(this.PORT,()=>{
                  console.log('Listening from port numebr : ' , this.PORT);
            })
      }

};

module.exports = Server;
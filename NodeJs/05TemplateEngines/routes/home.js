'use strict'
let express = require('express'),
   router = express.Router()

const pug = (req,res,next) => { 
  let locals = {
    title: 'Pug',
    description: 'Pug is a template engine written in JavaScript.',

  }
  res.render("home", locals);
}

router
   // En el navegador : http://localhost:3000/home
  .get("/", (req, res) => {
    res.send("Bienvenido al apartado de Home donde solo tenemos la ruta de /");
    
  })
  // En el navegador : http://localhost:3000/home/homeRuta2
  .get("/homeRuta2", pug);

//   Exportamos todas las direcciones 
module.exports = router;
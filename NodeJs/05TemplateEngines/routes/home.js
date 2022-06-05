'use strict'
let express = require('express'),
   router = express.Router()
      
router
   // En el navegador : http://localhost:3000/home
  .get("/", (req, res) => {
    res.send("Bienvenido al apartado de Home");
    // res.render(index, { title: 'Index with Jade' });
  })
  // En el navegador : http://localhost:3000/home/homeRuta2
  .get("/homeRuta2", (req, res) => {
    res.send("Home ruta numero 2");
    // res.render(index, { title: 'Index with Jade' });
  });

//   Exportamos todas las direcciones 
module.exports = router;
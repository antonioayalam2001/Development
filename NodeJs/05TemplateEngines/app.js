'use strict'
const express = require("express"),
  app = express(),
  path = require("path"),
  favicon = require("serve-favicon"),
  jade = require("jade"),
  routeIndex = require("./routes/index"),
  // Esta cachando todo lo que venga exportado de este modulo de la forma:
  // module.exports = router;
  routeHome = require("./routes/home"),
  viewsURL = path.join(__dirname, "views"),
  logoURL = `${__dirname}/public/img/logoCompleto.png`,
  publicDir = express.static(path.join(__dirname, "public")),
  PORT = process.env.PORT || 3000;

// view engine setup
app
// Setting up the views to our ptoject
   .set('views', viewsURL)
   .set('view engine', 'jade')
   .set('port', PORT)
   // Starting the middlewares
   .use(favicon(logoURL))
   .use(publicDir)
   // enrouter middleware
   .use('/',routeIndex)
   .use('/home', routeHome)
   
   module.exports = app;


   
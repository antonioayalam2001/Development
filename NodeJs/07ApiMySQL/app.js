'use strict'

//bodyParser
//    Works to the handle of information sended trough the form from the html or the view template

//Respuesta de los datos en forma de JSOn
//     .use(bodyParser.json())

//Permite que el modo de encriptado de la información mandada mediante el formuario sea de la forma :
//       pplication/x-www-form-urlencoded
//     .use(bodyParser.urlencoded({extended:false}))

const express = require('express'),
    app = express(),
    morgan = require('morgan'),
    path = require('path'),
    favicon = require('serve-favicon'),
    bodyParser = require('body-parser'),
    viewsURL = path.join(__dirname,'views'),
    logoURL = `${__dirname}/public/img/logoCompleto.png`,
    publicDir = express.static(path.join(__dirname,'public')),
    PORT = process.env.PORT || 3000

//Routes declaration
const indexRoute = require('./routes/index')



app.set('views',viewsURL)
    .set('view engine','pug')
    .set('port',PORT)
    .use(morgan('dev'))
    .use(favicon(logoURL))
    .use(bodyParser.json())
    .use(bodyParser.urlencoded({extended:false}))
    .use(publicDir)
    .use('/',indexRoute)


module.exports = app


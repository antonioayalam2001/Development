'use strict'

const express = require('express'),
    app = express(),
    http = require('http').createServer(app),
    io = require('socket.io')(http),
    publicDir = express.static(`${__dirname}/public`),
    port=process.env.PORT||3000


//Consideremos dos rutas necesarias
//1-> Aquella donde se comienzan a transmitir
//2->Aquella donde se consume la transmision



app
    .use(publicDir)
    .get('/', (req, res) => {
        res.sendFile(`${publicDir}/index.html`)
    })

http.listen(port, () => {
    console.log('Iniciando Express y Socket.IO en localhost:%d', port)
})

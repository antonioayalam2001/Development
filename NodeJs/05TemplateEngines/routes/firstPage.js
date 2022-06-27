const express = require('express'),
    router = express.Router();

function firstPage (req,res){
    let locals = {
        titulo:'Titulo de la pagina',
        desc : 'This is a brief descriptcion about the content that youcan create',
        link : '/',
        array : [1,2,3]
    }
    res.render('main',locals)
}

router.get('/',(req,res)=>{
    res.end('<h1>Terminando configuraciones</h1>')
}).get('/main',firstPage)


module.exports = router;
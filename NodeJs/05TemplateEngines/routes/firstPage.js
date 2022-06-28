const express = require('express'),
    router = express.Router();

function firstPage (req,res){
    let locals = {
        titulo:'Realizando una página con PUG',
        desc : 'This is a demo of how a website can be created using PUG',
        link : '/',
        array : [1,2,3]
    }
    res.render('main',locals)
}

router.get('/',(req,res)=>{
    res.end('<h1>Terminando configuraciones</h1>')
}).get('/main',firstPage)


module.exports = router;
const express = require('express'),
    dbConMov = require('../models/movies.js'),
    router = express.Router()


function error404 (req,res,next){
    let error = new Error();
    let locals = {
        title: 'Error 404',
        desc: 'Página no encontrada',
        error: error.stack
    }
    error.status = 404;
    res.render('error', locals);
    // res.next()
}
router
    .use(dbConMov)
router
    .get('/',(req,res)=>{
    req.getConnection((err,dbConMov)=>{
        if(err){
            console.log(err);
            return;
        }
        dbConMov.query('SELECT * FROM movie',(err,movies)=>{
            if(err){
                console.log(err);
                return;
            }
            res.render('main',{
                title: 'Movies',
                data: movies
            });
        }
        );
    })
})
    .use(error404);

module.exports = router
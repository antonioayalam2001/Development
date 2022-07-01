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
    .get('/agregar',(req,res,next)=>{
        res.render('add-movie',{
            title: "Agregar"
        })
})
    .post('/',(req,res,next)=>{
        req.getConnection((err,dbConMov)=>{
            let dataToAdd = {
                movie_id : req.body.movie_id,
                title : req.body.title,
                release_year : req.body.release_year,
                rating : req.body.rating,
                image : req.body.image
            }
             console.log(dataToAdd)
            // ? -> Se reemplaza por el objeto que creamos de dataToAdd
            dbConMov.query('insert into movie set ?',dataToAdd,(error,rows)=>{
                return error ? res.redirect('/agregar') : res.redirect('/')

            })
        })
    })
    .get('/editar/:titulo/:valor', (req,res,next)=>{
         console.log(req.params.titulo)
         console.log(req.params.valor)
         // console.log(req.searchParams)
         // console.log(req.params.title)
    })
    .use(error404);

module.exports = router



//RECUPERANDO PARAMETROS

//link : href=`/editar/?title=${movie.title}&hola=hihihi`
// Metodo:          console.log(req.query)
//                        console.log(req.query.title)
//                        console.log(req.query.hola)
//
// link : href=/editar/${movie.title}`
// Metodo :     .get('/editar/:titulo', (req,res,next)=>{
//          console.log(req.params.titulo)
//     })
'use strict'
//This variable has the module of the model
let MovieModel = require('../models/movie-model'),
    MovieController = () => {
    }
// Decide que es lo que necesita la vista y el modelo
//    This one takes charge of getting all the comunication between views  with the model
//    The controller must have the same methods as the model
MovieController.getAll = (req,res,next) => {
    MovieModel.getAll( (err, data) => {
        if (err) {
            let locals = {
                title : 'Error',
                desc : 'Error de sintaxis SQL'
            }
            res.render('error',locals)
        }
        let locals = {
            data: data,
            title: 'Movies'
        }
        res.render('main', locals);
    })
}
MovieController.insert = (req,res,next) => {
    let dataToAdd = {
        movie_id: req.body.movie_id,
        title: req.body.title,
        release_year: req.body.release_year,
        rating: req.body.rating,
        image: req.body.image
    }
    console.log(dataToAdd)
    MovieModel.insert(dataToAdd, (error, rows) => {
        console.log(error)
        return error ? res.redirect('/agregar') : res.redirect('/')
    })
}
MovieController.getOne = (req,res,next) => {
}
MovieController.update = (req,res,next) => {
}
MovieController.delete = (req,res,next) => {
}
//Solicitando vista de formulario
MovieController.addForm = (req,res,next) => {
        res.render('add-movie', {
            title: "Agregar"
        })
}
MovieController.error404 = (req,res,next) => {
    let error = new Error();
    let locals = {
        title: 'Error 404',
        desc: 'Página no encontrada',
        error: error.stack
    }
    error.status = 404;
    res.render('error', locals);
}

module.exports = MovieController
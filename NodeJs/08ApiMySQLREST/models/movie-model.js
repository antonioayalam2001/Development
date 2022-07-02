'use strict'
//This variable has the connection that comes from movie-connection
//Operaciones que realizan las bases de datos unico conectado a la misma
let con = require('./movie-connection'),
    MovieModel = () => {
    }
//    The only one who needs the connection is this one
MovieModel.getAll = (callBack) => {
    con.query('SELECT * FROM movie',callBack)
}
MovieModel.insert = (data,callback) => {
    con.query('insert into movie set ?',data,callback)
}
MovieModel.getOne = () => {
}
MovieModel.update = () => {
}
MovieModel.delete = () => {
}

module.exports = MovieModel

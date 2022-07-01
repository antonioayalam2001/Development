'use strict'
// Archivo para crear conexion con la base de datos

const mySQL = require('mysql'),
    myConnection = require('express-myconnection'),
    cbOptions = {
        host: 'localhost',
        user: 'root',
        password: 'password',
        port: 3306,
        database: 'movies'
    };

let dbConMov = myConnection(mySQL, cbOptions, 'request');
module.exports = dbConMov;


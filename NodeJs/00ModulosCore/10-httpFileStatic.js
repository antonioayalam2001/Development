'use strict'
let http = require('http');
let fs = require("fs");
let index;
index = fs.createReadStream(
  "/Users/tonyayala/Library/CloudStorage/OneDrive-Personal/Universidad/NodeJs/00ModulosCore/assets/index.html"
);  
let urlFile =
  "/Users/tonyayala/Library/CloudStorage/OneDrive-Personal/Universidad/NodeJs/00ModulosCore/assets/index.html";


http.createServer((req, res) => { 
    // function that helps us to handle if there's an error while reading an static html page
    function readFile(err,data) {
        if (err) throw err
        res.end(data)
    }
    res.writeHead(200, { 'Content-Type': 'text/html' });
    // fs.readFile(urlFile, options, callbackFunction);
    fs.readFile(urlFile, readFile)
}).listen(8081);
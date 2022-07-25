const http = require('http')


const server = http.createServer((req,res)=> {
     /*req ->
     To do lo que se solicida
     Headers, solicitudes que se nos realizan al servidor
     */
      /*          RESPONSE
      *     Aquello que nuestro servidor responde al cliente
      * */
      res.write('Hola Mundo');
      res.end();
})
    server.listen(3000)

console.log('Escuchando')
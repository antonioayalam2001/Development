const http = require('http')

//MAS INFORMACION ACERCA DE LOS METODOS EN NOTION O EN EL DOCUMENTO DE TEMAS
const server = http.createServer((req,res)=> {
      // console.log(req);
      //Accediendo a los headers
      // console.log(req.headers);
      //El token fue mandado mediante postman
      let {token} = req.headers;
      if(token){
            res.writeHead(302, {
                  'Location': 'http://google.com'
            });
            res.end();
      }else if (!token){
            // res.writeHead(202,{'Content-Type' : 'text/plain'})
            // req.url === '/page2' ? res.write('Page number 2') :
            //     res.write('Hola Mundo');
            if (req.url === '/page-json'){
                  const person = {
                        name : 'Antonio,',
                        age : 21
                  }
                  console.log('RESPONSE')
                  res.writeHead(202,{'Content-Type' : 'application/json'})
                  res.write(JSON.stringify(person))
            }
            //We must be specifying that we already finished
            res.end();
      }
})
    server.listen(3000)

console.log('Escuchando')
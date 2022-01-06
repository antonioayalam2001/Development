Notes to NodeJS

npm init

--Inicializa el proyecto creando el package JSON
--

npm -i express ejs
--Instalar dependencias
--express para la parte del servidor
--ejs Lenguaje que estamos ocupando que sería el de html con java integrado

npm i --save-dev nodemon dotenv
--nodemon: Reinicia servidor cada que se hagan modificaciones
--dotenv encriptar algunas informaciones

npm run devStart
--Comenzar a correr el servidor
--En el archivo json debemos cambiar a el archivo que tiene toda la estructura que va a correr en este caso "server.js"

app.use(express.static("Public"))
--Nos esta permitiendo acceder a las hojas de estilo


notes
INSTRUCCIONES PARA INICIALIZAR NODE JS Y MOONGOSE:
--Inicializar JSON
npm init 
--Instalar dependencias
npm i express ejs
--express : application server
--ejs : languaje
npm i --sabe-dev nodemon dotenv
--nodemon: Refresca en automatico
--dotenv : environment variables
npm run devStart
--Comienza a correr nuestro servidor 

--Esto va en el JSON que se genera:
"scripts": {
    "devStart": "nodemon server.js"
  }

--Instalando los paquetes necesarios para la base de datos 
npm install mongoose 
<%=  %>  : Pasamos una variable que viene desde el servidor
let userSocket = null;
let socket = null
const url = (window.location.hostname.includes('localhost'))
    ? 'http://localhost:3000/api/auth/'
    : 'https://projectapinodejstunas.herokuapp.com/api/auth/'

//Validate Token from LocalStorage
const validateJWT = async()=>{
      let token = localStorage.getItem('token') || null ;
      if (!token || token.length<10) {
            window.location = "index.html"
            return console.error("No hay ningún token actualmente")
      }
      const response = await fetch(url, {
            headers: {
                  "Content-Type": 'application/json',
                  "x-token": token
            }, method: "GET"
      });

      const {msg , token : tokenDB, usuario} = await response.json();
      //Renovando el Token
      localStorage.setItem("token",tokenDB);
      console.log(tokenDB)
      console.log(usuario)
      userSocket = usuario
}
const main = async () => {
      await validateJWT();
}


main();
// const socket = io()

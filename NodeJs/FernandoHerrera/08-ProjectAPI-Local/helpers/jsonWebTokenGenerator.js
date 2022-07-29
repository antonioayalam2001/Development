require('dotenv').config()
const JWT = require('jsonwebtoken');

//UID -> User Identifier lo unico que vamos a almacenar en el Payload
//Podemos almacenar to do lo que queramos
const JsonWebTokenGenerator = (uid = '')=>{
      return new Promise((resolve, reject)=>{
            const payload  = {uid}
            JWT.sign(payload,process.env.SECRETORPUBLICKEY)
      })


}
module.exports = {JsonWebTokenGenerator};
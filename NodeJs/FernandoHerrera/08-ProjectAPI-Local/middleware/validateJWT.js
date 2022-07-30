require('dotenv').config();
const JWT = require('jsonwebtoken');
const Usuario = require('../models/user');
const cookieparser = require('cookie-parser');

const validateJWT = async (req,res,next) => {
      // console.log(req.session)
      // const token = req.cookies.token || req.headers['x-token']
      const token = req.session.token;
      if(!token){
            return res.status(401).json({
                  msg:'No hay token en la petición :('
            })
      }
      try{
            JWT.verify(token,process.env.SECRETORPUBLICKEY)
            const {uid} = JWT.decode(token, process.env.SECRETORPUBLICKEY);
            //leer usuario que corresponde al uid
            const usuario = await Usuario.findOne({_id:uid});
            if(!usuario){
                  return res.status(401).json({
                        msg : "El usuario no existe en la base de Datos"
                  })
            }
            //Verificar si el uid no esta dado de baja state : false
            if (!usuario.state) {
                  return res.status(401).json({
                        msg : "El usuario no esta dado de alta"
                  })
            }
            req.user = usuario;
            req.uid = uid;
            //Agregando información a nuestra session
            next();
      }catch (e) {
            console.log(e)
            res.status(401).json({
                  msg : "Token no valido"
            })
      }


}

module.exports = {validateJWT}
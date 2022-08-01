const {request: req, response: res} = require('express');
const Usuario = require('../models/user')
const bcrypt = require('bcrypt');
const cookieparser = require('cookie-parser');
const {JsonWebTokenGenerator} = require("../helpers/jsonWebTokenGenerator");
const {googleVerify} = require("../helpers/googleVerify");


const loginPost = async (req, res) => {
      const {email, password} = req.body
      try {
            //verificar si email existe
            const usuario = await Usuario.findOne({email});
            // console.log(usuario)
            if (!usuario) {
                  return res.status(400).json({
                        msg: "Usuario / Password incorrecto --> EMAIL",
                  })
            }
            //Verificar si usuario se encuentra activo
            if (!usuario.state) {
                  return res.status(400).json({
                        msg: "Eliminado -- state : false",
                  })
            }
            //Verificar contraseña
            const validPassword = bcrypt.compareSync(password, usuario.password)
            if (!validPassword) {
                  return res.status(400).json({
                        msg: "Usuario / Password incorrecto --> PASSWORD",
                  });
            }
            //Generar JSON Web Token
            const token = await JsonWebTokenGenerator(usuario._id);
            // console.log(usuario)
            //Retirando el id del usuario dado que ya contamos con el en el JWT
            res.setHeader("cookie", token);
            res.cookie('token', token);
            // console.log(req.session)
            //Agregando información a nuestra session
            req.session.token = token;
            req.session.usuario = usuario;

            res.json({
                  msg: "Login success",
                  usuario,
                  token
            });
      } catch (e) {
            return res.status(500).json({
                  msg: 'Something went wrong'
            });
      }
}

const googleSign = async (req, res) => {
      const {token} = req.body;
      //Recuperando información del token
      try {
            const {nombre,img,email} = await googleVerify(token);
            console.log(googleUser);
            let usuario = await Usuario.findOne({email});
            if (!usuario){
                  const data = {
                        nombre,
                        email,
                        password : 'noImportaria',
                        img,
                        google : true
                  }
                  usuario = new Usuario(data)
                  await usuario.save()
            }else{
            //      Realizar actualización de los campos correspondientes a los de Google
            }
            res.json({
                  token,
                  msg: "Todo correcto, Google Sign in complete"
            })

      } catch (e) {
            res.status(400).json({
                  msg: "Algo salio mal al consultar la autenticación con Google"
            })
      }
}

module.exports = {
      loginPost,
      googleSign
}
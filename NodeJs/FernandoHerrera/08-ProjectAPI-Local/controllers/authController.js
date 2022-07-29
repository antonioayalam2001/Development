const {request: req, response: res} = require('express');
const Usuario = require('../models/user')
const bcrypt = require('bcrypt');
const {JsonWebTokenGenerator} = require("../helpers/jsonWebTokenGenerator");

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
            if (! usuario.state) {
                  return res.status(400).json({
                        msg: "Eliminado -- state : false",
                  })
            }
            //Verificar contraseña
            const validPassword = bcrypt.compareSync(password,usuario.password)
            if (!validPassword){
                  return res.status(400).json({
                        msg: "Usuario / Password incorrecto --> PASSWORD",
                  });
            }
            //Generar JSON Web Token
            const token = await JsonWebTokenGenerator(usuario._id);
            // console.log(usuario)
            //Retirando el id del usuario dado que ya contamos con el en el JWT
            res.setHeader("token",token)
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

const ruta2 = async (req, res) => {
      console.log(res.headers)
}


module.exports = {
      loginPost
}
const {request: req, response: res} = require('express');
const Usuario = require('../models/user')
const bcrypt = require('bcrypt');

const loginPost = async (req, res) => {
      const {email, password} = req.body
      try {
            //verificar si email existe
            const usuario = await Usuario.findOne({email});
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
                  })
            }
            //Generar JSON Web Token

            res.json({
                  msg: "Login success",
                  email,
                  password
            })
      } catch (e) {
            return res.status(500).json({
                  msg: 'Something went wrong'
            })
      }


}


module.exports = {
      loginPost
}
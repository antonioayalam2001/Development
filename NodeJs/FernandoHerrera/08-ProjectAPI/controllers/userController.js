const {response: res, request: req} = require('express');
const Usuario = require('../models/user');
const bcrypt = require('bcrypt');

const usuariosGet = async(req, res) => {
      const {limite , desde = 0 } = req.query;
      const usuarios = await Usuario.find().limit(limite).skip(desde);
      const usersCount =  await Usuario.find().count()

      res.json({usuarios , usersCount, limite , desde})
}

//Inserting a new User
const usuariosPost = async (req, res) => {
      //Si en el body vienen otros campos no existentes son ignorados
      const {nombre, email, password, role} = req.body;
      const usuario = new Usuario({nombre, email, password, role});
      //Encrypt password || Hash
      const saltRound = bcrypt.genSaltSync();
      usuario.password = bcrypt.hashSync(password, saltRound);
      //Save
      await usuario.save();
      // FORMA 2 de eliminar las propiedades
      // const resultado = usuario.toObject()
      // delete resultado.password
      // delete resultado.__v
      // console.log(resultado)
      res.status(403).json({
            usuario
      });
}

const usuariosPut = async (req, res) => {
      const {id} = req.params;
      const {_id, password, google, ...resto} = req.body;
      //Validar contra base de datos
      if (password) {
            //            Desea actualizar la contraseña
            const saltRound = bcrypt.genSaltSync();
            resto.password = bcrypt.hashSync(password, saltRound);
      }
      const usuario = await Usuario.findByIdAndUpdate(id, resto);
      res.status(202).json(
            usuario
      );
}

const usuariosPatch = (req, res) => {
      res.status(403).json({
            msg: "patch API-Controller"
      });
}
const usuariosDelete = (req, res) => {
      res.status(403).json({
            msg: "delete API-Controller"
      });
}

module.exports = {
      usuariosGet,
      usuariosPost,
      usuariosPut,
      usuariosPatch,
      usuariosDelete
}
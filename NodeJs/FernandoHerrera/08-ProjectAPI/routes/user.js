const {Router} = require('express');
const {check, param} = require('express-validator');
const {
      usuariosGet,
      usuariosPut,
      usuariosDelete,
      usuariosPost,
      usuariosPatch
} = require("../controllers/userController");
const {validateField} = require("../middleware/validate_fields");
const {isValidRole, emailExists, userExists} = require("../helpers/dbValidators");

//Defining router
const router = Router();
//ENDPOINT mas comunes: PUT REST POST DELETE
router.get('/', usuariosGet);
//Mandando los Middlewares necesarios
router.post('/',
    [
          //Corroborando que no este vacio
          check('nombre', 'Nombre obligatorio').not().isEmpty(),
          //Corroborando que coincida con correo
          check('email', 'El correo no es valido').isEmail(),
          check('email').custom(emailExists),
          check('password', 'Contraseña con longitud corta').isLength({min: 6}),
          //custom manda el valor del campo ingresado, pero como solo recibimos ese campo podemos "obviarlo"
          // check('role').custom(     isValidRole   ),
          check('role').custom((role) => isValidRole(role)),
          //Permite realizar la verificacion de que no hubieorn errores
          validateField
    ]
    , usuariosPost);
router.put('/:id', [
      check('id', 'No es un ID valido').isMongoId(),
      check('id').custom(userExists),
      check('role').custom((role) => isValidRole(role)),
      validateField
], usuariosPut);
router.patch('/', usuariosPatch)
router.delete('/', usuariosDelete);

module.exports = router;
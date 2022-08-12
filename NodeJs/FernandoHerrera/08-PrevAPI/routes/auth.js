const {Router} = require('express');
const {check} = require('express-validator');
const {validateField} = require("../middleware/validate_fields");
const {loginPost, googleSign, usuarioRegister} = require("../controllers/authController");
const router = Router();


router.get('/register',usuarioRegister);

router.post('/login',
    [
        check('email','Email must be provided').isEmail(),
        check('password','Password must be provided').not().isEmpty(),
        validateField
    ]
    ,loginPost);

router.post('/google',
    [
          check('token','El ID Token es necesario').not().isEmpty(),
          validateField
    ]
    ,googleSign);

module.exports = router;



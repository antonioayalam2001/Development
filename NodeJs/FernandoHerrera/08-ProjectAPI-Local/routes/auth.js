const {Router} = require('express');
const {check} = require('express-validator');
const {validateField} = require("../middleware/validate_fields");
const {loginPost} = require("../controllers/authController");
const router = Router();

router.post('/login',
    [
        check('email','Email must be provided').isEmail(),
        check('password','Password must be provided').not().isEmpty(),
        validateField
    ]
    ,loginPost);

module.exports = router;
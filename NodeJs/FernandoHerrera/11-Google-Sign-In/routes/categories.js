const {Router} = require('express')

//Controller
const {getCategories} = require("../controllers/categoriesController");
const router = Router()



router.get('/',getCategories);

module.exports = router
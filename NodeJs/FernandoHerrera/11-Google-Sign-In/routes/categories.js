const {Router} = require('express')
const {check} = require('express-validator');
const {validateField, validateJWT, validateAdminRole, tieneRol} = require('../middleware')
const {isValidRole, emailExists, userExists, categoryExists} = require("../helpers/dbValidators");
//Controller
const {
      getCategories,
      getCategoryById,
      insertCategory,
      updateCategoryById,
      deleteCategoryById
} = require("../controllers/categoriesController");
const router = Router()


//Route to access /api/categories
//Getting all the categories PUBLIC
router.get('/', getCategories);
//Get id Getting just one category per ID
router.get('/:id',[
      check('id','Necesitas tener un id valido para Solicitar').custom(categoryExists),
      validateField
] , getCategoryById)
//POST  -> Create category private (any role ----> Anyone with a token)
router.post('/', [
    validateJWT,
    check('name',"Name can not be empty").notEmpty(),
    check('description','You need to give a valid description').notEmpty()
],insertCategory)
//PUT -> Update by ID (Anyone with a valid token)
router.put('/:id',[
      validateJWT,
      check('id','Necesitas tener un id valido para eliminar').custom(categoryExists),
      validateField
] , updateCategoryById)
//DELETE -> Delete Category (Just if Role == Admin from active to inactive)
router.delete('/:id', [
    validateJWT,
    validateAdminRole,
    check('id','Necesitas tener un id valido para eliminar').custom(categoryExists),
    validateField
], deleteCategoryById)
module.exports = router
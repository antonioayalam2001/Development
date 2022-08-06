const {Router} = require('express');
const {check} = require('express-validator');
const {validateField,validateCollections} = require("../middleware");
const {uploadFile, updateImg} = require("../controllers");
// const {allowedCollections} = require("../helpers");

const router = Router();
//ROUTE : api/uploads

//Upload File with an non existent file POST
//We can send multiple files but it is better to just do one at the time
router.post('/',uploadFile)
//Update a file that already exists
router.put('/:collection/:id',[
    check('id','Id must be a valid MongoId').isMongoId(),
    validateCollections(['users','products']),
    // check('collection',"Collection must exists").custom(c=> allowedCollections(c,['users','products'])),
    validateField
],updateImg)

module.exports = router
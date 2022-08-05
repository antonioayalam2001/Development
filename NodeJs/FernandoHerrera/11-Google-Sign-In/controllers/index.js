const authController = require('./authController')
const categoriesController = require('./categoriesController')
const productController = require('./productController')
const searchController = require('./searchController')
const userController = require('./userController')

module.exports = {
      ...authController,
      ...categoriesController,
      ...productController,
      ...searchController,
      ...userController
}
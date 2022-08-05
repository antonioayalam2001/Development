const {
      Role, Usuario, Category, Product
} = require('../models')


const isValidRole = async (role = '') => {
      const existeRol = await Role.findOne({rol: role})
      if (!existeRol) {
            //Error personalizado del mismo Express Validator, no romple la aplicacion
            throw new Error('El role no se encuentra registrado en la base de Datos')
      }
}

const emailExists = async (email = '') => {
      //Verifying if email exists
      const exists = await Usuario.findOne({email})
      if (exists) {
            throw new Error(`El correo : ${email}  ya se encuentra registrado en la base de datos`)
      }
}

const userExists = async (id) => {
      const user = await Usuario.findById(id);
      if (!user) {
            throw new Error(`El ${id} no se encuentra en la base de datos`)
      }
}

const categoryExists = async (id) => {
      const category = await Category.findById(id);
      if (!category) {
            throw new Error(`El ${id} no se encuentra en la base de datos`)
      }
}

const productExists = async (id) => {
      const product = await Product.findById(id);
      if (!product) {
            throw new Error(`This ${id} is not registered in the Database system `)
      }
}
const categoryName = async (category) => {
      const categoryExists = await Category.findOne({name: category.toUpperCase(), state: true});
      if (!categoryExists || categoryExists.state === false) {
            throw new Error(`This category ${category} is not registered in the Database system try with another category `)
      }
}

module.exports = {
      isValidRole,
      emailExists,
      userExists,
      categoryExists,
      categoryName,
      productExists
}
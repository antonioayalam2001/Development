

const getCategories = (req,res)=>{
      res.status(200).json({
            msg : "Lista de Categorias"
      })
}


const getCategoryById = (req,res) => {
      res.status(200).json({
            msg : 'Todo bien'
      })
}


const insertCategory = (req,res) => {
      res.status(200).json({
            msg : 'Todo bien'
      })
}

const updateCategoryById = (req,res) => {
      res.status(200).json({
            msg : 'Todo bien'
      })
}

const deleteCategoryById = (req,res) => {

      res.status(200).json({
            msg : 'Todo bien DELETE'
      })
}

module.exports = {
      getCategories,
      getCategoryById,
      insertCategory,
      updateCategoryById,
      deleteCategoryById
}
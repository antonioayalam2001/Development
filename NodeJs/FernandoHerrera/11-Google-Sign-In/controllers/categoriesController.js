

const getCategories = (req,res)=>{
      res.status(200).json({
            msg : "Lista de Categorias"
      })
}

module.exports = {
      getCategories
}
'use strict'
const colors = require('colors')


const  showMenu = () =>{
      console.clear()
      console.log('========================'.magenta)
      console.log('--Seleccione una opcion--'.bgWhite.underline)
      console.log('========================\n'.magenta)

      console.log(`${'1'.green} Crear una Tarea`)
      console.log(`${'2'.green} Listar Tareas`)
      console.log(`${'3'.green} Listar tareas Completadas `)
      console.log(`${'4'.green} Listar Tareas Pendientes`)
      console.log(`${'5'.green} completar Tarea (s)`)
      console.log(`${'6'.green} Borrar Tarea`)
      console.log(`${'0'.green} Salir \n`)


}



module.exports = {showMenu}
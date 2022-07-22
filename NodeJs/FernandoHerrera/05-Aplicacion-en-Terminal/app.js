'use strict'
const colors = require('colors')
// const {showMenu, pause} = require("./helpers/messages");
const {inquirerMenu, pause, leerInput} = require("./helpers/inquirer");
const Tareas = require("./models/tareas");
const {saveDB, readDB} = require("./helpers/saveFile")

const main = async () => {
      console.clear();
      let opt = '';
      const tareas = new Tareas();
      const tareasDB = readDB();
      if (tareasDB) {
            console.log(tareasDB)
            tareas.loadDataFromArray(tareasDB)
            await pause()
      }
      do {
            opt = await inquirerMenu();
            switch (opt) {
                  case '1' :
                        //Crear Opcion
                        const desc = await leerInput('Please enter the description to your To-Do')
                        tareas.crearTarea(desc)
                        break;
                  case '2' :
                        tareas.listadoCompleto()
                        break;
                  case '3' :
                        break;
                  case '4' :
                        break;
                  case '5' :
                        break;
                  case '6' :
                        break;
            }

            saveDB(tareas.listadoArr);
            await pause()
      } while (opt !== '0')

}


main()

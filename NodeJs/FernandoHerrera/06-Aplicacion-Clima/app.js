const {leerInput, inquirerMenu, pause} = require("./helpers/inquirer");
const Busquedas = require("./models/busquedas.js");


const main = async () => {
      console.clear();
      let opt;
      do{
            opt = await inquirerMenu();
            switch (opt){
                  case 1:
                        //Show message
                      const place = await leerInput('City')
                        console.log(place)
                        console.log('\nInformacion de la ciudad\n'.green)
                        console.log('Ciudad')
                        console.log('Lat')
                        console.log('Lng')
                        console.log('Temperature')
                        break
                  case 2:
                        //Search places
                        break
                  case 3:
                        //Select place
                        break
                  case 4:
                        //Show weather
                        break
                  case 5:
                        // Show results
                        break
            }
            if (opt !==0) await pause();
      }while(opt!==0)

}

main()
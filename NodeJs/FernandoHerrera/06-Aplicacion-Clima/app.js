const {leerInput, inquirerMenu, pause, listarLugares} = require("./helpers/inquirer");
const Busquedas = require("./models/busquedas.js");


const main = async () => {
      console.clear();
      const busquedas = new Busquedas()
      let opt;
      do{
            opt = await inquirerMenu();
            switch (opt){
                  case 1:
                        //Show message
                      const place = await leerInput('City');
                      const places = await busquedas.ciudad(place);
                      const id = await listarLugares(places)
                      if (id!==0){
                            const selectedPlace = places.find(place=>place.id === id)
                            const {lat , lng }  = selectedPlace
                            const clima = await busquedas.weatherByPlace(lat,lng)
                            console.log(`\nInformacion de la ciudad   \n`.green)
                            console.log(`Ciudad ${selectedPlace.place_name}`)
                            console.log(`Latitude ${lat}`)
                            console.log(`Longitude: ${lng}`)
                            console.log(`Como esta el clima`.bold.magenta)
                            console.log(`Temperature : ${clima.temp}`.bold)
                            console.log(`Max_Temperature : ${clima.temp_max}`)
                            console.log(`Min_Temperature ${clima.temp_min}`)
                      }
                        break
            }
            if (opt !==0) await pause();
      }while(opt!==0 )

}

main()
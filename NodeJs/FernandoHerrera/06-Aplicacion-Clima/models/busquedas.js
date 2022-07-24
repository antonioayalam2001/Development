//Default settings
// const axios = require('axios').default;
//Normal
const axios = require('axios');
const dotenv = require('dotenv').config()

class Busquedas {
      //Limit 6
      historial = ['Mexico', 'USA', 'Madrid'];

      constructor() {
            // TODO: read DB if exists
      }

      get paramsMapBok(){
            return {
                  //El access token no deberia estar en el archivo
                  'access_token':`${process.env.MAPBOX_KEY}`,
                  'limit' : 5,
                  'language': 'en'
            }
      }

      async ciudad(lugar = '') {

            try {
                  //     HTTP require
                  //       Sending our own params to the request
                  const instance = axios.create({
                        // New%20York
                        baseURL : `https://api.mapbox.com/geocoding/v5/mapbox.places/${lugar}.json`,
                        params : this.paramsMapBok
                  })
                  const resp = await instance.get()
                  /*
                  * From data we need
                  * id
                  * place_name
                  * center -> Array with lon and lat
                  * */
                  //      Returns an array with all the locations that matches with the one choosed by the user
                  return resp.data.features.map(place => {
                        let {id,place_name,center} = place;
                        return {
                              id,
                              place_name,
                              lng : center[0],
                              lat: center[1]
                        }
                  })
            } catch (e) {
                  //Finishes the app
                  // throw e
                  // Returning an empty array just to keep the app going
                  return []
            }
      };

      get paramsWeather(){
            return  {
                  appid : process.env.OPENWETHERAPP,
                  units : 'metric'
            }
      }

      async weatherByPlace (lat,lon){
            try{
            //      Create instance for axios
                  const instance = axios.create({
                        baseURL : `https://api.openweathermap.org/data/2.5/weather`,
                        params : { ...this.paramsWeather,lat,lon}
                  })
            //      Response: Get the info from the data
                  const response = await instance.get();
                  const {temp,temp_min,temp_max} = response.data.main;
                  const [{description}] = response.data.weather;
                  return {
                        temp,
                        temp_min,
                        temp_max,
                        description
                  }
            }catch (e){
                  console.log('No se ha podido encontrar dicha ciudad')
            }
      }


}

module.exports = Busquedas
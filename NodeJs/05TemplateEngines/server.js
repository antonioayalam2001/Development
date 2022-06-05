// 'use strict'

// let app = require('./app'),
// server = app.listen(app.get('port'), () => {
//   console.log('Server on port', app.get('port'));
// })

const array = [1, 2, 3, 4, 5]
const [numero1, numero2] = array
console.log(numero1, numero2);

const objeto = {
   nombre: 'Juan',
   apellido: 'Perez'
}

const { nombre, apellido } = objeto
console.log(nombre, apellido);
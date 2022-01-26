// class Persona {
//     constructor(nombre, instagram) {
//         this.nombre = nombre
//         this.instagram = instagram
//     }
// }

// const data = [
//     ["Tony","Tony1"],
//     ["Ramon","Ramon11"],
//     ["Lupita","Lupita11"],
//     ["Sandy","Sandy1"],
// ]

// const personasCreadas = []

// for (let index in data) {
//     personasCreadas[index] = new Persona(data[index][0],data[index][1])
// }

// const obtenerPersona=  (id,callback) => {
//     if (personasCreadas[id] == undefined) {
//         callback('No se ha encontrado la persona')
//     } else {
//         callback(null,personasCreadas[id],id)
//     }
// }
// const obtenerInstagram=  (id,callback) => {
//     if (personasCreadas[id] == undefined) {
//         callback('No se ha encontrado Instagram')
//     } else {
//         callback(null,personasCreadas[id].instagram)
//     }
// }

// obtenerPersona(2 ,(err,persona,id) => {
//     if (err) {
//         console.log(err);
//     } else {
//         console.log(persona.nombre);
//         (obtenerInstagram(5, (err,persona) => {
//             if (err) {
//                 console.log(err);
//             } else {
//                 console.log(persona);
//             }
//         }));
//     }
// })

// let nombre = 'Tony'

// const promise = new Promise((resolve, reject) => {
//     if (nombre != 'Tony') {
//         reject ('Sorry name dont match')
//     } else {
//         resolve (nombre)
//     }
// })

// promise.then((result) => {
//     console.log(result);
// }).then(()=> {
// console.log('Podemos hacer algo asi ');
// }).catch ((err) => {
//     console.log(err);
// });

class Persona {
  constructor(nombre, instagram) {
    this.nombre = nombre;
    this.instagram = instagram;
  }
}

const data = [
  ["Tony", "Tony1"],
  ["Ramon", "Ramon11"],
  ["Lupita", "Lupita11"],
  ["Sandy", "Sandy1"],
];

const personasCreadas = [];

for (let index in data) {
  personasCreadas[index] = new Persona(data[index][0], data[index][1]);
}

const obtenerPersona = (id) => {
  return new Promise((resolve, reject) => {
    if (personasCreadas[id] == undefined) {
      reject("La persona no se encuentra");
    } else {
      resolve(personasCreadas[id].nombre);
    }
  });
};
const obtenerInstagram = (id) => {
  return new Promise((resolve, reject) => {
    if (personasCreadas[id] == undefined) {
      reject("No tiene instagram");
    } else {
      resolve(personasCreadas[id].instagram);
    }
  });
};

obtenerPersona(1).then((persona) => {
  console.log(persona);
  obtenerInstagram(10)
    .then((instagram) => {
      console.log(instagram);
    })
    .catch((err) => {
      console.log(err);
    })
    .catch((err) => {
      console.log(err);
    });
});

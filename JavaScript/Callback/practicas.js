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

// obtenerPersona(1).then((persona) => {
//   console.log(persona);
//   obtenerInstagram(10)
//     .then((instagram) => {
//       console.log(instagram);
//     })
//     .catch((err) => {
//       console.log(err);
//     })
//     .catch((err) => {
//       console.log(err);
//     });
// });

// obtenerPersona(1).then((persona) => {
//     console.log(persona);
//     return obtenerInstagram(10)
// }).then((instagram) => {
//     console.log(instagram);
// }).catch((err) => {
//     console.log(err);
// })

// const object = {
//     propiedad1: 'v1' ,
//     propiedad2: 'v2',
//     propiedad3: 'v3'
// }

// const obtenerInformacion = (text) => {
//     return new Promise((resolve, reject) => {
//         resolve(text)
//     })
// }

// async function getData() {
//   return Promise.resolve('data');
// }

// async function getAll() {
//   const data = await obtenerInformacion('0');
//   const data1 = await obtenerInformacion('1');
//   const data2 = await obtenerInformacion('2');
//   console.log(data);
//   console.log(data1);
//   console.log(data2);
// }

// getAll().then((all) => {
// //   console.log(all)
// })

const materiasHTML = document.querySelector(".materias");
const trigger = document.getElementById("trigger");
let materia;
const materias = [
  {
    nombre: "Fisica",
    nota: 7,
  },
  {
    nombre: "quimica",
    nota: 10,
  },
  {
    nombre: "Mate",
    nota: 5,
  },
  {
    nombre: "Calculo",
    nota: 9,
  },
  {
    nombre: "discretas",
    nota: 8,
  },
  {
    nombre: "Programacion",
    nota: 4,
  },
];

materias;

const obtenerMateria = (id) => {
  return new Promise((resolve, reject) => {
    materia = materias[id];
    if (materia == undefined) {
      reject("La materia no existe");
    } else {
      setTimeout(() => {
        resolve(materia);
      }, Math.random() * 400);
    }
  });
};

// obtenerMateria(1).then(res=>console.log(res))
// obtenerMateria(2).then(res=>console.log(res))
// obtenerMateria(3).then(res=>console.log(res))
// obtenerMateria(4).then(res=>console.log(res))
// obtenerMateria(5).then(res=>console.log(res))
// obtenerMateria(6).then(res => console.log(res)).catch((err) => console.log(err))

const escribirHola = () => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(
        (materiasHTML.innerHTML += `<h1 style="color:powderblue; padding:12px;"> Tu listado de materias es el siguiente</h1>`)
      );
    }, 1000);
  });
};

const devolverMaterias = async () => {
  trigger.disabled = true;
  trigger.remove();
  let materia = [];
  await escribirHola();
  for (let i = 0; i < materias.length; i++) {
    materia[i] = await obtenerMateria(i);
    let newHtmlCode = `<div class="materia">
        <div class="nombre">${materia[i].nombre}</div>
        <div class="nota">${materia[i].nota}</div>
      </div>`;
    materiasHTML.innerHTML += newHtmlCode;
  }
};

trigger.addEventListener("click", devolverMaterias);

let objeto = [
  {
    saludo: "hola",
    saludo2: "queonda",
  },
];
// console.log(typeof(JSON.stringify(objeto)));
const JSONserializado = '{saudo:"hola", saludo2:"adios"}';

const peticion = new XMLHttpRequest();
peticion.addEventListener("load", () => {
  if (peticion.readyState == 4 && peticion.status == 200) {
    let respuesta, objeto;
    respuesta = peticion.response;
    objeto = JSON.parse(respuesta);
    console.log(objeto.edad);
    // console.log(JSON.parse(respuesta).edad);
  } else {
    console.log("Error ");
  }
});

peticion.open("GET", "json.txt");
peticion.send();

// if (window.XMLHttpRequest) {
//   let peticion1 = new XMLHttpRequest
// } else {
//   let peticion1 = new ActiveXObject('Microsoft.XMLHTTP')
// }
const displayEmail = document.getElementById("display");
let dataJ;
peticionFetch = fetch("https://reqres.in/api/users?page=2");
let datas = [];
peticionFetch.then((res) => {
  res.text().then((res) => {
    dataJ = JSON.parse(res);
    for (const index in dataJ.data) {
      console.log(dataJ.data[index].email);
      datas.push(dataJ.data[index].email);
      displayEmail.innerHTML += `${dataJ.data[index].email} <br>`;
    }
  });
});

fetch("https://reqres.in/api/users")
  .then((res) => res.json())
  .then((res) => console.log(res));


axios.post("https://reqres.in/api/users", {
  "nombre": "Tony",
  "Apellido":"Ayala"
}).then(res => console.log(res))


const funcion = (a) => { console.log(a) }
function funcion2(a,b) {
   console.log(a+b);
}
console.log(funcion)
funcion(12)
funcion(10)

console.log(funcion2);
 

const myPromess = new Promise((resolve, reject) => {
   a = 1
   b=2
   if (a < b) {
      resolve ('Hola')
   } else { 
      reject ('adios')
   }
});

myPromess.then(res => { 
   console.log(res);
}).catch(e => { 
   console.log(e);
})

/* Implementación con promesas */
const doTask = (iterations) => new Promise((resolve, reject) => {
  const numbers = [];
  for (let i = 0; i < iterations; i++) {
    const number = 1 + Math.floor(Math.random() * 6);
    numbers.push(number);
    if (number === 6) {
      reject({
        error: true,
        message: "Se ha sacado un 6"
      });
    }
  }
  resolve({
    error: false,
    value: numbers
  });
});


doTask(10)
  .then((result) => console.log("Tiradas correctas: ", result))
  .catch((err) => console.error("Ha ocurrido algo: ", err.message));
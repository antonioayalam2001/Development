// // const helado = function (nombre) {
// //     let dinero = parseInt(prompt(`Ingresa la canfteidad de dinero e la persona ${nombre}`));
// //     console.log(typeof(dinero));
// //     if (typeof(dinero)===`number`) {
// //         console.log("Numero");
// //     }
// // }

// // helado ("Luis")

// let pc = {
//     nombre: "Tony",
//     procesador:"Intel",
//     ram: 16,
//     espacio: 1
// };

// console.log(pc); //{nombre: 'Tony', procesador: 'Intel', ram: 16, espacio: 1}
// console.log(typeof(pc)); //Objeto

// console.log(pc["nombre"]);
// console.log(typeof (pc["nombre"]));

// let frase= `<b>Hola a todos como estan</b><p>Debido a esto podemos</p>
// <b>Escribir en el html de esta forma</b><p>Usando las etiquetas desde javascript</p> ${pc["nombre"]}`

// document.write(frase);

// // let numero = parseInt(prompt("ingresa un numero"))
// // // while (numero > 0 ) {
// // //     console.log(numero);
// // //     document.write(`<br>${numero}`)
// // //     numero--
// // // }

// // do {
// //     console.log(numero);
// //     document.write(`<br>${numero}`)
    
// // } while (numero>10);

// // for (let index = 0; index < cantidad_de_veces; index++) {
        
// // }


// // let numeros = [1,2,3,4]
// // let numeros2 = [6,7,numeros]

// // for (i in numeros2)
// // {
// //     if (i == 2) {
// //         for (const y of numeros) {
// //             console.log(y);
// //         }
// //     } else {
// //         console.log(numeros2[i]);
// //     }
// //  }

// // ----------------------------------------- CICLOS Y BUCLES
// //     let cantidad = prompt("Cuandos alumnos son?")
// //     let alumnoTotales = [];
// //     for (let i = 0; i < cantidad; i++) {
// //         alumnoTotales[i] = [prompt("Nombre del alumno" + (i+1)), 0  ]
// //     }

// // const tomarAsistencia = (nombre, p) => {
// //     let presencia = prompt(nombre);
// //     if (presencia=="p"||presencia=="P") {
// //         alumnoTotales[p][1]++;
// //     }
// // }

// // for (i = 0; i < 4; i++){
// //     for (const alumno in alumnoTotales) {
// //         tomarAsistencia(alumnoTotales[alumno][0],alumno)
// //     }
// // }
// // for (const alumno in alumnoTotales) {
// //     let resultado = `${alumnoTotales[alumno][0]}:----------------------Asistencias: ${alumnoTotales[alumno][1]} <br> _______________ Ausencias: ${30 - alumnoTotales[alumno][1]}`;
// //     if (30 - alumnoTotales[alumno][1] > 18) {
// //         resultado += `Repreobado por inasistencia`
// //     } else {
// //     }
// //     document.write(resultado)
// // }

// // const suma = (num1,num2) => {
// //     return parseInt(num1+num2)
// // }
// // const multiplicacion = () => {
// //     return parseInt(num1*num2)
// // }
// // const division = () => {
// //     return parseInt(num1/num2)
// // }
// // const resta = () => {
// //     return parseInt(num1-num2)
// // }


// // do {
// //     alert(`Ingresa la opcion que desees:
// //     1:Suma
// //     2:Resta:
// //     3Multiplicacion:
// //     4Division`)
    
// // var opc=parseInt(prompt("Ingresa un numero"))
// // switch (opc) {
// //     case 1:
// //         let num1=parseInt(prompt("Ingresa el primer numero"))
// //         let num2=parseInt(prompt("Ingresa el segundo numero"))
// //         let resultado = suma(num1, num2)
// //         alert(parseInt(resultado));
// //         break;
// //         case 2:
// //         let num1=parseInt(prompt("Ingresa el primer numero"))
// //         let num2=parseInt(prompt("Ingresa el segundo numero"))
// //         let resultado = resta(num1, num2)
// //         alert(parseInt(resultado));
// //         break;
// //     case 3:
// //         let num1=parseInt(prompt("Ingresa el primer numero"))
// //         let num2=parseInt(prompt("Ingresa el segundo numero"))
// //         let resultado = multiplicacion(num1, num2)
// //         alert(parseInt(resultado));
// //         break;
// //     case 4:
// //         let num1=parseInt(prompt("Ingresa el primer numero"))
// //         let num2=parseInt(prompt("Ingresa el segundo numero"))
// //         let resultado = division(num1, num2)
// //         alert(parseInt(resultado));
// //         break;

// //     default:
// //         break;
// // }
// // } while (opc!=0);


// // class animal {
// //     constructor(especia, edad, color) {
// //         this.especia = especia;
// //         this.edad = edad;
// //         this.color = color;
// //     }
    
// //     verInformacion = () => {
// //         document.write(`Especia : ${this.especia}  Hola a todos la edad de este animal es: ${this.edad} <br>`)
// //     }
// // }

// // class perro extends animal {
// //     constructor(especia, edad,color,raza) {
// //         //Heredando atributos
// //         super(especia, edad, color)
// //         this.raza = raza;
// //     }
// //     set setRaza(nombre) {
// //         this.raza = nombre
// //     }

// //     get getRaza() {
// //         return this.raza
// //     }

// //     ladrar = () => {
// //         alert(`Wow aparte puede mostrar la raza ${this.raza}`)
// //     }

// //     static hola() {
// //         alert(`No necesito tener un objeto creado`)
// //     }
// // }

// // const perro2 = new perro("bulldog", 18, "azul", "doberman");
// //Usando el SET
// // perro2.setRaza = "El cambio se realiza de esta forma"
// //Usando el GET
// // alert(perro2.getRaza)
// // perro2.verInformacion()
// // perro2.ladrar()

// // perro.hola()


// // const perro1 = new animal("perro", 18, "white");
// // const pajaro= new animal("pajaro", 18, "black");
// // perro1.verInformacion()
// // pajaro.verInformacion()
// // // perro1.ladrar()

// // console.log(perro);
// // console.log(typeof(perro));
// // console.log(perro.color);


// class telefonoCelular{
//     constructor(color, peso, resolucion,ram,camara) {
//         this.color = color;
//         this.peso = peso;
//         this.resolucion = resolucion;
//         this.ram = ram;
//         this.camara = camara;
//         this.encendido = false;
//     }

//     muestraInfo() {
//         return (`<br>La informacion del telefono es: color ${this.color} <br> Peso ${this.peso} <br> Resolucion: ${this.resolucion} <br> ram: ${this.ram} <br> camara: ${this.camara}`)
//     }



//     prender() {
//         if (this.encendido == false) {
//             alert("Telefono prendiendo")
//             this.encendido = true;
//         } else {
//             alert("El telefono esta prendido")
//         }
//     }
    
//     apagar() {
//         if (this.encendido==true) {
//             var decision = prompt("Quieres apagarlo")
//             if (decision=="s") {
//                 alert("Apagando");
//                 this.encendido = false;
//             }
//         } else {
//             alert("El telefono no ha sido encendido")
//         }
//     }
    
//     reiniciar() {
//         if (this.encendido==true) {
//             let decision = prompt("Quieres reiniciar")
//             if (decision=="s") {
//                 alert("Reiniciando");
//                 this.encendido = false;
//                 this.prender();
//             }
//         } else {
//             alert("Telefono apagado")
//         }
//     }
    
//     tomarFoto() {
//         alert(`click con una resolucion de ${this.resolucion}`)
//     }
//     tomarVideo() {
//         alert(`Recording con una resolucion de ${this.resolucion}`)
//     }
// }

// class altagama extends telefonoCelular {
//     constructor(color, peso, resolucion,ram,camara,extracam) {
//         super(color, peso, resolucion, ram, camara)
//         this.extracam = extracam;
//         this.facial = false;
//     }

//     superLento() {
//         alert(`Grabando a velocidad super lenta con la camara extra ${this.extracam}`)
//     }

//     reconocimientoFacial() {
//         if (this.facial == false) {
//             let reconocimiento = prompt("Quieres activar el reconocimiento facial?")
//             if (reconocimiento == "s") {
//                 alert("Activando reconocimiento")
//                 this.facial = true;
//             } else {
//                 alert("Reconocimiento no activado")
//             }
//         } else {
//             alert("Ya lo habias activado")
//         }
//     }

//     infoAltaGama() {
//         return this.muestraInfo() + `<br> resolucion de la camara extra ${this.extracam}`
//     }
    
// }

// const cel1 = new telefonoCelular("blanco",12,1080,12,18);
// const cel2 = new telefonoCelular("negro",23,1080,6,10);
// const cel3 = new telefonoCelular("azul", 78, 1080,4,6);
// const cel4 = new altagama("rosa", 780, 1080,4,6,2048);

// document.write(`
// ${cel1.muestraInfo()}
// ${cel2.muestraInfo()}
// ${cel3.muestraInfo()}
// ${cel4.infoAltaGama()}
// `)
// // cel1.prender()
// // cel1.reiniciar()
// // cel1.prender()
// // cel1.apagar()
// // cel1.apagar()

// // cel2.apagar()

// // cel4.prender()
// // // cel4.reiniciar()
// // cel4.reconocimientoFacial();
// // cel4.reconocimientoFacial();
// // cel4.superLento();

// class app {
//     constructor(descargas, puntuacion, peso) {
//         this.descargas = descargas
//         this.puntuacion = puntuacion
//         this.peso = peso
//         this.iniciada = false;
//         this.instalada = false;
//     }

//     abrir() {
//         if (this.iniciada == false && this.instalada==true) {
//             alert("La aplicacion ha sido iniciada")
//             this.iniciada = true;
//         }
//     }
//     cerrar() {
//         if (this.iniciada == true) {
//             alert("La aplicacion  ya se cerro")
//             this.iniciada = false;
//         }
//     }
//     instalar() {
//         if (this.instalada == false) {
//             alert("La aplicacion  instalada")
//             this.instalada = true
//         }
//     }
//     desinstalar() {
//         if (this.instalada == true) {
//             alert("La aplicacion  se esta desinstalando")
//             this.instalada = false
//         }
//     }

//     muestraInfo() {
//         return (`<br> La aplicacion tiene la siguiente informacion ${this.descargas}<br> ${this.puntuacion}<br> ${this.peso}`)
//     }
// }

// // const aplicacion = new app(1256.12, 5, "12gb");
// // document.write(aplicacion.muestraInfo())
// // console.log(typeof(aplicacion.peso));
// // console.log(typeof (aplicacion.descargas));

// // aplicacion.instalar()
// // aplicacion.abrir()


// // let cadena = "                     Hola a todos"
// // let cadena2 = "Hola a todos            "
// // let resultado = cadena2.trimEnd()
// // // let resultado = cadena.padStart(24,"la")
// // document.write(resultado)

// // const str1 = '12';

// // console.log(str1.padStart("2", '0'));
// // // expected output: "05"

// // const fullNumber = '2034399002125581';
// // const last4Digits = fullNumber.slice(-4);
// // const maskedNumber = last4Digits.padStart(fullNumber.length, '*');

// // console.log(maskedNumber);
// // // expected output: "************5581"

// let nombres = ["Tony", "mom", "Ramon"]

// //Pop

// // console.log(nombres);
// // console.log(nombres.length);
// // let resultado = nombres.pop()
// // console.log(resultado);
// // console.log(resultado + "Hola a todos");
// // console.log(typeof(resultado));
// // console.log(resultado.length);

// //Shift
// // console.log(nombres);
// // console.log(nombres.length);
// // let resultado = nombres.shift()
// // console.log(resultado);
// // console.log(resultado + "Hola a todos");
// // console.log(typeof(resultado));
// // console.log(resultado.length);

// // nombres.push("Dad")
// // console.log(nombres);

// // console.log(nombres.unshift("Ayala","Mora","Martinez"))
// // console.log(nombres)

// // nombres.sort()
// // console.log(nombres);

// // console.log(nombres.splice(2, 2,"tony"));
// // console.log(nombres);

// // let resultado = nombres.filter()
// nombres.filter((numero) => {
//     if (numero=="Tony") {
//         alert("Enontre Tony")
//     } else {
//         document.write(numero + "<br>")
//     }
// }
// )
// // console.log(resultado);
// // document.write(resultado)

// // const materias = {
// //     fisica: ["Perez","pedro","pepito","cofla","maria"],
// //     programacion: ["Dalto","pedro","juan","pepito"],
// //     logica: ["Hernandez","pedro","juan","pepito","cofla","maria"],
// //     quimica: ["Rodriguez","pedro","juan","pepito","cofla","maria"]
// // }

// // console.log(materias["logica"][3]);

// // const obtenerInformacion = (materia)=>{
// //     console.log(materia);
// //     if (materias[materia] !== undefined) {
// //         console.log(materias[materia]);
// // 		return [materias[materia],materia,materias];
// // 	} else {
// //         return materias;
// // 	}
// // }
// // const mostrarInformacion = (materia)=>{
// //     let informacion = obtenerInformacion(materia);
    
// //     if (informacion !== false) {
// //         let profesor = informacion[0][0];
// //         alumnos = informacion[0];
// //         alumnos.shift();
// //         document.write(`El profesor de <b>${informacion[1]}</b> es: <b style="color:red">${profesor}</b><br>
// //         Los alumnos son: <b style="color:blue">${alumnos}</b><br><br>
// //         `);
// //     }
// // }

// // const cantidadDeClases = (alumno)=>{
// //     let informacion = obtenerInformacion();
// //     let clasesPresentes = [];
// //     let cantidadTotal = 0;
// //     for (info in informacion) {
// //             if (informacion[info].includes(alumno)) {
// //                 cantidadTotal++;
// //                 clasesPresentes.push(" "+ info);
// //             }
// //         }
// //         return `<b style='color:blue'>
// //         ${alumno}</b> está en <b>${cantidadTotal} clases: <b style='color:green'>${clasesPresentes}</b>
// //         <br><br>
// //         `;
// //     }
    
    
// //     mostrarInformacion("fisica");
// //     mostrarInformacion("quimica");
// //     mostrarInformacion("programacion");
// //     mostrarInformacion("logica");
    
// //     document.write(cantidadDeClases("cofla"))
// //     document.write(cantidadDeClases("pedro"))
    
    
    
// //     let informacion = obtenerInformacion("fisica")
// //     console.log(informacion);
// // console.log(materias["logica"][0]);
    


// const materias = {
// 	fisica: [90,6,3,"fisica"],
// 	matematica: [84,8,2,"matematica"],
// 	logica: [92,8,4,"logica"],
// 	quimica: [96,8,4,"quimica"],
// 	calculo: [91,6,3,"calculo"],
// 	programacion: [79,7,4,"programacion"],
// 	biologia: [75,9,2,"biologia"],
// 	bbdd: [98,9,1,"bbdd"],
// 	algebra: [100,10,4,"algebra"]
// }


// const aprobo = ()=>{
// 	for (materia in materias){
//         alert(materia)
// 		let asistencias = materias[materia][0];
// 		let promedio = materias[materia][1];
// 		let trabajos = materias[materia][2]

// 		console.log(materias[materia][3]);

// 		if (asistencias >= 90) {
// 			console.log("%c   Asistencias en orden","color:green");
// 		} else {
// 			console.log("%c   Falta de Asistencias","color:red");
// 		}

// 		if (promedio >= 7) {
// 			console.log("%c   Promedio en orden","color:green");
// 		} else {
// 			console.log("%c   Promedio desaprobado","color:red");
// 		}

// 		if (trabajos >= 3) {
// 			console.log("%c   Trabajos prácticos en Orden","color:green");
// 		} else {
// 			console.log("%c   Faltan trabajos prácticos","color:red");
// 		}
// 	}
// }

// aprobo()

const titulo = document.querySelector(".titulo");
// titulo.setAttribute("contentEditable", "true");
// titulo.setAttribute("hidden","true")
titulo.setAttribute("tabindex","3")

const input = document.querySelector(".input-normal")
const boton = document.querySelector(".boton")
function cambia() {
    titulo.classList.toggle("grande")
    // titulo.classList.replace("titulo","pequeño")
}



// document.write(input.value)
// input.minLength = "10";
// input.required = "true"

// titulo.classList.add("grande")
// let valor = titulo.classList.item(1)
// document.write(valor)
// let clase = prompt("Ingresa la clase    que quieres buscar")
// if (titulo.classList.contains(clase)) {
//     titulo.classList.remove(clase)
// } else {
//     titulo.classList.add(clase)
// }
const fragmento = document.createDocumentFragment()
const container = document.querySelector(".container")


for (i = 0; i < 10; i++)
{
    const item = document.createElement("LI")
    const textNode = document.createTextNode("Hola a todos")
    // document.write(textNode)
    item.appendChild(textNode)
    console.log(item);
    fragmento.appendChild(item)
}
 
container.appendChild(fragmento)
const childNodes = container.childNodes
console.log(childNodes);
const firstChild = container.firstElementChild;
console.log(firstChild);
firstChild.classList.add("titulo")


 
const parrafo = document.createElement("P");
const h2 = document.createElement("H2");
h2.innerHTML = "Titulo desde Javascript"
parrafo.innerHTML = "Creando un parrafo nuevo con javascript"
container.appendChild(h2)
container.appendChild(parrafo)
function alerta() {
    alert('hola desde el boton')
}

const boton1 = document.querySelector('.boton1');
window.addEventListener('select', () => {
    alert("Se cambio la resolución");
},true)
boton1.addEventListener('click', alerta)



input.addEventListener('select', (e) => {
    let start = e.target.selectionStart
    let end = e.target.selectionEnd
    let cadenaCompleta = e.target.value
    let seleccion = cadenaCompleta.substring(start, end)
    h2.textContent=seleccion
    parrafo.textContent=seleccion
    alert(seleccion)
})
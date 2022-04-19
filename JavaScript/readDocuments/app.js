// window.addEventListener("load",()=>{
//     document.getElementById("document").addEventListener('change',(e)=>{
//         let file = e.target.files[0];
//         if (file != null){
//             let reader = new FileReader();
//             reader.addEventListener('load',(e)=>{
//                 let content = e.target.result;
//                 console.log(content)
//             })
//             reader.readAsBinaryString(file)
//         }else{
//             console.log("No ingresaste archivo")
//         }
//     })
// })

let array = [1,2,3,4]
i=0;

while   (i < array.length){
    console.log(array[i])
    i++;
}
console.log("Reccoiendo con FOROF")

for (let number of array) {
    console.log(number)
}

console.log("Reccoiendo con FORIN")

for (let index in array) {
    console.log(array[index])
}

let person = {
    id:101,
    name:"Tony",
    lastName:'Mora'
}

let {id:propiedad1,name: nombrePersona} = person;

console.log(propiedad1)
console.log(nombrePersona)


//
// Object.keys(person).forEach(e=>{
//     console.log(e)
// })
//
// const {id} = person
// console.log(id)
//
// for (const idKey in person) {
//     console.log(idKey)
//     console.log(person[idKey])
// }
//
//


for (const index in array) {
    console.log(index)
}


console.log("Hola world desde }javascript on mac")
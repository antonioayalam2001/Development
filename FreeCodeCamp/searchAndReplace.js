'use strict'
// let regex = /[Hola]+/ig
// let sustituto = 'Hola'
// let cambio = 'Adios'
// let str = 'Hola a todo el mundo Hola'
// let array2 = str.split(' ').map(word=>{
//     if (word == sustituto){
//         return word = cambio
//     }else{
//         return word = word
//     }
// })
// console.log(array2.join(' '))
// str = str.replace('Hola','Adios')
// console.log(str)

function myReplace(str, before, after) {
    const regex = /[A-Z]/g
    regex.test(before.charAt(0)) ? after = after.charAt(0).toUpperCase() +after.substring(1) : after = after.charAt(0).toLowerCase() +after.substring(1)
    let array2 = str.split(' ').map(word=>{
        if (word.toLowerCase() == before.toLowerCase()){
            return word = after
        }else{
            return word = word
        }
    })
    console.log(array2.join(' '))
    return array2.join(' ');
}

myReplace("His name is Tom", "Tom", "john")
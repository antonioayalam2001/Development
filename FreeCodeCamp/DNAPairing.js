'use strict'
function pairElement(str) {
   let dictionary = {
       A : ['A','T'] ,
       T : ['T','A'],
       G : ['G','C'] ,
       C : ['C','G'] ,
   }
   let finalArray = []
    let array = str.split('')
    array.forEach(letter => {
        finalArray.push(dictionary[letter])
    })
    return finalArray;
}

pairElement("GCG");
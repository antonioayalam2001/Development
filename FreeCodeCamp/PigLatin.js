'use strict'
function translatePigLatin(str) {
    let regexVowel = /[aeiou]/
    if(regexVowel.test(str.charAt(0))){
        str+='way'
        return str
    }else{
        let counter = 0
        let limit = ''
        str = str.split('')
        while(!regexVowel.test(str[counter])){
            limit += str.shift()
        }
        console.log(str.join('').concat(limit+'ay'))
        return str.join('').concat(limit+'ay')

    }
}

translatePigLatin("schwartz");
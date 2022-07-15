'use strict'
let str = 'abce'
let dictionary = {
    a : 'a',
    b : 'b',
    c : 'c',
    d : 'd',
    e : 'e',
    f : 'f',
    g : 'g',
    h : 'h',
    i : 'i',
    j : 'j',
    k : 'k',
    l : 'l',
    m : 'm',
    n : 'n',
    o : 'o',
    p : 'p',
    q : 'q',
    r : 'r',
    s : 's',
    t : 't',
    u : 'u',
    v : 'v',
    w : 'w',
    x : 'x',
    y : 'y',
    z : 'z',
}
function fearNotLetter(str) {
    let counter
    let array = str.split('')
    // console.log(array)
    let index =(str.charCodeAt(0))
    let limit = str.charCodeAt(array.length-1)
    let letra = ''
    for (index, counter = 0; index<= limit  ; index++ , counter++){
        if (index != str.charCodeAt(counter)){
            letra = String.fromCharCode(index)
            // console.log(letra)
            return letra
        }

    }
return undefined

}

// fearNotLetter("");
console.log(fearNotLetter("abcdefghijklmnopqrstuvwxyz"))
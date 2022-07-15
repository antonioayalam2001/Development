'use strict'
function uniteUnique(arr) {
    let finalArg = [...arguments].flat().filter((item, ind, arr) => {
        // console.log(item)
        // console.log(ind)
        // console.log(arr)
        console.log(arr.indexOf(item))
        arr.indexOf(item) === ind
    });

    return finalArg;
}

uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]);
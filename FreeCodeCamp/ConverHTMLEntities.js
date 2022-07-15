'use strict'
function convertHTML(str) {
    let regex = /&|<|>|'|"/gi
    let dictionary = {
        '&': '&amp;',
        '<': '&lt;',
        '>': '&gt;',
        "\"" : '&quot;',
        "\'" : '&apos;'
    }

    let final = []
    str.split('').forEach(e=> {
        if (dictionary.hasOwnProperty(e)) e = dictionary[e]
        final.push(e)
    })
    return final.join('')

}

convertHTML("Dolce & Gabbana");
convertHTML("<>");
convertHTML("Stuff in \"quotation marks\"");
var elementos = document.getElementsByName("programa");
var pasatiempos = document.getElementsByName("red");
var info = document.getElementsByName("info");
var muestra = document.getElementsByClassName("info2")
var pas = document.getElementsByClassName("info3")
var titulo = document.getElementsByClassName("Titulo")
var datos = document.getElementsByClassName("persona")  
var curp = document.getElementById("curp");
let parrafo  = document.createElement('p')

function sijalo(){
    for (let i = 0; i < elementos.length ; i++) {
        if (elementos[i].checked) {
            muestra[i].innerHTML = elementos[i].value    
        }
        if (pasatiempos[i].checked) {
            pas[i].innerHTML = pasatiempos[i].value                 
        }
        if(i<2){
            titulo[i].style.display = "block"           
        }
    }
    titulo[2].style.display = "block"           
    
    datos[0].innerHTML = `Nombre: ${info[0].value}` 
    datos[3].innerHTML = `Curp: ${curp.value}`
    datos[1].innerHTML = `Apellido Paterno ${info[1].value }`
    datos[2].innerHTML = `Apellido Materno ${info[2].value}`
    datos[4].innerHTML = `Calle ${info[3].value}`
    datos[5].innerHTML = `Numero ${info[4].value}`
    datos[6].innerHTML = `Col ${info[5].value}`
    datos[7].innerHTML = `CP ${info[6].value}`
    datos[8].innerHTML = `Ciudad ${info[7].value}`
    datos[9].innerHTML = `Sexo ${info[8].value}`
    datos[10].innerHTML =` ${info[9].value}`
    
    
}



        

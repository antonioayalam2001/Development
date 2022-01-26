const sendButton = document.getElementById('button');
const displayRes = document.getElementById('resultado');
const modal = document.getElementById('modal');
const body = document.querySelector('body')

function abrirModal(resultado,mensaje) {
    modal.style.display= 'flex'
    modal.style.animation = 'popup 0.5s'
}

const verificarMen = (prevRes) => {
    let resultado;
    switch (prevRes) {
        case 1 :
            resultado = 'No puedes ser asi de pendejo'
            break;
        case 2:
            resultado = 'bien'
            break;
        case 3:
            resultado = 'casi'
            break;
        case 4:
            resultado = 'bueno'
            break;
        case 5:
            resultado = 'Rebrobado'
            break;
        case 6:
            resultado = 'panzaso'
            break;
        case 7:
            resultado = 'masomenos'
            break;
        case 8:
            resultado = 'bueno'
            break;
        case 9:
            resultado = 'bien'
            break;
        case 10:
            resultado = 'Excelente'
            break;
    
        default:
            resultado = null
            break;
        }
        return resultado
}

const verificarAprobacion = (nota1,nota2,prevRes) => {

    return Math.floor(((nota1+nota2+prevRes)/3))
}

sendButton.addEventListener('click', () => {
    let prevRes, mensaje,notas,nota1,nota2
    try {
        notas = document.querySelectorAll('#nota-alumno');
        console.log(notas);
        prevRes = parseInt(notas[0].value);
        nota1 = parseInt(notas[1].value);
        nota2 = parseInt(notas[2].value);

        if (isNaN(prevRes)) {
            throw 'Error no ingresaste un numero'
        }
        prevRes = verificarAprobacion(nota1,nota2,prevRes)
        mensaje = verificarMen(prevRes)
        if (prevRes<=5) {
            displayRes.innerHTML = `<b>Obtubista una calificacion de: ${prevRes} la cual fue reprobatoria y mereces este mensaje: ${mensaje}</b>`
            abrirModal(prevRes, mensaje)
            
        } else {
            displayRes.innerHTML = `<b>Felicidades obtubiste una calificacion de: ${prevRes} la cual fue aprobatoria y mereces este mensaje: ${mensaje}</b>`
            abrirModal(prevRes, mensaje)
        }

    } catch (error) {
        console.log(error);
    }

},true)


window.onclick = function(event) {
    if (event.target == modal) {
      modal.style.display = "none";
    }
  }
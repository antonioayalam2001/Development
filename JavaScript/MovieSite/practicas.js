const loader = document.querySelector('.loader');

// setTimeout(() => {
//     prompt('hola')
// }, 2);

// if ((loader.style.visibility == 'hidden')) {
//     alert('no oculto')
// }


setTimeout(() => {
    loader.style.visibility = "hidden";
    if (!(loader.style.visibility == "hidden")) {
        alert('adios');
    }
}, 5000);
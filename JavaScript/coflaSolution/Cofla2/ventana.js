alumnos = [
    {
    nombre:"Tony",
    email:"antonioayalam2001@gmail.com",
    materia:"Fisica"
    },
    {
    nombre:"Jorge",
    email:"antonioayalam2001@gmail.com",
    materia:"Quimica"
    },
    {
    nombre:"ramon",
    email:"antonioayalam2001@gmail.com",
    materia:"Algebra"
    },
    {
    nombre:"Lupita",
    email:"antonioayalam2001@gmail.com",
    materia:"Matematicas"
    },
    {
    nombre:"Erick",
    email:"antonioayalam2001@gmail.com",
    materia:"Fisica"
    },
    {
    nombre:"Sandy",
    email:"antonioayalam2001@gmail.com",
    materia:"Fisica"
    }
]

const gridContainer = document.querySelector('.grid_container');
const boton = document.querySelector('.btn_submit');

for (alumno in alumnos) {
    let datos = alumnos[alumno]
    let nombre = datos["nombre"]
    let email = datos["email"]
    let materia = datos["materia"]
    let htmlCode = `        <div class="grid_item nombre">${nombre}</div>
    <div class="grid_item email">${email}</div>
    <div class="grid_item materia">${materia}</div>
    <div class="grid_item semana">
        <select name="" id="" class="semana-elegida">
            <option value="Semana 1">Semana1</option>
            <option value="Semana 2">Semana2</option>
        </select>
    </div>`
    gridContainer.innerHTML += htmlCode

}

boton.addEventListener('click', () => {
    let confirmar = confirm('¿Quieres confirmar?')
    if (confirmar) {
        document.body.removeChild(boton)
        let elementos = document.querySelectorAll(".semana")
        let semanasElegidas = document.querySelectorAll(".semana-elegida");
        for (let elemento in elementos) {
            console.log(elementos[elemento]);
            semana = elementos[elemento]
            semana.innerHTML = semanasElegidas[elemento].value
        }
    }
})
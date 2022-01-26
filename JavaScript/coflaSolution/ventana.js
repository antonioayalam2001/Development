const studentName = document.getElementById('name');
const mail = document.getElementById('mail');
const btnSubmit = document.getElementById('btn-submit');
const result = document.querySelector('.resultado');
 const materias = ["Algebra", "Fisica", "Quimica"]

function capitalizeFirst(str) {
    return str.charAt(0).toUpperCase()+ str.slice(1)
}


const validData = (str) => {
    let error = [];
    if (studentName.value.length < 5 ) {
        error[0] = true
        error[1]= 'El nombre no puede ser menor a 5'
        return error;
    } else if(studentName.value.length > 40){
        error[0] = true
        error[1]= `El nombre no puede tener mas de 40`
        return error;
    } else if (mail.value.length < 10 || mail.value.length > 40 ||
        (mail.value.indexOf('@') == -1) ||
        (mail.value.indexOf('.') == -1) 
        ) {
        error[0] = true
        error[1]= `El mail no es correcto`
        return error;
    } else if (str != 'Fisica' ) {
        error[0] = true
        error[1]= `No escribiste una materia valida`
        return error;   
    }
    else {
        error[0] = false
        console.log('Todo chevere');
        return error
    }
}


btnSubmit.addEventListener('click', (e) => {
    e.preventDefault()
    var subject = document.getElementById('subject').value 
    subject = capitalizeFirst(subject)
    let error = validData(subject)
    if (error[0]) {
        result.classList.add('red')
        result.innerHTML = error[1]
    } else {
        result.classList.remove('red')
        result.classList.add('green')
        result.innerHTML = 'Solicitud enviada correctamente'
        
    }
    
})
var elementos = document.getElementsByName("pregunta");
 
for(var i=0; i<elementos.length; i++) {
  console.log(" Elemento: " + elementos[i].value + "\n Seleccionado: " + elementos[i].checked);
}

<input type="checkbox" value="condiciones" name="condiciones" id="condiciones"/> He leído y acepto las condiciones
<input type="checkbox" value="privacidad" name="privacidad" id="privacidad"/> He leído la política de privacidad


var elemento = document.getElementById("condiciones");
console.log(" Elemento: " + elemento.value + "\n Seleccionado: " + elemento.checked);
 
elemento = document.getElementById("privacidad");
console.log(" Elemento: " + elemento.value + "\n Seleccionado: " + elemento.checked);


<select id="opciones" name="opciones">
  <option value="1">Primer valor</option>
  <option value="2">Segundo valor</option>
  <option value="3">Tercer valor</option>
  <option value="4">Cuarto valor</option>
</select>


// Obtener la referencia a la lista
var lista = document.getElementById("opciones");
 
// Obtener el índice de la opción que se ha seleccionado
var indiceSeleccionado = lista.selectedIndex;
// Con el índice y el array "options", obtener la opción seleccionada
var opcionSeleccionada = lista.options[indiceSeleccionado];
 
// Obtener el valor y el texto de la opción seleccionada
var textoSeleccionado = opcionSeleccionada.text;
var valorSeleccionado = opcionSeleccionada.value;
 
console.log("Opción seleccionada: " + textoSeleccionado + "\n Valor de la opción: " + valorSeleccionado);





var lista = document.getElementById("opciones");
 
// Obtener el valor de la opción seleccionada
var valorSeleccionado = lista.options[lista.selectedIndex].value;
 
// Obtener el texto que muestra la opción seleccionada
var valorSeleccionado = lista.options[lista.selectedIndex].text;


document.getElementById("primero").focus();
<form id="formulario" action="#">
  <input type="text" id="primero" />
</form>





if(document.forms.length > 0) {
    if(document.forms[0].elements.length > 0) {
      document.forms[0].elements[0].focus();
    }
  }

  




if(document.forms.length > 0) {
for(var i=0; i < document.forms[0].elements.length; i++) {
    var campo = document.forms[0].elements[i];
    if(campo.type != "hidden") {
    campo.focus();
    break;
    }
}
}
  





<form id="formulario" action="#">
  ...
  <input type="button" value="Enviar" onclick="this.disabled=true; this.value=’Enviando...’; this.form.submit()" />
</form>





function limita(maximoCaracteres) {
    var elemento = document.getElementById("texto");
    if(elemento.value.length >= maximoCaracteres ) {
      return false;
    }
    else {
      return true;
    }
  }
  <textarea id="texto" onkeypress="return limita(100);"></textarea>

  






  function permite(elEvento, permitidos) {
    // Variables que definen los caracteres permitidos
    var numeros = "0123456789";
    var caracteres = " abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    var numeros_caracteres = numeros + caracteres;
    var teclas_especiales = [8, 37, 39, 46];
    // 8 = BackSpace, 46 = Supr, 37 = flecha izquierda, 39 = flecha derecha
   
    // Seleccionar los caracteres a partir del parámetro de la función
    switch(permitidos) {
      case 'num':
        permitidos = numeros;
        break;
      case 'car':
        permitidos = caracteres;
        break;
      case 'num_car':
        permitidos = numeros_caracteres;
        break;
    }
   
    // Obtener la tecla pulsada
    var evento = elEvento || window.event;
    var codigoCaracter = evento.charCode || evento.keyCode;
    var caracter = String.fromCharCode(codigoCaracter);
   
    // Comprobar si la tecla pulsada es alguna de las teclas especiales
    // (teclas de borrado y flechas horizontales)
    var tecla_especial = false;
    for(var i in teclas_especiales) {
      if(codigoCaracter == teclas_especiales[i]) {
        tecla_especial = true;
        break;
      }
    }
   
    // Comprobar si la tecla pulsada se encuentra en los caracteres permitidos
    // o si es una tecla especial
    return permitidos.indexOf(caracter) != -1 || tecla_especial;
  }




function validacion() {
    if (condicion que debe cumplir el primer campo del formulario) {
      // Si no se cumple la condicion...
      console.log('[ERROR] El campo debe tener un valor de...');
      return false;
    }
    else if (condicion que debe cumplir el segundo campo del formulario) {
      // Si no se cumple la condicion...
      console.log('[ERROR] El campo debe tener un valor de...');
      return false;
    }else if (condicion que debe cumplir el último campo del formulario) {
      // Si no se cumple la condicion...
      console.log('[ERROR] El campo debe tener un valor de...');
      return false;
    }
   
    // Si el script ha llegado a este punto, todas las condiciones
    // se han cumplido, por lo que se devuelve el valor true
    return true;
  }

  




  valor = document.getElementById("campo").value;
  if( valor == null || valor.length == 0 || /^\s+$/.test(valor) ) {
    return false;
  }

  


  valor = document.getElementById("campo").value;
if( isNaN(valor) ) {
  return false;
}



isNaN(3);          // false
isNaN("3");        // false
isNaN(3.3545);     // false
isNaN(32323.345);  // false
isNaN(+23.2);      // false
isNaN("-23.2");    // false
isNaN("23a");      // true
isNaN("23.43.54"); // true




indice = document.getElementById("opciones").selectedIndex;
if( indice == null || indice == 0 ) {
  return false;
}
<select id="opciones" name="opciones">
  <option value="">- Selecciona un valor -</option>
  <option value="1">Primer valor</option>
  <option value="2">Segundo valor</option>
  <option value="3">Tercer valor</option>
</select>



valor = document.getElementById("campo").value;
if( !(/\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)/.test(valor)) ) {
  return false;
}




var ano = document.getElementById("ano").value;
var mes = document.getElementById("mes").value;
var dia = document.getElementById("dia").value;
 
valor = new Date(ano, mes, dia);
 
if( !isNaN(valor) ) {
  return false;
}




valor = document.getElementById("campo").value;
var letras = ['T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E', 'T'];
 
if( !(/^\d{8}[A-Z]$/.test(valor)) ) {
  return false;
}
 
if(valor.charAt(8) != letras[(valor.substring(0, 8))%23]) {
  return false;
}



opciones = document.getElementsByName("opciones");
 
var seleccionado = false;
for(var i=0; i<opciones.length; i++) {
  if(opciones[i].checked) {
    seleccionado = true;
    break;
  }
}
 
if(!seleccionado) {
  return false;
}

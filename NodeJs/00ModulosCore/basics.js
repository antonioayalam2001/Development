// Organizacion del codigo de JavaScrips
/*
* Librerias / Modulos
* constantes
* objetos/variables
* funciones
* eventos
* ejecuciones
*
Usar camelCase
	Cuando una instrucción tenga una sola palabra, va en minúsculas p.e. require()
	Sólo las clases rompen esta regla, siempre va en mayúscula la letra inicial p.e. EventEmmiter()
	Cuando una instrucción tenga 2 o más palabras, apartir de la segunada la primer letra va en mayúscula p.e. createServer()
	Tipos de CamelCase
		UpperCamelCase
			Date()
			EventEmmiter()
		lowerCamelCase
			getElementById()
			createServer()
*/
'use strict'
console.log('Hola Mundo desde NodeJS esto se vera en la terminal de comandos')
console.log(2+2)
setInterval(function () {
    console.log('Hola a todos')
},1000)
// let x=5;
// let y=9;
// alert(x);
// alert(y);
// alert(x+y);


// function suma(){
//     var res=x+y;
//     alert ("Suma:" + res);
//     let w;
//     w=parseInt(prompt("Ingresa el resultado: " + res));
//     alert(w);
// }

// suma();

// function factorial
function factorial(x){
    let total=1;
    for (let i = 1; i <=x; i++) {
        total=total*i;        
    }
    alert(`El valor del factorial del numero ${x} es: ${total}`);
}


function Elevar(c,d){
    alert(`Los numeros son: ${c} y se va a elevar a una potencia de: ${d} `);
    let s = Math.pow(c,d);
    alert(`El valor de la potencia es: ${s}`);
}

Elevar(2,4);
factorial(5);
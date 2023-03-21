//HMTL References
const label = document.querySelector("#lblNuevoTicket");
const buttonCreate = document.querySelector(".btn");
const garnacha = document.querySelector("#garnacha");


const socket = io();


socket.on('connect', () => {
      // console.log('Conectado');
      buttonCreate.disabled = false;
      // lblOnline.style.display  = '';

});

socket.on('disconnect', () => {
      // console.log('Desconectado del servidor');
      buttonCreate.disabled = true;

});


socket.on('last-ticket', (payload) => {
      label.innerHTML = payload;
})


buttonCreate.addEventListener( 'click', () => {
      if (garnacha.value === ''){
            return garnacha.focus()
      }
      Swal.fire({
            title: `Estas apunto de pedir :  ${garnacha.value}`,
            text: "Una evz confirmado tu pedido será puesto en cola",
            icon: 'warning',
            showCancelButton: true,
            confirmButtonColor: '#3085d6',
            cancelButtonColor: '#d33',
            confirmButtonText: 'Hacer pedido',
            cancelButtonText : "Aguanta"
      }).then((result) => {
            if (result.isConfirmed) {
                  socket.emit( 'next-ticket', null, ( ticket ) => {
                        label.innerHTML = ticket;
                        console.log('Desde el server', ticket );
                  });
                  window.location = '/'
            }
      })

});


// const buttonSend = document.querySelector("#sendData");
// buttonSend.addEventListener('click',async (evt) => {
//       evt.preventDefault()
//       console.log(garnacha.value)
//       await fetch('/home',{
//             headers: {
//                   'Content-Type': 'application/json'
//             },
//             method: "POST",
//             body: JSON.stringify({
//                   garnacha : garnacha.value,
//             })
//       })
//           .then(function(res){ console.log(res) })
//           .catch(function(res){ console.log(res) })
// })

// console.log('Nuevo Ticket HTML');
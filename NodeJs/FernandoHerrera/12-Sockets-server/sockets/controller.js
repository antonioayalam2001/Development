const socketController = (socket) => {
            //socket.id -> Unique identifier from the socket, changes every time that you realize a connection
            console.log("socket connected" , socket.id);
            socket.on('disconnect', () => {
                  console.log("Client is gone" , socket.id);
            } )

            socket.on('send-message',(payload,callback)=>{
                  // console.log(payload);
                  const id = 1234
                  callback({id , date : new Date().getTime()});

                  //Just sending the message to the socket who make the send-message event
                  // socket.emit('send-message',payload)
                  //Send to multiple users except the socket self
                  socket.broadcast.emit('send-message',payload)
            })
}

module.exports = {
      socketController
}
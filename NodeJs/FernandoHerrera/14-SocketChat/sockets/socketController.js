const {Socket: socket} = require('socket.io')

const socketController = socket => {
      console.log("Cliente conectado", socket.id);
}

module.exports = socketController
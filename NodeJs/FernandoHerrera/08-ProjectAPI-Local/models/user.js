//Template
/*
{
    nombre : "",
    correo : "",
    password : "" ,
    img : "",
    role : "",
    estado : true -> alta , false-> Dado de baja,
    google :true -> Creado por google, false | Creado por sistema de identificacion propio
}
*/

const {Schema, model} = require('mongoose')

const usuarioSchema = Schema({
      nombre: {
            type: String,
            required: [true, 'Name must be provided']
      },
      email: {
            type: String,
            required: [true, 'email must be provided'],
            unique: true
      },
      password: {
            type: String,
            required: [true, 'password must be provided']
      },
      img: {
            type: String,
      },
      role: {
            type: String,
            required: true,
            // enum: ['ADMIN_ROLE', 'USER_ROLE','VENTAS_ROLE']
      },
      state: {
            type: Boolean,
            default: true
      },
      google: {
            type: Boolean,
            default: false
      }
});

//Sobreescribiendo metodo directamente del esquema
// para que al momento de retornar nos devuelva solo las propiedades
usuarioSchema.methods.toJSON = function (){
      const {__v,password, ...usuario} =  this.toObject();
      return usuario
}

//Mongoose agrega una s al final de nuestra String
module.exports = model('Usuario', usuarioSchema);
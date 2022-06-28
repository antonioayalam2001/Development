const express = require('express');
const router = express.Router();

router.get('/',(req,res)=>{
    var characters = [
        {
            name: 'Harry',
            designation: "Student"
        },
        {
            name: 'Dumbledore',
            designation: "Headmaster"
        },
        {
            name: 'Snape',
            designation: "Professor"
        },
        {
            name: 'Hermione',
            designation: "Student"
        }
    ];
    res.render('pageEjs',{title:"Titulo de la pagina",char:characters})
})

module.exports = router
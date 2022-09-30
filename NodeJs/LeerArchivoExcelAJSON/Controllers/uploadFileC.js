const excelToJson = require ( 'convert-excel-to-json' );
const { request : req , response : res } = require ( 'express' );
const fs = require('fs');
const home = ( req , res ) => {
      res.render ( 'index' )
}

const uploadFile = ( req , res ) => {
      const excelData = excelToJson ( {
            sourceFile : req.file.path ,
            header : {
                  rows : 1
            } ,
            columnToKey : {
                  A: 'Name' ,
                  B : 'SEPT' ,
                  C : 'OCT' ,
                  D : 'NOV',
                  E : 'DIC'
            }
      } )
      fs.rm(req.file.path , (err)=> {
            if ( ! err ) console.log ('No hubo error')
      });

      res.status ( 200 ).json ( excelData );
}


module.exports = {
      home ,
      uploadFile
}
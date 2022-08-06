const {request: req, response: res} = require('express');
const {uploadFiles} = require("../helpers");


const uploadFile = async (req, res) => {
      if (!req.files || Object.keys(req.files).length === 0) {
            return res.status(400).send('No files were uploaded.');
      }
      //@uploadFiles
      /*
      * @param : files : Files uploaded by te user
      * @param : array [] : Supported file type extensions
      * @param : string : Name of the folder to storage the file
      *
      * */

      const extensions = ["txt",'img'];
      try {
            //undefined if we want to keep the original one that we established in the function
            const fileName = await uploadFiles(req.files, undefined,'imgs')
            res.json({fileName})
      } catch (e) {
            res.json({e})
      }
}

const updateImg = async (req,res) => {
      const {collection , id} = req.params;
      res.json({collection,id})
}

const uploadMultipleFiles = (req, res) => {
      let uploadPath;
      if (!req.files || Object.keys(req.files).length === 0) {
            return res.status(400).send('No files were uploaded.');
      }
      const array = []
      for (let file in req.files) {
            array.push(req.files[file])
      }
      // The name of the input field (i.e. "sampleFile") is used to retrieve the uploaded file
      // Use the mv() method to place the file somewhere on your ser ver
      array.forEach(file => {
            uploadPath = path.join(__dirname, "../uploads/", file.name);
            file.mv(uploadPath, function (err) {
                  if (err)
                        return res.status(500).send(err);
            });
      })
      res.status(200).json({
            msg: 'Exito'
      })
}

module.exports = {
      uploadFile,
      updateImg
}
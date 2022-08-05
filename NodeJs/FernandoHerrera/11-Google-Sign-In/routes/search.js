const {Router} = require('express')
const{search} = require('../controllers')

const router = Router();
// searchPath: 'api/search'
//Usually is a get
router.get('/:collection/:search',search)






module.exports = router

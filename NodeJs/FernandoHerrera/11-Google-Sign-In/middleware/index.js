
const validateField = require("../middleware/validate_fields");
const validateJWT = require("../middleware/validateJWT");
const validateRoles = require("../middleware/validateRoles");
const validateCollections = require("../middleware/validateCollection");

module.exports = {
      ...validateCollections,
      ...validateField,
      ...validateJWT,
      ...validateRoles
}
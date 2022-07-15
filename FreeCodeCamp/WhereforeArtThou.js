'use strict'
function whatIsInAName(collection, source) {
    let arr = [];
    // Only change code below this line
    let sourceKey = Object.keys(source)
    console.log(sourceKey)
    arr = collection.filter(e=> sourceKey.every(prop => {return e.hasOwnProperty(prop) && e[prop]===source[prop]}))
    console.log(arr)
    // Only change code above this line
    return arr;
}
whatIsInAName([{ first: "Romeo", last: "Montague" }, { first: "Mercutio", last: null }, { first: "Tybalt", last: "Capulet" }], { last: "Capulet" });


let users = {
  Alan: {
    age: 27,
    online: false
  },
  Jeff: {
    age: 32,
    online: true
  },
  Sarah: {
    age: 48,
    online: false
  },
  Ryan: {
    age: 19,
    online: true
  }
};

function getArrayOfUsers(obj) {
  // Only change code below this line

  return Object.keys(obj)
  // Only change code above this line
}
for (const objKey in users) {
    console.log(users[objKey])
    console.log(Object.keys(users[objKey]))

}

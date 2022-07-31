Forma de crear una URL
// (A) DATA TO SEND
var data = {
      name : "jon doe",
      email : "jon@doe.com"
};

// (B) BUILD URL
var url = new URL("http://localhost:3000/api/auth/google");
for (let k in data) {
      url.searchParams.append(k, data[k]);
}
console.log(url);

function handleCredentialResponse(response) {
      // decodeJwtResponse() is a custom function defined by you
      // to decode the credential response.
      const responsePayload = decodeJwtResponse(response.credential);

      console.log("ID: " + responsePayload.sub);
      console.log('Full Name: ' + responsePayload.name);
      console.log('Given Name: ' + responsePayload.given_name);
      console.log('Family Name: ' + responsePayload.family_name);
      console.log("Image URL: " + responsePayload.picture);
      console.log("Email: " + responsePayload.email);
      console.log(response.credential)

      const payload = {
            id_token : response.credential
      }

      fetch(url,
          {
                headers: {
                      "Content-Type": "application/x-www-form-urlencoded",
                      //       'Accept': 'application/json',
                      // 'Content-Type': 'application/json'
                },
                method: "POST",
                body: new URLSearchParams({
                      cuerpo : "Hola",
                      mandandoParametro : true
                })
          })
          .then(function(res){ console.log(res) })
          .catch(function(res){ console.log(res) })

}

function decodeJwtResponse (token) {
      var base64Url = token.split('.')[1];
      var base64 = base64Url.replace('-', '+').replace('_', '/');
      return JSON.parse(window.atob(base64));
}
console.log(location);
console.log(location.origin);
console.log(location.protocol);
console.log(location.host);
console.log(location.hostname);
console.log(location.port);
console.log(location.href);
console.log(location.hash);
console.log(location.search);
console.log(location.pathname);


const options = {
	method: 'GET',
	headers: {
		'X-RapidAPI-Key': 'd91bda661emsh33c1da8ab8b313dp1e4f67jsn6c933af012cc',
		'X-RapidAPI-Host': 'call-of-duty-modern-warfare.p.rapidapi.com'
	}
};

fetch('https://call-of-duty-modern-warfare.p.rapidapi.com/warzone-matches/Amartin743/psn', options)
	.then(response => response.json())
	.then(response => console.log(response))
	.catch(err => console.error(err));
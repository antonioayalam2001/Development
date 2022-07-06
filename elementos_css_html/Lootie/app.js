// import lottieWeb from 'https://cdn.skypack.dev/lottie-web';
const container = document.querySelector('.container')
var animation = bodymovin.loadAnimation({
    // animationData: { /* ... */ },
    container: document.querySelector('.container'), // required
    path: 'lemonade.json', // required
    renderer: 'svg', // required
    loop: false, // optional
    autoplay: true, // optional
    name: "Demo Animation", // optional
});

var animation2 = bodymovin.loadAnimation({
    // animationData: { /* ... */ },
    container: document.querySelector('.container2'), // required
    path: 'letra.json', // required
    renderer: 'svg', // required
    loop: false, // optional
    autoplay: true, // optional
    name: "Demo Animation", // optional
});
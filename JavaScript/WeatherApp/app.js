const API_KEY = 'e70d97b6338a49e72ba487984a0cb8db';
icon = document.getElementsByClassName('icon')[0]
imagen = document.getElementById('img')
body = document.getElementsByTagName('body')[0]
contenedor = document.querySelector('.container')
console.log(body)
console.log(icon)
const getDate = () => {
    let date = new Date();
    return `${date.toString("DD MM yy").slice(0, 10)}`
}

document.addEventListener('scroll', () => {

    console.log(contenedor.getBoundingClientRect())
})


const setWeatherData = (data) => {
    const weatherData = {
        location: data.name,
        description: data.weather[0].description,
        humidity: data.main.humidity,
        pressure: data.main.pressure,
        temp: data.main.temp,
        temp_max: data.main.temp_max,
        temp_min: data.main.temp_min,
        date: getDate(),
    }
    // let descriptcion = data.weather[0].description
    switch (weatherData.description) {
        case 'clear sky':
            imagen.src = 'icon/cloud.svg'
            body.style.background = ' linear-gradient(0deg, rgba(255,255,255,1) 34%, rgba(119,242,255,1) 100%)'
            animarLogo(weatherData.description)
            break

        case 'overcast clouds':
            imagen.src = 'icon/cloud.svg'
            body.style.background = 'linear-gradient(0deg, rgba(255,255,255,1) 34%, rgba(125,125,125,1) 100%)'
            animarLogo(weatherData.description)
            break

        case 'broken clouds':
            imagen.src = 'icon/sun.png'
            body.style.background = 'linear-gradient(0deg, rgba(255,255,255,1) 34%, rgba(255,237,0,1) 100%)'
            animarLogo(weatherData.description)
            break
    }

    Object.keys(weatherData).forEach(key => {
        document.getElementById(`${key}`).innerText += weatherData[key]
    })
}

const petitionFetch = (position) => {
    const {latitude, longitude} = position.coords
    fetch(`http://api.openweathermap.org/data/2.5/weather?units=metric&lat=${latitude}&lon=${longitude}&appid=${API_KEY}`)
        .then(response => {
            return response.json()
        })
        .then(data => {
            console.log(data)
            setWeatherData(data);
        })


}

window.addEventListener('load', () => {
    navigator.geolocation.getCurrentPosition(petitionFetch)
})


function animarLogo(description) {
    switch (description) {
        case 'clear sky':
            icon.animate([
                // keyframes
                {transform: 'translate(-50px)'},
                {transform: 'rotate(50px)'}
            ], {
                // timing options
                duration: 1000,
                iterations: Infinity,
                direction: "alternate"
            })
            break

        case 'overcast clouds':
            icon.animate([
                // keyframes
                {transform: 'translate(-50px)'},
                {transform: 'rotate(50px)'}
            ], {
                // timing options
                duration: 1000,
                iterations: Infinity,
                direction: "alternate"
            })
            break
        case 'sunny':
            icon.animate([
                // keyframes
                {transform: 'rotate(0deg)'},
                {transform: 'rotate(-360deg)'}
            ], {
                // timing options
                duration: 5000,
                iterations: Infinity,
                // direction:"alternate"
            })
            icon.style.filter = 'invert(100%) sepia(100%) saturate(7500%) hue-rotate(354deg) brightness(107%) contrast(106%)'
            break

    }

}

trigger = document.getElementById('trigger');
getter = document.getElementById('getter')
trigger.addEventListener('click', () => {
    var user = {
        username: 'Tony',
        edad: 18,
        correo: 'antonioayalam2001@gmail.com'
    }
    var user2 = {
        username: 'Carlos',
        edad: 18,
        correo: 'antonioayalam2001@gmail.com'
    }

    var json = JSON.stringify(user)
    localStorage.setItem(user.username, json)
    console.log('used added')
    var json = JSON.stringify(user2)
    localStorage.setItem(user2.username, json)
    console.log('used added')

})

getter.addEventListener('click', () => {
    localStorage.clear()
})
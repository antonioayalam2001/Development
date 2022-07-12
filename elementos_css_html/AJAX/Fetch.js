(()=>{

    let fetchDOM = document.getElementById('fetch')
    let fragment = document.createDocumentFragment()



    //FORMA SIN ASYNC AWAIT

    fetch('https://gateway.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=50').then(res=>{
        // console.log(res)
        return res.json()
    })
        .then(data=>{
            data = data.data.results
            data.forEach(element =>{
                // console.log(element)
                const li = document.createElement('li')
                li.innerHTML = `${element.id} ------> ${element.name}`
                fragment.appendChild(li)
            })
            fetchDOM.appendChild(fragment)
    })
        .catch(error=>{
        console.log('Oops not the llama u were looking for')
    })
        .finally(()=>{
        console.log('Me ejecuto de todos modos soy FINALYY')
    })

})()

async function getData () {
    try{
        let res = await fetch('https://gateway.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=50')
        //Link para poder probaar los errores
        // let res = await fetch('https://gatewa.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=50')
        console.log(res)
        // if (!res.ok) throw new Error('Sorry not the llama you were looking for')
        if (!res.ok) throw {status : res.status, statusText : res.statusText}
        let content = await res.json()

        return content.data.results
    }catch (error){
        error.statusText = "Chanclas hubo un error"
        console.log('estoy en Catch con el error de : ', error.statusText)
    }finally {
        console.log('Finally del async Await')
    }
}

getData().then(content=>{
    console.log(content)
})



// URL : https://gateway.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=50`
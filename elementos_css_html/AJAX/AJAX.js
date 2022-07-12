(()=>{

const ajax = new XMLHttpRequest()
let ajaxDOM = document.getElementById('ajax')
let fragment = document.createDocumentFragment()

ajax.addEventListener('readystatechange',(e)=>{
    if (ajax.readyState !== 4) return
    // console.log(ajax)
    if (ajax.status >= 200 && ajax.status< 300){
        console.log('Exito')
        let data = JSON.parse(ajax.responseText)
        // console.log(data)
        data = data.data.results

        // data.forEach(element =>{
        //     // console.log(element)
        //     const li = document.createElement('li')
        //     li.innerHTML = `${element.id} ------> ${element.name}`
        //     fragment.appendChild(li)
        // })

        ajaxDOM.appendChild(fragment)

    }else{
        console.log('Error')
    }
})

ajax.open('GET','https://gateway.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=50')
ajax.send()

})()
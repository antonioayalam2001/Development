let axiosContainer = document.getElementById('axios')
let offset = 0
const w = window
axios.get('https://gateway.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=50').then((res)=>{
    let data = res.data.data.results
    // console.log(data)
})

let fragment = document.createDocumentFragment()

let getAxiosData  = async (offset)=>{

    try{
        let dataAsync =await axios.get(`https://gateway.marvel.com:443/v1/public/characters?ts=1&apikey=55bfb1504f1efc62d3523b2cdf3e5129&hash=e7ac7b03a621d6a4cd19a872d2fd9e47&limit=${40}&offset=${offset}`)
        let content = await dataAsync.data.data.results
        return content
    }catch (error){
        console.log('Axios Error')
    }finally {
        console.log('Finally Axios')
    }
}
function createContent(res){
    res.forEach(element =>{
        // console.log(element)
        const div = document.createElement('div')
        const figure = document.createElement('figure')
        const img = document.createElement('img')
        const p = document.createElement('p')
        div.classList.add('card')
        p.innerHTML = `${element.name}`
        img.setAttribute('src',`${element.thumbnail.path}.jpg`)
        figure.appendChild(img)
        figure.appendChild(p)
        div.appendChild(figure)
        fragment.appendChild(div)
    })
    axiosContainer.appendChild(fragment)
}
getAxiosData(0).then(res=>{
    createContent(res)
})

document.addEventListener('keyup',ev=>{
    if (ev.target.matches('#buscador')){
        document.querySelectorAll('.card').forEach(card=>{
            let cardContent = card.textContent.toLowerCase();
            let inputContent = ev.target.value.toLowerCase();
            cardContent.includes(inputContent) ? card.classList.remove('filtro') : card.classList.add('filtro')
        })
    }
})

w.addEventListener('scroll',ev=>{
    const {scrollTop, clientHeight, scrollHeight} = document.documentElement
    // console.log(document.documentElement)
    // console.log(scrollTop)
    // console.log(clientHeight)
    // console.log(scrollHeight)
    scrollTop+clientHeight == scrollHeight ? getAxiosData(offset+=40).then(res=>createContent(res)) : console.log('Hola')

})
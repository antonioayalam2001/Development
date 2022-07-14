const d = document;
const w = window;
const button = d.querySelector('.btn')
const container = d.querySelector('.container')
const nav = d.querySelector('.links')
const getData = async (link) => {
    container.innerHTML = '<img src="ball-triangle.svg">'
    try {
        let res = await fetch(link)
        let json = await res.json()
        return json
    } catch (error) {
        console.log(error)
    }
}

async function fullDOM(data) {
    console.log(data)
    let prevLink = ''
    let nextLink = ''
    let template = ''
    for (let i = 0; i < data.results.length; i++) {
        let habStr = ''
        try {
            let pokemonResponse = await fetch(data.results[i].url)
            let pokemon = await pokemonResponse.json()
            console.log(pokemon)
            pokemon.abilities.forEach(hab=>{
                habStr += `<p>${hab.ability.name}</p>`
            })
            template += `
            <section class="card">
            <figure class="imgBox">
                <img alt="" src=${pokemon.sprites.front_default}>
            </figure>
            <div class="info_container">
                <article class="info">
                    <h1>${pokemon.name}</h1>
                   <div class="grid">
                        <span>Weight : ${pokemon.weight} <br></span>
                        <span>Id : ${pokemon.id}</span>
                        <h3>Base Experience : ${pokemon.base_experience} <br></h3>
                        <h2>Id : ${pokemon.id}</h2>
                   </div>                    
                        <div class="habilities">
                        <h2>Habilities</h2>
                        ${habStr}
                         </div>
                </article>
            </div>
        </section>`
        } catch (e) {
            console.log(e)
        }

    }
    container.innerHTML = template
    container.style.gridTemplateColumns =  "repeat(auto-fit,minmax(450px,1rem))"
    prevLink = data.previous ? `<a href ="${data.previous}"><--</a>` : ""
    nextLink = data.next ? `<a href ="${data.next}">--></a>` : ""
    nav.innerHTML = nextLink + prevLink
}

button.addEventListener('click', () => {
    
    getData('https://pokeapi.co/api/v2/pokemon/').then(data => {
        fullDOM(data).then(()=>{

        })
            
        
    })
})

d.addEventListener('click',e=>{
    e.preventDefault()
    if (e.target.matches('.links a')){
        getData(e.target.getAttribute('href')).then(data=>{
            fullDOM(data)
        })
    }
})

const filter = (e,cards)=>{
    cards.forEach(card =>{
        let pokeName = card.childNodes[3].childNodes[1].childNodes[1].textContent.toLowerCase()
        let inputValue = e.target.value.toLowerCase()
        
        pokeName.includes(inputValue) ? card.classList.remove('filter') : card.classList.add('filter')
        
    })
}

d.addEventListener('keyup',e=>{
    if (e.target.matches('.form__input')){
        let cards = d.querySelectorAll('.card')
        console.log(cards)
        cards.length == 0 ? alert('Aun no hay datos') : filter(e,cards)
    }
})


// this.addEventListener('scroll',e=>{
//     const {scrollTop, clientHeight, scrollHeight} = document.documentElement
//     console.log(scrollTop, clientHeight, scrollHeight)
//     scrollTop+clientHeight === scrollHeight ? getData().then(data=>{fullDOM(data)}) : console.log('nada')
// })

const d = document
export default function searchFilters(input,selectors) {
    // d.querySelectorAll(selectors).forEach(card =>{card.classList.add('filter')})
    d.addEventListener('keyup',ev => {
        if (ev.target.matches(input)){
            d.querySelectorAll(selectors).forEach(card=>{
                //Obteniendo valores textuales de cada una de las tarjetas
                // console.log(card.textContent.toLowerCase())
                let cardContent = card.textContent.toLowerCase();
                //Obteniendi valor de los input
                // console.log(ev.target.value.toLowerCase())
                let inputContent = ev.target.value.toLowerCase();
                cardContent.includes(inputContent) ? card.classList.remove('filter') : card.classList.add('filter')

            })

        }

    })
}
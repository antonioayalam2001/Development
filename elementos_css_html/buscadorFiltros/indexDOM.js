import searchFilters from "./funcionModules/filtroBusquedas.js";
import winner from "./funcionModules/sorteo.js";


const d =document
d.addEventListener('DOMContentLoaded',(e)=>{
    searchFilters(".card-filter",".card")
    winner(".button","ul")
})
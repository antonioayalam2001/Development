import searchFilters from "./filtroBusquedas.js";
import winner from "./sorteo.js";


const d =document
d.addEventListener('DOMContentLoaded',(e)=>{
    searchFilters(".card-filter",".card")
    winner(".button","ul")
})
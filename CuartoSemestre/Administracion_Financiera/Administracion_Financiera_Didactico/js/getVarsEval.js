 function getAllVars(){
anios=document.getElementById("anios").value;
maximaproduccion=document.getElementById("maximaproduccion").value;
preciounidadextra=document.getElementById("preciounidadextra").value;
tasaminimaaceptacion=document.getElementById("tasaminimaaceptacion").value/100;
unidades=document.getElementById("unidades").value;
tasaanualunidades=document.getElementById("tasaanualunidades").value/100;
precio=document.getElementById("precio").value;
tasaanualprecio=document.getElementById("tasaanualprecio").value/100;
gastoadministracion=document.getElementById("gastoadministracion").value;
incrementoanualgastoadministracion=document.getElementById("incrementoanualgastoadministracion").value/100;
gastoventa=document.getElementById("gastoventa").value
incrementoanualgastoventa=document.getElementById("incrementoanualgastoventa").value/100;

costomateriaA=document.getElementById("costomateriaA").value;
incrementocostomateriaA=document.getElementById("incrementocostomateriaA").value/100;
costomateriaB=document.getElementById("costomateriaB").value;
incrementocostomateriaB=document.getElementById("incrementocostomateriaB").value/100;
costomateriales=document.getElementById("costomateriales").value;
incrementocostomateriales=document.getElementById("incrementocostomateriales").value/100;
costomanoobra=document.getElementById("costomanoobra").value;
incrementocostomanoobra=document.getElementById("incrementocostomanoobra").value/100;
costomantenimientoequipo=document.getElementById("costomantenimientoequipo").value;
incrementocostomantenimientoequipo=document.getElementById("incrementocostomantenimientoequipo").value/100;
terreno=document.getElementById("terreno").value;
//recuperacionterreno=document.getElementById("recuperacionterreno").value;
//vidautilterreno=document.getElementById("vidautilterreno").value;
edificio=document.getElementById("edificio").value;
recuperacionedificio=document.getElementById("recuperacionedificio").value;
vidautiledificio=document.getElementById("vidautiledificio").value;
equipo=document.getElementById("equipo").value;
recuperacionequipo=document.getElementById("recuperacionequipo").value;
vidautilequipo=document.getElementById("vidautilequipo").value;
capital=document.getElementById("capital").value;

inversionInicial();
  }
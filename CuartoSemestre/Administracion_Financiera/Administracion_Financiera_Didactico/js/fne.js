
var ventasedo=[]
var ivaedo=[]
var ventasnetasedo=[]
var costosprodedo=[]
var depreciacionedo;
var utilidadbrutedo=[]
var gastosventedo=[]
var gastosadmonedo=[]
var utilidadoperedo=[]
var gastosfinanedo=[]
var utilidadimpuedo=[]
var impuestoedo=[]
var utilidadejeredo=[]


function generarEdoResultado(){
	tabla=document.getElementById('edoresultados');
	ht='<tr><td>Ventas</td>'
	for (var i = 0; i < 6; i++) {
		ventasedo[i]=(unidadesmeses[i]*preciomeses[i]);	
		ht+='<td>$ '+parseFloat(ventasedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
	for (var i = 0; i < 6; i++) {
		ventasnetasedo[i]=ventasedo[i]/1.16		
	};
	for (var i = 0; i < 6; i++) {
		ivaedo[i]=ventasedo[i]-ventasnetasedo[i];		
	};
	ht+='<tr><td>IVA</td>'
	for (var i = 0; i < 6; i++) {
		ht+='<td>$ '+parseFloat(ivaedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Ventas Netas</td>'
	for (var i = 0; i < 6; i++) {
		ht+='<td>$ '+parseFloat(ventasnetasedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
	ht+='<tr><td>Costos de Produccion</td>'
	for (var i = 0; i < 6; i++) {
		costosprodedo[i]=(unidadesmeses[i]*costosprodmeses[i]);	
		ht+='<td>$ '+parseFloat(costosprodedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
	ht+='<tr><td>Depreciacion</td>'
	for (var i = 0; i < 6; i++) {
		depreciacionedo=((equipo-valorrescateequipo)/vidautilequipo)/12;	
		ht+='<td>$ '+parseFloat(depreciacionedo).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Utilidad Bruta</td>'
	for (var i = 0; i < 6; i++) {
		utilidadbrutedo[i]=ventasnetasedo[i]-costosprodedo[i]-depreciacionedo;	
		ht+='<td>$ '+parseFloat(utilidadbrutedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Gastos por ventas</td>'
	for (var i = 0; i < 6; i++) {
		gastosventedo[i]=unidadesmeses[i]*gastosventmeses[i];	
		ht+='<td>$ '+parseFloat(gastosventedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
	ht+='<tr><td>Gastos de administracion</td>'
	for (var i = 0; i < 6; i++) {
		gastosadmonedo[i]=unidadesmeses[i]*gastosadmonmeses[i];	
		ht+='<td>$ '+parseFloat(gastosadmonedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Utilidad de operacion</td>'
	for (var i = 0; i < 6; i++) {
		utilidadoperedo[i]=utilidadbrutedo[i]-gastosventedo[i]-gastosadmonedo[i];	
		ht+='<td>$ '+parseFloat(utilidadoperedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Gastos financieros</td>'
	gastosfinanedo[0]=prestamo*tasainterespres;	
	ht+='<td>$ '+parseFloat(gastosfinanedo[0]).toFixed(2)+'</td>'	
	for (var i = 1; i < 6; i++) {
		gastosfinanedo[i]=0;	
		ht+='<td>$  -  </td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Utilidad de antes de impuestos</td>'
	for (var i = 0; i < 6; i++) {
		utilidadimpuedo[i]=utilidadoperedo[i]-gastosfinanedo[i];	
		ht+='<td>$ '+parseFloat(utilidadimpuedo[i]).toFixed(2)+'</td>'		
	};

	ht+='</tr>'
	ht+='<tr><td>Impuestos</td>'
	ht+='<td>$  -  </td><td>$  -  </td>'
	impuestoedo[0]=0;
	impuestoedo[1]=0;
	for (var i = 2; i < 6; i++) {
		if (utilidadimpuedo[i]>=0 && utilidadimpuedo[i]<=999) {
			impuestoedo[i]=utilidadimpuedo[i]*.10;	
		}else if (utilidadimpuedo[i]>=1000 && utilidadimpuedo[i]<=9999){
			impuestoedo[i]=utilidadimpuedo[i]*.15;	
		}else if (utilidadimpuedo[i]>=10000 && utilidadimpuedo[i]<=49999){
			impuestoedo[i]=utilidadimpuedo[i]*.20;	
		}else if (utilidadimpuedo[i]>=50000 && utilidadimpuedo[i]<=99999){
			impuestoedo[i]=utilidadimpuedo[i]*.25;	
		}else if (utilidadimpuedo[i]>=100000 && utilidadimpuedo[i]<=499999){
			impuestoedo[i]=utilidadimpuedo[i]*.30;	
		}else{
			impuestoedo[i]=utilidadimpuedo[i]*.35;
		}
		
		ht+='<td>$ '+parseFloat(impuestoedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td class="reslt">Utilidad/Perdida del ejercicio</td>'
	for (var i = 0; i < 6; i++) {
		utilidadejeredo[i]=utilidadimpuedo[i]-impuestoedo[i];	
		ht+='<td>$ '+parseFloat(utilidadejeredo[i]).toFixed(2)+'</td>'		
	};

tabla.innerHTML=ht

flujoEfectivo();
}

var ventascontadoingr=[]
var cuentascobraringr=[]
var totalingr=[];

function flujoEfectivo(){
	tabla=document.getElementById('ingresos');
	ht='<tr><td>Pronostico de Ventas</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(ventasedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Ventas de contado (40%)</td>'
	for (var i = 0; i < 6; i++) {
		ventascontadoingr[i]=(ventasedo[i]*0.4);	
		ht+='<td>$ '+parseFloat(ventascontadoingr[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Cuentas por cobrar a un mes (60%)</td>'
	ht+='<td>$ '+parseFloat(cuentaspc).toFixed(2)+'</td>'
	cuentascobraringr[0]=cuentaspc;
	for (var i = 1; i < 6; i++) {
		cuentascobraringr[i]=(ventasedo[i-1]*0.6);	
		ht+='<td>$ '+parseFloat(cuentascobraringr[i]).toFixed(2)+'</td>'		
	};

	ht+='</tr>'
	ht+='<tr class="reslt"><td>Total de ingresos</td>'
	for (var i = 0; i < 6; i++) {
		totalingr[i]=parseFloat(ventascontadoingr[i])+parseFloat(cuentascobraringr[i]);	
		ht+='<td>$ '+parseFloat(totalingr[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
tabla.innerHTML=ht
flujoEfectivoEgresos();
}

var totalegre=[];

function flujoEfectivoEgresos(){
	tabla=document.getElementById('egresos');
	ht='<tr><td>Costos de produccion</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(costosprodedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Gastos por venta</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(gastosventedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
ht+='<tr><td>Gastos de administracion</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(gastosadmonedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Gastos Financieros</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(gastosfinanedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>IVA</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(ivaedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>impuestos</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(impuestoedo[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'


	ht+='<tr class="reslt"><td>Total de egresos</td>'
	for (var i = 0; i < 6; i++) {
		totalegre[i]=parseFloat(costosprodedo[i])+parseFloat(gastosventedo[i])+parseFloat(gastosadmonedo[i])+parseFloat(gastosfinanedo[i])+parseFloat(ivaedo[i])+parseFloat(impuestoedo[i])
		ht+='<td>$ '+parseFloat(totalegre[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

tabla.innerHTML=ht

flujoEfectivoOperacion();
}

var prestamoreq=[];
var flujototaloperacion=[]
function flujoEfectivoOperacion(){
	tabla=document.getElementById('flujoefectivoop');
	ht='<tr><td>Total de Ingresos</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(totalingr[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
	ht+='<tr><td>Total de Egresos</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(totalegre[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'
	ht+='<tr><td>Total de Flujo de operacion</td>'
	for (var i = 0; i < 6; i++) {	
		flujototaloperacion[i]=totalingr[i]-totalegre[i]
		if (flujototaloperacion[i]<valoresperado) {
			prestamoreq[i]=valoresperado-flujototaloperacion[i]

		}else{
			prestamoreq[i]=0;
		}
		ht+='<td>$ '+parseFloat(flujototaloperacion[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	tabla.innerHTML=ht;

	flujoEfectivoFinanciamiento();

}

var flujfin=[];
var operacionyfin=[];
var efectivoinicial=[];
var saldofinal=[]
function flujoEfectivoFinanciamiento(){
	tabla=document.getElementById('flujoefectivofin');
	ht='<tr><td>Prestamo Requerido</td>'
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(prestamoreq[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Flujo total de financiamiento</td>'
	ht+='<td>'+parseFloat(prestamo*-1).toFixed(2)+'</td>'
	flujfin[0]=prestamo*-1;
	for (var i = 1; i < 6; i++) {	
		flujfin[i]=prestamoreq[0]*-1
		ht+='<td>$ '+parseFloat(flujfin[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Flujo de Efectivo de operacion y financiamiento</td>'
	
	for (var i = 0; i < 6; i++) {	
		operacionyfin[i]=flujototaloperacion[i]+flujfin[i];
		ht+='<td>$ '+parseFloat(operacionyfin[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'



	
	efectivoinicial[0]=efectivo;
	for (var i = 0; i < 6; i++) {	
		saldofinal[i]=parseFloat(operacionyfin[i])+parseFloat(efectivoinicial[i]);
		efectivoinicial[i+1]=saldofinal[i];		
	};

	ht+='<tr><td>Efectivo Inicial</td>'
	ht+='<td>$ '+parseFloat(efectivo).toFixed(2)+'</td>'
	for (var i = 1; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(efectivoinicial[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>saldofinal</td>'
	
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(saldofinal[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	tabla.innerHTML=ht;

	balancegeneralfinact();
}


efectivonewbalance=[]
cuentascobrarnewbalance=[]
totalactivocnewbalance=[]
depreciacionacumnewbalance=[]
totalactivofnewbalance=[]
totalactivosnewbalance=[]
function balancegeneralfinact(){

	tabla=document.getElementById('balancegeneralfinact');
	ht='<tr><td>Efectivo</td>'
	for (var i = 0; i < 6; i++) {
	efectivonewbalance[i]=saldofinal[i];
		ht+='<td>$ '+parseFloat(saldofinal[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Cuentas por cobrar</td>';
	for (var i = 1; i < 6; i++) {	
		cuentascobrarnewbalance[i-1]=cuentascobraringr[i];
		ht+='<td>$ '+parseFloat(cuentascobraringr[i]).toFixed(2)+'</td>'		
	};
	cuentascobrarnewbalance[5]=ventasedo[5]*.6;
	ht+="<td>$ "+parseFloat(ventasedo[5]*.6).toFixed(2)+"</td>"
	ht+='</tr>'

	ht+='<tr><td>Total de activo circulante</td>';
	for (var i = 0; i < 6; i++) {	
		totalactivocnewbalance[i]=parseFloat(efectivonewbalance[i])+parseFloat(cuentascobrarnewbalance[i]);
		ht+='<td>$ '+parseFloat(parseFloat(efectivonewbalance[i])+parseFloat(cuentascobrarnewbalance[i])).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Equipo</td>';
	for (var i = 0; i < 6; i++) {	
		ht+='<td>$ '+parseFloat(equipo).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Depreciacion acumulada</td>';
	for (var i = 1; i < 7; i++) {	
		depreciacionacumnewbalance[i-1]=depreciacionedo*i;
		ht+='<td>$ '+parseFloat(depreciacionedo*i).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

ht+='<tr><td>Total de activo fijo</td>';
	for (var i = 0; i < 6; i++) {	
		totalactivofnewbalance[i]=equipo-depreciacionacumnewbalance[i];
		ht+='<td>$ '+parseFloat(totalactivofnewbalance[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

ht+='<tr><td>Total de activos</td>';
	for (var i = 0; i < 6; i++) {	
			totalactivosnewbalance[i]=parseFloat(parseFloat(totalactivocnewbalance[i])+parseFloat(totalactivofnewbalance[i]));
		ht+='<td>$ '+parseFloat(parseFloat(totalactivocnewbalance[i])+parseFloat(totalactivofnewbalance[i])).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	tabla.innerHTML=ht;

	balancegeneralfinpas();
}



function balancegeneralfinpas(){

	tabla=document.getElementById('balancegeneralfinpas');
	ht='<tr><td>Prestamo</td>'
	for (var i = 0; i < 6; i++) {
		ht+='<td>$ '+parseFloat(prestamoreq[i]).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Total de Pasivos</td>';
	for (var i = 0; i < 6; i++) {

		ht+='<td>$ '+parseFloat(prestamoreq[i]).toFixed(2)+'</td>'			
	};
	ht+='</tr>'

	tabla.innerHTML=ht;

	balancegeneralfincap();
}

unidadesperdidasacum=[]

function balancegeneralfincap(){

	tabla=document.getElementById('balancegeneralfincap');

	ht='<tr><td>Unidades o perdidas acumuladas</td>'
	for (var i = 0; i < 6; i++) {
		unidadesperdidasacum[i]=parseFloat(totalactivosnewbalance[i]-capitalsoc)
		ht+='<td>$ '+parseFloat(totalactivosnewbalance[i]-capitalsoc).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Capital social</td>'
	for (var i = 0; i < 6; i++) {
		ht+='<td>$ '+parseFloat(capitalsoc).toFixed(2)+'</td>'		
	};
	ht+='</tr>'

	ht+='<tr><td>Pasivo mas capital</td>';
	for (var i = 0; i < 6; i++) {

		ht+='<td>$ '+parseFloat(parseFloat(prestamoreq[i])+parseFloat(capitalsoc)+parseFloat(unidadesperdidasacum[i])).toFixed(2)+'</td>'			
	};
	ht+='</tr>'

	tabla.innerHTML=ht;
}
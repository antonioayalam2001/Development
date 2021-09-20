%%VALORES DE X
x = [ 100	1000	5000	10000	50000	100000	125000	175000	200000	225000	275000	300000	325000	375000	400000	425000	500000
];
%%VALORES DE y = F(x) en Milisegundos
y = [3.5048E-05	6.2418E-04	5.7921E-03	1.4734E-02	1.2065E-01	3.3611E-01	3.4146E-01	4.7708E-01	7.5258E-01	7.1483E-01	1.0851E+00	1.0610E+00	1.2005E+00	1.5154E+00	1.7913E+00	1.7277E+00	2.3140E+00
];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
p = polyfit(log(x),y,1)
a=p(1);
c=p(2);
fprintf('f(x)=%f*ln(x)+%f\n',a,c);

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,500000,2000);      %%ESPACIO DE PUNTOS PARA Xi
z = polyval(p,log(xi));        %%EVALUACION DE LA CURVA LOGARITMICA P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('Segundos');
xlabel('numeros');
title('Ajuste logarítmico y=a·ln(x)+c QuickSort');

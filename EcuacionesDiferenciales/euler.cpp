#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
using namespace std;

double f(double x, double y){
	//return (x + 1) * sqrt(y);
	return (4* pow(y,2) - pow(x,2) * y);
}

int main(int argc, char *argv[]) {
	int N; // N numero de datos o puntos
	double h, x[30], y[30];//[N] modificar*********
	float a, b, yo; //a, b intervalo
	
	FILE *file;
	
	file = fopen("euler.txt", "w");
	
	if (file == NULL) {
		printf("No se pudo abrir el archivo\n");
		return -1;
	}
	
	cout << "METODO DE EULER" << endl;
	
	printf("ingrese el valor del limite inferior del intervalo de integracion\n");
	scanf("%f", &a);
	
	printf("ingrese el valor del limite superior del intervalo de integracion\n");
	scanf("%f", &b);
	
	printf("ingrese el numero de puntos\n");
	scanf("%d", &N);
	
	printf("x_min=%f, x_max=%f, N=%d\n", a, b, N);
	
	h = 0.1;// modificar*********** o h = (b*a)/N
	
	printf("h=%.12f\n", h);
	
	printf("ingrese el dato inicial (yo)\n");
	scanf("%f", &yo);
	printf("yo=%f\n", yo);
	
	x[0] = a;
	y[0] = yo;
	/*
	cout << "x0: ";
	printf("%f\n", x[0]);
	cout << "y0: ";
	printf("%f\n", y[0]);
	*/
	fprintf(file,"%f", x[0]);
	fprintf(file,"\t%f\n", y[0]);
	
	for(int i = 0; i <= N-1; i++){
		x[i+1] = x[i] + h;
		y[i+1] = y[i] + h * f(x[i], y[i]);
		fprintf(file,"%f", x[i+1]);
		fprintf(file,"\t%f\n", y[i+1]);
		/*cout << "x"<<i+1<<": ";
		printf("%f\n", x[i+1]);
		cout << "y"<<i+1<<": ";
		printf("%f\n", y[i+1]);*/
	}
	
	
	return 0;
}

//para graficar en gnuplot
//plot 'datos.txt' using 1:2 with points
/*
plot 'datos1.txt' using 1:2 with points title 'Datos 1',
'datos2.txt' using 1:2 with points title 'Datos 2'
*/


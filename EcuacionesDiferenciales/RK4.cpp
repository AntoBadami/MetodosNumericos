#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
using namespace std;

double f(double x, double y){
	return y-4*y+pow(x,2);
}
	
	int main(int argc, char *argv[]) {
		int N; // N numero de datos o puntos
		double h, x[30], y[30];//[N] modificar*********
		float a, b, yo; //a, b intervalo
		double k1, k2, k3, k4;
		
		FILE *file;
		
		file = fopen("RK4.txt", "w");
		
		if (file == NULL) {
			printf("No se pudo abrir el archivo\n");
			return -1;
		}
		
		cout << "METODO DE RK4" << endl;
		
		printf("ingrese el valor del limite inferior del intervalo de integracion\n");
		scanf("%f", &a);
		
		printf("ingrese el valor del limite superior del intervalo de integracion\n");
		scanf("%f", &b);
		
		printf("ingrese el numero de puntos\n");
		scanf("%d", &N);
		
		printf("x_min=%f, x_max=%f, N=%d\n", a, b, N);
		
		h = 0.1; // modificar*********** o h = (b*a)/N
		
		printf("h=%.12f\n", h);
		
		printf("ingrese el dato inicial (yo)\n");
		scanf("%f", &yo);
		printf("yo=%f\n", yo);
		
		x[0] = a;
		y[0] = yo;
		
		fprintf(file,"%f", x[0]);
		fprintf(file,"\t%f\n", y[0]);
		
		for(int i = 0; i <= N-1; i++){
			
			k1 = f(x[i], y[i]);
			k2 = f(x[i] + h/2, y[i] + (k1 * h)/2);
			k3 = f(x[i] + h/2, y[i] + (k2 * h)/2);
			k4 = f(x[i] + h, y[i] + k3 * h);
			
			x[i+1] = x[i] + h;
			y[i+1] = y[i] + ((k1 + 2*k2 + 2*k3 + k4) *h )/6;
			
			fprintf(file,"%f", x[i+1]);
			fprintf(file,"\t%f\n", y[i+1]);
		}
		return 0;
	}
	
	
	//plot 'datos.txt' using 1:2 with points
/*
	plot 'datos1.txt' using 1:2 with points title 'Datos 1',
	'datos2.txt' using 1:2 with points title 'Datos 2'
	*/

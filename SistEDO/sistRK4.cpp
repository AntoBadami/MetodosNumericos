#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
using namespace std;
/*RK4: SIST DE ECUACIONES EDO (PARA 2 FUNCIONES)*/

double f1(double x, double y1, double y2){
	return y2;
}
	
	double f2(double x, double y1, double y2){
		return -5 * y1 * y2 - (y1 + 7) * sin(x);
	}
	
	int main(int argc, char *argv[]) {
		int N; // N numero de datos o puntos
		double h, x[100], y1[100], y2[100];//[N] modificar*********
		float a, b, y1o, y2o; //a, b intervalo
		double k11, k12, k13, k14;
		double k21, k22, k23, k24;
		
		FILE *file;
		
		file = fopen("sistRK4.txt", "w");
		
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
		
		h = 0.01; // modificar*********** o h = (b*a)/N
		
		printf("h=%.12f\n", h);
		
		printf("ingrese el dato inicial 1 (y1o)\n");
		scanf("%f", &y1o);
		printf("ingrese el dato inicial 2 (y2o)\n");
		scanf("%f", &y2o);
		printf("y1o=%f\n", y1o);
		printf("y2o=%f\n", y2o);
		
		x[0] = a;
		y1[0] = y1o;
		y2[0] = y2o;
		
		fprintf(file,"%f", x[0]);
		fprintf(file,"\t%f", y1[0]);
		fprintf(file,"\t%f\n", y2[0]);
		
		
		for(int i = 0; i <= N-1; i++){
			
			k11 = f1(x[i], y1[i], y2[i]);
			k21 = f2(x[i], y1[i], y2[i]);
			
			k12 = f1(x[i] + h/2, y1[i] + (k11 * h)/2, y2[i] + (k21 * h)/2);
			k22 = f2(x[i] + h/2, y1[i] + (k11 * h)/2, y2[i] + (k21 * h)/2);
			
			k13 = f1(x[i] + h/2, y1[i] + (k12 * h)/2, y2[i] + (k22 * h)/2);
			k23 = f2(x[i] + h/2, y1[i] + (k12 * h)/2, y2[i] + (k22 * h)/2);
			
			k14 = f1(x[i] + h, y1[i] + k13 * h, y2[i] + k23 * h);
			k24 = f2(x[i] + h, y1[i] + k13 * h, y2[i] + k23 * h);
			
			x[i+1] = x[i] + h;
			y1[i+1] = y1[i] + ((k11 + 2*k12 + 2*k13 + k14) *h )/6;
			y2[i+1] = y2[i] + ((k21 + 2*k22 + 2*k23 + k24) *h )/6;
			
			fprintf(file,"%f", x[i+1]);
			fprintf(file,"\t%f", y1[i+1]);
			fprintf(file,"\t%f\n", y2[i+1]);
			
		}
		return 0;
	}
	
	
	//plot 'datos.txt' using 1:2 with points
	/*
	plot 'datos1.txt' using 1:2 with points title 'Datos 1',
	'datos2.txt' using 1:2 with points title 'Datos 2'
	
	plot "sistRK4.txt" using 1:2 with points title 'y1', '' using 1:3 with points title 'y2'
	
	*/
	
	

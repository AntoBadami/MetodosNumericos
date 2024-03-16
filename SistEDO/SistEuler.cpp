#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
using namespace std;

/*EULER: SIST DE ECUACIONES EDO (PARA 2 FUNCIONES)*/

double f1(double x, double y1, double y2){
	return y2;
}
	
double f2(double x, double y1, double y2){;
	return -5 * y1 * y2 - (y1 + 7) * sin(x);
}
	
	int main(int argc, char *argv[]) {
		int N; // N numero de datos o puntos
		double h, x[100], y1[100], y2[100];//[N] modificar*********
		float a, b, y1o, y2o; //a, b intervalo
		
		FILE *file;
		
		file = fopen("sistEuler.txt", "w");
		
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
		
		h = 0.01;// modificar*********** o h = (b-a)/N
		
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
			x[i+1] = x[i] + h;
			y1[i+1] = y1[i] + h * f1(x[i], y1[i], y2[i]);
			y2[i+1] = y2[i] + h * f2(x[i], y1[i], y2[i]);
			
			fprintf(file,"%f", x[i+1]);
			fprintf(file,"\t%f", y1[i+1]);
			fprintf(file,"\t%f\n", y2[i+1]);
			
		}
		
		
		return 0;
	}
	
	//para graficar en gnuplot
	//plot 'datos.txt' using 1:2 with points
	/*
	plot 'datos1.txt' using 1:2 with points title 'Datos 1',
	'datos2.txt' using 1:2 with points title 'Datos 2'
	
	plot "sistRK4.txt" using 1:2 with points title 'y1', '' using 1:3 with points title 'y2'
	
	*/
	
	

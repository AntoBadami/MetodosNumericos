#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
using namespace std;

double f(double x, double y){
	return (x + 1) * sqrt(y);
}
	
	int main(int argc, char *argv[]) {
		int N; // N numero de datos o puntos
		double h, x[100], y[100], yp[100];//[N] modificar*********
		float a, b, yo; //a, b intervalo
		
		FILE *file;
		
		file = fopen("heun.txt", "w");
		
		if (file == NULL) {
			printf("No se pudo abrir el archivo\n");
			return -1;
		}
		
		cout << "METODO DE HEUN" << endl;
		
		printf("ingrese el valor del limite inferior del intervalo de integracion\n");
		scanf("%f", &a);
		
		printf("ingrese el valor del limite superior del intervalo de integracion\n");
		scanf("%f", &b);
		
		printf("ingrese el numero de puntos\n");
		scanf("%d", &N);
		
		printf("x_min=%f, x_max=%f, N=%d\n", a, b, N);
		
		h = 0.01; // modificar*********** o h = (b*a)/N
		
		printf("h=%.12f\n", h);
		
		printf("ingrese el dato inicial (yo)\n");
		scanf("%f", &yo);
		printf("yo=%f\n", yo);
		
		x[0] = a;
		y[0] = yo;
		//j = 0;
		/*while (x[j] != x_max && j < N)
		{
		x[j + 1] = x[j] + h;
		y[j + 1] = y[j] + h * f(x[j], y[j]);
		j++;
		if (error > errorMax)
		{
		h = h * (3 / 4); //Achicamos h.
		}
		else if (error < errorMin)
		{
		h = h * (4 / 3); //Aumentamos h.
		}
		}
		*/
		
		/*
		for (j = 1; j <= N; j++)
		{
		x[j] = a + (double)j * h;
		y[j] = y[j - 1] + h * f(x[j - 1], y[j - 1]);
		}
		*/
		
		fprintf(file,"%f", x[0]);
		fprintf(file,"\t%f\n", y[0]);
		
		for(int i = 0; i <= N-1; i++){
			x[i+1] = x[i] + h;
			yp[i+1] = y[i] + h * f(x[i], y[i]); //calcula predictor
			y[i+1] = y[i] + ( h * (f(x[i], y[i]) + f(x[i+1], yp[i+1]) )) /2;
			
			fprintf(file,"%f", x[i+1]);
			fprintf(file,"\t%f\n", y[i+1]);
		}
		/*
		for (int j = 0; j <= N; j++)
		
		fprintf(file, "%.12f  %.12f\n", x[j], y[j]);
		*/
		
		return 0;
	}
	
	//plot 'datos.txt' using 1:2 with points

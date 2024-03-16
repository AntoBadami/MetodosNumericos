//trapecio compuesto con tabla de valores NO equiespaciados
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	double x[7]={7,9,11,13,15,17,19};
	double y[7]={18,20,26,30,35,37,32};
	int n=7; // con n = 4 -> n = 0, 1, 2, 3
	double h;
	double sum=0; //suma los valores internos 
	
	for(int i=0; i<n-1; i++){
		h=x[i+1]-x[i];
		sum+=(h/2)*(y[i] + y[i+1]);
	}
	
	printf("La integral f(x) con puntos NO EQUIDISTANTES en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],sum);
	cout << endl << endl;
	
	return 0;
}

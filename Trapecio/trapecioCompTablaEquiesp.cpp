//trapecio compuesto con tabla de valores equiespaciados
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	double x[9]={0,0.25,0.5,0.75,1,1.25,1.5,1.75,2};
	double y[9]={0.890667, 1.434669, 1.715888, 2.105333, 2.688999, 3.631999, 4.644560, 5.322674, 5.468663};//[n] modificar***********
	int n=9; // con n = 4 -> n = 0, 1, 2, 3
	double h;
	double aprox;
	double sum=0; //suma los valores internos 
	
	//controlar q esta equiespaciada
	h=x[1]-x[0];
	
	for(int i=1; i <= n-2; i++){
		sum+=y[i];
	}
	
	aprox=(h/2)*((y[0] + y[n-1])+2*sum);
	
	printf("La integral f(x) con puntos EQUIDISTANTES en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],aprox);
	cout << endl << endl;
	return 0;
}


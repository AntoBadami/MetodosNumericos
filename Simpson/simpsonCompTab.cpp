//simpson compuesto con tabla (valores equiespaciados si o si)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	double x[11]={1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2};
	double y[11]={5.381,6.526702,7.635878,8.672,9.592,10.332953,10.853,11.123221,11.134,10.898786,10.435};//[n] modificar***********
	int n=11; // con n = 4 -> n = 0, 1, 2, 3
	// n debe ser impar, n es la cantidad de datos
	// para este metodo necesitamos una cantidad PAR de subintervalos
	double h;
	double aprox;
	double sumImp=0; //suma los valores internos impares
	double sumPar=0; //suma los valores internos pares
	
	//controlar q esta equiespaciada!!! =)
	h=x[1]-x[0];
	
	if(n%2==0){
		cout << "No se puede aplicar el metodo de Simpson! Usar Trapecio!! o interpolar para buscar mas puntos!" << endl;
		exit(0);	
	}
	
	for(int i=1; i <= n-2; i++){
		sumImp+=y[i];
		i++;
	}
	
	for(int i=2; i <= n-3; i++){
		sumPar+=y[i];
		i++;
	}
	
	aprox=(h/3)*((y[0] + y[n-1])+(4*sumImp)+(2*sumPar));
	
	printf("La integral f(x) en el intervalo [%lf;%lf] es: %lf", x[0],x[n-1],aprox);
	cout << endl << endl;
	
	return 0;
}

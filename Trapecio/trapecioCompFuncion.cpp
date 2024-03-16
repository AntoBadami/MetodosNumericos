//trapecio compuesto con funcion!!!

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

//Escribir aca la funcion:
double f(double x){
	//return (pow(x,2)+1);
	return sin(2*x)*exp(-x);
}
	
	
int main(int argc, char *argv[]) {
	
	double a;
	double b;
	int n;
	double h;
	double aprox;
	double x;
	double sum=0; //suma los valores internos
	
	
	cout << "Valor inferior del intervalo: ";
	cin >> a;
	cout << "Valor superior del intervalo: ";
	cin >> b;
	cout << "Cantidad de intervalos/segmentos: "; //Si es simple escribimos 1
	cin >> n;
	
	//los puntos son equidistantes
	h=(b-a)/n;
	
	for(int i=1; i <= n-1; i++){
		x=a+i*h;
		sum+=f(x);
	}
	
	aprox=(h/2)*(f(a)+f(b)+2*sum);
	printf("La integral f(x) en el intervalo [%lf;%lf] es: %lf\n", a,b,aprox);
	
	
	return 0;
}

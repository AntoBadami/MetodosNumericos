#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double g(double x);// g(x) = x !!!!!
double derivada(double x);

int main(int argc, char const *argv[]){
	double x0, xv, xn;
	double error = 1, tolerancia;
	int iter = 0;
	
	cout << "Ingrese el valor inicial: ";
	cin >> x0;
	cout << "Ingrese la tolerancia: ";
	cin >> tolerancia;
	xv = x0;
	
	do{
		iter++;
		
		if(fabs(derivada(xv))>=1){
			printf("No se cumple el criterio de convergencia");
			exit (0);	
		}else{
			xn = g(xv);
			error = fabs(xv-xn);
			xv = xn;
			
			cout << "La Raiz es: " << setprecision(7) <<xn << endl;
			cout << "El error es: " << error << endl;
			cout << "Iteraciones es: " << iter << endl;
		}
	}while(error > tolerancia);
	
	
	
	return 0;
}

// despeje
double g(double x){
	//return pow(x,5)-3*x*x*x-2*x*x+2;
	//return pow(x, x-cos(x));
	//return x * cosh(12/x)-5;
	return (-log(x)+sin(3*x))/2;
}
// derivada
double derivada(double x){
	double h = 0.01;
	return (g(x+h)-g(x))/h;
}

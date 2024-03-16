#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

double f(double x);

int main(int argc, char const *argv[]){
	double x0, xi, xn;
	double error = 1, tolerancia;
	int iter = 0;
	
	cout << "Ingrese x0: ";
	cin >> x0;
	cout << "Ingrese xi: ";
	cin >> xi;
	cout << "Ingrese la tolerancia: ";
	cin >> tolerancia;
	
	do{
		iter++;
		
		/*if(iter==1000 or (f(xvv)-f(xv))==0){
			printf("la funcion no converge.");
			exit (EXIT_FAILURE);
		}*/
		
		xn = xi - f(xi)*(x0-xi)/(f(x0)-f(xi));
		error = fabs(xn-xi);
		x0 = xi;
		xi = xn;
		
	}while(error > tolerancia);
	
	cout << "La Raiz es: " << setprecision(7)<< xn << endl;
	printf("Iteracion: %d, Error: %lf\n", iter, error);
	
	return 0;
}
	
double f(double x){
	return -x + 2;
}


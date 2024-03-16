#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

double f(double x);
double fprima(double x);

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
		
		if(fabs(fprima(xv)) < 0.00001){
			printf("Derivada muy pequenia");
			return 0;	
		}else{
			xn = xv - f(xv)/fprima(xv);
			//error = fabs((xv-xn)/xn);
			error = fabs(xn - xv); //Error estimado
			xv = xn;
		}
	}while(error > tolerancia);
	
	cout << "La Raiz es: " << setprecision(7) << xn << endl;
	cout << "El error es: " << error << endl;
	cout << "Iteraciones es: " << iter << endl;
	
	return 0;
}

double f(double x){
	//return pow(x,5)-3*x*x*x-2*x*x+2-x;
	return pow(x,x)-5;
	//return x * cosh(10/x)-x-6;
}
	
double fprima(double x){
	double h = 0.01;
	return ((f(x + h) - f(x)) / h);
	//return pow(x,x)*(log(x)+1);//cambiar derivada si es necesario*********
}

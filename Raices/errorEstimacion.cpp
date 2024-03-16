#include <iostream>
#include <math.h>
using namespace std;

double funcion (double x);

int main(int argc, char *argv[]) {
	double a, b, c, tolerancia, error=1, cv = a;
	
	cout << "Ingrese a: ";
	cin >> a;
	cout << "Ingrese b: ";
	cin >> b;
	cout << "Ingrese tolerancia: ";
	cin >> tolerancia;
	
	if(funcion(a) * funcion(b) > 0){
		cout << "NO hay raiz o hay un numero par de ellas" << endl;
	}
	
	do{
		
		c = (a+b)/2;
		
		if(funcion(a) * funcion(c) > 0){
			a = c;
		}else if(funcion(a) * funcion(c) < 0){
			b = c;
		}else if (funcion(a) * funcion(c) == 0){
			cout << "La raiz es: " << c;
			return 0;
		}
		
		error = abs(c-cv);
		cv = c;
		
	}while(error > tolerancia);
	
	cout << "La raiz es: " << c << endl << "El error es: " << error;
	
	return 0;
}

double funcion (double x){
	double resultado = log(x) + exp(sin(x)) - x;
	return resultado;
}
	

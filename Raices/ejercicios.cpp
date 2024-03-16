#include <iostream>
#include <math.h>
using namespace std;

double funcion (double x);

int main(int argc, char *argv[]) {
	double a, b, c, tolerancia, error=1;
	int i= 0;
	
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
		
		c = a - ((funcion(a) * (b - a)) / (funcion(b) - funcion(a)));	
		if(funcion(a) * funcion(c) > 0){
			a = c;
		}else if(funcion(a) * funcion(c) < 0){
			b = c;
		}else if (funcion(a) * funcion(c) == 0){
			cout << "La raiz es: " << c << endl;
			cout << "Iteraciones " << i;
			exit (0);
		}
		
		error = (b-a)/2;
		i++;
		
	}while(error > tolerancia);
	
	cout << "La raiz es: " << c << endl << "El error es: " << error << endl;
	cout << "Iteraciones " << i;
	return 0;
}

double funcion (double x){
	double resultado = pow(x,10) - 1;
	return resultado;
}
	

#include <iostream>
#include <math.h>
using namespace std;

double f(double x);

int main(int argc, char *argv[]) {
	double a, b, c, tolerancia, error=1;
	int iteracion=0;
	double errorporcentual;
	
	cout << "Ingrese a: ";
	cin >> a;
	cout << "Ingrese b: ";
	cin >> b;
	cout << "Ingrese tolerancia: ";
	cin >> tolerancia;
	
	if(f(a) * f(b) > 0){ //Si es negativo, hay una raiz o una cantidad impar de ellas.
		cout << "No hay raices o hay un numero par de ellas" << endl;
		exit(0);
	}
	double anterior = a;
	do{
		iteracion++;
		c=b-((f(b)*(b-a))/(f(b)-f(a))); //Calculo de la posible raiz como la interseccion de la recta entre f(a) y f(b), con el eje x.
		
		if(f(a)*f(c)>0) //Significa que la raiz esta en el intervalo c-b
			a=c;
		else if (f(c)*f(b)>0) //Significa que la raiz esta en el intervalo a-b
			b=c; //Significa que la raiz esta en el intervalo a-b
		else
			break;
		//error es el error estimado
		
		error = fabs(c - anterior);
		
		//
		//fabs((c - anterior)/c) es el error relativo estimado
		//
		//errorporcentual = fabs((c - anterior)/c)*100; 
		
		anterior = c;
		printf( "Iteracion: %d, Error: %.10lf\n", iteracion, error);//lo cambiar por errorporcentual o error
		printf( "La raiz es: %.10lf\n", c);
		
	}while(error > tolerancia);
	//}while(errorporcentual > 1);
	
	//printf( "El error relativo es: %.10lf\n", errorporcentual/100);
	//printf( "Iteracion: %d, Error: %.10lf\n", iteracion, error);
	//printf( "La raiz es: %.10lf\n", c);
	return 0;
}

double f(double x){
	//double resultado = log(x) + exp(sin(x)) - x;
	double resultado = 2.12*x*x-0.21*x-0.95;
	return resultado;
}
	

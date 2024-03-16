
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
// cambio la funcion que me interesa valuar
double f(double x){
	return (-3 + 4.23333*x -1.35*pow(x,2) + 0.116667*pow(x,3)); 	//FUNCION
}
	
int main(){
	double a;//El intervalo de la izquierda
	double b;//El intervalo de la derecha
	double error; 
	double c; //Es la posible raiz 
	double errorMinimo; //error minimo (es el q damos nosotros)
	int iteracion =0; //Recuento Iteraciones que tarda en encontrar la raiz.
	
	cout << "Ingrese el valor inferior de intervalo (a): "<< endl;
	cin >> a;
	cout << "Ingrese el valor superior de intervalo (b): "<< endl;
	cin >> b;
	cout << "Ingrese el valor del error esperado (e): "<< endl;
	cin >> errorMinimo;
	
	double intervalo1 = a; //Intervalo izquierdo original
	double intervalo2 = b; //Intervalo derecho original
	double anterior = a;
	
	if(f(a)*f(b)>0){ 	//Verifico que la multiplicacion de negativa, para saber si tiene una raiz o un numero impar de ellas.
		cout << "No hay raices o hay un numero par de ellas" << endl;
		exit(0);
	}
	
	
	do{
		iteracion++;
		c=(b+a)/2;  //Calculo de la posbile raiz, a la mitad de los dos intervalso
		
		if(f(a)*f(c)>0) //Significa que la raiz se encuentra entre c y b
			a=c; //Cambiamos para que c sea el nuevo intervalo
		else if (f(c)*f(b)>0) //Significa que la raiz se encuentra entre a y c
			b=c;
		else
			break;
		
		//
		//fabs((c - anterior)/c) es el error relativo estimado
		//
		//errorporcentual = fabs((c - anterior)/c)*100; 
		//error exacto = fabs(c - raizExacta)
		error = fabs(c - anterior); //error estimado.
		anterior = c;
		printf( "Iteracion: %d, Error: %.10lf\n", iteracion, error);
		printf( "La raiz es: %.10lf\n", c);
		
	}while(error > errorMinimo ); //Se repetira hasta que tengamos un error igual o menor al deseado
	
	printf( "Iteracion: %d, Error: %.10lf\n", iteracion, error);
	printf( "La raiz es: %.10lf\n", c);

	printf("El intervalo es: [%.2lf , %.2lf]", intervalo1,intervalo2);
	return 0;
}
		
	//error = (b-a)/2;
	//error = ((b-a)/2)*100;

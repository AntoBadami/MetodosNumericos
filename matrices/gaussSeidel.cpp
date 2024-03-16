#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int filas = 2; //numero de filas //modificar******
	double e = 1.0;
	double  m[2][2] = {3,1,-1,5};
	double b[2] = {10,18};	
	double xn[2], xv[2];
	double epsilon = 0.000001;//tolerancia
	double s;
	int iteracion = 0;
	
	for (int i  = 0; i < filas; i++){
		double suma = 0;
		for(int j = i+1; j < filas; j++)
			suma += m[i][j];
			cout << m[i][i] << " " << suma << endl;
			if(abs(m[i][i]) < abs(suma)){
				cout << "la matriz no se puede resolver por este metodo" << endl;
				return 0;
			}
	}
	
	for(int i = 0; i < filas; i++){
		xv[i] = 0;
		xn[i] = 0;
	}
	
	
	while (e > epsilon){
		for (int i = 0; i < filas; i++){
			s = 0;
			for (int j = 0; j < i; j++)
				s += m[i][j] * xn[j];
				
				for (int j = i + 1; j < filas; j++)
					s += m[i][j] * xv[j];
					
					xn[i] = (b[i] - s)/m[i][i];    
					
					double e1 = 0, e2 = 0;
					for(int i = 0; i < filas; i++){
						e1 += pow(xn[i]-xv[i],2);
						e2 += pow(xn[i],2);
					}
					e = sqrt(e1/e2);
					
					for(int i = 0; i < filas; i++)
						xv[i] = xn[i];
		}
		
		iteracion++;
	}
	
	cout << endl << "----- Soluciones -----" << endl;
	cout << "numeros de iteraciones " << iteracion << endl;
	cout << "Error = " << e << endl;
	for(int i =0; i<=filas-1; i++)
		cout << endl << "x["<< i+1 << "]= " << xn[i];
	cout << endl;
	return 0;
}


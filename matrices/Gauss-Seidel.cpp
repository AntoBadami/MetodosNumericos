#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 4;
	double a[4][4] = {2,-1, 3, -1,
		3, -4, -1, 1,
		-1, -1, 3, 1,
		1, 0, -2, 2};
	double b[4] = {5,-4,10,3};
	double xn[4];
	double xv[4];
	int contador = 0;
	double tol = 0.00001; // Tolerancia
	double suma=0;
	
	// Comprobacion de diagonal dominante
	for(int i=0; i<n; i++){
		suma = 0;
		for(int j=0; n<n; j++){
			if(j!= 1){
				suma+=fabs(a[i][j]);
			}
		}
		if(fabs(a[i][i]) <= suma){
			cout<<"la matriz no es diagonalmente dominante"<<endl;
		}
		if(a[i][i]==0){
			cout<<"ceros en la diagonal"<<endl;
			exit(1);
		}
		
	}
	
	double e;
	
	do {
		e = 0; // Reiniciar e en cada iteración
		for (int i = 0; i < n; i++) {
			suma = 0;
			for (int j = 0; j < n; j++) {
				if (j != i) {
					suma += a[i][j] * xn[j];
				}
			}
			double x_antiguo = xn[i]; // Mantener el valor anterior de xn
			xn[i] = (b[i] - suma) / a[i][i];
			e = fabs(xn[i] - x_antiguo);
		}
		
		for (int i = 0; i < n; i++) {
			xv[i] = xn[i]; // Actualizar xv con los nuevos valores
		}
		
		contador++;
	} while (e > tol);
	for (int i = 0; i < n; i++) {
		xv[i] = xn[i]; // Actualizar xv con los nuevos valores
		cout << "Xn" << i << " = " << xn[i] << endl;
	}
	cout << "Cantidad de iteraciones = " << contador << endl;
	cout << "Error = " << e << endl;
	
	return 0;
}

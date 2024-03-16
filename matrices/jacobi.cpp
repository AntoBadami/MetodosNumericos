#include <iostream>
#include <math.h>
using namespace std;

#define N 100

int main(int argc, char *argv[]) {
	double b[N];
	double a[N][N] {};
	int n = 100, iter=0;
	double e = 1.0, tol = 0.000001, suma =0;
	double xn[N], xv[N];
	
	
	// creacion de la matriz de datos
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			if(i!=0 || i!=99){
				a[i][i] = -2;
			}else if (a[i][j] == -2){
				a[i][j + 1] = 3;
				a[i][j + 2] = 4;
			}
			if(j == 0){
				a[i][j]=1;
				a[i][j + 1] = 4;
			}
			if(j==99){
				a[i][j-1]=1;
				a[i][j] = 4;
			}
			
		}
	}
	
	//verificar que a sea dd
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
	
	do{
		iter++;
		for(int i=0; i<n; i++){
			suma = 0;
			for(int j = 0; j<n; j++){
				if(j!=i){
					suma+=a[i][j]*xv[j];
				}
			}
			xn[i] = (b[i]-suma) / a[i][i];
		}
		suma = 0;
		for(int i=0; i<n; i++){
			suma+=pow(xn[i] - xv[i], 2);
		}
		
		e = sqrt(suma); 
		
		for(int i=0; i<n; i++){
			xv[i] = xn[i];
		}
		
	}while(e > tol);
	
	for(int i=0; i<n; i++){
		cout<< "X" << i << " = " << xn[i] << endl;
	}
	cout<<endl<<"error: "<<e<<endl;
	cout<<"iteraciones: "<<iter;
	return 0;
}


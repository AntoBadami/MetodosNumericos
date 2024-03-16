#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 3, iter=0;
	double e = 1.0, tol = 0.00001, suma =0;
	double  a[3][3] = {7,-1,1,
		11,-2,1,
		12,2,0};
	double b[3] = {1,0,0};
	double xn[3], xv[3];
	
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
			//exit(1);
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


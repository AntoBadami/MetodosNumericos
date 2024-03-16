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
	double xn[3];
	double xv[3];
	
	//verificar que a sea dd
	/*for(int i=0; i<n; i++){
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
		
	}*/
	
	do{
		iter++;
		for(int i=0; i<n; i++){
			suma = 0;
			if(i == 1){
				for(int j=1; j<n; j++){
					suma+=a[i][j]*xv[j];
				}
				xn[i] = (b[i]-suma)/a[i][i];
			}else{
				for(int j=0; j<i-1; j++){
					suma+=a[i][j]*xn[j];
				}
				for(int j=i; j<n; j++){
					suma+=a[i][j]*xv[j];
				}
				xn[i]=(b[i]-suma)/a[i][i];
			}
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
		cout<<xn[i]<<endl;
	}
	cout<<endl<<"error: "<<e<<endl;
	cout<<"iteraciones: "<<iter;
	return 0;
}

/*
con relajacion: w; o <= w <=2
xn [i]= w * xn[i] + (1-w) * xv[i]

esto se hace luego de calcular xn[i] y para cada i

0<w<1 -- no convergia, ahora converge
w = 1 --- no se modifica
1<w<2 -- convergia, converge mas rapido ahora
*/


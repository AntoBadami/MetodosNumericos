#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n=2;//n valor modificable segun el caso*******
	double x[2]={2,3}, y[2]={1,1.5};
	double a[4 * 2][4 *2],b[4 *2]; // [4n] modificar valor!! ********
	
	//armado de matriz
	
	//primeras 2n filas
	for(int k=0; k<=n-1; k++){
		for(int j=0; j<=3; j++){
			a[2*k][(4*k)+j] = pow( x[k] , (3-j) );
			a[(2*k)+1][(4*k)+j] = pow( x[k+1] , (3-j) );
		}
		b[2*k] = y[k];
		b[(2*k)+1] = y[k+1];
	}
	
	// filas de 2n a 3n-2
	for(int i=2*n; i<=(3*n)-2; i++){
		for(int k = 0; k<= n-2; k++){
			for(int j = 0; j<=2; j++){
				a[i][(4*k)+j] = (3-j) * pow( x[k+1] , (2-j) );
				a[i][(4*(k+1))+j] = - (3-j) * pow( x[k+1] , (2-j) );
			}
		}
		b[i] = 0;
	}
	
	//filas de 3n-1 a 4n-3
	for(int i=(3*n)-1; i<=(4*n)-3; i++){
		for(int k=0; k<=n-1; k++){
			a[i][4*k] = 6*x[k+1];
			a[i][(4*k)+1] = 2;
			a[i][4*(k+1)] = -6*x[k+1];
			a[i][(4*(k+1))+1] = -2;
		}
		b[i] = 0;
	}
	
	//ultimas 2 filas
	a[4*n-2][0] = 3*x[0];
	a[4*n-2][1] = 1;
	a[4*n-1][4*n-4] = 3*x[n];
	a[4*n-1][4*n-3] = 1;
	b[4*n-2] = 0;
	b[4*n-1] = 0;
	
	//imprimo matriz
	for(int i=0; i<4*n; i++){
		for(int j=0; j<4*n; j++){
			cout<<a[i][j]<<" ";
		}
		cout << " | " << b[i] <<endl;
	}
	
	
	
	//triangulacion superior
	double errorMinimo = 1e-9;
	double f;
	double aux;
	
	for(int i=0; i <= 4*n; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(a[i][i])<errorMinimo)
		{
			for(int j=i+1; j<=(4*n)-1; j++)
			{
				if(fabs(a[j][i])>errorMinimo)
				{
					for (int k=i;k<=(4*n)-1;k++)
					{
						aux=a[i][k];
						a[i][k]=a[j][k];
						a[j][k]=aux;			
					}
					aux=b[i];
					b[i]=b[j];
					b[j]=aux;
					cambio=1;
					break;
				}
			}
			if(cambio==0){
				cout << "El Sistema es singular! no se puede resolver" << endl;
				//return 0;
			}else
			   cout<< "Se hizo pivoteo ! "<<endl;
		}
		//***********************FIN PIVOTEO********************************
		for(int j=i+1; j <= 4*n; j++)
		{
			f=(-a[j][i])/(a[i][i]);
			for (int k=i; k <= 4*n; k++)
				a[j][k]=a[j][k]+f*a[i][k];
				b[j]=b[j]+f*b[i];
		} 
	}
	
	//imprimo matriz
	cout << endl << "Matriz de Triangular Superior" << endl;
	for(int i = 0; i<= 4*n; i++){
		for(int j = 0; j <= 4*n; j++){
			cout << a[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}
	
	
	//sustitucion regresiva
	double suma;
	double c[8]; //vector de soluciones. a[4n]. valor modificable segun el caso!!!******
	
	//valor de la ultima variable 
	c[n-1] = b[n-1] / a[n-1][n-1];
	cout << endl << "----- Soluciones -----" << endl;
	cout << endl << "a["<< n-1 << "]= " << c[n-1];
	
	for (int i=n-2; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=n-1; j++)
		{
			suma-=a[i][j]*c[j];
		} 
		c[i]=(suma)/a[i][i];
		cout << endl << "c["<< i << "]= " << c[i];
	}
	cout << endl;
	
	//Imprime el polinomio
	cout << "P = " ;
	for(int i=0,j=0;i<n;i++,j++)
	{
		if(j==0)
			cout << a[i] << " + ";
		else
			cout << a[i] << " " << "x^" << j << "+";
		
	}
	
	double valorX;
	double resultado = 0;
	//valua el polinomio en un x
	cout << "\n\nIngrese el valor de X : ";
	cin >> valorX;
	
	for(int i=0;i<n;i++)
	{
		resultado+= c[i] * pow(valorX,i);
	}
	cout << "El resultado es : " << resultado << endl;
	
	
	return 0;
}


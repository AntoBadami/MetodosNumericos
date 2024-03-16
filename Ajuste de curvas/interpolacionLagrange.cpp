#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	double xp=0, tol=0.000001;
	int n=3;//n valor modificable segun el caso*******
	double prod=0;
	double x[3]={0,60,100}, y[3]={1,4,10};
	double px;	/*COORDENADA X DE UN PAR [x,y]*/
	double py;	/*COORDENADA Y DE UN PAR [x,y]*/
	double m[3][3],b[3]; // [n] modificar valor!! ********
	double aux, f; 
	
	for(int i=0;i<=n-1;i++){ //Guardo la matriz 
		m[i][0] = 1.;
		for(int j=1;j<=n-1;j++){
			m[i][j] = pow(x[i],j);
		}
		b[i] = y[i];
	}
	
	//triangulacion superior
	for(int i=0; i < n-1; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(m[i][i])<tol)
		{
			for(int j=i+1; j<=n-1; j++)
			{
				if(fabs(m[j][i])>tol){
					for (int k=i;k<n-1;k++){
						aux=m[i][k];
						m[i][k]=m[j][k];
						m[j][k]=aux;			
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
				return 0;
			}
		}
		//fin pivoteo
		
		for(int j=i+1; j <= n-1; j++)
		{
			f=(-m[j][i])/(m[i][i]);
			for (int k=i; k <= n-1; k++)
				m[j][k]=m[j][k]+f*m[i][k];
				b[j]=b[j]+f*b[i];
		} 
	}
	
	//imprime la matriz triangulada
	cout << endl << "La Matriz triangular superior quedo: " << endl;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j < n; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}
	
	//sustitucion regresiva
	double suma;
	double a[3]; //vector de soluciones. a[n]. valor modificable segun el caso!!!******
	
	//valor de la ultima variable 
	a[n-1] = b[n-1] / m[n-1][n-1];
	cout << endl << "----- Soluciones -----" << endl;
	cout << endl << "a["<< n-1 << "]= " << a[n-1];
	
	for (int i=n-2; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=n-1; j++)
		{
			suma-=m[i][j]*a[j];
		} 
		a[i]=(suma)/m[i][i];
		cout << endl << "a["<< i << "]= " << a[i];
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
		resultado+= a[i] * pow(valorX,i);
	}
	cout << "El resultado es : " << resultado << endl;
	
	return 0;
}


#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n = 4;// n numero de filas
	double e = 1.0, suma =0;
	double  m[4][4] = 
	{2,-1, 3, -1,
		-1, -1, 3, 1,
		3, -4, -1, 1,
		1, 0, -2, 2};
	
	double b[4] = {5,10,-4,3};
	
	//verificar que a sea dd
	for(int i=0; i<n; i++){
		suma = 0;
		for(int j=0; n<n; j++){
			if(j!= 1){
				suma+=fabs(m[i][j]);
			}
		}
		if(fabs(m[i][i]) <= suma){
			cout<<"la matriz no es diagonalmente dominante"<<endl;
		}
		if(m[i][i]==0){
			cout<<"ceros en la diagonal"<<endl;
			exit(1);
		}
		
	}
	
	
	double f;
	int aux;
	float errorMinimo = 1e-10; //ACORDARSE DE CAMBIARLO!!!	
	
	//triangulacion superior
	for(int i=0; i < n-1; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(m[i][i])<errorMinimo)
		{
			for(int j=i+1; j<=n-1; j++)
			{
				if(fabs(m[j][i])>errorMinimo) //Error parecido a 0.
				{
					for (int k=i;k<=n-1;k++)
					{
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
			}else
			   cout<< "Se hizo pivoteo ! "<<endl;
		}
		//***********************FIN PIVOTEO********************************
		for(int j=i+1; j <= n-1; j++)
		{
			f=(-m[j][i])/(m[i][i]);
			for (int k=i; k <= n-1; k++) //k arranca desde la diagonal principal.. k=i.
				m[j][k]=m[j][k]+f*m[i][k];
				b[j]=b[j]+f*b[i];
		} 
		
	}
	
	//imprime la matriz como quedo!! 
	cout << endl << "La Matriz triangular superior quedo: " << endl;
	for(int i = 0; i<n; i++){
		for(int j = 0; j < n; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}
	
	double x[4]; //vector de soluciones //x[n] CAMBIAR SEGUN EL CASO!!!*******
	
	//valor de la ultima variable 
	x[n-1] = b[n-1] / m[n-1][n-1];
	
	for (int i=n-2; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=n-1; j++)
		{
			suma-=m[i][j]*x[j];
		} 
		x[i]=(suma)/m[i][i];
		e = sqrt(suma); 
	}
	cout << endl;
	
	cout << endl << "----- Soluciones -----" << endl;
	for(int i =0; i<=n-1; i++)
		cout << endl << "x["<< i+1 << "]= " << x[i];
	cout << endl;
	
	cout<<endl<<"error: "<<e<<endl;
	return 0;
}

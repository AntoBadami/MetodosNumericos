#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int n=10; // valor a modificar segun el caso!! (n numero de filas) numero de datos******
	int bandera=1; //bandera para validar los puntos
	int grado=0; // grado del polinomio deseado
	double x[10] = {0.2, 0.6, 0.8, 1.1, 1.5, 1.6, 2.1, 2.3, 2.5, 3.0};
	double y[10] = {2.71, 3.92, 4.79, 6.22, 8.48, 9.15, 13.4, 15.58, 18.17, 27.08};
	
	cout << endl <<"Regresion polinomica:" << endl;
	do{
		//Si es lineal ponemos 1 . Si no, ponemos mas.
		cout << "Ingrese el grado del polinomio deseado: " ;
		cin >> grado;
		
		if(n < grado+1){
			cout << endl <<"La regresion no es posible para el polinomio deseado";
			bandera=1;
		}
		else 
		   bandera=0;
	}while(bandera == 1);
	
	//Armo la matriz
	double m[3][3];//VALOR A MODIFICAR!! grado+1******
	double b[3];//VALOR A MODIFICAR!! grado+1*******
	double s; //suma 
	
	for(int i=0 ; i<=grado ; i++){
		for(int j=0 ; j<=grado ; j++){
			s=0;
			
			if(j==2||i==2){
				if(i==0&&j==2){
					for(int k=0 ; k<n ; k++)
						s = s + exp(x[k]);
				}else if(i==2&&j==0){
					for(int k=0 ; k<n ; k++)
						s = s + exp(x[k]);
				}else if(i==1&&j==2){
					for(int k=0 ; k<n ; k++)
						s = s + x[k] * exp(x[k]);
				}else if(i==2&&j==1){
					for(int k=0 ; k<n ; k++)
						s = s + x[k] * exp(x[k]);
				}else if(i==2&&j==2){
					for(int k=0 ; k<n ; k++)
						s = s + exp(x[k]*x[k]);
				}
				
			}else{
				for(int k=0 ; k<n ; k++)
					s = s + pow( x[k] , j+i );
			}
			m[i][j]=s;
		}
		s=0;		
		if(i==2){
			for(int k=0; k<n ; k++)
				s = s + (exp(x[k]) *y[k] );
		}else{
			for(int k=0; k<n ; k++)
				s = s + ( pow( x[k] , i )*y[k] ); 
		}
		b[i]=s;
	}
	
	//imprimo matriz
	cout << endl << "Matriz de Vandermonde" << endl;
	for(int i = 0; i<= grado; i++){
		for(int j = 0; j <= grado; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}
	
	//triangulacion superior
	double errorMinimo = 1e-9;
	double f;
	double aux;
	for(int i=0; i <= grado; i++)
	{
		//pivoteo
		int cambio =0;
		if (fabs(m[i][i])<errorMinimo)
		{
			for(int j=i+1; j<=grado-1; j++)
			{
				if(fabs(m[j][i])>errorMinimo)
				{
					for (int k=i;k<=grado-1;k++)
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
		for(int j=i+1; j <= grado; j++)
		{
			f=(-m[j][i])/(m[i][i]);
			for (int k=i; k <= grado; k++)
				m[j][k]=m[j][k]+f*m[i][k];
				b[j]=b[j]+f*b[i];
		} 
	}
	
	//imprimo matriz
	cout << endl << "Matriz de Triangular Superior" << endl;
	for(int i = 0; i<= grado; i++){
		for(int j = 0; j <= grado; j++){
			cout << m[i][j] << " ";		
		}
		cout << " ---> " << b[i] ;
		cout << endl;
	}
	
	//sustitucion regresiva
	double suma;
	double a[3]; //vector de soluciones //VALOR A MODIFICAR!! grado+1*****
	
	//valor de la ultima variable 
	a[grado] = b[grado] / m[grado][grado];
	
	for (int i=grado-1; i>=0; i--)
	{
		suma = b[i];
		for(int j=i+1; j<=grado; j++)
			suma-=m[i][j]*a[j];
			a[i]=(suma)/m[i][i];
	}
	
	for(int i=0; i<=grado; i++)
		cout << endl << "a["<< i << "]= " << a[i];
	
	cout << endl << endl;
	
	//imprimo el polinomio
	cout << "POLINOMIO" << endl;
	int exponente=0;
	for(int i=0; i<=grado; i++)
	{
		if(exponente==0)
			cout << a[i];
		else{
			if(a[i]>=0)
				cout << " + " << a[i] << " " << "X^" << exponente << " ";
			else
				cout << a[i] << " " << "X^" << exponente << " ";
		}
		exponente++;
	}
	
	cout << endl << endl;
	
	//Validaciones!!
	double syx;	//desviacion estandar-(error estandar estimado)
	double sr;	//error, residuo - (suma de los cuadrados de los residuos)
	double st;	//error medio- (suma total de los cuadrados)
	double r2;	//coeficiente de determinacion
	double r;	//coeficiente de correlacion
	double ymedia;	//media de y
	
	//calculo de media de y
	ymedia=0;	
	for(int i=0; i<n; i++)
		ymedia = ymedia + y[i];
	ymedia = ymedia / n;	
	
	//calculo del error medio
	st=0;
	for(int i=0; i<n; i++)
		st=st + pow( x[i]-ymedia ,2);	
	
	//calculo del error-residuo
	sr=0;	
	for(int i=0; i<n; i++){
		s=0;	
		for(int j=0; j<=grado; j++){
			s = s + ( a[j] * pow( x[i] ,j) );
		}
		sr=sr + pow((y[i]-s),2);
	}
	
	//calculo del error estandar estimado (desviacion estandar)
	syx = sqrt( sr / ( (double)n-(grado+1) ) );
	
	
	//calculo del coeficiente de determinacion
	r2=(st-sr)/st;
	
	
	//calculo del coeficiente de correlacion
	r=sqrt(r2);
	
	//Impresion de los resultados!!!
	cout << endl << "Error/Residuo (suma de cuadrados de los residuos): " << sr ;
	cout << endl << "Desviacion estandar (Error estandar estimado): " << syx;
	cout << endl << "Error medio (suma total de cuadrados): " << st;
	cout << endl << "Coeficiente de determinacion: " << r2;
	cout << endl << "Coeficiente de correlacion: " << r;
	
	cout << endl << endl;
	return 0;
}

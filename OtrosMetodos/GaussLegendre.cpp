#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double f(double);

int main(){
	double a,b,integral,valuar,c[6],x[6];
	int opcion=0;
	printf("Ingrese a y b\n");
	scanf("%lf",&a);
	scanf("%lf",&b);
	while(opcion!=1){
		valuar=0;
		printf("Ingrese la cantidad de puntos por los cuales quiere calcular\n");
		scanf("%d",&opcion);
		switch(opcion){
		case 1:
			printf("Adios.\n");
			break;
		case 2:
			x[0]=-1/sqrt(3);
			x[1]=1/sqrt(3);
			c[0]=1;
			c[1]=1;
			for(int i=0;i<opcion;i++){
				valuar=valuar+c[i]*f(((b-a)*x[i]+a+b)/2);
			}
			valuar=valuar*(b-a)/2;
			printf("La integral es %lf\n",valuar);
			break;
		case 3:
			x[0]=-0.774596669;
			c[0]=0.5555556;
			x[1]=0;
			c[1]=0.8888889;
			x[2]=0.774596669;
			c[2]=0.5555556;
			for(int i=0;i<opcion;i++){
				valuar=valuar+c[i]*f(((b-a)*x[i]+a+b)/2);
			}
			valuar=valuar*(b-a)/2;
			printf("La integral es %lf\n",valuar);
			break;
		case 4:
			x[0]=-0.861136312;
			c[0]=0.3478548;
			x[1]=-0.339981044;
			c[1]=0.6521452;
			x[2]=0.339981044;
			c[2]=0.6521452;
			x[3]=0.861136312;
			c[3]=0.3478548;
			for(int i=0;i<opcion;i++){
				valuar=valuar+c[i]*f(((b-a)*x[i]+a+b)/2);
			}
			valuar=valuar*(b-a)/2;
			printf("La integral es %lf\n",valuar);
			break;
		case 5:
			x[0]=-0.906179846;
			c[0]=0.2369269;
			x[1]=-0.538469310;
			c[1]=0.4786287;
			x[2]=0;
			c[2]=0.5688889;
			c[3]=0.4786287;
			x[3]=0.538469310;
			x[4]=0.906179846;
			c[4]=0.2369269;
			for(int i=0;i<opcion;i++){
				valuar=valuar+c[i]*f(((b-a)*x[i]+a+b)/2);
			}
			valuar=valuar*(b-a)/2;
			printf("La integral es %lf\n",valuar);
			break;
		case 6:
			x[0]=-0.932469514;
			c[0]=0.1713245;
			x[1]=-0.661209386;
			c[1]=0.3607616;
			x[2]=-0.238619186;
			c[2]=0.4679139;
			x[3]=0.238619186;
			c[3]=0.4679139;
			x[4]=0.661209386;
			c[4]=0.3607616;
			x[5]=0.932469514;
			c[5]=0.1713245;
			for(int i=0;i<opcion;i++){
				valuar=valuar+c[i]*f(((b-a)*x[i]+a+b)/2);
			}
			valuar=valuar*(b-a)/2;
			printf("La integral es %lf\n",valuar);
			break;
		default:
			printf("Opcion no valida\n");
			break;
		}
	}
	
	return 0;
}
	double f(double x){
		return pow(sin(x),2)*log(x);
	}
		

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define INFINITO 99999
using namespace std;
long numerador,denominador;
long a1,b1,c1,d1,a2,b2,c2,d2;
long GCD(int a,int b)
{
	if(b==0)
		return a;
	else 
		return GCD(b,a%b);
}
void reducir()
{
	long gcd=GCD(numerador,denominador);
	numerador /=gcd;
	denominador /=gcd;
}
bool busca_solucion_theta()
{ 
	if(d1<0)
		d1=360*(long)ceil(d1/-360.0)+d1;
	else 
		d1=d1%360;
	if(d2<0)
		d2=360*(long)ceil(d2/-360.0)+d2;
	else 
		d2=d2%360;
	numerador=d2-d1;
	denominador=c1-c2;
	if(denominador<0)
	{
		numerador*=-1;
		denominador*=-1;
	}
	if(numerador<0)
		numerador=360*(long)ceil(numerador/-360.0)+numerador;
	if(denominador==0)
	{
		if(numerador==0)
			denominador=1;
		else 
			return false;
	}
	else if(numerador==0)
		denominador=1;
	else 
		reducir();
	return true;
}
void obtener_solucion()
{
	bool ok=true;
	numerador=b2-b1;
	denominador=a1-a2;
	if(denominador==0)
	{
		if(numerador==0)
			ok=busca_solucion_theta();
		else
			ok=false;
	}
	else if(numerador*denominador>=0)
	{
		if(numerador==0)
			denominador=1;
		else
		{
			numerador= labs(numerador);
			denominador= labs(denominador);
			reducir(); 
		}
		if(ok)
		{ 
			long th1=c1*numerador+d1*denominador;
			long th2=c2*numerador+d2*denominador;
			ok=(a1*numerador+b1*denominador==0)||((th1-th2)%(360*denominador)==0);
			
		}
	}
	else 
		ok=false;
	if(!ok)
	{
		numerador=INFINITO;
		denominador=1;
	}
}
int main()
{
	long num1,num2,den1,den2;
	while((cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2)&&(a1||b1||c1||d1||a2||b2||c2||d2))
	{
		obtener_solucion();
		num1=numerador;
		den1=denominador;
		a2*=-1;
		b2*=-1;
		d2+=180;
		obtener_solucion();
		num2=numerador;
		den2=denominador;
		if(num1==INFINITO&&num2==INFINITO)
			printf("0 0\n");
		else if(num1*den2>num2*den1)
			printf("%ld %ld\n",num2,den2);
		else 
			printf("%ld %ld\n",num1,den1);
	}
	return 0;
}

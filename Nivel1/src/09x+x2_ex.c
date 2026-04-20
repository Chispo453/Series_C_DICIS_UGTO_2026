/**
 * ── NIVEL 1 ── 
 * @file 9x+x2_ex.c
 * @brief Aproximación de (x + x^2)e^x mediante serie de Maclaurin.
 *
 * @details
 * Serie: x + (4*x^2)/2! + (9*x^3)/3! + (16*x^4)/4! + ... + (i^2 * x^i)/i!
 * Este programa utiliza un enfoque de fuerza bruta con tres ciclos para 
 * calcular cada componente del término general por separado.
 *
 * @par Entrada: Entero n (términos) y flotante x (valor a evaluar).
 * 
 * @par Salida
 *
 * Imprime:
 * @code
 * (x + x^2)e^x   = valor
 * (x + x^2)e^x   = valor
 * error absoluto = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Debido al término i^2 en el numerador y al uso de float 
 * la serie se vuelve inestable para x > 1 o n > 32.
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
	int n, i, j;
	float x, e, num, den, t;

	do{
	   printf("Indique el numero de terminos:");
	   scanf("%d", &n);
	}while(n<=0); 

	printf("Ingrese el valor de x:");
	scanf("%f", &x);

	/*Ciclo externo para la suma*/

	for(i=1, e=0; i<n+1; i++)
	{
		/*para cálculo de x^i*/

	    /*Primer ciclo interno: O(n).*/
	   for(j=0, num=1; j<i; j++) 
	       num *= x;
	   /* Segundo ciclo interno: O(n). Calcula i! */
       /* Al estar separado del anterior, sus complejidades se suman, no se multiplican */

	     /*para cálculo de i!*/
	   for(j=1, den=1; j<i+1; j++)
	       den *= j ;
	   
	   t = (i*i*num)/ den; /* i*i puede causar overflow con enteros, por eso se uso float*/
	   e+=t;
	}

	printf("\nResultados para n = %d terminos:\n", n);
	printf("(x + x^2 )e^x aproximado = %.7f  \n",  e);
	printf("(x + x^2 )e^x real math.h = %.7f \n", (x+x*x)*exp(x));
	printf("Error absoluto =  %.7e \n", fabs(e - (x+x*x)*exp(x)));

	return 0;
}
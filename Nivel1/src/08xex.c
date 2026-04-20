/** 
 *── NIVEL 1 ── 
 * @file 8xex.c
 * @brief Aproximación de la función f(x) = xe^x.
 *
 * @details
 * Serie de Maclaurin: x + (2*x^2)/2! + (3*x^3)/3! + ... + (i*x^i)/i!
 * Calcula cada término desde cero usando ciclos anidados.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @par Observacion
 * El uso de float limita la estabilidad. Al separar el 
 * numerador (num) y el denominador (den), el programa llegará a un
 * límite de overflow cuando den (i!) supere 3.4e38 (aprox. n=34).
 *
 * @warning
 * Para valores de x grandes o n > 34, los resultados pueden ser inf o NaN.
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
	int n, i, j;
	float x, xex, num, den, t;

    /*Validación*/
	do{
	   printf("Indique el numero de terminos:");
	   scanf("%d", &n);
	}while(n<=0);

	printf("Ingrese el valor de x:");
	scanf("%f", &x);

	/*Ciclo para la suma de la serie*/

	for(i=1, xex=0; i<n+1; i++)
	{
		/*Ciclo para calcular cada termino*/
	
	   for(j=0, num=1, den=1; j<i; j++) 
	   {
	  	num *= x;       /*x^i*/
	   	den *= (j+1) ;  /*i!*/
	   }
	   t = i*(num / den);
	   xex+=t;

	}

	printf("\nResultados para n = %d terminos:\n", n);
	printf("%fe^%.4f aproximado = %.7f  \n", x, x, xex);
	printf("%fe^%.4f real math.h = %.7f \n", x, x, x*exp(x));
	printf("Error absoluto =  %.7e \n", fabs(xex - x*exp(x)));

	return 0;
}	
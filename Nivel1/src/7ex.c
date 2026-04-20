 /**
 *  ── NIVEL 1 ── 
 * @file 7ex.c
 * @brief Aproximación de e^x mediante la serie de Taylor.
 *
 * @details
 * Serie: e^x = 1 + x + x^2/2! + x^3/3! + ... + x^(n-1)/(n-1)!
 * Este programa utiliza ciclos anidados.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @par Limitaciones de Dominio (Análisis LIDIA)
 * Debido al uso de float y el cálculo separado de x^i e i!, el programa 
 * es inestable para valores de x > 2 o n grandes. 
 * Recomendación de prueba: x = {0.5, 1, 2} con n <= 128.
 *
 * @warning
 * Para n=256, el denominador (i!) excede la capacidad del float (Overflow),
 * resultando en valores 'inf' o 'NaN'. Este problema se corregirá en el 
 * Nivel 2 usando double.
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
	int n, i, j;
	float x, ex, num, den, t;  /*tipo float*/
 
	do{
	   printf("Indique el numero de terminos:");
	   scanf("%d", &n);
	}while (n<=0);

	printf("Ingrese el valor de x:");
	scanf("%f", &x);

	/*Ciclo externo para la suma de la serie*/

	for(i=0, ex=0; i<n; i++)
	{
		num=1;   /*x^0 = 1*/
		den=1;   /* 0! = 1*/

		/*Ciclo inetrno calcula x^i e i!*/
	   for(j=0; j<i; j++) 
	   {
	   	num *= x;
	   	den *= (j+1) ;
	   }
	   t = (num / den);  /* falla si den llega a infinito*/
	   ex+=t;
	}

	printf("\n Resultados para n = %d terminos:\n", n);
	printf("e^%.4f aproximado =  %.7f \n", x, ex);
	printf("e^%.4f real math.h = %.7f \n", x, exp(x));
	printf("Error absoluto =  %.4e \n", fabs(ex - exp(x)));

	return 0;
}  
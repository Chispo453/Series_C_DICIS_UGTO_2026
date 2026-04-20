/**
 *  ── NIVEL 1 ── 
 * @file 11_1_2lnu.c
 * @brief Aproximación de 1/2 * ln((1+x)/(1-x)) mediante serie de potencias.
 *
 * @details
 * Serie: x + x^3/3 + x^5/5 + x^7/7 + ...
 *
 * @par Entrada
 *  Entero n >= 1 (términos de la serie).
 *  Real x en el dominio  (-1, 1).
 *
 * @par Salida
 * Valor aproximado, referencia calculada con log() de math.h y error absoluto.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * El valor x = 1 o x = -1 producirá una división por cero en la función 
 * de referencia real, por lo que el dominio está restringido a (-1, 1).
 */


#include <stdio.h>
#include <math.h> 
/*uso de math.h para la comparación*/

int main(int argc, char *argv[])
{
	/*n: numero terminos, i: contador,  */

	int n, i;
	float num, den, x, j, ln, k;


	/*Validacion de cantidad de términos*/

	do{
		printf("Indique el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);

	/*Validacion de dominio para evitar asintotas división por 0 */

	do{
	   printf("Indique el valor de x (-1 < x <= 1):");
	   scanf("%f", &x);
	}while(-1>=x || x>=1); /*para -1<x<1*/


    for(i=1, ln=0, k=0; i<n+1; i++)
    {
    	den = 2*i-1;

    	/*Cálcula potencia de x^(2*i-1)*/

    	for(j=0, num=1; j<(2*i-1); j++) /* x ^(2i-1) */
	       num *= x;
	    k = num/den; /*termino i-ésimo*/
    	ln += k;   /* acumulador */   
    }
    

    printf("\nResultados para n = %d terminos:\n", n);
    printf("1/2 ln(1+x/1-x) aproximado = %.7f\n", ln);   /* 7 dígitos por precisión,por ser tipo float */
    printf("1/2 ln(1+x/1-x) real (math.h) = %.7f\n", 0.5*log((1+x)/(1-x))); 
    printf("Error absoluto = %.4e\n", fabs(ln - 0.5*log((1+x)/(1-x))));   /* comparacion con log  */

	return 0;
}
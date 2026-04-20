/**
 *  ── NIVEL 1 ── 
 * @file 13lnx.c
 * @brief Aproximación de ln(x) usando la variable u = (x-1)/x.
 *
 * @details
 *  Serie:
 *  ln(x) = u + u^2/2 + u^3/3 + ...  (para n terminos)
 * Donde u = (x-1)/x. Esta serie es una alternativa para calcular logaritmos
 * enfocándose en valores de x >= 0.5.
 *
 * @par Entrada
 *  Entero n >= 1 (términos de la serie).
 *  Real x > = 1/2 (valor para calcular el logaritmo).
 *
 * @par Salida
 * Valor de ln(x) aproximado, valor de referencia de math.h y error absoluto.
 *
 * @par Complejidad
 * Tiempo: O(n^2), debido al ciclo par acálcular las potencias en cada iteracion.
 * Memoria: O(1).
 *
 * @warning
 * En la serie el error crece al infinito si x < 0.5. 
 * El uso de float provoca errores de precisión acumulados para n grandes.
 */



#include <stdio.h>
#include <math.h> 


int main(int argc, char *argv[])
{
	
	int n, i;
	float num, den, x, j, u, ln, k;

    /* Validamos n y x */
	do{
		printf("Indique el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);

	do{
	   printf("Indique el valor de x (x>0):");
	   scanf("%f", &x);
	}while(x<0.5); /*dominio x>=1/2 */

	u = (x-1)/ x;
    for(i=1, ln=0, k=0; i<n+1; i++)
    {
    	den = i;
    	/* ciclo para u^i */
    	for(j=0, num=1; j<i; j++) 
	       num *= u;
	    k = num/den; /*sumatoria*/
    	ln += k;   /* acumulador */   
    }

    printf("\nResultados para n = %d terminos:\n", n);
    printf(" ln(x) aproximado = %.7f\n", ln);   /* 7 dígitos por precisión,por ser tipo float */
    printf(" ln(x) real (math.h) = %.7f\n", log(x)); 
    printf("Error absoluto = %.4e\n", fabs(ln - log(x)));   

	return 0;
}
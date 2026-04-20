/**
 *  ── NIVEL 1 ── 
 * @file 12lnx.c
 * @brief Aproximación de ln(x) usando la variable u = (x-1)/(x+1).
 *
 * @details
 * Serie: 
 *  ln(x) = 2 * [ u + u^3/3 + u^5/5 + ... + u^(2i-1)/(2i-1) ]
 *
 * @par Entrada
 *  Entero n >= 1 (términos de la serie).
 *  Real x > 0 (valor al que se le desea calcular el logaritmo).
 *
 * @par Salida
 * Valor de ln(x) aproximado, valor real de math.h y error absoluto.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * El uso de float limita la precisión conforme n aumenta. Aunque el 
 * dominio matemático es x > 0, valores extremadamente grandes o pequeños 
 * de x pueden presentar errores de redondeo debido al cálculo de u.
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
	}while(x<=0); /*dominio x>0 */

	u = (x-1)/(x+1);
    for(i=1, ln=0, k=0; i<n+1; i++)
    {
    	den = 2*i-1;
    	for(j=0, num=1; j<(2*i-1); j++) /* ciclo para u ^(2i-1) */
	       num *= u;
	    k = num/den; /*sumatoria*/
    	ln += k;   /* acumulador */   
    }
    ln = 2*ln;

    printf("\nResultados para n = %d terminos:\n", n);
    printf(" ln(x) aproximado = %.7f\n", ln);   /* 7 dígitos por precisión,por ser tipo float */
    printf(" ln(x) real (math.h) = %.7f\n", log(x)); 
    printf("Error absoluto = %.4e\n", fabs(ln - log(x)));   

	return 0;
}
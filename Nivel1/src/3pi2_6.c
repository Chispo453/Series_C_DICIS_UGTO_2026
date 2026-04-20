/**
 *  ── NIVEL 1 ── 
 * @file 3pi2_6.c
 * 
 * @brief Aproximacion mediante la serie Basilea
 *
 * @details
 *  Serie de Basilea: 
 * pi^2/6 = 1 + 1/2^2 + 1/3^2 + 1/4^2 + ... = sum_{i=1}^{inf} (1/i^2) = pi^2 / 6
 * Termino i: (1/i*i)
 * 
 * @par Entrada
 *  Numero entero n >=1 (número de términos, iteraciones del ciclo)
 * 
 * @par Salida
 *  Calcula el valor aproximado de pi, el valor de referencia de math.h y error absoluto en notación científica.
 *
 * @par Complejidad
 *  Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 *  Aunque converge más rápido que Leibniz, el límite de precisión esta dictado por el tipo float.
 *
 */

#include <stdio.h>
#include <math.h> 
/*uso de math.h para la comparación*/

int main(int argc, char *argv[])
{
	/* n: numero de terminos, i: contador */
    /* den: denominador */
    /* k: acumulador de pi^2/6, pi_aprox: pi resultado final */

	int n, i;
	float  j, pi_aprox, k, den;
	do{
		printf("Indique el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);


    for(i=1, k=0.0; i<n+1; i++)
    {
    	den = i*i; /* i cuadrada */
    	j = (1.0/den);   /* j junta el termino con el denominador */
    	k += j;   /* acumulador de pi^2 / 6 */   
    }
    pi_aprox= sqrt(6.0*k);   /* sqrt(pi/6 * 6) = pi */

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7f\n", pi_aprox);   /* 7 dígitos, precisión */
    printf("pi real (math.h) = %.7f\n", M_PI ); 
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI ));   /* comparacion y uso de %.4e para notacion cientifica*/

	return 0;
}
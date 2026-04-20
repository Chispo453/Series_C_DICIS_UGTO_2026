/**
 * ── NIVEL 1 ── 
 * @file 2pi_4.c
 *
 * @brief Aproximacion de pi mediante la serie Leibniz
 * 
 * @details
 * Serie de Leibniz: 
 * pi/4 = 1 - 1/3 + 1/5 - 1/7 + ... = sum_{i=1}^{inf} (-1)^(i+1) /(2i-1)
 * 
 * Aproximacion para pi con n terminos:
 * Termino i: signo * (1/i), i aumenta de 2 en 2, 
 * tomando impares
 * multiplica al final por 4 para obtener pi 
 * 
 * @par Entrada
 *  Numero entero n >=1 (numero de terminos)
 *
 * @par Salida
 *  Imprime pi aproimado, valor de referencia (math.h) y error absoluto.
 *
 * @par Complejidad
 *  Tiempo: O(n). Memoria: O(1).
 * 
 * @warning
 *
 *  La serie es Leibniz converge muy lentamente 
 *  comparada con otras series para pi. 
 *  Se necesitan muchos terminos para pocos decimales 
 */

#include <stdio.h>
#include <math.h> 
/*uso de math.h para la comparación*/

int main(int argc, char *argv[])
{
	/* n: numero de terminos, i: contador */
    /* sig: signo (+1, -1), den: denominador 1,3,5,... */
    /* k: acumulador de pi/4, pi_aprox: pi resultado final */

	int n, i, sig;
	float j, pi_aprox, k, den;
	do{
		printf("Indique el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);


    for(i=1, k=0.0; i<n+1; i++)
    {
    	den = 2*i-1; /* crea el aumento de 2 en 2 */
    	sig = -1*(1-2*(i%2));  /* +1 o -1 alternando */
    	j = sig*(1.0/den);   /* j junta el termino con el cambio para el denominador y el signo */
    	k += j;   /* acumulador de pi/4 */   
    }
    pi_aprox= 4.0*k;   /* pi/4 * 4 = pi */

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7f\n", pi_aprox);   
    printf("pi real (math.h) = %.7f\n", M_PI ); 
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI ));   /* float absolute fabs comparacion y e para notacion cientifica*/

	return 0;
}
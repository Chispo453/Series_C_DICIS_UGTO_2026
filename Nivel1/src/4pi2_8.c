/**
 * ── NIVEL 1 ── 
 * @file 4pi2_8.c
 * @brief Aproximacion mediante pi^2/8 
 *  Suma de inversos de impares al cuadrado.
 *
 * @details
 *  Serie: 
 *  pi^2/8 = 1 + 1/3^2 + 1/5^2 + 1/7^2 + ... = sum_{i=1}^{inf} [1 / (2i-1)^2]
 * Para obtener pi, se despeja de la suma acumulada de k
 *
 * pi = sqrt(k*8)
 *
 * @par Entrada
 *  Numero entero n >=1 (número de términos impares a sumar)
 *
 * @par Salida
 *   Calcula el valor aproximado de pi, el valor de referencia de math.h
 *   y el error absoluto en notación científica.
 *
 * @par Complejidad
 * Tiempo: O(n), un solo ciclo procesa n términos.
 * Memoria: O(1), Acumuladores y contadores.
 *
 * @warning
 *  Al igual que en la serie de Basilea, el error disminuye de forma cuadrática.
 *  Es más eficiente que Leibniz (pi/4), logrando mayor precisión
 *  con el mismo número de iteraciones.
 *
 */

#include <stdio.h>
#include <math.h> 
/*uso de math.h para la comparación*/

int main(int argc, char *argv[])
{
	/* n: numero de terminos, i: contador */
    /* k: acumulador de pi^2/8, pi_aprox: pi resultado final */

	int n, i;
	float d, den, j, pi_aprox, k;
	do{
		printf("Indique el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);


    for(i=1, k=0.0; i<n+1; i++)
    {
    	d = (2.0*i-1.0); /*d: denominador 1,3,5,...*/
    	den = d*d;   /* denominador al cuadrado*/
    	j = (1.0/den);   /* j junta el termino con el denominador */
    	k += j;   /* guarda pi^2 / 8 */   
    }
    pi_aprox= sqrt(8*k);   /* sqrt(pi^2/8 * 8) = pi */

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7f\n", pi_aprox);   /* precisión 7 dígitos */
    printf("pi real (math.h) = %.7f\n", M_PI ); 
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI ));   /* uso de notacion cientifica*/

	return 0;
}
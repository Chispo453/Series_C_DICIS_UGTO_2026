/**
 *  ── NIVEL 1 ── 
 * @file 1ln2.c
 * 
 * @brief Aproximacion de ln(2) con la serie alternante.
 *
 *@details
 *
 * Serie:ln(2)= 1 - 1/2 + 1/3 - 1/4 + ... 
 *   sum_{i=1}^{inf} (-1)^(i+1) / i
 *
 * Terminos de i: signo * (1/i), i va de 1 a n y el signo alterna +1,-1,+1,...
 *
 * @par Entrada
 *	Numero entero n >= 1 (numero de terminos).
 *
 *@par Salida
 * Imprime ln(2) aproximado, valor de referencia (math.h) y error absoluto.
 *
 *@par Complejidad
 * Tiempo: O(n), ya que realiza una sola pasada de n iteraciones.
 * Memoria: O(1), el uso de la memoria es constante.
 *
 *@warning
 * La serie converge lentamente.
 * Para buena precision se necesitan muchos terminos n. 
 * El acumulador k puede perder precisión con n grande. 
 */

#include <stdio.h>
#include <math.h> 
/*uso de math.h para la comparación*/

int main(int argc, char *argv[])
{
	/*s: signo, el numerador no cambia, n: numero terminos, i: contador */

	int n, i, s;
	float j, ln2, k=0;
	do{
		printf("Indique el numero de terminos: ");
		scanf("%d", &n);
	}while(n<=0);


    for(i=1; i<n+1; i++)
    {
    	s = -1*(1-2*(i%2));  /* +1 o -1 alternando */
    	j = s*(1.0/i);   /* j junta el termino y el signo */
    	k += j;   /* acumulador */   
    }
    ln2=k;

    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(2) aproximado = %.7f\n", ln2);   /* 7 dígitos por precisión,por ser tipo float */
    printf("ln(2) real (math.h) = %.7f\n", log(2)); 
    printf("Error absoluto = %.4e\n", fabs(ln2 - log(2)));   /* comparacion con log 2 */

	return 0;
}
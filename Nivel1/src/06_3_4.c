/**
 *  ── NIVEL 1 ── 
 * @file 6_3_4.c
 * @brief Aproximación de 3/4 mediante serie telescópica.
 *
 * @details
 * Serie: 3/4 = 1/(1*3) + 1/(2*4) + 1/(3*5) + ... + 1/(i*(i+2))
 * Esta serie es un ejemplo de suma telescópica donde la mayoría 
 * de los términos se cancelan, dejando una suma finita de 0.75.
 *
 * @par Entrada
 * Un número entero n >= 1 que representa la cantidad de términos.
 *
 * @par Salida
 *  Impri
 * @code
 * suma= valor
 * referencia = 0.750000
 * error absoluto = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Al usar el tipo 'float', la precisión se limita a los primeros 7 decimales.
 * Con n=1000, el error absoluto es del orden de 9.98e-4.
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n, i, d1, d2;   /* d1, d2 = los dos factores del denominador */
    float suma;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (i = 1, suma = 0; i <= n; i++) {
        d1 = i;       /* primer factor del denominador */
        d2 = i + 2;      /* segundo factor del denominador */
        suma += 1.0 / (d1 * d2); /*guarda numerador y multiplicacion de denominadores para la suma*/
    }

    printf("\n Aproximacion para n = %d terminos: \n", n );
    printf("Suma = %f\n", suma);
    printf("Referencia  = 0.750000\n");
    printf("Error absoluto: %.4e\n", fabs(suma - 0.750000));
    return 0;
}
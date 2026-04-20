/**
 * ── NIVEL 3 ──
 * @file 2pi_4_N3.c
 * @brief Aproximacion de pi con serie de Leibniz por recurrencia O(n).
 *
 * @details
 * Serie: pi/4 = sum_{i=1}^{n} (-1)^(i+1) / (2i-1)
 *
 * Recurrencia del termino con signo:
 *   ter_1     = 1    (i=1: +1/1)
 *   ter_{i+1} = -ter_i * (2i-1) / (2i+1)
 *
 * Derivacion:
 *   ter_i     = (-1)^(i+1) / (2i-1)
 *   ter_{i+1} = (-1)^(i+2) / (2i+1)
 *    = -ter_i * (2i-1)/(2i+1)
 *
 * Evita calcular el signo con modulo y el denominador desde cero.
 *
 * @par Entrada
 * @param n  Entero >= 1.
 *
 * @par Salida
 * @code
 * pi aproximado     = valor
 * pi real           = valor
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * La convergencia lenta es intrinseca a Leibniz.
 * Para mejor convergencia usar series de Machin o Ramanujan.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double k, k_prev, ter, pi_aprox, pi_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    for (i = 1, k = 0.0, ter = 1.0; i <= n; i++) {
        k += ter;
        ter *= -(double)(2 * i - 1) / (double)(2 * i + 1);
    }
    pi_aprox = 4.0 * k;

    /* Serie con n/2 terminos para Delta_n */
    if (n >= 2) {
        for (i = 1, k_prev = 0.0, ter = 1.0; i <= n / 2; i++) {
            k_prev += ter;
            ter*= -(double)(2 * i - 1) / (double)(2 * i + 1);
        }
        pi_prev = 4.0 * k_prev;
    } else {
        pi_prev = 0.0;
    }

    delta = fabs(pi_aprox - pi_prev);
    nea   = delta / (fabs(pi_aprox) > eps ? fabs(pi_aprox) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7lf\n", pi_aprox);
    printf("pi real = %.7lf\n", M_PI);
    printf("Delta_n = %.4e\n", delta);
    printf("nea (error aprox) = %.4e\n",  nea);
    printf("Error absoluto = %.4e\n",  fabs(pi_aprox - M_PI));

    return 0;
}
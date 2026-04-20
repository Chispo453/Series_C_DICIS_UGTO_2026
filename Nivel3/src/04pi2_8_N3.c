/**
 * ── NIVEL 3 ──
 * @file 4pi2_8_N3.c
 * @brief Aproximacion de pi con serie pi^2/8 por recurrencia O(n).
 *
 * @details
 * Serie: pi^2/8 = sum_{i=1}^{n} 1/(2i-1)^2
 *
 * Recurrencia del termino:
 *   ter_1     = 1    (i=1: 1/1^2)
 *   ter_{i+1} = ter_i * (2i-1)^2 / (2i+1)^2
 *
 * Derivacion:
 *   ter_i     = 1/(2i-1)^2
 *   ter_{i+1} = 1/(2i+1)^2
 *   =ter_i * (2i-1)^2/(2i+1)^2
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
 * Comparado con pi^2/6, esta serie suma solo los terminos impares
 * pero tiene velocidad de convergencia similar O(1/n^2) en la suma,
 * lo que la hace mas eficiente que Leibniz O(1/n).
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double d1, d2, k, k_prev, ter, pi_aprox, pi_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    /* ── Serie con n terminos por recurrencia ── */
    for (i = 1, k = 0.0, ter = 1.0; i <= n; i++) {
        k+= ter;
        d1 = (double)(2 * i - 1);
        d2 = (double)(2 * i + 1);
        ter *= (d1 * d1) / (d2 * d2);
    }
    pi_aprox = sqrt(8.0 * k);

    /* Delta_n */
    if (n >= 2) {
        for (i = 1, k_prev = 0.0, ter = 1.0; i <= n / 2; i++) {
            k_prev += ter;
            d1 = (double)(2 * i - 1);
            d2 = (double)(2 * i + 1);
            ter *= (d1 * d1) / (d2 * d2);
        }
        pi_prev = sqrt(8.0 * k_prev);
    } else {
        pi_prev = 0.0;
    }

    delta = fabs(pi_aprox - pi_prev);
    nea   = delta / (fabs(pi_aprox) > eps ? fabs(pi_aprox) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7lf\n", pi_aprox);
    printf("pi real = %.7lf\n", M_PI);
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox) = %.4e\n", nea);
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI));

    return 0;
}
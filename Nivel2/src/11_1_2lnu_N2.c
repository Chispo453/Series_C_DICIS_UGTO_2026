/**
 * ── NIVEL 2 ──
 * @file 11_1_2lnu_N2.c
 * @brief Aproximacion de 1/2*ln((1+x)/(1-x)) mediante serie de potencias (estabilizada).
 *
 * @details
 * Serie: 1/2*ln((1+x)/(1-x)) = x + x^3/3 + x^5/5 + x^7/7 + ...
 * = sum_{i=1}^{n} x^(2i-1) / (2i-1)
 *
 * Implementacion O(n^2):
 * El interno calcula x^(2i-1) desde cero multiplicando x en cada paso.
 *
 * @par Entrada
 * Entero n >= 1. Real x con dominio -1 < x < 1.
 *
 * @par Salida
 * @code
 * 1/2 ln((1+x)/(1-x)) aproximado = valor
 * 1/2 ln((1+x)/(1-x)) real       = valor
 * Delta_n                         = valor
 * nea                             = valor
 * Error absoluto                  = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * x = +-1 causa division por cero en la referencia 0.5*log((1+x)/(1-x)).
 * Dominio estricto: -1 < x < 1.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, ln, ln_prev, num, den, k, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Indique el valor de x (-1 < x < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= -1.0 || x >= 1.0);

    
    for (i = 1, ln = 0.0; i <= n; i++) {
        den = (double)(2 * i - 1);
        num = 1.0;
        for (j = 0; j < (2 * i - 1); j++)
            num *= x;
        k   = num / den;
        ln += k;
    }

    /* Serie con n/2 terminos, para Delta_n */
    if (n >= 2) {
        for (i = 1, ln_prev = 0.0; i <= n / 2; i++) {
            den = (double)(2 * i - 1);
            num = 1.0;
            for (j = 0; j < (2 * i - 1); j++)
                num *= x;
            ln_prev += num / den;
        }
    } else {
        ln_prev = 0.0;
    }

    delta = fabs(ln - ln_prev);
    nea   = delta / (fabs(ln) > eps ? fabs(ln) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("1/2 ln((1+x)/(1-x)) aproximado = %.7lf\n", ln);
    printf("1/2 ln((1+x)/(1-x)) real       = %.7lf\n", 0.5 * log((1.0 + x) / (1.0 - x)));
    printf("Delta_n                         = %.4e\n",  delta);
    printf("nea (error aprox)               = %.4e\n",  nea);
    printf("Error absoluto                  = %.4e\n",  fabs(ln - 0.5 * log((1.0 + x) / (1.0 - x))));

    return 0;
}
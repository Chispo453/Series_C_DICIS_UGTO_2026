/**
 * ── NIVEL 2 ──
 * @file 12lnx_N2.c
 * @brief Aproximacion de ln(x) con u=(x-1)/(x+1) (estabilizada).
 *
 * @details
 * Sea u = (x-1)/(x+1).
 * Serie: ln(x) = 2 * [ u + u^3/3 + u^5/5 + ... ]
 *  = 2 * sum_{i=1}^{n} u^(2i-1) / (2i-1)
 *
 * Implementacion O(n^2):
 * El ciclo interno recalcula u^(2i-1) desde cero.
 * Dominio: x > 0 (u queda en (-1,1) para todo x > 0).
 *
 * @par Entrada
 * Entero n >= 1. Real x > 0.
 *
 * @par Salida
 * @code
 * ln(x) aproximado = valor
 * ln(x) real       = valor
 * Delta_n          = valor
 * nea              = valor
 * Error absoluto   = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Para x muy pequeño (cercano a 0) u -> -1 y la convergencia se vuelve lenta.
 * Para x muy grande u -> 1 y ocurre lo mismo.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, u, ln, ln_prev, num, den, k, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Indique el valor de x (x > 0): ");
        scanf("%lf", &x);
        if (x <= 0.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= 0.0);

    u = (x - 1.0) / (x + 1.0);


    for (i = 1, ln = 0.0; i <= n; i++) {
        den = (double)(2 * i - 1);
        num = 1.0;
        for (j = 0; j < (2 * i - 1); j++)
            num *= u;
        k   = num / den;
        ln += k;
    }
    ln *= 2.0;

    /*Serie con n/2 termino Delta_n*/
    if (n >= 2) {
        for (i = 1, ln_prev = 0.0; i <= n / 2; i++) {
            den = (double)(2 * i - 1);
            num = 1.0;
            for (j = 0; j < (2 * i - 1); j++)
                num *= u;
            ln_prev += num / den;
        }
        ln_prev *= 2.0;
    } else {
        ln_prev = 0.0;
    }

    delta = fabs(ln - ln_prev);
    nea   = delta / (fabs(ln) > eps ? fabs(ln) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(%.4lf) aproximado = %.7lf\n", x, ln);
    printf("ln(%.4lf) real       = %.7lf\n", x, log(x));
    printf("Delta_n              = %.4e\n",  delta);
    printf("nea (error aprox)    = %.4e\n",  nea);
    printf("Error absoluto       = %.4e\n",  fabs(ln - log(x)));

    return 0;
}
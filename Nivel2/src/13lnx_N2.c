/**
 * ── NIVEL 2 ──
 * @file 13lnx_N2.c
 * @brief Aproximacion de ln(x) con u=(x-1)/x (estabilizada).
 *
 * @details
 * Sea u = (x-1)/x.
 * Serie: ln(x) = u + u^2/2 + u^3/3 + ...
 *  = sum_{i=1}^{n} u^i / i
 *
 * Converge para x >= 1/2 (|u| <= 1).
 *
 * Implementacion O(n^2):
 * El ciclo interno calcula u^i desde cero en cada iteracion.
 *
 * @par Entrada
 * Entero n >= 1. Real x >= 0.5.
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
 * Para x < 0.5, |u| > 1 y la serie diverge.
 * Para x muy grande u -> 1 y la convergencia es lenta.
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
        printf("Indique el valor de x (x >= 0.5): ");
        scanf("%lf", &x);
        if (x < 0.5)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x < 0.5);

    u = (x - 1.0) / x;

    /* ── Serie con n terminos ── */
    for (i = 1, ln = 0.0; i <= n; i++) {
        den = (double)i;
        num = 1.0;
        for (j = 0; j < i; j++)
            num *= u;
        k   = num / den;
        ln += k;
    }

    /* ── Serie con n/2 terminos (para Delta_n) ── */
    if (n >= 2) {
        for (i = 1, ln_prev = 0.0; i <= n / 2; i++) {
            den = (double)i;
            num = 1.0;
            for (j = 0; j < i; j++)
                num *= u;
            ln_prev += num / den;
        }
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
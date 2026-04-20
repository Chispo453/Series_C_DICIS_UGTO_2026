/**
 * ── NIVEL 3 ──
 * @file 12lnx_N3.c
 * @brief Aproximacion de ln(x) con u=(x-1)/(x+1) por recurrencia O(n).
 *
 * @details
 * Sea u = (x-1)/(x+1).
 * Serie: ln(x) = 2 * sum_{i=1}^{n} u^(2i-1) / (2i-1)
 *
 * Recurrencia del termino:
 *   ter_1     = u     (i=1: u^1/1)
 *   ter_{i+1} = ter_i * u^2 * (2i-1)/(2i+1)
 *
 * Derivacion (identica a E_2ln pero con u en lugar de x):
 *   ter_i     = u^(2i-1) / (2i-1)
 *   ter_{i+1} = u^(2i+1) / (2i+1)
 *             = ter_i * u^2 * (2i-1)/(2i+1)
 *
 * Elimina el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real con dominio x > 0.
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
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Esta formula converge para todo x > 0, a diferencia de otras series
 * que solo convergen en subintervalos. Es la mas robusta para ln(x).
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, u, u2, ln, ln_prev, ter, delta, nea, eps;

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

    u  = (x - 1.0) / (x + 1.0);
    u2 = u * u;


    for (i = 1, ln = 0.0, ter = u; i <= n; i++) {
        ln  += ter;
        ter *= u2 * (double)(2 * i - 1) / (double)(2 * i + 1);
    }
    ln *= 2.0;

    /*Serie con n/2 termino Delta_n*/
    if (n >= 2) {
        for (i = 1, ln_prev = 0.0, ter = u; i <= n / 2; i++) {
            ln_prev += ter;
            ter     *= u2 * (double)(2 * i - 1) / (double)(2 * i + 1);
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
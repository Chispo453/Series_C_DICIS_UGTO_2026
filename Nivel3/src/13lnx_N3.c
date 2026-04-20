/**
 * ── NIVEL 3 ──
 * @file 13lnx_N3.c
 * @brief Aproximacion de ln(x) con u=(x-1)/x por recurrencia O(n).
 *
 * @details
 * Sea u = (x-1)/x.
 * Serie: ln(x) = sum_{i=1}^{n} u^i / i
 *
 * Recurrencia del termino:
 *   ter_1     = u    (i=1: u^1/1)
 *   ter_{i+1} = ter_i * u * i/(i+1)
 *
 * Derivacion:
 *   ter_i     = u^i / i
 *   ter_{i+1} = u^(i+1) / (i+1)
 *             = ter_i * u * i/(i+1)
 *
 * Elimina el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real con dominio x >= 0.5.
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
 * Para x exactamente 0.5, u = -1 y la serie es armonica alternante
 * (convergencia muy lenta). Se recomienda usar E_ln_u para mayor rango.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, u, ln, ln_prev, ter, delta, nea, eps;

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

    /* ── Serie con n terminos por recurrencia ── */
    for (i = 1, ln = 0.0, ter = u; i <= n; i++) {
        ln  += ter;
        ter *= u * (double)i / (double)(i + 1);
    }

    /* ── Serie con n/2 terminos (para Delta_n) ── */
    if (n >= 2) {
        for (i = 1, ln_prev = 0.0, ter = u; i <= n / 2; i++) {
            ln_prev += ter;
            ter     *= u * (double)i / (double)(i + 1);
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
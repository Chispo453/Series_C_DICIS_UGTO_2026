/**
 * ── NIVEL 2 ──
 * @file 7ex_N2.c
 * @brief Aproximacion de e^x mediante la serie de Taylor (estabilizada).
 *
 * @details
 * Serie: e^x = 1 + x + x^2/2! + x^3/3! + ... + x^(n-1)/(n-1)!
 *             = sum_{i=0}^{n-1} x^i / i!
 *
 * Implementacion:
 * Ciclos anidados: externo acumula la suma, interno calcula x^i e i!
 * desde cero en cada termino. O(n^2).
 *
 * @par Entrada
 * Entero n >= 1. Real x (dominio: todos los reales).
 *
 * @par Salida
 * @code
 * e^x aproximado = valor
 * e^x real       = valor
 * Delta_n        = valor
 * nea            = valor
 * Error absoluto = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Con double el limite de overflow es 170!. Para |x| grande
 * y n > 170 den puede llegar a inf.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, ex, ex_prev, num, den, t, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    /* ── Serie con n terminos ── */
    for (i = 0, ex = 0.0; i < n; i++) {
        num = 1.0;
        den = 1.0;
        for (j = 0; j < i; j++) {
            num *= x;
            den *= (j + 1);
        }
        t   = num / den;
        ex += t;
    }

    /* ── Serie con n/2 terminos (para Delta_n) ── */
    if (n >= 2) {
        for (i = 0, ex_prev = 0.0; i < n / 2; i++) {
            num = 1.0;
            den = 1.0;
            for (j = 0; j < i; j++) {
                num *= x;
                den *= (j + 1);
            }
            ex_prev += num / den;
        }
    } else {
        ex_prev = 0.0;
    }

    delta = fabs(ex - ex_prev);
    nea   = delta / (fabs(ex) > eps ? fabs(ex) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("e^%.4lf aproximado = %.7lf\n", x, ex);
    printf("e^%.4lf real       = %.7lf\n", x, exp(x));
    printf("Delta_n            = %.4e\n",  delta);
    printf("nea (error aprox)  = %.4e\n",  nea);
    printf("Error absoluto     = %.4e\n",  fabs(ex - exp(x)));

    return 0;
}
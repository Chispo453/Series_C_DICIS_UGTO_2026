/**
 * ── NIVEL 2 ──
 * @file 10ln_1+x_N2.c
 * @brief Aproximacion de ln(1+x) con serie de Maclaurin (estabilizada).
 *
 * @details
 * Serie: ln(1+x) = x - x^2/2 + x^3/3 - x^4/4 + ...
 *                = sum_{i=1}^{n} (-1)^(i+1) * x^i / i
 *
 * Implementacion O(n^2):
 * Ciclos anidados, el interno calcula x^i desde cero en cada iteracion.
 *
 * @par Entrada
 * Entero n >= 1. Real x con dominio -1 < x <= 1.
 *
 * @par Salida
 * @code
 * ln(1+x) aproximado = valor
 * ln(1+x) real       = valor
 * Delta_n            = valor
 * nea                = valor
 * Error absoluto     = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * La serie diverge para |x| > 1 y en x = -1.
 * La convergencia es lenta para x cercano a 1 o -1.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j, s;
    double x, ln, ln_prev, num, den, k, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Indique el valor de x (-1 < x <= 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x > 1.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= -1.0 || x > 1.0);

    
    for (i = 1, ln = 0.0; i <= n; i++) {
        s   = (i % 2 == 0) ? -1 : 1;   /* signo alternado */
        den = (double)i;
        num = 1.0;
        for (j = 0; j < i; j++)
            num *= x;
        k   = s * (num / den);
        ln += k;
    }


    if (n >= 2)
     {
        for (i = 1, ln_prev = 0.0; i <= n / 2; i++)
         {
            s   = (i % 2 == 0) ? -1 : 1;
            den = (double)i;
            num = 1.0;
            for (j = 0; j < i; j++)
                num *= x;
            ln_prev += s * (num / den);
        }
    } else {
        ln_prev = 0.0;
    }

    delta = fabs(ln - ln_prev);
    nea   = delta / (fabs(ln) > eps ? fabs(ln) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(1+%.4lf) aproximado = %.7lf\n", x, ln);
    printf("ln(1+%.4lf) real       = %.7lf\n", x, log(1.0 + x));
    printf("Delta_n                = %.4e\n",  delta);
    printf("nea (error aprox)      = %.4e\n",  nea);
    printf("Error absoluto         = %.4e\n",  fabs(ln - log(1.0 + x)));

    return 0;
}
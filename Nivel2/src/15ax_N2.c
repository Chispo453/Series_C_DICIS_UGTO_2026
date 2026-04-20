/**
 * ── NIVEL 2 ──
 * @file 15ax_N2.c
 * @brief Aproximacion de a^x usando la serie de e^u con u=x*ln(a) (estabilizada).
 *
 * @details
 * Identidad: a^x = e^(x*ln(a))
 * Se define u = x * ln(a) y se aplica la serie de Maclaurin de e^u:
 *   a^x = sum_{i=0}^{n-1} u^i / i!
 *
 * Implementacion O(n^2):
 * Ciclos anidados, el interno recalcula u^i e i! desde cero.
 *
 * @par Entrada
 * Entero n >= 1. Real a > 0 y a != 1. Real x (todos los reales).
 *
 * @par Salida
 * @code
 * a^x aproximado = valor
 * a^x real       = valor
 * Delta_n        = valor
 * nea            = valor
 * Error absoluto = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Para a muy grande o x grande, u = x*ln(a) puede ser grande
 * y la serie necesitara muchos terminos para converger.
 * Limite practico con double: n = 170 para u moderado.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, a, u, ax, ax_prev, num, den, t, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Ingrese el valor de a (a > 0, a != 1): ");
        scanf("%lf", &a);
        if (a <= 0.0 || a == 1.0)
            printf("Error: El valor de a esta fuera del dominio permitido para esta serie.\n");
    } while (a <= 0.0 || a == 1.0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    u = x * log(a);   /* sustitucion: u = x*ln(a) */


    for (i = 0, ax = 0.0; i < n; i++) {
        num = 1.0;
        den = 1.0;
        for (j = 0; j < i; j++) {
            num *= u;
            den *= (j + 1);
        }
        t   = num / den;
        ax += t;
    }

  
    if (n >= 2) {
        for (i = 0, ax_prev = 0.0; i < n / 2; i++) {
            num = 1.0;
            den = 1.0;
            for (j = 0; j < i; j++) {
                num *= u;
                den *= (j + 1);
            }
            ax_prev += num / den;
        }
    } else {
        ax_prev = 0.0;
    }

    delta = fabs(ax - ax_prev);
    nea   = delta / (fabs(ax) > eps ? fabs(ax) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("%.4lf^%.4lf aproximado = %.7lf\n", a, x, ax);
    printf("%.4lf^%.4lf real       = %.7lf\n", a, x, pow(a, x));
    printf("Delta_n                = %.4e\n",  delta);
    printf("nea (error aprox)      = %.4e\n",  nea);
    printf("Error absoluto         = %.4e\n",  fabs(ax - pow(a, x)));

    return 0;
}
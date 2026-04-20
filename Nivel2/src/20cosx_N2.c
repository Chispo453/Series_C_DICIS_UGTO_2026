/**
 * ── NIVEL 2 ──
 * @file 20cosx_N2.c
 * @brief Aproximacion de cos(x) con serie de Maclaurin (estabilizada).
 *
 * @details
 * Serie: cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
 *  = sum_{i=0}^{n-1} (-1)^i * x^(2i) / (2i)!
 *
 * Implementacion O(n^2):
 * Ciclos anidados, el interno calcula x^(2i) y (2i)! desde cero.
 *
 * @par Entrada
 * Entero n >= 1. Real x (todos los reales; en radianes).
 *
 * @par Salida
 * @code
 * cos(x) aproximado = valor
 * cos(x) real       = valor
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * El factorial (2i)! con double desborda aproximadamente en i = 86.
 * Para |x| grande hay cancelacion; reducir rango mejora la precision.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, xcos, xcos_prev, num, den, sig, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x (radianes): ");
    scanf("%lf", &x);

    
    for (i = 0, xcos = 0.0; i < n; i++) {
        num = 1.0;
        den = 1.0;
        for (j = 0; j < (2 * i); j++) {
            num *= x;
            den *= (double)(j + 1);
        }
        sig   = (i % 2 == 0) ? 1.0 : -1.0;
        ter   = sig * (num / den);
        xcos += ter;
    }

    /* Serie con n/2 terminos para Delta_n */
    if (n >= 2) {
        for (i = 0, xcos_prev = 0.0; i < n / 2; i++) {
            num = 1.0;
            den = 1.0;
            for (j = 0; j < (2 * i); j++) {
                num *= x;
                den *= (double)(j + 1);
            }
            sig       = (i % 2 == 0) ? 1.0 : -1.0;
            xcos_prev += sig * (num / den);
        }
    } else {
        xcos_prev = 0.0;
    }

    delta = fabs(xcos - xcos_prev);
    nea   = delta / (fabs(xcos) > eps ? fabs(xcos) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("cos(%.4lf) aproximado = %.7lf\n", x, xcos);
    printf("cos(%.4lf) real       = %.7lf\n", x, cos(x));
    printf("Delta_n               = %.4e\n",  delta);
    printf("nea (error aprox)     = %.4e\n",  nea);
    printf("Error absoluto        = %.4e\n",  fabs(xcos - cos(x)));

    return 0;
}
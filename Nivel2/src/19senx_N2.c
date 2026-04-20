/**
 * ── NIVEL 2 ──
 * @file 19senx_N2.c
 * @brief Aproximacion de sen(x) con serie de Maclaurin (estabilizada).
 *
 * @details
 * Serie: sen(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 *               = sum_{i=0}^{n-1} (-1)^i * x^(2i+1) / (2i+1)!
 *
 * Implementacion O(n^2):
 * Ciclos anidados, el interno calcula x^(2i+1) y (2i+1)! desde cero.
 *
 * @par Entrada
 * Entero n >= 1. Real x (todos los reales; dominio natural: radianes).
 *
 * @par Salida
 * @code
 * sen(x) aproximado = valor
 * sen(x) real       = valor
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Para |x| grande la serie requiere muchos terminos y hay cancelacion.
 * Con double el factorial (2i+1)! desborda.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, sen, sen_prev, num, den, sig, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x (radianes): ");
    scanf("%lf", &x);


    for (i = 0, sen = 0.0; i < n; i++) {
        num = 1.0;
        den = 1.0;
        for (j = 0; j < (2 * i + 1); j++) {
            num *= x;
            den *= (double)(j + 1);
        }
        sig  = (i % 2 == 0) ? 1.0 : -1.0;
        ter  = sig * (num / den);
        sen += ter;
    }

    /* Serie Delta_n */
    if (n >= 2) {
        for (i = 0, sen_prev = 0.0; i < n / 2; i++) {
            num = 1.0;
            den = 1.0;
            for (j = 0; j < (2 * i + 1); j++) {
                num *= x;
                den *= (double)(j + 1);
            }
            sig      = (i % 2 == 0) ? 1.0 : -1.0;
            sen_prev += sig * (num / den);
        }
    } else {
        sen_prev = 0.0;
    }

    delta = fabs(sen - sen_prev);
    nea   = delta / (fabs(sen) > eps ? fabs(sen) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("sen(%.4lf) aproximado = %.7lf\n", x, sen);
    printf("sen(%.4lf) real       = %.7lf\n", x, sin(x));
    printf("Delta_n               = %.4e\n",  delta);
    printf("nea (error aprox)     = %.4e\n",  nea);
    printf("Error absoluto        = %.4e\n",  fabs(sen - sin(x)));

    return 0;
}
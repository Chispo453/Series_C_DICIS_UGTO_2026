/** 
 * ── NIVEL 2 ──
 * @file 8xex_N2.c
 * @brief Aproximacion de xe^x mediante la serie de Maclaurin (estabilizada).
 *
 * @details
 * Serie: xe^x = x + 2x^2/2! + 3x^3/3! + ... = sum_{i=1}^{n} i*x^i / i!
 *
 * Implementacion:
 * Ciclos anidados: el interno calcula x^i e i! desde cero.
 * Termino i: i * (x^i / i!) = x^i / (i-1)!
 * O(n^2).
 *
 * @par Entrada
 * Entero n >= 1. Real x (todos los reales).
 *
 * @par Salida
 * @code
 * xe^x aproximado = valor
 * xe^x real       = valor
 * Delta_n         = valor
 * nea             = valor
 * Error absoluto  = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * El factor i en el numerador acelera el crecimiento;
 * con double el limite practico sigue siendo n de 170.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, xex, xex_prev, num, den, t, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    /* ── Serie con n terminos ── */
    for (i = 1, xex = 0.0; i <= n; i++) {
        num = 1.0;
        den = 1.0;
        for (j = 0; j < i; j++) {
            num *= x;
            den *= (j + 1);
        }
        t    = i * (num / den);
        xex += t;
    }

    /* ── Serie con n/2 terminos (para Delta_n) ── */
    if (n >= 2) {
        for (i = 1, xex_prev = 0.0; i <= n / 2; i++) {
            num = 1.0;
            den = 1.0;
            for (j = 0; j < i; j++) {
                num *= x;
                den *= (j + 1);
            }
            xex_prev += i * (num / den);
        }
    } else {
        xex_prev = 0.0;
    }

    delta = fabs(xex - xex_prev);
    nea   = delta / (fabs(xex) > eps ? fabs(xex) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("%.4lf*e^%.4lf aproximado = %.7lf\n", x, x, xex);
    printf("%.4lf*e^%.4lf real       = %.7lf\n", x, x, x * exp(x));
    printf("Delta_n                  = %.4e\n",  delta);
    printf("nea (error aprox)        = %.4e\n",  nea);
    printf("Error absoluto           = %.4e\n",  fabs(xex - x * exp(x)));

    return 0;
}
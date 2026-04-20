/**
 * ── NIVEL 3 ──
 * @file 7ex_N3.c
 * @brief Aproximacion de e^x con recurrencia O(n).
 *
 * @details
 * Serie: e^x = sum_{i=0}^{n-1} x^i / i!
 *
 * Recurrencia del termino:
 *   t_0     = 1
 *   t_{i+1} = t_i * x / (i+1)
 *
 * Elimina ciclos internos: cada termino se obtiene multiplicando
 * el anterior por x/(i+1). Complejidad O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1 (numero de terminos).
 * @param x  Real (todos los reales).
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
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Para x muy negativo los terminos alternan signo; la suma converge
 * antes de n iteraciones pero no hay riesgo de overflow con double.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, ex, ex_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    /* ── Serie con n terminos por recurrencia ── */
    for (i = 0, ex = 0.0, ter = 1.0; i < n; i++) {
        ex  += ter;
        ter *= x / (i + 1);   /* t_{i+1} = t_i * x/(i+1) */
    }

    /* ── Serie con n/2 terminos (para Delta_n) ── */
    if (n >= 2) {
        for (i = 0, ex_prev = 0.0, ter = 1.0; i < n / 2; i++) {
            ex_prev += ter;
            ter     *= x / (i + 1);
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
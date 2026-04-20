/**
 *  ── NIVEL 3 ──
 * @file 9x+x2_ex_N3.c
 * @brief Aproximacion de (x+x^2)e^x con recurrencia O(n).
 *
 * @details
 * Serie: (x+x^2)e^x = sum_{i=1}^{n} i^2 * x^i / i!
 *
 * Definimos el termino base: b_i = x^i / i!
 * Recurrencia: b_{i+1} = b_i * x / (i+1)    con b_1 = x
 *
 * Termino de la serie: t_i = i^2 * b_i
 *
 * Con esto se elimina el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real (todos los reales).
 *
 * @par Salida
 * @code
 * (x+x^2)e^x aproximado = valor
 * (x+x^2)e^x real       = valor
 * Delta_n               = valor
 * nea                   = valor
 * Error absoluto        = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Para x fuera de [-2, 2] la serie puede necesitar muchos terminos
 * para converger, aunque double extiende el rango respecto a float.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, e3, e3_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    /* ── Serie con n terminos por recurrencia ── */
    /* b_1 = x  =>  t_1 = 1^2 * x = x */
    for (i = 1, e3 = 0.0, ter = x; i <= n; i++) {
        e3  += (double)(i * i) * ter;   /* t_i = i^2 * b_i */
        ter *= x / (i + 1);             /* b_{i+1} = b_i * x/(i+1) */
    }

    /* ── Serie con n/2 terminos (para Delta_n) ── */
    if (n >= 2) {
        for (i = 1, e3_prev = 0.0, ter = x; i <= n / 2; i++) {
            e3_prev += (double)(i * i) * ter;
            ter     *= x / (i + 1);
        }
    } else {
        e3_prev = 0.0;
    }

    delta = fabs(e3 - e3_prev);
    nea   = delta / (fabs(e3) > eps ? fabs(e3) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("(x+x^2)e^x aproximado = %.7lf\n", e3);
    printf("(x+x^2)e^x real       = %.7lf\n", (x + x * x) * exp(x));
    printf("Delta_n               = %.4e\n",  delta);
    printf("nea (error aprox)     = %.4e\n",  nea);
    printf("Error absoluto        = %.4e\n",  fabs(e3 - (x + x * x) * exp(x)));

    return 0;
}
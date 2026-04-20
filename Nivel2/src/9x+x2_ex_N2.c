/**
 * ── NIVEL 2 ──
 * @file 9x+x2_ex_N2.c
 * @brief Aproximacion de (x+x^2)e^x mediante serie de Maclaurin (estabilizada).
 *
 * @details
 * Serie: (x+x^2)e^x = sum_{i=1}^{n} i^2 * x^i / i!
 *   Termino i: i^2 * x^i / i!
 *
 * Implementacion O(n^2):
 * Ciclos anidados, el interno recalcula x^i e i! desde cero.
 *
 * @par Entrada
 * Entero n >= 1. Real x.
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
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * El factor i^2 en el numerador acelera el crecimiento de cada termino.
 * Con double el limite practico es n = 170 para x moderado.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, e3, e3_prev, num, den, t, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

   
    for (i = 1, e3 = 0.0; i <= n; i++) {
        num = 1.0;
        den = 1.0;
        for (j = 0; j < i; j++) {
            num *= x;
            den *= (j + 1);
        }
        t    = (double)(i * i) * (num / den); 
        e3  += t;
    }

    if (n >= 2) {
        for (i = 1, e3_prev = 0.0; i <= n / 2; i++) {
            num = 1.0;
            den = 1.0;
            for (j = 0; j < i; j++) {
                num *= x;
                den *= (j + 1);
            }
            e3_prev += (double)(i * i) * (num / den);
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
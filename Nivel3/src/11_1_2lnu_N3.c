/**
 * ── NIVEL 3 ──
 * @file 11_1_2lnu_N3.c
 * @brief Aproximacion de 1/2*ln((1+x)/(1-x)) con recurrencia O(n).
 *
 * @details
 * Serie: 1/2*ln((1+x)/(1-x)) = sum_{i=1}^{n} x^(2i-1) / (2i-1)
 *
 * Recurrencia del termino:
 *   ter_1     = x    (i=1: x^1/1)
 *   ter_{i+1} = ter_i * x^2 * (2i-1)/(2i+1)
 *
 * Derivacion:
 *   ter_i     = x^(2i-1) / (2i-1)
 *   ter_{i+1} = x^(2i+1) / (2i+1)
 *             = ter_i * x^2 * (2i-1)/(2i+1)
 *
 * Elimina el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real con dominio -1 < x < 1.
 *
 * @par Salida
 * @code
 * 1/2 ln((1+x)/(1-x)) aproximado = valor
 * 1/2 ln((1+x)/(1-x)) real       = valor
 * Delta_n                         = valor
 * nea                             = valor
 * Error absoluto                  = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Esta serie converge mas rapido que ln(1+x) para x moderado,
 * pero sigue siendo lenta para x cercano a +-1.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, ln, ln_prev, ter, x2, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Indique el valor de x (-1 < x < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= -1.0 || x >= 1.0);

    x2 = x * x;

    
    for (i = 1, ln = 0.0, ter = x; i <= n; i++) {
        ln  += ter;
        ter *= x2 * (double)(2 * i - 1) / (double)(2 * i + 1);
    }

    /* Serie con n/2 terminos para Delta_n */
    if (n >= 2) {
        for (i = 1, ln_prev = 0.0, ter = x; i <= n / 2; i++) {
            ln_prev += ter;
            ter     *= x2 * (double)(2 * i - 1) / (double)(2 * i + 1);
        }
    } else {
        ln_prev = 0.0;
    }

    delta = fabs(ln - ln_prev);
    nea   = delta / (fabs(ln) > eps ? fabs(ln) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("1/2 ln((1+x)/(1-x)) aproximado = %.7lf\n", ln);
    printf("1/2 ln((1+x)/(1-x)) real       = %.7lf\n", 0.5 * log((1.0 + x) / (1.0 - x)));
    printf("Delta_n                         = %.4e\n",  delta);
    printf("nea (error aprox)               = %.4e\n",  nea);
    printf("Error absoluto                  = %.4e\n",  fabs(ln - 0.5 * log((1.0 + x) / (1.0 - x))));

    return 0;
}
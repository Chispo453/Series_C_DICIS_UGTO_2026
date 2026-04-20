/**
 * ── NIVEL 2 ──
 * @file 14binomio_N2.c
 * @brief Aproximacion de (1+x)^alfa con la Serie Binomial (estabilizada).
 *
 * @details
 * Serie: (1+x)^alfa = sum_{i=0}^{n} C(alfa,i) * x^i
 *
 * Donde el coeficiente binomial generalizado es:
 *   C(alfa,0) = 1
 *   C(alfa,i) = alfa*(alfa-1)*...*(alfa-i+1) / i!
 *
 * Termino i: num = alfa*(alfa-1)*...*(alfa-i+1)
 *            den = i!
 *            multi = x^i
 * Los tres se calculan en un solo ciclo interno simultaneamente.
 *
 * Implementacion O(n^2):
 * Ciclos anidados, el interno recalcula num, den y multi desde cero.
 *
 * @par Entrada
 * Entero n >= 1. Real x con |x| < 1. Real alfa (exponente).
 *
 * @par Salida
 * @code
 * (1+x)^alfa aproximado = valor
 * (1+x)^alfa real       = valor
 * Delta_n               = valor
 * nea                   = valor
 * Error absoluto        = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * La serie binomial converge solo para |x| < 1.
 * Para alfa entero no negativo la serie es finita (polinomio de Newton)
 * y converge para todo x.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, j;
    double x, alfa, ter, ter_prev, num, den, multi, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Ingrese el valor de x (|x| < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= -1.0 || x >= 1.0);

    printf("Ingrese el valor de alfa: ");
    scanf("%lf", &alfa);

    ter = 0.0;
    for (i = 0; i <= n; i++) {
        /* Calcula C(alfa,i)*x^i desde cero en el ciclo interno */
        num   = 1.0;
        den   = 1.0;
        multi = 1.0;
        for (j = 0; j < i; j++) {
            num   *= (alfa - (double)j);   /* alfa*(alfa-1)*...*(alfa-i+1) */
            den   *= (double)(j + 1);      /* i! */
            multi *= x;                    /* x^i */
        }
        ter += (num / den) * multi;
    }

    /*Serie con n/2 terminos para Delta_n*/
    if (n >= 2) {
        ter_prev = 0.0;
        for (i = 0; i <= n / 2; i++) {
            num   = 1.0;
            den   = 1.0;
            multi = 1.0;
            for (j = 0; j < i; j++) {
                num   *= (alfa - (double)j);
                den   *= (double)(j + 1);
                multi *= x;
            }
            ter_prev += (num / den) * multi;
        }
    } else {
        ter_prev = 0.0;
    }

    delta = fabs(ter - ter_prev);
    nea   = delta / (fabs(ter) > eps ? fabs(ter) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("(1+%.4lf)^%.4lf aproximado = %.7lf\n", x, alfa, ter);
    printf("(1+%.4lf)^%.4lf real       = %.7lf\n", x, alfa, pow(1.0 + x, alfa));
    printf("Delta_n                     = %.4e\n",  delta);
    printf("nea (error aprox)           = %.4e\n",  nea);
    printf("Error absoluto              = %.4e\n",  fabs(ter - pow(1.0 + x, alfa)));

    return 0;
}
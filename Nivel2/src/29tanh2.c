/**
 * @file tanh2.c
 * @brief Aproximación de tanh(x) usando series de sinh(x) y cosh(x).
 *
 * @details
 * La función tanh(x) se calcula como tanh(x) = sinh(x) / cosh(x), donde:
 *
 * $\sinh(x) = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{(2n+1)!}$
 *
 * $\cosh(x) = \sum_{n=0}^{\infty} \frac{x^{2n}}{(2n)!}$
 *
 * Esta implementación calcula factoriales y potencias en cada iteración para ambos.
 *
 * @param n Número de términos (n >= 1)
 * @param x Valor real
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * Precisión limitada para valores grandes de x.
 *
 * @note
 * No se usa math.h.
 */

#include <stdio.h>

int main() {
    int n, i, j;
    double x;
    double sinh = 0.0, cosh = 0.0;
    double pot_sinh, pot_cosh;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);

    pot_sinh = x;
    pot_cosh = 1.0;

    for (i = 0; i < n; i++) {

        // factorial sinh
        double fact_s = 1.0;
        for (j = 1; j <= 2*i+1; j++) {
            fact_s *= j;
        }

        sinh += pot_sinh / fact_s;

        // factorial cosh
        double fact_c = 1.0;
        for (j = 1; j <= 2*i; j++) {
            fact_c *= j;
        }

        cosh += pot_cosh / fact_c;

        pot_sinh *= x * x;
        pot_cosh *= x * x;
    }

    if (cosh != 0)
        printf("tanh(x) = %lf\n", sinh / cosh);
    else
        printf("Error: division por cero\n");

    return 0;
}
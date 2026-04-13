/**
 * @file cosh1.c
 * @brief Aproximación simple de cosh(x) usando serie de Taylor.
 *
 * @details
 * La función cosh(x) se aproxima con la serie de Taylor:
 *
 * $\cosh(x) = \sum_{n=0}^{\infty} \frac{x^{2n}}{(2n)!}$
 *
 * Esta implementación calcula factoriales y potencias en cada iteración.
 *
 * @param x Valor real
 * @param n Número de términos (n >= 1)
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

int main(int argc, char *argv[]) {
    int n, i, j;
    double x, suma = 0.0;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);

    for (i = 0; i < n; i++) {

        // x^(2i)
        double pot = 1.0;
        for (j = 0; j < 2*i; j++) {
            pot *= x;
        }

        // (2i)!
        double fact = 1.0;
        for (j = 1; j <= 2*i; j++) {
            fact *= j;
        }

        suma += pot / fact;
    }

    printf("cosh(x) = %lf\n", suma);

    return 0;
}
/**
 * @file cosh2.c
 * @brief Aproximación de cosh(x) con cálculo incremental de potencias.
 *
 * @details
 * La función cosh(x) se aproxima con la serie de Taylor:
 *
 * $\cosh(x) = \sum_{n=0}^{\infty} \frac{x^{2n}}{(2n)!}$
 *
 * Las potencias se calculan incrementalmente para mejorar eficiencia.
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
    int n, i;
    double x, suma = 0.0;
    double pot = 1.0;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);

    pot = 1.0;

    for (i = 0; i < n; i++) {

        // factorial
        double fact = 1.0;
        int j;
        for (j = 1; j <= 2*i; j++) {
            fact *= j;
        }

        suma += pot / fact;

        // actualizar potencia
        pot *= x * x;
    }

    printf("cosh(x) = %lf\n", suma);

    return 0;
}
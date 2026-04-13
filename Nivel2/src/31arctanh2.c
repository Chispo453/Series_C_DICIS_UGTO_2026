/**
 * @file arctanh2.c
 * @brief Aproximación de arctanh(x) con validación estricta de entrada.
 *
 * @details
 * La función arctanh(x) se aproxima con la serie de Maclaurin:
 *
 * $\text{arctanh}(x) = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{2n+1}$
 *
 * Incluye validación estricta del dominio de convergencia.
 *
 * @param x Valor real tal que |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * La serie diverge si |x| >= 1.
 *
 * @note
 * No se usa math.h.
 */

#include <stdio.h>

int main() {
    int n, i, j;
    double x;
    double suma, termino;

    do {
        printf("Ingrese el numero de terminos (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    do {
        printf("Ingrese el valor de x (|x| < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: arctanh(x) solo converge para |x| < 1\n");
    } while (x <= -1.0 || x >= 1.0);

    suma = 0.0;

    for (i = 0; i < n; i++) {

        termino = 1.0;

        /* Construir x^(2i+1) incrementalmente */
        for (j = 0; j < (2*i + 1); j++) {
            termino *= x;
        }

        termino = termino / (2*i + 1);

        suma += termino;
    }

    printf("arctanh(%lf) = %.15lf\n", x, suma);

    return 0;
}
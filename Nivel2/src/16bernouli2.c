/**
 * @file bernouli2.c
 * @brief Cálculo intermedio de números de Bernoulli.
 *
 * @details
 * Se usa la recurrencia:
 *
 * $B_k = - \sum_{i=0}^{k-1} \binom{k}{i} \frac{B_i}{k+1-i}$
 *
 * El coeficiente binomial se calcula mediante
 * producto incremental en lugar de factoriales completos.
 *
 * @param n Índice máximo k (n >= 0)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(n)
 *
 * @warning
 * Precisión limitada por uso de double.
 *
 * @note
 * No se utiliza math.h.
 */

#include <stdio.h>

int main() {

    int n, k, i;
    double B[100];
    double suma, binom;

    do {
        printf("Ingrese n (n >= 0): ");
        scanf("%d", &n);
    } while (n < 0 || n > 99);

    B[0] = 1.0;

    for (k = 1; k <= n; k++) {

        suma = 0.0;

        for (i = 0; i < k; i++) {

            binom = 1.0;

            int j;
            for (j = 1; j <= i; j++)
                binom *= (double)(k - j + 1) / j;

            suma += binom * B[i] / (k+1-i);
        }

        B[k] = -suma;
    }

    for (k = 0; k <= n; k++)
        printf("B_%d = %.15lf\n", k, B[k]);

    return 0;
}
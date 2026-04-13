/**
 * @file bernouli1.c
 * @brief Cálculo directo de números de Bernoulli usando la recurrencia clásica.
 *
 * @details
 * Los números de Bernoulli se definen mediante:
 *
 * $B_0 = 1$
 *
 * $B_k = - \sum_{i=0}^{k-1} \binom{k}{i} \frac{B_i}{k+1-i}$
 *
 * En este nivel se calculan los coeficientes binomiales
 * mediante factoriales recalculados en cada iteración.
 *
 * @param n Índice máximo k (n >= 0)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^3)
 * Memoria: O(n)
 *
 * @warning
 * Para n grande pueden ocurrir errores numéricos.
 *
 * @note
 * No se utiliza math.h.
 */

#include <stdio.h>

int main() {

    int n, k, i, j;
    double B[100];
    double suma;
    double num, den;

    do {
        printf("Ingrese n (n >= 0): ");
        scanf("%d", &n);
    } while (n < 0 || n > 99);

    B[0] = 1.0;

    for (k = 1; k <= n; k++) {

        suma = 0.0;

        for (i = 0; i < k; i++) {

            /* Calcular binomial(k,i) con factorial */
            double fact_k = 1.0, fact_i = 1.0, fact_ki = 1.0;

            for (j = 1; j <= k; j++) fact_k *= j;
            for (j = 1; j <= i; j++) fact_i *= j;
            for (j = 1; j <= (k-i); j++) fact_ki *= j;

            num = fact_k;
            den = fact_i * fact_ki;

            suma += (num/den) * B[i] / (k+1-i);
        }

        B[k] = -suma;
    }

    for (k = 0; k <= n; k++)
        printf("B_%d = %.15lf\n", k, B[k]);

    return 0;
}
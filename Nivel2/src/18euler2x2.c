/**
 * @file euler2.c
 * @brief Cálculo alternativo de números de Euler con validación.
 *
 * @details
 * Implementación alternativa para calcular números de Euler con validación de entrada.
 *
 * @param k Índice del número de Euler (k >= 0)
 * @param M Número de iteraciones (M >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(M^2)
 * Memoria: O(1)
 *
 * @warning
 * Requiere muchas iteraciones para precisión.
 *
 * @note
 * Algoritmo alternativo al de euler/.
 */

#include <stdio.h>

int main() {
    int k, M, m, j, i;
    double suma_total = 0.0;

    do {
        printf("k (>=0): ");
        scanf("%d", &k);
    } while (k < 0);

    do {
        printf("M (iteraciones >=1): ");
        scanf("%d", &M);
    } while (M < 1);

    for (m = 1; m <= M; m++) {

        double suma_interna = 0.0;
        double comb = 1.0; // C(m,0)

        for (j = 0; j <= m; j++) {

            if (j > 0) {
                comb = comb * (m - j + 1) / j;
            }

            int signo = (j % 2 == 0) ? 1 : -1;

            // potencia
            double potencia = 1.0;
            int base = m - 2*j;

            for (i = 0; i < (2*k+1); i++) {
                potencia *= base;
            }

            suma_interna += comb * signo * potencia;
        }

        suma_total += suma_interna / m;
    }

    double divisor = 1.0;
    for (i = 0; i < (2*k+1); i++) {
        divisor *= 2.0;
    }

    printf("E_%d = %.10f\n", 2*k, suma_total / divisor);

    return 0;
}
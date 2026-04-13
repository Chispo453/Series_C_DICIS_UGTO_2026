/**
 * @file euler1.c
 * @brief Cálculo alternativo de números de Euler.
 *
 * @details
 * Implementación alternativa para calcular números de Euler.
 *
 * @param k Índice del número de Euler
 * @param M Número de iteraciones
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


    printf("k (>=0): ");
    scanf("%d", &k);
    
    printf("M (iteraciones >=1): ");
    scanf("%d", &M);

    for (m = 1; m <= M; m++) {

        double suma_interna = 0.0;

        for (j = 0; j <= m; j++) {

            // calcular combinacion C(m,j)
            double comb = 1.0;
            int temp = j;

            if (temp > m - temp)
                temp = m - temp;

            for (i = 0; i < temp; i++) {
                comb *= (m - i);
                comb /= (i + 1);
            }

            // calcular (m - 2j)^(2k+1)
            double potencia = 1.0;
            int base = m - 2*j;

            for (i = 0; i < (2*k+1); i++) {
                potencia *= base;
            }

            // (-1)^j
            int signo = (j % 2 == 0) ? 1 : -1;

            suma_interna += comb * signo * potencia;
        }

        suma_total += suma_interna / m;
    }

    // dividir por 2^(2k+1)
    double divisor = 1.0;
    for (i = 0; i < (2*k+1); i++) {
        divisor *= 2.0;
    }

    double resultado = suma_total / divisor;

    printf("E_%d = %.10f\n", 2*k, resultado);

    return 0;
}

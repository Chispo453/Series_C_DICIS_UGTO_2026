/**
 * @file euler2.c
 * @brief Cálculo de números de Euler E_k con validación.
 *
 * @details
 * Los números de Euler se calculan mediante:
 *
 * $E_k = \frac{2^{2k+2} (2k)!}{\pi^{2k+1}} \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n+1)^{2k+1}}$
 *
 * Incluye validación de entrada.
 *
 * @param k Índice del número de Euler (k >= 0)
 * @param iter Número de términos de la serie (iter >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(iter * k)
 * Memoria: O(1)
 *
 * @warning
 * Requiere muchos términos para precisión.
 *
 * @note
 * No se usa math.h.
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(int argc, char *argv[]) {
    int k, n, j, iter;
    double suma = 0.0;
    double termino;
    double factorial = 1.0;
    double resultado;

    do {
        printf("Ingrese k (>=0): ");
        scanf("%d", &k);
    } while (k < 0);

    do {
        printf("Ingrese numero de iteraciones (>=1): ");
        scanf("%d", &iter);
    } while (iter < 1);

    // (2k)!
    for (int i = 1; i <= 2*k; i++) {
        factorial *= i;
    }

    // Serie
    for (n = 0; n < iter; n++) {
        int impar = 2*n + 1;

        // calcular 1/(impar^(2k+1)) como producto
        termino = 1.0;

        for (j = 0; j < (2*k+1); j++) {
            termino *= 1.0 / impar;
        }

        if (n % 2 == 0)
            suma += termino;
        else
            suma -= termino;
    }

    // 2^(2k+2)
    double pot2 = 1.0;
    for (int i = 0; i < (2*k+2); i++) {
        pot2 *= 2.0;
    }

    // PI^(2k+1)
    double potpi = 1.0;
    for (int i = 0; i < (2*k+1); i++) {
        potpi *= PI;
    }

    resultado = (pot2 * factorial / potpi) * suma;

    printf("E_%d = %.10f\n", k, resultado);

    return 0;
}
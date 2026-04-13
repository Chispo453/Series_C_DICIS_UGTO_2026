/**
 * @file arcsen1.c
 * @brief Aproximación simple de arcsen(x) usando serie de Taylor.
 *
 * @details
 * La función arcsen(x) se aproxima directamente con la serie de Taylor:
 *
 * $\arcsin(x) = \sum_{n=0}^{\infty} \frac{(2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Esta implementación calcula factoriales y potencias en cada iteración,
 * resultando en una complejidad cuadrática.
 *
 * @param x Valor en el intervalo [-1, 1]
 * @param n Número de términos de la serie (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * La serie converge lentamente cerca de x = ±1.
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

    printf("Valor de x (entre -1 y 1): ");
    scanf("%lf", &x);

    if (x < -1 || x > 1) {
        printf("Error: fuera del dominio\n");
        return 0;
    }

    for (i = 0; i < n; i++) {

        // (2i)!
        double fact2i = 1.0;
        for (j = 1; j <= 2*i; j++) {
            fact2i *= j;
        }

        // (i!)^2
        double facti = 1.0;
        for (j = 1; j <= i; j++) {
            facti *= j;
        }

        // 4^i
        double pot4 = 1.0;
        for (j = 0; j < i; j++) {
            pot4 *= 4.0;
        }

        // x^(2i+1)
        double potx = 1.0;
        for (j = 0; j < 2*i+1; j++) {
            potx *= x;
        }

        double termino = (fact2i / (pot4 * facti * facti * (2*i+1))) * potx;

        suma += termino;
    }

    printf("arcsin(x) = %lf\n", suma);

    return 0;
}
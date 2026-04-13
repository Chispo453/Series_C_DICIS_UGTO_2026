/**
 * @file arcsen2.c
 * @brief Aproximación de arcsen(x) con validación de entrada.
 *
 * @details
 * La función arcsen(x) se aproxima directamente con la serie de Taylor:
 *
 * $\arcsin(x) = \sum_{n=0}^{\infty} \frac{(2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Esta implementación incluye validación estricta del dominio de entrada.
 *
 * @param x Valor en el intervalo (-1, 1)
 * @param n Número de términos de la serie (n >= 1)
 * @return 0 si ejecución correcta, 1 si error de dominio
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
    double x, suma = 0, termino;
    int n, i, j;
    double fact2n, factn;

    printf("x: ");
    scanf("%lf", &x);

    printf("n: ");
    scanf("%d", &n);

    if (x <= -1 || x >= 1) {
        printf("Error |x| < 1\n");
        return 1;
    }

    for (i = 0; i < n; i++) {

        // (2n)!
        fact2n = 1;
        for (j = 1; j <= 2*i; j++) fact2n *= j;

        // (n!)^2
        factn = 1;
        for (j = 1; j <= i; j++) factn *= j;
        factn *= factn;

        // x^(2n+1)
        termino = 1;
        for (j = 0; j < 2*i+1; j++) termino *= x;

        termino *= fact2n / ((1 << (2*i)) * factn * (2*i+1));

        suma += termino;
    }

    printf("arcsen(x) = %lf\n", suma);
}
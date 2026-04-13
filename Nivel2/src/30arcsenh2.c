/**
 * @file arcsenh2.c
 * @brief Aproximación de arcsenh(x) con validación de entrada.
 *
 * @details
 * La función arcsenh(x) se aproxima con la serie de Taylor:
 *
 * $\text{arcsenh}(x) = \sum_{n=0}^{\infty} \frac{(-1)^n (2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Incluye validación del dominio.
 *
 * @param x Valor real
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta, 1 si error
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
    double x, suma, termino, potencia;
    int n, i, j;
    double factorial1, factorial2;

    printf("Ingrese x: ");
    scanf("%lf", &x);

    printf("Ingrese numero de terminos: ");
    scanf("%d", &n);

    // Validacion
    if (x <= -1 || x >= 1) {
        printf("Error: |x| < 1\n");
        return 1;
    }

    suma = 0;

    for (i = 0; i < n; i++) {

        // x^(2n+1)
        potencia = 1;
        for (j = 0; j < 2*i + 1; j++) {
            potencia *= x;
        }

        // (2n)!
        factorial1 = 1;
        for (j = 1; j <= 2*i; j++) {
            factorial1 *= j;
        }

        // (n!)^2
        factorial2 = 1;
        for (j = 1; j <= i; j++) {
            factorial2 *= j;
        }
        factorial2 *= factorial2;

        // termino completo
        termino = factorial1 / ( (1 << (2*i)) * factorial2 * (2*i + 1) );

        // signo (-1)^n
        if (i % 2 != 0)
            termino = -termino;

        termino *= potencia;

        suma += termino;
    }

    printf("arcsenh(x) = %lf\n", suma);

    return 0;
}
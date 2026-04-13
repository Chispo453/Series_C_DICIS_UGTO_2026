/**
 * @file arctan2.c
 * @brief Aproximación de arctan(x) con validación de entrada.
 *
 * @details
 * La función arctan(x) se aproxima con la serie de Taylor:
 *
 * $\arctan(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{2n+1}$
 *
 * Incluye transformación para valores fuera de [-1, 1].
 *
 * @param x Valor real
 * @param n Número de términos de la serie (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * La precisión depende del número de términos.
 *
 * @note
 * No se usa math.h. Pi se define manualmente.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    double x, suma = 0, termino, pi = 3.1416;
    int n, i, j;

    printf("x: ");
    scanf("%lf", &x);

    printf("n: ");
    scanf("%d", &n);

    if (x > -1 && x < 1) {
        for (i = 0; i < n; i++) {

            termino = 1;
            for (j = 0; j < 2*i+1; j++) termino *= x;

            if (i % 2 != 0)
                termino = -termino;

            termino /= (2*i + 1);

            suma += termino;
        }
    } else {
        // transformación para |x| > 1
        double inv = 1/x;

        for (i = 0; i < n; i++) {

            termino = 1;
            for (j = 0; j < 2*i+1; j++) termino *= inv;

            if (i % 2 != 0)
                termino = -termino;

            termino /= (2*i + 1);

            suma += termino;
        }

        if (x > 0)
            suma = pi/2 - suma;
        else
            suma = -pi/2 - suma;
    }

    printf("arctan(x) = %lf\n", suma);
}
/**
 * @file csc1.c
 * @brief Aproximación simple de csc(x) usando serie de Taylor.
 *
 * @details
 * La función csc(x) se calcula como 1/sin(x), aproximando sin(x) con serie:
 *
 * $\sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{(2n+1)!}$
 *
 * Luego csc(x) = 1/sin(x).
 *
 * @param x Valor en grados
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * No definido en múltiplos de π.
 *
 * @note
 * Convierte grados a radianes.
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(int argc, char *argv[]) {
    int n, i, j;
    double x, suma = 0.0;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x en grados: ");
    scanf("%lf", &x);
    x = x * PI / 180.0;


    for (i = 0; i < n; i++) {

        double termino = 0.0;

        if (i == 0) {
            termino = 1.0 / x;
        } else {
            // potencia x^(2i-1)
            double pot = 1.0;
            for (j = 0; j < (2*i-1); j++) {
                pot *= x;
            }

            double coef;

            if (i == 1) coef = 1.0/6;
            else if (i == 2) coef = 7.0/360;
            else if (i == 3) coef = 31.0/15120;
            else coef = 0;

            termino = coef * pot;
        }

        suma += termino;
    }

    printf("csc(x) = %lf\n", suma);

    return 0;
}
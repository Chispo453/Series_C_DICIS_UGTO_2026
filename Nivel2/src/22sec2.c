/**
 * @file sec2.c
 * @brief Aproximación de sec(x) con términos fijos.
 *
 * @details
 * La función sec(x) se aproxima con términos fijos de su serie:
 *
 * $\sec(x) = 1 + \frac{x^2}{2} + \frac{5x^4}{24} + \frac{61x^6}{720} + \cdots$
 *
 * @param x Valor en grados
 * @param n Número de términos (limitado)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(1)
 * Memoria: O(1)
 *
 * @warning
 * No definido en múltiplos de π/2.
 *
 * @note
 * Convierte grados a radianes.
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(int argc, char *argv[]) {
    int n, i;
    double x, suma = 0.0;
    double pot;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x en grados: ");
    scanf("%lf", &x);

    x = x * PI / 180.0;

    pot = 1.0;

    for (i = 0; i < n; i++) {

        double coef;
        if (i == 0) coef = 1;
        else if (i == 1) coef = 1.0/2;
        else if (i == 2) coef = 5.0/24;
        else if (i == 3) coef = 61.0/720;
        else coef = 0;

        suma += coef * pot;

        // actualizar x^(2i)
        pot *= x * x;
    }

    printf("sec(x) = %lf\n", suma);

    return 0;
}
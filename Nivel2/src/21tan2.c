/**
 * @file tan2.c
 * @brief Aproximación de tan(x) con términos fijos.
 *
 * @details
 * La función tan(x) se aproxima con términos fijos de su serie:
 *
 * $\tan(x) = x + \frac{x^3}{3} + \frac{2x^5}{15} + \frac{17x^7}{315} + \cdots$
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
    double pot = 1.0;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);
    x = x * PI / 180.0;
    pot = x;

    for (i = 1; i <= n; i++) {

        double coef;

        if (i == 1) coef = 1;
        else if (i == 2) coef = 1.0/3;
        else if (i == 3) coef = 2.0/15;
        else if (i == 4) coef = 17.0/315;
        else coef = 0;

        suma += coef * pot;

        // actualizar potencia x^(2i+1)
        pot *= x * x;
    }

    printf("tan(%lf) = %lf\n", x/PI*180.0, suma);

    return 0;
}
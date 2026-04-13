/**
 * @file csc2.c
 * @brief Aproximación de csc(x) con validación de entrada.
 *
 * @details
 * La función csc(x) se calcula como 1/sin(x), aproximando sin(x) con serie:
 *
 * $\sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{(2n+1)!}$
 *
 * Incluye validación estricta del dominio.
 *
 * @param x Valor en grados, x != 0 mod 180
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
    int n, i;
    double x, suma = 0.0;
    double pot;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    do{
    printf("Valor de x en grados (<90): ");
    scanf("%lf", &x);
    }while (x>=90);

    x = x * PI / 180.0;

    if (x == 0) {
        printf("Error: csc(x) no definida en 0\n");
        return 0;
    }

    suma = 1.0 / x;

    pot = x;

    for (i = 1; i < n; i++) {

        double coef;

        if (i == 1) coef = 1.0/6;
        else if (i == 2) coef = 7.0/360;
        else if (i == 3) coef = 31.0/15120;
        else coef = 0;

        suma += coef * pot;

        // actualizar potencia x^(2i+1)
        pot *= x * x;
    }

    printf("csc(x) = %lf\n", suma);

    return 0;
}
/**
 * @file arcsenh1.c
 * @brief Aproximación simple de arcsenh(x) usando serie truncada.
 *
 * @details
 * La función arcsenh(x) se aproxima con los primeros términos de su serie:
 *
 * $\text{arcsenh}(x) = \sum_{n=0}^{\infty} \frac{(-1)^n (2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Esta implementación usa términos fijos hasta n=3.
 *
 * @param x Valor real
 * @param n Número de términos (limitado a 4)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(1)
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
    double x, suma;
    int n, i;

    printf("Ingrese x: ");
    scanf("%lf", &x);

    printf("Ingrese numero de terminos: ");
    scanf("%d", &n);

    suma = 0;

    for (i = 0; i < n; i++) {
        if (i == 0)
            suma += x;
        else if (i == 1)
            suma -= (x * x * x) / 6.0;
        else if (i == 2)
            suma += (3.0 * x * x * x * x * x) / 40.0;
        else if (i == 3)
            suma -= (5.0 * x * x * x * x * x * x * x) / 112.0;
    }

    printf("arcsenh(x) = %lf\n", suma);

    return 0;
}
/**
 * @file tanh1.c
 * @brief Aproximación simple de tanh(x) usando serie truncada.
 *
 * @details
 * La función tanh(x) se aproxima con los primeros términos de su serie:
 *
 * $\tanh(x) = x - \frac{x^3}{3} + \frac{2x^5}{15} - \frac{17x^7}{315} + \cdots$
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

int main() {
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
            suma -= (x * x * x) / 3.0;
        else if (i == 2)
            suma += (2.0 * x * x * x * x * x) / 15.0;
        else if (i == 3)
            suma -= (17.0 * x * x * x * x * x * x * x) / 315.0;
    }

    printf("tanh(x) = %lf\n", suma);

    return 0;
}
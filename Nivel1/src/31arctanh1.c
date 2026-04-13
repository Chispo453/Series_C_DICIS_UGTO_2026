/**
 * @file arctanh1.c
 * @brief Aproximación simple de arctanh(x) usando serie de Maclaurin.
 *
 * @details
 * La función arctanh(x) se aproxima con la serie de Maclaurin:
 *
 * $\text{arctanh}(x) = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{2n+1}$
 *
 * Esta implementación calcula potencias desde cero en cada iteración.
 *
 * @param x Valor real tal que |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * La serie diverge si |x| >= 1.
 *
 * @note
 * No se usa math.h.
 */

#include <stdio.h>

int main() {
    int n, i, j;
    double x;
    double suma, potencia;

    /* Validación de número de términos */
    printf("Ingrese el numero de terminos (n >= 1): ");
    scanf("%d", &n);

 
    printf("Ingrese el valor de x (|x| < 1): ");
    scanf("%lf", &x);
       
   

    suma = 0.0;

    for (i = 0; i < n; i++) {
        potencia = 1.0;

        /* Calcular x^(2i+1) desde cero */
        for (j = 0; j < (2*i + 1); j++) {
            potencia *= x;
        }

        suma += potencia / (2*i + 1);
    }

    printf("arctanh(%lf) = %.15lf\n", x, suma);

    return 0;
}
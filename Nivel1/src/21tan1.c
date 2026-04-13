/**
 * @file tan1.c
 * @brief Aproximación simple de tan(x) usando serie de Taylor.
 *
 * @details
 * La función tan(x) se aproxima con la serie de Taylor:
 *
 * $\tan(x) = x + \frac{x^3}{3} + \frac{2x^5}{15} + \frac{17x^7}{315} + \cdots$
 *
 * Esta implementación calcula términos específicos.
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
 * No definido en múltiplos de π/2.
 *
 * @note
 * Convierte grados a radianes.
 */

#include <stdio.h>
#define PI 3.141592653589793


int main(int argc, char *argv[]) {
    int n, i, j;
    double x, suma = 0.0;

    printf("Numero de terminos: ");
    scanf("%d", &n);

    printf("Valor de x: ");
    scanf("%lf", &x);
    x = x * PI / 180.0;

    for (i = 1; i <= n; i++) {

        // potencia x^(2i-1)
        double pot = 1.0;
        for (j = 0; j < (2*i-1); j++) {
            pot *= x;
        }

        // factorial (2i)!
        double fact = 1.0;
        for (j = 1; j <= 2*i; j++) {
            fact *= j;
        }

        // coeficientes conocidos (simplificado)
        double coef;

        if (i == 1) coef = 1;
        else if (i == 2) coef = 1.0/3;
        else if (i == 3) coef = 2.0/15;
        else if (i == 4) coef = 17.0/315;
        else coef = 0; // simplificado

        suma += coef * pot;
    }

    printf("tan(%lf) = %lf\n", x/PI*180.0, suma);

    return 0;
}
/**
 * @file arctan1.c
 * @brief Aproximación simple de arctan(x) usando serie de Taylor.
 *
 * @details
 * La función arctan(x) se aproxima con la serie de Taylor:
 *
 * $\arctan(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{2n+1}$
 *
 * Esta implementación incluye ajuste básico del dominio para |x| > 1.
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
#define PI 3.141592653589793

int main(int argc, char *argv[]) {
    int n, i, j;
    double x, suma = 0.0;
    int caso = 0;

    do {
        printf("Numero de terminos: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);

    
    if (x > 1) {
        x = 1.0 / x;
        caso = 1;
    }
    else if (x < -1) {
        x = 1.0 / x;
        caso = -1;
    }

    for (i = 0; i < n; i++) {

        // x^(2i+1)
        double pot = 1.0;
        for (j = 0; j < 2*i+1; j++) {
            pot *= x;
        }

        int signo = (i % 2 == 0) ? 1 : -1;

        suma += signo * pot / (2*i+1);
    }


    if (caso == 1) {
        suma = PI/2 - suma;
    }
    else if (caso == -1) {
        suma = -PI/2 - suma;
    }

    printf("arctan(x) = %lf\n", suma);

    return 0;

}
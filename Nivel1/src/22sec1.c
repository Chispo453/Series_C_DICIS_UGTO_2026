/**
 * @file sec1.c
 * @brief Aproximación simple de sec(x) usando serie de Taylor.
 *
 * @details
 * La función sec(x) se calcula como 1/cos(x), aproximando cos(x) con serie:
 *
 * $\cos(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n}}{(2n)!}$
 *
 * Luego sec(x) = 1/cos(x).
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

    printf("Valor de x en grados: ");
    scanf("%lf", &x);

    // convertir a radianes
    x = x * PI / 180.0;

    for (i = 0; i < n; i++) {

        // potencia x^(2i)
        double pot = 1.0;
        for (j = 0; j < 2*i; j++) {
            pot *= x;
        }

        // factorial (2i)!
        double fact = 1.0;
        for (j = 1; j <= 2*i; j++) {
            fact *= j;
        }

        // coeficientes conocidos
        double coef;
        if (i == 0) coef = 1;
        else if (i == 1) coef = 1.0/2;
        else if (i == 2) coef = 5.0/24;
        else if (i == 3) coef = 61.0/720;
        else coef = 0;

        suma += coef * pot;
    }

    printf("sec(x) = %lf\n", suma);

    return 0;
}
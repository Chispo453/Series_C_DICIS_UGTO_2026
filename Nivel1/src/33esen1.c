/**
 * @file esen1.c
 * @brief Aproximación simple de $e^{\sin(x)}$ usando series.
 *
 * @details
 * El usuario introduce x en grados.
 * Se convierte internamente a radianes:
 *
 * $rad = grados \cdot \frac{\pi}{180}$
 *
 * Luego:
 *
 * $\sin(x) = \sum (-1)^n \frac{x^{2n+1}}{(2n+1)!}$
 *
 * $e^y = \sum \frac{y^k}{k!}$
 *
 * @param n Numero de terminos (n>=1)
 * @param grados Valor en grados
 * @return 0 si ejecucion correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * Para valores grandes puede haber perdida de precision.
 *
 * @note
 * No se usa math.h. Pi se define manualmente.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n, i, j;
    double grados, x;
    double seno, exp_seno;
    double num, den;
    int signo;
    double PI = 3.14159265358979323846;

    printf("Ingrese numero de terminos (n >= 1): ");
    scanf("%d", &n);

    printf("Ingrese valor de x en grados: ");
    scanf("%lf", &grados);

    x = grados * PI / 180.0;

    seno = 0.0;

    for (i = 0; i < n; i++) {

        signo = 1 - 2*(i % 2);
        num = 1.0;
        den = 1.0;

        for (j = 0; j < (2*i + 1); j++) {
            num *= x;
            den *= (j + 1);
        }

        seno += signo * num / den;
    }

    exp_seno = 0.0;

    for (i = 0; i < n; i++) {

        num = 1.0;
        den = 1.0;

        for (j = 0; j < i; j++) {
            num *= seno;
            den *= (j + 1);
        }

        exp_seno += num / den;
    }

    printf("e^sen(%.2lf grados) = %.15lf\n", grados, exp_seno);

    return 0;
}
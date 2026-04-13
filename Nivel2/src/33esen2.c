/**
 * @file esen2.c
 * @brief Aproximación de $e^{\sin(x)}$ con validación de entrada.
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
    double termino;
    int signo;
    double PI = 3.14159265358979323846;

    do {
        printf("Ingrese numero de terminos (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese valor de x en grados: ");
    scanf("%lf", &grados);

    x = grados * PI / 180.0;

    /* ---- sen(x) incremental ---- */
    seno = 0.0;

    for (i = 0; i < n; i++) {

        signo = 1 - 2*(i % 2);
        termino = 1.0;

        for (j = 0; j < (2*i + 1); j++)
            termino *= (x / (j + 1));

        seno += signo * termino;
    }

    /* ---- e^seno incremental ---- */
    exp_seno = 0.0;

    for (i = 0; i < n; i++) {

        termino = 1.0;

        for (j = 0; j < i; j++)
            termino *= (seno / (j + 1));

        exp_seno += termino;
    }

    printf("e^sen(%.2lf grados) = %.15lf\n", grados, exp_seno);

    return 0;
}
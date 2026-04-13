/**
 * @file ln1x2.c
 * @brief Aproximación de ln(1+x)/(1+x) con cálculo incremental.
 *
 * @details
 * La función se aproxima con la serie:
 *
 * $\frac{\ln(1+x)}{1+x} = \sum_{i=1}^{n} (-1)^{i+1} H_i x^i$
 *
 * Donde $H_i = \sum_{j=1}^{i} \frac{1}{j}$ es el número armónico.
 *
 * Cálculo incremental de H_i y x^i.
 *
 * @param x Valor real, |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * Serie converge para |x| < 1.
 *
 * @note
 * No se usa math.h.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n, i;
    double x;
    double suma, armonico, potencia;
    int signo;

    do {
        printf("Ingrese numero de terminos (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    do {
        printf("Ingrese valor de x (|x| < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: la serie converge solo para |x| < 1\n");
    } while (x <= -1.0 || x >= 1.0);

    suma = 0.0;
    armonico = 0.0;
    potencia = 1.0;

    for (i = 1; i <= n; i++) {

        armonico += 1.0 / i;      /* H_i incremental */
        potencia *= x;            /* x^i incremental */

        signo = (i % 2 == 1) ? 1 : -1;

        suma += signo * armonico * potencia;
    }

    printf("ln(1+x)/(1+x) = %.15lf\n", suma);

    return 0;
}
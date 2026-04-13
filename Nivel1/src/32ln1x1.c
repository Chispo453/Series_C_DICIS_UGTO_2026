/**
 * @file ln1x1.c
 * @brief Aproximación simple de ln(1+x)/(1+x) usando serie con números armónicos.
 *
 * @details
 * La función se aproxima con la serie:
 *
 * $\frac{\ln(1+x)}{1+x} = \sum_{i=1}^{n} (-1)^{i+1} H_i x^i$
 *
 * Donde $H_i = \sum_{j=1}^{i} \frac{1}{j}$ es el número armónico.
 *
 * @param x Valor real, |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
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

    int n, i, j, k;
    double x;
    double suma, armonico, potencia;
    int signo;

    printf("Ingrese numero de terminos (n >= 1): ");
    scanf("%d", &n);


    printf("Ingrese valor de x (|x| < 1): ");
    scanf("%lf", &x);

    suma = 0.0;

    for (i = 1; i <= n; i++) {

        /* Calcular H_i  */
        armonico = 0.0;
        for (j = 1; j <= i; j++) {
            armonico += 1.0 / j;
        }

        /* Calcular x^i  */
        potencia = 1.0;
        for (k = 0; k < i; k++) {
            potencia *= x;
        }

        signo = (i % 2 == 1) ? 1 : -1;

        suma += signo * armonico * potencia;
    }

    printf("ln(1+x)/(1+x) = %.15lf\n", suma);

    return 0;
}
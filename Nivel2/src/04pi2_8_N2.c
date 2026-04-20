/**
 * ── NIVEL 2 ──
 * @file 4pi2_8_N2.c
 * @brief Aproximacion de pi mediante la serie pi^2/8 (estabilizada).
 *
 * @details
 * Serie: pi^2/8 = sum_{i=1}^{n} 1/(2i-1)^2
 * pi = sqrt(8 * suma)
 *
 * Implementacion O(n): ciclo unico, denominadores impares al cuadrado.
 *
 * @par Entrada
 * Entero n >= 1.
 *
 * @par Salida
 * @code
 * pi aproximado     = valor
 * pi real           = valor
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Converge mas rapido que Leibniz pero igual que Basel en orden O(1/n).
 * La precision esta limitada por double (15 decimales).
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double d, k, k_prev, pi_aprox, pi_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    for (i = 1, k = 0.0; i <= n; i++) {
        d  = (double)(2 * i - 1);
        k += 1.0 / (d * d);
    }
    pi_aprox = sqrt(8.0 * k);

    /* Delta_n */
    if (n >= 2) {
        for (i = 1, k_prev = 0.0; i <= n / 2; i++) {
            d = (double)(2 * i - 1);
            k_prev += 1.0 / (d * d);
        }
        pi_prev = sqrt(8.0 * k_prev);
    } else {
        pi_prev = 0.0;
    }

    delta = fabs(pi_aprox - pi_prev);
    nea = delta / (fabs(pi_aprox) > eps ? fabs(pi_aprox) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7lf\n", pi_aprox);
    printf("pi real = %.7lf\n", M_PI);
    printf("Delta_n = %.4e\n", delta);
    printf("nea (error aprox) = %.4e\n",  nea);
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI));

    return 0;
}
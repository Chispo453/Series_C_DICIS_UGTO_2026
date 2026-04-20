/**
 * ── NIVEL 2 ──
 * @file 2pi_4_N2.c
 * @brief Aproximacion de pi mediante la serie de Leibniz (estabilizada).
 *
 * @details
 * Serie: pi/4 = 1 - 1/3 + 1/5 - 1/7 + ...
 * sum_{i=1}^{n} (-1)^(i+1) / (2i-1)
 * pi = 4 * suma
 *
 * Implementacion O(n): ciclo unico, denominadores impares.
 * No hay dominio adicional que validar.
 *
 * @par Entrada
 * Entero n >= 1.
 *
 * @par Salida
 * @code
 * pi aproximado = valor
 * pi real       = valor
 * Delta_n       = valor
 * nea           = valor
 * Error absoluto= valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Convergencia muy lenta: se necesitan 10^6 terminos para 5 decimales.
 * Es la serie mas lenta para pi de todas las de esta practica.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, s;
    double den, k, pi_aprox, pi_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    for (i = 1, k = 0.0; i <= n; i++) {
        s = (i % 2 == 0) ? -1 : 1;
        den = (double)(2 * i - 1);
        k  += s * (1.0 / den);
    }
    pi_aprox = 4.0 * k;

    /* Serie con n/2 terminos para Delta_n */
    if (n >= 2) {
        for (i = 1, k = 0.0; i <= n / 2; i++) {
            s = (i % 2 == 0) ? -1 : 1;
            den = (double)(2 * i - 1);
            k+= s * (1.0 / den);
        }
        pi_prev = 4.0 * k;
    } else {
        pi_prev = 0.0;
    }

    delta = fabs(pi_aprox - pi_prev);
    nea = delta / (fabs(pi_aprox) > eps ? fabs(pi_aprox) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7lf\n", pi_aprox);
    printf("pi real = %.7lf\n", M_PI);
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox) = %.4e\n", nea);
    printf("Error absoluto= %.4e\n",  fabs(pi_aprox - M_PI));

    return 0;
}
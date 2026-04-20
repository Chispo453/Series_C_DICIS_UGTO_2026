/**
 * ── NIVEL 2 ──
 * @file 3pi2_6_N2.c
 * @brief Aproximacion de pi mediante la serie de Basel pi^2/6 (estabilizada).
 *
 * @details
 * Serie de Basel: pi^2/6 = sum_{i=1}^{n} 1/i^2
 * pi = sqrt(6 * suma)
 *
 * Implementacion O(n): ciclo unico, un termino 1/i^2 por iteracion.
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
 * Converge mas rapido que Leibniz (O(1/n) vs O(1/n)),
 * pero el error en pi crece por la raiz cuadrada aplicada a la suma.
 * El limite de precision esta dictado por double (15 decimales).
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double k, k_prev, pi_aprox, pi_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    for (i = 1, k = 0.0; i <= n; i++)
        k += 1.0 / ((double)i * (double)i);
    pi_aprox = sqrt(6.0 * k);

    
    if (n >= 2) {
        for (i = 1, k_prev = 0.0; i <= n / 2; i++)
            k_prev += 1.0 / ((double)i * (double)i);
        pi_prev = sqrt(6.0 * k_prev);
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
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI));

    return 0;
}
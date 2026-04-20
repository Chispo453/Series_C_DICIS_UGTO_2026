/**
 * ── NIVEL 3 ──
 * @file 3pi2_6_N3.c
 * @brief Aproximacion de pi con serie de Basel por recurrencia O(n).
 *
 * @details
 * Serie: pi^2/6 = sum_{i=1}^{n} 1/i^2
 *
 * Recurrencia del termino:
 *   ter_1     = 1    (i=1: 1/1^2)
 *   ter_{i+1} = ter_i * i^2/(i+1)^2
 *
 * Derivacion:
 *   ter_i     = 1/i^2
 *   ter_{i+1} = 1/(i+1)^2
 *             = ter_i * i^2/(i+1)^2
 *
 * La serie ya es O(n); la recurrencia elimina la multiplicacion
 * doble i*i en cada iteracion.
 *
 * @par Entrada
 * @param n  Entero >= 1.
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
 * La convergencia es O(1/n): necesita 10^10 terminos para 10 decimales en pi.
 * Para alta precision se prefieren series con convergencia exponencial.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double k, k_prev, ter, pi_aprox, pi_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    /* ── Por recurrencia ── */
    for (i = 1, k = 0.0, ter = 1.0; i <= n; i++) {
        k+= ter;
        ter *= (double)i * (double)i / ((double)(i + 1) * (double)(i + 1));
    }
    pi_aprox = sqrt(6.0 * k);

    
    if (n >= 2) {
        for (i = 1, k_prev = 0.0, ter = 1.0; i <= n / 2; i++) {
            k_prev += ter;
            ter*= (double)i * (double)i / ((double)(i + 1) * (double)(i + 1));
        }
        pi_prev = sqrt(6.0 * k_prev);
    } else {
        pi_prev = 0.0;
    }

    delta = fabs(pi_aprox - pi_prev);
    nea   = delta / (fabs(pi_aprox) > eps ? fabs(pi_aprox) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("pi aproximado = %.7lf\n", pi_aprox);
    printf("pi real = %.7lf\n", M_PI);
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox) = %.4e\n", nea);
    printf("Error absoluto = %.4e\n", fabs(pi_aprox - M_PI));

    return 0;
}
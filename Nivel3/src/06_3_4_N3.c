/**
 * ── NIVEL 3 ──
 * @file 6_3_4_N3.c
 * @brief Aproximacion de 3/4 con serie telescopica por recurrencia O(n).
 *
 * @details
 * Serie: 3/4 = sum_{i=1}^{n} 1/[i*(i+2)]
 *
 * Recurrencia del termino:
 *   ter_1     = 1/(1*3)
 *   ter_{i+1} = ter_i * i*(i+2) / [(i+1)*(i+3)]
 *
 * Derivacion:
 *   ter_i     = 1/[i*(i+2)]
 *   ter_{i+1} = 1/[(i+1)*(i+3)]
 *   ter_i * i*(i+2) / [(i+1)*(i+3)]
 *
 * @par Entrada
 * @param n  Entero >= 1.
 *
 * @par Salida
 * @code
 * Suma aproximada   = valor
 * Referencia        = 0.7500000
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * La forma cerrada de la suma parcial es S_n = 3/4 - (2n+3)/[2*(n+1)*(n+2)],
 * lo que confirma la convergencia a 3/4 al ritmo O(1/n^2).
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double suma, suma_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    /* Por recurrencia */
    /* ter_1 = 1/(1*3) = 1/3 */
    for (i = 1, suma = 0.0, ter = 1.0 / 3.0; i <= n; i++) {
        suma += ter;
        ter  *= (double)i * (double)(i + 2) /
                ((double)(i + 1) * (double)(i + 3));
    }

    /*Serie para Delta_n */
    if (n >= 2) {
        for (i = 1, suma_prev = 0.0, ter = 1.0 / 3.0; i <= n / 2; i++) {
            suma_prev += ter;
            ter *= (double)i * (double)(i + 2) /
                         ((double)(i + 1) * (double)(i + 3));
        }
    } else {
        suma_prev = 0.0;
    }

    delta = fabs(suma - suma_prev);
    nea   = delta / (fabs(suma) > eps ? fabs(suma) : eps);

    printf("\nAproximacion para n = %d terminos:\n", n);
    printf("Suma aproximada = %.7lf\n", suma);
    printf("Referencia = 0.7500000\n");
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox) = %.4e\n", nea);
    printf("Error absoluto = %.4e\n", fabs(suma - 0.75));

    return 0;
}
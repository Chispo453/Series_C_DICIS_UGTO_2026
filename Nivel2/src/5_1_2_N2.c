/**
 * ── NIVEL 2 ──
 * @file 5_1_2_N2.c
 * @brief Aproximacion de 1/2 con serie telescopica (estabilizada).
 *
 * @details
 * Serie: 1/2 = sum_{i=1}^{n} 1/[(2i-1)*(2i+1)]
 *
 * Implementacion O(n): ciclo unico, denominadores directos.
 *
 * @par Entrada
 * Entero n >= 1.
 *
 * @par Salida
 * @code
 * Suma aproximada   = valor
 * Referencia        = 0.5000000
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Converge lentamente: con n=1000 el error es ~2.5e-04.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, d1, d2;
    double suma, suma_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    for (i = 1, suma = 0.0; i <= n; i++) {
        d1= 2 * i - 1;
        d2 = 2 * i + 1;
        suma += 1.0 / ((double)d1 * (double)d2);
    }

    /* Serie para Delta_n */
    if (n >= 2) {
        for (i = 1, suma_prev = 0.0; i <= n / 2; i++) {
            d1= 2*i - 1;
            d2= 2*i + 1;
            suma_prev += 1.0 / ((double)d1 * (double)d2);
        }
    } else {
        suma_prev = 0.0;
    }

    delta = fabs(suma - suma_prev);
    nea = delta / (fabs(suma) > eps ? fabs(suma) : eps);

    printf("\nAproximacion para n = %d terminos:\n", n);
    printf("Suma aproximada = %.7lf\n", suma);
    printf("Referencia = 0.5000000\n");
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox) = %.4e\n",  nea);
    printf("Error absoluto = %.4e\n",  fabs(suma - 0.5));

    return 0;
}
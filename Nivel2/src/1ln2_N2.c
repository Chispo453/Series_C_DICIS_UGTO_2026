/** 
 * ── NIVEL 2 ──
 * @file 1ln2_N2.c
 * @brief Aproximacion de ln(2) con serie alternante (estabilizada).
 *
 * @details
 * Serie: ln(2) = 1 - 1/2 + 1/3 - 1/4 + ...
 * sum_{i=1}^{n} (-1)^(i+1) / i
 *
 * Implementacion O(n): ciclo unico, sin ciclo interno.
 * No hay dominio para validar (serie de constante).
 *
 * @par Entrada
 * Entero n >= 1.
 *
 * @par Salida
 * @code
 * ln(2) aproximado = valor
 * ln(2) real       = valor
 * Delta_n          = valor
 * nea              = valor
 * Error absoluto   = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Serie armonica alternante: converge muy lentamente.
 * Con n=10000 el error aun es del orden 5e-05.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i, s;
    double ln2, ln2_prev, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    
    for (i = 1, ln2 = 0.0; i <= n; i++) {
        s    = (i % 2 == 0) ? -1 : 1;
        ln2 += s * (1.0 / (double)i);
    }

    /* Serie con n/2 terminos para Delta_n*/
    if (n >= 2) {
        for (i = 1, ln2_prev = 0.0; i <= n / 2; i++) {
            s         = (i % 2 == 0) ? -1 : 1;
            ln2_prev += s * (1.0 / (double)i);
        }
    } else {
        ln2_prev = 0.0;
    }

    delta = fabs(ln2 - ln2_prev);
    nea   = delta / (fabs(ln2) > eps ? fabs(ln2) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(2) aproximado = %.7lf\n", ln2);
    printf("ln(2) real  = %.7lf\n", log(2.0));
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox)= %.4e\n",  nea);
    printf("Error absoluto = %.4e\n",  fabs(ln2 - log(2.0)));

    return 0;
}
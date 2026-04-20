/**
 * ── NIVEL 3 ──
 * @file 1ln2_N3.c
 * @brief Aproximacion de ln(2) con recurrencia O(n).
 *
 * @details
 * Serie: ln(2) = sum_{i=1}^{n} (-1)^(i+1) / i
 *
 * Recurrencia del termino con signo:
 *   ter_1     = 1       (i=1: +1/1)
 *   ter_{i+1} = -ter_i * i / (i+1)
 *
 * Derivacion:
 *   ter_i     = (-1)^(i+1) / i
 *   ter_{i+1} = (-1)^(i+2) / (i+1)
 *             = -ter_i * i / (i+1)
 *
 * Para esta serie ya era O(n) en Nivel 2; la recurrencia aqui
 * evita calcular el signo con modulo en cada iteracion.
 *
 * @par Entrada
 * @param n  Entero >= 1.
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
 * La convergencia lenta es intrinseca a la serie; no hay mejora
 * de velocidad de convergencia entre N2 y N3, solo de implementacion.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double ln2, ln2_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    /* Por recurrencia  */
    /* ter_1 = 1, ter_{i+1} = -ter_i * i/(i+1) */
    for (i = 1, ln2 = 0.0, ter = 1.0; i <= n; i++) {
        ln2 += ter;
        ter *= -(double)i / (double)(i + 1);
    }

    /* Serie con n/2 terminos para Delta_n */
    if (n >= 2) {
        for (i = 1, ln2_prev = 0.0, ter = 1.0; i <= n / 2; i++) {
            ln2_prev += ter;
            ter      *= -(double)i / (double)(i + 1);
        }
    } else {
        ln2_prev = 0.0;
    }

    delta = fabs(ln2 - ln2_prev);
    nea   = delta / (fabs(ln2) > eps ? fabs(ln2) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(2) aproximado = %.7lf\n", ln2);
    printf("ln(2) real = %.7lf\n", log(2.0));
    printf("Delta_n = %.4e\n",  delta);
    printf("nea (error aprox)= %.4e\n",  nea);
    printf("Error absoluto = %.4e\n",  fabs(ln2 - log(2.0)));

    return 0;
}
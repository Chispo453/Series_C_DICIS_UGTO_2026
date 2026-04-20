/** 
 * ── NIVEL 3 ──
 * @file 14binomio_N3.c
 * @brief Aproximacion de (1+x)^alfa con recurrencia del binomio. O(n).
 *
 * @details
 * Serie: (1+x)^alfa = sum_{i=0}^{n} C(alfa,i) * x^i
 *
 * Recurrencia del termino completo t_i = C(alfa,i) * x^i:
 *   t_0     = 1
 *   t_{i+1} = t_i * (alfa - i) / (i + 1) * x
 *
 * Derivacion:
 *   t_i     = [alfa*(alfa-1)*...*(alfa-i+1) / i!] * x^i
 *   t_{i+1} = [alfa*(alfa-1)*...*(alfa-i)  / (i+1)!] * x^(i+1)
 *    = t_i * (alfa - i) / (i + 1) * x
 *
 * Elimina los tres ciclos internos (num, den, multi): O(n).
 *
 * @par Entrada
 * @param n     Entero >= 1.
 * @param x     Real con |x| < 1.
 * @param alfa  Real (exponente de la potencia).
 *
 * @par Salida
 * @code
 * (1+x)^alfa aproximado = valor
 * (1+x)^alfa real       = valor
 * Delta_n               = valor
 * nea                   = valor
 * Error absoluto        = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Si alfa es entero no negativo, la serie termina exactamente en i=alfa
 * (los terminos siguientes son 0 porque (alfa - alfa) = 0).
 * El bucle puede detenerse antes si |t_i| < eps (convergencia anticipada).
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, alfa, ter, ter_prev, t, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Ingrese el valor de x (|x| < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= -1.0 || x >= 1.0);

    printf("Ingrese el valor de alfa: ");
    scanf("%lf", &alfa);

    /* ── Serie con n terminos por recurrencia ── */
    /* t_0 = 1  (i=0: C(alfa,0)*x^0 = 1) */
    for (i = 0, ter = 0.0, t = 1.0; i <= n; i++) {
        ter += t;
        t   *= (alfa - (double)i) / (double)(i + 1) * x;
    }

    /* Serie para Delta_n */
    if (n >= 2) {
        for (i = 0, ter_prev = 0.0, t = 1.0; i <= n / 2; i++) {
            ter_prev += t;
            t        *= (alfa - (double)i) / (double)(i + 1) * x;
        }
    } else {
        ter_prev = 0.0;
    }

    delta = fabs(ter - ter_prev);
    nea   = delta / (fabs(ter) > eps ? fabs(ter) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("(1+%.4lf)^%.4lf aproximado = %.7lf\n", x, alfa, ter);
    printf("(1+%.4lf)^%.4lf real       = %.7lf\n", x, alfa, pow(1.0 + x, alfa));
    printf("Delta_n                     = %.4e\n",  delta);
    printf("nea (error aprox)           = %.4e\n",  nea);
    printf("Error absoluto              = %.4e\n",  fabs(ter - pow(1.0 + x, alfa)));

    return 0;
}
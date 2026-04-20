/**
 * ── NIVEL 3 ──
 * @file 10ln_1+x_N3.c
 * @brief Aproximacion de ln(1+x) con recurrencia O(n).
 *
 * @details
 * Serie: ln(1+x) = sum_{i=1}^{n} (-1)^(i+1) * x^i / i
 *
 * Recurrencia del termino (sin signo):
 *   p_1     = x
 *   p_{i+1} = p_i * x           potencia x^(i+1)
 *
 * Termino completo: t_i = (-1)^(i+1) * p_i / i
 *
 * Reformulado con signo incluido en ter:
 *   ter_1     = x
 *   ter_{i+1} = -ter_i * x * i / (i+1)
 *
 * Esto evita el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real con dominio -1 < x <= 1.
 *
 * @par Salida
 * @code
 * ln(1+x) aproximado = valor
 * ln(1+x) real       = valor
 * Delta_n            = valor
 * nea                = valor
 * Error absoluto     = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Cerca de x = 1 la convergencia es lenta (serie armonica alternante).
 * Se necesitan muchos terminos para alta precision en ese extremo.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, ln, ln_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Indique el valor de x (-1 < x <= 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x > 1.0)
            printf("Error: El valor de x esta fuera del dominio permitido para esta serie.\n");
    } while (x <= -1.0 || x > 1.0);

    /* ── Serie con n terminos por recurrencia ── */
    /* ter_i = (-1)^(i+1) * x^i / i  =>  ter_1 = x */
    /* recurrencia: ter_{i+1} = -ter_i * x * i/(i+1) */
    for (i = 1, ln = 0.0, ter = x; i <= n; i++) {
        ln  += ter;
        ter *= -x * (double)i / (double)(i + 1);
    }

    
    if (n >= 2) 
    {
        for (i = 1, ln_prev = 0.0, ter = x; i <= n / 2; i++) 
        {
            ln_prev += ter;
            ter     *= -x * (double)i / (double)(i + 1);
        }
    } else {
        ln_prev = 0.0;
    }

    delta = fabs(ln - ln_prev);
    nea   = delta / (fabs(ln) > eps ? fabs(ln) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(1+%.4lf) aproximado = %.7lf\n", x, ln);
    printf("ln(1+%.4lf) real       = %.7lf\n", x, log(1.0 + x));
    printf("Delta_n                = %.4e\n",  delta);
    printf("nea (error aprox)      = %.4e\n",  nea);
    printf("Error absoluto         = %.4e\n",  fabs(ln - log(1.0 + x)));

    return 0;
}
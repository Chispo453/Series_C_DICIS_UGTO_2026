 /**
 * ── NIVEL 3 ──
 * @file 15ax_N3.c
 * @brief Aproximacion de a^x con recurrencia O(n).
 *
 * @details
 * Identidad: a^x = e^(x*ln(a)) = e^u  con u = x*ln(a)
 * Serie: a^x = sum_{i=0}^{n-1} u^i / i!
 *
 * Recurrencia del termino (identica a e^x pero con u):
 *   t_0     = 1
 *   t_{i+1} = t_i * u / (i+1)
 *
 * Elimina los ciclos internos: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param a  Real a > 0 y a != 1.
 * @param x  Real (todos los reales).
 *
 * @par Salida
 * @code
 * a^x aproximado = valor
 * a^x real       = valor
 * Delta_n        = valor
 * nea            = valor
 * Error absoluto = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Si u = x*ln(a) es muy grande (base grande o exponente grande),
 * los terminos iniciales crecen antes de decrecer, lo que puede
 * causar cancelacion catastrofica. Se recomienda |u| <= 700 con double.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, a, u, ax, ax_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    do {
        printf("Ingrese el valor de a (a > 0, a != 1): ");
        scanf("%lf", &a);
        if (a <= 0.0 || a == 1.0)
            printf("Error: El valor de a esta fuera del dominio permitido para esta serie.\n");
    } while (a <= 0.0 || a == 1.0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    u = x * log(a);   /* sustitucion: u = x*ln(a) */

   
    for (i = 0, ax = 0.0, ter = 1.0; i < n; i++) {
        ax  += ter;
        ter *= u / (i + 1);   /* t_{i+1} = t_i * u/(i+1) */
    }

    if (n >= 2) {
        for (i = 0, ax_prev = 0.0, ter = 1.0; i < n / 2; i++) {
            ax_prev += ter;
            ter     *= u / (i + 1);
        }
    } else {
        ax_prev = 0.0;
    }

    delta = fabs(ax - ax_prev);
    nea   = delta / (fabs(ax) > eps ? fabs(ax) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("%.4lf^%.4lf aproximado = %.7lf\n", a, x, ax);
    printf("%.4lf^%.4lf real       = %.7lf\n", a, x, pow(a, x));
    printf("Delta_n                = %.4e\n",  delta);
    printf("nea (error aprox)      = %.4e\n",  nea);
    printf("Error absoluto         = %.4e\n",  fabs(ax - pow(a, x)));

    return 0;
}
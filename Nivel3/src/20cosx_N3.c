/**
 * ── NIVEL 3 ──
 * @file 20cosx_N3.c
 * @brief Aproximacion de cos(x) con recurrencia O(n).
 *
 * @details
 * Serie: cos(x) = sum_{i=0}^{n-1} (-1)^i * x^(2i) / (2i)!
 *
 * Recurrencia del termino t_i = (-1)^i * x^(2i) / (2i)!:
 *   t_0     = 1
 *   t_{i+1} = t_i * (-x^2) / [(2i+1)*(2i+2)]
 *
 * Derivacion:
 *   t_i     = (-1)^i * x^(2i)   / (2i)!
 *   t_{i+1} = (-1)^(i+1) * x^(2i+2) / (2i+2)!
 *           = t_i * (-x^2) / [(2i+1)*(2i+2)]
 *
 * Elimina el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real (radianes).
 *
 * @par Salida
 * @code
 * cos(x) aproximado = valor
 * cos(x) real       = valor
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Para |x| > 2*pi se recomienda fmod(x, 2*M_PI) antes del calculo
 * para reducir la cancelacion en la suma alternante.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, xcos, xcos_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x (radianes): ");
    scanf("%lf", &x);


    /* t_0 = 1, t_{i+1} = t_i * (-x^2) / [(2i+1)(2i+2)] */
    for (i = 0, xcos = 0.0, ter = 1.0; i < n; i++) {
        xcos += ter;
        ter  *= -(x * x) / ((double)(2 * i + 1) * (double)(2 * i + 2));
    }

    /* Serie con n/2 terminos para Delta_n */
    if (n >= 2) {
        for (i = 0, xcos_prev = 0.0, ter = 1.0; i < n / 2; i++) {
            xcos_prev += ter;
            ter       *= -(x * x) / ((double)(2 * i + 1) * (double)(2 * i + 2));
        }
    } else {
        xcos_prev = 0.0;
    }

    delta = fabs(xcos - xcos_prev);
    nea   = delta / (fabs(xcos) > eps ? fabs(xcos) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("cos(%.4lf) aproximado = %.7lf\n", x, xcos);
    printf("cos(%.4lf) real       = %.7lf\n", x, cos(x));
    printf("Delta_n               = %.4e\n",  delta);
    printf("nea (error aprox)     = %.4e\n",  nea);
    printf("Error absoluto        = %.4e\n",  fabs(xcos - cos(x)));

    return 0;
}
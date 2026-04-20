/**
 * ── NIVEL 3 ──
 * @file 19senx_N3.c
 * @brief Aproximacion de sen(x) con recurrencia O(n).
 *
 * @details
 * Serie: sen(x) = sum_{i=0}^{n-1} (-1)^i * x^(2i+1) / (2i+1)!
 *
 * Recurrencia del termino positivo t_i = x^(2i+1) / (2i+1)!:
 *   t_0     = x
 *   t_{i+1} = t_i * (-x^2) / [(2i+2)*(2i+3)]
 *
 * Derivacion:
 *   t_i     = x^(2i+1)   / (2i+1)!
 *   t_{i+1} = x^(2i+3)   / (2i+3)!
 *           = t_i * x^2 / [(2i+2)*(2i+3)]
 * El signo alternante se absorbe en la recurrencia con -x^2.
 *
 * Elimina el ciclo interno: O(n).
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real (radianes).
 *
 * @par Salida
 * @code
 * sen(x) aproximado = valor
 * sen(x) real       = valor
 * Delta_n           = valor
 * nea               = valor
 * Error absoluto    = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Para |x| > 2*pi es recomendada la reduccion de rango con fmod(x, 2*M_PI)
 * para evitar cancelacion catastrofica en la suma alternante.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, sen, sen_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x (radianes): ");
    scanf("%lf", &x);

    /* Recurrencia */
    /* t_0 = x, signo absorbido: t_{i+1} = t_i * (-x^2) / [(2i+2)(2i+3)] */
    for (i = 0, sen = 0.0, ter = x; i < n; i++) {
        sen += ter;
        ter *= -(x * x) / ((double)(2 * i + 2) * (double)(2 * i + 3));
    }

    /* Delta_n */
    if (n >= 2) {
        for (i = 0, sen_prev = 0.0, ter = x; i < n / 2; i++) {
            sen_prev += ter;
            ter      *= -(x * x) / ((double)(2 * i + 2) * (double)(2 * i + 3));
        }
    } else {
        sen_prev = 0.0;
    }

    delta = fabs(sen - sen_prev);
    nea   = delta / (fabs(sen) > eps ? fabs(sen) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("sen(%.4lf) aproximado = %.7lf\n", x, sen);
    printf("sen(%.4lf) real       = %.7lf\n", x, sin(x));
    printf("Delta_n               = %.4e\n",  delta);
    printf("nea (error aprox)     = %.4e\n",  nea);
    printf("Error absoluto        = %.4e\n",  fabs(sen - sin(x)));

    return 0;
}
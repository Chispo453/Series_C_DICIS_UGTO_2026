/** 
 * ── NIVEL 3 ──
 * @file 8xex_N3.c
 * @brief Aproximacion de xe^x con recurrencia O(n).
 *
 * @details
 * Serie: xe^x = sum_{i=1}^{n} i * x^i / i! = sum_{i=1}^{n} x^i / (i-1)!
 *
 * Recurrencia del termino base (igual que e^x):
 *   b_1     = x
 *   b_{i+1} = b_i * x / (i+1)       <- esto es x^(i+1)/(i)!  ... x^i/i!
 *
 * El termino de la serie es:  t_i = i * b_i  con b_i = x^i / i!
 * Entonces:  t_i = i * b_i
 * Y la recurrencia de b: b_{i+1} = b_i * x/(i+1)
 *
 * @par Entrada
 * @param n  Entero >= 1.
 * @param x  Real (todos los reales).
 *
 * @par Salida
 * @code
 * xe^x aproximado = valor
 * xe^x real       = valor
 * Delta_n         = valor
 * nea             = valor
 * Error absoluto  = valor
 * @endcode
 *
 * @par Complejidad
 * Tiempo: O(n). Memoria: O(1).
 *
 * @warning
 * Para x = 0 la serie vale 0 exactamente desde el primer termino.
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int    n, i;
    double x, xex, xex_prev, ter, delta, nea, eps;

    eps = 1e-20;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Ingrese el valor de x: ");
    scanf("%lf", &x);

    /* ─Serie con n terminos por recurrencia ─ */
    /* ter arranca como b_1 = x  (= x^1/1!) */
    for (i = 1, xex = 0.0, ter = x; i <= n; i++) {
        xex += i * ter;           /* t_i = i * b_i */
        ter *= x / (i + 1);       /* b_{i+1} = b_i * x/(i+1) */
    }

    /* ─Serie con n/2 terminos (Delta_n) ─ */
    if (n >= 2) {
        for (i = 1, xex_prev = 0.0, ter = x; i <= n / 2; i++) {
            xex_prev += i * ter;
            ter      *= x / (i + 1);
        }
    } else {
        xex_prev = 0.0;
    }

    delta = fabs(xex - xex_prev);
    nea   = delta / (fabs(xex) > eps ? fabs(xex) : eps);

    printf("\nResultados para n = %d terminos:\n", n);
    printf("%.4lf*e^%.4lf aproximado = %.7lf\n", x, x, xex);
    printf("%.4lf*e^%.4lf real       = %.7lf\n", x, x, x * exp(x));
    printf("Delta_n                  = %.4e\n",  delta);
    printf("nea (error aprox)        = %.4e\n",  nea);
    printf("Error absoluto           = %.4e\n",  fabs(xex - x * exp(x)));

    return 0;
}
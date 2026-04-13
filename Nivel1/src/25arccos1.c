/**
 * @file arccos1.c
 * @brief Aproximación simple de arccos(x) usando serie de Taylor.
 *
 * @details
 * La función arccos(x) se calcula utilizando la identidad trigonométrica:
 *
 * $\arccos(x) = \frac{\pi}{2} - \arcsin(x)$
 *
 * Donde $\arcsin(x)$ se aproxima con la serie de Taylor:
 *
 * $\arcsin(x) = \sum_{n=0}^{\infty} \frac{(2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Esta implementación calcula factoriales y potencias en cada iteración,
 * lo que resulta en una complejidad mayor.
 *
 * @param x Valor en el intervalo [-1, 1]
 * @param n Número de términos de la serie (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(1)
 *
 * @warning
 * La serie converge lentamente cerca de x = ±1.
 *
 * @note
 * No se usa math.h. Pi se define manualmente.
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(int argc, char *argv[]) {
    int n, i, j;
    double x, suma = 0.0;

   
    printf("Numero de terminos: ");
    scanf("%d", &n);
   

    printf("Valor de x (entre -1 y 1): ");
    scanf("%lf", &x);

    if (x < -1 || x > 1) {
        printf("Error: fuera del dominio\n");
        return 0;
    }

    for (i = 0; i < n; i++) {

        double termino;

        if (i == 0) {
            termino = x;
        } else {

            // (2i)!
            double fact2i = 1.0;
            for (j = 1; j <= 2*i; j++) {
                fact2i *= j;
            }

            // (i!)^2
            double facti = 1.0;
            for (j = 1; j <= i; j++) {
                facti *= j;
            }

            // 4^i
            double pot4 = 1.0;
            for (j = 0; j < i; j++) {
                pot4 *= 4.0;
            }

            // x^(2i+1)
            double potx = 1.0;
            for (j = 0; j < 2*i+1; j++) {
                potx *= x;
            }

            termino = (fact2i / (pot4 * facti * facti * (2*i+1))) * potx;
        }

        suma += termino;
    }

    double resultado = (PI/2.0) - suma;

    printf("arccos(x) = %lf\n", resultado);

    return 0;
}
/**
 *  ── NIVEL 1 ── 
 * @file 20cosx.c
 * @brief Aproximación de cos(x) mediante serie de Maclaurin.
 *
 * @details
 * Serie: cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
 * Esta serie utiliza únicamente potencias pares y factoriales pares.
 *
 * @par Entrada
 *  Entero n >= 1 (cantidad de términos).
 *  Real x (valor del ángulo en radianes).
 *
 * @par Salida
 * Valor aproximado de cos(x), referencia de math.h y error absoluto.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Debido al crecimiento del factorial par (2i)!, el tipo float
 * presentará overflow. 
 * El error absoluto crecerá drásticamente si x es grande,
 * el numerador también puede causar que el resultado sea 'nan' o 'inf'
 */


#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int i, n, j;
    float num, den, sig, ter, xcos, x;

    /* ... validacion de n, a > 0, a != 1 ... */

    do
    {
       printf("Indique el numero de terminos:");
       scanf("%d", &n);
    } while (n<=0);

    
    printf("\nIngresa el valor de x:");
    scanf("%f", &x);


    for (i = 0, xcos = 0; i < n; i++)
    {
        for (j = 0, num = 1, den = 1; j < (2*i); j++)
        {
            num *= x;          /* acumula x^2i  */
            den *= (j + 1);    /* acumula i!   */
        }
        sig = -2*(i%2)+1;
        ter = sig * (num / den);
        xcos += ter;
    }

    printf("\n Resultados para n = %d terminos:\n", n);
    printf("cos(%.4f) aproximado =  %.7f \n", x, xcos);
    printf("cos(%.4f) real math.h = %.7f \n", x, cos(x));
    printf("Error absoluto =  %.4e \n", fabs(xcos - cos(x)));

    return 0;
}
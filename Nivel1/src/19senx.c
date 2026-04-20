/**
 *  ── NIVEL 1 ── 
 * @file 19senx.c
 * @brief Aproximación de sen(x).
 *
 * @details
 * Serie: sen(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 * Se calculan potencias y factoriales impares mediante ciclos anidados.
 *
 * @par Entrada: Entero n (términos) y flotante x (radianes).
 * @par Salida: sen(x) aproximado, valor real y error absoluto.
 *
 * @par Complejidad: Tiempo O(n^2), Memoria O(1).
 *
 * @warning 
 * El factorial (2i+1)! crece muy rápido.
 * El float se desbordará cerca de i=16 .
 */


#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int i, n, j;
    float num, den, sig, ter, sen, x;

    /* ... validacion de n */

    do
    {
       printf("Indique el numero de terminos:");
       scanf("%d", &n);
    } while (n<=0);

    
    printf("\nIngresa el valor de x:");
    scanf("%f", &x);


    for (i = 0, sen = 0; i < n; i++)
    {
        for (j = 0, num = 1, den = 1; j < (2*i+1); j++)
        {
            num *= x;          /* acumula x^2i+1  */
            den *= (j + 1);    /* acumula i!   */
        }
        sig = -2*(i%2)+1;
        ter = sig * (num / den);
        sen += ter;
    }

    printf("\n Resultados para n = %d terminos:\n", n);
    printf("sen(%.4f) aproximado =  %.7f \n", x, sen);
    printf("sen(%.4f) real math.h = %.7f \n", x, sin(x));
    printf("Error absoluto =  %.4e \n", fabs(sen - sin(x)));

    return 0;
}
/**
 *  ── NIVEL 1 ── 
 * @file 14binomio.c
 * @brief Aproximación de (1+x)^alfa mediante la Serie Binomial.
 *
 * @details
 * Serie: 1 + alfa*x + [alfa*(alfa-1)/2!]*x^2 + [alfa*(alfa-1)*(alfa-2)/3!]*x^3 + ...
 * Esta serie generaliza el binomio de Newton para exponentes no enteros (reales).
 *
 * @par Entrada
 *  Numero entero n >= 1 (términos).
 *  Numero real x en el dominio (-1,1).
 *  Numero real alfa (exponente de la potencia).
 *
 * @par Salida
 * Valor aproximado de (1+x)^alfa, valor real (pow) y error absoluto.
 *
 * @par Complejidad
 * Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * La serie solo converge si |x| < 1. Si x está fuera de este rango, 
 * los términos crecerán infinitamente.
 */


#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
    int i, j, n;
    float x, alfa, num, den, multi, ter;

    /*Validacion para n y x */

    do
    {
        printf("Indique el numero de terminos:");
        scanf("%d", &n);

    }while(n<1);

    do
    {
        printf("\n Ingrese el valor de x que sea |x|<1:");
        scanf("%f", &x);

    }while(x <= -1 || x >=1); /* para dominio de |x| < 1*/

    printf("Ingrese el valor de alfa: ");
    scanf("%f", &alfa);

    /*primer ciclo */
    for (i=0, ter=0; i<n+1; i++)
    {
        for(j=0, num=1, den=1, multi=1; j<i; j++)
        {
            num   *= (alfa -j);    /**/
            den   *= (j+1);        /**/
            multi *= x;            /*x^i*/
        }
        ter+= (num/den) * multi;  

    }

    printf("\n Resultados para n = %d terminos:\n", n);
    printf("(1+ %f )^ %f aproximado =  %.7f \n", x, alfa, ter);
    printf("(1+ %f )^ %f real math.h = %.7f \n", x, alfa, pow(1+x, alfa));  /*pow para potencia*/
    printf("Error absoluto =  %.4e \n", fabs(ter - pow(1+x, alfa)));

    return 0;
}
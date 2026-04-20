/** 
 * ── NIVEL 1 ── 
 * @file 15ax.c
 * @brief Aproximación de la potencia general a^x usando la serie de e^u.
 *
 * @details
 * Basado en la identidad: a^x = e^(x * ln(a)).
 * Se define u = x * ln(a) y se aplica la serie de Maclaurin:
 * a^x = 1 + u + u^2/2! + u^3/3! + ... + u^n/n!
 *
 * @par Entrada
 *  Entero n >= 1 (numero de términos).
 *  Real a > 0 y a != 1 (base con restricción).
 *  Real x (exponente).
 *
 * @par Complejidad
 *
  Tiempo: O(n^2). Memoria: O(1).
 *
 * @warning
 * Al igual que para E_ex.c, calcular por separado el num (u^i) y den (i!) 
 * provoca un desbordamiento por el tipo float cerca de n=34.
 */


#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int i, n, j;
    float x, a,u,ax,num,den, t;

    /* ... validacion de n, a > 0, a != 1 ... */

    do
    {
       printf("Indique el numero de terminos:");
       scanf("%d", &n);
    } while (n<=0);


    do
    {
        printf("\nIngresa el valor de a que sea a>0 y a!=1:");
        scanf("%f", &a);

    } while(a==1 || a<=0);

    
    printf("\nIngresa el valor de x:");
    scanf("%f", &x);

     u = x * log(a);   /* sustitucion: u = x*ln(a) */

    for (i = 0, ax = 0; i < n; i++)
    {
        for (j = 0, num = 1, den = 1; j < i; j++)
        {
            num *= u;          /* acumula u^i  */
            den *= (j + 1);    /* acumula i!   */
        }
        t   = num / den;
        ax += t;
    }

    printf("\n Resultados para n = %d terminos:\n", n);
    printf("%.4f^%.4f aproximado =  %.7f \n", a, x, ax);
    printf("%.4f^%.4f real math.h = %.7f \n", a, x, pow(a,x));
    printf("Error absoluto =  %.4e \n", fabs(ax - pow(a,x)));

    return 0;
}
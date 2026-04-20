/**
 *  ── NIVEL 1 ── 
 * @file 10ln_1+x.c
 * 
 * @brief Aproximacion de ln(1+x) con serie de Maclaurin.
 *
 * @details
 * Serie: ln(1+x) = x - x^2/2 + x^3/3 - x^4/4 + ...
 *   sum_{i=1}^{inf} (-1)^(i+1) * x^i / i
 *
 * Termino i: signo * (x^i / i), i va de 1 a n.
 *
 * @par Entrada
 *   Numero entero n >= 1 (numero de terminos).
 *   Real x con dominio -1 < x <= 1.
 *
 * @par Salida
 * Imprime ln(1+x) aproximado, valor de referencia (math.h) y error absoluto.
 *
 * @par Complejidad
 * Tiempo: O(n^2), ciclo externo n terminos, ciclo interno x^i.
 * Memoria: O(1), uso de memoria constante.
 *
 * @warning
 * La serie solo converge para -1 < x <= 1.
 * No acepta x fuera de ese dominio.
 */

#include <stdio.h>

#include <math.h> 

/*uso de math.h para la comparación*/


int main(int argc, char *argv[])

{

/*s: signo, n: numero terminos, i: contador */

int n, i, s;

float num, den, x, j, ln, k;

do{
printf("Indique el numero de terminos: ");
scanf("%d", &n);
}while(n<=0);


do{
   printf("Indique el valor de x (-1 < x <= 1):");
   scanf("%f", &x);
}while(-1>=x || x>1); /*para -1<x<=1*/


    for(i=1, ln=0, k=0; i<n+1; i++)

    {

    s = -1*(1-2*(i%2));  /* +1 o -1 alternando */

    den = i;

    for(j=0, num=1; j<i; j++) 

       num *= x;

    k = s*(num/den); 

    ln += k;   /* acumulador */   

    }

    
    printf("\nResultados para n = %d terminos:\n", n);
    printf("ln(1+x) aproximado = %.7f\n", ln);   /* 7 dígitos por precisión,por ser tipo float */
    printf("ln(1+x) real (math.h) = %.7f\n", log(1+x)); 
    printf("Error absoluto = %.4e\n", fabs(ln - log(1+x)));   /* comparacion con log */

return 0;

}
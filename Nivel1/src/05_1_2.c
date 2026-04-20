/**
 *  ── NIVEL 1 ── 
 * @file 5_1_2.c
 * @brief Aproximacion de 1/2 con serie telescopica de fracciones parciales.
 *
 * @details
 * Serie:
 *  1/2 = 1/(1*3) + 1/(3*5) + 1/(5*7) + ...  (n terminos)
 *
 * Este programa aproxima con n terminos:
 * 1/ ((2i-1)*(2i+1))
 *        
 * Implementacion:
 *   Para cada i calcula d1 = 2i-1 y d2 = 2i+1 como enteros.
 *   El termino es 1.0 / (d1 * d2) y se acumula en suma.
 *
 * @par Entrada
 *   Un entero n >= 1.
 *
 * @par Salida
 * Imprime:
 *
 * @code
 * Suma           = valor
 * Referencia     = 0.5000000
 * Error absoluto = valor
 * @endcode
 *
 * @warning
 * La serie converge lentamente: se necesitan muchos terminos para
 * obtener alta precision. Con n=1000 el error aun es del orden 2.5e-04.
 * No hay riesgo de overflow.
 */
 

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n, i, d1, d2;   /* d1, d2 = los dos factores del denominador */
    float suma;

    do {
        printf("Indique el numero de terminos: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (i = 1, suma = 0; i <= n; i++) {
        d1 = 2*i - 1;            /* primer factor del denominador */
        d2 = 2*i + 1;            /* segundo factor del denominador */
        suma += 1.0 / (d1 * d2); /*guarda numerador y multiplicacion de denominadores para la suma*/
    }

    
    printf("\n Aproximacion para n = %d terminos: \n", n );
    printf("Suma = %f\n", suma);
    printf("Referencia  = 0.500000\n");
    printf("Error absoluto: %.4e\n", fabs(suma - 0.500000));
    return 0;
}
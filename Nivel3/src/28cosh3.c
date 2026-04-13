/**
 * @file cosh3.c
 * @brief Aproximación optimizada de cosh(x) mediante serie con recurrencia.
 *
 * @details
 * Serie:
 *
 * $\cosh(x) = \sum_{n=0}^{\infty} \frac{x^{2n}}{(2n)!}$
 *
 * Recurrencia:
 *
 * $t_{n+1} = t_n \cdot \frac{x^2}{(2n+1)(2n+2)}$
 *
 * @param x Valor real
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * Para valores grandes de x, los términos crecen rápidamente.
 *
 * @note
 * Evita recalcular factoriales y potencias.
 */

#include <stdio.h>

/**
 * @brief Lee x y n y aproxima cosh(x) por la serie de Taylor.
 *
 * @dot
 * digraph flujo_cosh3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar_n [shape=diamond,label="n < 1?"];
 *   leer_x [shape=box,label="Leer x"];
 *   init [shape=box,label="termino = 1, suma = 0"];
 *   i_loop [shape=diamond,label="i < n"];
 *   acumular [shape=box,label="suma += termino"];
 *   actualizar [shape=box,label="termino *= x*x/((2i+1)(2i+2))"];
 *   salida [shape=box,label="Imprimir cosh(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_n;
 *   leer_n -> validar_n;
 *   validar_n -> leer_n [label="sí"];
 *   validar_n -> leer_x [label="no"];
 *   leer_x -> init;
 *   init -> i_loop;
 *   i_loop -> acumular [label="sí"];
 *   acumular -> actualizar;
 *   actualizar -> i_loop;
 *   i_loop -> salida [label="no"];
 *   salida -> fin;
 * }
 * @enddot
 */
int main(int argc, char *argv[]) {
    int n, i;
    double x, suma = 0.0;
    double termino;

    do {
        printf("Numero de terminos (>=1): ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);

    // primer término: 1
    termino = 1.0;

    for (i = 0; i < n; i++) {

        suma += termino;

        termino *= x * x / ((2.0*i+1)*(2.0*i+2));
    }

    printf("cosh(x) = %lf\n", suma);

    return 0;
}
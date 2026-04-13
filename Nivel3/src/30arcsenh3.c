/**
 * @file arcsenh3.c
 * @brief Aproximación optimizada de arcsenh(x) usando serie con recurrencia.
 *
 * @details
 * Fórmula:
 * $\text{arcsenh}(x) = \sum_{n=0}^{\infty} \frac{(-1)^n (2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Recurrencia:
 * $t_{n+1} = -t_n \cdot \frac{(2n-1)^2 x^2}{(2n)(2n+1)}$
 *
 * @param x Valor real, |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta, 1 si error
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * Precisión limitada para valores grandes de x.
 *
 * @note
 * Usa recurrencia para evitar factoriales.
 */

#include <stdio.h>

/**
 * @brief Lee x y n y aproxima arcsenh(x) mediante serie de Taylor con signo alternante.
 *
 * @dot
 * digraph flujo_arcsenh3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_x [shape=box,label="Leer x"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar [shape=diamond,label="|x| >= 1?"];
 *   error [shape=box,label="Imprimir error y retornar 1"];
 *   init [shape=box,label="termino=x, suma=x"];
 *   i_loop [shape=diamond,label="i < n"];
 *   actualizar [shape=box,label="termino *= -(2i-1)^2*x^2/((2i)(2i+1)); suma += termino"];
 *   salida [shape=box,label="Imprimir arcsenh(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_x;
 *   leer_x -> leer_n;
 *   leer_n -> validar;
 *   validar -> error [label="sí"];
 *   validar -> init [label="no"];
 *   init -> i_loop;
 *   i_loop -> actualizar [label="sí"];
 *   actualizar -> i_loop;
 *   i_loop -> salida [label="no"];
 *   salida -> fin;
 * }
 * @enddot
 */
int main() {
    double x, suma = 0, termino;
    int n, i;

    printf("x: ");
    scanf("%lf", &x);

    printf("n: ");
    scanf("%d", &n);

    if (x <= -1 || x >= 1) {
        printf("Error: |x| < 1\n");
        return 1;
    }

    termino = x;
    suma = termino;

    for (i = 1; i < n; i++) {
        termino *= - ( (2.0*i-1)*(2.0*i-1)*x*x ) / ( (2.0*i)*(2.0*i+1) );
        suma += termino;
    }

    printf("arcsenh(x) = %lf\n", suma);
}
/**
 * @file arctanh3.c
 * @brief Aproximación de arctanh(x) mediante su serie de Maclaurin optimizada.
 *
 * @details
 * Serie:
 * $\text{arctanh}(x) = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{2n+1}$
 *
 * Recurrencia:
 * $t_0 = x$
 * $t_{n+1} = t_n \cdot x^2 \cdot \frac{2n+1}{2n+3}$
 *
 * @param x Valor real tal que |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * La serie diverge si |x| >= 1.
 *
 * @note
 * Esta versión evita recalcular potencias y reduce la acumulación de error numérico.
 */

#include <stdio.h>

/**
 * @brief Lee n y x, valida dominio y aproxima arctanh(x) con serie de Maclaurin.
 *
 * @dot
 * digraph flujo_arctanh3 {
 *   inicio [shape=oval,label="Inicio"];
 *   validar_n [shape=diamond,label="n < 1?"];
 *   leer_x [shape=box,label="Leer x"];
 *   validar_x [shape=diamond,label="|x| >= 1?"];
 *   mensaje_error [shape=box,label="Imprimir error y repetir"];
 *   init [shape=box,label="suma=0, termino=x"];
 *   i_loop [shape=diamond,label="i < n"];
 *   acumular [shape=box,label="suma += termino"];
 *   actualizar [shape=box,label="termino *= x*x*(2i+1)/(2i+3)"];
 *   salida [shape=box,label="Imprimir arctanh(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> validar_n;
 *   validar_n -> validar_n [label="sí"];
 *   validar_n -> leer_x [label="no"];
 *   leer_x -> validar_x;
 *   validar_x -> mensaje_error [label="sí"];
 *   mensaje_error -> leer_x;
 *   validar_x -> init [label="no"];
 *   init -> i_loop;
 *   i_loop -> acumular [label="sí"];
 *   acumular -> actualizar;
 *   actualizar -> i_loop;
 *   i_loop -> salida [label="no"];
 *   salida -> fin;
 * }
 * @enddot
 */
int main() {

    int n, i;
    double x;
    double suma;
    double termino;

    /* Validación de número de términos */
    do {
        printf("Ingrese el numero de terminos (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Validación de dominio */
    do {
        printf("Ingrese el valor de x (|x| < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: arctanh(x) solo converge para |x| < 1\n");
    } while (x <= -1.0 || x >= 1.0);

    suma = 0.0;
    termino = x;   /* t0 */

    for (i = 0; i < n; i++) {

        suma += termino;

        /* Actualizar al siguiente término */
        termino = termino * x * x * (2.0*i + 1.0) / (2.0*i + 3.0);
    }

    printf("arctanh(%lf) = %.15lf\n", x, suma);

    return 0;
}
/**
 * @file arccos3.c
 * @brief Aproximación de arccos(x) usando serie de arcsin con recurrencia optimizada.
 *
 * @details
 * Se usa la identidad:
 *
 * $\arccos(x) = \frac{\pi}{2} - \arcsin(x)$
 *
 * y la serie:
 *
 * $\arcsin(x) = \sum_{n=0}^{\infty} \frac{(2n)!}{4^n (n!)^2 (2n+1)} x^{2n+1}$
 *
 * Recurrencia:
 *
 * $t_{n+1} = t_n \cdot \frac{(2n+1)^2}{(2n+2)(2n+3)} \cdot x^2$
 *
 * @param x Valor en [-1,1]
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * La serie converge lentamente cerca de x = ±1.
 *
 * @note
 * Se calcula arcsin(x) y luego se usa la identidad trigonométrica.
 */

#include <stdio.h>

#define PI 3.141592653589793

/**
 * @brief Lee x y n y aproxima arccos(x) usando arccos(x)=pi/2 - arcsen(x).
 *
 * @dot
 * digraph flujo_arccos3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_x [shape=box,label="Leer x"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar [shape=diamond,label="|x| >= 1?"];
 *   error [shape=box,label="Imprimir error y retornar 1"];
 *   init [shape=box,label="termino = x, suma = x"];
 *   i_loop [shape=diamond,label="i < n"];
 *   actualizar [shape=box,label="termino *= ((2i-1)^2*x^2)/((2i)(2i+1))"];
 *   acumular [shape=box,label="suma += termino"];
 *   calcular [shape=box,label="resultado = pi/2 - suma"];
 *   salida [shape=box,label="Imprimir arccos(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_x;
 *   leer_x -> leer_n;
 *   leer_n -> validar;
 *   validar -> error [label="sí"];
 *   validar -> init [label="no"];
 *   init -> i_loop;
 *   i_loop -> actualizar [label="sí"];
 *   actualizar -> acumular;
 *   acumular -> i_loop;
 *   i_loop -> calcular [label="no"];
 *   calcular -> salida;
 *   salida -> fin;
 * }
 * @enddot
 */
int main(int argc, char *argv[]) {
    double x, suma = 0, termino, pi = 3.1416;
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
        termino *= ( (2.0*i-1)*(2.0*i-1)*x*x ) / ( (2.0*i)*(2.0*i+1) );
        suma += termino;
    }

    printf("arccos(x) = %lf\n", (pi/2) - suma);
}
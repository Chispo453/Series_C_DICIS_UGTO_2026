/**
 * @file arctan3.c
 * @brief Aproximación optimizada de arctan(x) usando serie con ajuste de dominio.
 *
 * @details
 * Serie:
 * $\arctan(x) = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{2n+1}$
 *
 * Para |x| > 1:
 * $\arctan(x) = \frac{\pi}{2} - \arctan(1/x)$   (x > 1)
 * $\arctan(x) = -\frac{\pi}{2} - \arctan(1/x)$  (x < -1)
 *
 * Recurrencia:
 * $t_{n+1} = -t_n \cdot x^2 \cdot \frac{2n+1}{2n+3}$
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
 * Converge lentamente cerca de |x| = 1.
 *
 * @note
 * Se ajusta automáticamente el dominio para mejorar convergencia.
 */

#include <stdio.h>

#define PI 3.141592653589793
 
/**
 * @brief Lee x y n y aproxima arctan(x) con ajuste de dominio cuando |x|>=1.
 *
 * @dot
 * digraph flujo_arctan3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_x [shape=box,label="Leer x"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar_directa [shape=diamond,label="|x| < 1?"];
 *   iniciar_directa [shape=box,label="termino=x, suma=x"];
 *   for_directa [shape=diamond,label="i < n"];
 *   actualizar_directa [shape=box,label="termino *= -x*x; suma += termino/(2i+1)"];
 *   inv_calc [shape=box,label="inv=1/x, termino=inv, suma=inv"];
 *   for_inversa [shape=diamond,label="i < n"];
 *   actualizar_inversa [shape=box,label="termino *= -inv*inv; suma += termino/(2i+1)"];
 *   ajustar [shape=diamond,label="x > 0?"];
 *   aplicar_signo [shape=box,label="suma = ±pi/2 - suma"];
 *   salida [shape=box,label="Imprimir arctan(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_x;
 *   leer_x -> leer_n;
 *   leer_n -> validar_directa;
 *   validar_directa -> iniciar_directa [label="sí"];
 *   validar_directa -> inv_calc [label="no"];
 *   iniciar_directa -> for_directa;
 *   for_directa -> actualizar_directa [label="sí"];
 *   actualizar_directa -> for_directa;
 *   for_directa -> salida [label="no"];
 *   inv_calc -> for_inversa;
 *   for_inversa -> actualizar_inversa [label="sí"];
 *   actualizar_inversa -> for_inversa;
 *   for_inversa -> ajustar [label="no"];
 *   ajustar -> aplicar_signo [label="sí"];
 *   ajustar -> aplicar_signo [label="no"];
 *   aplicar_signo -> salida;
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

    if (x > -1 && x < 1) {

        termino = x;
        suma = termino;

        for (i = 1; i < n; i++) {
            termino *= -x*x;
            suma += termino / (2*i+1);
        }

    } else {
        double inv = 1/x;

        termino = inv;
        suma = termino;

        for (i = 1; i < n; i++) {
            termino *= -inv*inv;
            suma += termino / (2*i+1);
        }

        if (x > 0)
            suma = pi/2 - suma;
        else
            suma = -pi/2 - suma;
    }

    printf("arctan(x) = %lf\n", suma);
}
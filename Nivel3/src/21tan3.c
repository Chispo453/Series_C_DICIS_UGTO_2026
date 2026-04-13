/**
 * @file tan3.c
 * @brief Aproximación optimizada de tan(x) mediante serie de potencias.
 *
 * @details
 * Serie de Taylor:
 *
 * $\tan(x) = x + \frac{x^3}{3} + \frac{2x^5}{15} + \frac{17x^7}{315} + \cdots$
 *
 * Se usa actualización incremental de potencia:
 *
 * $x^{2i+1} = x^{2i-1} \cdot x^2$
 *
 * evitando recalcular potencias desde cero.
 *
 * @param x Valor en grados
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * La serie diverge cerca de $\pm \frac{\pi}{2}$.
 *
 * @note
 * Este método es más eficiente que recalcular potencias en cada iteración.
 */

#include <stdio.h>
#define PI 3.141592653589793

/**
 * @brief Lee x y n, convierte grados a radianes y calcula tan(x) por serie.
 *
 * @dot
 * digraph flujo_tan3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer [shape=box,label="Leer n"];
 *   validar [shape=diamond,label="n < 1?"];
 *   leer_x [shape=box,label="Leer x y convertir a radianes"];
 *   init [shape=box,label="pot = x"];
 *   i_loop [shape=diamond,label="i <= n"];
 *   coef [shape=diamond,label="i == 1/2/3/4?"];
 *   sumar [shape=box,label="suma += coef * pot"];
 *   actualizar [shape=box,label="pot *= x*x"];
 *   salida [shape=box,label="Imprimir tan(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer;
 *   leer -> validar;
 *   validar -> leer [label="sí"];
 *   validar -> leer_x [label="no"];
 *   leer_x -> init;
 *   init -> i_loop;
 *   i_loop -> coef [label="sí"];
 *   coef -> sumar;
 *   sumar -> actualizar;
 *   actualizar -> i_loop;
 *   i_loop -> salida [label="no"];
 *   salida -> fin;
 * }
 * @enddot
 */
int main(int argc, char *argv[]) {
    int n, i;
    double x, suma = 0.0;
    double pot;

    // Validación
    do {
        printf("Numero de terminos (>=1): ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x: ");
    scanf("%lf", &x);
    x = x * PI / 180.0; // Convertir a radianes

    // inicial
    pot = x;

    for (i = 1; i <= n; i++) {

        double coef;

        if (i == 1) coef = 1;
        else if (i == 2) coef = 1.0/3;
        else if (i == 3) coef = 2.0/15;
        else if (i == 4) coef = 17.0/315;
        else coef = 0;

        suma += coef * pot;

        // recurrencia de potencia
        pot *= x * x;
    }

    printf("tan(%lf) = %lf\n", x/PI*180.0, suma);

    return 0;
}
/**
 * @file sec3.c
 * @brief Aproximación optimizada de sec(x) usando serie de Maclaurin.
 *
 * @details
 * Serie:
 *
 * $\sec(x) = 1 + \frac{x^2}{2} + \frac{5x^4}{24} + \frac{61x^6}{720} + \cdots$
 *
 * Se usa actualización incremental de potencia:
 *
 * $x^{2i} = x^{2i-2} \cdot x^2$
 *
 * @param x Ángulo en grados (convertido internamente a radianes)
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * La función sec(x) no está definida en $x = \frac{\pi}{2} + k\pi$.
 *
 * @note
 * Se convierte automáticamente de grados a radianes.
 */

#include <stdio.h>

#define PI 3.141592653589793

/**
 * @brief Lee x y n para aproximar sec(x) con una serie de Maclaurin.
 *
 * @dot
 * digraph flujo_sec3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar_n [shape=diamond,label="n < 1?"];
 *   leer_x [shape=box,label="Leer x en grados"];
 *   convertir [shape=box,label="x = x*pi/180"];
 *   advertencia [shape=diamond,label="|x| > 1.5?"];
 *   init [shape=box,label="pot = 1"];
 *   i_loop [shape=diamond,label="i < n"];
 *   coef [shape=diamond,label="i == 0/1/2/3?"];
 *   acumular [shape=box,label="suma += coef * pot"];
 *   actualizar [shape=box,label="pot *= x*x"];
 *   salida [shape=box,label="Imprimir sec(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_n;
 *   leer_n -> validar_n;
 *   validar_n -> leer_n [label="sí"];
 *   validar_n -> leer_x [label="no"];
 *   leer_x -> convertir;
 *   convertir -> advertencia;
 *   advertencia -> init;
 *   init -> i_loop;
 *   i_loop -> coef [label="sí"];
 *   coef -> acumular;
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
    double pot;

    // validación
    do {
        printf("Numero de terminos (>=1): ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Valor de x en grados: ");
    scanf("%lf", &x);

    // conversión a radianes
    x = x * PI / 180.0;

    // validación de dominio
    if (x > 1.5 || x < -1.5) {
        printf("Advertencia: x cercano a punto donde sec(x) diverge\n");
    }

    pot = 1.0;

    for (i = 0; i < n; i++) {

        double coef;

        if (i == 0) coef = 1;
        else if (i == 1) coef = 1.0/2;
        else if (i == 2) coef = 5.0/24;
        else if (i == 3) coef = 61.0/720;
        else coef = 0;

        suma += coef * pot;

        // recurrencia
        pot *= x * x;
    }

    printf("sec(x) = %lf\n", suma);

    return 0;
}
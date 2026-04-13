/**
 * @file esen3.c
 * @brief Aproximación de $e^{\sin(x)}$ usando recurrencias optimizadas.
 *
 * @details
 * El usuario introduce x en grados.
 * Se convierte internamente a radianes:
 *
 * $rad = grados \cdot \frac{\pi}{180}$
 *
 * Luego:
 *
 * $\sin(x) = \sum (-1)^n \frac{x^{2n+1}}{(2n+1)!}$
 *
 * usando recurrencia:
 * $t_0 = x$
 * $t_{n+1} = t_n \cdot \frac{x^2}{(2n+2)(2n+3)}$
 *
 * $e^y = \sum \frac{y^k}{k!}$
 *
 * usando:
 * $s_0 = 1$
 * $s_{k+1} = s_k \cdot \frac{y}{k+1}$
 *
 * @param n Numero de terminos (n>=1)
 * @param grados Valor en grados
 * @return 0 si ejecucion correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * Para valores grandes puede haber perdida de precision.
 *
 * @note
 * No se usa math.h. Pi se define manualmente.
 */

#include <stdio.h>

/**
 * @brief Lee n y grados y calcula e^{sen(x)} mediante series optimizadas.
 *
 * @dot
 * digraph flujo_esen3 {
 *   inicio [shape=oval,label="Inicio"];
 *   validar_n [shape=diamond,label="n < 1?"];
 *   leer_grados [shape=box,label="Leer grados"];
 *   convertir [shape=box,label="x = grados*pi/180"];
 *   init_seno [shape=box,label="termino_seno = x, seno = 0"];
 *   i_seno [shape=diamond,label="i < n"];
 *   actualizar_seno [shape=box,label="seno += signo * termino_seno; termino_seno *= (x/(2i+2))*(x/(2i+3))"];
 *   init_exp [shape=box,label="termino_exp = 1, exp_seno = 0"];
 *   i_exp [shape=diamond,label="i < n"];
 *   actualizar_exp [shape=box,label="exp_seno += termino_exp; termino_exp *= seno/(i+1)"];
 *   salida [shape=box,label="Imprimir e^{sen(x)}"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> validar_n;
 *   validar_n -> validar_n [label="sí"];
 *   validar_n -> leer_grados [label="no"];
 *   leer_grados -> convertir;
 *   convertir -> init_seno;
 *   init_seno -> i_seno;
 *   i_seno -> actualizar_seno [label="sí"];
 *   actualizar_seno -> i_seno;
 *   i_seno -> init_exp [label="no"];
 *   init_exp -> i_exp;
 *   i_exp -> actualizar_exp [label="sí"];
 *   actualizar_exp -> i_exp;
 *   i_exp -> salida [label="no"];
 *   salida -> fin;
 * }
 * @enddot
 */
int main(int argc, char *argv[]) {

    int n, i;
    double grados, x;
    double seno = 0.0;
    double termino_seno;
    double exp_seno = 0.0;
    double termino_exp;
    double PI = 3.14159265358979323846;

    do {
        printf("Ingrese numero de terminos (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Ingrese valor de x en grados: ");
    scanf("%lf", &grados);

    /* Conversion grados -> radianes */
    x = grados * PI / 180.0;

    /* ---- sen(x) optimizado ---- */
    termino_seno = x;

    for (i = 0; i < n; i++) {

        seno += (1 - 2*(i % 2)) * termino_seno;

        termino_seno *= (x / (2*i + 2)) * (x / (2*i + 3));
    }

    /* ---- e^seno optimizado ---- */
    termino_exp = 1.0;

    for (i = 0; i < n; i++) {

        exp_seno += termino_exp;

        termino_exp *= seno / (i + 1);
    }

    printf("e^sen(%.2lf grados) = %.15lf\n", grados, exp_seno);

    return 0;
}
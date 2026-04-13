#include <stdio.h>

/**
 * @file tanh3.c
 * @brief Aproximación de $\tanh(x)$ usando series de Taylor optimizadas.
 *
 * @details
 * La función $\tanh(x)$ se define como:
 *
 * $\tanh(x) = \frac{\sinh(x)}{\cosh(x)}$
 *
 * Donde:
 *
 * $\sinh(x) = \sum_{n=0}^{\infty} \frac{x^{2n+1}}{(2n+1)!}$
 * $\cosh(x) = \sum_{n=0}^{\infty} \frac{x^{2n}}{(2n)!}$
 *
 * En esta implementación se calculan ambas series de manera eficiente
 * utilizando relaciones recursivas entre términos consecutivos:
 *
 * $\sinh_{n+1} = \sinh_n \cdot \frac{x^2}{(2n)(2n+1)}$
 * $\cosh_{n+1} = \cosh_n \cdot \frac{x^2}{(2n-1)(2n)}$
 *
 * Esto evita recalcular potencias y factoriales desde cero en cada iteración,
 * mejorando significativamente el rendimiento.
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
 * La precisión depende del número de términos utilizados.
 *
 * @note
 * No se utiliza math.h ni funciones auxiliares.
 */

/**
 * @brief Lee x y n y calcula tanh(x) como sinh(x)/cosh(x) por series.
 *
 * @dot
 * digraph flujo_tanh3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_x [shape=box,label="Leer x"];
 *   leer_n [shape=box,label="Leer n"];
 *   init [shape=box,label="term_sinh=x, term_cosh=1, sinh=x, cosh=1"];
 *   i_loop [shape=diamond,label="i < n"];
 *   actualizar_sinh [shape=box,label="term_sinh *= x^2/((2i)(2i+1)); sinh += term_sinh"];
 *   actualizar_cosh [shape=box,label="term_cosh *= x^2/((2i-1)(2i)); cosh += term_cosh"];
 *   resultado [shape=box,label="Imprimir sinh/cosh"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_x;
 *   leer_x -> leer_n;
 *   leer_n -> init;
 *   init -> i_loop;
 *   i_loop -> actualizar_sinh [label="sí"];
 *   actualizar_sinh -> actualizar_cosh;
 *   actualizar_cosh -> i_loop;
 *   i_loop -> resultado [label="no"];
 *   resultado -> fin;
 * }
 * @enddot
 */
int main() {
    double x, sinh = 0, cosh = 0;
    double term_sinh, term_cosh;
    int n, i;

    printf("Ingrese x: ");
    scanf("%lf", &x);

    printf("Ingrese numero de terminos: ");
    scanf("%d", &n);

    /** Inicializacion de los primeros terminos */
    term_sinh = x;
    term_cosh = 1;

    sinh = term_sinh;
    cosh = term_cosh;

    /** Calculo de la serie */
    for (i = 1; i < n; i++) {

        /** Relacion recursiva para sinh */
        term_sinh *= x * x / ((2.0 * i) * (2.0 * i + 1));
        sinh += term_sinh;

        /** Relacion recursiva para cosh */
        term_cosh *= x * x / ((2.0 * i - 1) * (2.0 * i));
        cosh += term_cosh;
    }

    printf("tanh(x) = %lf\n", sinh / cosh);

    return 0;
}
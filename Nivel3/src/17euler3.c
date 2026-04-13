/**
 * @file euler3.c
 * @brief Cálculo optimizado del número de Euler E_k usando serie con recurrencia.
 *
 * @details
 * Se implementa la fórmula:
 *
 * $E_k = \frac{2^{2k+2} (2k)!}{\pi^{2k+1}} \cdot \left\{ 1 - \frac{1}{3^{2k+1}} + \frac{1}{5^{2k+1}} - \cdots \right\}$
 *
 * La serie se evalúa mediante recurrencia:
 *
 * $t_n = \frac{1}{(2n+1)^{2k+1}}$
 *
 * $t_{n+1} = t_n \cdot \left(\frac{2n+1}{2n+3}\right)^{2k+1}$
 *
 * @param k Índice del número de Euler (k >= 0)
 * @param iter Número de términos de la serie (iter >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * Para valores grandes de k, el factorial puede crecer mucho.
 *
 * @note
 * Este método es más eficiente que recalcular cada término desde cero.
 */

#include <stdio.h>

#define PI 3.141592653589793

/**
 * @brief Lee k e iter y calcula E_k mediante una serie alternante.
 *
 * @dot
 * digraph flujo_euler3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer [shape=box,label="Leer k e iter"];
 *   validar_k [shape=diamond,label="k < 0?"];
 *   validar_iter [shape=diamond,label="iter < 1?"];
 *   factorial [shape=box,label="factorial = (2k)! "];
 *   init_termino [shape=box,label="termino = 1"];
 *   n_loop [shape=diamond,label="n < iter"];
 *   sign [shape=diamond,label="n par?"];
 *   acumular [shape=box,label="suma += ± termino"];
 *   factor_loop [shape=box,label="Calcular factor rec."];
 *   update_termino [shape=box,label="termino *= factor"];
 *   pot2 [shape=box,label="Calcular 2^(2k+2)"];
 *   potpi [shape=box,label="Calcular pi^(2k+1)"];
 *   resultado [shape=box,label="resultado = (pot2*factorial/potpi)*suma"];
 *   salida [shape=box,label="Imprimir E_k"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer;
 *   leer -> validar_k;
 *   validar_k -> leer [label="sí"];
 *   validar_k -> validar_iter [label="no"];
 *   validar_iter -> leer [label="sí"];
 *   validar_iter -> factorial [label="no"];
 *   factorial -> init_termino;
 *   init_termino -> n_loop;
 *   n_loop -> sign [label="sí"];
 *   sign -> acumular;
 *   acumular -> factor_loop;
 *   factor_loop -> update_termino;
 *   update_termino -> n_loop;
 *   n_loop -> pot2 [label="no"];
 *   pot2 -> potpi;
 *   potpi -> resultado;
 *   resultado -> salida;
 *   salida -> fin;
 * }
 * @enddot
 */
int main(int argc, char *argv[]) {
    int k, n, j, iter;
    double suma = 0.0;
    double termino;
    double factorial = 1.0;
    double resultado;

    // -----------------------------
    // Entrada de datos
    // -----------------------------
    do {
        printf("Ingrese k (>=0): ");
        scanf("%d", &k);
    } while (k < 0);

    do {
        printf("Ingrese numero de iteraciones (>=1): ");
        scanf("%d", &iter);
    } while (iter < 1);

    // -----------------------------
    // Calcular (2k)!
    // -----------------------------
    for (int i = 1; i <= 2*k; i++) {
        factorial *= i;
    }

    // -----------------------------
    // Inicialización del primer término
    // t0 = 1/(1^(2k+1)) = 1
    // -----------------------------
    termino = 1.0;

    // -----------------------------
    // Serie usando recurrencia
    // -----------------------------
    for (n = 0; n < iter; n++) {

        // Alternancia de signo
        if (n % 2 == 0)
            suma += termino;
        else
            suma -= termino;

        // Factor de recurrencia:
        // ((2n+1)/(2n+3))^(2k+1)
        double factor = 1.0;

        for (j = 0; j < (2*k+1); j++) {
            factor *= (double)(2*n+1) / (2*n+3);
        }

        // Actualizar término
        termino *= factor;
    }

    // -----------------------------
    // Calcular 2^(2k+2)
    // -----------------------------
    double pot2 = 1.0;
    for (int i = 0; i < (2*k+2); i++) {
        pot2 *= 2.0;
    }

    // -----------------------------
    // Calcular PI^(2k+1)
    // -----------------------------
    double potpi = 1.0;
    for (int i = 0; i < (2*k+1); i++) {
        potpi *= PI;
    }

    // -----------------------------
    // Resultado final
    // -----------------------------
    resultado = (pot2 * factorial / potpi) * suma;

    // -----------------------------
    // Salida
    // -----------------------------
    printf("E_%d = %.10f\n", k, resultado);

    return 0;
}

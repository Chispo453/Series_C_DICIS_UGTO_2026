/**
 * @file bernouli3.c
 * @brief Cálculo optimizado de números de Bernoulli.
 *
 * @details
 * Se utiliza la recurrencia:
 *
 * $B_0 = 1$
 *
 * $B_k = - \sum_{i=0}^{k-1} \binom{k}{i} \frac{B_i}{k+1-i}$
 *
 * El coeficiente binomial se obtiene por recurrencia:
 *
 * $\binom{k}{0}=1$
 *
 * $\binom{k}{i} = \binom{k}{i-1} \frac{k-i+1}{i}$
 *
 * evitando factoriales y productos repetidos.
 *
 * @param n Índice máximo k (n >= 0)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n^2)
 * Memoria: O(n)
 *
 * @warning
 * Para n grande puede haber inestabilidad numérica.
 *
 * @note
 * Implementación optimizada sin factoriales.
 * No se utiliza math.h.
 */

#include <stdio.h>

/**
 * @brief Lee n y calcula los números de Bernoulli B[0..n].
 *
 * @dot
 * digraph flujo_bernoulli {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar_n [shape=diamond,label="n < 0 o n > 99"];
 *   set_B0 [shape=box,label="B[0] = 1.0"];
 *   k_loop [shape=diamond,label="k <= n"];
 *   init_k [shape=box,label="suma=0, binom=1"];
 *   i_loop [shape=diamond,label="i < k"];
 *   if_binom [shape=diamond,label="i > 0"];
 *   update_binom [shape=box,label="binom *= (k-i+1)/i"];
 *   acumular [shape=box,label="suma += binom * B[i]/(k+1-i)"];
 *   guardar [shape=box,label="B[k] = -suma"];
 *   imprimir [shape=box,label="Imprimir B[0..n]"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_n;
 *   leer_n -> validar_n;
 *   validar_n -> leer_n [label="sí"];
 *   validar_n -> set_B0 [label="no"];
 *   set_B0 -> k_loop;
 *   k_loop -> init_k [label="sí"];
 *   k_loop -> imprimir [label="no"];
 *   init_k -> i_loop;
 *   i_loop -> if_binom [label="sí"];
 *   i_loop -> guardar [label="no"];
 *   if_binom -> update_binom [label="sí"];
 *   if_binom -> acumular [label="no"];
 *   update_binom -> acumular;
 *   acumular -> i_loop;
 *   guardar -> k_loop;
 *   imprimir -> fin;
 * }
 * @enddot
 */
int main() {

    int n, k, i;
    double B[100];
    double suma, binom;

    do {
        printf("Ingrese n (n >= 0): ");
        scanf("%d", &n);
    } while (n < 0 || n > 99);

    B[0] = 1.0;

    for (k = 1; k <= n; k++) {

        suma = 0.0;
        binom = 1.0;

        for (i = 0; i < k; i++) {

            if (i > 0)
                binom *= (double)(k - i + 1) / i;

            suma += binom * B[i] / (k+1-i);
        }

        B[k] = -suma;
    }

    for (k = 0; k <= n; k++)
        printf("B_%d = %.15lf\n", k, B[k]);

    return 0;
}
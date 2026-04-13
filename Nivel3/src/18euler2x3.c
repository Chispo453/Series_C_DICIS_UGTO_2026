/**
 * @file euler3.c
 * @brief Cálculo optimizado del número de Euler E_{2k} usando doble sumatoria.
 *
 * @details
 * Se implementa la fórmula:
 *
 * $E_{2k} = \frac{1}{2^{2k+1}} \cdot \sum_{m=1}^{M} \left[ \frac{1}{m} \cdot \sum_{j=0}^{m} C(m,j) \cdot (-1)^j \cdot (m - 2j)^{2k+1} \right]$
 *
 * Donde:
 * - $C(m,j)$ es la combinación (coeficiente binomial)
 * - La sumatoria interna se optimiza usando una recurrencia para $C(m,j)$:
 *
 * $C(m,j) = C(m,j-1) \cdot \frac{m - j + 1}{j}$
 *
 * Esto evita recalcular factoriales en cada iteración.
 *
 * @param k Índice del número de Euler (k >= 0)
 * @param M Número de términos de la sumatoria externa (M >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(M^2)
 * Memoria: O(1)
 *
 * @warning
 * Para valores grandes de k o M, pueden presentarse errores numéricos.
 *
 * @note
 * Esta versión mejora respecto al cálculo directo, evitando recomputar combinaciones desde cero.
 */

#include <stdio.h>

/**
 * @brief Lee k y M para aproximar E_{2k} con una doble sumatoria.
 *
 * @dot
 * digraph flujo_euler2x3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer [shape=box,label="Leer k, M"];
 *   validar_k [shape=diamond,label="k < 0?"];
 *   validar_M [shape=diamond,label="M < 1?"];
 *   m_loop [shape=diamond,label="m <= M"];
 *   init_interna [shape=box,label="suma_interna=0, comb=1"];
 *   j_loop [shape=diamond,label="j <= m"];
 *   if_comb [shape=diamond,label="j > 0?"];
 *   update_comb [shape=box,label="comb *= (m-j+1)/j"];
 *   sign [shape=box,label="signo = (-1)^j"];
 *   potencia [shape=box,label="Calcular potencia (m-2j)^(2k+1)"];
 *   acumular_interna [shape=box,label="suma_interna += comb*signo*potencia"];
 *   acumular_externa [shape=box,label="suma_total += suma_interna/m"];
 *   divisor [shape=box,label="Calcular divisor 2^(2k+1)"];
 *   resultado [shape=box,label="resultado = suma_total/divisor"];
 *   salida [shape=box,label="Imprimir E_{2k}"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer;
 *   leer -> validar_k;
 *   validar_k -> leer [label="sí"];
 *   validar_k -> validar_M [label="no"];
 *   validar_M -> leer [label="sí"];
 *   validar_M -> m_loop [label="no"];
 *   m_loop -> init_interna [label="sí"];
 *   m_loop -> divisor [label="no"];
 *   init_interna -> j_loop;
 *   j_loop -> if_comb [label="sí"];
 *   if_comb -> update_comb [label="sí"];
 *   if_comb -> sign [label="no"];
 *   update_comb -> sign;
 *   sign -> potencia;
 *   potencia -> acumular_interna;
 *   acumular_interna -> j_loop;
 *   j_loop -> acumular_externa [label="no"];
 *   acumular_externa -> m_loop;
 *   divisor -> resultado;
 *   resultado -> salida;
 *   salida -> fin;
 * }
 * @enddot
 */
int main() {
    int k, M, m, j, i;
    double suma_total = 0.0;

    // -----------------------------
    // Validación de entrada
    // -----------------------------
    do {
        printf("Ingrese k (>=0): ");
        scanf("%d", &k);
    } while (k < 0);

    do {
        printf("Ingrese M (>=1): ");
        scanf("%d", &M);
    } while (M < 1);

    // -----------------------------
    // Sumatoria externa
    // -----------------------------
    for (m = 1; m <= M; m++) {

        double suma_interna = 0.0;
        double comb = 1.0; // C(m,0)

        // -------------------------
        // Sumatoria interna
        // -------------------------
        for (j = 0; j <= m; j++) {

            // Recurrencia de combinación
            if (j > 0) {
                comb = comb * (m - j + 1) / j;
            }

            // Signo alternante (-1)^j
            int signo = (j % 2 == 0) ? 1 : -1;

            // Potencia (m - 2j)^(2k+1)
            int base = m - 2*j;
            double potencia = 1.0;

            for (i = 0; i < (2*k + 1); i++) {
                potencia *= base;
            }

            // Acumulación
            suma_interna += comb * signo * potencia;
        }

        // División entre m
        suma_total += suma_interna / m;
    }

    // -----------------------------
    // División final por 2^(2k+1)
    // -----------------------------
    double divisor = 1.0;
    for (i = 0; i < (2*k + 1); i++) {
        divisor *= 2.0;
    }

    double resultado = suma_total / divisor;

    // -----------------------------
    // Salida
    // -----------------------------
    printf("E_%d = %.10f\n", 2*k, resultado);

    return 0;
}

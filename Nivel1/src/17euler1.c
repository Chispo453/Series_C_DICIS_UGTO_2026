/**
 * @file euler1.c
 * @brief Cálculo simple de números de Euler E_k.
 *
 * @details
 * Los números de Euler se calculan mediante:
 *
 * $E_k = \frac{2^{2k+2} (2k)!}{\pi^{2k+1}} \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n+1)^{2k+1}}$
 *
 * @param k Índice del número de Euler
 * @param max_iter Número de términos de la serie
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(max_iter * k)
 * Memoria: O(1)
 *
 * @warning
 * Requiere muchos términos para precisión.
 *
 * @note
 * No se usa math.h.
 */

#include <stdio.h>

#define PI 3.141592653589793

int main(int argc, char *argv[]) {
    int k, n, max_iter;
    double suma = 0.0;
    double termino;
    double factorial = 1.0;
    double resultado;

    printf("Ingresa el valor de k: ");
    scanf("%d", &k);

    printf("Numero de terminos de la serie: ");
    scanf("%d", &max_iter);

    
    for (int i = 1; i <= 2 * k; i++) {
        factorial *= i;
    }

   
    for (n = 0; n < max_iter; n++) {
        int impar = 2 * n + 1;
        double potencia = 1.0;

        
        for (int j = 0; j < (2 * k + 1); j++) {
            potencia *= impar;
        }

        termino = 1.0 / potencia;

        if (n % 2 == 0) {
            suma += termino;
        } else {
            suma -= termino;
        }
    }

    
    double potencia2 = 1.0;
    for (int i = 0; i < (2 * k + 2); i++) {
        potencia2 *= 2.0;
    }

  
    double potencia_pi = 1.0;
    for (int i = 0; i < (2 * k + 1); i++) {
        potencia_pi *= PI;
    }

    
    resultado = (potencia2 * factorial / potencia_pi) * suma;

    printf("E_%d = %.10f\n", k, resultado);

    return 0;
}
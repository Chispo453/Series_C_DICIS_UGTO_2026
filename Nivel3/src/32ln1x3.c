/**
 * @file ln1x3.c
 * @brief Aproximación optimizada de ln(1+x)/(1+x) mediante serie de potencias.
 *
 * @details
 * Serie:
 *
 * $\frac{\ln(1+x)}{1+x} = \sum_{n=1}^{\infty} (-1)^{n+1} H_n x^n$
 *
 * donde:
 * $H_n = \sum_{k=1}^{n} \frac{1}{k}$ (número armónico)
 *
 * Recurrencias usadas:
 *
 * $H_n = H_{n-1} + \frac{1}{n}$
 * $x^n = x^{n-1} \cdot x$
 *
 * @param x Valor real con |x| < 1
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * La serie diverge si |x| >= 1.
 *
 * @note
 * Esta implementación evita recalcular números armónicos y potencias desde cero.
 */

#include <stdio.h>

/**
 * @brief Lee n y x, valida el dominio y aproxima ln(1+x)/(1+x) por serie.
 *
 * @dot
 * digraph flujo_ln1x3 {
 *   inicio [shape=oval,label="Inicio"];
 *   validar_n [shape=diamond,label="n < 1?"];
 *   leer_x [shape=box,label="Leer x"];
 *   validar_x [shape=diamond,label="|x| >= 1?"];
 *   mensaje_error [shape=box,label="Imprimir error y repetir"];
 *   init [shape=box,label="suma=0, armonico=0, potencia=1"];
 *   i_loop [shape=diamond,label="i <= n"];
 *   actualizar [shape=box,label="armónico += 1/i; potencia *= x"];
 *   signo [shape=diamond,label="i impar?"];
 *   acumular [shape=box,label="suma += signo * armonico * potencia"];
 *   salida [shape=box,label="Imprimir resultado"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> validar_n;
 *   validar_n -> validar_n [label="sí"];
 *   validar_n -> leer_x [label="no"];
 *   leer_x -> validar_x;
 *   validar_x -> mensaje_error [label="sí"];
 *   mensaje_error -> leer_x;
 *   validar_x -> init [label="no"];
 *   init -> i_loop;
 *   i_loop -> actualizar [label="sí"];
 *   actualizar -> signo;
 *   signo -> acumular [label="sí/no"];
 *   acumular -> i_loop;
 *   i_loop -> salida [label="no"];
 *   salida -> fin;
 * }
 * @enddot
 */
int main(int argc, char *argv[]) {

    int n, i;
    double x;
    double suma;
    double armonico;
    double potencia;
    int signo;

    /* Validación n */
    do {
        printf("Ingrese numero de terminos (n >= 1): ");
        scanf("%d", &n);
    } while (n < 1);

    /* Validación dominio */
    do {
        printf("Ingrese valor de x (|x| < 1): ");
        scanf("%lf", &x);
        if (x <= -1.0 || x >= 1.0)
            printf("Error: la serie converge solo para |x| < 1\n");
    } while (x <= -1.0 || x >= 1.0);

    suma = 0.0;
    armonico = 0.0;
    potencia = 1.0;

    for (i = 1; i <= n; i++) {

        armonico += 1.0 / i;
        potencia *= x;

        signo = (i % 2 == 1) ? 1 : -1;

        suma += signo * armonico * potencia;
    }

    printf("ln(1+x)/(1+x) = %.15lf\n", suma);

    return 0;
}
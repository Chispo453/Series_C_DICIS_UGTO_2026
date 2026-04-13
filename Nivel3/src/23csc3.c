/**
 * @file csc3.c
 * @brief Aproximación optimizada de csc(x) mediante serie de potencias.
 *
 * @details
 * Serie de Maclaurin:
 *
 * $\csc(x) = \frac{1}{x} + \frac{x}{6} + \frac{7x^3}{360} + \frac{31x^5}{15120} + \cdots$
 *
 * Se utiliza actualización incremental:
 *
 * $x^{2i+1} = x^{2i-1} \cdot x^2$
 *
 * @param x Ángulo en grados (convertido a radianes)
 * @param n Número de términos (n >= 1)
 * @return 0 si ejecución correcta
 *
 * @par Complejidad
 * Tiempo: O(n)
 * Memoria: O(1)
 *
 * @warning
 * $\csc(x)$ no está definida en $x = k\pi$.
 *
 * @note
 * Incluye conversión automática de grados a radianes.
 */

#include <stdio.h>

#define PI 3.141592653589793

/**
 * @brief Lee n y x para aproximar csc(x) por la serie de Maclaurin.
 *
 * @dot
 * digraph flujo_csc3 {
 *   inicio [shape=oval,label="Inicio"];
 *   leer_n [shape=box,label="Leer n"];
 *   validar_n [shape=diamond,label="n < 1?"];
 *   leer_x [shape=box,label="Leer x en grados (<90)"];
 *   validar_x [shape=diamond,label="x >= 90?"];
 *   convertir [shape=box,label="x = x*pi/180"];
 *   if_zero [shape=diamond,label="x == 0?"];
 *   error [shape=box,label="Imprimir error y salir"];
 *   advertencia [shape=diamond,label="|x| > 3? "];
 *   init [shape=box,label="suma = 1/x, pot = x"];
 *   i_loop [shape=diamond,label="i < n"];
 *   coef [shape=diamond,label="i == 1/2/3?"];
 *   acumular [shape=box,label="suma += coef * pot"];
 *   actualizar [shape=box,label="pot *= x*x"];
 *   salida [shape=box,label="Imprimir csc(x)"];
 *   fin [shape=oval,label="Fin"];
 *   inicio -> leer_n;
 *   leer_n -> validar_n;
 *   validar_n -> leer_n [label="sí"];
 *   validar_n -> leer_x [label="no"];
 *   leer_x -> validar_x;
 *   validar_x -> leer_x [label="sí"];
 *   validar_x -> convertir [label="no"];
 *   convertir -> if_zero;
 *   if_zero -> error [label="sí"];
 *   if_zero -> advertencia [label="no"];
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
    double x, suma;
    double pot;

    // validación
    do {
        printf("Numero de terminos (>=1): ");
        scanf("%d", &n);
    } while (n < 1);

    do{
    printf("Valor de x en grados (<90): ");
    scanf("%lf", &x);
    }while (x>=90);

    // conversión a radianes
    x = x * PI / 180.0;

    if (x == 0) {
        printf("Error: csc(x) no definida en 0\n");
        return 0;
    }

    // advertencia dominio
    if (x > 3.0 || x < -3.0) {
        printf("Advertencia: posible divergencia de la serie\n");
    }

    suma = 1.0 / x;
    pot = x;

    for (i = 1; i < n; i++) {

        double coef;

        if (i == 1) coef = 1.0/6;
        else if (i == 2) coef = 7.0/360;
        else if (i == 3) coef = 31.0/15120;
        else coef = 0;

        suma += coef * pot;
        pot *= x * x;
    }

    printf("csc(x) = %lf\n", suma);

    return 0;
}
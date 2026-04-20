# Series_C_DICIS_UGTO_2026
Repositorio del proyecto de la practica 1 de programación en ingenieria
Autores: Luis Antonio Rincón García, Fátima Alondra Hernandez Garcia

Compilación y ejecución

El proyecto está desarrollado en lenguaje C y contiene múltiples programas organizados por niveles y ejercicios. Cada archivo fuente (.c) puede compilarse de manera independiente.

Requisitos
Compilador de C (se recomienda gcc)
Terminal (Linux, macOS o Windows con MinGW o WSL)

Para verificar que el compilador está instalado:

gcc --version

Compilación

Cada programa debe compilarse de forma individual. Desde la raíz del repositorio o dentro de la carpeta correspondiente, ejecute:

gcc nombre_archivo.c -o nombre_programa

Por ejemplo:

gcc esen1.c -o esen1

En caso de utilizar funciones matemáticas (como sin, cos, exp, etc.), es necesario enlazar la biblioteca matemática:

gcc nombre_archivo.c -o nombre_programa -lm

Ejecución

Una vez compilado el programa, puede ejecutarse desde la terminal:

./nombre_programa

Ejemplo:

./esen1

Algunos programas requieren que el usuario ingrese valores (por ejemplo, x y n). Estos se solicitan directamente en la ejecución o pueden proporcionarse mediante entrada estándar.

Ejemplo con entrada manual:

./esen1

Ejemplo con entrada redirigida:

echo -e "1.0\n10" | ./esen1

Organización del proyecto
Los programas están divididos por niveles de complejidad.
Cada archivo implementa aproximaciones numéricas mediante series.
Los resultados pueden variar dependiendo del número de términos (n) y del valor de entrada (x).
Limpieza (opcional)

Para eliminar archivos ejecutables generados:

rm -f *.o nombre_programa

Notas
Cada archivo contiene su propia función main, por lo que se compilan de forma independiente.
Se recomienda compilar y ejecutar desde la misma carpeta donde se encuentra el archivo fuente.

# Curso-C-plus-plus
Curso avanzado de C ++ con ejemplos didacticos. Ideal para aquellas personas que quieran profundizar en su aprendizaje de este hermoso lenguaje de programacion.

## Diferencia entre semanticas. Semandtica de valor y semantica de referencia. 

 En la semántica de valor, que es la que utiliza C++ por defecto, al copiar un objeto se crea una copia independiente del objeto original. En cambio, en la semántica de referencia, que utilizan otros lenguajes como Java, C# y Python, al inicializar un objeto a partir de otro o pasar un objeto a una función, se obtiene una referencia al objeto original, es decir, no se crea una nueva copia sino que se comparte la misma memoria utilizada por el objeto original.

Para administrar la memoria en la semántica de referencia, muchos lenguajes utilizan un *recolector de basura* ("garbage collector"), un programa interno que mantiene un registro de todos los objetos en el programa y sus relaciones, y que decide qué objetos ya no están en uso y pueden ser eliminados de la memoria. En cambio, en C++, se administra la memoria manualmente, lo que significa que el programador debe asignar y liberar la memoria de los objetos según sea necesario.

La semántica de valor de C++ tiene la ventaja de no requerir el uso de un recolector de basura, lo que significa que no hay sobrecarga adicional en el uso de la memoria o en la interrupción del programa. Además, los objetos locales se destruyen de manera determinista, lo que significa que el programador sabe en qué orden se destruirán y cuándo se liberará su memoria. Sin embargo, la creación de copias de objetos puede tener un costo elevado en términos de rendimiento.

En resumen, el video explora las diferencias entre la semántica de valor y la semántica de referencia en la administración de la memoria, y cómo cada enfoque tiene sus propias ventajas y desventajas en términos de eficiencia y control de la memoria. También se menciona que C++ no utiliza un recolector de basura debido a su énfasis en el rendimiento y la eficiencia.

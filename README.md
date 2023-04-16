# Curso C++ 

### Para abrir la pestaña de Markdown apreta F1 y busca Markdown Open review. 
<!--  Este es un comentario de ejemplo -->
# Conceptos de Repaso
## Funciones

## <span style="color: yellow;">Pasar un una variable por valor </span>
Cuando pasamos una variable a una función y no hacemos nada especial, se pasa por valor. Esto significa que habrá un valor local, "y", dentro de esta función que se inicializará a partir de cualquier variable que pasemos a ella.

Entonces, en este caso, "y" será un entero con el mismo valor que "x", que es dos. La declaración de retorno (return) significa que copiamos y en el valor de retorno de la función.

Por lo tanto, el valor de retorno de la función será dos en este caso.
En este caso tenemos 3 variables creadas en diferentes posiciones de memoria, lo que quiere decir que x,y,z son diferentes "objetos".
Lo que implica que modificar el valor de "y" no afectara al valor de "x".

 ``` C++
#include <iostream>
#include <stdlib.h>

int function (int y){
    std::cout << "Address of y is: " << &y << std::endl;
    return y;
}

int main(int argc, char const *argv[])
{
    int x = 2;
    std::cout << "Address of x is " << &x << std::endl;
    int z = function(x); //z va a ser una copia del valor retornado por la funcion.
    std::cout << "Address of z is: " << &z << std::endl;
    std::cout << "After calling function(), x = " << x << std::endl;
    std::cout << "After calling function(), z = " << z << std::endl;
    return 0;
}
```
#### *Output*

Address of x is 0xd8ae3ffdec  
Address of y is: 0xd8ae3ffdc0   
Address of z is: 0xd8ae3ffde8        
After calling function(), x = 2      
After calling function(), z = 2 

## <span style="color: yellow;">Pasar un valor por direccion de memoria (address)</span>

Ahora, habrá una variable local y, que es un puntero a un entero, y la dirección será la dirección de x.

Si hacemos una operación de desreferenciación (*y), esto nos dará los datos en esa dirección de memoria, que también son utilizados por la variable x.

Entonces, si cambiamos esos datos a uno, entonces x tendrá el valor uno.

 ``` C++
#include <iostream>
#include <stdlib.h>

int function (int *y){ // y will be the address of the caller's variable x.
    std::cout << "Address of y is: " << &y << std::endl;
    *y = 1;
    return *y; // Copy y into the function's return value.
}

int main(int argc, char const *argv[])
{
    int x = 2;
    std::cout << "Address of x is " << &x << std::endl;
    int z = function(&x); //z will be a copy of func's return value.
    std::cout << "Address of z is: " << &z << std::endl;
    std::cout << "After calling function(), x = " << x << std::endl;
    std::cout << "After calling function(), z = " << z << std::endl;
    return 0;
}
```
#### *Output* 

Address of x is 0x22fbbffb6c  
Address of y is: 0x22fbbffb40        
Address of z is: 0x22fbbffb68        
After calling function(), x = 1      
After calling function(), z = 1 

## <span style="color: yellow;">Pasar un valor por referencia</span>
La otra forma de cambiar la dirección de memoria de x es mediante el uso de paso por referencia.

Esto significa que la función ahora toma una referencia en lugar de un puntero.

Por lo tanto, la variable local y aquí será una referencia a x.

Esto significa que y puede acceder a los datos de x.

Por lo general, esto se implementa como un puntero que se desreferencia automáticamente por el compilador.

En efecto, es una forma más simple de escribir lo que teníamos antes.
 ``` C++
#include <iostream>
#include <stdlib.h>

int function (int& y){ // y will be the address of the caller's variable x.
    std::cout << "Address of y is: " << &y << std::endl;
    y = 1;
    return y; // Copy y into the function's return value.
}

int main(int argc, char const *argv[])
{
    int x = 2;
    std::cout << "Address of x is " << &x << std::endl;
    int z = function(x); //z will be a copy of func's return value.
    std::cout << "Address of z is: " << &z << std::endl;
    std::cout << "After calling function(), x = " << x << std::endl;
    std::cout << "After calling function(), z = " << z << std::endl;
    return 0;
}
```
#### *Output* 
Address of x is 0x2cfa9ff90c  
Address of y is: 0x2cfa9ff90c        
Address of z is: 0x2cfa9ff908        
After calling function(), x = 1      
After calling function(), z = 1  

En este caso, el compilador ha implementado la referencia como un puntero a x. Y podemos ver que x tiene el valor de uno cuando se devuelve de la función.
Como se puede apreciar en la salida, ahora las direcciones de memoria de "x" e "y" son iguales, Indicando que "y" es un puntero a "x". 

## <span style="color: yellow;">Pasar un valor por referencia constante (const reference)</span>


Finalmente, algo útil que puedes hacer es pasar por referencia constante.

Esto significa que la cosa a la que se hace referencia no se puede cambiar.

Entonces, si tienes un objeto de clase y tu función solo quiere inspeccionar el objeto, es decir, acceder solo de forma de lectura, lo más eficiente suele ser pasar el objeto por referencia constante.

Al no pasar por valor, no se hace una copia, lo que significa que no hay sobrecarga en la copia de los datos, lo que puede ser bastante costoso para algunas clases, puede implicar muchas operaciones que aumentan el tiempo de ejecución. Y debido a que la referencia es constante, significa que este objeto aquí no se puede cambiar.

 ``` C++
class MyClass {...};

void function(const MyClass& mc){
    ...
}
MyClass my_class;
function(my_class);
```

 ``` C++
#include <iostream>
#include <stdlib.h>

int function (const int& y){ // y will be the address of the caller's variable x.
    std::cout << "Address of y is: " << &y << std::endl;
    //y = 1; Como es constante no puede cambiar de valor
    return y; // Copy y into the function's return value.
}

int main(int argc, char const *argv[])
{
    int x = 2;
    std::cout << "Address of x is " << &x << std::endl;
    int z = function(x); //z will be a copy of func's return value.
    std::cout << "Address of z is: " << &z << std::endl;
    std::cout << "After calling function(), x = " << x << std::endl;
    std::cout << "After calling function(), z = " << z << std::endl;
    return 0;
}
```
## <span style="color: yellow;">Diferencia entre semanticas. Semandtica de valor y semantica de referencia. </span>

 En la semántica de valor, que es la que utiliza C++ por defecto, al copiar un objeto se crea una copia independiente del objeto original. En cambio, en la semántica de referencia, que utilizan otros lenguajes como Java, C# y Python, al inicializar un objeto a partir de otro o pasar un objeto a una función, se obtiene una referencia al objeto original, es decir, no se crea una nueva copia sino que se comparte la misma memoria utilizada por el objeto original.

Para administrar la memoria en la semántica de referencia, muchos lenguajes utilizan un *recolector de basura* ("garbage collector"), un programa interno que mantiene un registro de todos los objetos en el programa y sus relaciones, y que decide qué objetos ya no están en uso y pueden ser eliminados de la memoria. En cambio, en C++, se administra la memoria manualmente, lo que significa que el programador debe asignar y liberar la memoria de los objetos según sea necesario.

La semántica de valor de C++ tiene la ventaja de no requerir el uso de un recolector de basura, lo que significa que no hay sobrecarga adicional en el uso de la memoria o en la interrupción del programa. Además, los objetos locales se destruyen de manera determinista, lo que significa que el programador sabe en qué orden se destruirán y cuándo se liberará su memoria. Sin embargo, la creación de copias de objetos puede tener un costo elevado en términos de rendimiento.

En resumen, el video explora las diferencias entre la semántica de valor y la semántica de referencia en la administración de la memoria, y cómo cada enfoque tiene sus propias ventajas y desventajas en términos de eficiencia y control de la memoria. También se menciona que C++ no utiliza un recolector de basura debido a su énfasis en el rendimiento y la eficiencia.

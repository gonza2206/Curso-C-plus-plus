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

```C++
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

#### _Output_

Address of x is 0xd8ae3ffdec  
Address of y is: 0xd8ae3ffdc0  
Address of z is: 0xd8ae3ffde8  
After calling function(), x = 2  
After calling function(), z = 2

## <span style="color: yellow;">Pasar un valor por direccion de memoria (address)</span>

Ahora, habrá una variable local y, que es un puntero a un entero, y la dirección será la dirección de x.

Si hacemos una operación de desreferenciación (\*y), esto nos dará los datos en esa dirección de memoria, que también son utilizados por la variable x.

Entonces, si cambiamos esos datos a uno, entonces x tendrá el valor uno.

```C++
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

#### _Output_

Address of x is 0x22fbbffb6c  
Address of y is: 0x22fbbffb40  
Address of z is: 0x22fbbffb68  
After calling function(), x = 1  
After calling function(), z = 1

## <span style="color: yellow;"> Pasar un valor por referencia</span>

La otra forma de cambiar la dirección de memoria de x es mediante el uso de paso por referencia.

Esto significa que la función ahora toma una referencia en lugar de un puntero.

Por lo tanto, la variable local y aquí será una referencia a x.

Esto significa que y puede acceder a los datos de x.

Por lo general, esto se implementa como un puntero que se desreferencia automáticamente por el compilador.

En efecto, es una forma más simple de escribir lo que teníamos antes.

```C++
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

#### _Output_

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

```C++
class MyClass {...};

void function(const MyClass& mc){
   ...
}
MyClass my_class;
function(my_class);
```

```C++
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

## <span style="color: yellow;">Diferencia entre semanticas. Semantica de valor y semantica de referencia. </span>

En la semántica de valor, que es la que utiliza C++ por defecto, al copiar un objeto se crea una copia independiente del objeto original. En cambio, en la semántica de referencia, que utilizan otros lenguajes como Java, C# y Python, al inicializar un objeto a partir de otro o pasar un objeto a una función, se obtiene una referencia al objeto original, es decir, no se crea una nueva copia sino que se comparte la misma memoria utilizada por el objeto original.

Para administrar la memoria en la semántica de referencia, muchos lenguajes utilizan un _recolector de basura_ ("garbage collector"), un programa interno que mantiene un registro de todos los objetos en el programa y sus relaciones, y que decide qué objetos ya no están en uso y pueden ser eliminados de la memoria. En cambio, en C++, se administra la memoria manualmente, lo que significa que el programador debe asignar y liberar la memoria de los objetos según sea necesario.

La semántica de valor de C++ tiene la ventaja de no requerir el uso de un recolector de basura, lo que significa que no hay sobrecarga adicional en el uso de la memoria o en la interrupción del programa. Además, los objetos locales se destruyen de manera determinista, lo que significa que el programador sabe en qué orden se destruirán y cuándo se liberará su memoria. Sin embargo, la creación de copias de objetos puede tener un costo elevado en términos de rendimiento.
C++ no utiliza un recolector de basura debido a su énfasis en el rendimiento y la eficiencia.

## <span style="color: yellow;">Universal Initialization </span>

Una de las nuevas características es la sintaxis de inicialización universal que permite inicializar diferentes tipos de la misma manera mediante llaves. Además, se puede inicializar contenedores con múltiples valores en una sola sentencia en lugar de tener que declarar el vector como vacío y luego agregar elementos. También se soluciona un error de larga data en C que permitía ignorar los datos adicionales que son demasiado grandes para un tipo de datos numérico, lo que permite trunca los datos. Además, se soluciona otro problema con la sintaxis de declaración de objeto. La característica más importante es la corrección de errores que C++ 11 introduce.

```C++
#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
   int x{7}; // Equivalente a int x = 7
   std::string str{"Hola Mundo!"}; // Inicialización de string con llaves
   std::vector<int> v{4, 2, 3, 5, 1}; // Inicialización de vector con múltiples valores

   double d{7.7};
   int y{d}; // En versiones anteriores esto truncaría el valor a 7
   std::cout << y << std::endl; // Imprime "7"

    std::vector<int> v1(4, 0); // Vector con cuatro elementos con valor 0 [0,0,0,0]
    std::vector<int> v2(4, 2); // Vector con cuatro elementos con valor 2
    std::vector<int> v3{1, {4, 2}}; // Vector con un elemento con valor 1 y dos elementos con valores 4 y 2

    Test t1; // En versiones anteriores, esto podría ser interpretado como la declaración de una función que devuelve un objeto Test
    Test t2{}; // Uso de llaves para indicar inicialización de objeto
}
```

### ¿Cuál es la diferencia entre nullptr y NULL en C++?

En C++ anteriormente se usaba el valor NULL para indicar que un puntero no apuntaba a nada, sin embargo, se descubrió que esto podía llevar a errores de ambigüedad en ciertos contextos.

En C++11 se introdujo el valor nullptr, que es un valor nulo de puntero que se puede convertir a cualquier otro tipo de puntero, pero no a otros tipos de datos, lo que evita ambigüedades. En otras palabras, nullptr es el valor nulo de puntero recomendado en C++ moderno y es preferible usarlo en lugar de NULL.

Por ejemplo, en el siguiente código:

```C++
#include <iostream>
#include <stdlib.h>

void foo(char* str) {
    // do something
}

int main() {
    foo(NULL);
    return 0;
}
```

Es posible que el compilador no sepa si el valor NULL debe ser convertido a int o a char*, lo que puede provocar errores. Si usamos nullptr en su lugar, el compilador sabrá que queremos un puntero nulo de tipo char*, lo que evitará ambigüedades y posibles errores:

```C++
void foo(char* str) {
  // do something
}

int main() {
  foo(nullptr);
  return 0;
}
```

## Creacion de alias

En versiones antiguas de C++, se utilizaba la palabra clave "typedef" para crear un alias. Por ejemplo:

```C++
typedef vector<int> IntVec;
```

Ahora, se puede utilizar una sintaxis más simple utilizando la palabra clave "using". Por ejemplo:

```C++
using IntVec = vector<int>;
```

De esta forma, se puede crear un alias para "vector<int>" llamado "IntVec". Esto hace que sea más fácil de leer y entender en el código. Por ejemplo:

```C++
IntVec v1; // es lo mismo que vector<int> v1;
IntVec v2; // es lo mismo que vector<int> v2;
```

En resumen, crear un alias para un tipo de dato puede mejorar la legibilidad y mantenibilidad del código. En lugar de tener que escribir un tipo de dato largo y complejo repetidamente en el código, se puede utilizar un alias más corto y fácil de entender.

## <span style="color: yellow;">Special Member Functions </span>

Las funciones especiales de C++, que están relacionadas con la gestión de objetos y su ciclo de vida. Estas funciones se llaman automáticamente por el compilador y no se suelen llamar explícitamente. Las cuatro funciones especiales son:

1.  constructor
2.  constructor de copia
3.  operador de asignación
4.  destructor

`Constructor`: es un método especial que se llama automáticamente cuando se crea una instancia (objeto) de una clase. Su función principal es inicializar los atributos del objeto y reservar cualquier recurso necesario para su uso. El constructor tiene el mismo nombre que la clase y no tiene tipo de retorno.

`Constructor de copia`: es un método que se utiliza para crear una nueva instancia de una clase a partir de una instancia existente. Su función es copiar el valor de los atributos de la instancia existente en la nueva instancia. El constructor de copia se llama automáticamente cuando se crea una copia de un objeto, ya sea al pasar el objeto como argumento a una función o al asignarlo a otra variable.

`Operador de asignación`: es un método que se utiliza para asignar el valor de una instancia de una clase a otra instancia de la misma clase. Su función es copiar el valor de los atributos de la instancia asignada en la instancia que recibe la asignación. El operador de asignación se utiliza con el símbolo "=".

`Destructor`: es un método que se llama automáticamente cuando una instancia de una clase se destruye (elimina). Su función principal es liberar cualquier recurso reservado para el objeto, como la memoria asignada dinámicamente. El destructor tiene el mismo nombre que la clase, pero precedido por el símbolo ~ y no tiene tipo de retorno.

Estos cuatro conceptos son fundamentales en la programación orientada a objetos y se utilizan para garantizar que los objetos se inicialicen correctamente, se manejen adecuadamente y se eliminen sin dejar recursos sin liberar en la memoria del sistema.

Ejemplo de aplicacion:

```C++
#include <iostream>
using namespace std;

class Persona {
 private:
   string nombre;
   int edad;

 public:
   // Constructor
   Persona(string nombre, int edad) {
       this->nombre = nombre;
       this->edad = edad;
   }

   // Constructor de copia
   //Se pasa un objeto por referencia en el constructor copia para evitar una copia innecesaria y costosa de ese objeto. Cuando se copia un objeto por valor, se crea una nueva instancia del objeto y se copian todos sus miembros en la nueva instancia. Si el objeto es grande, este proceso puede ser costoso en términos de tiempo y memoria.
   Persona(const Persona &p) {
       nombre = p.nombre;
       edad = p.edad;
   }

   // Operador de asignación
   //La forma más eficiente de pasar objetos es por referencia constante y la operación devuelve una referencia al objeto asignado. Esto se hace para permitir la encadenación de las operaciones de asignación en C y C++, lo que significa que puedes asignar varios objetos en una sola instrucción.
   Persona& operator=(const Persona &p) {
       nombre = p.nombre;
       edad = p.edad;
       return *this;
   }

   // Destructor
   ~Persona() {
       cout << "Destruyendo objeto Persona" << endl;
   }

   // Métodos para obtener y establecer los valores de los atributos
   string getNombre() { return nombre; }
   int getEdad() { return edad; }
   void setNombre(string nombre) { this->nombre = nombre; }
   void setEdad(int edad) { this->edad = edad; }
};

int main() {
   // Crear una instancia de la clase Persona usando el constructor
   Persona p1("Juan", 30);

   // Crear una instancia de la clase Persona usando el constructor de copia
   Persona p2 = p1;

   // Crear una instancia de la clase Persona usando el operador de asignación
   Persona p3("Maria", 25);
   p3 = p1;

   // Imprimir los valores de las instancias de Persona
   cout << "p1: " << p1.getNombre() << ", " << p1.getEdad() << endl;
   cout << "p2: " << p2.getNombre() << ", " << p2.getEdad() << endl;
   cout << "p3: " << p3.getNombre() << ", " << p3.getEdad() << endl;

   return 0;
}
```

En este ejemplo, la clase Persona tiene un constructor que toma un nombre y una edad como parámetros y los asigna a los atributos nombre y edad, respectivamente. También hay un constructor de copia que crea una nueva instancia de Persona a partir de otra instancia existente, y un operador de asignación que asigna los valores de un objeto Persona a otro. Finalmente, hay un destructor que se llama cuando se destruye un objeto Persona.

En el main(), se crean tres instancias de la clase Persona utilizando diferentes métodos: el constructor, el constructor de copia y el operador de asignación. Luego, se imprimen los valores de las instancias para demostrar que se han creado correctamente.

## Explicacion ampliada sobre el operador de asignacion.

```C++
#include <iostream>
//creamos una clase Example con un miembro int x

class Example {
public:
    int x;
    Example(int x) : x(x) {}//Lista de inicializacion del constructor iguala el valor de x = lo que reciba cuando se contruya. Esto ahorra un pasom ya que si pusieramos dentro del constructor
    Example& operator=(const Example& other) {
        if (this != &other) {
            x = other.x;
        }
        return *this; // La operación de asignación devuelve una referencia no constante al objeto de destino lo que permite la encadenación de asignaciones. Si fuera const no podria asignar otro valor porque es constante, el compilador no te deja asignar valores a "objetos" constantes.
    }
};

int main() {
    Example a(1);
    Example b(2);
    Example c(3);

    a = b = c; //Esto es gracias a que devolvemos una asignacion no constante.


    std::cout << a.x << std::endl; // output: 3
    std::cout << b.x << std::endl; // output: 3
    std::cout << c.x << std::endl; // output: 3

    return 0;
}
```

En este ejemplo, creamos una clase Example con un miembro int x. La operación de asignación operator= se sobrecarga para asignar el valor de x en el objeto de destino al valor de x en el objeto fuente. La operación de asignación devuelve una referencia no constante al objeto de destino, lo que permite la encadenación de asignaciones. En el main, creamos tres objetos a, b y c de tipo Example, y luego asignamos c a b y luego b a a usando la operación de asignación. Como resultado, los valores de x en los tres objetos son 3, y se imprimen en la consola.

## <span style="color: yellow;">Pointers and memory </span>

Un puntero es una variable que representa una dirección en la memoria, y su valor es la dirección en sí.

Ejemplo de declaracion de punteros:

1. Declaración de un puntero a un entero:
   ```C++
   int* ptr;
   ```
2. Declaración de un puntero a un carácter:
   ```C++
   char* ptr;
   ```
3. Declaración de un puntero a un arreglo de enteros:
   ```C++
    int* ptr = new int[10];
   ```
4. Declaración de un puntero a una estructura:

   ```C++
   struct Persona {
    std::string nombre;
    int edad;
   };

   Persona\* ptr = new Persona();
   ```

5. Declaración de un puntero a una funcion:
   ```C++
   int (*ptr)(int, int);
   ```

## Memory leak (Fuga de memoria)

Una fuga de memoria sería cuando un programa reserva memoria dinámicamente para un objeto o una variable, pero no libera esa memoria cuando ya no se necesita. Por ejemplo, en C++, podemos crear una fuga de memoria si usamos el operador new para asignar memoria a un objeto y luego no usamos el operador delete para liberar esa memoria.

```C++
int main() {
int* p = new int(5); // asignamos memoria para un entero con valor 5
p = new int(10);     // asignamos más memoria para un entero con valor 10, pero no liberamos la memoria anterior
return 0;
}
```

La memoria asignada en el heap permanecerá asignada hasta que se libere explícitamente.

## Dangling pointer (puntero colgante)

Un dangling pointer es un puntero que apunta a una zona de memoria que ya no es válida o que ha sido liberada. Esto puede ocurrir cuando se utiliza un puntero después de haber liberado la memoria a la que apuntaba, o cuando se ha asignado memoria a un puntero pero no se ha inicializado.  
Cuando se accede a un dangling pointer, puede ocurrir un comportamiento impredecible y potencialmente peligroso para el sistema, como errores de segmentación o corrupción de memoria. Es importante evitar el uso de dangling pointers y liberar correctamente la memoria asignada cuando ya no se necesita.

Un ejemplo de dangling pointer podría ser el siguiente:

```C++
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr = new int {5}; // Asignar memoria dinámica
  *ptr = 42; // Asignar un valor al espacio de memoria apuntado por ptr
  delete ptr; // Liberar el espacio de memoria apuntado por ptr
  printf("%d", *ptr); // Intentar acceder al espacio de memoria liberado (dangling pointer)
  return 0;
}
```

La forma correcta de liberar memoria seria:

```C++
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr = new int {5}; // Asignar memoria dinámica
  *ptr = 42; // Asignar un valor al espacio de memoria apuntado por ptr
  delete ptr; // Liberar el espacio de memoria apuntado por ptr
  return 0;
}
```

Exiten dos tipos de `delete`: delete y delete[]. delete [] va a tomar el comienzo del bloque de memoria que fue asignado con _new_ y lo elimina.  
La principal diferencia entre ellos es que delete se utiliza para liberar la memoria asignada para un solo objeto dinámico, mientras que delete[] se utiliza para liberar la memoria asignada para un arreglo de objetos dinámicos.  
_Es importante usar el operador correcto para evitar errores de memoria en el programa. Si se usa delete para liberar la memoria asignada a un arreglo dinámico, o viceversa, el programa puede comportarse de manera impredecible o incluso fallar._

## <span style="color: yellow;">VECTOR LIBRARY </span>

La librería "vector" de C++ es un contenedor de datos dinámico que permite almacenar un conjunto de elementos de un mismo tipo. Los elementos se almacenan en una estructura de datos que crece y disminuye dinámicamente según se añaden o eliminan elementos, lo que la hace muy flexible en comparación con arrays estáticos.

Ejemplo 1: Crear un vector vacío y agregar elementos a él.

```C++
#include <iostream>
#include <vector>


int main() {
  std::vector<int> v; // Crear un vector vacío

  // Agregar elementos al vector
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // Imprimir los elementos del vector
  for (auto x : v) {
    std::cout << x << " ";
  }

  return 0;
}

```

Ejemplo 2: Crear un vector con tamaño y valores predeterminados.

```C++
#include <iostream>
#include <vector>

int main() {
  // Crear un vector con tamaño y valores predeterminados
  std::vector<int> v(5, 10); // 5 elementos con valor 10
  std::vector<int> v{5, 10};//  vector con valores [5,10]
  // Imprimir los elementos del vector
  for (auto x : v) {
    std::cout << x << " ";
  }

  return 0;
}
```

Output: 10 10 10 10 10

Ejemplo 3: Acceder y modificar elementos del vector.

```C++
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5}; // Crear un vector con valores

  // Acceder y modificar elementos del vector
  std::cout << "El primer elemento es " << v[0] << std::endl; // Acceder al primer elemento
  v[3] = 10; // Modificar el cuarto elemento

  // Imprimir los elementos del vector
  for (auto x : v) {
    std::cout << x << " ";
  }

  return 0;
}
```

Output: El primer elemento es 1  
1 2 3 10 5

## <span style='color: yellow;'>TWO DIMENTIONAL ARRAY</span>

Formas de definir un array:

### Iteracion

```C++
 string names[2][4] = {
		{"Fred", "Wilma", "Pebbles", "Dino"},
		{"Barney", "Betty", "Bamm-Bamm", "Hoppy"}
	 };

	 cout << "names[1][2] = " << names[1][2] << endl;

	 cout << "\nThe elements of names are:\n";
	 for (int row = 0; row < 2; ++row) {
		 for (int col = 0; col < 4; ++col) {
			 cout << names[row][col] << ", ";
		 }
		 cout << "\n";
	 }
```

### Flatened

Un array bidimensional puede ser "aplastado" a un array unidimensional. Esto con el objetivo de ganar eficiencia a expensas de hacer mas complejo el codigo.

```C++
 string names[] = {
		"Fred", "Wilma", "Pebbles", "Dino", "Barney", "Betty", "Bamm-Bamm", "Hoppy"
	};

	cout << "names[1][2] = " << names[1*4 + 2] << endl;

	cout << "\nThe elements of names are:\n";
	for (int row = 0; row < 2; ++row) {
		for (int col = 0; col < 4; ++col) {
			cout << names[row*4 + col] << ", ";
		}
		cout << "\n";
	}
```

Un array bidimensional es un array de arrays. Acceder a un elemento en un array interno requiere una desreferenciación de puntero.

Un array unidimensional es un array simple. Acceder a un elemento en un array "aplanado" requiere calcular el desplazamiento del elemento.

En los ordenadores modernos, el cálculo del desplazamiento es mucho más rápido que la desreferenciación de un puntero.

El calculo para moverse entre filas y columnas en un array bidimensional es:
Elemento en fila m * numeroColumnas + columna del elemento.  
names[fila*4 + columna].

## <span style='color: yellow;'>NUMERIC TYPES </span>

En C++, hay varios tipos de datos que se pueden utilizar para declarar variables. Aquí hay una lista de los tipos de datos más comunes:

### Tipos de datos básicos:

- int: para números enteros. **16bits**
- float: para números de punto flotante de precisión simple. **6 digitos de presicion**
- double: para números de punto flotante de precisión doble.**15 digitos de presicion**
- long double: **20 digitos de presicion**
- char: para caracteres individuales.**8bits**
- bool: para valores booleanos (verdadero o falso).
- long: al menos 32 bits. Debe ser por lo menos tan largo como long. **32bits**
- long long: al menos 64 bits. Debe ser por lo menos tan largo como long.**64bits**

### Tipos de datos derivados:

- Arrays: una colección de elementos del mismo tipo.
- Strings: una secuencia de caracteres.
- Punteros: una variable que almacena la dirección de memoria de otra variable.
- Referencias: un alias para una variable existente.

### Tipos de datos compuestos:

- Estructuras: una colección de variables de diferentes tipos.
- Uniones: una estructura que permite almacenar diferentes tipos de datos en el mismo espacio de memoria.
- Enumeraciones: una lista de valores con nombres simbólicos.

## Bases

Es posible representar distintos tipos de bases de la siguiente forma:

```C++
 #include <iostream>

using namespace std;

int main() {
	// Numeric literals are decimal by default
	int decimal = 42;            // 4*10 + 2*1 = 42
	cout << "Decimal: " << decimal << endl;

	//Hexadecimal numbers have 0x or 0X in front
	int hexadecimal = 0x2a;          // 2*16 + 10*1 = 42
	cout << "Hexadecimal: " << hexadecimal << endl;

	//Octal numbers have 0 in front
	int octal = 052;         // 5*8 + 2*1 = 42
	cout << "Octal: " << octal << endl;

	//Binary numbers have 0b or 0B in front (C++14 onwards)
	int binary = 0b101010;   // 1*32 + 1*8 + 1*2 = 42
	cout << "Binary: " << binary << endl;
}
```

### Caracteres para destacar el tipo de base

Decimal: _por defecto_  
Hexadecimal: **0x**  
Octal: **0**  
Binario: **1b**

_Se puede representar un numero grande de forma comoda como:_

```C++
 const int one_million = 1'000'000;
```

De esta forma es mas facil de leer y el compilador entiende que es un millon.

## <span style='color: yellow;'>STRING LITERALS </span>

En C++, un string literal es una secuencia de caracteres entre comillas dobles. Por ejemplo, "Hola mundo" es un string literal en C++ que representa la cadena de texto "Hola mundo".

En C++, los string literals tienen un tipo de dato constante, llamado "array de caracteres constante", que es un conjunto de caracteres consecutivos en memoria. Por lo tanto, los string literals en C++ se representan como un puntero a un array de caracteres constante.

Por ejemplo, el siguiente código en C++ muestra cómo se puede utilizar un string literal para inicializar una variable de tipo puntero a char:

```C++
  const char* saludo = "Hola mundo";
```

La desventaja ded estos caracteres constantes es que no pueden ser concatenados. Para ello se introducen nuevas formas de declarar strings:

```C++
 	// String literal with escaped characters
	string url = "<a href=\"file\">C:\\\"Program Files\"\\</a>\\n";
	cout << "URL is " << url << endl << endl;

	// Raw string literal with unescaped characters
	string raw_url = R"(<a href="file">C:\"Program Files"\</a>\n)";
	cout << "Raw URL is " << raw_url << endl << endl;

	// Raw string literal with delimiter x
	string delimited_url = R"x(<a href="file">C:\"Program Files (x86)"\</a>\n)x";
	cout << "Delimited URL is " << delimited_url << endl << endl;
```

Los casos de interes son el segundo y el tercero.
En el segundo caso se envuelve al string con:  
**R"(string)"**.  
De esta forma le dedcimos al compilador que no considere las comillas internas del string como final del string.  
En el tercer caso usamos un delimitador "x", esta forma es la mas segura ya que delimitamos el string entre las dos 'x'.  
**R"x(string)x"**

## <span style='color: yellow;'> CASTING </span>

Existen 4 tipos diferentes de casteos:

1. **_static_cast<>_**  
   Convierte un valor de un tipo de datos a otro de manera explícita en tiempo de compilación, siempre y cuando la conversión sea segura y definida. Por ejemplo, se puede utilizar para convertir un entero a un flotante, o para realizar conversiones de punteros entre tipos relacionados.
   ```C++
    int c = 'A';
   cout << c << endl;
   cout << static_cast<char>(c) << endl;
   ```
2. **_const_cast<>_**  
   Convierte la constancia de un objeto. Es decir, permite eliminar o agregar la calificación de constante a un objeto, lo cual puede ser útil en situaciones donde se necesita modificar un objeto que originalmente se declaró como constante. Sin embargo, es importante tener en cuenta que modificar un objeto que originalmente se declaró como constante puede resultar en un comportamiento indefinido.
   ```C++
    const char *msg = "Hello, world!";
   //print(msg);               // Error - invalid conversion
   print(const_cast<char *>(msg));
   ```
3. **_reinterpret_cast<>_**  
   Realiza una conversión entre dos tipos de datos que no están relacionados entre sí, como convertir un puntero a un entero o viceversa. Este tipo de casting puede ser peligroso, ya que puede conducir a comportamientos indefinidos si se utiliza de manera incorrecta.
4. **_dynamic_cast<>_**  
   Convierte un puntero o una referencia a un objeto a otro tipo de datos relacionado en tiempo de ejecución, verificando si la conversión es segura. Este tipo de casting se utiliza principalmente en situaciones donde se necesita convertir un puntero a una clase base a un puntero a una clase derivada, o para realizar conversiones entre punteros a clases relacionadas en una jerarquía de clases. Si la conversión no es posible, el resultado de dynamic_cast será un puntero o una referencia nulo.

## <span style='color: yellow;'>ITERATORS </span>

Un iterador es un objeto en C++ que permite recorrer y manipular los elementos de un contenedor, como un arreglo, un vector, una lista, un conjunto o un mapa. Un iterador se utiliza para acceder a los elementos de un contenedor sin exponer su representación interna, lo que proporciona una capa de abstracción y seguridad.

Los iteradores se definen como clases o estructuras que tienen una serie de operaciones definidas, como avanzar al siguiente elemento, retroceder al elemento anterior, acceder al valor del elemento actual y comparar dos iteradores para determinar si son iguales o no. Los iteradores pueden ser usados en ciclos para recorrer todos los elementos de un contenedor.

```C++
  #include <iostream>
#include <vector>

int main() {
    // Se crea un vector de enteros
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Se define un iterador que apunta al primer elemento del vector
    std::vector<int>::iterator it = vec.begin();

    // Se recorre el vector con el iterador e imprime cada elemento
    while (it != vec.end()) {
        std::cout << *it << " ";
        it++;  // Se avanza al siguiente elemento
    }

    return 0;
}
```

En este ejemplo, se crea un vector de enteros llamado vec con cinco elementos. Luego, se define un iterador llamado it que apunta al primer elemento del vector utilizando la función begin(). Se utiliza un ciclo while para recorrer el vector, y en cada iteración se imprime el valor del elemento actual **apuntado por el iterador** mediante la indirección \*it. Finalmente, se avanza el iterador al siguiente elemento mediante el operador ++.

Otra forma mas sencilla de hacer lo mismo seria:

```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str("Hello");

	for (string::iterator it = str.begin(); it != str.end(); ++it)
        cout << *it << ", ";
}
```

## Agregar y quitar elementos de un vector con Iteradores

```C++ #include <iostream>
#include <vector>

int main() {
    // Se crea un vector de enteros
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Se define un iterador que apunta al tercer elemento del vector
    std::vector<int>::iterator it = vec.begin() + 2;

    // Se inserta un nuevo elemento antes del tercer elemento del vector
    vec.insert(it, 10);

    // Se imprime el vector después de insertar el nuevo elemento
    std::cout << "Vector después de insertar un elemento: ";
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Se elimina el cuarto elemento del vector
    it = vec.begin() + 3;
    vec.erase(it);

    // Se imprime el vector después de eliminar el cuarto elemento
    std::cout << "Vector después de eliminar un elemento: ";
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

En este ejemplo, se crea un vector de enteros llamado vec con cinco elementos. Luego, se define un iterador llamado it que apunta al tercer elemento del vector utilizando la función begin() y el operador +. Se utiliza la función insert() del vector para insertar un nuevo elemento con valor 10 antes del tercer elemento del vector apuntado por it.

Después, se utiliza el operador + y la función erase() del vector para eliminar el cuarto elemento del vector apuntado por it.

Finalmente, se utilizan dos ciclos for para recorrer el vector y se imprimen sus elementos antes y después de la inserción y eliminación de elementos.

Este es un ejemplo básico de cómo agregar y quitar elementos en un vector utilizando iteradores en C++. Con los iteradores, es posible realizar una amplia variedad de operaciones en los contenedores, como agregar o eliminar elementos en una posición específica, copiar o mover elementos entre contenedores, y mucho más.

## <span style='color: yellow;'>Auto </span>

Cuando definimos una variable podemos escribir "auto" en lugar de un tipo, el compilador deducira el tipo de dato para incializar la variable.

### ¿Por qué es importante el "auto"?

"auto" nos permite escribir definiciones más simples de variables con tipos complejos.

"auto" nos permite definir variables cuyo tipo no puede ser conocido por nosotros o es difícil de descubrir.

```C++
 #include <iostream>
#include <string>

using namespace std;

int main() {
	auto i{42};                       // Type of i is deduced as int
	auto str1 = "Hello";              // Type of str1 is deduced as const char*
	auto str2 = "Hello"s;             // Type of str2 is deduced as std::string

	cout << "i * 2 = " << i * 2 << endl;
	auto it = str2.begin();
	cout << "First element of str2: " << *it << endl;
}
```

Usando auto para escribir versiones simples de la siguiente definicion:

```C++
vector<int>::iterator it = vec.begin();
```

```C++
 auto it = vec.begin();
```

## Usando auto y const

```C++
 #include <iostream>

using namespace std;

int main() {
	const int& x{6};
	auto y = x;
	++y;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}
```

Si se utiliza auto y asignamos una variable constante "auto" descartara la parte constante ya que estamos pasando a x como valor. Entonces podemos decir que "auto" descarta las referencias y const.

Otro Ejemplo del uso de "auto" :

```C++
 #include <iostream>

using namespace std;

 int func() {                 // Function returning reference to const int
	return 5;
}

int main() {
	auto x = func();                // x has type int
	cout << x << endl;
}
```

_x_ va a ser un valor de tipo entero.

## <span style='color: yellow;'>Iterators and Loops </span>

Ademas del iterador comun que solo avanza en una direccion podemos definir otros 3 iteradores:

1. Const iterator : Si queremos evitar que un loop modifique un string podemos usar _const_iterator_
2. Reverse iterator: Utilizado para iterar hacia atras desde el ultimo elemento, se utiliza _reverse_iterator_
3. Const reverse iterator.

```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str{"Hello"};

	cout << "Iterator: ";
	for (auto it = str.begin(); it != str.end(); ++it)
        cout << *it << ", ";

	cout << endl << "Const iterator: ";
	for (auto it = str.cbegin(); it != str.cend(); ++it)
        cout << *it << ", ";

	cout << endl << "Reverse iterator: ";
	for (auto it = str.rbegin(); it != str.rend(); ++it)
        cout << *it << ", ";

	cout << endl << "Const reverse iterator: ";
	for (auto it = str.crbegin(); it != str.crend(); ++it)
        cout << *it << ", ";
}
```

En c++ tambien tenemos non-member functions begin() y end(). Esto quiere decir que no solo se pueden usar estos metodos con iteradores, ahora tambien se pueden usar con arrays. Esto tambien permite usar _auto_ para iterar entre contenedores de una manera mas sencilla.

```C++
 #include <iostream>

using namespace std;

int main() {
	int arr[] = {1, 2, 3, 4, 5};

	cout << "Iterator: ";
	for (auto it = begin(arr); it != end(arr); ++it)
		cout << *it << ", ";

	cout << endl << "Const iterator: ";
	for (auto it = cbegin(arr); it != cend(arr); ++it)
		cout << *it << ", ";

	cout << endl << "Reverse iterator: ";
	for (auto it = rbegin(arr); it != rend(arr); ++it)
        cout << *it << ", ";

	cout << endl << "Const reverse iterator: ";
	for (auto it = crbegin(arr); it != crend(arr); ++it)
        cout << *it << ", ";
}
```

## Range for loops

Tenemos una forma especial de anotar los bucles for como estos:

```C++
  for (auto it = begin(arr); it != end(arr); ++it)
  {
      int el = *it; //copia del elemento. Ya que estamos desreferenciando un puntero y asignandolo a una variable. Es lo mismo que decir x=valor.
      cout << el;
  }
```

una forma abreviada de escribir esto seria:

```C++
 for (auto el : vec)
 {}
```

esta forma es equivalente a la anterior pero mas consisa.  
Esto lee **_por cada elemento en el vector._**  
_el_ es un elemento dentro del vector y cualquier cambio que hagamos a _el_ no va a afectar el contenedor de elementos.

### ¿Como podemos modificar los elementos dentro del Loop?

Esto lo podemos lograr agregando la referencia antes de "auto". Si recordamos al usar auto siempre tenes el tipo de dato actual ignorando cualquier const o referencia. Si añadimos una referencia a "auto" entonces vamos a tener una referencia al tipo de elemento. Entonces si tenemos un vector de int y pasamos

```C++
 for (auto& el : vec)
 {}
```

vamos a tener que el es una referencia al valor del vector, de esta forma podremos modificar su valor.

Ejemplo:

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec = {1, 2, 3, 4};

	cout << "Vector elements: " << endl;
	for (auto el : vec)
		cout << el << ", ";                                          // Prints out each element of vec

	cout << endl << "Adding 2 to each element" << endl;
	for (auto& el : vec)
		el += 2;                                                    // Add 2 to each element of vec

	cout << endl << "Modified vector elements: " << endl;
	for (auto el : vec)
		cout << el << ", ";                                         // Prints out each element of vec
}
```

### ¿Cuando no es conveniente usar este tipo de iteradores?

- si el loop itera sobre una parte del contenedor.
- si el loop se saltea algunos elementos.
- si el loop añade o remueve elementos.

Si no estamos trabajando en esas condiciones es recomendable usar este tipo de for siempre que se pueda.

## <span style='color: yellow;'>Iterators Arithmetic </span>

Podemos realizar calculos con los iteradores, como:

- Sumar un iterador: esto provoca que se mueva un lugar hacia adelante en el contenedor.

```C++
 auto second = begin(vec) + 1;
```

- restar un iterador: esto implica moverse un lugar hacia atras en el contenedor.

```C++
 auto last = end(vec) - 1; //esto nos dara el ultimo valor del contenedor. Por lo que podemos desreferenciarlo. recordar que end() apunta a la casilla de memoria siguiente del ultimo elemento.
```

end() - begin() nos da el numero total de elementos.

Como no esta bueno poner numeros en un codigo hay funciones que hacen lo mismo que los casos anteriores:

```C++
 auto second = next(begin(vec)); //muevo un lugar hacia adelante.
 auto last = prev(end(vec)); //mueco un lugar hacia atras.
 distance(begin(vec),end(vec)); //me devuelve la cantidad de pasos hay desde el primer lugar hasta el ultimo.
 advance(iterador, numero de casillas a avanzar);//Permite mover un iterador una cantidad de pasos especifica segun especifique en el segundo parametro.
  auto mid = begin(vector1); // defino mid como un iterador,
  advance(mid, 2);//avanzo dos lugares
  std::cout << *mid << std::endl; //muestro el valor.
```

Un iterador es un puntero, por lo que solo puede sumarse o restarse. No es un numero por el cual puede ser dividido. Por lo que intentar hacer esto:

```C++
 auto mid = begin(str)/2 + end(str)/2;
```

No tiene sentido en C++.

## <span style='color: yellow;'>Templates </span>

En C++, las plantillas (también conocidas como templates en inglés) son una herramienta de programación que permite definir funciones y clases genéricas, es decir, funciones y clases que pueden trabajar con diferentes tipos de datos.

Las plantillas en C++ se definen utilizando la palabra clave template, seguida de la definición de la función o clase. Por ejemplo, aquí hay una función plantilla que toma un argumento de tipo genérico T y lo imprime en la consola:

```C++
template <typename T> //Se usa como regla general T mayuscula para indicar el tipo de dato generico. Tambien en lugar de typename se puede usar class. (no es que sea una clase sino que asi se declaraba antes).
void imprimir(const T& valor) {
    std::cout << valor << std::endl;
}
```

En este ejemplo, la plantilla imprimir toma un argumento valor de tipo genérico T, y lo imprime en la consola utilizando std::cout. El tipo T se especifica utilizando la palabra clave typename, seguida del nombre del tipo genérico.

Luego, para utilizar la función imprimir con un tipo de datos específico, simplemente se llama a la función con el tipo de datos deseado, como en este ejemplo:

```C++
int entero = 42;
double flotante = 3.14;
std::string cadena = "hola mundo";

imprimir(entero);    // Imprime "42"
imprimir(flotante);  // Imprime "3.14"
imprimir(cadena);    // Imprime "hola mundo"
```

otro ejemplo de templates:

```C++
 #include <iostream>

using namespace std;

// Function template for finding maximum of two values
template <class T>                              // T is the parameter type
T Max(const T& t1, const T& t2) {               // The arguments and return value have this type
    if (t1 > t2)
        return t1;
    return t2;
}

int main() {
	cout << Max<double>(7.0, 2.6) << endl;  // Expands template to:

	/*
	double Max(const double& t1, const double& t2) {               // The arguments and return value have this type
    if (t1 > t2)
        return t1;
    return t2;
	}
	*/
}
```

Algo importante que anotar es que el compilador debe conocer el cuerpo del template de la funcion antes de llamarla. Por lo que es una practica habitual poner la definicion de la funcion en el encabezado o en un archivo separado e incluirlo despues con el archivo de encabezado.

### Class templates

```C++
template <class T>
class Test {
T data; //tiene un dato de cualquier tipo
Test(const T& data) : data(data) {} // inicializamos el constructor y asignamos un valor a la variable data de tipo T.
};

Test<string> test{"Hello"}; // Creamos una instancia de la clase Test llamada test, y iniciamos el constructor con una variable de tipo string.
```

El compilador internamente generara la clase asi:

```C++
class Test_xcajkjha { // Instantiated with unique name
string data;
Test(const string& data) : data(in_data) {}
};
```

## <span style='color: yellow;'>Namespace </span>

Un namespace en C++ es un mecanismo de encapsulamiento que se utiliza para evitar conflictos de nombres entre diferentes componentes de un programa. Un namespace es como un contenedor que agrupa diferentes elementos (variables, funciones, clases, etc.) bajo un mismo nombre, para que puedan ser referidos de forma única y evitar colisiones con otros elementos que tienen el mismo nombre.

¿Como definimos un namespace?

```C++
 namespace abc {
   class Test;
 }
 abc::Test alphaTest;
```

Por ejemplo, si tienes una función max que devuelve el máximo entre dos números enteros, y también tienes una clase Persona con un miembro llamado max, puede haber un conflicto entre ambos ya que tienen el mismo nombre. En este caso, puedes definir un namespace para cada uno para evitar cualquier colisión de nombres:

```C++
  // namespace para la función max
namespace Math {
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
}

// namespace para la clase Persona
namespace Datos {
    class Persona {
    public:
        int max;
        // ...
    };
}
```

Para utilizar una función o una clase que está definida en un namespace, debes indicar el nombre del namespace seguido de un operador de ámbito (::) y luego el nombre del elemento que deseas utilizar. Por ejemplo:

```C++
int resultado = Math::max(3, 5);
Datos::Persona persona;
persona.max = 10;
```

En este ejemplo, se utiliza la función max del namespace Math para calcular el máximo entre 3 y 5, y se accede al miembro max de la clase Persona del namespace Datos.

### Global namespace

El global namespace es usado para todos los simbolos que no han sido declarados en un spacename especifico.  
La forma de declarar es simplemente declarando un simbolo fuera de cualquier spacename.  
La forma de ingresar a este namespace global es a traves del operador ::

```C++
 ::Test globalTestObject
```

### Name hiding

Cuando se declara un nombre en un namespace que es el mismo que un nombre fuera del namespace, el nombre externo es "ocultado" por el nombre interno.
Ejemplo de esto:

```C++
#include <iostream>

using namespace std;

int x{23};                                  // x defined in the global namespace

namespace abc {
	int x{47};                              // x defined in the namespace abc - hides global x
	void func() {
		cout << "x = " << x << endl;        // Will use abc's x -> 47
		cout << "::x = " << ::x << endl;    // Will use global x -> 23
	}
}

int main() {
	abc::func();
}
```

## using declarations

En C++, using se utiliza para crear un alias o abreviatura para un namespace o una parte de él, lo que facilita su uso en el código. Para utilizar using con un namespace, se puede hacer lo siguiente:

```C++
  #include <iostream>

namespace MiNamespace {
    int x = 42;
}

int main() {
    using namespace MiNamespace;  // utilizando using con el namespace MiNamespace
    std::cout << "El valor de x es: " << x << std::endl;
    return 0;
}
```

En este ejemplo, se utiliza using namespace MiNamespace para indicar que se quiere utilizar todo el contenido del namespace MiNamespace en el cuerpo de la función main. Luego se imprime el valor de x, que es una variable definida dentro del namespace.

Es importante tener en cuenta que el uso excesivo de using puede llevar a conflictos de nombres y hacer el código menos legible. Por lo tanto, es recomendable utilizar using solo cuando sea necesario y limitarlo a partes específicas del código.

## <span style='color: yellow;'>Function pointer</span>

Pasar funciones con punteros es una técnica utilizada en C++ para poder pasar funciones como argumentos a otras funciones.

En C++, una función es en realidad una dirección de memoria que apunta a un bloque de código en el programa. Por lo tanto, se pueden usar punteros para almacenar estas direcciones de memoria y luego pasarlas como argumentos a otras funciones.

La forma de enviar una funcion por puntero es la siguiente:

```C++
 (*func_ptr)(x,y)
```

Aquí hay un ejemplo sencillo que muestra cómo pasar una función con punteros:

```C++
#include <iostream>

void suma(int a, int b)
{
    std::cout << "La suma de " << a << " y " << b << " es " << a + b << std::endl;
}

void resta(int a, int b)
{
    std::cout << "La resta de " << a << " y " << b << " es " << a - b << std::endl;
}

void operacion(int a, int b, void (*func)(int, int)) // recibe dos numeros y un puntero a una funcion que recibe dos numeros y devuelve void
{
    func(a, b); // llamada a la funcion recibida como puntero
}

int main()
{
    int num1 = 10, num2 = 5;

    operacion(num1, num2, &suma); // se le pasa el puntero a la funcion suma
    operacion(num1, num2, &resta); // se le pasa el puntero a la funcion resta

    return 0;
}
```

Otro ejemplo pasando vectores:

```C++
#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Incluye la librería necesaria para rand() y srand()
#include <vector>

void funcion (const std::vector<int>& vector, void(*func_ptr)(const std::vector<int>&)) //la funcion envia como parametro el vector a la funcion pasada como parametro
{
    func_ptr(vector);
}

void mostrar(const std::vector<int>& vector) //la funcion mostrar que fue pasada como parametro "CALLBACK" muestra el vector.
{
    for (auto &element : vector)
    {
        std::cout << element << std::endl;
    }

}

int main()
{
   std::vector<int> prueba {1,2,3,4,5};
   funcion(prueba,&mostrar); //definimos una funcion y le pasamos como argumento un vector de enteros y un puntero a una funcion mostrar
}
```

Cuando pasamos una funcion como arguemento decimos que es un Callback.

Como regla general. Si quiero pasar por referencia un valor a una funcion. La funcion en la declaracion tiene que esperar un puntero o una posicion de memoria.

```C++
  void testfunction (int *x )
{
    std::cout << *x << std::endl; //desreferencio el puntero para ver el contenido.
}
 int main()
 {
   int value = 3;
   testfunction(&value);
 }
```

Caso contrario, si paso un puntero a una funcion como parametro tengo que esperar una posicion de memoria en la declaracion.

```C++
void testfunction (int &x )
{
    std::cout << x << std::endl;
}
 int main()
 {
   int value = 3;
   int *pointer = &value;
   testfunction(*pointer);
   testfunction(value);
 }
```

# String interface

## <span style='color: yellow;'> Basic String Operations </span>

en C++ existen varios métodos que se utilizan frecuentemente para manipular cadenas de caracteres o strings. Algunos de los métodos más utilizados son:

- length() o size(): devuelve la longitud de la cadena.

- substr(): devuelve una subcadena de la cadena original.

- append(): agrega una cadena a otra.

- find(): busca una subcadena dentro de la cadena.

- replace(): reemplaza una subcadena por otra.

- compare(): compara dos cadenas.

- c_str(): devuelve un puntero a una cadena de caracteres terminada en nulo equivalente a la cadena de la clase string.

- empty(): devuelve true si la cadena está vacía, false en caso contrario.

Por ejemplo, supongamos que tenemos una cadena llamada myString:

```C++
std::string myString = "Hola, mundo!";
int length = myString.length(); // Devuelve 13
std::string subString = myString.substr(0, 4); // Devuelve "Hola"
myString.append(" Adiós!"); // Ahora myString es "Hola, mundo! Adiós!"
int index = myString.find("mundo"); // Devuelve 6
myString.replace(0, 5, "Chau"); // Ahora myString es "Chau, mundo! Adiós!"
int compareResult = myString.compare("Chau, mundo! Adiós!"); // Devuelve 0 (iguales)
const char* cString = myString.c_str(); // Devuelve un puntero a una cadena de caracteres equivalente a "Chau, mundo! Adiós!"
bool empty = myString.empty(); // Devuelve false
```

## <span style='color: yellow;'>Converting between Strings and numbers </span>

Una de las maneras que tiene C++ de convertir strings a enteros es con la funcion miembro std::stoi

```C++
 #include <iostream>
#include <string>

using namespace std;

int main() {
	cout << stoi("42"s) << endl;              // Displays 42

	string str{ "  314 159" };             // Leading whitespace is ignored
	size_t n_processed; //typedef the unsigned long long

	auto i = stoi(str, &n_processed);

	if (n_processed < str.size()) {
		cout << "Non-numeric character at index " << n_processed << endl;
	}

	cout << "Result of conversion: " << i << endl;  // Displays 314

	//stoi("abcdef"s);                              // Cannot be converted - throws exception

	auto x = stoi("2a", nullptr, 16);   //stoi para convertir a otras bases
	cout << "Result of conversion: " << x << endl;  // Displays 42
}
```

### ¿Qué sucede si hay caracteres en la cadena que no son dígitos?

• Los caracteres de espacio en blanco al principio son ignorados  
• De lo contrario, los caracteres que no son dígitos hacen que la conversión se detenga.

### ¿Cómo podemos detectar errores de conversión con std::stoi?

• std::stoi tiene un segundo argumento opcional que se pasa por dirección  
• Cuando la llamada devuelve, esto contendrá el número de caracteres procesados  
• Si se convirtió toda la cadena exitosamente, esto contendrá el número de caracteres en la cadena  
• Si solo se convirtió parte de la cadena, esto contendrá el índice del primer carácter no numérico  
• Si la conversión falla completamente, stoi() arroja una excepción.

Para convertir un string a flotante se utiliza el metodo std::stod()

```C++
 #include <iostream>
#include <string>

using namespace std;

int main() {
	string pi {"3.14159"};

	cout << "pi: " << pi << endl << endl;

	size_t n_processed;

	cout << "stoi:\n";
	cout << stoi(pi, &n_processed) << endl;                  // Displays 3
	cout << n_processed << " characters processed\n\n";
	cout << "stod:\n";
	cout << stod(pi, &n_processed) << endl;                  // Displays 3.14159
	cout << n_processed << " characters processed\n\n";
}
```

## Convertir numeros a strings utilizando to_string()

```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
	string hello { "Hello, " };
	string pi { to_string(3.14159) };
	hello += pi;
	cout << hello << endl;
}

```

## <span style='color: yellow;'> Some useful operations with strings </span>

## data() member function

El método data() de la clase std::string se utiliza para obtener un puntero a la cadena de caracteres interna que almacena la instancia de std::string.  
Es importante tener en cuenta que el puntero devuelto por data() no tiene un carácter nulo al final de la cadena, lo que significa que no se puede asumir que la cadena tiene un terminador nulo.  
El uso común de data() es cuando se necesita pasar la cadena de caracteres a una función que acepta una cadena de caracteres como argumento, como una función de sistema operativo o una llamada a una biblioteca externa. Por ejemplo, supongamos que tenemos una instancia de std::string llamada myString y queremos llamar a una función externa que acepta una cadena de caracteres como argumento:

```C++
void externalFunction(const char* myString);

externalFunction(myString.data()); // Pasamos la cadena de caracteres de myString a la función externa
```

En este ejemplo, se utiliza data() para obtener el puntero a la cadena de caracteres interna de myString, que se pasa a la función externa externalFunction() como argumento.

Otro ejemplo.

```C++
#include <iostream>
#include <vector>

using namespace std;

void print(int *arr, size_t size) {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ", ";
}

int main() {
	std::vector<int> numbers {1, 2, 3, 4, 5};

	print(numbers.data(), numbers.size()); //Imprime la posicion de memoria donde inicia el vector numbers.
}
```

## Swapping

En C++, el método swap() de la clase std::string se utiliza para intercambiar el contenido de dos instancias de std::string.

El método swap() intercambia eficientemente el contenido de dos instancias de std::string sin realizar ninguna copia adicional. Esto significa que, en lugar de crear una copia temporal de la cadena, el método swap() intercambia los punteros internos de la cadena de caracteres de ambas instancias de std::string, lo que resulta en una operación muy rápida.

El uso común de swap() es cuando se necesita intercambiar el contenido de dos instancias de std::string, por ejemplo, para implementar la asignación por movimiento (move assignment) de std::string. Supongamos que tenemos dos instancias de std::string llamadas string1 y string2 y queremos intercambiar su contenido:

```C++
std::string string1 = "Hello";
std::string string2 = "World";

string1.swap(string2); // Intercambiamos el contenido de string1 y string2

std::cout << string1 << " " << string2 << std::endl; // Imprime "World Hello"
```

En este ejemplo, se utiliza swap() para intercambiar el contenido de string1 y string2, lo que resulta en la cadena "Hello" en string2 y la cadena "World" en string1. La salida del programa es "World Hello".

```C++
 for(auto& c : str)
 {
  c = toupper(c);
 }
```

## <span style='color: yellow;'>Character Functions </span>

Estas son funciones de biblioteca de C++ que se utilizan para verificar si un carácter determinado pertenece a una determinada categoría de caracteres. Aquí hay una breve descripción de cada una de ellas:

**isdigit**: esta función devuelve verdadero si el carácter proporcionado es un dígito (0-9), y falso en caso contrario.

**islower**: devuelve verdadero si el carácter proporcionado es una letra minúscula (a-z), y falso en caso contrario.

**_isupper_**: devuelve verdadero si el carácter proporcionado es una letra mayúscula (A-Z), y falso en caso contrario.

**_isspace_**: devuelve verdadero si el carácter proporcionado es un espacio en blanco (espacio, tabulación, salto de línea, retorno de carro, etc.), y falso en caso contrario.

**_ispunct_**: devuelve verdadero si el carácter proporcionado es un signo de puntuación (coma, punto, punto y coma, etc.), y falso en caso contrario.

Estas funciones son útiles en situaciones donde es necesario verificar la validez o el formato de una entrada de usuario, o cuando se necesitan manipular cadenas de texto de una manera específica.  
Para utilizar estas funciones es necesario importar el header "cctype".

Ejemplo de uso:

```C++
 #include <iostream>
#include <cctype>

using namespace std;

int main() {
	string hello {"Hello, World!"};

	for (auto c: hello) {
		if (isupper(c))
			cout << c << " is an upper case letter\n";
		if (islower(c))
			cout << c << " is a lower case letter\n";
		if (ispunct(c))
			cout << c << " is a punctuation character\n";
		if (isspace(c))
			cout << "\'" << c << "\'" << " is a whitespace character\n";
	}
}
```

Para pasar de mayusculas a minusculas un string se utiliza **toupper** o **tolower**.

```C++
 #include <iostream>
#include <cctype>

using namespace std;

// Return true if input starts with 'Y' or 'y'
bool yes_or_no(const string& input) {
	char c = input[0];

	if (toupper(c) == 'Y')                           // Is c equal to 'Y' or 'y'?
		return true;
	return false;
}

int main() {
	string input;
	cout << "Do you want to enter a string which starts with Y or y?" << endl;
	cin >> input;

	if (yes_or_no(input))
		cout << "Evidently you do!\n";
	else
		cout << R"(I will take that as a "no"!)" << endl;
}
```

## Comparacion entre dos string caseSensitive

```C++
bool equal_strings(const string& lhs, const string& rhs) {
  if (lhs.size() != rhs.size())
    return false;
  auto lit=lhs.cbegin();
  auto rit = rhs.cbegin();
  while (lit != lhs.cend() && rit != rhs.cend()) {
    if (toupper(*lit) != toupper(*rit))
    return false;
    ++lit;
    ++rit;
  }
  return true;
}
```
En este ejemplo podemos compara dos string teniendo en cuenta si fueron escritas en mayusculas o minusculas. 
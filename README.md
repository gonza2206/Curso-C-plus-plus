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

## <span style="color: yellow;">Vector library </span>

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

## <span style='color: yellow;'>Two dimensional Array </span>

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

## <span style='color: yellow;'>Numeric Types </span>

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

## <span style='color: yellow;'>String literals </span>

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

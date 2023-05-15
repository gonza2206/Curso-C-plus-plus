# Miscelaneous Features

## <span style='color: yellow;'>Bitset </span>

La libreria bitset nos permite trabajar de una forma mas comoda con bits.  
Ejemplos de uso:

```C++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	bitset<8> b1{"10101110"};              // Initialize from string literal - bitset with value 174
	bitset<8> b2{0xae};                    // Initialize from integer (decimal or hexadecimal)
	bitset<8> b3{0b1010'1110};             // Initialize from binary constant (C++14)

	cout << "b1 is " << b1 << endl;                          // Displays 10101110
	cout << "b2 in decimal is " << b2.to_ulong() << endl;    // Displays 174
	cout << "b2 as a string is " << b2.to_string() << endl;  // Displays 10101110
	cout << "b3 is " << b3 << endl;                          // Displays 10101010

	cout << "b1 has " << b1.size() << " bits\n";         //Displays 8

	// Display all the bits in b1
	cout << "The bits of b1 are: ";
	for (std::size_t i = 0; i < b1.size(); ++i)
		std::cout << b1[i] << ",";
	cout << endl;

	// Bit access with bounds checking
	cout << "Trying access to bit 8 of b1 with bounds checking\n";
	try {
		std::cout << "b1 bit "<< 8 << " = " << b1.test(8) << endl;
	}
	catch (std::exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
}
```

## Logicals Operations

```C++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	bitset<8> b1{"10101110"};                        // Bitset with value 174
	bitset<8> b2{0b010'1110};                        // Bitset with value 42

	cout << "b1 is  " << b1 << endl;                 // Displays 10101110
	cout << "~b1 is " << ~b1 << endl;                // Displays 01010001
	cout << "b2 is  " << b2 << endl;                 // Displays 00101010

	cout << "b1 & b2 is " <<(b1 & b2) << endl;       // Displays 00101010
	cout << "b1 | b2 is " << (b1 | b2) << endl;      // Displays 10001110
	cout << "b1 ^ b2 is " << (b1 ^ b2) << endl;      // Displays 10000100

	cout << "b1 << 4 is " << (b1 << 4) << endl;      // Displays 11100000
	cout << "b2 >> 2 is " << (b2 >> 2) << endl;      // Displays 00001011
}
```

## Bit Operations

```C++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
	bitset<8> b1{"10101110"};              // Bitset with value 174

	cout << "b1 = " << b1 << endl;

	auto b2 = b1;
	cout << "Calling b2.set()" << endl;
	b2.set();                              // Set all bits to true
	cout << "b2 = " << b2 << endl;

	auto b3 = b1;
	cout << "Calling b3.set(0)" << endl;
	b3.set(0);                            // Set bit 0 to true
	cout << "b3 = " << b3 << endl;

	cout << "Calling b3.set(0, false)" << endl;
	b3.set(0, false);                     // Set bit 0 to false
	cout << "b3 = " << b3 << endl;

	auto b4 = b1;
	cout << "Calling b4.reset()" << endl;
	b4.reset();                           // Set all bits to false
	cout << "b4 = " << b4 << endl;

	auto b5 = b1;
	cout << "Calling b5.reset(7)" << endl;
	b5.reset(7);                          // Set bit 7 to false
	cout << "b5 = " << b5 << endl;

	auto b6 = b1;
	cout << "Calling b6.flip()" << endl;
	b6.flip();                            // Invert all bits
	cout << "b6 = " << b6 << endl;

	auto b7 = b1;
	cout << "Calling b7.flip(7)" << endl;
	b7.flip(7);                           // Invert bit 7
	cout << "b5 = " << b5 << endl;
}
```

## Bitset Checks

• all()
Returns true if all bits are true  
• any()  
 Returns true if at least one bit is true  
• none()  
 Returns true if no bits are true  
• count()  
 Returns the number of true bits

```C++
#include <iostream>
#include <bitset>

using namespace std;

int main() {
bitset<8> b1{"10101110"}; // Bitset with value 174

    cout << "b1 = " << b1 << endl;

    bitset<8> b2;
    b2.set();                              // Set all bits to true
    cout << "b2 = " << b2 << endl;

    bitset<8> b3;
    b3.reset();                            // Set all bits to false
    cout << "b3 = " << b3 << endl << endl;

    cout << boolalpha << "Are all bits set?" << endl;
    cout << "b1: " << b1.all() << endl;
    cout << "b2: " << b2.all() << endl;
    cout << "b3: " << b3.all() << endl << endl;

    cout << boolalpha << "Are any bits set?" << endl;
    cout << "b1: " << b1.any() << endl;
    cout << "b2: " << b2.any() << endl;
    cout << "b3: " << b3.any() << endl << endl;

    cout << boolalpha << "Are no bits set?" << endl;
    cout << "b1: " << b1.none() << endl;
    cout << "b2: " << b2.none() << endl;
    cout << "b3: " << b3.none() << endl << endl;

    cout << "Number of bits set" << endl;
    cout << "b1: " << b1.count() << endl;
    cout << "b2: " << b2.count() << endl;
    cout << "b3: " << b3.count() << endl << endl;
}
```

## <span style='color: yellow;'>Tuples </span>

Un tuple es una clase la cual se comporta como una estructura. Lo cual nos permite almancenar cualquier cantidad de objetos de distinto tipo de una forma simple.

### ¿Cual es la diferencia entre Pair y Tuple?

Un std::pair tiene dos miembros, mientras que un std::tuple puede tener cualquier número de elementos
• Se accede a los miembros de un std::pair por nombre, utilizando la sintaxis de miembro, mientras que los elementos en un std::tuple son accedidos por índice, usando el función get() con plantilla:

```C++
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
	// We can create a tuple instance explicitly
	tuple<double, int, string> numbers(1.0, 2, "Three"s);

	// Or use make_tuple() to create a tuple instance
	//auto numbers{make_tuple(1.0, 2, "Three"s)};

	auto x = get<0>(numbers);                    // Store first element in x
	cout << "First element is " << x << endl;

	cout << "Setting second element to 3" << endl;
	get<1>(numbers) = 3;                         // Set second element to 3

	// C++14 allows us to use the type as the parameter, if unique
	auto i = get<int>(numbers);                  // Store int element in i
	cout << "Value of int element is " << i << endl;
}
```

## Unpacking a tuple

std::tie se usa para desempaquetar los elementos de una tuple en variables

```C++
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
	tuple<double, int, string> numbers(1.0, 2, "Three"s);

	double d;
	int i;
	string str;

	tie(d, i, str) = numbers;              // Store all elements in variables

	cout << "Tuple elements are: " << d << ", " << i << R"(, ")" << str << R"(")" << endl;
}
```

## Returning multiple values

```C++
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<double, int, string> func() {
	return {1.0, 2, "Three"s};                        // Return the tuple from the function
}

int main() {
	double d;
	int i;
	string str;
	tie(d, i, str) = func();                             // Unpack the tuple in the caller

	cout << "Elements of returned tuple are: " << d << ", " << i << R"(, ")" << str << R"(")" << endl;
}
```

## <span style='color: yellow;'>Enum </span>

En C++, "enum" es una palabra clave que se utiliza para declarar un tipo de dato enumerado. Un tipo enumerado es una lista de valores enteros con nombres simbólicos asignados a cada uno de ellos. Estos nombres simbólicos se denominan "enumeradores" y se utilizan para identificar cada uno de los valores posibles que puede tomar una variable de ese tipo.

Por ejemplo, se puede definir un tipo enumerado "Color" con tres posibles valores: "Red", "Green" y "Blue". La sintaxis para definir un tipo enumerado en C++ es la siguiente:

```C++
  enum Color {
  Red,
  Green,
  Blue
};
```

En este ejemplo, se define un tipo enumerado "Color" con tres enumeradores: "Red", "Green" y "Blue". El valor entero asignado a cada enumerador es automático y comienza en 0 para el primer enumerador y se incrementa en 1 para cada enumerador adicional.

Una vez definido un tipo enumerado, se puede declarar una variable de ese tipo y asignarle uno de los valores posibles. Por ejemplo:

```C++
  Color color = Red;
```

En este ejemplo, se declara una variable "color" de tipo "Color" y se le asigna el valor "Red".

Los tipos enumerados son útiles porque permiten definir un conjunto de valores posibles para una variable y hacer que el código sea más legible y fácil de entender al utilizar nombres simbólicos en lugar de valores enteros crípticos. Además, el compilador puede detectar errores en tiempo de compilación si se utiliza un valor que no está definido como parte del tipo enumerado.

Ejemplo de uso:

```C++
  #include <iostream>

enum Color {
  Red,
  Green,
  Blue
};

int main() {
  Color color = Red;

  switch (color) {
    case Red:
      std::cout << "El color es rojo.\n";
      break;
    case Green:
      std::cout << "El color es verde.\n";
      break;
    case Blue:
      std::cout << "El color es azul.\n";
      break;
    default:
      std::cout << "Color desconocido.\n";
      break;
  }

  return 0;
}
```

En este ejemplo, se define un tipo enumerado "Color" con tres valores posibles: "Red", "Green" y "Blue". A continuación, se declara una variable "color" de tipo "Color" y se le asigna el valor "Red". Luego, se utiliza un switch para imprimir un mensaje dependiendo del valor de "color".

En este caso, como "color" tiene el valor "Red", se imprime "El color es rojo." en la salida estándar. Si se cambia el valor de "color" a "Green" o "Blue", se imprimirán mensajes diferentes en función del valor de "color". Si se utiliza un valor que no está definido como parte del tipo enumerado, se imprimirá "Color desconocido.".

## <span style='color: yellow;'>Unions </span>

En C++, una unión es un tipo de dato compuesto que permite almacenar diferentes tipos de datos **en la misma ubicación de memoria**. A diferencia de una estructura, donde cada miembro ocupa su propia ubicación de memoria, en una unión todos los miembros comparten la misma ubicación de memoria.

Una unión se define utilizando la palabra clave "union" seguida de un nombre de identificador y una lista de miembros separados por punto y coma (;). Cada miembro de una unión puede ser de un tipo diferente, como int, float, char, etc. Por ejemplo, la siguiente declaración define una unión llamada "MyUnion" con dos miembros: un entero y un flotante:

```C++
union MyUnion {
  int myInt;
  float myFloat;
};
```

En este ejemplo, la unión "MyUnion" tiene dos miembros llamados "myInt" y "myFloat", que ocupan la misma ubicación de memoria. Si se asigna un valor a uno de los miembros, el valor del otro miembro se sobrescribirá. Por ejemplo:

```C++
MyUnion u;
u.myInt = 42;
cout << u.myInt << endl; // Output: 42
u.myFloat = 3.14;
cout << u.myFloat << endl; // Output: 3.14
cout << u.myInt << endl; // Output: 1091567616 (el valor se ha sobrescrito)
```

En este ejemplo, se crea una instancia de la unión "MyUnion" llamada "u". Se asigna el valor 42 al miembro "myInt" y se imprime su valor. Luego se asigna el valor 3.14 al miembro "myFloat" y se imprime su valor, y finalmente se imprime el valor del miembro "myInt", que ha sido sobrescrito por el valor del miembro "myFloat".

Las uniones en C++ son útiles cuando se necesita almacenar diferentes tipos de datos en la misma ubicación de memoria, y se sabe que sólo se utilizará uno de ellos en un momento dado. Algunos casos de uso comunes de las uniones incluyen:

Representación de datos en diferentes formatos: Las uniones se pueden utilizar para representar datos en diferentes formatos, como enteros y flotantes, lo que puede ser útil para convertir datos de un formato a otro.

Implementación de variantes de tipos: Las uniones se pueden utilizar para implementar variantes de tipos, que son tipos de datos que pueden contener diferentes tipos de valores en diferentes momentos.

Ahorro de memoria: Las uniones pueden ahorrar memoria en algunas situaciones, ya que sólo se utiliza la cantidad de memoria necesaria para el miembro más grande de la unión.

## Tagged Unions

Una Tagged Union, también conocida como Discriminated Union, es una estructura de datos en la que se pueden almacenar diferentes tipos de datos en una única ubicación de memoria, pero que además incluye una etiqueta (o "tag") que indica el tipo de dato que está actualmente almacenado en la estructura.

En una Tagged Union, cada miembro tiene una etiqueta asociada que indica el tipo de dato que se almacena en ese miembro. La etiqueta puede ser un valor numérico o una cadena de caracteres que identifica el tipo de dato. Por ejemplo, se podría definir una Tagged Union en C++ para representar diferentes tipos de datos, como sigue:

```C++
#include <iostream>

using namespace std;

enum class TokenType { Char, Int, Double };     // Enumerate allowed types

union Token {
	// Members are public by default
	char c;
	int i;
	double d;
};

struct TaggedToken {
    Token token;
    TokenType type;                         // "Tag" field to indicate which member is in use
};

int main() {
	TaggedToken tk;
	tk.type = TokenType::Char;              // char member is in use
	tk.token.c = 'Z';

	// Check if safe to access double member
	if (tk.type == TokenType::Double)
		cout << tk.token.d << endl;
	else
		cout << "Double member not in use\n";
}
```

Como vimos el uso de union puede ser muy beneficioso, sin embargo vimos que hay que tener especial cuidado en no sobreescribir los datos. Una mforma mas segura de utilizar unions es implementandola en una clase. De esta forma las funciones publicas accederan a la variable de tipo union e internamente la clase manejara si se puede acceder o no a esta union mediante el uso del Tag anteriormente explicado. Esto se conoce como Wrapped Tagged Union.

## Wrapped Tagged Union

Hace uso de la encapsulación para hacer cumplir el uso seguro de la unión

• La variable union es un miembro privado de la clase
• Solo se puede acceder a través de las funciones de miembros públicos de la clase  
• Estos realizan la configuración y verificación necesarias del miembro de la etiqueta.
Ejemplo:

```C++
  #include <iostream>

using namespace std;

enum class TokenType { Char, Int, Double };     // Enumerate allowed types

union Token {
	// Members are public by default
	char c;
	int i;
	double d;
};

class TokenWrapper {
	Token token;
	TokenType type;                            // "Tag" field to indicate which member is in use
public:
	void set_char(char c) {
		type = TokenType::Char;                // char member is in use
		token.c = c;
	}

	double get_double() {
		if (type == TokenType::Double)
			return token.d;
		else
			throw std::invalid_argument("Double member not in use");
	}
};

int main() {
	TokenWrapper tw;
	tw.set_char('Z');

	// Check if safe to access double member
	try {
		double d = tw.get_double();
		cout << d << endl;
	}
	catch (std::exception& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
}
```

Un ejemplo mas avanzado para la lectura del siguiente archivo binario:
El archivo tendría una estructura similar a la siguiente:

```C++
  | Tipo (1 byte) | Valor (4 bytes) |
```

```C++
| Tipo | Valor    |
|------|----------|
| 0x01 | 0x2A0000 |
| 0x02 | 0x4048F5 |
| 0x03 | 0x486F6C6... |
```

En este ejemplo, el valor "42" se almacena como un entero en formato binario de 4 bytes (0x2A en hexadecimal), el valor "3.14" se almacena como un flotante en formato binario de 4 bytes (0x4048F5 en hexadecimal) y la cadena de texto "Hola, mundo!" se almacena como una serie de caracteres en formato binario (0x486F6C6... en hexadecimal).

```C++
 #include <iostream>
#include <fstream>

struct Data {
  enum Type { Integer, Float, String } type;
  union {
    int intValue;
    float floatValue;
    char stringValue[32];
  } value;
};

int main() {
  std::ifstream file("datos.bin", std::ios::binary);
  Data data;

  while (file.read(reinterpret_cast<char*>(&data.type), 1)) {
    switch (data.type) {
      case Data::Integer:
        if (file.read(reinterpret_cast<char*>(&data.value.intValue), sizeof(int))) {
          std::cout << "Entero: " << data.value.intValue << "\n";
        }
        break;
      case Data::Float:
        if (file.read(reinterpret_cast<char*>(&data.value.floatValue), sizeof(float))) {
          std::cout << "Flotante: " << data.value.floatValue << "\n";
        }
        break;
      case Data::String:
        if (file.read(data.value.stringValue, sizeof(data.value.stringValue))) {
          std::cout << "Cadena: " << data.value.stringValue << "\n";
        }
        break;
      default:
        std::cout << "Tipo desconocido.\n";
        break;
    }
  }

  return 0;
}
```

En este ejemplo, abrimos el archivo "datos.bin" en modo binario y leemos los datos en la estructura "Data" utilizando la función "read". La estructura "Data" tiene una etiqueta de tipo "Type" que indica el tipo de dato que se está leyendo: "Integer", "Float" o "String". La unión "value" contiene los valores en sí mismos: "intValue" para enteros, "floatValue" para flotantes y "stringValue" para cadenas de texto.

Dentro del while loop, utilizamos un switch statement para leer los valores según el tipo de dato leído. Para leer los valores de la unión "value", utilizamos la función "read" para leer los bytes correspondientes del archivo y luego reinterpretamos el puntero a char a un puntero al tipo de dato correspondiente.

Es importante notar que en este ejemplo se asume que los valores están almacenados en el archivo en el orden en que aparecen en la estructura "Data", es decir, primero el campo "type" y luego el campo "value". Si el orden de los campos fuera diferente, se necesitaría ajustar la forma en que se lee el archivo.

## <span style='color: yellow;'>Member function pointers </span>

Los member function pointers (punteros a funciones miembro) son punteros que apuntan a funciones miembro de una clase en particular. Es decir, son punteros que apuntan a una función específica de un objeto de una clase, y que pueden ser utilizados para llamar a esa función en cualquier momento.

Los member function pointers son útiles cuando se desea llamar a una función miembro de una clase, pero no se sabe exactamente cuál es la función que se desea llamar en tiempo de compilación. Por ejemplo, se pueden utilizar para llamar a diferentes funciones miembro de una misma clase en función de una condición determinada en tiempo de ejecución.

Para definir un puntero a una función miembro, se utiliza la siguiente sintaxis:

```C++
tipo_retorno (clase::*nombre_puntero)(tipo_arg1, tipo_arg2, ...);
```

Donde tipo_retorno es el tipo de dato que devuelve la función miembro, clase es el nombre de la clase a la que pertenece la función, nombre_puntero es el nombre que se le da al puntero a la función miembro, y tipo_arg1, tipo_arg2, etc. son los tipos de datos de los argumentos que recibe la función miembro.

A continuación, se muestra un ejemplo de cómo se puede utilizar un member function pointer:

```C++
  #include <iostream>

class MiClase {
public:
    int suma(int a, int b) {
        return a + b;
    }
};

int main() {
    MiClase obj;
    int (MiClase::*puntero_suma)(int, int) = &MiClase::suma;
    int resultado = (obj.*puntero_suma)(2, 3);
    std::cout << "El resultado de la suma es: " << resultado << std::endl;
    return 0;
}
```

En este ejemplo, definimos una clase llamada MiClase que tiene una función miembro llamada suma. Luego, creamos un objeto obj de la clase MiClase. A continuación, definimos un puntero a la función miembro suma utilizando la sintaxis de los member function pointers, y lo inicializamos con la dirección de la función suma de la clase MiClase. Finalmente, utilizamos el operador de puntero a miembro .\* para llamar a la función suma a través del objeto obj.

La salida del programa sería:

```C++
  El resultado de la suma es: 5
```

También es posible llamar a una función miembro a través de un puntero a función miembro utilizando el operador ->_ en lugar del operador ._ El operador ->\_ se utiliza para llamar a una función miembro a través de un puntero a función miembro que apunta a un objeto en el heap.

A continuación, se muestra un ejemplo de cómo se utiliza el operador de puntero a miembro para llamar a una función miembro a través de un puntero a función miembro utilizando el operador ->\_ en C++:

```C++
#include <iostream>

class MiClase {
public:
    int suma(int a, int b) {
        return a + b;
    }
};

int main() {
    MiClase* obj = new MiClase();
    int (MiClase::*puntero_suma)(int, int) = &MiClase::suma;
    int resultado = (obj->*puntero_suma)(2, 3);
    std::cout << "El resultado de la suma es: " << resultado << std::endl;
    delete obj;
    return 0;
}
```

En este ejemplo, definimos una clase llamada MiClase que tiene una función miembro llamada suma. Luego, creamos un objeto obj de la clase MiClase en el heap utilizando el operador new. A continuación, definimos un puntero a la función miembro suma utilizando la sintaxis de los member function pointers, y lo inicializamos con la dirección de la función suma de la clase. Finalmente, llamamos a la función miembro suma a través del puntero a función miembro utilizando el operador ->\*. Después de usar el objeto obj, lo eliminamos utilizando el operador delete.

## Para que es util esto?

El uso de punteros a funciones miembro y los operadores ._ y ->_ en C++ permite una mayor flexibilidad en el diseño de programas orientados a objetos y en el manejo de estructuras de datos complejas. Algunas situaciones en las que estos conceptos pueden resultar útiles incluyen:

Diseño de interfaces genéricas: las plantillas y los punteros a funciones miembro permiten crear interfaces genéricas que puedan funcionar con diferentes tipos de objetos y funciones miembro.

Implementación de algoritmos genéricos: los algoritmos genéricos pueden ser implementados de manera más flexible y reusable utilizando punteros a funciones miembro.

Acceso a elementos de estructuras de datos complejas: cuando una estructura de datos contiene objetos de diferentes clases que tienen funciones miembro con el mismo nombre y firma, los punteros a funciones miembro pueden utilizarse para acceder a estas funciones de manera unificada.

En general, el uso de punteros a funciones miembro y los operadores ._ y ->_ permite una mayor modularidad y flexibilidad en el diseño de programas orientados a objetos y puede resultar muy útil en situaciones en las que se requiere una mayor abstracción y reusabilidad del código.

## <span style='color: yellow;'>Interfacing to C </span>

Interfacing to C (interfaz con C) es la técnica de crear una interfaz entre un lenguaje de programación en particular y C. El objetivo de la interfaz es permitir que el lenguaje de programación interactúe con las bibliotecas escritas en C y permita que las bibliotecas escritas en C se utilicen desde el lenguaje de programación.

C es un lenguaje de programación muy popular debido a su eficiencia y portabilidad, y se utiliza ampliamente en la programación de sistemas operativos, controladores de dispositivos y bibliotecas de software. La interfaz con C permite que los desarrolladores de software que utilizan otros lenguajes de programación accedan a estas bibliotecas de software y utilicen su funcionalidad en sus propios programas.

Para crear una interfaz con C, es necesario definir un conjunto de funciones que actúen como envoltorios (wrappers) para las funciones en la biblioteca de C. Estas funciones envolventes proporcionan una capa de abstracción que permite que los programas escritos en otros lenguajes de programación se comuniquen con la biblioteca de C utilizando tipos de datos y convenciones de llamada que son compatibles con C.

En resumen, la interfaz con C es una técnica que permite que los programas escritos en otros lenguajes de programación se comuniquen con las bibliotecas de software escritas en C, lo que aumenta la interoperabilidad y la reutilización de software entre diferentes lenguajes de programación.

## Mangiling

El compilador de C++ cambiará el nombre de una función codificando el
detalles del argumento en él. Esto es necesario para implementar la sobrecarga de funciones.
Esto es un problema ya que C no cambia el nombre de las funciones en el binario ya que no existe sobreacarga de funciones. por lo que se debe usar la palabra clave

```C++
extern "C" **nombre de funcion**;
extern "C" int add(int x, int y);
```

Esto le indica al compilador que no manipule los nombres de las funciones. El código resultante será compatible con C.

Para crear correctamente un encabezado que sea compatible con C es necesario dar instrucciones al compilador antes de que empiece a compilar el programa. Estas instrucciones o "directivas" son denominadas directivas de preprocesador.

#ifdef es una directiva de preprocesador en C y C++ que se utiliza para condicionalmente incluir o excluir secciones de código del programa durante el proceso de compilación. La directiva #ifdef verifica si una macro está definida y, si es así, incluye el bloque de código que sigue a continuación. Si la macro no está definida, entonces el bloque de código se omite.

Por ejemplo, se puede utilizar #ifdef para crear versiones diferentes de un programa para sistemas operativos diferentes. En el siguiente ejemplo, el código que utiliza la función fork() sólo se incluirá si se está compilando en un sistema operativo que lo soporta:

```C++
  #ifdef _WIN32
    // Código para sistemas operativos Windows
#else
    // Código para sistemas operativos no-Windows
    #ifdef _POSIX_VERSION
        // Código para sistemas operativos POSIX
        #include <unistd.h>
    #endif
#endif
```

Volviendo al tema que nos compete si queremos hacer una interfaz a C desde C++ el encabezado para poder utilizar codigo que C entienda seria:

```C++
#ifndef ADD_H
#define ADD_H

#ifdef __cplusplus
extern "C" int add(int x, int y);
#else
int add(int x, int y);
#endif

#endif //ADD_H
```

## \_\_cplusplus

\_\_cplusplus es una macro definida por el compilador C++ que indica la versión del estándar de C++ que se está utilizando. Esta macro se puede utilizar en el código fuente para hacer comprobaciones en tiempo de compilación y permitir el uso de características específicas del estándar de C++.
Por ejemplo, se puede utilizar esta macro para definir diferentes comportamientos del código en función de la versión del estándar de C++ que se esté utilizando. También se puede utilizar para incluir encabezados específicos del estándar de C++ en el código fuente.

Aquí hay un ejemplo de cómo se puede utilizar la macro \_\_cplusplus para hacer comprobaciones en tiempo de compilación:

```C++
  #include <iostream>

int main() {
  #ifdef __cplusplus
    std::cout << "Estándar de C++ utilizado: " << __cplusplus << "\n";
  #endif
  return 0;
}
```

En este ejemplo, se utiliza la macro \_\_cplusplus para imprimir la versión del estándar de C++ que se está utilizando. La macro se envuelve en un bloque #ifdef para asegurarse de que sólo se utilice si se está compilando con un compilador de C++.

\_\_ (dos guiones bajos) es un prefijo que se utiliza en C y C++ para identificar identificadores reservados o definidos por el compilador. Estos identificadores se conocen como macros del sistema o macros definidas por el compilador, y proporcionan información adicional al programador sobre el estado del programa o la plataforma en la que se está ejecutando.

Por ejemplo, aparte de **cplusplus, hay otras macros definidas por el compilador que comienzan con **, como **FILE**, **LINE** y **func**, que proporcionan información sobre el archivo fuente, la línea y la función en la que se encuentran, respectivamente.\*\*

Es importante tener en cuenta que el uso de identificadores que comienzan con \_\_ en el código fuente del usuario se considera una mala práctica, ya que estos identificadores están reservados para el uso del compilador y pueden cambiar entre diferentes compiladores o versiones del mismo compilador, lo que puede causar errores o comportamientos inesperados.

## <span style='color: yellow;'>Multiple Inheritance </span>

La herencia múltiple es una característica de C++ que permite a una clase derivada heredar miembros y comportamientos de varias clases base diferentes. En la herencia múltiple, una clase derivada puede tener más de una clase base directa, y por lo tanto, puede heredar miembros y comportamientos de todas ellas.

Cuando una clase derivada hereda de varias clases base, puede haber una ambigüedad en el acceso a los miembros heredados. Esto se debe a que dos o más clases base pueden tener miembros con el mismo nombre y tipo. En este caso, es necesario especificar cuál de los miembros heredados se quiere utilizar.

Por ejemplo, considera el siguiente código:

```C++
  class A {
public:
    int x;
};

class B {
public:
    int x;
};

class C : public A, public B {
public:
    void print() {
        std::cout << "x from A: " << A::x << std::endl;
        std::cout << "x from B: " << B::x << std::endl;
    }
};

int main() {
    C c;
    c.A::x = 1;
    c.B::x = 2;
    c.print();
    return 0;
}

```

En este ejemplo, la clase C hereda de las clases A y B. Ambas clases tienen un miembro llamado x. En la función print() de la clase C, se especifica cuál de los miembros x se quiere utilizar al imprimir los valores de x heredados de las clases A y B. En la función main(), se crea un objeto de la clase C y se establecen los valores de los miembros x heredados de las clases A y B.

En lo que respecta a constructores y destructores estos seran llamados en el orden en que fueron declarados y se iran destruyendo en orden inverso.

Ejemplo de uso.

```C++
 #include <iostream>

using namespace std;

struct Params {};

// Hardware class
class HardwareDevice {
public:
	HardwareDevice() { cout << "Calling HardwareDevice constructor\n"; }
	~HardwareDevice() { cout << "Calling HardwareDevice destructor\n"; }
	bool initialize(Params&) {
		cout << "Calling HardwareDevice::initialize()\n";
		return true;
	}
	void get_data() {
		cout << "Calling HardwareDevice::get_data()\n";
	}
};

// User interaction class
class TouchResponder {
public:
	TouchResponder() { cout << "Calling TouchResponder constructor\n"; }
	~TouchResponder() { cout << "Calling TouchResponder destructor\n"; }
	void initialize() {
		cout << "Calling TouchResponder::initialize()\n";
	}
	bool touch_down() {
		cout << "Calling TouchResponder::touch_down()\n";
		return true;
	}
};

// Classes which inherit from both HardwareDevice and TouchResponder
class Mouse: public HardwareDevice, public TouchResponder {
public:
	Mouse() { cout << "Calling Mouse constructor\n"; }
	~Mouse() { cout << "Calling Mouse destructor\n"; }
	bool initialize(Params& params) {
		cout << "Calling Mouse::initialize()\n";
		HardwareDevice::initialize(params);
		TouchResponder::initialize();
		return true;
	}
	void process() {                                    // Member function in Mouse class
		if (touch_down())                               // Mouse inherits touch_down() from TouchResponder
			get_data();                                 // Mouse inherits get_data() from HardwareDevice
	}
};

int main() {
	Mouse mouse;
	Params params;
	mouse.initialize(params);
}
```

Tenemos dos clases que hacen diferentes cosas y utilizamos una clase para unirlas. Esto es util si queremos llamar distintas clases dentro de otra clase.

En resumen, la herencia múltiple en C++ permite a una clase derivada heredar miembros y comportamientos de varias clases base diferentes. Sin embargo, puede haber una ambigüedad en el acceso a los miembros heredados cuando dos o más clases base tienen miembros con el mismo nombre y tipo. En este caso, es necesario especificar cuál de los miembros heredados se quiere utilizar.

## <span style='color: yellow;'>Multiple Inheritance </span>

La herencia múltiple en C++ es una característica que permite a una clase heredar de más de una clase base. Cuando una clase hereda de múltiples clases base, se dice que la clase heredera tiene una "herencia múltiple".

La herencia virtual en C++ es un tipo de herencia que se utiliza cuando una clase hereda de múltiples clases base y una o más de esas clases base también heredan de una misma clase base común. La herencia virtual se utiliza para resolver el problema conocido como "diamante de la muerte" (diamond problem) que puede ocurrir cuando se tiene una jerarquía de clases que incluye múltiples niveles de herencia.

El diamante de la muerte ocurre cuando una clase hereda de dos clases base que a su vez heredan de la misma clase base. Esto crea una ambigüedad en la clase heredera sobre cómo resolver las funciones que se definen en la clase base común. Para resolver este problema, se utiliza la herencia virtual.

En la herencia virtual, la clase base común sólo se hereda una vez por la clase heredera, independientemente de cuántas veces se herede en las clases base. Esto garantiza que sólo haya una instancia de la clase base común en la clase heredera, evitando así ambigüedades.

Para utilizar la herencia virtual en C++, se utiliza la palabra clave "virtual" en la declaración de herencia en la clase base. Por ejemplo, si se tiene una clase "A" que es heredada por dos clases "B" y "C", y luego otra clase "D" hereda de ambas "B" y "C", se podría utilizar la herencia virtual de la siguiente manera:

```C++
  class A {
  // Definición de la clase A
};

class B : virtual public A {
  // Definición de la clase B
};

class C : virtual public A {
  // Definición de la clase C
};

class D : public B, public C {
  // Definición de la clase D
};
```

En este ejemplo, se utiliza la palabra clave "virtual" al heredar de la clase "A" en las clases "B" y "C". Esto garantiza que la clase "D" sólo tenga una instancia de la clase "A".

Otro ejemplo:

```C++
#include <iostream>

using namespace std;

class Employee {
public:
	void address() { cout << "Employee address = " << static_cast<void *>(this) << endl; }
};

class SalesEmployee: public virtual Employee {
};

class Manager: public virtual Employee {
};

class SalesManager: public SalesEmployee, public Manager {
};

int main() {
	SalesManager sm;

	cout << "Cast to SalesEmployee\n";
	SalesEmployee* se{static_cast<SalesEmployee *>(&sm)};
	se->address();

	cout << "Cast to Manager\n";
	Manager* m{static_cast<Manager *>(&sm)};
	m->address();
}
```

## <span style='color: yellow;'>INLINE </span>

La palabra clave "inline" puede tener dos usos. Para funciones y para namespaces.

## Inline con namespaces

Un nested namespace es un namespace que esta definido dentro de otro namespace:

```C++
  namespace A {
    namespace B {                   // Namespace B is "nested" inside namespace A
        int x;                      // x is a symbol defined in namespace B
    }
    //B::x;                         // To use x in namespace A, we must put B:: in front of it
}

int main() {
	A::B::x = 5;                    // To use x in the global namespace, we put A::B::
}
```

Como puede ser un poco engorroso tener que llamar a tantos namespaces se puede utilizar la palabra clave `inline`.

```C++
  namespace A {
    inline namespace B {            // Namespace B is "inline" to namespace A
        int x;                      // x is a symbol defined in namespace B
    }
    //x;                            // No need to put B:: here
}

int main() {
	A::x = 5;                       // To use x outside the namespaces, we can just put A::
}
```

Esto funcionara de la misma forma que el ejemplo anterior. Sin embargo los simbols definidos en el inline namespace pueden ser accedidos como si hubieran sido definidos en el namespace exterior.
Por eso podemos llamar a x unicamente colocando A::, sindo que x pertenece al namespace de B.

### ¿Cuando es util usar namespaces?

Esto es util cuando queremos hacer versiones, por ejemplo:

El codigo de la version actual es un inline namespace, el codigo para otra version es un nested namespace.
Sin hacer ninguna operacion podemos obtener la nueva version del codigo. Esto haciendo la nueva version inline.

Tenemos la version 1

```C++

#ifndef VERSION1_H
#define VERSION1_H

#include <iostream>

inline namespace version1 {
	class refrigerator {
		int temperature{2};
		bool door_open{false};
		bool power_on{true};
	public:
		refrigerator() {}
		refrigerator(int temperature) : temperature(temperature) {}
		void print() {
			std::cout << "Temperature = " << temperature;
			std::cout << std::boolalpha;
			std::cout << ", door_open = " << door_open;
			std::cout << ", power_on = " << power_on;
		}
	};
}

#endif // VERSION1_H
```

Y la version 2

```C++
#ifndef VERSION2_H
#define VERSION2_H

#include <iostream>
#include <string>

namespace version2 {
	class Internet {
		public:
		void connect() { std::cout << "Connected to Internet" << std::endl; }
		void login(const std::string&id, const std::string& pw) { std::cout << "Logging in!" << std::endl; }
	};

	class refrigerator {
		// Data members
		int temperature{2};
		bool door_open{false};
		bool power_on{true};
		Internet internet;
	public:
		refrigerator() : refrigerator(2, "me", "secret") {}
		refrigerator(int temperature) : refrigerator(temperature, "me", "secret") {}
		refrigerator(const std::string& id, const std::string& pw) : refrigerator(2, id, pw) {}
		refrigerator(int temperature, const std::string& id, const std::string& pw) :
						temperature(temperature) { internet.connect(); internet.login(id, pw); }
		void print() {
			std::cout << "Temperature = " << temperature;
			std::cout << std::boolalpha;
			std::cout << ", door_open = " << door_open;
			std::cout << ", power_on = " << power_on;
		}
	};
}

#endif // VERSION2_H
```

En el main

```C++
#include <iostream>
#include <string>

namespace product {
	#include "version1.h"
	#include "version2.h"

	void test() {
		refrigerator fridge;
		fridge.print();
	}
}

int main() {
	product::test();
}
```

En resumen, la palabra clave "inline" en C++ se puede utilizar con funciones definidas en un espacio de nombres, y se aplican las mismas reglas de inclusión en línea que en cualquier otra función. La función definida en el espacio de nombres se considera como si se hubiera definido fuera de él, y se debe hacer referencia al espacio de nombres en el que se define la función cuando se utiliza en el código.

## Inline en funciones

En C++, la palabra clave "inline" se utiliza para sugerir al compilador que una función se debe insertar en línea en el código fuente en lugar de llamarla mediante una llamada de función. La inclusión en línea de una función puede mejorar el rendimiento del código en algunas situaciones, especialmente cuando la función es pequeña y se llama muchas veces.

Cuando se utiliza la palabra clave "inline" en la definición de una función, el compilador intentará reemplazar todas las llamadas a esa función en el código por el cuerpo de la función en sí. Esto puede reducir la sobrecarga de la llamada de función y mejorar el rendimiento en algunos casos.

Por ejemplo, si se tiene una función "suma" que simplemente suma dos números y se llama muchas veces en el código, se podría utilizar la palabra clave "inline" para sugerir al compilador que incluya el cuerpo de la función directamente en el código donde se llama:

```C++
  inline int suma(int a, int b) {
  return a + b;
}
```

En este ejemplo, se utiliza la palabra clave "inline" en la definición de la función "suma". Esto indica al compilador que debe intentar insertar el cuerpo de la función en línea en lugar de hacer una llamada de función.

Es importante tener en cuenta que la inclusión en línea de una función no siempre mejora el rendimiento del código. En algunos casos, puede aumentar el tamaño del código y hacer que el programa sea más lento debido a la caché de memoria y otros factores. Por lo tanto, se recomienda utilizar la palabra clave "inline" sólo en funciones pequeñas que se llamen con frecuencia y se ha demostrado que mejoran el rendimiento.

## <span style='color: yellow;'>Attributes </span>

los atributos (attributes) son anotaciones que se pueden añadir a declaraciones de variables, funciones, clases, etc. Los atributos se utilizan para proporcionar información adicional al compilador y a otras herramientas de desarrollo, como depuradores y analizadores de código.

Los atributos se definen utilizando la sintaxis de doble corchete "[[]]". Se colocan justo antes de la declaración a la que se aplican. Por ejemplo, para aplicar un atributo "deprecated" a una función, se puede hacer lo siguiente:

```C++
  [[deprecated]] void funcionAntigua();
```

En este ejemplo, el atributo "deprecated" indica que la función "funcionAntigua" ya no se recomienda su uso y que se considera obsoleta. El compilador puede generar una advertencia o un error al compilar el código que utiliza esta función.

Además del atributo "deprecated", que se utiliza para marcar elementos obsoletos, C++ incluye una serie de atributos estándar que se pueden utilizar para proporcionar información adicional al compilador. Algunos ejemplos de estos atributos estándar son:

- "noreturn": indica que una función no regresa nunca (por ejemplo, porque lanza una excepción o porque entra en un bucle infinito).
- "const": indica que una función o una variable no modifica su estado interno.
- "align": indica el alineamiento que se debe aplicar a una variable (por ejemplo, para mejorar el rendimiento en ciertas arquitecturas de procesador).
- "packed": indica que una estructura o una clase debe tener un tamaño mínimo (por ejemplo, para mejorar la eficiencia de la memoria).

Además de los atributos estándar, los desarrolladores de C++ pueden definir sus propios atributos personalizados. Esto se hace mediante la definición de macros o mediante la utilización de las capacidades de plantillas de C++. Los atributos personalizados pueden ser muy útiles para proporcionar información adicional a herramientas de desarrollo y bibliotecas de terceros que se utilizan en el proyecto.

Ejemplos de uso:

1. Atributo "noreturn"
   Este atributo se utiliza para indicar al compilador que una función no va a regresar a su llamada. Por ejemplo, una función que lanza una excepción no regresará nunca. Se puede utilizar de la siguiente manera:

```C++
  [[noreturn]] void lanzarExcepcion() {
  throw "¡Se ha producido un error!";
}
```

En este ejemplo, la función "lanzarExcepcion" utiliza el atributo "noreturn" para indicar que no regresará a su llamada después de lanzar una excepción.

2. Atributo "const"
   Este atributo se utiliza para indicar que una función o variable no modifica su estado interno. Por ejemplo, una función que sólo lee un valor de una variable puede ser marcada como "const". Se puede utilizar de la siguiente manera:

```C++
class Persona {
public:
  [[nodiscard]] const std::string& getNombre() const {
    return nombre;
  }
private:
  std::string nombre;
};

```

En este ejemplo, la función "getNombre" de la clase "Persona" utiliza el atributo "const" para indicar que no modifica el estado interno del objeto. Además, utiliza el atributo "nodiscard" para indicar que la función devuelve un valor que no debe ser ignorado.

3. Atributo "align"
   Este atributo se utiliza para indicar el alineamiento que se debe aplicar a una variable. Por ejemplo, se puede utilizar para mejorar el rendimiento en ciertas arquitecturas de procesador. Se puede utilizar de la siguiente manera:

```C++
  struct Registro {
  int valor1;
  [[align(16)]] double valor2;
};
```

En este ejemplo, la estructura "Registro" utiliza el atributo "align" para indicar que el segundo valor de la estructura (de tipo "double") debe tener un alineamiento de 16 bytes.

4. Atributo "packed"
   Este atributo se utiliza para indicar que una estructura o una clase debe tener un tamaño mínimo. Por ejemplo, se puede utilizar para mejorar la eficiencia de la memoria en ciertos sistemas embebidos. Se puede utilizar de la siguiente manera:

```C++
  struct Registro {
  char letra;
  int valor;
} __attribute__((packed));
```

En este ejemplo, la estructura "Registro" utiliza el atributo "packed" para indicar que no debe haber ningún espacio entre los miembros de la estructura y que el tamaño total de la estructura debe ser mínimo.

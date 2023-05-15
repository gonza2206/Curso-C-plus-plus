# COMPILE-TIME PROGRAMING

## <span style='color: yellow;'>Const expression </span>

"constexpr" es una palabra clave que se utiliza para declarar que una expresión o función puede ser evaluada en tiempo de compilación y que, por lo tanto, puede ser utilizada en contextos que requieren constantes conocidas en tiempo de compilación. La evaluación de una expresión "constexpr" se realiza en tiempo de compilación, lo que significa que no hay costo de tiempo de ejecución en la evaluación de la expresión en sí.

Una expresión "constexpr" puede ser utilizada para inicializar una variable constante o como el tamaño de una matriz o el valor de una plantilla. Por ejemplo, la siguiente declaración utiliza "constexpr" para definir el valor de una constante:

```C++
 constexpr int valor = 42;
```

En este ejemplo, "valor" es una constante que se puede utilizar en contextos que requieren una constante conocida en tiempo de compilación.

Además de las expresiones "constexpr", también se puede utilizar la palabra clave "constexpr" para declarar funciones que se pueden evaluar en tiempo de compilación. Las funciones "constexpr" son funciones que se pueden llamar con argumentos constantes y que siempre producirán resultados constantes conocidos en tiempo de compilación. Por ejemplo:

```C++
  constexpr int cuadrado(int x) {
  return x * x;
}
```

En este ejemplo, la función "cuadrado" se declara como "constexpr", lo que indica que se puede utilizar en contextos que requieren constantes conocidas en tiempo de compilación.

Otro ejemplo de uso de "constexpr" en C++ puede ser la definición de valores constantes utilizando funciones o expresiones que se pueden evaluar en tiempo de compilación. Por ejemplo:

```C++
constexpr double PI = 3.14159265358979323846;

constexpr int factorial(int n) {
  return (n <= 1) ? 1 : (n * factorial(n-1));
}

constexpr int fib(int n) {
  return (n <= 1) ? n : (fib(n-1) + fib(n-2));
}
```

En este ejemplo, se definen constantes utilizando funciones "constexpr". La constante "PI" se define como una expresión constante, mientras que las funciones "factorial" y "fib" son funciones "constexpr" que calculan el factorial y la secuencia de Fibonacci respectivamente.

Estas constantes y funciones se pueden utilizar en cualquier parte del código donde se requieran valores constantes conocidos en tiempo de compilación. Por ejemplo:

```C++
  double areaCirculo(double radio) {
  return PI * radio * radio;
}

constexpr int valorFactorial = factorial(5);

int main() {
  double area = areaCirculo(2.5);
  std::cout << "Área del círculo: " << area << std::endl;
  std::cout << "5! = " << valorFactorial << std::endl;
  return 0;
}
```

En este ejemplo, la constante "PI" se utiliza para calcular el área de un círculo, mientras que la constante "valorFactorial" se utiliza para imprimir el factorial de 5 en la salida estándar. Como ambas constantes se definen como "constexpr", se garantiza que se evalúan en tiempo de compilación y que su valor es conocido en tiempo de compilación, lo que mejora el rendimiento del programa.

## ¿Cual es la diferencia entre constexpr y const?

La principal diferencia entre "constexpr" y "const" en C++ es que "constexpr" se utiliza para definir constantes que pueden ser evaluadas en tiempo de compilación, mientras que "const" se utiliza para definir variables que no pueden ser modificadas una vez que se han inicializado.

## <span style='color: yellow;'>Classes and Templates </span>

Los templates en C++ son una característica que permite definir funciones y clases genéricas que pueden trabajar con diferentes tipos de datos sin necesidad de especificarlos de antemano. En esencia, los templates permiten escribir código genérico que puede ser utilizado con diferentes tipos de datos, lo que hace que el código sea más reutilizable y flexible.

Para definir una función o clase genérica utilizando templates, se utiliza la palabra clave "template" seguida de una lista de parámetros de tipo entre corchetes angulares. Por ejemplo, para definir una función que calcule el máximo entre dos valores de cualquier tipo, se puede utilizar el siguiente código:

```C++
  template<typename T>
T maximo(T a, T b) {
  return (a > b) ? a : b;
}
```

En este ejemplo, la función "maximo" se define utilizando la palabra clave "template" seguida del parámetro de tipo "T". Esto indica que la función puede ser utilizada con cualquier tipo de dato, siempre y cuando se especifique en tiempo de compilación. Dentro de la función, se utilizan los parámetros "a" y "b" del tipo "T" para calcular el máximo entre ellos y se devuelve el resultado.

Para utilizar la función "maximo" con un tipo de dato específico, se debe especificar el tipo de dato en tiempo de compilación. Por ejemplo:

```C++
int maximo_entero = maximo<int>(5, 10);
double maximo_flotante = maximo<double>(3.14159, 2.71828);

```

En este ejemplo, se utiliza la función "maximo" con el tipo de dato "int" y "double", respectivamente. Se especifica el tipo de dato dentro de los corchetes angulares utilizando la sintaxis "nombre_de_la_funcion<tipo_de_dato>(argumentos)".

## Generic Classes

Además de las funciones genéricas, los templates también se pueden utilizar para definir clases genéricas. Por ejemplo, se puede definir una clase de pila genérica utilizando templates de la siguiente manera:

```C++
 template<typename T>
class Pila {
public:
  Pila() {}
  void push(T valor) { datos.push_back(valor); }
  T pop() {
    T valor = datos.back();
    datos.pop_back();
    return valor;
  }
private:
  std::vector<T> datos;
};

```

En este ejemplo, se define una clase de pila genérica utilizando la palabra clave "template" seguida del parámetro de tipo "T". Dentro de la clase, se utilizan los parámetros de tipo "T" para definir el tipo de los datos almacenados en la pila y se proporcionan los métodos "push" y "pop" para agregar y quitar elementos de la pila.

Para utilizar la clase de pila genérica con un tipo de dato específico, se debe especificar el tipo de dato en tiempo de compilación. Por ejemplo:

```C++
Pila<int> pila_enteros;
pila_enteros.push(5);
pila_enteros.push(10);
int valor = pila_enteros.pop();

Pila<std::string> pila_cadenas;
pila_cadenas.push("hola");
pila_cadenas.push("mundo");
std::string cadena = pila_cadenas.pop();
```

En este ejemplo, se crean dos instancias de la clase de pila genérica: una para enteros y otra para cadenas de caracteres. Se especifica el tipo de dato dentro de los corchetes angulares utilizando la sintaxis "nombre_de_la_clase<tipo_de_dato>". Luego, se utilizan los métodos "push" y "pop" para agregar y quitar elementos de las pilas.

Además de los parámetros de tipo, los templates también pueden utilizar valores constantes como parámetros. Esto se hace utilizando la palabra clave "constexpr" antes del tipo de dato o valor constante utilizado como parámetro. Por ejemplo:

```C++
template<const int N>
class Arreglo {
public:
  Arreglo() {}
  int size() { return N; }
private:
  int datos[N];
};

constexpr int TAMANIO = 10;
Arreglo<TAMANIO> mi_arreglo;
```

"nombre_de_la_clase<tipo_de_dato>". Luego, se utilizan los métodos "push" y "pop" para agregar y quitar elementos de las pilas.

Además de los parámetros de tipo, los templates también pueden utilizar valores constantes como parámetros. Esto se hace utilizando la palabra clave "constexpr" antes del tipo de dato o valor constante utilizado como parámetro. Por ejemplo:

arduino
Copy code
template<const int N>
class Arreglo {
public:
Arreglo() {}
int size() { return N; }
private:
int datos[N];
};

constexpr int TAMANIO = 10;
Arreglo<TAMANIO> mi_arreglo;

En este ejemplo, se define una clase de arreglo genérica utilizando un valor constante como parámetro. La palabra clave "constexpr" indica que el valor de "N" es constante en tiempo de compilación. Dentro de la clase, se utiliza el valor de "N" para definir el tamaño del arreglo. Luego, se crea una instancia de la clase de arreglo genérica utilizando una constante llamada "TAMANIO".

## Especialice Templeates

Otra forma en la que se pueden utilizar los templates es mediante la especialización. La especialización de un template permite definir una versión específica del mismo para un tipo de dato concreto. Por ejemplo:

```C++
template<typename T>
class Clase {
public:
  void funcion() {
    std::cout << "Version general" << std::endl;
  }
};

template<>
class Clase<int> {
public:
  void funcion() {
    std::cout << "Version especializada para int" << std::endl;
  }
};

Clase<double> c1;
c1.funcion(); // Imprime "Version general"

Clase<int> c2;
c2.funcion(); // Imprime "Version especializada para int"

```

En este ejemplo, se define una clase genérica llamada "Clase" utilizando un parámetro de tipo "T". La clase tiene un método llamado "funcion" que imprime un mensaje en la consola. Luego, se define una especialización de la clase "Clase" para el tipo de dato "int", que tiene una implementación diferente del método "funcion". Finalmente, se crean dos instancias de la clase "Clase" utilizando diferentes tipos de datos.

Cuando se llama al método "funcion" de la instancia "c1" de la clase "Clase", se utiliza la versión genérica del método, que imprime "Version general". Cuando se llama al método "funcion" de la instancia "c2" de la clase "Clase", se utiliza la versión especializada del método para el tipo de dato "int", que imprime "Version especializada para int".

En resumen, la especialización de templates permite definir versiones específicas de una función o clase para tipos de datos concretos. Esto permite escribir código más eficiente y específico para ciertos tipos de datos. Sin embargo, se debe tener cuidado al utilizar la especialización de templates, ya que puede aumentar la complejidad del código y disminuir la flexibilidad del mismo.

## Extern Templeates

La palabra clave "extern template" en C++ se utiliza para evitar la instanciación explícita de un template en un archivo de código fuente. Cuando se utiliza "extern template", se indica al compilador que la instanciación del template se realizará en otro archivo de código fuente.

La sintaxis de "extern template" es la siguiente:

```C++
  extern template class nombre_de_la_clase<tipo_de_dato>;
```

En esta sintaxis, se utiliza la palabra clave "extern" seguida de "template", la palabra clave "class", el nombre de la clase de template y el tipo de dato utilizado como parámetro. Por ejemplo:

```C++
  // archivo1.cpp
template<class T>
class Clase {
public:
  void funcion() {}
};

extern template class Clase<int>; // Evita la instanciación explícita de Clase<int>

// archivo2.cpp
#include "archivo1.cpp"

int main() {
  Clase<int> c; // Instancia de Clase<int>
  c.funcion();
  return 0;
}
```

En este ejemplo, se define una clase de template llamada "Clase" en el archivo "archivo1.cpp". Luego, se utiliza "extern template" para evitar la instanciación explícita de "Clase<int>" en "archivo1.cpp". Finalmente, en "archivo2.cpp", se incluye el archivo "archivo1.cpp" y se crea una instancia de "Clase<int>" utilizando la sintaxis normal de templates.

La ventaja de utilizar "extern template" es que puede reducir el tiempo de compilación al evitar la instanciación explícita de templates en cada archivo de código fuente. Esto es especialmente útil en proyectos grandes donde se utilizan templates complejos que tardan mucho tiempo en compilar.

En resumen, "extern template" es una palabra clave en C++ que se utiliza para evitar la instanciación explícita de templates en un archivo de código fuente. Esto puede mejorar el tiempo de compilación en proyectos grandes que utilizan templates complejos.

## <span style='color: yellow;'>Variadic templeates </span>

Los variadic templates son una característica de C++ que permiten definir templates con un número variable de argumentos. Esto significa que se pueden definir templates que aceptan cualquier cantidad de argumentos de cualquier tipo.

La sintaxis para definir un variadic template es la siguiente:

```C++
template <typename T, typename... Args>
void funcion(T t, Args... args) {
  // ...
}
```

En esta sintaxis, se utiliza "typename" seguido de "..." para indicar que "Args" es una lista de tipos de datos. La función "funcion" acepta un argumento de tipo "T" y una lista variable de argumentos de cualquier tipo "Args".

Para utilizar un variadic template, se pueden utilizar funciones recursivas o funciones variadicas como "va_list" y "va_arg" para acceder a los argumentos de la lista. Por ejemplo:

```C++
 #include <iostream>
#include <cstdarg>

template<typename T>
T sum(T t) {
  return t;
}

template<typename T, typename... Args>
T sum(T t, Args... args) {
  return t + sum(args...);
}

int main() {
  std::cout << sum(1, 2, 3, 4, 5) << std::endl; // Imprime "15"
  std::cout << sum(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl; // Imprime "15"
  return 0;
}
#include <iostream>
#include <cstdarg>

template<typename T>
T sum(T t) {
  return t;
}

template<typename T, typename... Args>
T sum(T t, Args... args) {
  return t + sum(args...);
}

int main() {
  std::cout << sum(1, 2, 3, 4, 5) << std::endl; // Imprime "15"
  std::cout << sum(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl; // Imprime "15"
  return 0;
}
```

En este ejemplo, se define una función "sum" que utiliza un variadic template para sumar cualquier cantidad de argumentos de cualquier tipo. La función "sum" utiliza una implementación recursiva para sumar los argumentos de la lista.

Cuando se llama a la función "sum" con una lista de argumentos, el compilador automáticamente deduce el tipo de datos de la lista de argumentos y llama a la versión adecuada de la función "sum". En este ejemplo, se llaman a dos versiones de la función "sum" con argumentos de tipo entero y flotante, respectivamente.

En resumen, los variadic templates son una característica de C++ que permiten definir templates con un número variable de argumentos de cualquier tipo. Los variadic templates son útiles para definir funciones y clases que pueden aceptar cualquier cantidad de argumentos sin conocer de antemano el tipo de datos de la lista de argumentos.

## <span style='color: yellow;'>decltype </span>

La palabra clave "decltype" en C++ se utiliza para obtener el tipo de una expresión en tiempo de compilación. En otras palabras, "decltype" permite deducir el tipo de una expresión sin necesidad de evaluarla.

La sintaxis básica para utilizar "decltype" es la siguiente:

```C++
  decltype(expression)
```

Donde "expression" es la expresión cuyo tipo se desea deducir. La expresión puede ser una variable, una función, una constante, una expresión aritmética, una llamada a función, etc.

Por ejemplo, si tenemos una función que devuelve un puntero y queremos deducir el tipo del puntero, podemos utilizar "decltype" de la siguiente manera:

```C++
int* foo();
decltype(foo()) ptr = nullptr;
```

En este ejemplo, "decltype(foo())" deduce el tipo de retorno de la función "foo", que es un puntero a entero. Luego, se crea una variable llamada "ptr" de ese tipo y se le asigna el valor "nullptr".

"decltype" es útil para escribir código genérico y para deducir tipos de datos complejos en situaciones donde no es posible deducir el tipo de datos a través de plantillas o mediante el uso de tipos de datos conocidos.

Ejemplo de uso:

```C++
#include <iostream>
#include <vector>

using namespace std;

// Return the sum of two arguments of any type
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

// Return a vector of n elements, initialized with value x
auto make_vector = [] (auto x, size_t n) {
    return vector<decltype(x)>(n, x);
};

int main() {
	cout << "add(2, 3) => " << add(2, 3) << endl;
	cout << R"(add("Hello", 2) => )" << add("Hello", 2) << endl;

	cout << R"(make_vector(2, 3) => )";
	auto vint = make_vector(2, 3);
	for (auto i : vint)
		cout << i << ", ";
	cout << endl;

	cout << R"(make_vector("Hello", 2) => )";
	auto vstr = make_vector("Hello", 2);
	for (auto s : vstr)
		cout << s << ", ";
	cout << endl;
}
```

Explicaremos una seccion del codigo que es la mas interesante:

```C++
 // Return the sum of two arguments of any type
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}
```

"decltype" se utiliza para deducir el tipo de datos del resultado de la expresión "t + u". En este caso, el operador "+" se aplica a los argumentos "t" y "u", por lo que "decltype" deducirá el tipo de datos de la suma de estos dos argumentos.

Luego, la función utiliza "auto" para deducir el tipo de retorno de la función a partir del resultado de la expresión "decltype(t + u)".

En otras palabras, esta función puede ser utilizada para sumar dos argumentos de cualquier tipo, ya que el tipo de datos se deduce automáticamente en tiempo de compilación.

En resumen, "decltype" es una palabra clave de C++ que permite deducir el tipo de una expresión en tiempo de compilación. Se utiliza para escribir código genérico y para deducir tipos de datos complejos en situaciones donde no es posible deducir el tipo de datos a través de plantillas o mediante el uso de tipos de datos conocidos.

# MOVE SEMANTICS

## <span style='color: yellow;'>Introduction </span>

n C++, move semantics es una característica de lenguaje que permite el movimiento eficiente de los recursos de un objeto a otro objeto sin tener que hacer una copia completa de los datos. Esta técnica se basa en el uso de los "rvalue references" (referencias de valor temporal) para identificar los objetos que pueden ser movidos, en lugar de copiados.

Cuando se mueve un objeto, se traslada la propiedad de los recursos que el objeto contiene, como su memoria dinámica, sus recursos de E/S, etc., a otro objeto. En lugar de realizar una copia completa de los datos, el objeto original cede su propiedad de los recursos al objeto de destino, y se deja en un estado "válido pero indefinido". En otras palabras, después de un movimiento, el objeto original puede seguir existiendo, pero no se puede garantizar el estado de sus datos.

## <span style='color: yellow;'>Rvalues and Lvalues </span>

Un `lvalue` (abreviatura de "left value" o "valor de la izquierda") es una expresión a la que se le puede asignar un valor y **_tomar su direccion de memoria_**. Ejemplos comunes de lvalues incluyen variables, elementos de matriz y referencias a objetos.

Por otro lado, un `rvalue` (abreviatura de "right value" o "valor de la derecha") es una expresión que solo puede aparecer en el lado derecho de una asignación o como argumento de una función. Los rvalues son valores temporales que no tienen una dirección de memoria persistente, lo que significa que **_no se pueden asignar a una variable ni tomar su dirección_**. Ejemplos comunes de rvalues incluyen constantes, expresiones aritméticas y valores de retorno de funciones.

```C++
int a = 10;      // 'a' es un lvalue, tiene una dirección de memoria persistente
int b = a + 5;   // 'a' es un lvalue, '5' es un rvalue
int& c = a;      // 'c' es una referencia a un lvalue
int&& d = a + 5; // 'a + 5' es un rvalue y 'd' es una referencia a un rvalue

```

En resumen, lvalues y rvalues son dos tipos diferentes de expresiones en C++ que se utilizan en una asignación o en una llamada a una función. Los lvalues se pueden asignar y tienen una dirección de memoria persistente, mientras que los rvalues son temporales y no se pueden asignar a una variable ni tomar su dirección. **Las rvalue references se utilizan para indicar que una expresión puede ser movida en lugar de copiada**, mejorando el rendimiento en algunas situaciones.

## <span style='color: yellow;'>Lvalues and Rvalues References </span>

En C++, las referencias son una forma de acceder a un objeto sin crear una copia del mismo. Se utilizan para evitar la sobrecarga de memoria y mejorar el rendimiento en muchas situaciones.

Las referencias se dividen en dos tipos: lvalue references y rvalue references.

Una lvalue reference se define usando el operador "&" y se refiere a un objeto que tiene una dirección de memoria persistente, es decir, un lvalue. Una lvalue reference solo se puede inicializar con un lvalue. Por ejemplo:

```C++
int a = 10;
int& ref_a = a; // lvalue reference to 'a'
//En este ejemplo, ref_a es una lvalue reference que se refiere a a.
```

Una rvalue reference se define usando el operador "&&" y se refiere a un objeto que no tiene una dirección de memoria persistente, es decir, un rvalue. Una rvalue reference solo se puede inicializar con un rvalue. Por ejemplo:

```C++
 int&& ref_b = 20; // rvalue reference to '20'
 //En este ejemplo, ref_b es una rvalue reference que se refiere al rvalue 20.
```

**La principal diferencia entre una lvalue reference y una rvalue reference es que una lvalue reference se refiere a un objeto que tiene una dirección de memoria persistente, mientras que una rvalue reference se refiere a un objeto temporal que no tiene una dirección de memoria persistente.**

Por esta razón, `las rvalue references se usan comúnmente para implementar el movimiento semántico`, que permite transferir la propiedad de los recursos de un objeto a otro sin tener que hacer una copia completa de los datos.

```C++
std::string hello = "Hello, world!";       // 'hello' es un lvalue, tiene una dirección de memoria persistente
std::string&& rvalue_ref = std::move(hello); // 'rvalue_ref' es una referencia a un rvalue
std::string copy = hello;                  // 'hello' es un lvalue, 'copy' es una copia de 'hello'
std::string& lvalue_ref = copy;            // 'lvalue_ref' es una referencia a un lvalue
```

## Porque no puedo mover un Lvalue?

Antes de contestar la pregunta hay que definir dos conceptos importantes, memoria persistente e identidad en el programa.

Tener una dirección de **memoria persistente** significa que un objeto tiene una ubicación de memoria asignada durante su ciclo de vida y esa ubicación no cambia. Es decir, el objeto tiene una dirección de memoria que se mantiene constante mientras existe en el programa. Esto permite que el objeto sea referenciado por su dirección de memoria y permite que el objeto sea utilizado en varias partes del programa.

Por otro lado, tener una **identidad en el programa** significa que un objeto es único y puede ser identificado por su ubicación de memoria. Dos objetos distintos que tienen los mismos valores de atributos y métodos no son el mismo objeto en el programa, ya que tienen ubicaciones de memoria diferentes y, por lo tanto, son identidades distintas.

En el contexto del movimiento semántico, mover un objeto implica transferir la propiedad de sus recursos a otro objeto y cambiar su identidad. Sin embargo, si un objeto tiene una dirección de memoria persistente y una identidad en el programa, no es posible moverlo sin cambiar su identidad, lo que puede llevar a comportamientos no deseados.

Un ejemplo de que NO se deberia hacer:

```C++
#include <iostream>
#include <utility>

int main() {
    int x = 5;
    int y = std::move(x); // Error: no se puede mover un lvalue

    std::cout << "x = " << x << '\n'; // Imprime "x = 5"
    std::cout << "y = " << y << '\n'; // Imprime "y = 5"

    return 0;
}
```

En este ejemplo, tratamos de mover el lvalue x a la variable y utilizando std::move. Sin embargo, esto es incorrecto, ya que no se puede mover un lvalue. La variable y simplemente se inicializa con el valor de x, y no hay ninguna transferencia de recursos o cambio de identidad.

Al final del programa, x y y tienen los mismos valores que antes, ya que no se ha realizado ningún movimiento.

## <span style='color: yellow;'>move() </span>

La función std::move() es una función de la librería estándar de C++ que se utiliza para convertir un objeto lvalue en un objeto rvalue, permitiendo su movimiento o transferencia de recursos en lugar de copiarlos. Esta función se utiliza comúnmente en el contexto de mover objetos que tienen recursos costosos, como memoria dinámica, para mejorar la eficiencia del programa.

La función std::move() no realiza en sí misma ninguna transferencia de recursos, sino que simplemente "roba" los recursos de un objeto lvalue y los convierte en un objeto rvalue. Esto se logra mediante la utilización de una referencia rvalue (mediante la declaración de un objeto como && en lugar de &), que indica que el objeto es temporal y que su contenido puede ser transferido a otro objeto.

Por ejemplo, supongamos que tenemos un objeto std::vector<int> que contiene muchos elementos y queremos mover su contenido a otro objeto:

```C++
std::vector<int> vec1 {1, 2, 3, 4, 5};
std::vector<int> vec2 = std::move(vec1);  // Movemos el contenido de vec1 a vec2
```

En este caso, utilizamos std::move() para convertir vec1 en un objeto rvalue y transferir su contenido a vec2. Como resultado, el contenido de vec1 se "mueve" a vec2 sin realizar ninguna copia costosa de los elementos del vector.

Es importante destacar que después de que se utiliza std::move() para mover el contenido de un objeto, el objeto original puede ser "vacío" o tener un estado indefinido. Es responsabilidad del programador asegurarse de que no se utilice el objeto original después de su movimiento, ya que podría generar resultados inesperado

## Una funcion que retorna un entero es un rValue?

Depende de cómo se use la función. Si la función devuelve un valor y ese valor se utiliza inmediatamente en una expresión, entonces ese valor se considera un rvalue.

Por ejemplo, si tienes una función como la siguiente:

```C++
  int sum(int a, int b) {
  return a + b;
}
```

Y luego la usas de esta forma:

```C++
  int x = sum(2, 3);
```

este caso, sum(2, 3) devuelve el valor 5, que se asigna a la variable x. En este contexto, el valor 5 se considera un rvalue.

Sin embargo, si guardas el resultado de la función en una variable y luego usas esa variable en una expresión, esa variable se considera un lvalue.

```C++
int x = sum(2, 3);
int y = x + 1; // x es un lvalue aquí
```

En este caso, x se considera un lvalue porque se refiere a la variable donde se guarda el resultado de la función sum().

## <span style='color: yellow;'>Function Arguments and Move Semantics </span>

La mejor forma de pasar argumentos a funciones depende si el valor a pasar es un Lvalue o un Rvalue.
Si tenemos un Lvalue la mejor forma es pasar por referencia constante:

```C++
  void foo(int& x) {
  // Realiza operaciones con x
}
```

En cambio si tenemos un Rvalue la mejor forma es pasarlo por una referencia universal que se define con la sintaxis &&. La referencia universal permite que la función pueda aceptar tanto lvalues como rvalues, y decide cómo manejarlos en función del contexto.

```C++
void bar(auto&& x) {
  // Realiza operaciones con x
}

int main() {
  int a = 5;
  bar(a);     // Esto no compilará, ya que a es un lvalue
  bar(10);    // Esto funciona, ya que 10 es un rvalue
  return 0;
}
```

## <span style='color: yellow;'>Forwarding References </span>

**reference collapsing** (colapsado de referencias) es un mecanismo que se produce cuando se combinan dos referencias en una sola, dando como resultado una referencia con características específicas.

En C++, una referencia a una referencia se colapsa en una única referencia. Por ejemplo, si tenemos dos referencias, una lvalue y otra rvalue, al combinarlas en una única referencia, el compilador aplicará las reglas de reference collapsing para determinar el tipo resultante.

Las reglas son las siguientes:

- Si se tiene una referencia lvalue & y se combina con cualquier tipo de referencia, la referencia resultante será otra referencia lvalue &.
- Si se tiene una referencia rvalue && y se combina con una referencia lvalue &, la referencia resultante será una referencia lvalue &.
- Si se tiene una referencia rvalue && y se combina con otra referencia rvalue &&, la referencia resultante será una referencia rvalue &&.

Esto se debe a que una referencia lvalue no puede referenciar a una rvalue, por lo que en el segundo caso, la referencia lvalue se considera más restrictiva y se colapsa en una referencia lvalue. Por otro lado, dos referencias rvalue se combinan en una única referencia rvalue, ya que una referencia rvalue puede referenciar tanto a rvalues como a lvalues.

La reference collapsing es importante para entender el comportamiento de las referencias universales (conocidas también como referencias rvalue universales), que utilizan la sintaxis auto&&. Estas referencias universales permiten que un parámetro de función enlace tanto con lvalues como con rvalues y utilizan las reglas de reference collapsing para determinar el tipo resultante.

En el ejemplo anterior vimos el uso de una `Referencia universal`.
La sintaxis && se puede utilizar para cosas diferentes. En en caso de

```C++
  std::string&& rvalue_ref = std::move(hello);
```

"&&" se utiliza para crear una referencia rvalue a un objeto std::string. Aquí, rvalue_ref es una referencia rvalue que se puede usar para mover el objeto hello a otro lugar. La función std::move() se utiliza para convertir un objeto lvalue en un objeto rvalue y hacer posible su movimiento.

En el segundo ejemplo

```C++
void bar(int&& x)
{
    // Realiza operaciones con x
}
```
&& se utiliza para indicar que el parámetro x es una referencia rvalue a un objeto int. Esto significa que la función bar() solo aceptará argumentos rvalue int.

Sin embargo existe una excepcion importante al utilizar `auto&&` (o Templates) para declarar un parametro de funcion, la referencia universal permitirá que el parámetro enlace tanto con lvalues como con rvalues.

Por lo tanto, la declaración void foo(auto&& arg) permite que el parámetro arg enlace tanto con lvalues como con rvalues. Esto se debe a que la sintaxis auto&& deduce el tipo del argumento y crea una referencia universal que puede enlazarse tanto con lvalues como con rvalues.

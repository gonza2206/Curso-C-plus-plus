# Error Handling

Para usar excepciones en C++, debemos seguir los siguientes pasos:

1. Identificar el código que puede generar una excepción.
2. Escribir una función de manejo de excepciones para capturar y manejar las excepciones.
3. Utilizar la palabra clave "throw" para lanzar una excepción en caso de error.

A continuación, se muestra un ejemplo sencillo para entender el uso de excepciones en C++:

```C++
#include <iostream>
using namespace std;

int main() {
   int numerador, denominador, resultado;

   cout << "Ingrese el numerador: ";
   cin >> numerador;
   cout << "Ingrese el denominador: ";
   cin >> denominador;

   try {
      if (denominador == 0) {
         throw "El denominador no puede ser cero.";
      }
      resultado = numerador / denominador;
      cout << "Resultado: " << resultado << endl;
   }
   catch (const char* mensaje) {
      cerr << "Error: " << mensaje << endl;
   }

   return 0;
}
```

En este ejemplo, se pide al usuario que ingrese un numerador y un denominador. Luego, se verifica si el denominador es cero o no. Si el denominador es cero, se lanza una excepción con un mensaje de error. Si el denominador no es cero, se realiza la división y se muestra el resultado.

El bloque "try" es utilizado para envolver el código que puede generar una excepción. Si se lanza una excepción en el bloque "try", la función de manejo de excepciones se ejecutará automáticamente. En este caso, el mensaje de error se muestra por la función "cerr".

Para entender mejor el uso de excepciones en C++, es importante conocer algunos conceptos clave, como:

1. Lanzamiento de excepciones: Para lanzar una excepción, se utiliza la palabra clave "throw". Se puede lanzar cualquier tipo de dato, como una cadena, un número o un objeto.

2. Bloque "try-catch": El bloque "try" es utilizado para envolver el código que puede generar una excepción. Si se lanza una excepción en el bloque "try", la función de manejo de excepciones se ejecutará automáticamente. El bloque "catch" se utiliza para manejar la excepción. Puede haber varios bloques "catch" para manejar diferentes tipos de excepciones.

3. Clases de excepciones: En C++, las excepciones son objetos. Se pueden definir clases de excepciones para manejar diferentes tipos de errores. Por ejemplo, se podría definir una clase de excepción para manejar errores de entrada y otra para manejar errores de salida.

4. Funciones de manejo de excepciones: Las funciones de manejo de excepciones son utilizadas para manejar las excepciones lanzadas por el código en el bloque "try". Estas funciones pueden ser definidas por el usuario o utilizar las funciones de manejo de excepciones predeterminadas.

## <span style='color: yellow;'>Flujo del programa al captar una excepcion <span>

Cuando se produce una excepción en un programa C++, el flujo del programa cambia y se busca un bloque "catch" adecuado para manejar la excepción. El proceso de manejo de excepciones sigue los siguientes pasos:

1. El programa ejecuta el código en el bloque "try".
2. Si se produce una excepción dentro del bloque "try", el programa deja de ejecutar el código dentro del bloque "try" y busca un bloque "catch" correspondiente para manejar la excepción. El proceso de búsqueda comienza con el bloque "catch" más cercano al bloque "try" y continúa buscando en bloques "catch" externos hasta que se encuentra un bloque "catch" adecuado.
3. Si se encuentra un bloque "catch" adecuado, el programa ejecuta el código dentro del bloque "catch" para manejar la excepción. Después de que se maneja la excepción, el programa continúa ejecutando el código después del bloque "try-catch".
4. Si no se encuentra un bloque "catch" adecuado, el programa se detiene y se muestra un mensaje de error.

El bloque "catch" puede especificar el tipo de excepción que está tratando de manejar. Si la excepción lanzada es del mismo tipo que el especificado en el bloque "catch", se ejecutará el código en ese bloque. Si la excepción lanzada no es del mismo tipo que el especificado en el bloque "catch", el programa continuará buscando en bloques "catch" externos.

**Es importante tener en cuenta que el manejo de excepciones puede tener un impacto en el rendimiento del programa, especialmente si se lanzan y manejan muchas excepciones. Por lo tanto, es importante utilizar excepciones de manera cuidadosa y adecuada para evitar la sobrecarga innecesaria del sistema.**

## <span style='color: yellow;'>Tipos de excepciones </span>

C++ proporciona varios tipos de excepciones de forma nativa. Algunos de ellos son:

**std::exception**: es la clase base de todas las excepciones estándar. Contiene una función miembro llamada "what()" que devuelve una cadena con información sobre la excepción.

**std::bad_alloc**: se lanza cuando no se puede asignar memoria dinámica con "new" o "new[]".

**std::bad_cast:** se lanza cuando una conversión "dynamic_cast" falla.

**std::runtime_error**: se utiliza para errores que pueden ocurrir durante la ejecución del programa y que no se pueden prever durante la compilación.

**std::logic_error**: se utiliza para errores que son causados por problemas en la lógica del programa, como una división por cero o un acceso a un índice fuera de rango.

**std::out_of_range**: se lanza cuando se intenta acceder a un índice fuera del rango válido en una colección, como un vector o una cadena.

**std::invalid_argument**: se lanza cuando se pasa un argumento inválido a una función.

**std::length_error**: se lanza cuando una operación sobre una colección supera su capacidad máxima.

**std::overflow_error**: se lanza cuando una operación aritmética resulta en un desbordamiento.

**std::underflow_error**: se lanza cuando una operación aritmética resulta en un subdesbordamiento.

Algunos ejemplos de cómo manejar excepciones específicas en C++:

`Excepción de archivo no encontrado:`


```C++
  try {
  std::ifstream archivo("archivo.txt");
  if (!archivo) {
    throw std::runtime_error("El archivo no se pudo abrir.");
  }
} catch (const std::exception& e) {
  std::cout << "Error al abrir el archivo: " << e.what() << std::endl;
}
```


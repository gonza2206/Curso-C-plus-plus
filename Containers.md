# CONTAINERS

## <span style='color: yellow;'>Standar Library Array </span>

La librería "array" de C++ es una plantilla (template) de la biblioteca estándar de C++ que proporciona una manera segura y eficiente de almacenar y manipular arreglos de elementos del mismo tipo en memoria contigua.

La plantilla "array" se define en el archivo de encabezado "array" y está disponible a partir de C++11. Esta biblioteca proporciona una alternativa moderna y más segura a los arreglos tradicionales de C, ya que ofrece algunas características útiles, como el tamaño constante y la comprobación en tiempo de compilación para garantizar la seguridad de los índices.

Un objeto de "array" tiene un tamaño fijo y se puede acceder a sus elementos mediante el operador de corchetes []. También proporciona una serie de funciones miembro útiles para trabajar con arreglos, como:
"at()", "front()", "back()", "fill()", "swap()" y "size()".

```C++
#include <array>
#include <iostream>

int main() {
  std::array<int, 5> arr = {1, 2, 3, 4, 5};

  std::cout << "El arreglo contiene: ";
  for (auto elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << "\n";

  std::cout << "El tamaño del arreglo es: " << arr.size() << "\n";

  return 0;
}
```

## ¿Cuáles son las principales ventajas de std::array sobre los arreglos incorporados?

• El número de elementos es parte del tipo de std::array  
• Es imposible usar un std::array con el número incorrecto de elementos  
• std::array tiene una función miembro que devuelve el número de elementos  
• std::array nunca se convierte en un puntero  
• std::array es compatible con otros contenedores STL  
• Admite verificación de rango, utilizando la función miembro at()  
• Los std::arrays se pueden asignar si tienen el mismo tipo

## ¿En qué situaciones sería preferible usar un arreglo incorporado en lugar de un std::array o std::vector?

• Si la compatibilidad con el código antiguo es importante.

## Funciones miembro de la Libreria Array

## at()

La función at() se utiliza para acceder a los elementos de un std::array con verificación de rango. Si el índice está fuera del rango válido, la función arroja una excepción std::out_of_range.

```C++
 int main() {
  std::array<int, 3> arr = {1, 2, 3};

  // Accede al primer elemento del arreglo
  std::cout << "El primer elemento del arreglo es: " << arr.at(0) << "\n";

  // Intenta acceder al cuarto elemento, fuera de rango
  try {
    std::cout << "El cuarto elemento del arreglo es: " << arr.at(3) << "\n";
  } catch (const std::out_of_range& e) {
    std::cout << "Error: " << e.what() << "\n";
  }

  return 0;
}
```

## front()

La función front() se utiliza para acceder al primer elemento de un std::array.

```C++
 int main() {
  std::array<int, 3> arr = {1, 2, 3};

  // Accede al primer elemento del arreglo
  std::cout << "El primer elemento del arreglo es: " << arr.front() << "\n";

  return 0;
}
```

## back()

La función back() se utiliza para acceder al último elemento de un std::array.

```C++
 int main() {
  std::array<int, 3> arr = {1, 2, 3};

  // Accede al último elemento del arreglo
  std::cout << "El último elemento del arreglo es: " << arr.back() << "\n";

  return 0;
}
```

## fill()

La función fill() se utiliza para asignar un valor a todos los elementos de un std::array

```C++
 int main() {
  std::array<int, 3> arr = {1, 2, 3};

  // Asigna el valor 0 a todos los elementos del arreglo
  arr.fill(0);

  // Imprime el arreglo modificado
  std::cout << "El arreglo contiene: ";
  for (auto elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << "\n";

  return 0;
}
```

## swap()

La función `swap()` se utiliza para intercambiar el contenido de dos std::array del mismo tipo y tamaño.

```C++
 int main() {
  std::array<int, 3> arr1 = {1, 2, 3};
  std::array<int, 3> arr2 = {4, 5, 6};

  // Intercambia el contenido de los dos arreglos
  arr1.swap(arr2);

  // Imprime los arreglos intercambiados
  std::cout << "El arreglo 1 contiene: ";
  for (auto elem : arr1) {
    std::cout << elem << " ";
  }
  std::cout << "\n";

  std::cout << "El arreglo 2 contiene: ";
  for (auto elem : arr2) {
    std::cout << elem << " ";
    }
    std::cout << "\n";

    return 0;
}
```

## size()

La función `size()` se utiliza para obtener el número de elementos de un `std::array`.

```C++
 int main() {
  std::array<int, 3> arr = {1, 2, 3};

  // Obtiene el número de elementos del arreglo
  std::cout << "El arreglo tiene " << arr.size() << " elementos\n";

  return 0;
}
```

## <span style='color: yellow;'>Forward List</span>

## Estructura de una lista enlazada

Una lista enlazada consiste en una serie de nodos. Cada nodo contiene un solo elemento y un puntero al siguiente nodo.
Cada elemento tiene su propia asignación de memoria, en contraposición a ser almacenado con otros elementos en un bloque de memoria.
En una lista enlazada podemos recorrerla **siempre** de forma secuencial, y podemos añadir un elemento, quitar un elemento.  
Las listas enlazadas no permiten el acceso aleatorio.

Existe una libreria en C++ que posee una implementacion eficiente de listas de una direccion.

```C++
 #include <iostream>
#include <forward_list>

using namespace std;

int main() {
	forward_list<int> l{4, 3, 1};                 // Create a list object

	cout << "Initial elements in list" << endl;
	for (auto el: l)                              // Use a range-for loop to display all the elements
	    cout << el << ", ";
	cout << endl;

	auto second = l.begin();                      //Inicializa el iterador
	advance(second, 1);                           // i is an iterator to the second element
	l.insert_after(second, 2);                    // Insert a new element after the first element

	cout << "Elements in list after inserting 2" << endl;
	for (auto el: l)
	   cout << el << ", ";
	cout << endl;

	l.erase_after(second);                        // Remove this element

	cout << "Elements in list after erasing 2" << endl;
	for (auto node: l)
	   cout << node << ", ";
	cout << endl;
}
```

## <span style='color: yellow;'>List </span>

La biblioteca list de C++ es una de las bibliotecas estándar de plantillas (STL) que proporciona una implementación de una lista doblemente enlazada. La lista es una estructura de datos lineal que almacena una colección de elementos en un orden secuencial. Los elementos se almacenan en nodos que contienen el valor del elemento y los enlaces a los nodos anterior y siguiente.

La libreria estandar de C++ provee dos librerias:

• std::forward_list para listas enlazadas simples  
• std::list para listas doblemente enlazadas

## ¿Cuál es la diferencia principal entre estos dos tipos?

std::forward_list solo tiene un enlace al elemento siguiente. No soporta directamente la iteración hacia atrás.  
std::list tiene un enlace al elemento anterior. Soporta la iteración en cualquier dirección.
En las listas doblemente enlazadas podemos insertar un elemento, removier un elemento y recorrer la lista.
Ejemplo utilizando la libreria "list":

```C++
 #include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> l{4, 3, 1};                       // Create a list object

	cout << "Initial elements in list" << endl;
	for (auto el: l)                            // Use a range-for loop to display all the elements
	    cout << el << ", ";
	cout << endl;

	auto last = end(l);
	advance(last, -1);                          // i is an iterator to the second element
	auto two = l.insert(last, 2);               // Insert a new element before the last element

	cout << "Elements in list after inserting 2" << endl;
	for (auto el: l)
	   cout << el << ", ";
	cout << endl;

	l.erase(two);                               // Remove this element

	cout << "Elements in list after erasing 2" << endl;
	for (auto node: l)
	   cout << node << ", ";
	cout << endl;
}
```

los métodos proporcionados por la biblioteca list de C++:

- begin() y end(): Devuelven iteradores que apuntan al primer y último elemento de la lista, respectivamente.

- size(): Devuelve el número de elementos en la lista.

- empty(): Devuelve verdadero si la lista está vacía.

- push_front(value) y push_back(value): Insertan el elemento especificado al principio o al final de la lista, respectivamente.

- pop_front() y pop_back(): Eliminan el primer o el último elemento de la lista, respectivamente.

- insert(pos, value) e erase(pos): Insertan o eliminan un elemento en una posición dada en la lista.

- remove(value): Elimina todos los elementos de la lista que tienen el valor especificado.

- sort() y reverse(): Ordena la lista y la invierte, respectivamente.

## <span style='color: yellow;'>Comparativa entre las distintas estructuras secuanciales </span>

Vector: Es una estructura de datos contigua que almacena elementos en una matriz de tamaño dinámico. Los elementos son accesibles a través de un índice, lo que significa que se pueden acceder rápidamente a los elementos mediante operaciones de índice. Los vectores son útiles cuando se necesita acceder a los elementos de forma aleatoria o cuando se requiere un acceso rápido a los elementos en una determinada posición. Sin embargo, agregar o eliminar elementos en el medio del vector puede ser costoso ya que se requiere mover los elementos para mantener la contigüidad. Los vectores son útiles cuando se necesita un acceso rápido a los elementos y cuando el número de elementos no cambia frecuentemente.

Array: Es una estructura de datos contigua que almacena elementos en una matriz de tamaño fijo. Los elementos son accesibles a través de un índice, lo que significa que se pueden acceder rápidamente a los elementos mediante operaciones de índice. A diferencia de los vectores, los arreglos tienen un tamaño fijo y no se pueden modificar después de su creación. Los arreglos son útiles cuando se sabe de antemano el número de elementos que se almacenarán y se necesita acceder rápidamente a los elementos mediante operaciones de índice.

Lista enlazada: Es una estructura de datos que almacena elementos en nodos que contienen un valor y un enlace al siguiente nodo. Debido a su estructura de datos enlazada, agregar o eliminar elementos en cualquier posición de la lista es rápido. Además, no se necesita mover los elementos para agregar o eliminar elementos. Sin embargo, el acceso a los elementos se realiza de manera secuencial, lo que significa que no se pueden acceder rápidamente a los elementos mediante operaciones de índice. Las listas enlazadas son útiles cuando se necesita agregar o eliminar elementos con frecuencia en cualquier posición y cuando el acceso a los elementos no se realiza mediante operaciones de índice.

En resumen, los vectores son útiles cuando se necesita un acceso rápido a los elementos y cuando el número de elementos no cambia frecuentemente; los arreglos son útiles cuando se sabe de antemano el número de elementos que se almacenarán y se necesita acceder rápidamente a los elementos mediante operaciones de índice; y las listas enlazadas son útiles cuando se necesita agregar o eliminar elementos con frecuencia en cualquier posición y cuando el acceso a los elementos no se realiza mediante operaciones de índice.

## <span style='color: yellow;'>TREE DATA STRUCTURE </span>

En C++, una estructura de datos de árbol es una colección jerárquica de nodos que están conectados entre sí por medio de enlaces o "ramas". Cada nodo en el árbol tiene un valor o dato asociado y cero o más nodos hijos, que se conectan al nodo padre. El primer nodo del árbol se llama raíz y los nodos sin hijos se llaman hojas.

Hay varios tipos de árboles en C++, pero uno de los más comunes es el árbol binario. Un árbol binario es aquel en el que cada nodo tiene como máximo dos hijos. El árbol binario se puede recorrer en tres maneras diferentes: preorden, postorden y enorden.

Para implementar un árbol en C++, primero se necesita una estructura de nodo, que contenga un valor de dato y punteros a sus nodos hijos. Luego, se puede crear una clase para el árbol que contenga punteros a la raíz del árbol y los métodos para agregar, buscar y eliminar nodos en el árbol.

En un árbol binario, el nodo izquierdo siempre tiene un valor menor que el nodo padre y el nodo derecho siempre tiene un valor mayor que el nodo padre. Por lo tanto, al insertar un nuevo nodo en el árbol, se compara su valor con el valor del nodo actual y se decide si se debe ir a la izquierda o a la derecha.

Si el valor del nuevo nodo es menor que el valor del nodo actual, se debe insertar en el subárbol izquierdo del nodo actual. Si es mayor, se debe insertar en el subárbol derecho. Si el valor es igual al valor del nodo actual, se puede decidir si se inserta a la izquierda o a la derecha (por ejemplo, en algunos casos se puede permitir duplicados y se podrían insertar en ambos lados).

Por ejemplo, si se tiene el siguiente árbol binario:

```C++
       10
     /     \
    5       15
   / \     /  \
  3   8   12   20

```

Se comenzaría en el nodo raíz con valor 10. Como 6 es menor que 10, se debe seguir por el subárbol izquierdo, que comienza con el nodo de valor 5. Como 6 es mayor que 5, se debe seguir por el subárbol derecho del nodo 5, que es el nodo de valor 8. Como 6 es menor que 8, se debe seguir por el subárbol izquierdo del nodo 8, que es un nodo hoja vacío. Entonces, se inserta el nuevo nodo con valor 6 como hijo izquierdo del nodo 8:

```C++
       10
     /     \
    5       15
   / \     /  \
  3   8   12   20
     / \
    6   *


```

En resumen, la decisión de si ir a la izquierda o a la derecha en un árbol binario depende de si el valor del nuevo nodo es mayor o menor que el valor del nodo actual, respectivamente.

## <span style='color: yellow;'>Sets </span>

Un set en C++ es una colección ordenada de elementos únicos. Los elementos en un set se ordenan automáticamente según su valor y los duplicados se eliminan automáticamente. Esto significa que si intentas insertar un elemento que ya existe en el set, no se agregará una segunda vez.

La implementación de set en C++ se basa en una estructura de árbol auto-balanceado, como árboles rojo-negro o AVL. Debido a esto, los elementos se pueden buscar, insertar y eliminar de manera eficiente en un set.

Para crear un set en C++, primero debes incluir la biblioteca de contenedores STL (Standard Template Library) y luego declarar un objeto de set especificando el tipo de datos que contendrá. Por ejemplo:

```C++
#include <set>
set<int> mi_set;
```

Esto crea un set vacío que contendrá elementos de tipo "int". Luego puedes agregar elementos al set utilizando el método "insert":

```C++
mi_set.insert(10);
mi_set.insert(20);
mi_set.insert(30);
```

En este ejemplo, se agregan los valores 10, 20 y 30 al set. Si intentas agregar un valor que ya existe en el set, como por ejemplo insertar 10 nuevamente, no sucederá nada.

Para recorrer los elementos de un set, se puede utilizar un bucle for:

```C++
for (auto it = mi_set.begin(); it != mi_set.end(); ++it) {
cout << \*it << endl;
}
```

En este ejemplo, se utiliza un iterador para recorrer el set desde el principio hasta el final. La variable "it" apunta al primer elemento del set y se va incrementando hasta llegar al último elemento.

Los sets en C++ tienen una gran cantidad de funciones y métodos disponibles para realizar operaciones de búsqueda, inserción y eliminación de elementos, así como para realizar operaciones de conjunto, como unión, intersección y diferencia.

Ejemplo:

```C++
#include <iostream>
#include <set>

using namespace std;

void print(const set<int>& s) {
	cout << "Elements of set: ";

	for (auto el: s)                    // Use a range-for loop to display all the elements
		cout << el << ",";
	cout << endl << endl;
}

int main() {
	set<int> s;                         // Create an empty std::set
	s.insert(6);                        // Add some elements to it
	s.insert(7);                        // The argument to insert() is the key of the element
	s.insert(4);
	s.insert(5);
	s.insert(3);
	print(s);

	auto ret = s.insert(3);
	if (ret.second)
		cout << "Added element with key 3 to set\n";
	else
		cout << "Set already contains element with key " << *(ret.first) << endl;

	print(s);

	cout << "Removing element with key 3\n";

	s.erase(3);
	print(s);

	auto ret2 = s.insert(3);
	if (ret2.second)
		cout << "Added element with key 3 to set\n";
	else
		cout << "Set already contains element with key" << *(ret2.first) << endl;

	print(s);

  cout << "Calling find(7)\n";
	auto it = s.find(7); //Busca un valor en el arbol

	if (it != s.end())
		cout << "The set has an element with key " << *it << endl;
	else
		cout << "The set has no element with key 7\n";

}
```

Este tipo de colecciones son utiles si no se quieren tener duplicados.

## <span style='color: yellow;'>MAP </span>

En C++, un "map" es una estructura de datos que almacena pares clave-valor. Cada elemento del mapa se compone de una clave y un valor asociado con esa clave. La clave es única y se utiliza para buscar y acceder al valor asociado.

Los mapas en C++ se implementan generalmente utilizando árboles de búsqueda binaria auto-balanceados, como árboles rojo-negro o AVL. Debido a esto, los elementos se pueden buscar, insertar y eliminar de manera eficiente en un mapa.

Para crear un mapa en C++, primero debes incluir la biblioteca de contenedores STL (Standard Template Library) y luego declarar un objeto de map especificando el tipo de datos de la clave y el valor. Por ejemplo:

```C++
#include <map>
#include <utility> // incluir para make_pair
map<string, int> mi_mapa;
```

Esto crea un mapa vacío que contendrá pares de elementos con una clave de tipo "string" y un valor de tipo "int". Luego puedes agregar elementos al mapa utilizando el método "insert":

```C++
mi_mapa.insert(make_pair("uno", 1));
mi_mapa.insert(make_pair("dos", 2));
mi_mapa.insert(make_pair("tres", 3));
```

En este ejemplo, se agregan los pares "uno - 1", "dos - 2" y "tres - 3" al mapa.

`make_pair` es una función de la biblioteca estándar de C++ que se utiliza para crear un objeto de tipo std::pair. Un std::pair es una estructura de datos simple que almacena dos valores, llamados "first" y "second".

La función make_pair toma dos argumentos y devuelve un objeto std::pair que contiene esos dos argumentos como su "first" y "second". Por ejemplo, puedes usar la función make_pair para crear un par de valores para insertar en un mapa.

En este ejemplo, se utiliza make_pair para crear un par de valores en cada llamada y luego se insertan en el mapa utilizando el método insert.

La función make_pair es útil cuando se necesita crear pares de valores temporalmente sin tener que declarar un objeto std::pair explícitamente.

Para acceder al valor asociado con una clave en el mapa, se utiliza la sintaxis de corchetes:

```C++
cout << mi_mapa["dos"] << endl;
```

En este ejemplo, se accede al valor asociado con la clave "dos" en el mapa y se imprime por pantalla.

Los mapas en C++ tienen una gran cantidad de funciones y métodos disponibles para realizar operaciones de búsqueda, inserción y eliminación de elementos, así como para realizar operaciones de conjunto, como unión, intersección y diferencia. Además, se pueden utilizar iteradores para recorrer los elementos del mapa en orden.

## Mostrar y buscar datos en un mapa

```C++
 #include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void print(const map<string, int>& scores) {
	cout << "Map elements:" << endl;

	for (auto it: scores)                    // Use a range-for loop to display all the elements
		cout << it.first << " has a score of " << it.second << endl;
	cout << endl;
}

int main() {
	map<string, int> scores;                                              // Create empty std::map
	scores.insert(make_pair("Maybelline", 86));                           // Add some elements to it
	scores.insert( {"Graham", 78} );

	print(scores);

	cout << "Calling find_if()\n";
	auto gra = find_if(begin(scores), end(scores), [](pair<string, int> p) { return p.first == "Graham"s;});

	if (gra != scores.end()) {
		cout << "Found an element with key ";
		cout << gra->first << " which has a score of " << gra->second << endl;
		// cout << "Changing Graham's name to Gra\n";
		// gra->first = "Gra"s;
		cout << "Changing Graham's score to 67\n";
		gra->second = 67;
		print(scores);
	}
	else
		cout << "The map has no element with the key Graham\n";

	cout << "Calling count_if()\n";
	auto n = count_if(cbegin(scores), cend(scores), [](pair<string, int> p) { return p.first == "Graham"s;});

	if (n == 1)
		cout << "The map has 1 element with key \"Graham\"\n";
	else
		cout << "The map has 0 elements with key \"Graham\"\n";
}
```

## Remover o añadir elementos

```C++
 #include <iostream>
#include <map>
#include <string>

using namespace std;

void print(const map<string, int>& scores) {
	cout << "Map elements:" << endl;

	for (auto it: scores)                    // Use a range-for loop to display all the elements
		cout << it.first << " has a score of " << it.second << endl;
	cout << endl;
}

int main() {
	map<string, int> scores;                                              // Create an empty std::map
	scores.insert(make_pair("Maybelline", 86));                           // Add some elements to it
	scores.insert( {"Graham", 78} );

	print(scores);

	cout << "Adding element with key Graham\n";
	auto ret = scores.insert( {"Graham", 66} );
	if (ret.second)
		cout << "Added element with key Graham to map\n";
	else {
		auto it = ret.first;                                            // Iterator to existing element
		cout << "Map already contains an element with key " << it->first;
		cout << " which has value " << it->second << endl;
	}

	print(scores);

	cout << "Removing element with key Graham\n";
	scores.erase("Graham");

	print(scores);

	auto ret2 = scores.insert( {"Graham", 66} );
	if (ret2.second)
		cout << "Added element with key Graham to map\n";
	else {
		auto it = ret2.first;                                            // Iterator to existing element
		cout << "Map already contains an element with key " << it->first;
		cout << " which has value " << it->second << endl;
	}

	print(scores);
}
```

## Cambiar valor de un elemento

```C++
#include <map>
#include <string>
#include <iostream>

using namespace std;

void print(const map<string, int>& scores) {
	cout << "Map elements: " << endl;
	for (auto it : scores)
		cout << it.first << " has a score of " << it.second << endl;
	cout << endl;
}

int main() {
	map<string, int> scores;                                           // Create an instance of std::map
	scores.insert(make_pair("Maybelline", 86));                           // Add some elements to it
	scores.insert( {"Graham", 78} );

	print(scores);

	cout << "Graham has a score of " << scores["Graham"] << endl;      // Fetches the value with key "Graham"
	print(scores);

	cout << "Setting Graham's score to 66" << endl;
	scores["Graham"] = 66;          // Changes the value of the element with key "Graham"
	print(scores);

	cout << "Adding Grace's score of 66" << endl;
	scores["Grace"] = 66;           // Creates a new element with key "Grace"
	print(scores);
}
```

## <span style='color: yellow;'> Multiset and Multimap</span>

En C++, un Multiset y un Multimap son contenedores de la biblioteca estándar que permiten almacenar elementos de forma ordenada, pero permitiendo duplicados.

Un Multiset es una colección ordenada de elementos donde cada elemento puede aparecer más de una vez. Los elementos se almacenan en el contenedor en orden ascendente por defecto, pero se puede personalizar este orden mediante un comparador personalizado.

Por otro lado, un Multimap es un contenedor que permite almacenar elementos de la misma forma que un mapa, pero con claves duplicadas. Es decir, cada elemento está asociado a una clave, pero diferentes elementos pueden tener la misma clave. Los elementos se almacenan en orden de clave por defecto.

```C++
 #include <iostream>
#include <map>

using namespace std;

int main() {
	multimap<string, int> scores;                  // Create an empty std::multimap
	scores.insert( {"Graham"s, 78} );              // Add some elements to it
	scores.insert( {"Grace"s, 66} );
	scores.insert( {"Graham"s, 66} );              // Add duplicate elements
	scores.insert( {"Graham"s, 72} );
	scores.insert( {"Hareesh"s, 77} );

	//scores.erase("Graham");                      // Erase all elements with the key "Graham"

	for (auto s: scores)
		cout << s.first << " has a score of " << s.second << endl;
}
```

Como se ve en el codigo anterior es posible añadir objetos duplicados. Los elementos en un multimapa y en un multiset se ordenan automaticamente. Por lo que todos los keys repetidos se encontraran uno al lado del otro.  
Al borrar un key especifico se borran todos los elementos con el key.

### Como puedo eliminar un solo elemento que tienen el mismo key?

Esto se logra atraves de un iterador. Utilizando find() nos dara como retorno el iterador apuntando al primer elemento encontrado.
Despues con count() obtenemos la cantidad de elementos con el mismo key, y por ultimo iteramos con un bucle for sobre todos los elementos con el mismo key.

```C++
#include <iostream>
#include <map>

using namespace std;

int main() {
	multimap<string, int> scores;                  // Create an empty std::multimap
	scores.insert( {"Graham"s, 78} );              // Add some elements to it
	scores.insert( {"Grace"s, 66} );
	scores.insert( {"Graham"s, 66} );              // Add duplicate elements
	scores.insert( {"Graham"s, 72} );
	scores.insert( {"Hareesh"s, 77} );

	auto res = scores.find("Graham");              // Find first element with key "Graham"

	if (res != end(scores)) {                      // Do we have any results?
		auto n_matches = scores.count("Graham");   // Find number of matching elements

		// Loop over the matching elements
		for (int i = 0; i < n_matches; ++i) {
			 cout << "Key = " << res->first << ", value = " << res->second << endl;
			 ++res;
		}
	}
}
```

## Busqueda por valor de un elemento repetido

```C++
 #include <iostream>
#include <map>

using namespace std;

int main() {
	multimap<string, int> scores;                  // Create an empty std::multimap
	scores.insert( {"Graham"s, 78} );              // Add some elements to it
	scores.insert( {"Grace"s, 66} );
	scores.insert( {"Graham"s, 66} );              // Add duplicate elements
	scores.insert( {"Graham"s, 72} );
	scores.insert( {"Hareesh"s, 77} );

	auto res = scores.find("Graham");              // Find first element with key "Graham"

	if (res != end(scores)) {                     // Do we have any results?
		auto n_matches = scores.count("Graham");   // Find number of matching elements

		// Loop over the matching elements
		for (int i = 0; i < n_matches; ++i) {
			 if (res->second == 66) {
				cout << "Found an element with key Graham and value 66!" << endl;
				break;
			}
			++res;
		}
	}
}
```

## Metodos mas utilizados

1. insert(): Inserta un par clave-valor en el multimap.

2. emplace(): Inserta un elemento en el multimap de forma constructiva, es decir, construye el elemento en el lugar del contenedor.

3. find(): Busca un elemento con una clave específica en el multimap y devuelve un iterador al primer elemento encontrado. Si no se encuentra un elemento con la clave especificada, devuelve un iterador al final del multimap.

4. count(): Devuelve el número de elementos en el multimap con una clave específica.

5. equal_range(): Devuelve un par de iteradores que definen el rango de elementos con una clave específica en el multimap.

6. erase(): Elimina un elemento o un rango de elementos del multimap.

7. clear(): Elimina todos los elementos del multimap.

8. size(): Devuelve el número de elementos en el multimap.

Ejemplo:

```C++
 #include <iostream>
#include <map>

int main() {
  // Creamos un multimap de personas y sus edades
  std::multimap<std::string, int> personas;

  // Insertamos algunos elementos en el multimap
  personas.insert(std::make_pair("Juan", 30));
  personas.insert(std::make_pair("Pedro", 25));
  personas.insert(std::make_pair("Juan", 40));
  personas.insert(std::make_pair("Maria", 30));

  // Utilizamos find() para buscar la edad de Juan
  auto it = personas.find("Juan");
  if (it != personas.end()) {
    std::cout << "La edad de Juan es " << it->second << std::endl;
  } else {
    std::cout << "Juan no se encuentra en el multimap." << std::endl;
  }

  // Utilizamos count() para contar el número de personas de 30 años
  int num_personas_30 = personas.count("Maria");
  std::cout << "Hay " << num_personas_30 << " personas de 30 años en el multimap." << std::endl;

  // Utilizamos equal_range() para encontrar todas las personas con una edad específica
  auto range = personas.equal_range("Juan");
  std::cout << "Personas con el nombre Juan: " << std::endl;
  for (auto it = range.first; it != range.second; ++it) {
    std::cout << "  Edad: " << it->second << std::endl;
  }

  // Utilizamos erase() para eliminar todas las personas con el nombre "Pedro"
  int num_erased = personas.erase("Pedro");
  std::cout << "Se eliminaron " << num_erased << " personas con el nombre Pedro." << std::endl;

  // Imprimimos el tamaño del multimap
  std::cout << "El multimap tiene un tamaño de " << personas.size() << " elementos." << std::endl;

  return 0;
}
```

La función equal_range() se utiliza para encontrar todos los elementos en el multimap que tienen una clave específica, que en este caso es el nombre "Juan".

La función equal_range() devuelve un par de iteradores que define el rango de elementos en el multimap que tienen la clave especificada. El primer iterador del par apunta al primer elemento que tiene la clave "Juan", mientras que el segundo iterador apunta al siguiente elemento después del último elemento que tiene la clave "Juan".

Luego, en el código, se utiliza un bucle for para iterar a través del rango de elementos que se encontraron y se imprime la edad de cada persona en el multimap que tiene el nombre "Juan". En cada iteración, el iterador it apunta a un elemento en el rango que se encontró y se accede al valor de la edad utilizando el método second del iterador, que devuelve el valor asociado a la clave en ese elemento del multimap.

## <span style='color: yellow;'>Como usar Contenedores asociativos con variables propias </span>

Supongamos que tenemos la clase book.

Indice para los libros:

```C++
#ifndef BOOK_INDEX_H
#define BOOK_INDEX_H

#include <string>
#include <iostream>

class book_idx {
	std::string author;
	std::string title;
	public:
	book_idx(const std::string& author, const std::string& title) : author(author), title(title) {}
	bool operator < (const book_idx& other) const {
		// If the author is the same, order by title
		if (author == other.author)
			return title < other.title;

		// Otherwise, order by author
		return author < other.author;
	}
	friend std::ostream& operator <<(std::ostream& os, const book_idx& bkx) {
		os << bkx.author << ", " << bkx.title;
		return os;
	}
};

#endif //BOOK_INDEX_H
```

Funcion principal:

```C++
#include <iostream>
#include <map>
#include "book_index.h"

using namespace std;

// Class with book details
class book {
private:
    string publisher;
	string edition;
	int date;
public:
    book(string publisher, string edition, int date) : publisher(publisher), edition(edition), date(date) {}
    friend ostream& operator << (ostream& os, const book& bk) {
		os << "(" << bk.publisher << ", " << bk.edition << ", " << bk.date << ")";
		return os;
	}
};

int main() {
	multimap<book_idx, book> library;        // Key is a book_idx object, value is a book object

	// Add some books to the library
	book prog_princs("Addison-Wesley", "2nd Edition", 2014);
	book_idx prog_princs_idx{"Stroustrup, Bjarne", "Programming Principles and Practice"};
	library.insert( make_pair(prog_princs_idx, prog_princs) );

	book cpp_primer("Addison-Wesley", "5th Edition", 2013);
	book_idx cpp_primer_idx{"Lippman, Stanley B.", "C++ Primer"};
	library.insert( make_pair(cpp_primer_idx, cpp_primer) );

	book cpp_prog("Addison-Wesley", "4th Edition", 2013);
	book_idx cpp_prog_idx{"Stroustrup, Bjarne", "The C++ Programming Language"};
	library.insert( make_pair(cpp_prog_idx, cpp_prog) );

	book cpp_tour("Addison-Wesley", "1st Edition", 2018);
	book_idx cpp_tour_idx{"Stroustrup, Bjarne", "A Tour of C++"};
	library.insert( make_pair(cpp_tour_idx, cpp_tour) );

	// Print out all the books
	for (auto b: library)
	   cout << b.first << ", " << b.second << endl;
}
```

Si recordamos un mapa ordean sus elementos utilizando el operador <. Por lo que sera necesario crear el operador para la clase que utilizaremos. De esta forma creamos un mapa que alamena varios libros y los ordena por autor en caso de tener varios libros iguales.
En resumen es necesario para utilizar nuestras clases o clases de terceros en mapas, crear el operador < para que pueda ordenar correctamente los elementos.

## <span style='color: yellow;'>Nested Maps </span>

En C++, un nested map (mapa anidado) es una estructura de datos que consiste en un mapa dentro de otro mapa. El primer mapa se utiliza como un índice o clave principal para el segundo mapa, que a su vez puede contener otros valores o datos.

Por ejemplo, podemos crear un nested map para almacenar información de estudiantes, donde la clave principal es el nombre del estudiante y el segundo mapa contiene información como la edad, la dirección y el número de teléfono. Podríamos declarar el nested map de la siguiente manera:

```C++
  std::map<std::string, std::map<std::string, std::string>> student_info;
```

En este caso, el primer std::string se utiliza como clave para el primer mapa y representa el nombre del estudiante. El segundo std::map std::string, std::string es el mapa anidado que contiene la información del estudiante. En este ejemplo, estamos utilizando una std::string como clave en el segundo mapa para representar diferentes tipos de información del estudiante.

Para agregar información de un estudiante al nested map, podemos hacer lo siguiente:

```C++
student_info["Juan"]["edad"] = "22";
student_info["Juan"]["direccion"] = "Av. Independencia 123";
student_info["Juan"]["telefono"] = "555-1234";

```

En este ejemplo, estamos agregando información de un estudiante llamado "Juan" al nested map. Primero utilizamos la clave principal ("Juan") para acceder al segundo mapa, y luego utilizamos diferentes claves (edad, dirección, teléfono) para agregar la información correspondiente.

El nested map es una estructura de datos útil en C++ cuando necesitamos almacenar datos que tienen una estructura compleja y se pueden representar de manera jerárquica. Sin embargo, hay que tener cuidado al trabajar con nested maps, ya que pueden ser menos eficientes que otras estructuras de datos para ciertas operaciones, como la búsqueda de elementos.

Otro ejemplo:

```C++
 #include <iostream>
#include <map>

using namespace std;

using level_map = map<int, string>;

void print(const map<int, level_map>& game_map) {
	cout << "Game map" << endl;
	for (auto level : game_map) {
		cout << "Level " << level.first << " map:" << endl;
		for (auto elem : level.second) {
			cout << elem.first << ", " << elem.second << endl;
		}
	}
	cout << endl;
}

int main() {
	level_map level_one_map = {
		{1, "player"},                                 // Element with key 1
		{10, "door"}                                   // Element with key 10
	};

	level_map level_two_map = {                        // Create another level map
		{5, "player"},
		{10, "monster"}
	};

	// Game map
	map<int, level_map> game_map = {
		{1, level_one_map},                            // Element with key 1, value first level map
		{2, level_two_map}                             // Element with key 10, value second level map
	};

	print(game_map);

	cout << "Inserting a new entity into level 2\n";
	auto level2 = game_map.find(2);                    // Find the level 2 element

	if (level2 != end(game_map)) {
		level2->second.insert({3, "magic wand"});      // Add another object to the level 2 map
	}

	print(game_map);

	cout << "Inserting a new level\n";
	level_map level_three_map = {                      // Create another level map
		{7, "player"},
		{8, "bomb"}
	};

	game_map.insert({3, level_three_map});             // Add the level map to the game map

	print(game_map);

	cout << "Removing element with key 10 from level 2\n";

	auto& lmap = level2->second;
	auto ten = lmap.find(10);
	if (ten != end(lmap))
		lmap.erase(ten);

	print(game_map);
}
```

## <span style='color: yellow;'> Queue FIFO</span>

En C++, una Queue es una estructura de datos que permite almacenar elementos en una cola, siguiendo una política de "primero en entrar, primero en salir" (FIFO, por sus siglas en inglés). Esto significa que el elemento que se inserta primero en la cola es el primero en ser eliminado.

Una Queue sin prioridad en C++ se implementa utilizando la plantilla de clase "queue" que se encuentra en la biblioteca estándar de C++ (STL, por sus siglas en inglés). Esta estructura de datos es una cola simple que no considera ningún criterio de prioridad para los elementos que se agregan. Los elementos se insertan en la cola al final y se eliminan del frente.

Por ejemplo, el siguiente código crea una cola simple y agrega tres elementos a ella:

```C++
  #include <queue>
#include <iostream>
using namespace std;

int main() {
  queue<int> myQueue;
  myQueue.push(10);
  myQueue.push(20);
  myQueue.push(30);

  while (!myQueue.empty()) {
    cout << myQueue.front() << " ";
    myQueue.pop();
  }
  return 0;
}
```

La salida de este programa será: 10 20 30.

## Queue con prioridad

Una Queue con prioridad en C++ se implementa utilizando la plantilla de clase "priority_queue". Esta estructura de datos es una cola en la que los elementos se ordenan de acuerdo a una prioridad específica. Los elementos con mayor prioridad se ubican al frente de la cola y se eliminan primero. El orden de prioridad se determina utilizando una función de comparación que se pasa como un parámetro al crear la cola.

Por ejemplo, el siguiente código crea una cola con prioridad que ordena los elementos de mayor a menor:

```C++
 #include <queue>
#include <iostream>
using namespace std;

int main() {
  priority_queue<int> myQueue;
  myQueue.push(10);
  myQueue.push(20);
  myQueue.push(30);

  while (!myQueue.empty()) {
    cout << myQueue.top() << " ";
    myQueue.pop();
  }
  return 0;
}
```

La salida de este programa será: 30 20 10. En este caso, los elementos se ordenan de mayor a menor prioridad de acuerdo al operador de comparación predeterminado.

### ¿como sabe el programa que elemento es mas prioritario?

En una Queue con prioridad en C++, el programa determina la prioridad de los elementos utilizando una función de comparación que se especifica al crear la cola con prioridad. La función de comparación compara dos elementos y devuelve un valor booleano que indica si el primer elemento es considerado de mayor prioridad que el segundo.

Por defecto, si no se especifica ninguna función de comparación al crear la cola con prioridad, se utiliza el operador mayor que (>) para comparar los elementos y ordenarlos de mayor a menor prioridad. Sin embargo, se puede definir una función de comparación personalizada para ordenar los elementos de acuerdo a cualquier criterio específico.

Por ejemplo, si se desea crear una cola con prioridad de strings en la que los elementos se ordenen alfabéticamente de forma ascendente, se puede crear una función de comparación personalizada que compare los strings utilizando el operador menor que (<), de la siguiente manera:

```C++
  #include <queue>
#include <iostream>
using namespace std;

bool myComparison(string a, string b) {
  return a > b;
}

int main() {
  priority_queue<string, vector<string>, decltype(&myComparison)> myQueue(&myComparison);
  myQueue.push("alpha");
  myQueue.push("delta");
  myQueue.push("gamma");

  while (!myQueue.empty()) {
    cout << myQueue.top() << " ";
    myQueue.pop();
  }
  return 0;
}
```

La salida de este programa será: alpha delta gamma. En este caso, se ha definido una función de comparación personalizada "myComparison" que compara los strings utilizando el operador menor que (<). Luego, se crea la cola con prioridad utilizando esta función de comparación mediante el parámetro "decltype(&myComparison)". De esta manera, los elementos se ordenan alfabéticamente de forma ascendente.

## decltype

`decltype(&myComparison)` es un tipo de datos que se utiliza para especificar el tipo de la función de comparación personalizada que se utilizará en la cola con prioridad.

En C++, el operador decltype se utiliza para determinar el tipo de una expresión. En este caso, se está utilizando decltype para determinar el tipo de la función de comparación &myComparison, es decir, un puntero a una función que devuelve un valor booleano.

Al crear una cola con prioridad en C++, es necesario especificar tres tipos de datos: el tipo de los elementos que se almacenarán en la cola, el tipo de contenedor subyacente utilizado para almacenar los elementos y el tipo de la función de comparación que se utilizará para determinar la prioridad de los elementos. En este caso, la función de comparación es un puntero a la función myComparison.

Al utilizar decltype(&myComparison) se está especificando el tipo de la función de comparación que se utilizará para determinar la prioridad de los elementos en la cola con prioridad. En resumen, decltype(&myComparison) es una forma de especificar el tipo de la función de comparación personalizada que se utilizará en la cola con prioridad.

## <span style='color: yellow;'>Stack </span>

En C++, un stack es una estructura de datos que representa una pila, es decir, una colección de elementos organizados en una estructura de tipo LIFO (last in, first out), donde el último elemento que se inserta en la pila es el primer elemento en salir.

La implementación de stack en C++ se basa en un contenedor subyacente que se utiliza para almacenar los elementos de la pila. Por defecto, el contenedor subyacente utilizado por la clase stack es deque (double-ended queue), pero también se puede utilizar list o vector.

La clase stack en C++ proporciona varios métodos para trabajar con la pila, como push, pop, top, empty, size, entre otros. A continuación se describen algunos de estos métodos:

push(elemento): Agrega un elemento al tope de la pila.
pop(): Elimina el elemento del tope de la pila.
top(): Devuelve una referencia al elemento del tope de la pila.
empty(): Devuelve true si la pila está vacía, false en caso contrario.
size(): Devuelve la cantidad de elementos en la pila.
A continuación se muestra un ejemplo de cómo utilizar la clase stack en C++:

```C++
  #include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> pila;

  pila.push(1);
  pila.push(2);
  pila.push(3);

  while (!pila.empty()) {
    cout << pila.top() << " ";
    pila.pop();
  }

  return 0;
}
```

En este ejemplo, se crea una pila stack de enteros llamada pila, a la que se agregan tres elementos utilizando el método push. Luego, se recorre la pila utilizando un bucle while y se imprime cada elemento utilizando el método top, que devuelve el elemento del tope de la pila, y el método pop, que elimina el elemento del tope de la pila. La salida de este programa sería: 3 2 1, ya que los elementos se imprimen en orden inverso al que fueron insertados en la pila debido a la estructura de tipo LIFO.

## <span style='color: yellow;'>emplace </span>

En C++, la función emplace (o emplace_back en el caso de vector y emplace_front en el caso de deque) se utiliza para construir y agregar un objeto directamente en un contenedor, en lugar de crear un objeto aparte y luego agregarlo al contenedor. Esto se conoce como emplazamiento (en inglés, emplacement).

La función emplace toma como argumentos los parámetros necesarios para construir el objeto, en lugar de tomar el objeto ya construido. Estos argumentos se utilizan para crear un objeto directamente en el contenedor utilizando el constructor apropiado. Esta función es útil cuando se necesita construir objetos directamente dentro de un contenedor, lo que puede mejorar el rendimiento y reducir el uso de memoria, ya que se evita la creación de objetos temporales.

Por ejemplo, si se tiene un vector de objetos de tipo Persona, se podría agregar un nuevo objeto utilizando la función push_back de la siguiente manera:

```C++
vector<Persona> personas;
Persona p("Juan", 25);
personas.push_back(p);
```

Sin embargo, utilizando la función emplace_back, se podría agregar el objeto directamente al vector sin la necesidad de crear un objeto temporal p:

```C++
vector<Persona> personas;
personas.emplace_back("Juan", 25);
```

En este caso, se utilizan los parámetros "Juan" y 25 para construir un nuevo objeto Persona directamente dentro del vector.

En resumen, la función emplace se utiliza para construir y agregar un objeto directamente a un contenedor en C++, ***evitando la necesidad de crear un objeto temporal y mejorando el rendimiento y el uso de memoria.***

### ¿Cuando NO conviene usar emplace? 
1. Cuando se agregan pocos elementos: Si se agregan pocos elementos a un contenedor, no hay mucho beneficio en utilizar emplace. En cambio, es más sencillo y legible utilizar el constructor del objeto y luego agregarlo al contenedor utilizando push_back o push_front.

2. Cuando se tienen objetos ya construidos: Si se tienen objetos ya construidos que se quieren agregar al contenedor, no se puede utilizar emplace. En este caso, hay que utilizar la función push_back o push_front.

3. Cuando se necesita agregar elementos en una posición específica: La función emplace siempre agrega elementos al final del contenedor. Si se necesita agregar elementos en una posición específica, se debe utilizar una función como insert.

4. Cuando se utilizan tipos de datos simples: La función emplace está diseñada para construir objetos complejos. Para tipos de datos simples como enteros, flotantes, caracteres, etc., no hay mucho beneficio en utilizar emplace, ya que los constructores son simples y los objetos se crean rápidamente.

## <span style='color: yellow;'>Hash Maps </span>

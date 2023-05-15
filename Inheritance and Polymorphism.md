# INHERITANCE AND POLIMORPHISM

La herencia es un concepto fundamental de la programación orientada a objetos que permite crear nuevas clases basadas en clases existentes. En C++, la herencia se define mediante la palabra clave "class" o "struct", seguida por el nombre de la nueva clase derivada y el nombre de la clase base de la que se hereda.
Ejemplo

```C++
#include <iostream>

using namespace std;

class Vehicle {
	int max_speed;
	public:
    Vehicle(int max_speed) :  max_speed(max_speed) {       // Initialize max_speed
		cout << "Vehicle constructor\n";
	}
    // ...  Member Functions
};

class Aeroplane : public Vehicle {
	int max_height;
	public:
    // Initialize the Vehicle part of the instance, then initialize max_height
    Aeroplane(int max_speed, int max_height) : Vehicle(max_speed), max_height(max_height) {
				cout << "Aeroplane constructor\n";
	}
    // ...  Member Functions
};

int main() {
	cout << "Creating Vehicle object\n";
	Vehicle vehicle(10);
	cout << "Creating Aeroplane object\n";
	Aeroplane plane(40000, 500);
}
```

Cuando una clase es hija de otra se crea primero la clase base seguida de la clase hija.
En memoria la clase padre esta primero y se asignan unos bits extra para la clase hijo.

## <span style='color: yellow;'> Member Functions and Inheritance </span>

Cuando hablamos de heredar funciones miembro nos referimos a que una clase hijo automaticamente hereda todas las funciones `publicas` de su padre. Estas funciones son llamadas como si se hubieran definido en la clase padre.

```C++
 class Vehicle {
public:
    void start() { cout << "Engine started "; }
};
class Aeroplane : public Vehicle {
    public:
    /// void start(); Inherited from Vehicle ///
};

int main() {
	Aeroplane plane;
	plane.start();    // Calls start() on an Aeroplane object. Prints out "Engine started: "
	cout << "\n";
}
```

Podemos definir una seccion protected en la clase. Todos los metodos declarados dentro de esta seccion unicamente podran ser llamados por el padre y sus hijos.

```C++
 class Vehicle {
protected:
    void kids_only();                              // Can only be called by this class  and its children

};
class Aeroplane : public Vehicle {
public:
    void do_something() { kids_only(); }           // Child can call protected member function
};

int main() {
	Vehicle vehicle;
	//vehicle.kids_only();                           // Cannot be called by "outsider" code
}
```

Como se menciono antes, los metodos de la clase padre estan disponible para la clase hijo. Por ejemplo:

```C++
 class Vehicle {
public:
    void start() { cout << "Engine started: "; }
};
class Aeroplane : public Vehicle {
    public:
    void start() {
        cout << "Carrying out checks... ";
		Vehicle::start();              // Call base class member function
        cout << "Ready for take-off!";
    }
};

int main() {
	Aeroplane plane;
	plane.start();    // Calls start() on an Aeroplane object. Prints out "Engine started: "
	cout << "\n";
}
```

## <span style='color: yellow;'>Overloading Member Functions </span>

Podemos sobrecargar una función miembro que se hereda de la clase padre. En la clase hija, escribimos una función que tiene el mismo nombre pero una firma diferente.

```C++
 class Vehicle {
public:
    void accelerate() { cout << "Increasing speed: "; }
};
class Aeroplane : public Vehicle {
    public:
	void accelerate() {  Vehicle:: accelerate();  }            // Call parent version of accelerate()
    void accelerate(int height) {
        cout << "Accelerating at a height of: " << height;
    }
};

int main() {
	Aeroplane plane;
	plane.accelerate(1000);
	cout << endl;
	plane.accelerate();
	cout << endl;
}
```

En el ejemplo anterior vemos como declarando dos metodos con el mismo nombre al ser llamados con los argumentos corresponfientes en el main el compilador tomara la desicion de que funcion ejecutar.

### Hidden Member Functions

En C++, una "hidden member function" (función miembro oculta) se refiere a una función miembro en una clase base que ha sido redefinida en una clase derivada con el mismo nombre y firma, lo que hace que la versión de la función de la clase base quede oculta.

Cuando una función miembro se redefine en una clase derivada, se crea una nueva función con el mismo nombre y firma que la función de la clase base. Esto significa que la función de la clase base ya no es accesible en la clase derivada a menos que se realice una operación explícita para acceder a ella.

```C++
 class Vehicle {
public:
    void accelerate() { cout << "Increasing speed: "; }
};
class Aeroplane : public Vehicle {
    public:
    void accelerate(int height) {
        cout << "Accelerating at a height of: " << height;
    }
};

int main() {
	Aeroplane plane;
	plane.accelerate(1000);
	cout << endl;
	plane.accelerate();             // Does not compile - no matching function
}
```

Una forma que se tiene de poder acceder a las funciones miembro del padre y del hijo es utilizando la palabra clave `using`.

```C++
 class Vehicle {
public:
    void accelerate() { cout << "Increasing speed: "; }
};
class Aeroplane : public Vehicle {
    public:
	using Vehicle::accelerate;
    void accelerate(int height) {
        cout << "Accelerating at a height of: " << height;
    }
};

int main() {
	Aeroplane plane;
	plane.accelerate(1000);
	cout << endl;
	plane.accelerate();
	cout << endl;
}
```

La línea `using Vehicle::accelerate` en la clase "Aeroplane" está utilizando la herencia de nombre para hacer que la función "accelerate()" de la clase base "Vehicle" sea accesible en la clase derivada "Aeroplane". Esto significa que la función "accelerate()" de la clase base puede ser invocada a través de un objeto de la clase derivada.

## <span style='color: yellow;'>Pointers, References and Inheritance </span>

El siguiente codigo presenta un error:

```C++
class Shape {};

class Circle : public Shape {};

int main() {
	Circle circle;                                   // Derived class object
	Shape* pshape = &circle;                         // Pointer to base class, points to a Circle object

	Shape shape;                                     // Base class object
	Circle* pcircle = &shape;                        // Error!
}
```

Esto se debe a que un objeto Circle siempre contiene un objeto Shape, pero un objeto Shape no necesariamente forma parte de un objeto Circle.
Si recordamos un objeto posee una posicion de memoria, al asignar una clase hijo al objeto se creara en una nueva posicion de memoria La clase padre + clase hijo.

[Clase padre Clase Hijo]

por lo tento si apuntamos con un puntero el puntero tiene que apuntar al mismo tipo de dato con el que fue definido. En este caso un puntero `Shape` debe apuntar a un tipo de dato `Shape`.
Como la clase padre siempre esta en la cabezera de la seccion de memoria del hijo el puntero SIEMPRE debe ser de la clase padre y este apuntar a la direccion de memoria de la clase hijo.

->ClasePadre + ClaseHijo.

```C++
class Shape {};

class Circle : public Shape {};

int main() {
	Circle circle;               // Derived class object
	Shape& sref = circle;        // Binds reference to base class, to a Circle object
	Shape shape;
	Circle& cref = shape;        // Error!
}
```

Se crea una referencia a la clase base Shape llamada sref, que se enlaza al objeto circle. Debido a que Circle es una clase derivada de Shape, sref se puede utilizar para acceder a los miembros heredados de la clase Shape que se encuentran en circle.

Se intenta crear una referencia a la clase derivada Circle llamada cref y enlazarla al objeto shape. Esto dará lugar a un error de compilación porque shape es una instancia de la clase base Shape y no contiene los miembros específicos de la clase derivada Circle.

Al declarar las clases mediante referencia podemos acceder a los metodos de esta. Aqui un ejemplo:

```C++

class Shape {
	public:
	void draw() { cout << "Drawing a generic shape...\n"; }
};

class Circle : public Shape {
	public:
	void draw() { cout << "Drawing a circle...\n"; }
	void area() { cout << "Calculating area of circle...\n"; }
};

int main() {
	Circle circle;                                   // Derived class object
	Shape* pshape = &circle;                         // Pointer to base class, points to a Circle object

	pshape->draw();                                  // Calls Shape's version of draw()
	//pshape->area();                                  // Error!
}
```

Creamos un clase Shape la cual es una clase hija de Circle.
creamos un puntero pshape el cual apuntara a la direccion de memoria de la clase circle, previamente declarada.
Si recordamos el puntero pshape esta apuntando a la clase padre, por lo que tiene acceso a las funciones miembro de la clase padre. Por lo que el codigo anterior mostrara el resultado de draw() de la clase padre.

## Casting to an object

```C++
 class Shape {
public:
	void draw() { cout << "Drawing a generic shape...\n"; }
};

class Circle: public Shape {
public:
	void draw() { cout << "Drawing a circle...\n"; }
};

int main() {
	vector<Shape *> shapes;      // Vector of pointers to Shape instances

	// Create a pointer to a child class of Shape and append it to the vector
	shapes.push_back(new Circle);

	for (auto s: shapes)
		static_cast<Circle *>(s)->draw();              // Calls Shape::draw()

	for (auto s : shapes)       // Release allocated memory
		delete s;
}
```

## <span style='color: yellow;'>Static and dynamic Type </span>

En C++, cada objeto tiene dos tipos: el tipo estático (o tipo declarado) y el tipo dinámico (o tipo actual).

El tipo estático de un objeto se establece en tiempo de compilación y se determina por el tipo de la variable que se utiliza para declarar el objeto. Por ejemplo, si tienes una clase Circle que hereda de una clase Shape, y creas un objeto Circle y lo declaras como tipo Shape, entonces el tipo estático del objeto es Shape.

El tipo dinámico de un objeto se establece en tiempo de ejecución y se determina por el tipo real del objeto que se está utilizando. Si el objeto Circle anterior se creó como un objeto Circle y luego se convirtió en un objeto Shape, entonces el tipo dinámico sigue siendo Circle.

La diferencia entre el tipo estático y el tipo dinámico es importante porque afecta a cómo se accede a los miembros de la clase. Cuando usas un puntero o una referencia a la clase base para acceder a un objeto de la clase derivada, solo tienes acceso a los miembros de la clase base. Si necesitas acceder a los miembros de la clase derivada, debes hacer una conversión de tipo explícita para convertir el puntero o la referencia a la clase derivada correspondiente.

Ejemplo de statyc type:

```C++
 int x{5};		// statyc type int
 int* p_x = &x; //puntero estatico a entero
 Circle circle;
 Circle *p_circle = &circle; //Static type Circle
 Cicle& pcircle = circle;	//Static reference to Circle
```

En general el tipo dinamico depende de la variable que esta en memoria. Que en general va a ser del mismo tipo de la declaracion.

Ejemplo de dynamic type:

```C++
 int x{5};		// dynamic type int
 int* p_x = &x; //dynamic type int pointer
 Circle circle;
 Circle *p_circle = &circle; //Static type Circle
 Cicle& pcircle = circle;	//Static reference to Circle
```

Para la mayoria de los objetos siempre el tipo dinamico va a ser del mismo tipo de la declaracion. Sin embargo este puede ser distinto en el caso de un puntero apuntando a una clase hija.

`C++ casi siempre usa static Type. El tipo dinamico es solamente usado para punteros o referencia a una clase base.`

Para usar dynamic type, tenemos que declarar a las funciones miembro como `virtual` en la clase base

```C++
 class Shape{
	public:
		virtual void draw(); // Declare Shape::draw() as virtual
 };

 Shape* p_shape = new Circle();
 pshape->draw();	//Resuelve en tiempo de ejecucion - llama a Circle::draw()
```

Al declarar una funcion como virtual. El compilador decidira de que tipo de objeto se trata y llamara a la funcion miembro del objeto.

```C++
 Shape *p_shape = &circle; //dynamic type pointer to Circle
 Shape &p_shape = circle;//dynamic type reference to Circle
```

```C++
#include <iostream>
#include <vector>

using namespace std;

class Shape {
	public:
	virtual void draw() { cout << "Drawing a generic shape...\n"; }
};

class Circle : public Shape {
	public:
	void draw() { cout << "Drawing a circle...\n"; }
};

int main() {
	vector<Shape *> shapes;      // Vector of pointers to Shape objects

	// Create a pointer to a child class of Shape and append it to the vector
	shapes.push_back(new Circle());

	for (auto shape: shapes)
		shape->draw();              // Calls Circle::draw()

	for (auto shape : shapes)       // Release allocated memory
		delete shape;
}
```

En resumen, el tipo estático se establece en tiempo de compilación y se determina por el tipo de la variable utilizada para declarar el objeto, mientras que el tipo dinámico se establece en tiempo de ejecución y se determina por el tipo real del objeto que se está utilizando. La diferencia es importante porque afecta a cómo se accede a los miembros de la clase y cómo se realizan las conversiones de tipo.

## <span style='color: yellow;'>Virtual Funcions </span>

## Static Binding

El "static binding" es la llamada a una función o método se resuelve en tiempo de compilación en función del tipo declarado de la variable que realiza la llamada.

En C++, esto se puede ver en las funciones no virtuales y en las funciones que no están marcadas como virtuales en una clase. En este caso, la llamada se realiza al método correspondiente de la clase de la variable declarada en tiempo de compilación. Por ejemplo:

```C++
class Animal {
public:
    void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        std::cout << "The dog barks." << std::endl;
    }
};

int main() {
    Animal animal;
    Dog dog;

    animal.makeSound(); // llama a Animal::makeSound()
    dog.makeSound(); // llama a Dog::makeSound()

    Animal& animalRef = dog;
    animalRef.makeSound(); // llama a Animal::makeSound() porque la variable es de tipo Animal&

    return 0;
}
```

En este ejemplo, la función "makeSound" de la clase Animal es llamada en tiempo de compilación para el objeto "animal", y la función "makeSound" de la clase Dog es llamada en tiempo de compilación para el objeto "dog". La llamada a "makeSound" para la variable "animalRef" también se resuelve en tiempo de compilación, llamando a la función "makeSound" de la clase Animal, porque la variable es de tipo Animal&.

En resumen, el "static binding" se refiere a la resolución de las llamadas a funciones en tiempo de compilación basándose en el tipo de la variable que realiza la llamada

## Dynamic Binding

El "dynamic binding" es la llamada a una función o método se resuelve en tiempo de ejecución en función del tipo real del objeto al que se está llamando.

En C++, esto se puede lograr con el uso de funciones virtuales. Cuando una función es declarada como virtual en una clase base y es sobrescrita por una clase derivada, la llamada a esta función se resuelve en tiempo de ejecución en función del tipo real del objeto al que se está llamando, no en función del tipo declarado de la variable que realiza la llamada. Por ejemplo:

```C++
  class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }
};

int main() {
    Animal* animalPtr;
    Dog dog;

    animalPtr = &dog;
    animalPtr->makeSound(); // llama a Dog::makeSound() en tiempo de ejecución

    return 0;
}
```

### ¿Cuáles son las dos condiciones que deben cumplirse para que ocurra el enlace dinámico?

• Se llama a una función miembro en un puntero o referencia a una clase base.  
• La función miembro fue declarada como virtual en la clase base.

### Entonces definiendo correctamente que es una funcion virtual:

En C++, una función virtual es una función miembro de una clase que se puede sobrescribir en una clase derivada. La sobrescritura de funciones virtuales permite que una clase base tenga una función virtual que puede ser implementada de manera diferente en cada una de sus clases derivadas.
Para declarar una función virtual en C++, se utiliza la palabra clave "virtual" antes del tipo de retorno de la función. Por ejemplo:

```C++
class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "The cat meows." << std::endl;
    }
};
```

En este ejemplo, la clase Animal tiene una función virtual llamada "makeSound". Las clases Dog y Cat heredan de la clase Animal y sobrescriben la función "makeSound" para que se comporte de manera diferente en cada una de ellas.

La palabra clave "override" significa que una función miembro vuelve a implementar una función miembro virtual.  
• El compilador verificará si esta función miembro sobrescribe una función miembro virtual en la clase base.  
• Si no lo hace, se producirá un error de compilación.

El uso de funciones virtuales permite que las funciones de una clase base se comporten de manera diferente en cada una de sus clases derivadas, lo que puede ser muy útil para implementar el polimorfismo en C++.

Cabe destacar que al crear una override estamos escondiendo los metodos de la clase padre para los hijos. Por lo que si queremos llamar a la clase padre debermos hacerlo mediante

`ClasePadre :: MetodoClasePadre();`

Un problema que se puede llegar a tener es cuando queres hacer un override a una funcion que esta sobrecargando un metodo (es decir le agrega nuevos parametros). Por lo que hay que tener cuidado a la hora de declarar una funcion como override. Esta realmente tiene que llamarse igual y tener los mismos parametros. Ejemplo:

```C++
#include <iostream>

using namespace std;

class Shape {
public:
	virtual void draw() const { cout << "Drawing a generic shape...\n"; }
};

class Circle : public Shape {
public:
	void draw() const override { cout << "Drawing a circle...\n"; }    // OK - overrides Shape::draw()
	//void draw(int radius) const override;  // Error! Does not override, this OVERLOAD
};

int main() {
	Circle circle;
	circle.draw();
}
```

## Final keyword

En C++, la palabra clave "final" se utiliza para evitar la sobrescritura de una función virtual por parte de una clase derivada. Cuando una función virtual es declarada como "final" en una clase base, esta función no puede ser sobrescrita por ninguna clase derivada.

```C++
class Animal {
public:
    virtual void makeSound() final {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    // Esto generará un error de compilación porque Animal::makeSound() está declarado como final
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }
};
```

La palabra clave "final" también se puede utilizar en la definición de una clase para indicar que esta clase no puede ser heredada por ninguna otra clase. Por ejemplo:

```C++
class Animal final {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};

// Esto generará un error de compilación porque Animal está declarado como final y no puede ser heredado
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }
};
```

En este caso, la clase Animal es declarada como final, lo que significa que no puede ser heredada por ninguna otra clase. La definición de la clase Dog intenta heredar de Animal, lo que generará un error de compilación debido a que la clase base está declarada como final.

En resumen, en C++, la palabra clave "final" se utiliza para evitar la sobrescritura de una función virtual por parte de una clase derivada, o para indicar que una clase no puede ser heredada por ninguna otra clase.

## <span style='color: yellow;'>Virtual destructor </span>

En C++, un destructor virtual es un destructor declarado como "virtual" en una clase base que será heredado por una o más clases derivadas. La declaración de un destructor virtual permite que las clases derivadas se destruyan adecuadamente cuando se elimina un objeto a través de un puntero a la clase base.

Cuando se elimina un objeto mediante un puntero a la clase base, el comportamiento predeterminado del compilador es llamar al destructor de la clase base solamente.

Si la clase base no tiene un destructor virtual y las clases derivadas tienen recursos propios que necesitan ser liberados al destruir el objeto, estos recursos pueden no ser liberados correctamente, lo que puede provocar fugas de memoria o comportamiento indefinido.
Por ejemplo:

```C++
class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound." << std::endl;
    }

    // Destructor virtual
    virtual ~Animal() {
        std::cout << "Animal destructor called." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks." << std::endl;
    }

    ~Dog() {
        std::cout << "Dog destructor called." << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound();
    delete animal; // llama al destructor virtual de la clase base
    return 0;
}
```

## <span style='color: yellow;'>Pure Virtual Functions </span>

En C++, una función virtual pura es una función virtual que no tiene definición en la clase base y se define completamente en las clases derivadas. La sintaxis para declarar una función virtual pura es agregar el sufijo "= 0" a la declaración de la función en la clase base.

Por ejemplo, consideremos la siguiente clase base "Shape":

```C++
class Shape {
public:
    virtual double area() const = 0;
};
```

En este caso, la función "area" es una función virtual pura porque no tiene una definición en la clase base "Shape" y se espera que se defina completamente en las clases derivadas. Como resultado, la clase "Shape" se convierte en una clase abstracta, lo que significa que no se puede crear un objeto directamente de esta clase.

Para definir una clase derivada que hereda de la clase base "Shape" y define completamente la función virtual pura "area", podemos hacer lo siguiente:

```C++
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
private:
    double width, height;
};
```

En este ejemplo, la clase "Rectangle" es una clase derivada que hereda de la clase base "Shape" y define completamente la función virtual pura "area". La función "area" en la clase "Rectangle" calcula el área del rectángulo y devuelve el resultado.

Cuando tenemos una clase con una funcion virtual no podemos instanciarla. Esto se conoce como
`abstract class`.  
Si o si tendremos que hacer un override de todas las funciones puras que posea la clase abstracta.

Las funciones virtuales puras se utilizan comúnmente en C++ para crear clases abstractas, que son clases que no se pueden instanciar directamente, sino que solo se pueden utilizar como clases base para otras clases. Las funciones virtuales puras también se utilizan para definir interfaces, que son conjuntos de funciones virtuales puras que se implementan en clases derivadas para proporcionar un conjunto común de funciones para una aplicación o sistema.

## Objetc Slincing

El object slicing ocurre cuando se pasa un objeto de una clase derivada a una función que toma la clase base por valor  
• El constructor de copia de la clase base se utilizará para crear el objeto para el cuerpo de la función
• Dentro del cuerpo de la función, la parte de la clase derivada del objeto parece haber sido "cortada"
Por ejemplo: 
```C++  
 #include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
public:
    virtual void draw() const { cout << "Shape::draw()\n"; }       // Empty virtual function
};

class Circle : public Shape {
public:
    void draw() const override { cout << "Drawing a Circle...\n"; }
};

// Function taking base class by value
void draw_shape(Shape s) {
	s.draw();                                  // Always calls Shape's draw()
}

int main() {
	Circle circle;
	draw_shape(circle);                       // Pass derived class object by value as a Shape
	//En este caso es como si le estuviera pasando la clase base. Ya que se "corta" la parte de la clase hija. 
} 
```

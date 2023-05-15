# Smart Pointers

Un "Smart Pointer" (puntero inteligente) es un objeto que se utiliza en programación para administrar automáticamente la memoria asignada a un objeto en C++. En C++, el programador es responsable de administrar la memoria manualmente, lo que puede resultar en errores y problemas de rendimiento si no se manejan adecuadamente. Los punteros inteligentes ayudan a reducir el riesgo de errores de memoria y mejoran la eficiencia del código.

Hay varios tipos de punteros inteligentes en C++, los más comunes son:

`unique_ptr`: este puntero inteligente permite que solo un objeto tenga la propiedad de un recurso de memoria en un momento dado. El recurso de memoria se libera automáticamente cuando se elimina el objeto.

`shared_ptr`: este puntero inteligente permite que varios objetos tengan la propiedad de un recurso de memoria al mismo tiempo. El recurso de memoria se libera automáticamente cuando todos los objetos que comparten la propiedad han sido eliminados.

`weak_ptr`: este puntero inteligente es similar al shared_ptr, pero no tiene la propiedad de la memoria asignada, solo es capaz de observar si la memoria sigue existiendo o no.

Para utilizar punteros inteligentes en C++, debes incluir la biblioteca "memory" y usar la sintaxis adecuada para crear y utilizar los objetos. Por ejemplo, para crear un unique_ptr, se puede usar la siguiente sintaxis:

```C++
#include <memory>
std::unique_ptr<MyClass> myPointer = std::make_unique<MyClass>();
```

Esto creará un puntero inteligente "myPointer" que administra automáticamente la memoria asignada a un objeto de la clase "MyClass". Una vez que el objeto ya no es necesario, el puntero inteligente lo liberará automáticamente.

Es importante recordar que los punteros inteligentes no son una solución mágica para todos los problemas de memoria en C++, pero son una herramienta valiosa que puede ayudar a reducir la complejidad y mejorar la eficiencia del código.

## <span style='color: yellow;'>Unique Pointer</span>

Es un puntero inteligente "exclusivo", lo que significa que solo un objeto unique_ptr puede poseer la propiedad de un recurso de memoria en un momento dado.
Cuando se crea un objeto unique_ptr, se debe especificar el tipo de objeto al que apuntará el puntero. La sintaxis básica para crear un unique_ptr es la siguiente:

```C++
#include <memory>
std::unique_ptr<MyClass> myPointer(new MyClass);
```

En este ejemplo, se crea un objeto unique_ptr llamado myPointer que apunta a un objeto MyClass recién creado en la memoria dinámica. La memoria se liberará automáticamente cuando myPointer se destruya, lo que ocurre cuando su alcance finaliza o cuando se asigna a otro objeto unique_ptr.

Una forma más segura y recomendada de crear un objeto unique_ptr es utilizando la función std::make_unique, que es más eficiente y reduce la posibilidad de errores:

```C++
std::unique_ptr<MyClass> myPointer = std::make_unique<MyClass>();
```

La función std::make_unique crea un objeto MyClass en la memoria dinámica y devuelve un objeto unique_ptr que posee la propiedad de la memoria. De esta forma, se evita la necesidad de utilizar el operador new y se mejora la seguridad y eficiencia del código.

Es importante tener en cuenta que los objetos unique_ptr no se pueden copiar, solo se pueden mover. Esto significa que el objeto unique_ptr original pierde la propiedad de la memoria cuando se asigna a otro objeto unique_ptr, lo que ayuda a evitar errores de memoria. Además, los objetos unique_ptr se pueden utilizar en contenedores STL como std::vector y std::map.

Ejemplo con estructuras:

```C++
#include <iostream>
#include <memory>

using namespace std;

// Data structure representing a point on the screen
struct Point {
    int x;
    int y;
};

int main() {
	// Create a unique_ptr to an point which has initial value {3,6}
	auto p{ make_unique<Point>( Point{3, 6} ) };
	//unique_ptr<Point> p{ new Point{3, 6} };           // C++11

	cout << p->x << ", " << p->y << endl;
}
```

## <span style='color: yellow;'>Unique Pointers and Polymorphism </span>

Los unique pointers pueden utilizarse en combinación con polimorfismo para administrar la memoria de objetos polimórficos de manera segura y eficiente.

En C++, el polimorfismo se logra mediante el uso de clases base abstractas y clases derivadas concretas que implementan la funcionalidad específica. Un ejemplo de esto sería una clase base abstracta Shape con funciones virtuales puras para calcular el área y el perímetro, y clases derivadas concretas como Circle, Rectangle, etc.

Cuando se utiliza polimorfismo, los objetos se crean en la memoria dinámica y se acceden a través de punteros a la clase base abstracta. Para administrar la memoria de estos objetos de manera segura, se puede utilizar un unique pointer que se encarga de liberar automáticamente la memoria cuando ya no se necesita.

La forma más común de usar unique pointers con objetos polimórficos es crear un unique pointer que apunta a la clase base abstracta y asignarle la dirección de un objeto derivado concreto mediante un operador de conversión de puntero. Por ejemplo:

```C++
  #include <memory>

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Circle : public Shape {
public:
    double area() const override {
        // calcular el área del círculo
    }
    double perimeter() const override {
        // calcular el perímetro del círculo
    }
};

int main() {
    std::unique_ptr<Shape> myShape = std::make_unique<Circle>();
    // hacer algo con myShape
    return 0;
}
```

En este ejemplo, se crea un objeto unique pointer myShape que apunta a un objeto Circle en la memoria dinámica. Como Circle es una clase derivada de Shape, se utiliza el operador de conversión de puntero para asignar la dirección del objeto Circle a myShape.

Cuando el objeto myShape sale del alcance, automáticamente libera la memoria que se asignó para el objeto Circle. Esto garantiza que la memoria se libera de manera segura y eficiente y se evita cualquier problema potencial de fuga de memoria.

En resumen, los unique pointers pueden ser una herramienta valiosa para administrar la memoria de objetos polimórficos de manera segura y eficiente en C++. Al utilizar un unique pointer para apuntar a la clase base abstracta y asignarle la dirección de un objeto derivado concreto, se puede garantizar que la memoria se libera automáticamente cuando ya no se necesita.

Para una mejor compresion se ilustra como se haria de la manera habitual:

```C++
 #include <iostream>

using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const { cout << "Drawing a Circle...\n"; }
};

class Triangle : public Shape {
public:
    void draw() const { cout << "Drawing a Triangle...\n"; }
};

class Square : public Shape {
public:
    void draw() const { cout << "Drawing a Square...\n"; }
};

// Factory function
Shape* create_shape(int sides) {
	// The returned pointer will be copied into the function's return space
    if (sides == 1)
		return new Circle;                         // Create 1-sided shape
	else if (sides == 3)
		return new Triangle;                       // Create 3-sided shape
    else if (sides == 4)
		return new Square;                         // Create 4-sided shape
	else {
		cout << "Cannot create a shape with " << sides << " sides\n";
		return nullptr;
	}
}

int main() {
	// The returned pointer will be copied into a variable in the caller
	Shape *pshape = create_shape(3);

	if (pshape)
		pshape->draw();

	delete pshape;                                   // Memory leak if the pointer is not deleted
}
```

Ahora utlizando unique_pointer

```C++
  #include <iostream>
#include <memory>

using namespace std;

class Shape {
public:
	virtual void draw() const = 0;
	virtual ~Shape() = default;
};

class Circle: public Shape {
public:
	void draw() const { cout << "Drawing a Circle...\n"; }
};

class Triangle: public Shape {
public:
	void draw() const { cout << "Drawing a Triangle...\n"; }
};

class Square: public Shape {
public:
	void draw() const { cout << "Drawing a Square...\n"; }
};

// Factory function
unique_ptr<Shape> create_shape(int sides) {
	// The returned unique_ptr will be moved into the function's return space
	if (sides == 1)
		return make_unique<Circle>();               // Create 1-sided shape
	else if (sides == 3)
		return make_unique<Triangle>();             // Create 3-sided shape
	else if (sides == 4)
		return make_unique<Square>();               // Create 4-sided shape
	else {
		cout << "Cannot create a shape with " << sides << " sides\n";
		return nullptr;
	}
}

int main() {
	// The returned unique_ptr will be moved into a variable in the caller
	auto pshape{create_shape(3)};

	if (pshape)
		pshape->draw();
	// Memory allocation is automatically released at end of scope
}
```

En los dos ejemplos anteriores se utilizo una funcion para crear y devolver objetos esta funcion se denomina Factory Pattern.

Una factory function (función de fábrica) es una función que se utiliza para crear y devolver objetos de una clase específica. Es una forma común de implementar el patrón de diseño creacional de fábrica, que se utiliza para encapsular la creación de objetos y permitir la flexibilidad en la selección de la clase concreta.

Otro ejemplo de uso:

```C++
  class Animal {
public:
    virtual void makeSound() = 0;
    static Animal* createAnimal(const std::string& animalType);
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

Animal* Animal::createAnimal(const std::string& animalType) {
    if (animalType == "Dog") {
        return new Dog();
    }
    else if (animalType == "Cat") {
        return new Cat();
    }
    else {
        return nullptr;
    }
}

int main() {
    Animal* myDog = Animal::createAnimal("Dog");
    Animal* myCat = Animal::createAnimal("Cat");

    myDog->makeSound(); // salida: "Woof!"
    myCat->makeSound(); // salida: "Meow!"

    delete myDog;
    delete myCat;

    return 0;
}
```

## <span style='color: yellow;'>PLMPL idiom </span>

## <span style='color: yellow;'> shared_ptr</span>

## <span style='color: yellow;'>weak_ptr </span>

Falta terminar esta seccion bien si es que se usa en sistemas embebidos. 

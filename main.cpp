#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Incluye la librería necesaria para rand() y srand()
#include <vector>
#include "excercise.h"
#include <algorithm>
class Test
{
private:
    int x;

public:
    Test(int objX);
    ~Test();
    void getData();
};

Test::Test(int objX) : x(objX) // esta forma de asignar valores es aun mejor, Ya que lo hace en la construccion del objeto.
// Sino crea la variable vacia y despues la asigna. Gastando recursos.
{
    // x = objX;
    // this->x = objX; es otra forma de poner lo que esta arriba
}

void Test::getData()
{
    std::cout << "valor de x del objeto: " << x << std::endl;
}

Test::~Test()
{
    std::cout << "Destruyendo al objeto..." << std::endl;
}

struct Persona
{
    std::string nombre;
    std::string apellido;
    uint8_t edad = 26;
} Persona1, *p_Persona1 = &Persona1;

void devolverEstructura(uint8_t edad, std::string apellido, std::string nombre)
{
    p_Persona1->apellido = apellido;
    p_Persona1->edad = edad;
    p_Persona1->nombre = nombre;
}

uint8_t valorPorReferencia(uint8_t &num)
{
    num = 5;
    return num;
}

void imprimirVector(char (&vector)[4])
{
    char *p_vector = vector;

    for (uint8_t i = 0; i < 4; i++)
    {
        std::cout << *p_vector << std::endl;
        p_vector++;
    }
}

void llenarArray(uint8_t *p_vector, uint8_t tamano)
{
    for (uint8_t i = 0; i < tamano; i++)
    {
        p_vector[i] = rand() % 10;
    }
}

uint8_t *crearArray(uint8_t tamano)
{
    uint8_t *p_vector = new uint8_t[tamano];
    llenarArray(p_vector, tamano);
    return p_vector;
}

void leerVector(const uint8_t *array, uint8_t tamano) // NO USAR REFERENCIAS A PUNTEROS, NO TIENE SENTIDO. Un puntero ya es una dirección de memoria que apunta a un valor específico. Al pasar un puntero por referencia, esencialmente estás pasando la dirección de memoria que ya apunta a una ubicación de memoria específica. Por lo tanto, no hay una razón clara para pasar un puntero por referencia en lugar de simplemente pasar el puntero en sí mismo.
{

    std::cout << "Tamano del array: " << static_cast<int>(tamano) << std::endl;
    for (uint8_t i = 0; i < tamano; i++)
    {
        std::cout << static_cast<int>(array[i]) << " ";
    }
    delete[] array;
    std::cout << std::endl;
}

using namespace std;
namespace mynamespace
{
    int x = 10;
}

void funcion(const std::vector<int> &vector, void (*func_ptr)(const std::vector<int> &))
{
    func_ptr(vector);
}

void mostrar(const std::vector<int> &vector)
{
    for (auto &element : vector)
    {
        std::cout << element << std::endl;
    }
}

bool esUnDiez(const int8_t &x)
{
    bool status;
    x == 10 ? status = true : status = false;
    return status;
}

void testfunction(bool (*funcionX)(const int8_t &valor))
{
    int x = 10;
    bool retorno = funcionX(x);
    if (retorno)
    {
        std::cout << "Es un diez" << std::endl;
    }
    else
    {
        std::cout << "no es un diez" << std::endl;
    }
}

void test2(uint8_t *x)
{
    std::cout << "Memory position: " << (void *)x << " Valor del puntero: " << (int)*x << std::endl;
}

int main()
{
    std::vector<int> prueba{1, 2, 3, 4, 5};
    funcion(prueba, &mostrar);
    int value = 3;
    int *pointer = &value;
    testfunction(&esUnDiez);

    uint8_t numero = 1;
    uint8_t *puntero1;
    puntero1 = &numero;
    test2(puntero1);
    double num;
    using Int = uint8_t; // es lo mismo decir Int que uint8_t

    std::cout << static_cast<void *>(&numero) << std::endl; // Al agregar static_cast<void*>, estamos diciéndole al compilador que interprete la dirección de memoria como un puntero a void, que no tiene ningún tipo de datos asociado, lo que evita cualquier intento del compilador de interpretar la dirección de memoria como una cadena de caracteres.
    std::cout << static_cast<void *>(puntero1) << std::endl;

    valorPorReferencia(numero); // paso la referencia del numero, osea que me modifica directamente el numero real.
    std::cout << static_cast<int>(numero) << std::endl;

    devolverEstructura(12, "lopez", "gonzalo");
    std::cout << p_Persona1->nombre << std::endl;
    std::cout << p_Persona1->apellido << std::endl;
    std::cout << static_cast<int>(p_Persona1->edad) << std::endl; // La consola espera char o const char

    char saludo[4] = {'h', 'o', 'l', 'a'};
    imprimirVector(saludo);

    srand(time(0)); // Inicializa la semilla del generador de números aleatorios
    // Genera un número aleatorio entre 0 y 99

    int tamano = rand() % 10;
    uint8_t *array = crearArray(tamano);

    leerVector(array, tamano);
    delete[] array;

    Int numeros{10}; // esta linea es lo mismo que decir uint8_t numero = 10;
    cout << "numeros: " << static_cast<int>(numeros) << std::endl;
    {
        // Al estar el objeto dentro de un scope vacio en el momento que salga se destruira.
        Test test(3);
        test.getData();
    }
    cout << "Fuera del scope..." << std::endl;

    string names[] = {
        "Fred", "Wilma", "Pebbles", "Dino", "Barney", "Betty", "Bamm-Bamm", "Hoppy"};

    cout << "names[1][2] = " << names[1 * 4 + 2] << std::endl;

    cout << "\nThe elements of names are:\n";
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            cout << names[row * 4 + col] << ", ";
        }
        cout << "\n";
    }

    vector<int> vector1{1, 2, 3, 4, 5};
    // definimos automaticamente a it como un iterador que va a ir aumentando de uno en uno

    for (auto it = begin(vector1); it < end(vector1); it++)
    {
        cout << *it << ",";
    }
    cout << std::endl;

    for (auto i = rbegin(vector1); i < rend(vector1); i++)
    {
        cout << *i << std::endl;
    }

    for (auto it = cbegin(vector1); it < cend(vector1); it++)
    {
        if (*it % 2 == 0)
        {
            vector1.erase(it);
        }
    }

    for (auto el : vector1)
    {
        std::cout << el;
    }
    std::cout << std::endl;
    auto mid = begin(vector1); // defino mid como un iterador,
    advance(mid, 2);
    std::cout << *mid << std::endl;
    string str{"hola"};
    int x = 3;                                // si bien declaro la variable x aca
    std::cout << mynamespace::x << std::endl; // aca muestro la variable x del namespace "mynamespace"

    vector<int> pruebaDeVector{1, 2, 3, 4, 5, 6};

    std::cout << "Puntero al comienzo del vector:  " << *pruebaDeVector.data() << "\nTamano del vector: " << pruebaDeVector.size() << std::endl;

    std::string sentence{"To be, or not to be, that is the question:"};
    std::cout << "Ejercicio: " << exercise::exclaim(sentence) << std::endl;
    struct datos
    {
        int dato = 10;
        bool esta = false;
    };
    datos variable1;
    datos *p_datos = &variable1;
    std::cout << " dato: " << p_datos->dato << std::endl;

    int x2 = 5;
    int y2 = std::move(x2); // Error: no se puede mover un lvalue


    return 0;
}

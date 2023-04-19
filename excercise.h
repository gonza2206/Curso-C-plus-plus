#ifndef EXERCISE_H
#define EXERCISE_H
#include <iostream>
#include <stdlib.h>
#include <cstdlib> // Incluye la librería necesaria para rand() y srand()
#include <vector>
namespace exercise
{
    std::string exclaim(std::string myString)
    {
        for (auto &element : myString)
        {
            if (ispunct(element))
            {
                element = '!';
            }
        }
        return (myString);
    }
}

#endif // _EXERCISE_H
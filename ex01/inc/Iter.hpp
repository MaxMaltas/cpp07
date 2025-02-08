#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T array[], size_t sizeArray, void function(T&))
{
    if (!array || !function)
    {
        std::cout << "Some error ocurred, check array or function" << std::endl;
        return;
    }
    for (size_t i = 0; i < sizeArray; i++)
    {
        function(array[i]);
    }
}

#endif
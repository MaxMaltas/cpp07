#include "Array.hpp"

#include <iostream>
#include <cstdlib>

#define MAX_VAL 750

int main()
{
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }
    {
        try {
            Array<int> arr(5);
            
            for (size_t i = 0; i < arr.size(); i++) {
                arr[i] = (i * 10);
            }

            std::cout << "\n\nContent Array: \n";
            for (size_t i = 0; i < arr.size(); i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;

            // COPY CONSTRUCTOR
            Array<int> copy(arr);
            std::cout << "\nCopied Array: \n";
            for (size_t i = 0; i < copy.size(); i++) {
                std::cout << copy[i] << " ";
            }
            std::cout << std::endl;

            // ASIGMENT CONSTRUCTOR
            Array<int> assigned;
            assigned = copy;
            std::cout << "\nAssigned Array: \n";
            for (size_t i = 0; i < assigned.size(); i++) {
                std::cout << assigned[i] << " ";
            }
            std::cout << std::endl;

            // CHECK OF BAD INDEX
            std::cout << "\nTrying acces with bad index ex. 10" << std::endl;
            std::cout << arr[10] << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }   
    }
    return 0;
}
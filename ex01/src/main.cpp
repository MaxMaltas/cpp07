#include "Iter.hpp"

void imprimir(int &x)
{
    std::cout << x << " ";
}

void sumOne(int &x)
{
    std::cout << ++x << " ";
}

int main()
{
    
    int intArr[] = {1, 2, 3, 4, 5, 6};
    int charArr[] = {'a', 'b', 'c', 'd'};
    // int *arr = NULL;
    
    size_t sizeIntArr = sizeof(intArr) / sizeof(intArr[0]);
    size_t sizeCharArr = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << sizeIntArr << std::endl;
    std::cout << sizeCharArr << std::endl;
    
    std::cout << "Print Array..." << std::endl;
    iter(intArr, sizeIntArr, imprimir);
    
    std::cout << "\nSum one..." << std::endl;
    iter(intArr, sizeIntArr, sumOne);
    
    std::cout << "\n\nPrint Array..." << std::endl;
    iter(charArr, sizeCharArr, imprimir);
    
    std::cout << "\nSum one..." << std::endl;
    iter(charArr, sizeCharArr, sumOne);

    return (0);
}

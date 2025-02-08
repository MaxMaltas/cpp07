#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T      *_array;
        size_t _size;
    
    public:
        Array() : _array(NULL), _size(0) {};
        
        Array(unsigned int n) : _size(n)
        {
            _array = new T[_size];
        };
        
        Array(const Array &other)
        {
            _size = other._size;
            _array = new T[_size];
            for (size_t i = 0; i < _size; i++)
                _array[i] = other._array[i];
        };

        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                _size = other._size;
                delete[] _array;
                _array = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        };

        T &operator[](size_t index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        };

        ~Array()
        {
            delete[] _array;
        };

        size_t size()
        {
            return _size;
        };

};

#endif
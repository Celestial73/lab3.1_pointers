#pragma once
#include "../pointers/SmartPtr.h"
#include <stdexcept>
#include <iostream>

namespace ds
{
    template <typename T>
    class SmartArray
    {
    private:
        SmartPtr<T> data; // Smart pointer to the first element of the array
        size_t size;      // Size of the array

    public:
        // Constructor
        SmartArray(size_t size) : size(size)
        {
            data.reset(new T[size]); // Allocate memory for the array
        }

        // Access an element of the array
        T &operator[](size_t index)
        {
            return data.get()[index];
        }

        // Get the size of the array
        size_t getSize() const
        {
            return size;
        }

        // Method to add an element to the end of the array (expansion)
        void append(const T &element)
        {
            SmartPtr<T> newData(new T[size + 1]); // Create a new array with one additional element
            for (size_t i = 0; i < size; ++i)
            {
                newData.get()[i] = data.get()[i]; // Copy old elements
            }
            newData.get()[size] = element; // Add the new element
            size++;                        // Increase the size
            data = std::move(newData);     // Use move to transfer ownership
        }

        // Method to print the elements of the array
        void print() const
        {
            for (size_t i = 0; i < size; ++i)
            {
                std::cout << data.get()[i] << " ";
            }
            std::cout << std::endl;
        }
    };
}
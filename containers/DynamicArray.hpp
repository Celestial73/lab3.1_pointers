#pragma once
#include <iostream>

namespace ds
{
    template <class T>
    class DynamicArray
    {
    private:
        T *elements = nullptr;
        int size;

    public:
        // Constructs the array with elements from an existing array of items
        DynamicArray(T *items, int itemCount)
        {
            this->elements = new T[itemCount];
            this->size = itemCount;
            for (int i = 0; i < itemCount; i++)
            {
                this->elements[i] = items[i];
            }
        }

        // Default constructor creates an empty array
        DynamicArray()
        {
            this->elements = nullptr;
            this->size = 0;
        }

        // Constructs an array with a specified size
        DynamicArray(int newSize)
        {
            this->size = newSize;
            this->elements = new T[newSize];
        }

        // Copy constructor for creating a copy of another DynamicArray
        DynamicArray(DynamicArray<T> &otherArray)
        {
            this->size = otherArray.size;
            this->elements = new T[this->size];
            for (int i = 0; i < this->size; i++)
            {
                this->elements[i] = otherArray.elements[i];
            }
        }

        // Returns the element at the specified index
        T get(int index)
        {
            if (index < 0 || index >= size)
                throw std::out_of_range("index");
            return elements[index];
        }

        // Returns the size of the array
        int getSize()
        {
            return this->size;
        }

        // Sets the element at the specified index to a new value
        void set(int index, T value)
        {
            if (index < 0 || index >= size)
            {
                throw std::out_of_range("index");
            }
            this->elements[index] = value;
        }

        // Resizes the array to a new size
        void resize(int newSize)
        {
            if (newSize < 0)
            {
                throw std::out_of_range("newSize");
            }
            if (newSize == 0)
            {
                this->size = 0;
                this->elements = nullptr;
                return;
            }
            this->elements = (T *)realloc(this->elements, newSize * sizeof(T));
            this->size = newSize;
        }
    };
}
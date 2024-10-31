#pragma once
#include "DynamicArray.hpp"
#include "Sequence.h"
#include "../pointers/SharedPtr.h"
#include <iostream>

// ds - Data Structures
namespace ds
{

    template <class T>
    class ArraySequence : public Sequence<T>
    {
    private:
        SharedPtr<DynamicArray<T>> dataArray;

    public:
        ArraySequence(T *items, int count)
        {
            this->dataArray = SharedPtr<DynamicArray<T>>(new DynamicArray<T>(items, count));
        }

        ArraySequence()
        {
            this->dataArray = SharedPtr<DynamicArray<T>>(new DynamicArray<T>());
        }

        ArraySequence(int size)
        {
            this->dataArray = SharedPtr<DynamicArray<T>>(new DynamicArray<T>(size));
        }

        ArraySequence(const ArraySequence<T> &array)
        {
            this->dataArray = array.dataArray;
        }

        // Returns the first element in the sequence
        T getFirst()
        {
            return this->dataArray->get(0);
        }

        // Returns the last element in the sequence
        T getLast()
        {
            return this->dataArray->get(this->dataArray->getSize() - 1);
        }

        // Returns the element at the specified index
        T get(int index)
        {
            return this->dataArray->get(index);
        }

        // Returns a subsequence from startIndex to endIndex
        ArraySequence<T> *getSubsequence(int startIndex, int endIndex)
        {
            if (this->dataArray->getSize() <= 0 || startIndex < 0 || startIndex >= this->dataArray->getSize() ||
                endIndex < 0 || endIndex >= this->dataArray->getSize() || endIndex <= startIndex)
            {
                throw std::out_of_range("Incorrect index.");
            }
            else
            {
                auto subsequence = new ArraySequence<T>((endIndex - startIndex) + 1);
                int subIndex = 0;
                for (int i = startIndex; i <= endIndex; ++i)
                {
                    T element = this->dataArray->get(i);
                    subsequence->dataArray->set(subIndex++, element);
                }
                return subsequence;
            }
        }

        // Returns the length of the sequence
        int getLength()
        {
            return this->dataArray->getSize();
        }

        // Adds an element to the end of the sequence
        void append(T item)
        {
            this->dataArray->resize(this->dataArray->getSize() + 1);
            this->dataArray->set(this->dataArray->getSize() - 1, item);
        }

        // Adds an element to the start of the sequence
        void prepend(T item)
        {
            this->dataArray->resize(this->dataArray->getSize() + 1);
            for (int i = this->dataArray->getSize() - 1; i > 0; --i)
            {
                T element = this->dataArray->get(i - 1);
                this->dataArray->set(i, element);
            }
            this->dataArray->set(0, item);
        }

        // Inserts an element at the specified index
        void insertAt(T item, int index)
        {
            this->dataArray->resize(this->dataArray->getSize() + 1);
            for (int i = this->dataArray->getSize() - 1; i > index; --i)
            {
                T element = this->dataArray->get(i - 1);
                this->dataArray->set(i, element);
            }
            this->dataArray->set(index, item);
        }

        // Concatenates this sequence with another ArraySequence
        Sequence<T> *concat(ArraySequence<T> *list)
        {
            auto concatenatedSequence = new ArraySequence<T>(this->dataArray->getSize() + list->dataArray->getSize());
            int concatIndex = 0;

            for (int i = 0; i < this->dataArray->getSize(); ++i)
            {
                concatenatedSequence->dataArray->set(concatIndex++, this->dataArray->get(i));
            }
            for (int i = 0; i < list->dataArray->getSize(); ++i)
            {
                concatenatedSequence->dataArray->set(concatIndex++, list->dataArray->get(i));
            }

            return concatenatedSequence;
        }

        // Prints all elements in the sequence
        void print()
        {
            for (int i = 0; i < this->dataArray->getSize(); ++i)
            {
                std::cout << this->dataArray->get(i) << " ";
            }
            std::cout << std::endl;
        }
    };

}
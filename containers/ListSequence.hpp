#pragma once
#include <iostream>
#include "LinkedList.hpp"
#include "Sequence.h"
#include "../pointers/UniquePtr.h" // Include UniquePtr for memory management
namespace ds
{
    template <class T>
    class ListSequence : public Sequence<T>
    {
    private:
        UniquePtr<LinkedList<T>> listData; // UniquePtr to manage LinkedList

    public:
        // Constructor with array of items
        ListSequence(T *items, int count)
        {
            this->listData = UniquePtr<LinkedList<T>>(new LinkedList<T>(items, count));
        }

        // Default constructor
        ListSequence()
        {
            this->listData = UniquePtr<LinkedList<T>>(new LinkedList<T>());
        }

        // Move constructor
        ListSequence(ListSequence<T> &&list) noexcept
        {
            this->listData = std::move(list.listData); // Transfer ownership of pointer
        }

        // Move assignment operator
        ListSequence<T> &operator=(ListSequence<T> &&list) noexcept
        {
            if (this != &list)
            {
                this->listData = std::move(list.listData); // Transfer ownership
            }
            return *this;
        }

        // Get the first element
        T getFirst()
        {
            return this->listData->getFirst();
        }

        // Get the last element
        T getLast()
        {
            return this->listData->getLast();
        }

        // Get an element by index
        T get(int index)
        {
            return this->listData->get(index);
        }

        // Get a subsequence as a new ListSequence
        ListSequence<T> *getSubsequence(int startIndex, int endIndex)
        {
            UniquePtr<LinkedList<T>> sublist = UniquePtr<LinkedList<T>>(this->listData->getSubList(startIndex, endIndex));
            ListSequence<T> *newSequence = new ListSequence<T>();
            newSequence->listData = std::move(sublist); // Transfer ownership of pointer
            return newSequence;
        }

        // Get the length of the sequence
        int getLength()
        {
            return this->listData->getLength();
        }

        // Append an item to the end of the sequence
        void append(T item)
        {
            this->listData->append(item);
        }

        // Prepend an item to the beginning of the sequence
        void prepend(T item)
        {
            this->listData->prepend(item);
        }

        // Insert an item at a specified index
        void insertAt(T item, int index)
        {
            this->listData->insertAt(item, index);
        }

        // Concatenate two sequences
        Sequence<T> *concat(ListSequence<T> *list)
        {
            LinkedList<T> *combinedList = this->listData->concat(list->listData.get()); // Access raw pointer with get()

            UniquePtr<LinkedList<T>> uniqueCombinedList(combinedList);

            ListSequence<T> *result = new ListSequence<T>();
            result->listData = std::move(uniqueCombinedList); // Transfer ownership
            return result;
        }

        // Print elements of the sequence
        void print()
        {
            for (int i = 0; i < this->listData->getLength(); ++i)
            {
                std::cout << this->listData->get(i) << " ";
            }
            std::cout << std::endl;
        }
    };
}
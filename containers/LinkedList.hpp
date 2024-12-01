#pragma once
#include <iostream>
#include "../pointers/SharedPtr.h"
#include "../pointers/UniquePtr.h"

template <class T>
struct Node
{
    T item;
    SharedPtr<Node<T>> next;
};

template <class T>
class LinkedList
{
private:
    SharedPtr<Node<T>> head;
    SharedPtr<Node<T>> tail;
    int listSize;

public:
    // Constructor with array of items
    LinkedList(T *items, int count) : head(nullptr), tail(nullptr)
    {
        int itemsIndex = 0;

        for (int i = 0; i < count; ++i)
        {
            SharedPtr<Node<T>> newNode = SharedPtr<Node<T>>(new Node<T>());
            newNode->item = items[itemsIndex++];
            newNode->next = SharedPtr<Node<T>>();

            if (this->head.get() == nullptr)
            {
                this->head = SharedPtr(newNode); // Set first element of the list
            }
            else
            {
                this->tail->next = SharedPtr(newNode); // Link new node to the last element
            }

            this->tail = newNode; // Update tail pointer
        }

        this->listSize = count;
    }

    // Default constructor
    LinkedList()
    {
        this->head = SharedPtr<Node<T>>();
        this->tail = SharedPtr<Node<T>>();
        this->listSize = 0;
    }

    // Copy constructor
    LinkedList(const LinkedList<T> &list)
    {
        for (int i = 0; i < list.getLength(); i++)
        {
            append(list.get(i));
        }
        this->listSize = list.listSize;
    }

    // Get the first element
    T getFirst()
    {
        if (this->head.get() == nullptr)
        {
            throw std::out_of_range("Empty list.");
        }
        else
        {
            return this->head->item;
        }
    }

    // Get the last element
    T getLast()
    {
        if (this->head.get() == nullptr)
        {
            throw std::out_of_range("Empty list.");
        }
        else
        {
            return this->tail->item;
        }
    }

    // Get an element by index
    T get(int index)
    {
        if (index < 0 || index >= this->listSize)
        {
            throw std::out_of_range("Invalid index.");
        }

        Node<T> *currentNode = this->head.get();
        for (int i = 0; i < index; ++i)
        {
            currentNode = currentNode->next.get();
        }

        return currentNode->item;
    }

    // Get a sublist from startIndex to endIndex
    LinkedList<T> *getSubList(int startIndex, int endIndex)
    {
        if (startIndex < 0 || endIndex >= listSize || startIndex > endIndex)
        {
            throw std::out_of_range("Invalid index range");
        }

        LinkedList<T> *subList = new LinkedList<T>();
        Node<T> *current = head.get();
        int index = 0;

        while (current != nullptr)
        {
            if (index >= startIndex && index <= endIndex)
            {
                subList->append(current->item);
            }
            current = current->next.get();
            index++;
        }
        return subList;
    }

    // Get the length of the list
    int getLength()
    {
        return this->listSize;
    }

    // Append an item to the end of the list
    void append(T item)
    {
        SharedPtr<Node<T>> newNode = SharedPtr<Node<T>>(new Node<T>());
        newNode->item = item;
        newNode->next = SharedPtr<Node<T>>();

        if (listSize == 0)
        {
            head = newNode; // Move newNode to head
        }
        else
        {
            tail->next = newNode; // Move newNode to tail's next
        }
        tail = newNode; // Move newNode to tail
        listSize++;
    }

    // Prepend an item to the beginning of the list
    void prepend(T item)
    {
        SharedPtr<Node<T>> newNode = SharedPtr<Node<T>>(new Node<T>());
        newNode->item = item;
        newNode->next = this->head; // Move current head to newNode's next
        this->head = newNode;       // Move newNode to head

        // if (listSize == 0)
        // {
        //     tail = head.get(); // Only update tail if list was empty
        // }
        listSize++;
    }

    // Insert an item at a specific index
    void insertAt(T item, int index)
    {
        if (index < 0 || index > this->listSize)
        {
            throw std::out_of_range("Invalid index.");
        }
        SharedPtr<Node<T>> newNode = SharedPtr<Node<T>>(new Node<T>());
        newNode->item = item;

        if (index == 0)
        {
            newNode->next = this->head; // Move head to newNode's next
            this->head = newNode;       // Move newNode to head
        }
        else
        {
            Node<T> *currentNode = this->head.get();
            for (int i = 0; i < index - 1; ++i)
            {
                currentNode = currentNode->next.get();
            }

            newNode->next = currentNode->next; // Move current node's next to newNode's next
            currentNode->next = newNode;       // Move newNode to current node's next

            // if (index == listSize)
            // {
            //     tail = currentNode->next.get(); // Update tail if new node is added at the end
            // }
        }

        listSize++;
    }

    // Concatenate two linked lists
    LinkedList<T> *concat(LinkedList<T> *list)
    {
        LinkedList<T> *newList = new LinkedList<T>();
        newList->listSize = this->listSize + list->listSize;

        // Move the current list's head to newList's head
        newList->head = this->head;

        // Link the current list's tail to the other list's head by moving ownership
        this->tail->next = list->head;

        // Move the other list's tail to newList's tail
        newList->tail = list->tail;

        return newList;
    }
};

#pragma once
#include <iostream>

template <class T>
struct Node
{
    T item;
    Node *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int listSize;

public:
    // Constructor with array of items
    LinkedList(T *items, int count)
    {
        this->head = nullptr;
        this->tail = nullptr;
        int itemsIndex = 0;

        for (int i = 0; i < count; ++i)
        {
            Node<T> *newNode = new Node<T>();
            newNode->item = items[itemsIndex++];
            newNode->next = nullptr;

            if (this->head == nullptr)
            {
                this->head = newNode; // Set first element of the list
            }
            else
            {
                this->tail->next = newNode; // Link new node to the last element
            }

            this->tail = newNode; // Update tail pointer
        }

        this->listSize = count;
    }

    // Default constructor
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
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
        if (this->head == nullptr)
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
        if (this->head == nullptr)
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

        Node<T> *currentNode = this->head;
        for (int i = 0; i < index; ++i)
        {
            currentNode = currentNode->next;
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
        Node<T> *current = head;
        int index = 0;

        while (current != nullptr)
        {
            if (index >= startIndex && index <= endIndex)
            {
                subList->append(current->item);
            }
            current = current->next;
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
        Node<T> *newNode = new Node<T>();
        newNode->item = item;
        newNode->next = nullptr;

        if (listSize == 0)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
        listSize++;
    }

    // Prepend an item to the beginning of the list
    void prepend(T item)
    {
        Node<T> *newNode = new Node<T>();
        newNode->item = item;
        newNode->next = this->head;
        this->head = newNode;
        listSize++;
    }

    // Insert an item at a specific index
    void insertAt(T item, int index)
    {
        if (index < 0 || index > this->listSize)
        {
            throw std::out_of_range("Invalid index.");
        }

        Node<T> *newNode = new Node<T>();
        newNode->item = item;

        if (index == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        else
        {
            Node<T> *prevNode = nullptr;
            Node<T> *currentNode = this->head;
            for (int i = 0; i < index; ++i)
            {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }

            prevNode->next = newNode;
            newNode->next = currentNode;
        }

        listSize++;
    }

    // Concatenate two linked lists
    LinkedList<T> *concat(LinkedList<T> *list)
    {
        LinkedList<T> *newList = new LinkedList<T>();
        newList->listSize = this->listSize + list->listSize;
        newList->head = this->head;
        this->tail->next = list->head;
        newList->tail = list->tail;
        return newList;
    }
};

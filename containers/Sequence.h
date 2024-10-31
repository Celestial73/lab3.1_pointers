#pragma once

template <class T>
class Sequence
{
public:
    virtual T getFirst() = 0;
    virtual T getLast() = 0;
    virtual T get(int index) = 0;
    virtual int getLength() = 0;
    virtual void append(T item) = 0;
    virtual void insertAt(T item, int index) = 0;
    virtual void print() = 0;
};

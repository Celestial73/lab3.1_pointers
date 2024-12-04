#pragma once

#include "../pointers/UniquePtr.h"

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
    virtual void set(int index1, T value) = 0;
    virtual UniquePtr<Sequence<T>> concat(Sequence<T> *Sequence) = 0;
    virtual UniquePtr<Sequence<T>> getSubsequence(int startIndex, int endIndex) = 0;
};

#include <iostream>
#include <cassert>
#include "../containers/arraysequence.hpp"

using namespace ds;
void testGetFirst()
{
    int elements[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(elements, 5);
    assert(sequence.getFirst() == 1); // Check if the first element is 1
    std::cout << "testGetFirst PASSED" << std::endl;
}

void testGetLast()
{
    int elements[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(elements, 5);
    assert(sequence.getLast() == 5); // Check if the last element is 5
    std::cout << "testGetLast PASSED" << std::endl;
}

void testGet()
{
    int elements[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(elements, 5);
    assert(sequence.get(2) == 3); // Check if element at index 2 is 3
    std::cout << "testGet PASSED" << std::endl;
}

void testGetOutOfRange()
{
    int elements[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(elements, 5);
    try
    {
        sequence.get(10);                                      // Access an out-of-bounds index
        std::cout << "testGetOutOfRange failed!" << std::endl; // No exception thrown
    }
    catch (std::out_of_range &e)
    {
        std::cout << "testGetOutOfRange PASSED" << std::endl; // Expecting exception
    }
}

void testGetLength()
{
    int elements[] = {1, 2, 3, 4, 5};
    ArraySequence<int> sequence(elements, 5);
    assert(sequence.getLength() == 5); // Check if length of array is 5
    std::cout << "testGetLength PASSED" << std::endl;
}

void testAppend()
{
    ArraySequence<int> sequence;
    sequence.append(10);
    assert(sequence.getLength() == 1); // Check if length is now 1
    assert(sequence.get(0) == 10);     // Check if element is added correctly
    std::cout << "testAppend PASSED" << std::endl;
}

void testInsertAt()
{
    int elements[] = {1, 2, 4, 5};
    ArraySequence<int> sequence(elements, 4);
    sequence.insertAt(3, 2);           // Insert element 3 at index 2
    assert(sequence.get(2) == 3);      // Check if element inserted correctly
    assert(sequence.getLength() == 5); // Check if length increased
    std::cout << "testInsertAt PASSED" << std::endl;
}

void testInsertAtOutOfRange()
{
    ArraySequence<int> sequence;
    try
    {
        sequence.insertAt(1, 5);                                    // Attempt to insert element out of bounds
        std::cout << "testInsertAtOutOfRange failed!" << std::endl; // No exception thrown
    }
    catch (std::out_of_range &e)
    {
        std::cout << "testInsertAtOutOfRange PASSED" << std::endl; // Expecting exception
    }
}

void arraySequenceWithSharedPtrTest()
{
    testGetFirst();
    testGet();
    testAppend();
    testGetLast();
    testGetLength();
    testGetOutOfRange();
    testInsertAt();
    testInsertAtOutOfRange();
}

#include <iostream>
#include <cassert>
#include "../containers/listsequence.hpp" // Include ListSequence class
using namespace ds;
// Test getFirst method for ListSequence
void testListGetFirst()
{
    int items[] = {1, 2, 3, 4};
    ListSequence<int> sequence(items, 4);
    assert(sequence.getFirst() == 1); // Verify that the first element is 1
    std::cout << "testListGetFirst PASSED" << std::endl;
}

// Test getLast method for ListSequence
void testListGetLast()
{
    int items[] = {1, 2, 3, 4};
    ListSequence<int> sequence(items, 4);
    assert(sequence.getLast() == 4); // Verify that the last element is 4
    std::cout << "testListGetLast PASSED" << std::endl;
}

// Test get method for ListSequence
void testListGet()
{
    int items[] = {1, 2, 3, 4};
    ListSequence<int> sequence(items, 4);
    assert(sequence.get(2) == 3); // Verify that element at index 2 is 3
    std::cout << "testListGet PASSED" << std::endl;
}

// Test getLength method for ListSequence
void testListGetLength()
{
    int items[] = {1, 2, 3, 4};
    ListSequence<int> sequence(items, 4);
    assert(sequence.getLength() == 4); // Verify that list length is 4
    std::cout << "testListGetLength PASSED" << std::endl;
}

// Test append method for ListSequence
void testListAppend()
{
    ListSequence<int> sequence;
    sequence.append(10);               // Add element 10 to an empty list
    assert(sequence.getLength() == 1); // Verify list length is now 1
    assert(sequence.getLast() == 10);  // Verify that the last element is 10
    std::cout << "testListAppend PASSED" << std::endl;
}

// Test insertAt method for ListSequence
void testListInsertAt()
{
    int items[] = {1, 2, 4, 5};
    ListSequence<int> sequence(items, 4);
    sequence.insertAt(3, 2);           // Insert element 3 at index 2
    assert(sequence.get(2) == 3);      // Verify element at index 2 is now 3
    assert(sequence.getLength() == 5); // Verify list length increased to 5
    std::cout << "testListInsertAt PASSED" << std::endl;
}

// Test for insertion at an invalid index in ListSequence
void testListInsertAtOutOfRange()
{
    int items[] = {1, 2, 3, 4};
    ListSequence<int> sequence(items, 4);
    bool exceptionCaught = false;

    try
    {
        sequence.insertAt(5, 10); // Try inserting at invalid index 10
    }
    catch (const std::out_of_range &)
    {
        exceptionCaught = true; // Set flag to true if exception is caught
    }

    assert(exceptionCaught); // Verify exception was thrown
    std::cout << "testListInsertAtOutOfRange PASSED" << std::endl;
}

// Test for retrieving element at an invalid index in ListSequence
void testListGetOutOfRange()
{
    int items[] = {1, 2, 3, 4};
    ListSequence<int> sequence(items, 4);
    bool exceptionCaught = false;

    try
    {
        sequence.get(10); // Try retrieving element at invalid index 10
    }
    catch (const std::out_of_range &)
    {
        exceptionCaught = true; // Set flag to true if exception is caught
    }

    assert(exceptionCaught); // Verify exception was thrown
    std::cout << "testListGetOutOfRange PASSED" << std::endl;
}

// Test concat method for ListSequence
void testListConcat()
{
    int items1[] = {1, 2, 3};
    int items2[] = {4, 5, 6};

    ListSequence<int> sequence1(items1, 3); // Sequence 1: {1, 2, 3}
    ListSequence<int> sequence2(items2, 3); // Sequence 2: {4, 5, 6}

    ListSequence<int> *concatenatedSequence = dynamic_cast<ListSequence<int> *>(sequence1.concat(&sequence2));

    assert(concatenatedSequence->getLength() == 6); // Verify combined length is 6

    assert(concatenatedSequence->get(0) == 1);
    assert(concatenatedSequence->get(1) == 2);
    assert(concatenatedSequence->get(2) == 3);
    assert(concatenatedSequence->get(3) == 4);
    assert(concatenatedSequence->get(4) == 5);
    assert(concatenatedSequence->get(5) == 6);

    std::cout << "testListConcat PASSED" << std::endl;

    delete concatenatedSequence; // Free memory for concatenated result
}

// Run all tests for ListSequence
void listSequenceWithUniquePtrTests()
{
    testListInsertAt();
    testListAppend();
    testListGetLength();
    testListGet();
    testListGetFirst();
    testListGetLast();
    testListGetOutOfRange();
    testListInsertAtOutOfRange();
    testListConcat();
}

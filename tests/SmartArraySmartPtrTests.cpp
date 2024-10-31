#include "SmartArraySmartPtrTests.h"
#include <iostream>
#include <cassert>
#include "../containers/SmartArray.h"
using namespace ds;
void testInitialization()
{
    // Create an array of integers with 5 elements
    SmartArray<int> arr(5);

    // Initialize the array with values
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        arr[i] = static_cast<int>(i + 1); // Fill the array with 1, 2, 3, 4, 5
    }

    // Check initial values
    std::cout << "Initial array: ";
    arr.print(); // Should output: 1 2 3 4 5

    // Check the size of the array
    assert(arr.getSize() == 5); // Verify that the array size is 5
}

void testAccessElements()
{
    SmartArray<int> arr(5);

    // Initialize the array with values
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        arr[i] = static_cast<int>(i + 1); // Fill the array with 1, 2, 3, 4, 5
    }

    // Check access to elements
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        assert(arr[i] == static_cast<int>(i + 1)); // Verify that array elements match expected values
    }
}

void testAppendElements()
{
    SmartArray<int> arr(5);

    // Initialize the array with values
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        arr[i] = static_cast<int>(i + 1); // Fill the array with 1, 2, 3, 4, 5
    }

    // Append a new element
    arr.append(6);
    std::cout << "After appending 6: ";
    arr.print();                // Should output: 1 2 3 4 5 6
    assert(arr.getSize() == 6); // Verify that the array size is now 6
    assert(arr[5] == 6);        // Verify that the appended element is 6

    // Append another element
    arr.append(7);
    std::cout << "After appending 7: ";
    arr.print();                // Should output: 1 2 3 4 5 6 7
    assert(arr.getSize() == 7); // Verify that the array size is now 7
    assert(arr[6] == 7);        // Verify that the appended element is 7
}

void SmartArraySmartPtrTests()
{
    testInitialization();
    testAccessElements();
    testAppendElements();

    std::cout << "All tests PASSED" << std::endl;
}

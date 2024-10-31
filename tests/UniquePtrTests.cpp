#include "UniquePtrTests.h"
#include <iostream>
#include "../pointers/UniquePtr.h"

void testDefaultConstructorUniquePtr()
{
    UniquePtr<int> ptr;
    if (ptr.get() == nullptr)
    {
        std::cout << "testDefaultConstructor PASSED\n";
    }
    else
    {
        std::cout << "testDefaultConstructor FAILED\n";
    }
}

void testExplicitConstructorUniquePtr()
{
    UniquePtr<int> ptr(new int(42));
    if (*ptr == 42)
    {
        std::cout << "testExplicitConstructor PASSED\n";
    }
    else
    {
        std::cout << "testExplicitConstructor FAILED\n";
    }
}

void testMoveConstructorUniquePtr()
{
    UniquePtr<int> ptr1(new int(42));
    UniquePtr<int> ptr2(std::move(ptr1));

    if (ptr1.get() == nullptr && *ptr2 == 42)
    {
        std::cout << "testMoveConstructor PASSED\n";
    }
    else
    {
        std::cout << "testMoveConstructor FAILED\n";
    }
}

void testMoveAssignmentUniquePtr()
{
    UniquePtr<int> ptr1(new int(100));
    UniquePtr<int> ptr2;

    ptr2 = std::move(ptr1);

    if (ptr1.get() == nullptr && *ptr2 == 100)
    {
        std::cout << "testMoveAssignment PASSED\n";
    }
    else
    {
        std::cout << "testMoveAssignment FAILED\n";
    }
}

void testDereferenceOperatorUniquePtr()
{
    UniquePtr<int> ptr(new int(55));
    if (*ptr == 55)
    {
        std::cout << "testDereferenceOperator PASSED\n";
    }
    else
    {
        std::cout << "testDereferenceOperator FAILED\n";
    }
}

void testArrowOperatorUniquePtr()
{
    struct TestClass
    {
        int value;
        TestClass(int val) : value(val) {}
    };

    UniquePtr<TestClass> ptr(new TestClass(42));
    if (ptr->value == 42)
    {
        std::cout << "testArrowOperator PASSED\n";
    }
    else
    {
        std::cout << "testArrowOperator FAILED\n";
    }
}

void testReleaseMethodUniquePtr()
{
    UniquePtr<int> ptr(new int(88));
    int *rawPtr = ptr.release();

    if (ptr.get() == nullptr && *rawPtr == 88)
    {
        std::cout << "testReleaseMethod PASSED\n";
    }
    else
    {
        std::cout << "testReleaseMethod FAILED\n";
    }

    delete rawPtr;
}

void testResetMethodUniquePtr()
{
    UniquePtr<int> ptr(new int(77));
    ptr.reset(new int(99));

    if (*ptr == 99)
    {
        std::cout << "testResetMethod PASSED\n";
    }
    else
    {
        std::cout << "testResetMethod FAILED\n";
    }
}

void runUniquePtrTests()
{
    testArrowOperatorUniquePtr();
    testDefaultConstructorUniquePtr();
    testDereferenceOperatorUniquePtr();
    testExplicitConstructorUniquePtr();
    testMoveAssignmentUniquePtr();
    testMoveConstructorUniquePtr();
    testReleaseMethodUniquePtr();
    testResetMethodUniquePtr();
}
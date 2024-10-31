#include "SmartPtrTests.h"
#include <iostream>
#include "../pointers/SmartPtr.h"

void testDefaultConstructorSmartPtr()
{
    SmartPtr<int> ptr;
    if (ptr.get() == nullptr && ptr.num_count() == 0)
    {
        std::cout << "testDefaultConstructor PASSED\n";
    }
    else
    {
        std::cout << "testDefaultConstructor FAILED\n";
    }
}

void testConstructorWithParameterSmartPtr()
{
    SmartPtr<int> ptr(new int(42));
    if (*ptr == 42 && ptr.num_count() == 1)
    {
        std::cout << "testConstructorWithParameter PASSED\n";
    }
    else
    {
        std::cout << "testConstructorWithParameter FAILED\n";
    }
}

void testCopyConstructorSmartPtr()
{
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2(ptr1);

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2)
    {
        std::cout << "testCopyConstructor PASSED\n";
    }
    else
    {
        std::cout << "testCopyConstructor FAILED\n";
    }
}

void testCopyAssignmentSmartPtr()
{
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2;
    ptr2 = ptr1;

    if (*ptr1 == 42 && *ptr2 == 42 && ptr1.num_count() == 2 && ptr2.num_count() == 2)
    {
        std::cout << "testCopyAssignment PASSED\n";
    }
    else
    {
        std::cout << "testCopyAssignment FAILED\n";
    }
}

void testMoveConstructorSmartPtr()
{
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2(std::move(ptr1));

    if (ptr1.get() == nullptr && *ptr2 == 42 && ptr2.num_count() == 1)
    {
        std::cout << "testMoveConstructor PASSED\n";
    }
    else
    {
        std::cout << "testMoveConstructor FAILED\n";
    }
}

void testMoveAssignmentSmartPtr()
{
    SmartPtr<int> ptr1(new int(42));
    SmartPtr<int> ptr2;
    ptr2 = std::move(ptr1);

    if (ptr1.get() == nullptr && *ptr2 == 42 && ptr2.num_count() == 1)
    {
        std::cout << "testMoveAssignment PASSED\n";
    }
    else
    {
        std::cout << "testMoveAssignment FAILED\n";
    }
}

void testResetSmartPtr()
{
    SmartPtr<int> ptr(new int(42));
    ptr.reset(new int(100));

    if (*ptr == 100 && ptr.num_count() == 1)
    {
        std::cout << "testReset PASSED\n";
    }
    else
    {
        std::cout << "testReset FAILED\n";
    }
}

void testDereferenceOperatorSmartPtr()
{
    SmartPtr<int> ptr(new int(42));
    if (*ptr == 42)
    {
        std::cout << "testDereferenceOperator PASSED\n";
    }
    else
    {
        std::cout << "testDereferenceOperator FAILED\n";
    }
}

void testArrowOperatorSmartPtr()
{
    struct TestClass
    {
        int value;
        TestClass(int val) : value(val) {}
    };

    SmartPtr<TestClass> ptr(new TestClass(42));
    if (ptr->value == 42)
    {
        std::cout << "testArrowOperator PASSED\n";
    }
    else
    {
        std::cout << "testArrowOperator FAILED\n";
    }
}

void runSmartPtrTests()
{
    testArrowOperatorSmartPtr();
    testConstructorWithParameterSmartPtr();
    testCopyAssignmentSmartPtr();
    testCopyConstructorSmartPtr();
    testDefaultConstructorSmartPtr();
    testDereferenceOperatorSmartPtr();
    testMoveAssignmentSmartPtr();
    testMoveConstructorSmartPtr();
    testResetSmartPtr();
}

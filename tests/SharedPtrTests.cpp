#include "SharedPtrTests.h"
#include <iostream>
#include "../pointers/SharedPtr.h"

void testCopyAssignmentSharedPtr()
{
    SharedPtr<int> sharedIntA(new int(58));
    SharedPtr<int> sharedIntB;
    sharedIntB = sharedIntA;

    if (*sharedIntA == 58 && *sharedIntB == 58 && sharedIntA.num_count() == 2 && sharedIntB.num_count() == 2)
    {
        std::cout << "testCopyAssignment PASSED\n";
    }
    else
    {
        std::cout << "testCopyAssignment failed\n";
    }
}

void testConstructorWithParameterSharedPtr()
{
    SharedPtr<int> sharedInt(new int(99));
    if (*sharedInt == 99 && sharedInt.num_count() == 1)
    {
        std::cout << "testConstructorWithParameter PASSED\n";
    }
    else
    {
        std::cout << "testConstructorWithParameter failed\n";
    }
}

void testArrowOperatorSharedPtr()
{
    struct SampleClass
    {
        int data;
        SampleClass(int val) : data(val) {}
    };

    SharedPtr<SampleClass> ptrSample(new SampleClass(78));
    if (ptrSample->data == 78)
    {
        std::cout << "testArrowOperator PASSED\n";
    }
    else
    {
        std::cout << "testArrowOperator failed\n";
    }
}

void testDefaultConstructorSharedPtr()
{
    SharedPtr<int> emptyPtr;
    if (emptyPtr.get() == nullptr && emptyPtr.num_count() == 0)
    {
        std::cout << "testDefaultConstructor PASSED\n";
    }
    else
    {
        std::cout << "testDefaultConstructor failed\n";
    }
}

void testCopyConstructorSharedPtr()
{
    SharedPtr<int> sharedOriginal(new int(73));
    SharedPtr<int> sharedCopy(sharedOriginal);

    if (*sharedOriginal == 73 && *sharedCopy == 73 && sharedOriginal.num_count() == 2 && sharedCopy.num_count() == 2)
    {
        std::cout << "testCopyConstructor PASSED\n";
    }
    else
    {
        std::cout << "testCopyConstructor failed\n";
    }
}

void testReferenceCountingSharedPtr()
{
    SharedPtr<int> refCountPtrA(new int(44));
    SharedPtr<int> refCountPtrB(refCountPtrA);
    SharedPtr<int> refCountPtrC(refCountPtrB);

    if (refCountPtrA.num_count() == 3 && refCountPtrB.num_count() == 3 && refCountPtrC.num_count() == 3)
    {
        std::cout << "testReferenceCounting PASSED\n";
    }
    else
    {
        std::cout << "testReferenceCounting failed\n";
    }

    refCountPtrC.reset();
    if (refCountPtrA.num_count() == 2 && refCountPtrB.num_count() == 2 && refCountPtrC.num_count() == 0)
    {
        std::cout << "testReferenceCounting after reset PASSED\n";
    }
    else
    {
        std::cout << "testReferenceCounting after reset failed\n";
    }
}

void testResetSharedPtr()
{
    SharedPtr<int> resetPtr(new int(45));
    resetPtr.reset(new int(101));

    if (*resetPtr == 101 && resetPtr.num_count() == 1)
    {
        std::cout << "testReset PASSED\n";
    }
    else
    {
        std::cout << "testReset failed\n";
    }
}

void testDereferenceOperatorSharedPtr()
{
    SharedPtr<int> derefPtr(new int(88));
    if (*derefPtr == 88)
    {
        std::cout << "testDereferenceOperator PASSED\n";
    }
    else
    {
        std::cout << "testDereferenceOperator failed\n";
    }
}

void runSharedPtrTests()
{
    testDefaultConstructorSharedPtr();
    testReferenceCountingSharedPtr();
    testConstructorWithParameterSharedPtr();
    testResetSharedPtr();
    testArrowOperatorSharedPtr();
    testCopyAssignmentSharedPtr();
    testCopyConstructorSharedPtr();
    testDereferenceOperatorSharedPtr();
}

#include "menu.h"
#include "tests/ArraySequenceSharedPtrTests.h"
#include "tests/SmartArraySmartPtrTests.h"
#include "tests/ListSequenceUniquePtrTests.h"
#include "tests/SharedPtrTests.h"
#include "tests/SmartPtrTests.h"
#include "tests/UniquePtrTests.h"

#include <iostream>

void print_menu()
{
    std::cout << "\nMenu:\n";
    std::cout << "(1) Shared pointer and array sequence tests\n";
    std::cout << "(2) Unique pointer and list sequence tests\n";
    std::cout << "(3) Smart pointer and smart array tests\n";
    std::cout << "(4) Exit\n";
    std::cout << "Choose an option: ";
}

void menu()
{
    int choice;

    do
    {
        print_menu();
        std::cin >> choice;
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;

        switch (choice)
        {
        case 1:
            arraySequenceWithSharedPtrTest();
            runSharedPtrTests();
            break;
        case 2:
            listSequenceWithUniquePtrTests();
            runUniquePtrTests();
            break;
        case 3:
            SmartArraySmartPtrTests();
            runSmartPtrTests();
        case 4:
            std::cout << "Exit\n";
            break;
        default:
            std::cout << "Number out of range. \n";
            break;
        }
    } while (choice != 4);
}

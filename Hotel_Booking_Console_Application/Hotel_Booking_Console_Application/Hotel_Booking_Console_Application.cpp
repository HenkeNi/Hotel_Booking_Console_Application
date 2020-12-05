#include "Application.h"
#include <iostream>

int main()
{
    try
    {
        Application::run();
    }
    catch (...)
    {
        std::cerr << "Abnormal Termination!";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


#include "eventLoop.h"

// Main Cpp to run application
void projectMainCPP()
{

}

// Define all C function calls from main.c below
extern "C"
{
    void projectMain()
    {
        projectMainCPP();
    }
}
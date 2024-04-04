#ifndef EVENTLOOP_H_
#define EVENTLOOP_H_

#include <stdint.h>
#include <stdio.h>

void projectMainCPP();   // Cpp function to call into main event loop

#ifdef __cplusplus
extern "C"
{
#endif
    void projectMain();  // C function to call into Cpp event loop from main
#ifdef __cplusplus
}
#endif

#endif /* EVENTLOOP_H_ */
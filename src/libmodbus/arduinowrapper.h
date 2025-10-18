#ifndef ARDUINOWRAPPER_H
#define ARDUINOWRAPPER_H

// #ifdef __cplusplus
//     #include <Arduino.h>
// #endif

// struct Print_;

// Key: this header should be usable from both - C and C++ code
// Read more: https://isocpp.org/wiki/faq/mixing-c-and-cpp
// Read more: https://stackoverflow.com/questions/43602910/extern-c-causing-an-error-expected-before-string-constant

// #pragma once
#ifdef __cplusplus
extern "C" {
#endif

    // You may define SHandle as void * and add casts everywhere to avoid declaring "struct Print_;" above
    // Read more: https://stackoverflow.com/questions/11971063/how-to-use-c-objects-in-c
    typedef void * PrintWrapper;
    PrintWrapper create_wrapper();
    void    free_wrapper(PrintWrapper);
    void    call_serial(PrintWrapper, const char *);

#ifdef __cplusplus
}
#endif

#endif // ARDUINOWRAPPER_H
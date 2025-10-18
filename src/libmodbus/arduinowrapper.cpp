#include "arduinowrapper.h"
#include <Arduino.h>

extern "C" {
    PrintWrapper create_wrapper() { 
        // if (!SerialUSB){
        //     SerialUSB.begin(9600);
        //     while (!SerialUSB.available()) {
        //         ;
        //     }
        // }
        return (Print *)(&SerialUSB);
    }
    void free_wrapper(PrintWrapper p) { 
        // delete (Print *)p;
        // Only delete pointer, not the SerialUSB object
        p = 0; 
    }
    
    void call_serial(PrintWrapper p, const char * str) {
        ((Print *)p)->println(str); 
    }
}
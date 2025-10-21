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

    void call_serial_int(PrintWrapper p, uint8_t i) {
        ((Print *)p)->println(i);
    }

    void call_serial_msg(PrintWrapper p, uint8_t *msg, int msg_length){
        for (int i = 0; i < msg_length; i++){
            ((Print *)p)->print("[");
            ((Print *)p)->print((int)msg[i], HEX);
            ((Print *)p)->print("] ");
        }
        ((Print *)p)->println();
    }
}
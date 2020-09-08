#ifndef StreamMOCK_h
#define StreamMOCK_h

#include "Arduino.h"
/*#include <Stream.h>*/

class StreamMOCK : public Stream
{
    private:
        int numRead = 0;
        int numWrite = 0;
        int numFlush = 0;
        int numAvailable = 0;
        byte WriteBufferIndex = 0;
        byte ReadBufferIndex = 0;
        
    
    public:
        StreamMOCK();

        byte writeBuffer[64];
        byte readBuffer[64];
        int availableBytes= 0;
        int available();
        void flush();
        int read();
        size_t write(byte b);
        void write(byte *b, int l);
        int peek();
        void print(String message);
        int availableCalls();
        int flushCalls();
        int readCalls();
        int writeCalls();
        void clean();
        
        
};

#endif

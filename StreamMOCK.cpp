#include "Arduino.h"
#include "StreamMOCK.h"

StreamMOCK::StreamMOCK()
{

}


int StreamMOCK::available()
{
    numAvailable++;
    return availableBytes;
}


void StreamMOCK::flush()
{
    numFlush++;
}


int StreamMOCK::read()
{
    numRead++;
    byte r = readBuffer[0];
    
    for(byte i = 0; i < availableBytes; i++)
    {
        readBuffer[i] = readBuffer[i + 1];
    }

    availableBytes--;

    return r; 
}

size_t StreamMOCK::write(byte b)
{
    numWrite++;
    writeBuffer[WriteBufferIndex] = b;
    WriteBufferIndex++;
}

void StreamMOCK::write(byte *b, int l)
{
    numWrite++;

    for(int i = 0; i < l; i++)
    {
        writeBuffer[WriteBufferIndex] = b[i];
        WriteBufferIndex++;
    }
}

int StreamMOCK::peek()
{
   return readBuffer[0];
}


void StreamMOCK::print(String message)
{   
    byte arrayMessage[message.length() + 1];
    message.toCharArray(arrayMessage, message.length() + 1);

    for(int i = 0; i < message.length(); i++)
    {
        writeBuffer[i] = arrayMessage[i]; 
    }
}

int StreamMOCK::availableCalls()
{
    return numAvailable;
}
int StreamMOCK::flushCalls()
{
    return numFlush;
}
int StreamMOCK::readCalls()
{
    return numRead;
}

int StreamMOCK::writeCalls()
{
    return numWrite;
}

void StreamMOCK::clean()
{
    numFlush = 0;
    numRead = 0;
    numWrite = 0;
    numAvailable = 0;
    WriteBufferIndex = 0;
    availableBytes= 0;
    for(int i = 0; i < 64; i++)
    {
      writeBuffer[i] = '\0';
    }
}

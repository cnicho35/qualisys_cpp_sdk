#include "RTProtocol.h"
#include "RTPacket.h"

#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>

extern "C"
{
    const char * initQTM(const char *ipAddress, const unsigned short qtmPort);
    const char * getData();
    void closeQTM();

}
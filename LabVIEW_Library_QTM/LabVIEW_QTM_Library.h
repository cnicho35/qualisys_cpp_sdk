#include "RTProtocol.h"
#include "RTPacket.h"

#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>

extern "C"
{
    int32_t initQTM(const char *ipAddress, unsigned short * qtmPort);
    char * getData();
    void closeQTM();

}
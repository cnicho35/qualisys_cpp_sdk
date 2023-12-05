#include "LabVIEW_QTM_Library.h"

int main() {
    int32_t response;
    const char* add = "192.168.254.001";
    unsigned short port = 22222;
    unsigned short* portptr = &port;

    response = initQTM(add, portptr);
    std::cout << response << std::endl;


    // Rest of your code
    char * stringOut = getData();

    std::cout << stringOut << std::endl;

    closeQTM();




    return 0;
}
#include "LabVIEW_QTM_Library.h"

CRTProtocol rtProtocol;

const int majorVersion = 1;
const int minorVersion = 19;
const bool bigEndian = false;

bool dataAvailable = false;
bool streamFrames = false;
unsigned short udpPort = 6734;

CRTPacket::EPacketType packetType;

std::stringstream initString;
std::stringstream dataString;
unsigned long long cameraTime;

int32_t failedInit;

const int BUFFER_SIZE = 512;
char* cString = new char[BUFFER_SIZE];
std::string result;

int32_t initQTM(const char * ipAddress, unsigned short  * qtmPort)
{
    const char *serverAddr = ipAddress;
    const unsigned short basePort = *qtmPort;
    failedInit= 0;


    if (!rtProtocol.Connected())
    {
        if (!rtProtocol.Connect(serverAddr, basePort, &udpPort, majorVersion, minorVersion, bigEndian))
        {

            failedInit= 1;
        }
    }

    if (!dataAvailable)
    {
        if (!rtProtocol.Read6DOFSettings(dataAvailable))
        {
            failedInit= 1;
        }
    }

    if (!streamFrames)
    {
        if (!rtProtocol.StreamFrames(CRTProtocol::RateAllFrames, 0, udpPort, NULL, "6d timecode"))
        {
            failedInit= 1;
        }
    }
     return failedInit;
}
char* getData()
{
    dataString.str("");  // Clear the stringstream
    result.clear();      // Clear the result string
    strncpy(cString, "", BUFFER_SIZE - 1);

    dataString << std::fixed;

    if (rtProtocol.Receive(packetType, true) == CNetwork::ResponseType::success)
    {
        if (packetType == CRTPacket::PacketData)
        {
            float fX, fY, fZ;
            float rotationMatrix[9];

            CRTPacket* rtPacket = rtProtocol.GetRTPacket();

            printf("Frame %d\n", rtPacket->GetFrameNumber());
            printf("======================================================================================================================\n");

            rtPacket->GetTimecodeCameraTime(cameraTime);

            for (unsigned int i = 0; i < rtPacket->Get6DOFBodyCount(); i++)
            {
                if (rtPacket->Get6DOFBody(i, fX, fY, fZ, rotationMatrix))
                {
                    dataString << fX << "," << fY << "," << fZ << "," << rotationMatrix[0] << "," << rotationMatrix[1] << "," << rotationMatrix[2] << "," << rotationMatrix[3] << "," << rotationMatrix[4] << "," << rotationMatrix[5] << "," << rotationMatrix[6] << "," << rotationMatrix[7] << "," << rotationMatrix[8] << "," << cameraTime;
                }
                else
                {
                    dataString << "ERROR";
                }

                result = dataString.str();
                strncpy(cString, result.c_str(), BUFFER_SIZE - 1);
            }
        }
    }
    return cString;
}
void closeQTM()
{
    rtProtocol.StopCapture();
    rtProtocol.Disconnect();
}

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

const char *initQTM(const char *ipAddress, const unsigned short qtmPort)
{
    initString.clear();

    const char *serverAddr = ipAddress;
    const unsigned short basePort = qtmPort;

    if (!rtProtocol.Connected())
    {
        if (!rtProtocol.Connect(serverAddr, basePort, &udpPort, majorVersion, minorVersion, bigEndian))
        {

            initString << "Connection Failed,";
        }
        else
        {
            initString << "Connection Succeeded,";
        }
    }

    if (!dataAvailable)
    {
        if (!rtProtocol.Read6DOFSettings(dataAvailable))
        {
            initString << "No Data Available, ";
        }
        else
        {
            initString << "Data Available, ";
        }
    }

    if (!streamFrames)
    {
        if (!rtProtocol.StreamFrames(CRTProtocol::RateAllFrames, 0, udpPort, NULL, CRTProtocol::cComponent6d))
        {
            initString << "No Stream Available, ";
        }
        else
        {
            streamFrames = true;
            initString << "Stream Available, ";
        }
    }
    return initString.str().c_str();
}
const char *getData()
{
    dataString.clear();
    if (rtProtocol.Receive(packetType, true) == CNetwork::ResponseType::success)
    {
        if (packetType == CRTPacket::PacketData)
        {
            float fX, fY, fZ;
            float rotationMatrix[9];

            CRTPacket *rtPacket = rtProtocol.GetRTPacket();

            printf("Frame %d\n", rtPacket->GetFrameNumber());
            printf("======================================================================================================================\n");

            for (unsigned int i = 0; i < rtPacket->Get6DOFBodyCount(); i++)
            {
                if (rtPacket->Get6DOFBody(i, fX, fY, fZ, rotationMatrix))
                {
                    dataString << fX << "," << fY << "," << fZ << "," << rotationMatrix[0] << "," << rotationMatrix[1] << "," << rotationMatrix[2] << "," << rotationMatrix[3] << "," << rotationMatrix[4] << "," << rotationMatrix[5] << "," << rotationMatrix[6] << "," << rotationMatrix[7] << "," << rotationMatrix[8];
                }
                else
                {
                    dataString << "ERROR";
                }
            }
        }
    }
    return dataString.str().c_str();
}
void closeQTM()
{
    rtProtocol.StopCapture();
    rtProtocol.Disconnect();
}

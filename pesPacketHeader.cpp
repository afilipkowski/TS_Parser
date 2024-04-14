#include "pesPacketHeader.h"

void pesPacketHeader::Reset(){
    PSCP    = 0;
    SID     = 0;
    PES_LEN = 0;
}

void pesPacketHeader::Parse(const uint8_t* Input)
{
    uint32_t* payloadPtr = (uint32_t*)Input; //32b is equal to packet start code prefix and stream id
    uint16_t* payloadPtr2;

    uint32_t  payloadVal = xSwapBytes32(*payloadPtr);
    uint8_t   sidMASK    = 0b11111111;
    uint32_t  pscpMask   = 0xFFFFFF;

    SID     = payloadVal bitand sidMASK;
    PSCP    = (payloadVal >> 8) bitand pscpMask;
    
    payloadPtr++;
    payloadPtr2 = (uint16_t*)payloadPtr;
    PES_LEN     = xSwapBytes16(*payloadPtr2);
}

void pesPacketHeader::Print()
{
    printf(" PES:");
    printf(" PSCP=%d", PSCP);
    printf(" SID=%d", SID);
    printf(" LEN=%d", PES_LEN);
}
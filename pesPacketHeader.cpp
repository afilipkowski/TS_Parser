#include "pesPacketHeader.h"

void pesPacketHeader::Reset(){
    PSCP    = 0;
    SID     = 0;
    PES_LEN = 0;
    PES_HEADER_LEN = 0;
}

uint8_t* pesPacketHeader::Parse(const uint8_t* Input)
{
    uint32_t* payloadPtr = (uint32_t*)Input; //32b is equal to packet start code prefix and stream id
    uint16_t* payloadPtr2;
    uint8_t*  payloadPtr3;

    uint32_t  payloadVal = xSwapBytes32(*payloadPtr);
    uint8_t   sidMASK    = 0b11111111;
    uint32_t  pscpMask   = 0xFFFFFF;

    SID     = payloadVal bitand sidMASK;
    PSCP    = (payloadVal >> 8) bitand pscpMask;
    
    payloadPtr++;
    payloadPtr2 = (uint16_t*)payloadPtr;
    PES_LEN     = xSwapBytes16(*payloadPtr2);
    payloadPtr2+=2;
    PES_HEADER_LEN = (xSwapBytes16(*payloadPtr2) >> 8) bitand 0b0000000011111111;
    payloadPtr3 = (uint8_t*)payloadPtr2;
    payloadPtr3 += (PES_HEADER_LEN + 1);

    return payloadPtr3;
}

void pesPacketHeader::Print()
{
    printf("\n\t");
    printf("\033[0;36m");
    printf("PES:");
    printf(" PSCP=%d", PSCP);
    printf(" SID=%d", SID);
    printf(" LEN=%d", PES_LEN);
    printf("\033[0m");
    printf(" Start assembling");
}
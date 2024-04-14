#pragma once
#include "tsCommon.h"

class pesPacketHeader
{

protected:
    uint32_t PSCP;
    uint8_t  SID;
    uint16_t PES_LEN;


public:
    void Reset();
    void Parse(const uint8_t* Input);
    void Print();
};


#pragma once
#include "tsCommon.h"

class pesPacketHeader
{

protected:
    uint32_t PSCP;
    uint8_t  SID;
    uint16_t PES_LEN;
    uint8_t  PES_HEADER_LEN;


public:
    void Reset();
    uint8_t* Parse(const uint8_t* Input);
    void Print();

public:
    uint8_t     getPESHL() const {return PES_HEADER_LEN;}
    uint16_t    getPES_LEN() const {return PES_LEN - (PES_HEADER_LEN+3);}
};


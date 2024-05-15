#pragma once
#include "tsCommon.h"
class pesAssembler
{

public:
    uint8_t lastCC;
    void absorbPacket(FILE* output, uint8_t* data_ptr, uint8_t tsBytes);
    void printStatus(uint16_t pesBytes);
};
#pragma once
#include "tsCommon.h"
class pesAssembler
{

public:
    uint8_t lastCC;
    void absorbPacket(uint16_t pesBytes, uint8_t tsBytes, uint8_t continuityCounter);
    void printStatus(uint16_t pesBytes);
};
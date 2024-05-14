#include "pesAssembler.h"

void pesAssembler::absorbPacket(uint16_t pesBytes, uint8_t tsBytes, uint8_t continuityCounter)
{
    if (continuityCounter == lastCC+1)
    {
        lastCC++;
    }
}

void pesAssembler::printStatus(uint16_t pesBytes)
{
    if (pesBytes != 0)
    {
        printf(" Assembling");
    }
    else
    {
        printf(" Finished ");
    }
    
}
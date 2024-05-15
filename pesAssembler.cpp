#include "pesAssembler.h"
#include "tsCommon.h"

void pesAssembler::absorbPacket(FILE* output, uint8_t* data_ptr, uint8_t tsBytes)
{
        lastCC++;
        uint8_t data_buffer[tsBytes];
        uint8_t* dataptr = data_ptr;
        for (int i=0;i<tsBytes;i++)
        {
            data_buffer[i] = *dataptr;
            dataptr++;
        }
        size_t savedBytes = fwrite(data_buffer, 1, tsBytes, output);
        printf(" %d", savedBytes);

}

void pesAssembler::printStatus(uint16_t pesBytes)
{
    if (pesBytes != 0)
    {
        printf(" Assembling");
    }
    else
    {
        printf("\n");
        printf("\t\t\t\t\t\t\tFinished ");
    }
    
}
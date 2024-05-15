#include "tsCommon.h"
#include "tsPacketHeader.h"
#include "tsAdaptationField.h"
#include "pesPacketHeader.h"
#include "pesAssembler.h"
//=============================================================================================================================================================================

int main(int argc, char *argv[ ], char *envp[ ])
{
  FILE* fp = std::fopen("../example_new.ts", "rb");
  if (!fp)
  {
    std::perror("File opening failed");
    return EXIT_FAILURE;
  }

  FILE* output = std::fopen("../output.mp2", "wb");

  TS_PacketHeader    TS_PacketHeader;
  TS_AdaptationField TS_AdaptationField;
  pesPacketHeader    pesPacketHeader;
  pesAssembler       pesAssembler;

  uint8_t             BUFFER_SIZE = 188;
  uint8_t             TS_PacketBuffer[BUFFER_SIZE];
  uint8_t             PES_PacketBuffer[BUFFER_SIZE-4];
  int32_t             TS_PacketId = 0;
  uint16_t*           AF_ptr; //pointer to adaptation field
  uint8_t*            PES_ptr; //pointer to payload
  uint8_t*            data_ptr;
  uint16_t            pesBytesLeft;
  uint8_t             tsBytesLeft;
  bool                isAssembling;

  while(!std::feof(fp))
  {
    tsBytesLeft = 188; //length of one TS packet
    fread(TS_PacketBuffer, 1, BUFFER_SIZE, fp);
    TS_PacketHeader.Reset();
    AF_ptr = TS_PacketHeader.Parse(TS_PacketBuffer);
    tsBytesLeft-=4; //length of header
    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();

    if (TS_PacketHeader.hasAdaptationField())
    {
      TS_AdaptationField.Reset();
      PES_ptr = TS_AdaptationField.Parse(AF_ptr);
      tsBytesLeft -= TS_AdaptationField.getAFLength();
      TS_AdaptationField.Print();
    }
    else{
      PES_ptr = (uint8_t*)AF_ptr;
    }

    if (TS_PacketHeader.beginsPayload() && TS_PacketHeader.getPID() == 136)
    {
      pesPacketHeader.Reset();
      PES_ptr = pesPacketHeader.Parse(PES_ptr);
      pesPacketHeader.Print();
      tsBytesLeft -= (9 + pesPacketHeader.getPESHL()); //9 bytes of header + optional data
      pesBytesLeft = pesPacketHeader.getPES_LEN() - tsBytesLeft;
      isAssembling = true;
      pesAssembler.absorbPacket(output, PES_ptr, tsBytesLeft);
    } 

    else if (isAssembling && TS_PacketHeader.getPID() == 136)
    {
      pesAssembler.absorbPacket(output, PES_ptr, tsBytesLeft);
      pesBytesLeft -= tsBytesLeft;
      if(pesBytesLeft == 0) isAssembling = false;
      pesAssembler.printStatus(pesBytesLeft);
      pesAssembler.lastCC = TS_PacketHeader.getCC();
    }  

    printf("\n");
    TS_PacketId++;
  }


  fclose(fp);
  fclose(output);

  return EXIT_SUCCESS;
}


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

    if (TS_PacketHeader.beginsPayload() && TS_PacketHeader.getPID() == 136)
    {
      pesPacketHeader.Reset();
      data_ptr = pesPacketHeader.Parse(PES_ptr);
      pesPacketHeader.Print();
      tsBytesLeft -= (9 + pesPacketHeader.getPESHL()); //9 bytes of header + optional data
      pesBytesLeft = pesPacketHeader.getPES_LEN() - tsBytesLeft;
      isAssembling = true;
      pesAssembler.lastCC = TS_PacketHeader.getCC();
    }

    else if (isAssembling && TS_PacketHeader.getPID() == 136)
    {
      pesAssembler.absorbPacket(pesBytesLeft, tsBytesLeft, TS_PacketHeader.getCC());
      pesBytesLeft -= tsBytesLeft;
      pesAssembler.printStatus(pesBytesLeft);
    }

    printf("\n");
    TS_PacketId++;
  }


  fclose(fp);

  return EXIT_SUCCESS;
}


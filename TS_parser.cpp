#include "tsCommon.h"
#include "tsPacketHeader.h"
#include "tsAdaptationField.h"
#include "pesPacketHeader.h"
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

  uint8_t             BUFFER_SIZE = 188;
  uint8_t             TS_PacketBuffer[BUFFER_SIZE];
  int32_t             TS_PacketId = 0;
  uint16_t*           AF_ptr;
  uint8_t*            PES_ptr;

  while(!std::feof(fp))
  {
    fread(TS_PacketBuffer, 1, BUFFER_SIZE, fp);
    TS_PacketHeader.Reset();
    AF_ptr = TS_PacketHeader.Parse(TS_PacketBuffer);
    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();

    if (TS_PacketHeader.hasAdaptationField())
    {
      TS_AdaptationField.Reset();
      PES_ptr = TS_AdaptationField.Parse(AF_ptr);
      TS_AdaptationField.Print();
    }

    if (TS_PacketHeader.beginsPayload() && TS_PacketHeader.getPID() == 136)
    {
      pesPacketHeader.Reset();
      pesPacketHeader.Parse(PES_ptr);
      pesPacketHeader.Print();
    }

    printf("\n");

    TS_PacketId++;
  }
  fclose(fp);

  return EXIT_SUCCESS;
}


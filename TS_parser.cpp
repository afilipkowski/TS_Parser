#include "tsCommon.h"
#include "tsTransportStream.h"
//=============================================================================================================================================================================

int main(int argc, char *argv[ ], char *envp[ ])
{
  // TODO - open file
  FILE* fp = std::fopen("../example_new.ts", "rb");
  // TODO - check if file if opened
  if (!fp)
  {
    std::perror("File opening failed");
    return EXIT_FAILURE;
  }
  xTS_PacketHeader    TS_PacketHeader;
  xTS_AdaptationField TS_AdaptationField;

  uint8_t             BUFFER_SIZE = 188;
  uint8_t             TS_PacketBuffer[BUFFER_SIZE];
  int32_t             TS_PacketId = 0;
  uint8_t             AFC;
  uint16_t*           AF_ptr;

  while(!std::feof(fp))
  {
    // TODO - read from file
    fread(TS_PacketBuffer, 1, 188, fp);
    TS_PacketHeader.Reset();
    AF_ptr = TS_PacketHeader.Parse(TS_PacketBuffer);
    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();
    AFC = TS_PacketHeader.getAFC();
    if (AFC == 2 || AFC == 3)
    {
      TS_AdaptationField.Reset();
      TS_AdaptationField.Parse(AF_ptr);
      TS_AdaptationField.Print();
    }
    printf("\n");

    TS_PacketId++;
  }
  
  // TODO - close file
  fclose(fp);

  return EXIT_SUCCESS;
}

//=============================================================================================================================================================================

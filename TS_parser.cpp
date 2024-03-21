#include "tsCommon.h"
#include "tsTransportStream.h"
#include <iostream>
#include <typeinfo>
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

  uint8_t             BUFFER_SIZE = 188;
  uint8_t             TS_PacketBuffer[BUFFER_SIZE];
  int32_t             TS_PacketId = 0;

  while(!std::feof(fp))
  {
    // TODO - read from file
    size_t readBytes = fread(TS_PacketBuffer, 1, 188, fp);
    TS_PacketHeader.Reset();
    TS_PacketHeader.Parse(TS_PacketBuffer);
    printf("%010d ", TS_PacketId);
    TS_PacketHeader.Print();
    printf("\n");

    TS_PacketId++;
  }
  
  // TODO - close file
  fclose(fp);

  return EXIT_SUCCESS;
}

//=============================================================================================================================================================================

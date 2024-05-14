#include "tsAdaptationField.h"

void TS_AdaptationField::Reset()
{
  AFL =  0;
  DC  =  0;
  RA  =  0;
  SP  =  0;
  PR  =  0;
  OR  =  0;
  SF  =  0;
  TP  =  0;
  EX  =  0;
}

uint8_t* TS_AdaptationField::Parse(const uint16_t* Input)
{
  uint16_t AF       =    xSwapBytes16(*Input);
  uint16_t AFL_Mask =    0b1111111100000000;
  AFL               =    ((AF bitand AFL_Mask) >> 8)+1;
  DC                =    (AF >> 7) bitand 1;
  RA                =    (AF >> 6) bitand 1;
  SP                =    (AF >> 5) bitand 1;
  PR                =    (AF >> 4) bitand 1;
  OR                =    (AF >> 3) bitand 1;
  SF                =    (AF >> 2) bitand 1;
  TP                =    (AF >> 1) bitand 1;
  EX                =    AF bitand 1;

  uint8_t* passPtr = (uint8_t*)Input; //cast pointer back to 8bit in order to move within single bytes
  passPtr += AFL; //move the pointer past the adaptation field to start accessing payload

  return passPtr;
}

void TS_AdaptationField::Print() const
{
  printf("\n\t");
  printf("\033[0;31m");
  printf("AF:");
  printf(" AFL=%d", AFL);
  printf(" DC=%d", DC);
  printf(" RA=%d", RA);
  printf(" SP=%d", SP);
  printf(" PR=%d", PR);
  printf(" OR=%d", OR);
  printf(" SF=%d", SF);
  printf(" TP=%d", TP);
  printf(" EX=%d", EX);
  printf("\033[0m");
}
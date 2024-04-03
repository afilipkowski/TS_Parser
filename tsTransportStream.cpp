#include "tsTransportStream.h"

//=============================================================================================================================================================================
// xTS_PacketHeader
//=============================================================================================================================================================================


/// @brief Reset - reset all TS packet header fields
void xTS_PacketHeader::Reset()
{
  SB  =   0;
  E   =   0;
  S   =   0;
  T   =   0;
  PID =   0;
  TSC =   0;
  AFC =   0;
  CC  =   0;
}

uint16_t* xTS_PacketHeader::Parse(const uint8_t* Input)
{
  uint32_t* H_ptr      =   (uint32_t*) Input;
  uint32_t  H_val      =   xSwapBytes32(*H_ptr);

  uint32_t  E_mask     =   0b00000000100000000000000000000000;
  uint32_t  S_mask     =   0b00000000010000000000000000000000;
  uint32_t  T_mask     =   0b00000000001000000000000000000000;
  uint32_t  PID_mask   =   0b00000000000111111111111100000000;
  uint32_t  TSC_mask   =   0b00000000000000000000000011000000;
  uint32_t  AFC_mask   =   0b00000000000000000000000000110000;
  uint32_t  CC_mask    =   0b00000000000000000000000000001111;

  SB                   =   H_val >> 24;                 
  E                    =   (H_val bitand E_mask)  >> 23;
  S                    =   (H_val bitand S_mask)  >> 22;
  T                    =   (H_val bitand T_mask)  >> 21;
  PID                  =   (H_val bitand PID_mask)>>  8;
  TSC                  =   (H_val bitand TSC_mask)>>  6;
  AFC                  =   (H_val bitand AFC_mask)>>  4;
  CC                   =   H_val bitand CC_mask;

  H_ptr++;
  return (uint16_t*)H_ptr;
  
}

void xTS_PacketHeader::Print() const
{
  printf(" SB=%d", SB);
  printf(" E=%d", E);
  printf(" S=%d", S);
  printf(" T=%d", T);
  printf(" PID=%d", PID);
  printf(" TSC=%d", TSC);
  printf(" AFC=%d", AFC);
  printf(" CC=%d", CC);
}

//=============================================================================================================================================================================
// xTS_AdaptationField
//=============================================================================================================================================================================

void xTS_AdaptationField::Reset()
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

void xTS_AdaptationField::Parse(const uint16_t* Input)
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
}

void xTS_AdaptationField::Print() const
{
  printf("\033[0;31m");
  printf(" AFL=%d", AFL);
  printf(" DC=%d", DC);
  printf(" RA=%d", RA);
  printf(" SP=%d", SP);
  printf(" PR=%d", PR);
  printf(" OR=%d", OR);
  printf(" SF=%d", SF);
  printf(" EX=%d", EX);
  printf("\033[0m");

}
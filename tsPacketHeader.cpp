#include "tsPacketHeader.h"

void TS_PacketHeader::Reset()
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

uint16_t* TS_PacketHeader::Parse(const uint8_t* Input)
{
  uint32_t* H_ptr      =   (uint32_t*) Input; //32bits - 4bytes - length of header
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
  return (uint16_t*)H_ptr; //for convenience in reading AF fields
  
}

void TS_PacketHeader::Print() const
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
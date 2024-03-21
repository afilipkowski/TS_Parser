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

/**
  @brief Parse all TS packet header fields
  @param Input is pointer to buffer containing TS packet
  @return Number of parsed bytes (4 on success, -1 on failure) 
 */
int32_t xTS_PacketHeader::Parse(const uint8_t* Input)
{
  uint8_t   b_count    =   0; 
  uint32_t* H_ptr      =   (uint32_t*) Input;
  uint32_t  H_val      =   xSwapBytes32(*H_ptr);

  uint32_t  E_mask     =   0b00000000100000000000000000000000;
  uint32_t  S_mask     =   0b00000000010000000000000000000000;
  uint32_t  T_mask     =   0b00000000001000000000000000000000;
  uint32_t  PID_mask   =   0b00000000000111111111111100000000;
  uint32_t  TSC_mask   =   0b00000000000000000000000011000000;
  uint32_t  AFC_mask   =   0b00000000000000000000000000110000;
  uint32_t  CC_mask    =   0b00000000000000000000000000001111;

  SB                   =   H_val >> 24;                             if(SB)   b_count++;
  E                    =   H_val bitand E_mask;     E =   E  >> 23; if(E)    b_count++;
  S                    =   H_val bitand S_mask;     S =   S  >> 22; if(S)    b_count++;
  T                    =   H_val bitand T_mask;     T =   T  >> 21; if(T)    b_count++;
  PID                  =   H_val bitand PID_mask; PID = PID  >>  8; if(PID)  b_count++;
  TSC                  =   H_val bitand TSC_mask; TSC = TSC  >>  6; if(TSC); b_count++;
  AFC                  =   H_val bitand AFC_mask; AFC = AFC  >>  4; if(AFC); b_count++;
  CC                   =   H_val bitand CC_mask;                    if(CC);   b_count++;

  
  if (b_count==4) return b_count; else return -1;
  
}

/// @brief Print all TS packet header fields
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

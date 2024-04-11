#pragma once
#include "tsCommon.h"

class xTS_AdaptationField
{
protected:
  uint8_t  AFL;
  uint8_t  DC;
  uint8_t  RA;
  uint8_t  SP;
  uint8_t  PR;
  uint8_t  OR;
  uint8_t  SF;
  uint8_t  TP;
  uint8_t  EX;

public:
  void     Reset();
  void     Parse(const uint16_t* Input);
  void     Print() const;

};
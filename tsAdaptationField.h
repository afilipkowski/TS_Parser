#pragma once
#include "tsCommon.h"

class TS_AdaptationField
{
protected:
  uint8_t  AFL; //length (in bytes) AFL + 1; max. 184 B (no payload)
  uint8_t  DC;
  uint8_t  RA;
  uint8_t  SP;
  uint8_t  PR;
  uint8_t  OR;
  uint8_t  SF;
  uint8_t  TP;
  uint8_t  EX;

public:
  void         Reset();
  uint8_t*     Parse(const uint16_t* Input);
  void         Print() const;


public:
  uint8_t  getAFLength() const { return AFL; }
  uint8_t  getPCRFlag() const { return PR; }
  uint8_t  getOPCRFlag() const { return OR; }
};
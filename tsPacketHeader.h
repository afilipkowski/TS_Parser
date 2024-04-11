#pragma once
#include "tsCommon.h"

class xTS_PacketHeader
{
public:
  enum class ePID : uint16_t
  {
    PAT  = 0x0000,
    CAT  = 0x0001,
    TSDT = 0x0002,
    IPMT = 0x0003,
    NIT  = 0x0010, //DVB specific PID
    SDT  = 0x0011, //DVB specific PID
    NuLL = 0x1FFF,
  };

protected:
  uint8_t  SB;
  uint8_t  E;
  uint8_t  S;
  uint8_t  T;
  uint16_t PID;
  uint8_t  TSC;
  uint8_t  AFC;
  uint8_t  CC;

public:
  void     Reset();
  uint16_t* Parse(const uint8_t* Input);
  void     Print() const;

public:
  uint8_t  getSyncByte() const { return SB; }
  uint8_t  geteErrorIndicator() const { return E; }
  uint8_t  getPayloadIndicator() const { return S; }
  uint8_t  getTransportPriority() const { return T; }
  uint8_t  getPID() const { return PID; }
  uint8_t  getTSC() const { return TSC; }
  uint8_t  getAFC() const { return AFC; }
  uint8_t  getCC() const { return CC; }  

public:
  bool     hasAdaptationField() const { if (AFC == 2 || AFC == 3) return true; else return false;}
  bool     hasPayload        () const { if (AFC == 3 || AFC == 1) return true; else return false;}
};
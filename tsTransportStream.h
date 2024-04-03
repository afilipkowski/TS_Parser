#pragma once
#include "tsCommon.h"
#include<string>
//=============================================================================================================================================================================

class xTS
{
public:
  static constexpr uint32_t TS_PacketLength  = 188;
  static constexpr uint32_t TS_HeaderLength  = 4;

  static constexpr uint32_t PES_HeaderLength = 6;

  static constexpr uint32_t BaseClockFrequency_Hz         =    90000; //Hz
  static constexpr uint32_t ExtendedClockFrequency_Hz     = 27000000; //Hz
  static constexpr uint32_t BaseClockFrequency_kHz        =       90; //kHz
  static constexpr uint32_t ExtendedClockFrequency_kHz    =    27000; //kHz
  static constexpr uint32_t BaseToExtendedClockMultiplier =      300;
};

//=============================================================================================================================================================================

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
  //TODO - derrived informations
  //bool     hasAdaptationField() const { /*TODO*/ }
  //bool     hasPayload        () const { /*TODO*/ }
};

//=============================================================================================================================================================================

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
#include <iostream>
#include "if/supported_if.h"

void DoWork1(If& i)
{
  std::cout << "Doing work package - 1" << std::endl;
  SBBus s(SBBus::GET_DIAG_MUX_MONITOR);
  TypGetter<SBBus, SBBus::CGetDiagMuxMonitor> tp(s);

  tp().ip.iSegment = 111;
  tp().ip.iDeviceAdr = 222;
  tp().ip.iCommand = 333;
  i.Process(s);
  std::cout << "Result after processing: Value = " << tp().op.Value << ", Result= " << tp().op.Result << std::endl;
}

void DoWork2(If& i)
{
  std::cout << "Doing work package - 2" << std::endl;

  I2CCom s(I2CCom::WRITE_EEPROM_MONITOR);
  TypGetter<I2CCom, I2CCom::CWriteEeprom> tp(s);

  tp().ip.iSegment = 666;
  tp().ip.iDeviceAdr = 777;
  tp().ip.iCommand = 888;
  i.Process(s);
  std::cout << "Result = " << tp().op.Result << std::endl;
}

extern If* GetIfImpl();

int main()
{
  std::cout << "############### APP1 ##################" << std::endl;
  If* i = GetIfImpl();
  DoWork1(*i);
  DoWork2(*i);
  return 0;
}



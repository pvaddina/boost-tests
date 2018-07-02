#include <iostream>
#include "if/supported_if.h"

void DoWork1(If& i)
{
  std::cout << "Doing work package - 1" << std::endl;
  SBBus s(SBBus::GET_ACCU_CONTROLLER);
  TypGetter<SBBus, SBBus::CGetAccuController> tp(s);

  tp().ip.iSegment = 1001;
  tp().ip.iDeviceAdr = 1002;
  tp().ip.iCommand = 1003;
  i.Process(s);
  std::cout << "Result after processing: Value = " << tp().op.Value << ", Result= " << tp().op.Result << std::endl;
}

void DoWork2(If& i)
{
  std::cout << "Doing work package - 2" << std::endl;

  I2CCom s(I2CCom::READ_GPIO_CONTROLLER);
  TypGetter<I2CCom, I2CCom::CReadGpioController> tp(s);
  tp().ip.iSegment = 1005;
  tp().ip.iDeviceAdr = 1006;
  tp().ip.iCommand = 1007;
  i.Process(s);
  std::cout << "Result after processing: Value = " << tp().op.Value << ", Result= " << tp().op.Result << std::endl;
}

extern If* GetIfImpl();

int main()
{
  std::cout << "############### APP2 ##################" << std::endl;
  If* i = GetIfImpl();
  DoWork1(*i);
  DoWork2(*i);
  return 0;
}



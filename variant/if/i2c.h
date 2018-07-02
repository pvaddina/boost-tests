#pragma once

#include "def.h"
#include "boost/variant.hpp"
#include <vector>

class I2CCom
{
  private:
    struct SegAddr
    {
      int iSegment;
      int iDeviceAdr;
      int iCommand;
    };

    struct ReadResult
    {
      int Value;
      int Result;
    };

    struct WriteResult
    {
      int Result;
      std::vector<int> mulResults;
    };

  public:
    enum Action
    {
      READ_EEPROM_MONITOR,
      WRITE_EEPROM_MONITOR,
      READ_PWR_CTRL_CONTROLLER,
      WRITE_PWR_CTRL_CONTROLLER,
      READ_GPIO_CONTROLLER,
      WRITE_GPIO_CONTROLLER
    };

    typedef msg<READ_EEPROM_MONITOR, SegAddr, ReadResult>         CReadEeprom;
    typedef msg<WRITE_EEPROM_MONITOR, SegAddr, WriteResult>       CWriteEeprom;
    typedef msg<READ_PWR_CTRL_CONTROLLER, SegAddr, ReadResult>    CReadPwrController;
    typedef msg<WRITE_PWR_CTRL_CONTROLLER, SegAddr, WriteResult>  CWritePwrController;
    typedef msg<READ_GPIO_CONTROLLER, SegAddr, ReadResult>        CReadGpioController;
    typedef msg<WRITE_GPIO_CONTROLLER, SegAddr, WriteResult>      CWriteGpioController;

    typedef boost::variant< CReadEeprom
                          , CWriteEeprom
                          , CReadPwrController
                          , CWritePwrController
                          , CReadGpioController
                          , CWriteGpioController > I2CVar;

    I2CCom(const Action a)
    {
      if      (a == READ_EEPROM_MONITOR)        { m = CReadEeprom();          }
      else if (a == READ_PWR_CTRL_CONTROLLER)   { m = CReadPwrController();   }
      else if (a == WRITE_EEPROM_MONITOR)       { m = CWriteEeprom();         }
      else if (a == WRITE_PWR_CTRL_CONTROLLER)  { m = CWritePwrController();  }
      else if (a == READ_GPIO_CONTROLLER)       { m = CReadGpioController();  }
      else if (a == WRITE_GPIO_CONTROLLER)      { m = CWriteGpioController(); }
    }

    I2CVar& operator()() { return m; }
private:
    I2CVar m;
};



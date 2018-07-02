#include <boost/variant.hpp>
#include <iostream>

#include "if/supported_if.h"
#include "if/sb.h"
#include "if/i2c.h"

class ActualImplementation : public boost::static_visitor<>
{
  public:
    void operator()(SBBus::CGetDiagMuxMonitor& msg)
    {
      std::cout << "Incoming message configuration: "
                << "iSegment = "   << msg.ip.iSegment   << " - "
                << "iDeviceAdr = " << msg.ip.iDeviceAdr << " - "
                << "iCommand = "   << msg.ip.iCommand   << std::endl;

      msg.op.Value = 444;
      msg.op.Result = 555;
    }

    void operator()(SBBus::CSetDiagMuxMonitor& msg)
    {
    }

    void operator()(SBBus::CGetAlarmRegController& msg)
    {
    }

    void operator()(SBBus::CSetAlarmRegController& msg)
    {
    }

    void operator()(SBBus::CGetAccuController& msg)
    {
      std::cout << "Incoming message configuration: "
                << "iSegment = "   << msg.ip.iSegment   << " - "
                << "iDeviceAdr = " << msg.ip.iDeviceAdr << " - "
                << "iCommand = "   << msg.ip.iCommand   << std::endl;

      msg.op.Result = 1004;
    }

    void operator()(SBBus::CSetAccuController& msg)
    {
    }

    void operator()(I2CCom::CReadEeprom& msg)
    {
    }

    void operator()(I2CCom::CWriteEeprom& msg)
    {
      std::cout << "Incoming message configuration: "
                << "iSegment = " << msg.ip.iSegment << " - "
                << "iDeviceAdr = " << msg.ip.iDeviceAdr << " - "
                << "iCommand = " << msg.ip.iCommand << std::endl;

      msg.op.Result = 999;
    }

    void operator()(I2CCom::CReadPwrController& msg)
    {
    }

    void operator()(I2CCom::CWritePwrController& msg)
    {
    }

    void operator()(I2CCom::CReadGpioController& msg)
    {
      std::cout << "Incoming message configuration: "
                << "iSegment = " << msg.ip.iSegment << " - "
                << "iDeviceAdr = " << msg.ip.iDeviceAdr << " - "
                << "iCommand = " << msg.ip.iCommand << std::endl;

      msg.op.Value = 1008;
      msg.op.Result = 1009;
    }

    void operator()(I2CCom::CWriteGpioController& msg)
    {
    }
};


class IfImpl : public If
{
  public:
    IfImpl(ActualImplementation* a) : mA(a) {}
    ~IfImpl() { delete mA; }

    virtual void Process(I2CCom& msg)
    {
      boost::apply_visitor(*mA, msg());
    }
    virtual void Process(SBBus& msg)
    {
      boost::apply_visitor(*mA, msg());
    }

  private:
    ActualImplementation* mA;
};


If* GetIfImpl()
{
  return new IfImpl(new ActualImplementation);
}


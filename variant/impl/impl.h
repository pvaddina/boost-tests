#if 0


#include "if/supported_if.h"
#include <boost/variant.hpp>

class ActualHandler;
class I2CCom;
class SBBus;

class IfImpl : public If
{
  public:
    IfImpl(ActualHandler& a) : mA(a) {}
    static IfImpl* GetIfImpl();

    virtual void Process(I2CCom& msg)
    {
      boost::apply_visitor(mA, msg);
    }
    virtual void Process(SBBus& msg)
    {
      boost::apply_visitor(mA, msg);
    }

  private:
    ActualHandler& mA;
};

#endif

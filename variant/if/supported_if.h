#pragma once

#include "i2c.h"
#include "sb.h"

class If
{
  public:
    virtual void Process(I2CCom&) = 0;
    virtual void Process(SBBus&) = 0;
};


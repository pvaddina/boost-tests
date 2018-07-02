#pragma once

#include "def.h"
#include "boost/variant.hpp"

class SBBus
{
  private:
    struct SegAddr
    {
      int iSegment;
      int iDeviceAdr;
      int iCommand;
    };

    struct GetResult
    {
      int Value;
      int Result;
    };

    struct SetResult
    {
      int Result;
    };

    struct SetNameResult
    {
      int Result;
    };

  public:
    enum Action
    {
      GET_DIAG_MUX_MONITOR,
      GET_ALARM_REG_CONTROLLER,
      SET_DIAG_MUX_MONITOR,
      SET_ALARM_REG_CONTROLLER,
      GET_ACCU_CONTROLLER,
      SET_ACCU_CONTROLLER
    };

    typedef msg<GET_DIAG_MUX_MONITOR, SegAddr, GetResult>     CGetDiagMuxMonitor;
    typedef msg<SET_DIAG_MUX_MONITOR, SegAddr, SetResult>     CSetDiagMuxMonitor;
    typedef msg<GET_ALARM_REG_CONTROLLER, SegAddr, GetResult> CGetAlarmRegController;
    typedef msg<SET_ALARM_REG_CONTROLLER, SegAddr, SetResult> CSetAlarmRegController;
    typedef msg<GET_ACCU_CONTROLLER, SegAddr, GetResult>      CGetAccuController;
    typedef msg<SET_ACCU_CONTROLLER, SegAddr, SetResult>      CSetAccuController;

    SBBus(const Action a)
    {
      if      (a == GET_DIAG_MUX_MONITOR)     { m = CGetDiagMuxMonitor();     }
      else if (a == SET_DIAG_MUX_MONITOR)     { m = CSetDiagMuxMonitor();     }
      else if (a == GET_ALARM_REG_CONTROLLER) { m = CGetAlarmRegController(); }
      else if (a == SET_ALARM_REG_CONTROLLER) { m = CSetAlarmRegController(); }
      else if (a == GET_ACCU_CONTROLLER)      { m = CGetAccuController();     }
      else if (a == SET_ACCU_CONTROLLER)      { m = CSetAccuController();     }
    }

    typedef boost::variant< CGetDiagMuxMonitor
                          , CSetDiagMuxMonitor
                          , CGetAlarmRegController
                          , CSetAlarmRegController
                          , CGetAccuController
                          , CSetAccuController > SBBusVar;

    SBBusVar& operator()() { return m; }
  private:
    SBBusVar m;
};



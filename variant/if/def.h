#pragma once

#include "boost/variant/get.hpp"

template <int ACTION, typename IP, typename OP>
struct msg
{
  typedef msg<ACTION, IP, OP> THIS_MSG;
  IP ip;
  OP op;
  msg() : ip(), op() {}
};


template <typename MsgHolder, typename TargetTyp>
struct TypGetter
{
  TypGetter(MsgHolder& m)
    : var(boost::get<TargetTyp>(m())) {}
  TargetTyp& operator()() { return var; }
private:
  TargetTyp& var;
};




#ifndef AbstractHMI_h
#define AbstractHMI_h

#include "Arduino.h"

class AbstractHMI
{
  public:
    virtual void begin() = 0;
    virtual bool read() = 0;
    virtual bool stateChanged() = 0;
    virtual void forceUpdate() = 0;
};

#endif
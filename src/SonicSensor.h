#ifndef SonicSensor_h
#define SonicSensor_h

#include "Arduino.h"


class SonicSensor
{
public:
  SonicSensor(int, int);
  void setDebounce(int);
  int getDebounce();

  int getDistance();

  void setMinimumDistance(int);
  int getMinimumDistance();
  void setMaximumDistance(int);
  int getMaximumDistance();

private:
  int _min, _max;
  int _debounce;
  int _trig, _echo;
  int _lastDistance;
  unsigned long _lastChecked;
};

#endif

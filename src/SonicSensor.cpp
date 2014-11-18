#include "SonicSensor.h"

SonicSensor::SonicSensor(int trigPin, int echoPin)
{
  _trig = trigPin;
  _echo = echoPin;
  _debounce = 300;
  _min = 2;
  _max = 200;
  _lastDistance = 0;
  pinMode(_trig, OUTPUT);
  digitalWrite(_trig, LOW);
  pinMode(_echo, INPUT);
}

void SonicSensor::setDebounce(int ms){
  _debounce = ms;
}

int SonicSensor::getDebounce(){
  return _debounce;
}

int SonicSensor::getDistance(){
  unsigned long tmpCheck;
  if (!_lastDistance || ((tmpCheck=millis()) - _lastChecked > _debounce)){
    digitalWrite(_trig, HIGH);
    delayMicroseconds(10000);
    digitalWrite(_trig, LOW);
    unsigned int duration = pulseIn(_echo, HIGH); // microSecs
    _lastDistance = (duration/2)/29.1; // cm?
    _lastChecked = tmpCheck;
    if (_lastDistance < _min){
      _lastDistance = _min;
    }else if(_lastDistance > _max){
      _lastDistance = _max;
    }
  }
  return _lastDistance;
}


void SonicSensor::setMinimumDistance(int min){
  _min = min;
}

int SonicSensor::getMinimumDistance(){
  return _min;
}

void SonicSensor::setMaximumDistance(int max){
  _max = max;
}

int SonicSensor::getMaximumDistance(){
  return _max;
}

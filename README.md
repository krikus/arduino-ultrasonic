arduino-ultrasonic
==================

Library for arduino that provides interface to communicate with HS-SR04 compatybile ultrasonic sensor.

Distance is provided in centimeters.


==================

For start you need to create new object using `SonicSensor uss = SonicSensor(trigger_pin, echo_pin)`.

Constructor is defined as follows: `SonicSensor(int, int)`.


Following public methods are provided:

`void setDebounce(int)` // set debounce - how much time must pass (in ms) before we can send ultrasonic beam to measure distance.

`int getDebounce()` // get debounce (ms) [default 300ms]

`int getDistance()` // gets distance to object in centimeters. It returns old distance if debounce time has not passed

`void setMinimumDistance(int)` // sets minimum distance (in centimeters) [default 2cm]

`int getMinimumDistance()` // gets minimum distance (in centimeters)

`void setMaximumDistance(int)` // sets maximum distance (in centimeters) [default 200cm]

`int getMaximumDistance()`  // gets maximum distance (in centimeters)

===================
Please see example for more information.

// GEO Cookstove Sensor Code
// C.O.N.D.O.R.S. 2020-2021
// Arduino code for the cookstove sensor.
// CO.h
// This file contains the CO sensor library, including the pin numbers and other necessary variables
// We received most of this code for the CO sensor by an SPEC sensor representative


#ifndef CO_H
#define CO_H

#include <Arduino.h>
#include <String.h>
#include <Adafruit_SCD30.h>

class CO {
  public:
    int vgas = 0; //Analog pin, Pin #1 on sensor (this is the pin that we use to get the CO reading. use analogRead(vgas); )
    int vtemp = 1; //Analog pin, temperature sensor for CO (we haven't been using this)

    // variables used in the measure function
    double Vavg = 0;
    double result = 0;

    // function that returns one CO raw measurement
    double measure();
};

#endif //CO_H

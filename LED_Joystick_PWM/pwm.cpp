#include "pwm.h"

AK_PWM(int pin, int percentup) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
    _percentup = percentup; 
}

void AK_PWM::setPeriod(int percentup) {
   _percentup = percentup; 
}



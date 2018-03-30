#pragma once

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__)
  #define DUALMAX14870MOTORSHIELD_USE_20KHZ_PWM
#endif

#include <Arduino.h>

class DualMAX14870MotorShield
{
  public:
    DualMAX14870MotorShield();
    DualMAX14870MotorShield(uint8_t M1DIR, uint8_t M2DIR, uint8_t nEN,
      uint8_t nFAULT);

    void setM1Speed(int speed);
    void setM2Speed(int speed);
    void setSpeeds(int m1Speed, int m2Speed);
    void flipM1(bool flip);
    void flipM2(bool flip);
    bool getFault();
    void enableDrivers();
    void disableDrivers();

  private:
    void initPinsAndMaybeTimer();

    uint8_t _nEN;
    uint8_t _M1DIR;
    uint8_t _M2DIR;
    static const uint8_t _M1PWM = 9;
    static const uint8_t _M2PWM = 10;
    uint8_t _nFAULT;

    bool _flipM1 = false;
    bool _flipM2 = false;

    bool initialized = false;

    inline void init()
    {
      if (!initialized)
      {
        initialized = true;
        initPinsAndMaybeTimer();
      }
    }
};
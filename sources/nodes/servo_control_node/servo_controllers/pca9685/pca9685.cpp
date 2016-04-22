#include "pca9685.h"
#include "pca9685_registers.h"

namespace
{
    const float dutyMin = 3;
    const float dutyMax = 14.5;
    const float dutySpan = dutyMax - dutyMin;
}

using namespace devices;

Pca9685::Pca9685(const char* filename):
    I2cDevice(filename)
{}

bool Pca9685::start()
{
    if (!I2cDevice::start()) return false;

    this->reset();
    this->setFrequency(1000); // to settings

    return true;
}

uint8_t Pca9685::i2cAddress() const
{
    return ALLCALLADR;
}

bool Pca9685::checkDevicePresent()
{
    return true; //TODO: this->i2cRead(WHO_AM_I) == 0xC4;
}

void Pca9685::reset()
{
    this->i2cWrite(MODE1, 0x01); // Normal mode FIXME: check 0x00
    this->i2cWrite(MODE2, 0x04); // Totem pole
}

void Pca9685::setFrequency(float frequency)
{
    uint8_t prescaledFrequency = (CLOCK_FREQ / 4096 / frequency) - 1;
    this->i2cWrite(MODE1, 0x10); // Sleep
    this->i2cWrite(PRE_SCALE, prescaledFrequency); // Multiplyer for PWM frequency
    this->i2cWrite(MODE1, 0x80); // Restart
    this->i2cWrite(MODE2, 0x04); // Totem pole
}

void Pca9685::setPwm(uint8_t channel, int value)
{
    this->setPwm(channel, 0, value);
}

void Pca9685::setPwm(uint8_t channel, int onValue, int offValue)
{
    this->i2cWrite(LED0_ON_L + LED_MULTIPLYER * (channel - 1), onValue & 0xFF);
    this->i2cWrite(LED0_ON_H + LED_MULTIPLYER * (channel - 1), onValue >> 8);
    this->i2cWrite(LED0_OFF_L + LED_MULTIPLYER * (channel - 1), offValue & 0xFF);
    this->i2cWrite(LED0_OFF_H + LED_MULTIPLYER * (channel - 1), offValue >> 8);
}

int Pca9685::pwm(uint8_t channel)
{
    int value = this->i2cRead(LED0_OFF_H + LED_MULTIPLYER * (channel - 1));
    value = value & 0xf;
    value <<= 8;
    value += this->i2cRead(LED0_OFF_L + LED_MULTIPLYER * (channel - 1));
    return value;
}

void Pca9685::init()
{
    if (this->isStarted()) this->stop();
    this->start();
}

bool Pca9685::checkAvalible()
{
    return (this->isStarted() && this->checkDevicePresent());
}

void Pca9685::setAngle(uint8_t channel, float angle)
{
    //FIXME: angle to pwm correct calculation
    int duty = 100 - (angle / 180) * ::dutySpan + ::dutyMin;
    this->setPwm(channel, duty);
}

float Pca9685::angle(uint8_t channel) const
{
    // FIXME: angle
    return 0;
}

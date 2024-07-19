#include <Arduino.h>

#include "Log.h"

Log::Log(HardwareSerial *serial)
    : serial(serial),
      prefix(nullptr)
{
  //
}

Log &Log::setPrefix(const char *prefix)
{
  this->prefix = prefix;

  return *this;
}

void Log::begin(unsigned long baud)
{
  this->serial->begin(baud);
}

void Log::end()
{
  this->serial->end();
}

size_t Log::print(const char str[])
{
  this->printPrefix(Level::LOG);

  this->isLineEnded = false;

  return this->serial->print(str);
}

size_t Log::println(const char str[])
{
  this->printPrefix(Level::LOG);

  this->isLineEnded = true;

  return this->serial->println(str);
}

size_t Log::println(unsigned long num, int base)
{
  this->printPrefix(Level::LOG);

  this->isLineEnded = true;

  return this->serial->println(num, base);
}

size_t Log::println(double num, int digits)
{
  this->printPrefix(Level::LOG);

  this->isLineEnded = true;

  return this->serial->println(num, digits);
}

size_t Log::println(long long num, int base)
{
  this->printPrefix(Level::LOG);

  this->isLineEnded = true;

  return this->serial->println((long)num, base);
}

size_t Log::warnln(const char str[])
{
  this->printPrefix(Level::WARN);

  this->isLineEnded = true;

  return this->serial->println(str);
}

void Log::printPrefix(Level level)
{
  if (!this->isLineEnded)
  {
    return;
  }

  if (this->prefix != nullptr)
  {
    this->serial->print(this->prefix);
  }

  switch (level)
  {
  case Level::ERROR:
    this->serial->print("[ERROR]");
    break;
  case Level::WARN:
    this->serial->print("[WARN]");
    break;
  case Level::LOG:
    this->serial->print("[LOG]");
    break;
  default:
    break;
  }

  this->serial->print(' ');
}

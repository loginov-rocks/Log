#ifndef LOG_H
#define LOG_H

#include <Arduino.h>

// Print.h
#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Log
{
public:
  enum class Level
  {
    ERROR,
    WARN,
    LOG,
  };

  Log(HardwareSerial * = &Serial);
  Log &setLevel(Level);
  Log &setPrefix(const char *);

  // HardwareSerial.h
  void begin(unsigned long baud);
  void end();

  // Print.h
  size_t print(const char *);

  size_t println(const char *);
  size_t println(unsigned long, int = DEC);
  size_t println(double, int = 2);
  size_t println(long long, int = DEC);

  // Custom
  size_t warnln(const char *);

private:
  HardwareSerial *serial;
  Level level = Level::LOG;
  const char *prefix;

  boolean isLineEnded = true;

  void printPrefix(Level);
};

#endif

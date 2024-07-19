#include <Arduino.h>

#include "Log.h"

Log logger;

void setup()
{
  logger.begin(9600);
  logger.println("Hello, world!");
}

void loop()
{
  logger.println("Hello, world!");
  logger.println(12.345, 2);
  logger.println(millis());
}

#include <Arduino.h>
#include <Log.h>

Log logger;
// Log logger(&Serial1);

void setup()
{
  // logger.setLevel(Log::Level::ERROR)
  // logger.setPrefix("[MAIN]");
  logger.begin(9600);
  logger.println("Hello, world!");
  // logger.setPrefix("[LOOP]");
  // logger.warnln("Warning!");
}

void loop()
{
  logger.print("Double: ");
  logger.println(12.3456789, 4);

  delay(1000);

  logger.print("Millis: ");
  logger.println(millis());

  delay(1000);
}

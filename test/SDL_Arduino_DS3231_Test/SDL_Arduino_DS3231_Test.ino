#include "SDL_ARDUINO_DS3231.h"

void setup()
{
  Serial.begin(57600);
}

void loop()
{

  tmElements_t tm;
  float DS3231_Temp;
  RTC.read(tm);
  DS3231_Temp =RTC.get_treg();

  Serial.print("------------------\n");
  Serial.print(" Timestamp DS3231 \n");
  Serial.print("------------------\n");
  Serial.print(tm.Hour);
  Serial.print(":");
  Serial.print(tm.Minute);
  Serial.print(":");
  Serial.print(tm.Second);
  Serial.print(", Date (D/M/Y) = ");
  Serial.print(tm.Day);
  Serial.print('/');
  Serial.print(tm.Month);
  Serial.print('/');
  Serial.print(tmYearToCalendar(tm.Year));
  Serial.println();
  Serial.print("Temperature= ");
  Serial.println(DS3231_Temp); 

  delay(5000);
}

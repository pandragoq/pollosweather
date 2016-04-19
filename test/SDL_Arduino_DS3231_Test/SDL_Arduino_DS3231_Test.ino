#include "SDL_ARDUINO_DS3231.h"

  const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

void printDigits(int digits){
  // utility function for digital clock display: prints an leading 0

  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}

void return2Digits(char returnString[], char *buffer2, int digits)
{
  if(digits < 10)
    sprintf(returnString,"0%i", digits);
  else
    sprintf(returnString,"%i", digits);

  strcpy(returnString, buffer2);


}

void buildTimeString(char returnString[], char *buffer2, tmElements_t convertTime)
{



    char myBuffer[5];
    sprintf(myBuffer,"%i-", tmYearToCalendar(convertTime.Year));
    strcat(returnString, myBuffer);

    return2Digits(myBuffer, myBuffer, convertTime.Month);
    strcat(returnString, myBuffer);
    strcat(returnString, "-");

    return2Digits(myBuffer, myBuffer, convertTime.Day);
    strcat(returnString, myBuffer);
    strcat(returnString, " ");

    return2Digits(myBuffer, myBuffer, convertTime.Hour);
    strcat(returnString, myBuffer);
    strcat(returnString, ":");

    return2Digits(myBuffer, myBuffer, convertTime.Minute);
    strcat(returnString, myBuffer);
    strcat(returnString, ":");

    return2Digits(myBuffer, myBuffer, convertTime.Second);
    strcat(returnString, myBuffer);
}

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

  Serial.println("------------------");
  Serial.println(" Timestamp DS3231 ");
  Serial.println("------------------");
  printDigits(tm.Hour);
  Serial.print(":");
  printDigits(tm.Minute);
  Serial.print(":");
  printDigits(tm.Second);
  Serial.print(", Date (D/M/Y) = ");
  printDigits(tm.Day);
  Serial.print('/');
  printDigits(tm.Month);
  Serial.print('/');
  Serial.print(tmYearToCalendar(tm.Year));
  Serial.println();
  Serial.print("Temperature= ");
  Serial.println(DS3231_Temp); 

  delay(5000);
}

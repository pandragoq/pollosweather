#include "Adafruit_Sensor.h"
#include "Adafruit_BMP085_U.h"

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

/**************************************************************************/
/*
    Displays some basic information on this sensor from the unified
    sensor API sensor_t type (see Adafruit_Sensor for more information)
*/
/**************************************************************************/
void displayBMP180SensorDetails(void)
{
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" hPa");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void setup()
{
  Serial.begin(57600);
  bmp.begin();
}

void loop()
{
  displayBMP180SensorDetails();
  sensors_event_t event;
  float BMP180_Pressure;    // hPa
  float BMP180_Temperature; // C
  float BMP180_Altitude;    // m
  bmp.getEvent(&event);
  if (event.pressure)
  {
    BMP180_Pressure = event.pressure;
    float temperature;
    bmp.getTemperature(&temperature); //Using a local variable so we can keep old value and check.
    BMP180_Temperature = temperature;
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    BMP180_Altitude = bmp.pressureToAltitude(seaLevelPressure, BMP180_Pressure);
  }

  Serial.print("Pressure   : "); Serial.print(BMP180_Pressure); Serial.println(" hPa");
  Serial.print("Temperature: "); Serial.print(BMP180_Temperature); Serial.println(" C");
  Serial.print("Altitude   : "); Serial.print(BMP180_Altitude); Serial.println(" m");
    
    
  delay(5000);
}

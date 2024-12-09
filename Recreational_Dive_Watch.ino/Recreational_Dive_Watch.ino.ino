// displaying BME280 values on LCD Display

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "rgb_lcd.h"
#define SEALEVELPRESSURE_HPA (1013.25)// sets the sea level presure 
#define <PulseSensorPlayground.h>
//delcare sensors
rgb_lcd lcd;
Adafruit_BME280 bme;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int OUTPUT_TYPE = SERIAL_PLOTTER// for using arduino serial plotter 
const int THRESHOLD = 2000// sets the threshold for the analog sample taken by heartrate monitor  


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

  //Serial.begin(9600);
  lcd.print("BME Test");
  bme.begin(0x76);// declare the class bme. 
  Serial.begin(115200);// for heartrate Sensor
  pulseSensor.analogInput(PULSE_INPUT);
  pulseSensor.setSerial(Serial);
  pulseSensor.setOutputType(OUTPUT_TYPE);
  pulseSensor.setThreshold(THRESHOLD);

}

void loop() {
  // put your main code here, to run repeatedly:
 printTemp();
 delay(2000);
 lcd.clear();

 printPress();
 delay(2000);
 lcd.clear();

 printAltit();
 delay(2000);
 lcd.clear();

 printHum();
 delay(2000);
 lcd.clear();
}


 void printTemp(){

  lcd.setCursor(0,1);
  lcd.print("Temperature = ");
  lcd.print(bme.readTemperature());
  lcd.println(" °C");
}

void printPress(){
  lcd.setCursor(0,1);
  lcd.print("Pressure = ");
  lcd.print(bme.readPressure()/ 100.0F);
  lcd.println(" hPa");
 
}
  
void printAltit(){
  lcd.setCursor(0,1);
  lcd.print("Approx. Altitude = ");
  lcd.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  lcd.println(" m");
}

void printHum(){
  lcd.setCursor(0,1);
  lcd.print("Humidity = ");
  lcd.print(bme.readHumidity());
  lcd.println(" %");
  delay(2000);

}

  


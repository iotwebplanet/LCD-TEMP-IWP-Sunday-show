#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 8 on the Arduino
#define ONE_WIRE_BUS 8
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
// Set the LCD address to 0x27 for a 16 chars and 2 line display 0x3F
LiquidCrystal_I2C lcd(0x3F, 16, 2);

//display pin 
//SCL Pin for nano v3 A4
//SCL Pin for nano v3 A5

//SCL Pin for Uno R3 
//SCL Pin for Uno R3 

//Temp sensor on pin 8 of uno/nano

float temp=0.0;

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hi! IoTwebplanet.com");

  Serial.begin(9600); //Begin serial communication
Serial.println("Serial Monitor Version"); //Print message
sensors.begin();
}

void loop()
{
  // command to get temperatures
sensors.requestTemperatures(); 
//Serial.print("Temperature is: ");
//Serial.println(sensors.getTempCByIndex(0)); // 0 refers to the first IC on the wire
//Update value time
lcd.clear();

temp=sensors.getTempCByIndex(0);

lcd.print("Temp: ");
 
 
lcd.print(sensors.getTempCByIndex(0));
if(temp>30)
{
  lcd.clear();
  lcd.print("Too Hot ");
  delay(500);
}

 if(temp<20)
{
  lcd.clear();
  lcd.print("Too Cold ");
  delay(500);
}
 
 
delay(1000);
  

}

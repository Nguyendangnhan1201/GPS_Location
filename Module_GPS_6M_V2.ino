#include <TinyGPS++.h>           // Include TinyGPS++ library
#include <SoftwareSerial.h>      // Include software serial library
#include <LiquidCrystal_I2C.h>
#include<Wire.h>
TinyGPSPlus gps;
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#define S_RX    4                // Define software serial RX pin
#define S_TX    3                // Define software serial TX pin
int buzzer = 5;
SoftwareSerial SoftSerial(S_RX, S_TX);
void setup(void) {

  Serial.begin(4800);  // Open Serial Monitor at 4800
  pinMode(buzzer, OUTPUT);
  SoftSerial.begin(9600);
  lcd.init();
  lcd.backlight( );
  lcd.clear();
  // Make an introduction for fun:
  lcd.setCursor(0, 0);
  lcd.print("This is GPS by");
  lcd.setCursor(0, 1);
  lcd.print("Your name");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("It can take you");
  lcd.setCursor(0, 1);
  lcd.print("a few minutes...");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting...");
}



void loop() {

  while (SoftSerial.available() > 0) {
   
    
    if (gps.encode(SoftSerial.read())) {  // If the encoding of the value is available
      if (gps.location.isValid()) {
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        delay(100);
        Serial.print("Latitude  = ");
        Serial.println(gps.location.lat(), 6);  // Round to 6 digits for the value of latitude
        Serial.print("Longitude  = ");
        Serial.println(gps.location.lng(), 6);  // Round to 6 digits for the value of longtitude
        lcd.setCursor(0, 0);
        lcd.print("Lat: ");
        lcd.setCursor(0, 1);
        lcd.print("Lng:");
        lcd.setCursor(5, 0);
        lcd.print(gps.location.lat(), 6);
        lcd.setCursor(5, 1);
        lcd.print(gps.location.lng(), 6);

      }

      else

        Serial.println("Location Invalid");


    }
  }
  }

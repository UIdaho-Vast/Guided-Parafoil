#include "TinyGPS++.h"
// This library is used for parsing GPS outputs. It can be found at:
// http://arduiniana.org/libraries/tinygpsplus/

TinyGPSPlus gps; // initializing the GPS object

// REMEMBER TO APPLY 3.3V TO EN pin

char incomingByte;   // for incoming serial data

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  Serial1.begin(9600);   // Serial1 is the default object for the secondary serial comm port
}

void loop() {

  // send data only when you receive data:
  if (Serial1.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial1.read(); //Grabs the last char transmitted to Serial1
    gps.encode(incomingByte);      // Converts that byte to a GPS sentence
    // These could be simplified as gps.encode(serial1.read()) but I thought this order was easier to read.
  }


  // Basic use case statement, checks if new satellite info is available and prints it
  if (gps.satellites.isUpdated()){
    Serial.println(gps.satellites.value());
  }

}

// Methods of GPS objects created with the tinyGPS class:
/*
Serial.println(gps.location.lat(), 6); // Latitude in degrees (double)
Serial.println(gps.location.lng(), 6); // Longitude in degrees (double)
Serial.print(gps.location.rawLat().negative ? "-" : "+");
Serial.println(gps.location.rawLat().deg); // Raw latitude in whole degrees
Serial.println(gps.location.rawLat().billionths);// ... and billionths (u16/u32)
Serial.print(gps.location.rawLng().negative ? "-" : "+");
Serial.println(gps.location.rawLng().deg); // Raw longitude in whole degrees
Serial.println(gps.location.rawLng().billionths);// ... and billionths (u16/u32)
Serial.println(gps.date.value()); // Raw date in DDMMYY format (u32)
Serial.println(gps.date.year()); // Year (2000+) (u16)
Serial.println(gps.date.month()); // Month (1-12) (u8)
Serial.println(gps.date.day()); // Day (1-31) (u8)
Serial.println(gps.time.value()); // Raw time in HHMMSSCC format (u32)
Serial.println(gps.time.hour()); // Hour (0-23) (u8)
Serial.println(gps.time.minute()); // Minute (0-59) (u8)
Serial.println(gps.time.second()); // Second (0-59) (u8)
Serial.println(gps.time.centisecond()); // 100ths of a second (0-99) (u8)
Serial.println(gps.speed.value()); // Raw speed in 100ths of a knot (i32)
Serial.println(gps.speed.knots()); // Speed in knots (double)
Serial.println(gps.speed.mph()); // Speed in miles per hour (double)
Serial.println(gps.speed.mps()); // Speed in meters per second (double)
Serial.println(gps.speed.kmph()); // Speed in kilometers per hour (double)
Serial.println(gps.course.value()); // Raw course in 100ths of a degree (i32)
Serial.println(gps.course.deg()); // Course in degrees (double)
Serial.println(gps.altitude.value()); // Raw altitude in centimeters (i32)
Serial.println(gps.altitude.meters()); // Altitude in meters (double)
Serial.println(gps.altitude.miles()); // Altitude in miles (double)
Serial.println(gps.altitude.kilometers()); // Altitude in kilometers (double)
Serial.println(gps.altitude.feet()); // Altitude in feet (double)
Serial.println(gps.satellites.value()); // Number of satellites in use (u32)
Serial.println(gps.hdop.value()); // Horizontal Dim. of Precision (100ths-i32)
*/

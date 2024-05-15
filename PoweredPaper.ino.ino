/*
    MPU6050 Triple Axis Gyroscope & Accelerometer. Simple Accelerometer Example.
    Read more: http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-zyroskop-i-akcelerometr-mpu6050.html
    GIT: https://github.com/jarzebski/Arduino-MPU6050
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
*/

// Include Librays for MPU Accelerometer
#include <Wire.h>
#include <MPU6050.h>

// Select the correct board
MPU6050 mpu;

//variable for storing when the craft is in flight
bool Launched = false;
//variable for storing the amount of time the motor stays on
int flightTime = 5000;

void setup() 
{
  //start serial
  Serial.begin(115200);
  //serial debuging
  Serial.println("Initialize MPU6050");
  //pin for the motor Mosfet
  pinMode(1, OUTPUT);
  //pin for LED
  pinMode(2, OUTPUT);
  //pin for potentiometer
  pinMode(8, INPUT);

  //This is not a part that I wrote however it checks if the MPU can be detected
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  
  checkSettings();
}

// This whole function does MPU startup functions, I did not write this part
void checkSettings()
{
  Serial.println();
  
  Serial.print(" * Sleep Mode:            ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");
  
  Serial.print(" * Clock Source:          ");
  switch(mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }
  
  Serial.print(" * Accelerometer:         ");
  switch(mpu.getRange())
  {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }  

}

void loop()
{
  
  Vector rawAccel = mpu.readRawAccel();           // These set the MPU accelerometer values to a variable that can be acsessed.
  Vector normAccel = mpu.readNormalizeAccel();
  flightTime = analogRead(8);                     // This is where we read the Potentiometer pin
  Serial.println(flightTime);                     // Debuging for the flightTime variable

  Serial.println(" Yraw = ");                     // Shows the Y axis of acceleration in the serial moniter
  Serial.println(rawAccel.YAxis);

  if(rawAccel.YAxis < -30000){                    // detects if the plane is being launched
    Launched = true;                              // sets the Launched variable to true so the code knows its in flight
}
  if(Launched == true){                           // if statement for controlling the craft in flight
    digitalWrite(2, HIGH);                        // sets the LED to on to indicate flight detected
    Serial.println("launched");                   // Tells the Serial Monitor its in flight for debugging
    analogWrite(1, 255);                          // Turns the motor on to 100%
    flightTime = analogRead(8);                   // Reads the potentiometer again for accuracy
    delay((flightTime * 5));                      // delays for the potentiometers value times 5 to increase flightime to a useable amount
    analogWrite(1, 0);                            // after the time that has been selectid is over the motor turns off
    digitalWrite(2, LOW);                         // the LED turns off
    Serial.println("Power Off");                  // Debugging
    Serial.println("waiting for landing");        // Debugging
    while(Launched == true){                      // Waits for the craft to crash or be shook in order to fly again to avoid damaging the propeller
      Vector rawAccel = mpu.readRawAccel();         // Reads the MPU again
      Vector normAccel = mpu.readNormalizeAccel();
      if(rawAccel.YAxis < -30000){                  // Crash / shake detection
        digitalWrite(2, HIGH);                      // turns LED on
        Launched = false;                           // Resets Launched value so it can fly again
        delay(1500);                                // Delay for relability
        digitalWrite(2, LOW);                       // turns LED off
      }
    }
  }
  

  
  delay(10);                                        // Delay to avoid bogging down the chip with MPU values
}

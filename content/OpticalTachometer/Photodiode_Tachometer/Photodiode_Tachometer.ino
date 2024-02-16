/*
   Photodiode Tachometer for use with Stirling Engine
   Sketch Diagarm  - https://circuits.io/circuits/3331950-arduino-photodiode-stiriling-engine-rpm-measure/edit
   Flow Diagram - https://www.draw.io/?chrome=0&lightbox=1&edit=https%3A%2F%2Fwww.draw.io%2F%23G0B3pegJdQdHO4blQ1QVB4MlgyVjg&nav=1#G0B3pegJdQdHO4blQ1QVB4MlgyVjg
   Uses an LED and Photosensitive Photodiode to implement an Photodiode tachometer.
   The LED is connected to pin 13 and ran continually.
   Pin 2 (interrupt 0) is connected across the Photodiode.
   Pin 2 on Ardunio is pre assigned interrupt 0 by default
*/
// include the library code:
#include "LiquidCrystal.h"

int ledPin = 13; // LED connected to digital pin 13
volatile byte rpmcount = 0;
unsigned int rpm = 0;
unsigned long timeold = 0;

int max_steps = 80; // 16 blocks in lcd screen * 5 rows in each block.

int max_rpm = 4000; //set # to max of what you are measuring - stiriling engine can go to 600rpm + 400 incase of threshold.

int steps = 0; // Math to visualise the rpm on lcd as a percentage bar.

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

//Create the progress bar characters
byte p20[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};
byte p40[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};
byte p60[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};
byte p80[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};
byte p100[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void rpm_count()
{
  // Each rotation this 'interrupt function' is ran twice, so take that into consideration for
  // calculating RPM and Update count.
  rpmcount++;
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);  // intialise the LCD
  lcd.print("UoG RPM Counter!"); // Welcome message.

  lcd.setCursor(0, 1);
  //Make progress bar characters
  lcd.createChar(0, p20);
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(4, p100);

  lcd.print("                ");  // Clear the line each time it reaches the end with 16 " " (spaces).


  for (int i = 0; i < 16; i++) // Iterate through each character on the second line
  {

    for (int j = 0; j < 5; j++) // Iterate through each progress value for each character
    {
      lcd.setCursor(i, 1); // Move the cursor to this location
      lcd.write(j);        // update progress bar
      delay(10);          // wait
    }
  }

  // Interrupt 0 is digital pin 2,  where the Photodiode should be connected
  // Triggers on FALLING (change from HIGH to LOW)
  attachInterrupt(0, rpm_count, FALLING);

  //Turn on LED in pin 13
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(10);// delay to stop ledPin HIGH being counted at start of void loop.

}

void loop()
{
  // Update RPM every second
  delay(1000);
  // Don't process interrupts during calculations
  detachInterrupt(0);

  // Do all processes when interrupt is disabled.

  // Note that this would be 60*1000/(millis() - timeold)*rpmcount if the interrupt
  // happened once per revolution instead of twice. (30 = 2 blades) (20 = 3 blades) (15 = 4 blades) (12 = 5 blades)
  rpm = 30 * 1000 / (millis() - timeold) * rpmcount;
  steps = (int)(((float)rpm / (float)max_rpm) * max_steps); // Math to visualise the rpm on lcd as a percentage bar.

  rpmcount = 0; // reset counter

  //Graphical output for void loop() to lcd screen.

  //Print out result to lcd
  lcd.clear();
  lcd.print("RPM = ");
  lcd.print(rpm);

  // Visualise the rpm result on the percentage bar.

  lcd.setCursor(0, 1); //(column, row)
  lcd.print("                "); //Clear the line each time it reaches the end with 16 " " (spaces).

  //Iterate through each progress value for each character.
  for (int j = 0; j < steps; j++)
  {
    lcd.setCursor((j / 5), 1); //Move the cursor to this location.
    lcd.write(j % 5);         //update progress bar with remainder as this will go up ensure 1 column accuracy across 5 columns.
  }


  timeold = millis(); // get new time before starting interrupt again
  //Restart the interrupt processing
  attachInterrupt(0, rpm_count, FALLING);
}

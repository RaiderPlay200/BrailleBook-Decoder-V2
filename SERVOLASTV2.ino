#include <SoftwareSerial.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte rxPin = 4;
const byte txPin = 2;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

char val;
char var = "";

int down = 0;
int up = 90;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
 
  lcd.init();
  lcd.backlight();  


  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);

  servo1.attach (3);
  servo2.attach (5);
  servo3.attach (6);
  servo4.attach (9);
  servo5.attach (10);
  servo6.attach (11);

  servo1.write(down);
  servo2.write(down);
  servo3.write(down);
  servo4.write(down);
  servo5.write(down);
  servo6.write(down);
}

void Servos()
{
     if (val == 'a' or val == 'b' or val == 'c' or val == 'd' or val == 'e' or val == 'f' or val == 'g' or val == 'h' or val == 'k' or val == 'l' or val == 'm' or val == 'n' or val == 'o' or val == 'p' or val == 'q' or val == 'r' or val == 'u' or val == 'v' or val == 'x' or val == 'y' or val == 'z')
    {
      servo1.write(up);
    }

    if (val == 'b' or val == 'f' or val == 'g' or val == 'h' or val == 'i' or val == 'j' or val == 'l' or val == 'p' or val == 'q' or val == 'r' or val == 's' or val == 't' or val == 'v' or val == 'w')
    {
      servo2.write(up);
    }

    if (val == 'k' or val == 'l' or val == 'm' or val == 'n' or val == 'o' or val == 'p' or val == 'q' or val == 'r' or val == 's' or val == 't' or val == 'u' or val == 'v' or val == 'x' or val == 'y' or val == 'z')
    {
      servo3.write(up);
    }

    if (val == 'c' or val == 'd' or val == 'f' or val == 'g' or val == 'i' or val == 'j' or val == 'm' or val == 'n' or val == 'p' or val == 'q' or val == 's' or val == 't' or val == 'w' or val == 'x' or val == 'y')
    {
      servo4.write(up);
    }

    if (val == 'd' or val == 'e' or val == 'g' or val == 'h' or val == 'j' or val == 'n' or val == 'o' or val == 'q' or val == 'r' or val == 't' or val == 'w' or val == 'y' or val == 'z')
    {
      servo5.write(up);
    }

    if (val == 'u' or val == 'v' or val == 'w' or val == 'x' or val == 'y' or val == 'z')
    {
      servo6.write(up);
    }


    delay(5000);
    servo1.write(down);
    servo2.write(down);
    servo3.write(down);
    servo4.write(down);
    servo5.write(down);
    servo6.write(down);

}

void loop() {
  // put your main code here, to run repeatedly:

 if (Serial.available())   
{
 val = Serial.read(); 
} 

 if (BTSerial.available() > 0) 
{
  val = (char) BTSerial.read();
}

  var = val;
  Servos(); 

  lcd.setCursor(0, 0);
  lcd.print("Chosen letter:");
  lcd.setCursor(14, 0);
  lcd.print(var);
}


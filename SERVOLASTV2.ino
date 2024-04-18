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

String var = "";

int down = 90;
int up = 68;
int up2 = 70;
int up3 = 63;
int up4 = 114;
int up5 = 114;
int up6 = 124;



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

void Servos(char val)
{
     if (val == 'a' or val == 'b' or val == 'c' or val == 'd' or val == 'e' or val == 'f' or val == 'g' or val == 'h' or val == 'k' or val == 'l' or val == 'm' or val == 'n' or val == 'o' or val == 'p' or val == 'q' or val == 'r' or val == 'u' or val == 'v' or val == 'x' or val == 'y' or val == 'z')
    {
      servo1.write(up);
    }

    if (val == 'b' or val == 'f' or val == 'g' or val == 'h' or val == 'i' or val == 'j' or val == 'l' or val == 'p' or val == 'q' or val == 'r' or val == 's' or val == 't' or val == 'v' or val == 'w')
    {
      servo2.write(up2);
    }

    if (val == 'k' or val == 'l' or val == 'm' or val == 'n' or val == 'o' or val == 'p' or val == 'q' or val == 'r' or val == 's' or val == 't' or val == 'u' or val == 'v' or val == 'x' or val == 'y' or val == 'z')
    {
      servo3.write(up3);
    }

    if (val == 'c' or val == 'd' or val == 'f' or val == 'g' or val == 'i' or val == 'j' or val == 'm' or val == 'n' or val == 'p' or val == 'q' or val == 's' or val == 't' or val == 'w' or val == 'x' or val == 'y')
    {
      servo4.write(up4);
    }

    if (val == 'd' or val == 'e' or val == 'g' or val == 'h' or val == 'j' or val == 'n' or val == 'o' or val == 'q' or val == 'r' or val == 't' or val == 'w' or val == 'y' or val == 'z')
    {
      servo5.write(up5);
    }

    if (val == 'u' or val == 'v' or val == 'w' or val == 'x' or val == 'y' or val == 'z')
    {
      servo6.write(up6);
    }

  lcd.print(val);

    delay(3000);
    servo1.write(down);
    servo2.write(down);
    servo3.write(down);
    servo4.write(down);
    servo5.write(down);
    servo6.write(down);
    delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);
  lcd.print("Recieved data:");
  lcd.setCursor(0, 1);
  

if (Serial.available()) {

  var = Serial.readString(); 

  for (int i = 0; i < var.length(); i++) {
    val = var.charAt(i); // Get the character at index i
    // Do something with the character, such as printing it
    Serial.println(val);
    Servos(val);
    }
    // Clear the receivedString variable for the next string
    val = "";
    delay(2000);
    lcd.clear();

} 

if (BTSerial.available() > 0) 
{
  var = BTSerial.readString();

  Serial.println(val);

  for (int i = 0; i < var.length(); i++) {
    val = var.charAt(i); // Get the character at index i
    // Do something with the character, such as printing it
    Serial.println(val);
    Servos(val); 
    }
    // Clear the receivedString variable for the next string
    val = "";
    delay(2000);
    lcd.clear();
  }

}


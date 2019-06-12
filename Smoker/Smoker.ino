#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,16,2);

int analogPin1 = A0;
int analogPin2 = A1;
//int analogPin3 = 0;
void setup() {
  
 
  Serial.begin(115200);
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  //lcd.clear();
  
}

int count = 0;

void loop() 
{

  int read1 = analogRead(analogPin1); 
  float vout1 = (read1 * (5.00/ 1023.0));
  
  int read2 = analogRead(analogPin2);
  float vout2 = (read2 * (5.00/ 1023.0));
  
  lcd.clear();
  double Temperature1 = (vout1 - 1.247) / 0.005;
  Temperature1 -= 20;
  Temperature1 = (Temperature1 * 9.0/5.0)+32;
  
  
  lcd.print("Meat:    ");
  lcd.print(Temperature1);
  lcd.setCursor(0,1);
  double Temperature2 = (vout2 - 1.247) / 0.005;
  Temperature2 -= 20;
  Temperature2 = (Temperature2 * 9.0/5.0)+32;

  lcd.print("Chamber: ");
  lcd.print(Temperature2);
  delay(1000); 
  
  count ++;
  if(count >= 10){
    Serial.print(Temperature1);
    Serial.print(", ");
    Serial.print(Temperature2);
    Serial.println("");
    count = 0;
  }

}

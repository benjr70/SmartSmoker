int analogPin1 = A0;
int analogPin2 = A1;
//int analogPin3 = 0;
void setup() {
  
  //analogReference(INTERNAL);
  Serial.begin(115200);
    
}

void loop() 
{

int read1 = analogRead(analogPin1); 
float vout1 = (read1 * (5.00/ 1023.0));

int read2 = analogRead(analogPin2);
float vout2 = (read2 * (5.00/ 1023.0));


double Temperature1 = (vout1 - 1.247) / 0.005;
Temperature1 -= 20;
Temperature1 = (Temperature1 * 9.0/5.0)+32;
Serial.print(Temperature1);
Serial.print(", ");


double Temperature2 = (vout2 - 1.247) / 0.005;
Temperature2 -= 20;
Temperature2 = (Temperature2 * 9.0/5.0)+32;
Serial.print(Temperature2);
Serial.println("");

delay(2000);

}

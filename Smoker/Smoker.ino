int analogPin1 = A0;
int analogPin2 = A1;
//int analogPin3 = 0;
void setup() {
  
Serial.begin(115200);
    
}

void loop() 
{

int read1 = analogRead(analogPin1); 
float vout1 = (read1 * (5.00/ 1023.0));

int read2 = analogRead(analogPin2);
float vout2 = (read2 * (5.00/ 1023.0));

double Temperature1 = (vout1 - 1.247) / 0.005;
Serial.print((Temperature1* 9.0/5.0)+32);
Serial.print(',');

double Temperature2 = (vout2 - 1.247) / 0.005;
Serial.print((Temperature2* 9.0/5.0)+32);
Serial.println("");

delay(500);

}

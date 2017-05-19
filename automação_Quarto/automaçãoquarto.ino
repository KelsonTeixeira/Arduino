#include <IRremote.h>
#include <Servo.h>

Servo tranca;
int RECV_PIN = 11;
const int led = 2;
int luz = 0;
int servovalue;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode (led, OUTPUT);
  tranca.attach (6);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
    
    switch (results.value){
    
     case 0x18E7906F:
     digitalWrite (led, HIGH);
     break;
     
     case 0x18E7A05F:
     digitalWrite (led, LOW);
     break;    
     
     case 0x18E7A857:
     servovalue = 0;
     break;   
     
     case 0x18E720DF:
     servovalue =180; 
     break;  
     
     case 0x18E738C7:
     digitalWrite (led, LOW);
     servovalue =0;
     break;
     
     case 0x18E718E7:
     digitalWrite (led, HIGH);
     servovalue= 180;
     break;
     } 
  
     tranca.write (servovalue);
  }
}
/*how to use a Servo Motor*/

// first step: you must include the servo library

#include <Servo.h>


// than you should define the port where the servo is

#define servo_1 8

// for this example I will use a potenciometer to move the servo, so, define this too

#define potenciometro_1 A0

// Now we will define the servo like a "servo variable"

Servo move_1;

//now we will set the set up fuction

void setup(){
    //let tell to Servo variable where the the servo is
    move_1.attach(servo_1);
}

//now is time to set the loop function

void loop(){
    //we want to know the value of the potenciometer so...

    int pt_position = analogRead (potenciometro_1);
      
    //now we need to mad the servo into potenciometer

    byte servo_position = map(pt_position, 0, 1023, 0, 179);
    // translating: map(x, potenciometer minimum value, potenciometer maximum value, servo minimum angle, servo maximum angle)
    
    //now to make the real servo correspon to the attributed value we do this:
    
    move_1.write(servo_position);

    //it's done
}

